#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F          first
#define S          second
#define PB         push_back
#define sz(x)      (int)x.size()
#define en         '\n'
#define sp         ' '
vector < string > field(10);
string sub = "IEHOVA#";
int vis[7];
ll n, m;
void srch(ll x, ll y){
    ll p=x, q=y;
    if(x-1 >= 0 && x < n && y >= 0 && y < m){
        for(int j = 0;j <= 6;j++){
            if(field[x-1][y] == sub[j] && vis[j] == 0){
                p = x-1;
                q = y;
                vis[j] = 1;
                cout << "forth";
                break;
            }
        }
    }
    if(x >= 0 && x < n && y+1 >= 0 && y+1 < m){
        for(int j = 0;j <= 6;j++){
            if(field[x][y+1] == sub[j] && vis[j] == 0){
                p = x;
                q = y+1;
                vis[j] = 1;
                cout << "right";
                break;
            }
        }
    }
    if(x >= 0 && x < n && y-1 >= 0 && y-1 < m){
        for(int j = 0;j <= 6;j++){
            if(field[x][y-1] == sub[j] && vis[j] == 0){
                p = x;
                q = y-1;
                vis[j] = 1;
                cout << "left";
                break;
            }
        }
    }
    if(vis[6] == 0)cout << " ";
    if(p == x && q == y)return;
    srch(p, q);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--){
        cin >> n >> m;
        for(int i = 0;i < 7;i++)vis[i] = 0;
        for(int i = 0;i < n;i++){
            cin >> field[i];
        }
        for(int i = 0;i < m;i++){
            if(field[n-1][i] == '@'){
                srch(n-1, i);
                break;
            }
        }
        cout << en;
    }
    return 0;
}
