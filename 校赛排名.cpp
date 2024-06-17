#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct student{
    int pass;
    int spend;
    string name;
    int weight;
};

struct compare{
    bool operator()(const student& a, const student& b)const{
        if(a.pass != b.pass){
            return a.pass < b.pass;
        } else if (a.spend != b.spend){
            return a.spend > b.spend;
        } else {
            return a.weight > b.weight;
        }
    }
};

int main(){
    priority_queue<student, vector<student>, compare> students;
    int n;
    int m;
    int weightt = 0;
    cin >> n;
    m = n;
    while (n--){
        student tmp;
        cin >> tmp.pass >> tmp.spend >> tmp.name;
        tmp.weight = weightt;
        students.push(tmp);
        weightt++;
    }
    while (m--){
        cout << students.top().name << endl;
        students.pop();
    } 
}