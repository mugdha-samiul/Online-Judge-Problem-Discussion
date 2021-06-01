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

vector < ll > grp[200];
vector < ll > vis(200);
ll pp;

void DFS(ll src, ll lvl){
    vis[src] = lvl+1;
    for(auto &a : grp[src])
        if((vis[a] >= vis[src]+1 || vis[a] == 0) && a != pp){
            DFS(a, vis[src]);
        }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll kk = 1, u, v, n, i;
    while(1){
        for(i = 0;i < 200;i++)grp[i].clear();
        map < ll, ll > nodes;
        while(1){
            cin >> u >> v;
            if(u == v && v == 0)break;
            grp[u].PB(v);
            nodes[u]++;
            nodes[v]++;
        }
        n = sz(nodes);
        if(n == 0)break;
        cout << "Case " << kk << ": average length between pages = ";
        kk++;
        ll tot = 0;
        for(auto &a : nodes){
            for(i = 0;i < 200;i++) vis[i] = 0;
            vis[a.F] = 0;
            pp = a.F;
            DFS(pp, -1);
            for(i = 0;i < 103;i++) tot += vis[i];
        }
        n = n * (n-1);
        cout << fixed << setprecision(3) << (double)((double)tot/(double)n) << " clicks\n";
    }
    return 0;
}
