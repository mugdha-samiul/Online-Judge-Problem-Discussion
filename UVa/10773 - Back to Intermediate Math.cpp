#include <stdio.h>
#include <math.h>
int main(){
    int tc, i = 1;
    long long int d, u, v;
    double ans;
    scanf("%d", &tc);
    while(tc--){
        scanf("%lld %lld %lld", &d, &u, &v);
        if(u >= v || u == 0 || v == 0){
            printf("Case %d: can't determine\n", i);
            i++;
            continue;
        }
        ans = (v*v) - (u*u);
        ans = d / (sqrt(ans));
        ans = ans - ((double)d / (double)v);
        printf("Case %d: %.3lf\n", i, ans);
        i++;
    }
    return 0;
}
