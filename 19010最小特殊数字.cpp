#include <iostream>
#include <algorithm>

using namespace std;

int used[12] = {0};
int enter[12] = {0};
int ansarr[12] = {0};
int n;
int k;
int ans = 0;

int getans(){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum = sum * 10 + ansarr[i];
    }
    return sum;
}

int dfs(int step){
    if(step == n){
        if(getans() % k == 0 && !ans){
            ans = getans();
        }
    } else {
        for(int i = 0; i < n; i++){
            if((step == 0 && enter[i] == 0) || used[i]){
                continue;
            } else {
                ansarr[step] = enter[i];
                used[i] = 1;
                dfs(step + 1);
                used[i] = 0;
            }
        }
    }
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> enter[i];
    }
    sort(enter, enter + n);
    dfs(0);
    if(ans)
        cout << ans << endl; 
    else if(n == 1 && enter[0] == 0){
        cout << "0" << endl;
    }
    else {
        cout << " -1" << endl;
    }
}