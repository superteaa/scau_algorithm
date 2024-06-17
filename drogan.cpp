#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main (){
    int head[200001];
    int soldier[200001];
    int n, m;
    while (cin >> n >> m && n && m){
        int cur = 0;
        int cost = 0;
        for(int i = 0; i < n; i++){
            cin >> head[i];
        }
        for(int i = 0; i < m; i++){
            cin >> soldier[i];
        }
        sort(head, head + n);
        sort(soldier, soldier + m);
        int i = 0;
        for(i = 0; i < m; i++){
            if(soldier[i] >= head[cur]){
                cost += soldier[i];
                cur++;
                if(cur == n){
                    break;
                }
            }
        }
        if(cur != n){
            cout << "Loowater is doomed!" << endl;
        } else {
            cout << cost << endl;
        }
    }
}