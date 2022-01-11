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
    ll n;
    double sum = 0,ans = 0, x, y;
    cin >> n;
    vector < ll > nums(n);
    for(auto &a : nums){
        cin >> a;
        sum += a;
    }
    x = sum / (double)n;
    for(auto &a : nums){
        y = (sum-a)/(double)(n-1);
        if(y < x)ans++;
    }
    x = (ans / (double)n) * 100;
    cout << fixed << setprecision(3) << x << "%" << en;
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
