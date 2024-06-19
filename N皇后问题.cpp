#include <iostream>

using namespace std;

int col[128] = {0};
int dia[128] = {0};
int anti[128] = {0};
int ans = 0;
int n;

void search(int cur){
   if(cur == n){
        ans++;
        return;
   } else {
        for(int i = 0; i < n; i++){
            if(!col[i] && !dia[i + cur] && !anti[i - cur + n]){
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
    int t;
    cin >> t;
    while (t--){
        cin >> n;
        ans = 0;
        search(0);
        cout << ans << endl;
    }
}