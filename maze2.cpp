#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct poin{
    int x;
    int y;
    int step;
};

int movx[4] = {0, 1, 0, -1};
int movy[4] = {1, 0, -1, 0};

int n, m;
int w;

char mapp[101][101];
poin tp[101][101];

poin now;
int sc, sr, ec, er;

queue<poin> q;
int ans = -1;

int main(){
    int casenum;
    cin >> casenum;
    while(casenum--){
        
        cin >> n >> m;
        
        for(int i = 0; i < n; i++){
            for(int k = 0; k < m; k++){
                cin >> mapp[i][k];
            }
        }
        
        
        cin >> w;
        while(w--){
            int c1, r1, c2, r2;
            cin >> c1 >> r1 >> c2 >> r2;
            tp[c1][r1].x = c2;
            tp[c1][r1].y = r2;
            mapp[c1][r1] = '3';
        }
        
        cin >> sc >> sr >> ec >> er;
        now = {sc, sr};
        now.step = 0;
        ans = -1;
        q.push(now);
        while(!q.empty()){
            now = q.front();
            q.pop();
            if(now.x == ec && now.y == er){
                ans = now.step;
                break;
            }
            if(mapp[now.x][now.y] == '3'){
                mapp[now.x][now.y] = '1';
                int tmpx = now.x;
                now.x = tp[tmpx][now.y].x;
                now.y = tp[tmpx][now.y].y;
                now.step++;
                q.push(now);
                mapp[now.x][now.y] = '1';
            } else {
                for(int i = 0; i < 4; i++){
                    poin tmp = now;
                    tmp.x += movx[i];
                    tmp.y += movy[i];
                    if(tmp.x < n && tmp.x >=0 && tmp.y < m && tmp.y >= 0 && mapp[tmp.x][tmp.y] != '1'){
                        tmp.step++;
                        q.push(tmp);
                        if(mapp[tmp.x][tmp.y] != '3'){
                            mapp[tmp.x][tmp.y] = '1';
                        }
                    }
                }
            }
        }
        if(ans != -1){
            cout << ans << endl;
        } else {
            cout << "die" << endl;
        }
    }
}