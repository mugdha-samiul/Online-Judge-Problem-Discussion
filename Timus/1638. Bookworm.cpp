#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F          first
#define S          second
#define PB         push_back
#define sz(x)      (int)x.size()
#define en         '\n'
#define sp         ' '
#define inf        LONG_LONG_MAX

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll wid, cov, s, e, ans;
    cin >> wid >> cov >> s >> e;
    if(s < e){
        ans = cov * 2;
        ans += ((e-s-1)*(wid+cov+cov));
    }
    else if(s > e){
        ans = (s-e+1)*(wid+cov+cov);
        ans -= (cov+cov);
    }
    else ans = wid;
    cout << ans << en;
    return 0;
}
