#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long LL;
const int maxn = 10001;
int A[maxn], B[maxn];

int main()
{
    int n, m;
    while (cin >> n >> m && n && m){
        for(int i = 0; i< n; i++){
            cin>>A[i];
        }
        for(int i = 0; i< m; i++){
            cin>>B[i];
        }
        sort(A,A+n);
        sort(B,B+m);
        int cur = 0;
        int cost = 0;
        for(int i = 0;i < m; i++){
            if(B[i]>=A[cur]){
                cost = cost + B[i];
                cur++;
                if(cur == n){
                    break;
                }
            }
        }
        if(cur < n){
            cout << "Loowater is doomed!" <<endl;
        }
        else {
            cout << cost <<endl;
        }
    }

    return 0;
}
