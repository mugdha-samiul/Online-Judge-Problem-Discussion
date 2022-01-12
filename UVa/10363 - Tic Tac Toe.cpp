#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F          first
#define S          second
#define PB         push_back
#define sz(x)      (int)x.size()
#define en         '\n'
#define sp         ' '

void solve(){
    vector < string > board(3);
    cin >> board[0] >> board[1] >> board[2];
    ll xx = 0, oo = 0, p, q;
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            if(board[i][j] == 'X')xx++;
            else if (board[i][j] == 'O') oo++;
        }
    }
    if(!(xx - oo == 0 || xx - oo == 1)){
        cout << "no\n";
        return;
    }
    p = xx, q = oo;
    xx = 0, oo = 0;
    for(auto &a : board){
        if(a == "XXX")xx++;
        else if(a == "OOO")oo++;
    }
    int x, o;
    for(int i = 0;i < 3;i++){
        x = 0, o = 0;
        for(int j = 0;j < 3;j++){
            if(board[j][i] == 'X')x++;
            else if(board[j][i] == 'O')o++;
        }
        if(x == 3)xx++;
        if(o == 3)oo++;
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == 'X')xx++;
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == 'O')oo++;
    if(board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[0][2] == 'X')xx++;
    if(board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[0][2] == 'O')oo++;
    if(xx > 2 || oo > 2 || (xx > 0 && oo > 0) || (oo > 0 && p != q) || (xx > 0 && p-1 != q)){
        cout << "no\n";
        return;
    }
    else
        cout << "yes\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll tc = 1;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}
