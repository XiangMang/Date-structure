#include <iostream>

using namespace std;

int n;
char op;
int sum;

int main(void){
    
    cin >> sum >> op;
    
    while(op != '='){
        cin >> n;
        
        if(op == '+') sum += n;
        else if(op == '-') sum -= n;
        else if(op == '*') sum *= n;
        else if(op == '/'){
             if(n == 0){
                puts("ERROR");
                return 0;
             }
            else sum /= n;
        }
        else{
            puts("ERROR");
            return 0;
        }
        
        cin >> op;
    }
    cout << sum << endl;
    
    return 0;
}