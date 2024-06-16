#include <iostream>

using namespace std;

int main() {
    int n;
    while (cin >> n && n){
        long long y;
        long long z;
        for(long long x = n + 1; x <= 3 * n; x++){
            if((n * x) % (x - n) == 0) {
                y = (n * x) / (x - n);
                if (y >= x)
                    cout << "1/" << n << "=1/" << y << "+1/" << x << endl;
            }
            for(long long q = (n * x) / (x - n) + 1; q <= 2 * (n * x) / (x - n); q++){
                if((q * x * n) % (q * x - n * x - n * q) == 0){
                    z = (q * x * n) / (q * x - n * x - n * q);
                    if(z >= q && q >= x)
                        cout << "1/" << n << "=1/" << z << "+1/" << q << "+1/" << x << endl;
                }
            }
        }
        cout << endl;
    }

    return 0;
}