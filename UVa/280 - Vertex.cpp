#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F          first
#define S          second
#define PB         push_back
#define sz(x)      (int)x.size()
#define en         '\n'
#define sp         ' '
vector < ll > graph[105];
vector < ll > vis(105);
void bfs(ll src){
    queue < ll > qq;
    qq.push(src);
    while(!qq.empty()){
        ll cur = qq.front();
        for(auto &child : graph[cur]){
            if(vis[child] == 0){
                qq.push(child);
                vis[child] = 1;
            }
        }
        qq.pop();
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int nodes;
    while(cin >> nodes && nodes != 0){
        ll x, y, q;
        for(int i = 0;i < 105;i++)
            graph[i].clear();
        while(cin >> x && x != 0){
            while(cin >> y && y != 0){
                graph[x].push_back(y);
            }
        }
        //cout << "jj\n";
        cin >> q;
        while(q--){
            for(auto &a : vis)a = 0;
            cin >> x;
            bfs(x);
            ll ans = 0, tmp = 0;
            for(int i = 1;i <= nodes;i++){
                if(vis[i]==0)ans++;
            }
            cout << ans;
            for(int i = 1;i <= nodes;i++){
                if(vis[i]==0)cout << sp << i, tmp++;
                //if(tmp != ans && vis[i] == 0)cout << "a";
            }
            cout << en;
        }
    }
    return 0;
}
