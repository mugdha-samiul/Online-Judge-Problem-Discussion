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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll tc;cin >> tc;
    while(tc--){
        ll u, v, w, n, m;
        cin >> n >> m;
        vector < pair < pi , ll > > grp;
        vi cost(n, LONG_LONG_MAX);
        while(m--){
            cin >> u >> v >> w;
            grp.PB({{u,v},w});
        }
        cost[0] = 0;
        for(int i = 0;i < n-1;i++){
            for(auto &a : grp){
                if(cost[a.F.F] != LONG_LONG_MAX && cost[a.F.S] > cost[a.F.F] + a.S){
                    cost[a.F.S] = cost[a.F.F] + a.S;
                }
            }
        }
        w = 1;
        for(auto &a : grp){
            if(cost[a.F.F] != LONG_LONG_MAX && cost[a.F.S] > cost[a.F.F] + a.S){
                w = 0;
                break;
            }
        }
        if(!w)cout << "possible\n";
        else cout << "not possible\n";
    }
    return 0;
}
