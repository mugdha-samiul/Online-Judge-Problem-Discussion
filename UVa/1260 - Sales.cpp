#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F          first
#define S          second
#define PB         push_back
#define sz(x)      (int)x.size()
#define en         '\n'
#define sp         ' '

void solve(){
    ll n, ans = 0;
    cin >> n;
    map < ll, ll > records;
    vector < ll > nums(n);
    for(auto &a : nums){
        cin >> a;
        for(auto &b : records){
            if(b.F <= a){
                ans += b.S;
            }
            else{
                break;
            }
        }
        records[a]++;
    }
    cout << ans << en;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll tc = 1;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}
