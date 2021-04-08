#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector < ll > vl;
typedef pair < ll,ll > pl;
#define FAST       ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define rep(I,a,b) for(int I = a; I < b; I++)
#define sz(x)      (int)x.size()
#define PB         push_back
#define MP         make_pair
#define F          first
#define S          second
#define en         '\n'
#define sp         ' '
vl grp[200];
ll in[200];
vl ans;
void topo(ll n, ll m){
    queue < ll > q;
    for(int i = 1;i <= n;i++){
        if(in[i] == 0)
            q.push(i);
    }
    ll top = q.front();
    while(!q.empty()){
        for(auto &a : grp[top]){
            in[a]--;
            if(in[a] == 0)q.push(a);
        }
        ans.PB(top);
        q.pop();
        top = q.front();
    }
    for(auto &a : ans)
        cout << a << sp;
    cout << en;
}
int main(){
    FAST
    ll n, m, x, y, i;
    while(cin >> n >> m){
        if(n == 0 && n == m)break;
        ans.clear();
        rep(i, 0, 200){
            grp[i].clear();
            in[i] = 0;
        }
        rep(i, 0, m){
            cin >> x >> y;
            grp[x].PB(y);
            in[y]++;
        }
        topo(n, m);
    }
    return 0;
}
