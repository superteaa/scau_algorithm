#include <iostream>

using namespace std;

int main(){
    int casenum;
    cin >> casenum;
    while (casenum--){
        int n;
        cin >> n;
        for(int i = 1; i < n; i++){
            if((n * n % i == 0) && (n * n / i + i) % 2 == 0){
                cout << (n * n / i + i) / 2 << ',' << (n * n / i - i) / 2 << endl;
            } else {
                continue;
            }
        }
        for(int i = 1; i < n; i++){
            for(int j = i; j < n; j++){
                if(i * i + j * j == n * n){
                    cout << j << ',' << i << endl;
                } else {
                    continue;
                }
            }

        }
        cout << endl;
    }
    
}