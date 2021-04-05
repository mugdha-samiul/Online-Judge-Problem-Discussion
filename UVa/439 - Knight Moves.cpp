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

int dx[] = {1, 2, 2, 1,-1,-2,-1,-2};
int dy[] = {2, 1,-1,-2, 2, 1,-2,-1};
int vis[9][9];
queue < pair < int, int > > pp;

void BFS(int x1, int y1){
    vis[x1][y1] = 1;
    pi top = {x1, y1};
    pp.push(top);
    int i;
    while(!pp.empty()){
        for(i = 0;i < 8;i++){
            if(top.F+dx[i] > 0 && top.F+dx[i] < 9 && top.S+dy[i] > 0 && top.S+dy[i] < 9){
                if(vis[top.F+dx[i]][top.S+dy[i]] == 0){
                    vis[top.F+dx[i]][top.S+dy[i]] = vis[top.F][top.S] + 1;
                    pp.push({top.F+dx[i], top.S+dy[i]});
                }
            }
        }
        pp.pop();
        top = pp.front();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string st1, st2;
    while(cin >> st1){
        cin >> st2;
        int x1, x2, y1, y2, i , j;
        x1 = st1[0] - 'a' + 1;
        x2 = st2[0] - 'a' + 1;
        y1 = st1[1] - '0';
        y2 = st2[1] - '0';

        for(i = 0;i < 9;i++)
            for(j = 0;j < 9;j++)
                vis[i][j] = 0;
        while(!pp.empty())pp.pop();

        BFS(x1, y1);
        cout << "To get from "<< st1 <<" to "<< st2 <<" takes "<< vis[x2][y2] - 1 <<" knight moves.\n";
    }
    return 0;
}
