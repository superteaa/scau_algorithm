#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

struct position{
    int x;
    int y;
    int dist;
};

const int movx[4] = {1, 0, -1, 0};
const int movy[4] = {0, 1, 0, -1};
int N,M;

bool isV(vector<vector<int>> &sq, int x, int y){
    if(sq[y][x] == 1 || sq[y][x] == 2){
        return false;
    }
    else return true;
}

int solve(vector<vector<int>>& sq, queue<position> s, int ec, int er){
    priority_queue<int,vector<int>,greater<int>> cnt;
    while (!s.empty()){
        position now = s.front();
        s.pop();
        if(ec == now.y && er == now.x){
            cnt.push(now.dist);
            sq[now.y][now.x] = 0;
        }
        else {
            for(int i = 0; i < 4;i++){
                int nx = now.x + movx[i];
                int ny = now.y + movy[i];
                int nd = now.dist + 1;
                if(nx < 0){
                    nx = M-1;
                }
                else if(nx == M){
                    nx = 0;
                }
                if(ny < 0){
                    ny = N-1;
                }
                else if(ny == N){
                    ny = 0;
                }
                if(isV(sq, nx,ny)){
                    s.push({nx,ny,nd});
                    sq[ny][nx] = 2;
                }
            }
        }
    }
    if(cnt.empty())
        return 0;
    else {
        return cnt.top();
    }
}

int main(){
    queue<position> s;
    int casenum;
    cin >> casenum;
    char num;
    while (casenum--){
        int sc, sr, ec, er, mindist;
        position current;
        position end;
        cin >> N >> M;
        vector<vector<int>> sq(N, vector<int>(M));
        for(int i = 0; i< N;i++){
            for(int j = 0; j<M; j++){
                cin >> num;
                sq[i][j] = num - '0';
            }
        }
        cin >> sc >> sr >> ec >> er;
        sq[sc][sr] = 2;
        current.y = sc;
        current.x = sr;
        current.dist = 0;
        s.push(current);
        mindist = solve(sq,s, ec, er);
        if(!mindist){
            cout << "die" <<endl;
        }
        else cout << mindist <<endl;
    }
    return 0;
}