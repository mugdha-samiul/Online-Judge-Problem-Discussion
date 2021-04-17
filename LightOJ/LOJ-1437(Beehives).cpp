#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector < int > vi;
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

vi grp[550];
int ans;

void shortcycle(int src){
    int lvl[550];
    int i, top = src;
    for(i = 0;i < 550;i++)lvl[i] = 0;
    lvl[src] = 1;
    queue < int > q;
    vector < int > parent(550, -1);
    q.push(top);
    while(!q.empty()){
        for(auto &a : grp[top]){
            if(lvl[a] == 0){
                lvl[a] = lvl[top] + 1;
                q.push(a);
                parent[a] = top;
            }
            else
                if(parent[top] != a)
                    ans = min(ans, lvl[a]+lvl[top]-1);
        }
        q.pop();
        top = q.front();
    }
}

int main(){
    FAST
    int tc, kk, n, m, x, y, i;
    cin >> tc;
    for(kk = 1;kk <= tc;kk++){
        cout << "Case "<< kk <<": ";
        cin >> n >> m;
        ans = INT_MAX;
        for(i = 0;i < 550;i++)
            grp[i].clear();
        for(i = 0;i < m;i++)
            cin >> x >> y, grp[x].PB(y), grp[y].PB(x);
        for(i = 0;i < n;i++)
            shortcycle(i);
        if(ans == INT_MAX)
            cout << "impossible\n";
        else
            cout << ans << "\n";
    }
    return 0;
}
