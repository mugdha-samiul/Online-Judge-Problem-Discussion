#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > pi;
#define F          first
#define S          second
#define PB         push_back
#define MP         make_pair
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define sz(x)      (int)x.size()
#define en         '\n'
#define sp         ' '
int vis[11000];
vector < ll > vec[11000];
ll ans;
void kela(ll x){
    if(vis[x] == 0){
        vis[x] = 1;
        ans++;
    }
    for(auto &a : vec[x])
        if(vis[a] == 0)
            kela(a);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll tc;
    cin >> tc;
    while(tc--){
        ll i, n, m ,l, x, y;
        ans = 0;
        cin >> n >> m >> l;
        for(i = 0;i <= n;i++)vis[i] = 0;
        for(i = 0;i <= n;i++)vec[i].clear();
        vis[0] = 1;
        while(m--){
            cin >> x >> y;
            vec[x].PB(y);
        }
        while(l--){
            cin >> x;
            if(vis[x] == 0)
                kela(x);
        }
        cout << ans << en;
    }
    return 0;
}
