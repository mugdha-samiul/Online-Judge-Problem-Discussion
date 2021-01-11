#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz(x)  (int)x.size()
#define en     '\n'
#define sp     ' '
#define pb(x)  push_back(x)
vector < int > graph[100001];
vector < int > vis(100001);
int x, y;
void DFS(int src){
    if(vis[src] == 1)x++;
    if(vis[src] == 2)y++;
    bool flag = 1;
    for(auto &childs : graph[src]){
        if(vis[childs] == 0)flag = 0;
        if(vis[src] == 1)vis[childs] = 2;
        else if(vis[src] == 2)vis[childs] = 1;
        if(flag == 0)DFS(childs);
        flag = 1;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int tc;
    cin >> tc;
    int n, m, i, tmp, u, v, ans, t = 1;
    for(t = 1;t <= tc;t++){
        cout << "Case " << t << ": ";

        set < int > nodes;
        for(i = 0;i <= 100001;i++)
            graph[i].resize(0);
        for(i = 0;i <= 100001;i++)
            vis[i] = 0;

        cin >> m;
        tmp = m;
        while(tmp--){
            cin>>u>>v; graph[u].pb(v); graph[v].pb(u);
            nodes.insert(u);
            nodes.insert(v);
        }
        ans = 0;
        for(auto &a : nodes){
            if(vis[a] == 0){
                x = 0, y = 0;
                vis[a] = 1;
                DFS(a);
                ans += max(x, y);
            }
        }
        cout << ans << en;
    }
    return 0;
}
