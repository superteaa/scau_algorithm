#include <iostream>

using namespace std;

typedef long long ll;

int main(){
    ll casenum;
    cin >> casenum;
    ll x, y, t;
    while (casenum--){
        cin >> x >> y;
        ll a, b;
        a = x;
        b = y;
        while (a % b != 0){
            t = a;
            a = b;
            b = t % b;
        }
        cout << x * y / b << endl;
    }
    cout << "group 1 done" << endl;
    while (cin >> x >> y && x && y){
        ll a, b;
        a = x;
        b = y;
        while (a % b != 0){
            t = a;
            a = b;
            b = t % b;
        }
        cout << x * y / b << endl;
    }
    cout << "group 2 done" << endl;
    while (cin >> x >> y){
        ll a, b;
        a = x;
        b = y;
        while (a % b != 0){
            t = a;
            a = b;
            b = t % b;
        }
        cout << x * y / b << endl;
    }
    cout << "group 3 done" << endl;

    return 0;
}