#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll n;
ll k;
ll num[12];
ll book[12] = {0};
ll ansa[12];
ll ans = 0;

ll getnum(){
    ll sum = 0;
    for (int i = 1; i <= n; i++){
        sum = sum * 10 + ansa[i];
    }
    return sum;
}

void dfs(ll step){
    if(step == n + 1){
        if(getnum() % k == 0 && !ans)
            ans = getnum();
        return;
    }
    for(int i = 1; i <= n; i++){
        if(step == 1 && !num[i]){
            continue;
        }
        if(!book[i]) {
            book[i] = 1;
            ansa[step] = num[i];
            dfs(step + 1);
            book[i] = 0; 
        }
    }
}

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> num[i];
    }
    if(n == 1 && !num[1]){
        cout << "0" << endl;
        return 0;
    }
    sort(num + 1, num + 1 + n);
    dfs(1);
    if(!ans){
        cout << "-1" << endl;
    } else cout << ans << endl;
}