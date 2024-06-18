#include <iostream>
#include <string>

using namespace std;


int main(){
    int n;
    while (cin >> n && n){
        
        for(int i = 1; i <= 98765; i++){
            int arr[12] = {0};
            int flag = 1;

            string num1 = to_string(i);
            for (char ch : num1){
                arr[ch - '0']++;
                if(ch != '0' && arr[ch - '0'] >= 2){
                    flag = 0;
                    break;
                }
            }
            if(!flag){
                continue;
            } else {
                int k;
                k = i * n;
                string num2 = to_string(k);
                if(num2.length() > 5){
                    break;
                } else {
                    for(char ch : num2){
                        arr[ch - '0']++;
                        if(ch != '0' && arr[ch - '0'] >= 2){
                            flag = 0;
                            break;
                        }
                    }
                    if(!flag){
                        continue;
                    } else {
                        printf("%05d/%05d=%d\n", k, i, n);
                    }
                }
            }
        }
        cout << endl;
    }
}