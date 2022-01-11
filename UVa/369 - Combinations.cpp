#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
long long int solve(int n, int r);
int main(){
      while(1){
            int n, r;
            long long int ans = 0;
            scanf("%d %d", &n, &r);
            if(n == 0 && r == 0)
                  break;
            ans = solve(n, r);
            printf("%d things taken %d at a time is %lld exactly.\n", n, r, ans);
      }
    return 0;
}
long long int solve(int n, int r){
      long long int ans = 1;
      if(n - r < r)
            r = n - r;
      int i = r, j = 1;
      for(i = 0;i < r;i++){
            ans *= (n - i);
            for(;j <= r;j++){
                  if(ans % j == 0){
                        ans /= j;
                  }
                  else
                        break;
            }
      }
      return ans;
}
