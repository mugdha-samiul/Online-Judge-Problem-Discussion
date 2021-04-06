#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef vector < pair < int, int > > vip;
typedef pair < int, int > pi;
#define F          first
#define S          second
#define PB         push_back
#define MP         make_pair
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define sz(x)      (int)x.size()
#define en         '\n'
#define sp         ' '

vi grp[100];
map < int, int > trans;
map < int, int > vis;

void BFS(int x, int y){
    queue < int > q;
    int top = x;
    vis[x] = 1;
    q.push(x);
    while(!q.empty()){
        for(auto &a : grp[top]){
            if(vis[a] == 0){
                q.push(a);
                vis[a] = vis[top] + 1;
            }
        }
        q.pop();
        top = q.front();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n, i, x, y, tc = 1, cnt;
    while(cin >> n && n != 0){
        cnt = 0;
        vis.clear();
        trans.clear();
        for(i = 0;i < 100;i++)grp[i].clear();
        for(i = 0;i < n;i++){
            cin >> x >> y;
            if(trans[x] == 0){
                cnt += 1;
                trans[x] = cnt;
            }
            if(trans[y] == 0){
                cnt += 1;
                trans[y] = cnt;
            }
            grp[trans[x]].PB(trans[y]);
            grp[trans[y]].PB(trans[x]);
        }
        while(cin >> x >> y){
            if(x == 0 && y == 0)
                break;
            for(auto &a : trans)
                vis[a.S] = 0;
            BFS(trans[x], y+1);
            int ans = 0;
            for(auto &a : vis)
                if(a.S > y+1 || a.S == 0)
                    ans++;
            cout << "Case "<< tc <<": "<< ans <<" nodes not reachable from node "<< x <<" with TTL = "<< y <<".\n";
            tc++;
        }
    }
    return 0;
}
