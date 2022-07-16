#include <iostream>

using namespace std;

const int N = 1e5 +10;

int n;
int q[N], tmp[N];

int main(void){

    cin >> n;

    for(int i = 0; i < n; i++) scanf("%d", &q[i]);

    int res = 1, num = 1, r = 0;
    for(int i = 1; i <= n; i++){
        if(q[i - 1] < q[i]){
            if(res < ++num){
                res = num;
                r = i;
            }
        }
        else num = 1;
    }

    printf("%d", q[r - res + 1]);
    for(int i = r - res + 2; i <= r; i++) printf(" %d", q[i]);
    
    return 0;
}