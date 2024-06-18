#include <iostream>

using namespace std;

int main(){
    long long n;
    while (cin >> n && n){
        for(long long i = n + 1; i <= 3 * n; i++){
            if (n * i % (i - n) == 0){
                long long tmp = n * i / (i - n);
                if(tmp >= i)
                    cout << "1/" << n << "=" << "1/" << tmp << "+1/" << i << endl;
            }
            for(long long j = n * i / (i - n) + 1; j <= 2 * (n * i / (i - n)) + 1; j++){
                if((n * j * i) % (j * i - n * i - n * j) == 0){
                    long long tmp2 = (n * j * i) / (j * i - n * i - n * j);
                    if(tmp2 >= j && j >= i){
                        cout << "1/" << n << "=" << "1/" << tmp2 << "+1/" << j << "+1/" << i << endl;
                    }
                        
                }
            }
        }
        cout << endl;
    }
}