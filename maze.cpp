#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool isok(vector<vector<int>> &mapp, int x, int y){
    if (mapp[x][y] == 1 || mapp[x][y] == 2){
        return false;
    } else {
        return true;
    }
}

struct point {
    int x;
    int y;
    int dc;
};

int movx[4] = {0, 1, 0, -1};
int movy[4] = {1, 0, -1, 0};

int main() {
    int casenum;
    cin >> casenum;
    while(casenum--){
        int N, M;
        cin >> N >> M;
        vector<vector<int>> mapp(N, vector<int>(M));
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                char tmp;
                cin >> tmp;
                mapp[i][j] = tmp - '0';
            }
        }
        int sc, sr, ec, er;
        cin >> sc >> sr >> ec >> er;
        struct point now;
        queue<point> q;
        now.x = sc;
        now.y = sr;
        now.dc = 0;
        q.push(now);
        int flag = 0;
        while (!q.empty()){
            now = q.front();
            q.pop();
            if (now.x == ec && now.y == er){
                cout << now.dc << endl;
                flag = 1;
                break;
            } else {
                for(int i = 0; i < 4; i++){
                    point tmp = now;
                    tmp.x += movx[i];
                    tmp.y += movy[i];
                    if(tmp.x >= N){
                        tmp.x = 0;
                    } else if(tmp.x < 0){
                        tmp.x = N - 1;
                    }
                    if(tmp.y >= M){
                        tmp.y = 0;
                    } else if (tmp.y < 0){
                        tmp.y = M - 1;
                    }
                    if (isok(mapp, tmp.x, tmp.y)){
                        tmp.dc = now.dc + 1;
                        q.push(tmp);
                        mapp[tmp.x][tmp.y] = 2;
                    }
                }
            }
        }
        if(!flag){
            cout << "die" << endl;
        }
    }

    return 0;
}