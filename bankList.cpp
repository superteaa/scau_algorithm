#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct custom {
    long long time;
    int level;
    string name;
    int weight;
};

// 比时间
struct compare1 {
    bool operator()(const custom& a, const custom& b) const {
        if(a.time != b.time) {
            return a.time > b.time;
        }
        else {
            if(a.level != b.level)
                return a.level < b.level;
            else
                return a.weight > b.weight;
        }
    }
};

// 比等级
struct compare2 {
    bool operator()(const custom& a, const custom& b) const {
        if(a.level != b.level) {
            return a.level < b.level;
        }
        else {
            if(a.time != b.time)
                return a.time > b.time;
            else
                return a.weight > b.weight;
        }
    }
};

int main(){
    long long n;
    priority_queue<custom, vector<custom>, compare2> q;
    priority_queue<custom, vector<custom>, compare1> wait;
    long long now = 0;
    long long close;
    long long r = 0;
    long long wait_time = 0;
    cin >> n >> close;
    custom customer;
    for (long long i = 0; i < n;i++){
        cin >> customer.time >> customer.level >> customer.name;
        customer.weight = r;
        r++;
        wait.push(customer);
    }
    while((!q.empty() || !wait.empty()) && now < close){
        while ((wait.top().time+4) / 5 <=  wait_time && !wait.empty()){
            if(now <= close){
                q.push(wait.top());
                wait.pop();
            }
            else {
                return 0;
            }
        }
        if (!q.empty() && now < close){
            cout << q.top().name << endl;
            now += 5;
            wait_time ++;
            q.pop();
        }
        else {
            now += 5;
            wait_time++;
        }
    }
    return 0;
}