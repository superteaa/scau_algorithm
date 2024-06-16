#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

int main(){
    while (cin >> n >>m){
        int cost = 0;
        vector<int> head;
        vector<int> wr;
        if(n == 0 && m == 0){
            return 0;
        }
        else {
            for(int i = 0; i< n;i++){
                int tmp;
                cin >> tmp;
                head.push_back(tmp);
            }
            for(int i = 0; i < m; i++){
                int tmp;
                cin >> tmp;
                wr.push_back(tmp);
            }
            sort(wr.begin(),wr.end());
            sort(head.begin(), head.end());
            vector<int>::iterator it = wr.begin();
            vector<int>::iterator i = head.begin();
            while (it != wr.end() && i!=head.end()){
                if (*it >= *i){
                    cost += *it;
                    i++;
                    it++;
                }
                else {
                    it++;
                }
            }
            if(i == head.end()){
                cout << cost << endl;
            }
            else cout << "Loowater is doomed!" << endl;
        }
    }
}