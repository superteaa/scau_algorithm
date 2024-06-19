#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    while(cin >> n && n){
        int arr[100005] = {0};
        int dp[100005] = {1};
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        for(int i = 1; i < n; i++){
            for(int k = i - 1; k >= 0; k--){
                if(arr[i] > arr[k]){
                    dp[i] = max(dp[i], dp[k] + 1);
                }
            }
        }
        int ans;
        ans = *max_element(dp, dp + n);
        cout << ans << endl;
    }
}