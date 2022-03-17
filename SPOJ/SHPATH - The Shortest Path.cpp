#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F          first
#define S          second
#define PB         push_back
#define sz(x)      (int)x.size()
#define en         '\n'
#define sp         ' '

vector < pair < ll, ll > > graph[10001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll tc;cin >> tc;
    while(tc--){
        ll cityNumber, con, cc, u, v, w;
        cin >> cityNumber;
        vector <string> cityList(cityNumber+1);
        map <string, ll> track;
        string tmp, tmp2;
        for(int cc = 1;cc <= cityNumber;cc++)graph[cc].clear();
        for(int cc = 1;cc <= cityNumber;cc++){
            cin >> tmp >> con;
            cityList[cc] = tmp;
            track[tmp] = cc;
            while(con--){
                cin >> v >> w;
                graph[cc].PB({w,v});
            }
        }
        cin >> cc;
        while(cc--){
            cin >> tmp >> tmp2;
            u = track[tmp], v = track[tmp2];
            priority_queue < pair<ll,ll>, vector<pair<ll,ll> >, greater<pair<ll,ll> > > pq;
            pair<ll,ll> cur;
            vector <ll> vis(cityNumber+1, 10e9);
            vis[u] = 0;
            pq.push({0,u});
            while(!pq.empty()){
                cur = pq.top();
                pq.pop();
                ll curNode = cur.S, prevCost = cur.F;
                for(auto &child : graph[curNode]){
                    if(prevCost+child.F < vis[child.S]){
                        vis[child.S] = prevCost+child.F;
                        pq.push({vis[child.S],child.S});

                    }
                }
            }
            cout << vis[v] << en;
        }
    }
    return 0;
}
