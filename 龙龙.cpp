#include <iostream>

using namespace std;

long long H(long long n){
    long long p = 0, q = 1;
    long long res = 0;
    long long cnt = 0;
    for(long long i = 1; p != q; i++){
        p = n / i;
        q = n / (i + 1);
        res += (p - q) * i;
        cnt += (p - q);
    }
    for(long long i = 1; i <= (n - cnt); i++){
        res += n / i;
    }
    return res;

}

int main(){
    int casenum;
    cin >> casenum;
    while (casenum--){
        long long n;
        cin >> n;
        if (n > 0){
            cout << H(n) << endl;
        } else {
            cout << "0" << endl;
        }
    }
}