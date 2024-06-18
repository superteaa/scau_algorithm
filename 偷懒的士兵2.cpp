#include <iostream>
#include <algorithm>

using namespace std;

int arr[88888] = {0};

int findmin(int n, int tiny, int step){
    if (n < 88888 && arr[n] != 0){
        return arr[n];
    } else if (n < 3) {
        return tiny;
    } else if (n == 3) {
        return 99999;
    } else {
        return min(findmin((n + 1) / 2, tiny, step * 2), findmin(n / 2, tiny + step, step * 2));
    }
}

int main(){
    int n;
    while (cin >> n && n){
        if (findmin(n, 1, 1) != 99999){
            cout << findmin(n, 1, 1) << endl;
        } else cout << "0" << endl;
    }
    return 0;
}