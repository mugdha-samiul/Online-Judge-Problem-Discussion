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
int r, c, m, n;
int px[8] = {1,-1, 2,-1, 1,-2,-2, 2};
int py[8] = {2,-2,-1, 2,-2, 1,-1, 1};
int dx[8], dy[8];
int mapp[150][150], vis[150][150];

void visit(int p, int q){
    vis[p][q] = 1;
    map < pair< int, int >, int >track;
    for(int i = 0;i < 8;i++){
        if(track[{dx[i], dy[i]}] > 0)continue;
        else track[{dx[i], dy[i]}]++;
        if(p+dx[i] >= 0 && q+dy[i] >= 0 && p+dx[i] < r && q+dy[i] < c && mapp[p+dx[i]][q+dy[i]] != -1){
            mapp[p][q]++;
            if(vis[p+dx[i]][q+dy[i]] == 0)visit(p+dx[i], q+dy[i]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int tc, i, j, water, x, y, kk;
    cin >> tc;
    for(kk = 1;kk <= tc;kk++){
        cout << "Case " << kk << ": ";
        cin >> r >> c >> m >> n >> water;

        for(i = 0;i < 150;i++)
            for(j = 0;j < 150;j++)
                mapp[i][j] = 0, vis[i][j] = 0;

        for(i = 0;i < water;i++){
            cin >> x >> y;
            mapp[x][y] = -1, vis[x][y] = 1;
        }

        for(i = 0;i < 8;i++){
            if(abs(px[i]) == 1)dx[i] = px[i] * m;
            else dx[i] = (px[i]/2) * n;
            if(abs(py[i]) == 1)dy[i] = py[i] * m;
            else dy[i] = (py[i]/2) * n;
        }

        visit(0, 0);

        int even = 0, odd = 0;
        for(i = 0;i < 150;i++)
            for(j = 0;j < 150;j++){
                if(mapp[i][j] > 0 && mapp[i][j] % 2 == 1)odd++;
                else if(mapp[i][j] > 0 && mapp[i][j] % 2 == 0)even++;
            }
        if(even == 0 && odd == 0)cout << "1 0\n";
        else cout << even << sp << odd << en;
    }
    return 0;
}
