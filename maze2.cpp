#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n,m,w;
int sc, sr, ec, er;
char maze[101][101];

struct pos{
    int x;
    int y;
    int step;
};

pos door[101][101];

int nextx[4] = {0, 1, 0, -1};
int nexty[4] = {1, 0, -1, 0};
int ans = 0;
bool flag = false;
void gomaze(){
    pos now = {sc,sr,0};
    queue<pos> q;
    q.push(now);
    while (!q.empty()){
        
        now = q.front();
        pos nex = {0,0,now.step};
        if (now.x == ec && now.y == er){
            ans = now.step;
            flag = true;
            break;
        }
        q.pop();
        if (maze[now.x][now.y] == '2') {
            maze[now.x][now.y] = '1';
            int tmp = now.x;
            now.x = door[now.x][now.y].x;
            now.y = door[tmp][now.y].y;
            now.step++;
            maze[now.x][now.y] = '1';
            q.push(now);
        } else {
            for (int i = 0; i < 4; i++){

                nex.x = now.x + nextx[i];
                nex.y = now.y + nexty[i];
                if (nex.x >= 0 && nex.x < n && nex.y >= 0 && nex.y < m && maze[nex.x][nex.y] != '1'){
                    if(maze[nex.x][nex.y] != '2')
                        maze[nex.x][nex.y] = '1';
                    nex.step = now.step + 1;
                    q.push(nex);
                }
                
            }
        }

    }
}

int main(){
    int casenum;
    cin >> casenum;
    while (casenum--){
        flag = false;
        ans = 0;
        cin >> n >> m;

        for(int i = 0; i < n; i++){
            for(int k = 0; k < m; k++){
                cin >> maze[i][k];
                door[i][k] = {-1, -1};
            }
        }
        cin >> w;
        for (int i = 0; i < w; i++) {
            int c1, r1, c2, r2;
            cin >> c1 >> r1 >> c2 >> r2;
            maze[c1][r1] = '2';
            door[c1][r1] = {c2, r2};
        }
        cin >> sc >> sr >> ec >> er;
        maze[sc][sr] = '0';
        gomaze();
        if (!flag){
            cout << "die" << endl;
        }
            else cout << ans << endl;

    }
}