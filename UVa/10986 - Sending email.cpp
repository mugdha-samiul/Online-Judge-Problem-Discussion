#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector < ll > vi;
typedef pair < ll, ll > pi;
#define F          first
#define S          second
#define PB         push_back
#define MP         make_pair
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define sz(x)      (int)x.size()
#define en         '\n'
#define sp         ' '
vector < pi > grp[21000];
vector < ll > cost(21000);

void dijkstra(ll src){
    ll curr, ww;
    set < pi > pq;
    cost[src] = 0;
    pq.insert({0, src});
    while(sz(pq) != 0){
        auto tmp = *pq.begin();
        pq.erase(pq.begin());
        curr = tmp.S, ww = tmp.F;
        for(auto &a : grp[curr]){
            if(cost[a.S] == -1 || cost[a.S] > a.F + ww){
                pq.insert({ww+a.F, a.S});
                cost[a.S] = ww+a.F;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll tc, kk, i, u, v, w, n, m, s, t;
    cin >> tc;
    for(kk = 1;kk <= tc;kk++){
        cout << "Case #" << kk << ": ";
        cin >> n >> m >> s >> t;
        for(i = 0;i <= n;i++){
            grp[i].clear();
            cost[i] = -1;
        }
        while(m--){
            cin >> u >> v >> w;
            grp[u].PB({w, v});
            grp[v].PB({w, u});
        }
        dijkstra(s);
        if(cost[t] == -1)cout << "unreachable\n";
        else cout << cost[t] << en;
    }
    return 0;
}
