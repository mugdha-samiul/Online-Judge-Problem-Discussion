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
vector < ll > vis1(200);
vector < ll > vis2(200);
ll pp;

void DFS(ll src, ll lvl, ll flag){
    if(flag == 1){
        vis1[src] = lvl+1;
        for(auto &a : grp[src])
            if((vis1[a] >= vis1[src]+1 || vis1[a] == 0) && a != pp)
                DFS(a, vis1[src], 1);
    }
    if(flag == 2){
        vis2[src] = lvl+1;
        for(auto &a : grp[src])
            if((vis2[a] >= vis2[src]+1 || vis2[a] == 0) && a != pp)
                DFS(a, vis2[src], 2);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll tc, kk = 1, u, v, n, m, i;
    cin >> tc;
    for(kk = 1;kk <= tc;kk++){
        cout << "Case " << kk << ": ";
        for(i = 0;i < 200;i++)grp[i].clear(), vis1[i] = 0, vis2[i] = 0;
        cin >> n >> m;
        while(m--)
            cin >> u >> v, grp[u].PB(v), grp[v].PB(u);
        cin >> u >> v;
        pp = u, DFS(u, -1, 1);
        pp = v, DFS(v, -1, 2);
        ll mex = -1;
        for(i = 0;i < n;i++)
            mex = max(mex, vis1[i]+vis2[i]);
        cout << mex << "\n";
    }
    return 0;
}
