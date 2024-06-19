#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
    char str1[1005];
    char str2[1005];
    cin >> str1;
    cin >> str2;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int dp[len1 + 5][len2 + 5] = {0};
    memset(dp, 0, sizeof(dp));

    for(int i = len1 - 1; i >= 0; i--){
        for(int k = len2 -1; k >= 0; k--){
            if(str1[i] == str2[k]){
                dp[i][k] = dp[i + 1][k + 1] + 1;
            } else {
                dp[i][k] = max(dp[i + 1][k], dp[i][k + 1]);
            }
        }
    }
    cout << dp[0][0] << endl;
}