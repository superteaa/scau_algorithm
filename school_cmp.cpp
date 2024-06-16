#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

struct student {
    int pass;
    int spend;
    string name;
    int weight;

};

bool compare(const student& a, const student& b) {
    if (a.pass != b.pass) {
        return a.pass > b.pass;
    } else if (a.spend != b.spend) {
        return a.spend < b.spend;
    } else {
        return a.weight < b.weight;
    }
}

int main() {
    long long n;
    scanf("%lld",&n);
    vector<student> students;

    for (int i = 0; i < n; i++) {
        struct student tmp;

        cin >> tmp.pass >> tmp.spend;
        cin >> tmp.name;
        tmp.weight = i;
        students.push_back(tmp);
    }

    sort(students.begin(), students.end(), compare);

    vector<student>::iterator it = students.begin();
    for(; it != students.end(); it++){
        printf("%s\n", it->name.c_str());
    }
    return 0;
}