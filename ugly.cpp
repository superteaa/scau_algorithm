#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    int n; // 输入数字个数
    cin >> n;
    vector<int> cnt; // 存储输入的数字
    int* max_position; // 指向最大数字的位置
    set<long long> s; // 存储所有乘积
    priority_queue<long long, vector<long long>, greater<long long>> pq; // 小顶堆，用于找到最小的乘积
    const int coeff[3] = {2, 3, 5}; // 乘法因子，用于生成所有可能的乘积
    
    // 初始化集合和优先队列，插入数值1
    s.insert(1);
    pq.push(1);
    
    // 输入n个数字
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        cnt.push_back(tmp);
    }
    
    // 找到输入数字中的最大值
    max_position = &*(max_element(cnt.begin(), cnt.end()));
    
    // 生成所有可能的乘积，直到达到最大数字的值
    for(int i = 0; i < *max_position; i++){
        long long x = pq.top();
        pq.pop();
        for(int j = 0; j < 3; j++){
            long long x2 = x * coeff[j];
            // 如果乘积尚未出现，则插入集合和优先队列
            if(!s.count(x2)){
                s.insert(x2);
                pq.push(x2);
            }
        }
    }
    
    // 输出每个数字对应的最小乘积
    for(int i = 0; i < n; i++){
        auto it = s.begin();
        // 根据当前数字的位置，找到对应的最小乘积
        advance(it, cnt[i] - 1);
        cout << *it << endl;
    }
    
    return 0;
}