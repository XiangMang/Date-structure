#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n;
int q[N];

int max3(int a, int b, int c){
    int tmp = a > b ? a : b;
    return tmp > c ? tmp : c;
}

int merge(int l, int r){
    if(l >= r){
        if(q[l] > 0) return q[l];
        else return 0;
    }
    int mid = l + r >> 1;

    int max_left_sum = merge(l, mid);
    int max_right_sum = merge(mid + 1, r);

    int left_sum = 0, left_tmp = 0;
    for(int i = mid; i >= l; i--){// 判断左侧最大子序列
        left_tmp += q[i];
        left_sum = max(left_sum, left_tmp);
    }

    int right_sum = 0, right_tmp = 0;
    for(int i = mid + 1; i <= r; i++){// 判断右侧最大子序列
        right_tmp += q[i];
        right_sum = max(right_sum, right_tmp);
    }

    // 因为需要判断处于中间的最大子序列，
    // 故左侧从分界点向左侧循环， 右侧从分界点向右侧循环

    return max3(max_left_sum, max_right_sum, left_sum + right_sum);
}

int main(void){

    cin >> n;

    int tmp = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &q[i]);
        if(q[i] < 0) tmp++;
    }

    if(tmp == n) puts("0");
    else printf("%d\n", merge(0, n - 1));

    return 0;
}