#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct custom{
    int time;
    int level;
    string name;
    int weight;
};

struct compara_time{
    bool operator()(const custom& a, const custom& b)const{
        if(a.time != b.time){
            return a.time > b.time;
        } else if (a.level != b.level){
            return a.level < b.level;
        } else return a.weight > b.weight;
    }
};

struct compara_l{
    bool operator()(const custom& a, const custom& b)const{
        if(a.level != b.level){
            return a.level < b.level;
        } else if (a.time != b.time){
            return a.time > b.time;
        } else return a.weight > b.weight;
    }
};

int main(){
    int n, close;
    cin >> n >> close;
    int tweight = 0;
    int now = 0;
    int wait_time = 0;
    priority_queue<custom, vector<custom>, compara_time> customers;
    priority_queue<custom, vector<custom>, compara_l> q;
    while(n--){
        custom tmp;
        cin >> tmp.time >> tmp. level >> tmp.name;
        tmp.weight = tweight;
        customers.push(tmp);
        tweight++;
    }
    while (!q.empty() || !customers.empty()){
        while (!customers.empty() && (customers.top().time + 4) / 5 <= wait_time){
            q.push(customers.top());
            customers.pop();
        }
        if (now <= close && !q.empty()){
            cout << q.top().name << endl;
            q.pop();
            now += 5;
            wait_time++;
        } else {
            now += 5;
            wait_time++;
        }
        if (now >= close){
            return 0;
        }
    }

    return 0;
}