#include <iostream>

using namespace std;

int main(){
    int m, n;
    int weight[35] = {0};
    int v[35] = {0};
    int dp[35][205] = {0};
    cin >> m >> n;
    for(int i = 1; i <= n; i++){
        cin >> weight[i] >> v[i];
    }
    for(int i = 1; i <= n; i++){
        for(int k = 1; k <= m; k++){
            if(k - weight[i] >= 0 && v[i] + dp[i - 1][k - weight[i]] > dp[i - 1][k])
                dp[i][k] = v[i] + dp[i - 1][k - weight[i]];
            else {
                dp[i][k] = dp[i - 1][k];
            }
        }
    }
    cout << dp[n][m] << endl;
}