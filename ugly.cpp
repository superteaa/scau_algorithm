#include <iostream>
#include <set>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<ll> cnt;
    ll* max_p;
    for(int i = 0; i < n ; i++){
        ll tmp;
        cin >> tmp;
        cnt.push_back(tmp);
    }
    max_p = &*(max_element(cnt.begin(), cnt.end()));
    set<ll> s;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll coeff[3] = {2, 3, 5};
    s.insert(1);
    pq.push(1);
    for(ll i = 0; i < *max_p; i++){
        ll x = pq.top();
        pq.pop();
        for (int j = 0; j < 3; j++){
            ll x2 = x * coeff[j];
            if(!s.count(x2)){
                s.insert(x2);
                pq.push(x2);
            }
        }
    }
    for(int i = 0; i < n; i++){
        auto it = s.begin();
        advance(it, cnt[i] - 1);
        cout << *it << endl;
    }

    return 0;
}