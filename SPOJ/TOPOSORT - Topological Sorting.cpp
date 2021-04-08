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

vector < ll > grp[11000];
vector < ll > ans(0);
ll in[11000];

void topo(ll n, ll m){
    ll i;
    set < ll > mp;
    for(i = 1;i <= n;i++){
        if(in[i] == 0){
            mp.insert(i);
        }
    }
    set < ll > :: iterator it;
    ll top;
    if(sz(mp) > 0){
        it = mp.begin();
        top = *it;
    }
    while(sz(mp) != 0){
        for(auto &a : grp[top]){
            in[a]--;
            if(in[a] == 0)
                mp.insert(a);
        }
        ans.PB(top);
        mp.erase(it);
        if(sz(mp) != 0){
            it = mp.begin();
            top = *it;
        }
    }
    if(sz(ans) != n){
       cout << "Sandro fails.\n";
       return;
    }
    for(auto &a : ans)
        cout << a << sp;
    cout << en;
}

int main(){
    FAST
    ll x, y, n, m, i;
    cin >> n >> m;
    for(i = 0;i < 11000;i++){
        grp[i].clear();
        in[i] = 0;
    }
    while(m--){
        cin >> x >> y;
        grp[x].PB(y);
        in[y]++;
    }
    topo(n, m);
    return 0;
}
