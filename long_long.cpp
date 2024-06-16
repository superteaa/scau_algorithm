#include <stdio.h>

long long H(int n){
    long long res = 0;
    int i = 1;
    int p, q;
    int cnt = 0;
    while (1){
        p = n / i;
        q = n / (i + 1);
        if(p == q){
            break;
        } else {
            res += (p - q) * i;
            cnt += (p - q);
        }
        i++;
    }

    for(i = 1; i <= n - cnt; i=i+1 ){
        res = (res + n/i);
    }
    return res;
}

int main(){
    int casenum;
    scanf("%d", &casenum);
    while (casenum--){
        int num;
        scanf("%d", &num);
        if(num >= 0)
            printf("%lld\n", H(num));
        else printf("0\n");
    }

    return 0;
}