#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
    char str1[1001];
    char str2[1001];
    cin >> str1;
    cin >> str2;
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int dp[len1 + 2][len2 + 2] = {0};
    memset(dp, 0, sizeof(dp));

    for(int i = len1 - 1; i >= 0; i--){
        for(int k = len2 - 1; k >= 0; k--){
            if (str1[i] == str2[k] ){
                dp[i][k] = dp[i + 1][k + 1] + 1;
            } else {
                dp[i][k] = max(dp[i][k + 1], dp[i + 1][k]);
            }
        }
    }
    cout << dp[0][0] << endl;

    return 0;
}