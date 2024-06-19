#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int gethappy[51] = {0};
    int losepow[51] = {0};
    int dp[51][2001] = {0};
    for(int i = 1; i <= n; i++){
        cin >> gethappy[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> losepow[i];
    }
    for(int i = 1; i <= n; i++){
        for(int k = 1; k <= 1999; k++){
            if(k - losepow[i] >= 0 && gethappy[i] + dp[i - 1][k - losepow[i]] > dp[i - 1][k]){
                dp[i][k] = gethappy[i] + dp[i - 1][k - losepow[i]];
            } else {
                dp[i][k] = dp[i - 1][k];
            }
        }
    }
    cout << dp[n][1999] + 1 << endl;
}