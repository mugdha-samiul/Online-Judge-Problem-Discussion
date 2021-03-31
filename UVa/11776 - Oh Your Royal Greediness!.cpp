#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz(x)  (int)x.size()
#define en     '\n'
#define sp     ' '
#define F      first
#define S      second
bool flag[10005];
vector < ll > primes;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll n, i, j, tc = 1;
    while(cin >> n && n != -1){
        ll ct, ans = 0;
        vector < ll > beg(n), endd(n);
        for(i = 0;i < n;i++)
            cin >> beg[i] >> endd[i];
        sort(beg.begin(), beg.end());
        sort(endd.begin(), endd.end());

        for(i = 0;i < n;i++){
            ct = 0;
            for(j = i;j < n;j++)
                if(endd[i] >= beg[j])ct++;
            ans = max(ans, ct);
        }
        cout << "Case " << tc << ": " << ans << en;
        tc++;
    }
    return 0;
}
