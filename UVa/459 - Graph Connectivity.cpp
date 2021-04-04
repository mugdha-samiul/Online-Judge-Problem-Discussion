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
int vis[60];
vi grp[60];
int cnt = 0;
void DFS(int src){
    vis[src] = 1;
    for(auto &a : grp[src])
        if(vis[a] == 0)
            DFS(a);
}
int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);cout.tie(NULL);
    int tc, len, i;
    cin >> tc;
    while(tc--){
        string str;
        cin >> str;
        len = str[0] - 'A' + 1;
        cnt = 0;
        getchar();
        for(i = 0;i < 60;i++)vis[i] = 0;
        for(i = 0;i < 60;i++)grp[i].clear();
        while(getline(cin, str)){
            if(str.length() == 0)break;
            grp[str[0]-'A'+1].PB(str[1]-'A'+1);
            grp[str[1]-'A'+1].PB(str[0]-'A'+1);
        }
        for(i = 1;i <= len;i++){
            if(vis[i] == 0){
                cnt++;
                DFS(i);
            }
        }
        cout << cnt << en;
        if(tc != 0)cout << en;
    }
    return 0;
}
