#include <iostream>

using namespace std;

int col[100] = {0};
int dia[100] = {0};
int anti[100] = {0};
int n;
int ans;

void search(int cur) {
    if(cur == n){
        ans++;
    }
    else {
        for(int i = 0; i < n; i++){
            if (!col[i] && !dia[i + cur] && !anti[i - cur + n]){
                col[i] = 1;
                dia[i + cur] = 1;
                anti[i - cur + n] = 1;
                search(cur + 1);
                col[i] = 0;
                dia[i + cur] = 0;
                anti[i - cur + n] = 0;
            }
        }
    }
}

int main(){
    int casenum;
    cin >> casenum;
    for(int k = 0; k < casenum; k++){
        cin >> n;
        search(0);
        cout << ans << endl;
        ans = 0;
    }
    return 0;
}
