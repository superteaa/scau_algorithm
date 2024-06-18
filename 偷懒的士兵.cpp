#include <iostream>

using namespace std;

int arr[8888] = {0};

int soldier(int n){
    if (n < 8888 && arr[n] != 0){
        return arr[n];
    } else if(n < 3){
        return 0;
    } else if(n == 3){
        return 1;
    } else {
        int sum = soldier(n / 2) + soldier((n + 1) / 2);
        if(n < 8888)
            arr[n] = sum;
        return sum;
    }
}

int main() {
    int n;
    while(cin >> n && n != 0){
        int tmp = soldier(n);
        cout << n - 3 * tmp << endl;
    }
}