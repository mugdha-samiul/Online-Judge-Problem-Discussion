#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz(x)  (int)x.size()
#define en     '\n'
#define sp     ' '
#define pb(x)  push_back(x)
int ans, x, y;
vector < string > grid(101);
int vis[101][101];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

bool ispossible(int p, int q){
    if(p >= 0 && p < y && q >= 0 && q < x && vis[p][q] == 0 && grid[p][q] == '.')
        return 1;
    else return 0;
}

void DFS(int p, int q){
    vis[p][q] = 1;
    for(int i = 0;i < 4;i++){
        if(ispossible(p+dx[i], q+dy[i])){
            ans++;
            DFS(p+dx[i], q+dy[i]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int tc;
    cin >> tc;
    int i, j, u, v, n, m, t, tmp, p, q;
    for(t = 1;t <= tc;t++){
        cout << "Case " << t << ": ";
        cin >> x >> y;
        for(i = 0;i < y;i++)
            grid[i].resize(0);
        for(i = 0;i < y;i++){
            cin >> grid[i];
            for(j = 0;j < x;j++){
                vis[i][j] = 0;
                if(grid[i][j] == '@'){
                    p = i;
                    q = j;
                }
            }
        }
        ans = 0;
        DFS(p,q);
        cout << ans+1 << en;
    }
    return 0;
}
