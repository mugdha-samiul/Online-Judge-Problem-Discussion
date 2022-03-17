#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F          first
#define S          second
#define PB         push_back
#define sz(x)      (int)x.size()
#define en         '\n'
#define sp         ' '
ll parent[200005], sz[200005];
int Find(int vertex){
    if(parent[vertex] == vertex)return vertex;
    return Find(parent[vertex]);
}
void Union(int x, int y){
    int a = Find(x);
    int b = Find(y);
    if(a != b){
        if(sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}
void solve(ll n, ll m){
    vector < pair<ll, pair<ll, ll> > >graph;
    map <ll,ll> ans;
    ll u, v, w, total = 0;
    for(int i = 0;i <= n;i++)parent[i]=i, sz[i]=1;
    for(int i = 0;i < m;i++){
        cin >> u >> v >> w;
        graph.PB({w,{u,v}});
        graph.PB({w,{v,u}});
        ans[w]++;
    }
    sort(graph.begin(), graph.end());
    ll tot = 0;
    for(auto &curr : graph){
        u = curr.S.F;
        v = curr.S.S;
        w = curr.F;
        if(Find(u) != Find(v)){
            tot += w;
            Union(u, v);
            ans[w]--;
        }
    }
    ll flag = 0;
    for(auto &a : ans){
        if(a.S > 0){
            if(flag == 0){
                flag = 1;
                ans[a.F]--;
                cout << a.F;
                continue;
            }
            ans[a.F]--;
            cout << " " << a.F;
        }
    }
    if(flag == 0)cout << "forest";
    cout << en;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll n, m;
    while(cin >> n >> m){
        if(n == 0 && m == 0)break;
        solve(n, m);
    }
}
