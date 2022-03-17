#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F          first
#define S          second
#define PB         push_back
#define sz(x)      (int)x.size()
#define en         '\n'
#define sp         ' '

struct edge{
    ll u;
    ll v;
    ll w;
};
edge grp[1000004];
int parent[1000004];
bool cmp(edge a, edge b){
    if(a.w < b.w)return true;
    else return false;
}
ll findParent(ll cur){
    if(parent[cur] == -1)return cur;
    return findParent(parent[cur]);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll n, flag = 0;
    while(cin >> n){
        if(flag != 0)cout << en;
        flag++;

        ll i, m, k, p, q, r, tmp = 0, minCost = 0;
        for(i = 0;i < n-1;i++)
            cin >> p >> q >> r, tmp += r;
        cin >> m;
        for(i = 0;i < m;i++)
            cin >> grp[i].u >> grp[i].v >> grp[i].w;
        cin >> k;
        for(;i < m+k;i++)
            cin >> grp[i].u >> grp[i].v >> grp[i].w;

        for(int i = 0;i <= n;i++)
            parent[i] = -1;
        sort(grp, grp+m+k, cmp);
        for(int i = 0;i < m+k;i++){
            ll x = findParent(grp[i].u);
            ll y = findParent(grp[i].v);
            if(x != y){
                minCost += grp[i].w;
                parent[x] = y;
            }
        }
        if(tmp != minCost)cout << tmp << en;
        cout << minCost << en;
    }
    return 0;
}
