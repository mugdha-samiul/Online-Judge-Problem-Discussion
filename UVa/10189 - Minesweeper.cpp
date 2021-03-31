#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz(x)  (int)x.size()
#define en     '\n'
#define sp     ' '
int dx[8] = {+1, +1, 0, 0, -1, -1, +1, -1};
int dy[8] = {+1, -1, 1,-1, -1, +1,  0,  0};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int r, c, tc, i, j, k;

    for(tc = 1;;tc++){
        cin >> r >> c;
        if(r == 0 && c == 0)break;
        if(tc != 1)cout << "\n";
        cout << "Field #" << tc << ":\n";
        char twod[r][c];
        int ans[r][c];

        for(i = 0;i < r;i++)
            for(j = 0;j < c;j++){
                cin >> twod[i][j];
                ans[i][j] = 0;
            }

        for(i = 0;i < r;i++)
            for(j = 0;j < c;j++){
                if(twod[i][j] == '*'){
                    ans[i][j] = -1;
                    for(k = 0;k < 8;k++)
                        if(i+dx[k] >= 0 && i+dx[k] < r && j+dy[k] >= 0 && j+dy[k] < c && ans[i+dx[k]][j+dy[k]] != -1)
                            ans[i+dx[k]][j+dy[k]]++;
                }
            }

        for(i = 0;i < r;i++){
            for(j = 0;j < c;j++){
                if(ans[i][j] == -1)cout << "*";
                else cout << ans[i][j];
            }
            cout << en;
        }
    }
    return 0;
}
