#include <iostream>
#include <vector>


using namespace std;

vector<long long> arr(99999, 0);

long long soldier(long long n){
    if (n < 99998 && arr[n] != 0){
        return arr[n];
    }

    if (n < 3){
        return 0;
    } else if (n == 3){
        return 1;
    } else {
        long long sum = 0;
        sum = soldier(n / 2) + soldier((n + 1) / 2);
        if (n < 99998)
            arr[n] = sum;
        return sum;
    }

}

int main(){
    long long n;
    while (cin >> n && n != 0){
        cout << soldier(n) << endl;
    }
    return 0;
}