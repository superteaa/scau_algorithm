#include <iostream>
#include <string>

using namespace std;


int main() {
    int num;
    while (cin >> num && num != 0){



        for (int k = 1; k < 98765; k++){
            int arr[10] = {0};
            string nums = to_string(k);
            int flag = 1;
            for (char ch : nums){
                arr[ch - '0']++;
                if (ch >'0' && arr[ch - '0'] >= 2) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 0){
                continue;
            }
            int ans = k * num;
            string nums2 = to_string(ans);
            if (nums2.length() > 5){
                break;
            }
            for (char ch : nums2){
                arr[ch - '0']++;
                if (ch >'0' && arr[ch - '0'] >= 2) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 0) {
                continue;
            }
            printf("%05d/%05d=%d\n",ans,k,num);
        }
        cout <<endl;
    }


    return 0;
}
