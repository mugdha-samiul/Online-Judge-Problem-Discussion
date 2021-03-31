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

vector < string > ss(27);
int dx[] = {0, 0, 1,-1, 1, -1, 1,-1};
int dy[] = {1,-1, 0, 0, 1, -1,-1, 1};
int arr[27][27];

void dfs(int x, int y, int n){
    arr[x][y] = 1;
    for(int i = 0;i < 8;i++){
        if(x+dx[i] >= 0 && x+dx[i] < n && y+dy[i] >= 0 && y+dy[i] < n){
            if(ss[x+dx[i]][y+dy[i]] == '1'  && arr[x+dx[i]][y+dy[i]] == 0)
                dfs(x+dx[i], y+dy[i], n);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n, tc = 1;
    while(cin >> n){
        int i, j, cnt = 0;

        ss.clear();
        for(i = 0;i < 27;i++)
            for(j = 0;j < 27;j++)
                arr[i][j] = 0;

        for(i = 0;i < n;i++)
            cin >> ss[i];

        for(i = 0;i < n;i++){
            for(j = 0;j < n;j++){
                if(arr[i][j] == 0){
                    arr[i][j] = 1;
                    if(ss[i][j] == '1'){
                        dfs(i, j, n);
                        cnt++;
                    }
                }
                else
                    continue;
            }
        }
        cout << "Image number " << tc << " contains "<< cnt <<" war eagles." << en;
        tc++;
    }

    return 0;
}
