#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    while (cin >> n && n != 0){
        int arr[10001] = {0};
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }
        int dp[10001] = {1};
        for(int i = 1; i < n; i++){
            for(int k = i - 1; k >= 0; k--){
                if (arr[i] > arr[k]) {
                    dp[i] = max(dp[k] + 1, dp[i]);
                }
            }
        }
        int maxnum = *max_element(dp, dp + n);

        cout << maxnum << endl;
    }
    return 0;
}