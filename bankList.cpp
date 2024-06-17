#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct custom {
    long long time;
    int level;
    string name;
    int weight;
};

struct compare_time{
    bool operator()(const custom& a, const custom& b)const{
        if(a.time != b.time){
            return a.time > b.time;
        } else if (a.level != b.level){
            return a.level < b.level;
        } else {
            return a.weight > b.weight;
        }
    }
};

struct compare_level{
    bool operator()(const custom& a, const custom& b)const{
        if(a.level != b.level){
            return a.level < b.level;
        } else if (a.time != b.time){
            return a.time > b.time;
        } else {
            return a.weight > b.weight;
        }
    }
};

int main(){
    priority_queue<custom, vector<custom>, compare_time> customer;
    priority_queue<custom, vector<custom>, compare_level> q;
    int n;
    int tmp_weight = 0;
    int wait_time = 0;
    // int now = 0;
    cin >> n;
    while (n--){
        custom tmp;
        cin >> tmp.time >> tmp.level >> tmp.name;
        tmp.weight = tmp_weight;
        tmp_weight++;
        customer.push(tmp);
    }
    while (!customer.empty() || !q.empty()){
        while (!customer.empty() && (customer.top().time + 4) / 5 <= wait_time){
            q.push(customer.top());
            customer.pop();
        }
        if (!q.empty()){
            cout << q.top().name << endl;
            wait_time++;
            // now += 5;
            q.pop();
        } else {
            wait_time++;
        }
    }


    return 0;
}