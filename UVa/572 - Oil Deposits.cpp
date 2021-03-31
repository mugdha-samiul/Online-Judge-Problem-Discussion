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

vector < string > ss(101);
int dx[] = {0, 0, 1,-1, 1, -1, 1,-1};
int dy[] = {1,-1, 0, 0, 1, -1,-1, 1};
int arr[101][101];

void dfs(int x, int y, int n, int m){
    arr[x][y] = 1;
    for(int i = 0;i < 8;i++){
        if(x+dx[i] >= 0 && x+dx[i] < n && y+dy[i] >= 0 && y+dy[i] < m){
            if(ss[x+dx[i]][y+dy[i]] == '@'  && arr[x+dx[i]][y+dy[i]] == 0)
                dfs(x+dx[i], y+dy[i], n, m);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n, m, tc = 1;
    while(1){
        cin >> n >> m;
        if(n == 0 && m == 0)break;

        int i, j, cnt = 0;

        ss.clear();
        for(i = 0;i < 101;i++)
            for(j = 0;j < 101;j++)
                arr[i][j] = 0;

        for(i = 0;i < n;i++)
            cin >> ss[i];

        for(i = 0;i < n;i++){
            for(j = 0;j < m;j++){
                if(arr[i][j] == 0){
                    arr[i][j] = 1;
                    if(ss[i][j] == '@'){
                        dfs(i, j, n, m);
                        cnt++;
                    }
                }
                else
                    continue;
            }
        }
        cout << cnt << en;
    }

    return 0;
}
