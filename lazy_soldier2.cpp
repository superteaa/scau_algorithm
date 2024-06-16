#include <iostream>

using namespace std;

int digui(int num, int xiao, int step){
    if(num < 3){
        return xiao;
    }
    if(num == 3){
        return 99999;
    }
    return min(digui((num + 1) / 2, xiao, 2 * step), digui(num / 2, xiao + step, 2 * step));
}

int main() {

    int n;
    while (cin >> n && n != 0){
        int ans = digui(n, 1, 1);
        if(ans != 99999)
            cout << ans << endl;
        else cout << 0 << endl;
    }

    return 0;
}