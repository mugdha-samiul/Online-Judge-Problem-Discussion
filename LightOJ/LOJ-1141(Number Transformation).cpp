#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < ll,ll > pl;
#define FAST       ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define rep(I,a,b) for(int I = a; I < b; I++)
#define sz(x)      (int)x.size()
#define PB         push_back
#define MP         make_pair
#define F          first
#define S          second
#define en         '\n'
#define sp         ' '

vi divisors;
int ans;


void cntdis(int top, int t){
    queue < int > q;
    q.push(top);
    vi lvl(t+1, INT_MAX), tempo;
    int temp, i, flag;
    lvl[top] = 1;
    ans = INT_MAX;

    while(!q.empty()){
        tempo.clear();
        divisors.clear();
        for(i = 2;i < top;i++)
            if(top % i == 0)
                tempo.PB(i);
        temp = top, i = 0, flag = 0;
        while(temp > 1 && i < sz(tempo)){
            while(temp % tempo[i] == 0 && temp > 1){
                temp = temp / tempo[i];
                flag = 1;
            }
            if(flag)divisors.PB(tempo[i]);
            flag = 0;
            i++;
        }

        for(auto &a : divisors){
            if(top + a <= t){
                if(lvl[top + a] == INT_MAX)
                    q.push(top+a);
                lvl[top + a] = min(lvl[top+a], lvl[top]+1);
            }
        }
        q.pop();
        top = q.front();
    }
    ans = lvl[t];
}

int main(){
    FAST
    int tc, kk;
    cin >> tc;
    for(kk = 1;kk <= tc;kk++){
        cout << "Case "<< kk <<": ";
        int s, t, i;
        cin >> s >> t;
        cntdis(s, t);
        if(ans == INT_MAX)cout << "-1\n";
        else cout << ans-1 << en;
    }
    return 0;
}
