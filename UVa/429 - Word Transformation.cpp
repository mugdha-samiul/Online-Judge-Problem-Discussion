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

vector < ll > grp[300];
vector < ll > vis(300);
ll pp;

void DFS(ll src, ll lvl){
    vis[src] = lvl+1;
        for(auto &a : grp[src])
            if((vis[a] >= vis[src]+1 || vis[a] == 0) && a != pp)
                DFS(a, vis[src]);
}

bool comp(string s1, string s2){
    if(sz(s1) != sz(s2))return 0;
    int i, x = sz(s1), cnt = 0;
    for(i = 0;i < x;i++)
        if(s1[i] != s2[i])cnt++;
    if(cnt == 1)return 1;
    else return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll tc, i, j, tmp, n, u, v;
    string str, s1, s2;
    cin >> tc;
    while(tc--){
        for(i = 0;i < 300;i++) grp[i].clear();
        map < string, ll > rel;
        map < ll, string > rev;
        tmp = 1;
        while(cin >> str){
            if(str == "*"){break;}
            rel[str] = tmp;
            rev[tmp] = str;
            tmp++;
        }
        n = tmp - 1;
        for(i = 1;i <= n;i++){
            for(j = i + 1;j <= n;j++){
                if(comp(rev[i], rev[j])){
                    grp[i].PB(j);
                    grp[j].PB(i);
                }
            }
        }

        int xx = 0;
        //getchar();
        while(1){

            getline(cin, str);

            if(str.length() == 0)xx++;
            if(xx == 2)break;
            tmp = str.length() / 2;
            s1 = "", s2 = "";
            for(i = 0;i < tmp;i++){
                s1 += str[i];
                s2 += str[i+tmp+1];
            }
            u = rel[s1], v = rel[s2];
            pp = u;
            DFS(u, -1);
            if(s1 == ""){for(i = 0;i < 300;i++) vis[i] = 0;continue;}
            cout <<s1 << sp << s2 << sp << vis[v] << "\n";
            for(i = 0;i < 300;i++) vis[i] = 0;
        }
        if(tc != 0) cout << "\n";
    }
    return 0;
}
