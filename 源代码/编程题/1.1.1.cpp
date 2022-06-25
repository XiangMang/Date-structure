// 动态规划
#include <iostream>

using namespace std;

const int N = 10;

int n;
int q[N];

int Max(void){
    int tmp = 0, sum = 0;
    for(int i = 1; i <= n; i++){
        tmp += q[i];
        if(tmp > sum) sum = tmp;
        else if(tmp < 0) tmp = 0;
    }
    return sum;
}

int main(void){

    cin >> n;

    int time = 0;
    for(int i = 1; i <= n; i++) scanf("%d", &q[i]), time += q[i];

    if(time <= -n) puts("0");
    else printf("%d", Max());  

    return 0;
}