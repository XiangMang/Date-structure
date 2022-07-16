#include <iostream>

using namespace std;

const int N = 1e2 + 10;

int n, m;
int q[N];

void s(){
    for(int i = n - 1; i >= 1; i--) swap(q[0], q[i]);
}

int main(void){

    cin >> n >> m;

    for(int i = 0; i < n; i++) cin >> q[i];

    m %= n;

    for(int i = 0; i < m; i++) s();

    cout << q[0];
    for(int i = 1; i < n; i++) cout << ' ' << q[i];
    cout << endl;

    return 0;
} 