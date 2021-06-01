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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll tc, i, j;
    cin >> tc;
    while(tc--){
        priority_queue < pair<ll,ll>, vector< pair<ll,ll> >, greater<pair<ll,ll>> > pq;
        vector < pair <ll,ll> > grp[5000];
        vector < ll > vis(110, INT_MAX);
        ll n, start, time, path, u, v, w, curr, cost, ans = 0;
        pair < ll, ll > tmp;
        cin >> n >> start >> time >> path;
        while(path--){
            cin >> u >> v >> w;
            grp[v].PB({w, u});
        }
        vis[start] = 0;
        pq.push({0, start});

        while(!pq.empty()){
            tmp = pq.top();
            curr= tmp.S, cost = tmp.F;
            pq.pop();
            if(cost != vis[curr])continue;

            for(auto &a : grp[curr]){
                if(vis[a.S] > cost + a.F){
                    vis[a.S] = cost + a.F;
                    pq.push({cost+a.F,a.S});
                }
            }
        }

        for(i = 1;i <= n;i++)
            if(vis[i] <= time)ans++;

        cout << ans << en;
        if(tc != 0) cout << "\n";
    }
    return 0;
}
