#include <iostream>
#include <cmath>

using namespace std;

int n, m;
long long sum;

int main(void){

    cin >> n >> m;

    for(int i = 1, j = pow(10, m - 1); i <= m; i++, j /=10) sum += i * j * n;

    cout << sum << endl;

    return 0;
}