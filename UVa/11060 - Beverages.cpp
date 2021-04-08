#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector < ll > vl;
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

map < string, ll > track;
vector < string > st;
vl grp[300];
ll in[300];
vector < ll > ans;
void topo(ll n, ll m){
    ll i;
    priority_queue<ll, vector<ll>, greater<ll> > pq;
    for(i = 1;i <= n;i++){
        if(in[track[st[i-1]]] == 0){
            pq.push(track[st[i-1]]);
        }
    }
    ll tp = pq.top();
    while(!pq.empty()){
        pq.pop();
        ans.PB(tp);
        for(auto &a : grp[tp]){
            in[a]--;
            if(in[a] == 0)
                pq.push(a);
        }
        tp = pq.top();
    }
}

int main(){
    FAST
    ll i, n, m, tc = 1;
    while(cin >> n){
        string str, str2;
        ans.clear();
        st.clear();
        track.clear();
        for(i = 0;i < n;i++){
            cin >> str;
            st.PB(str);
            track[str] = i+1;
        }
        for(i = 0;i < 300;i++){
            grp[i].clear();
            in[i] = 0;
        }
        cin >> m;
        for(i = 0;i < m;i++){
            cin >> str >> str2;
            grp[track[str]].PB(track[str2]);
            in[track[str2]]++;
        }
        topo(n, m);
        cout << "Case #" << tc << ": Dilbert should drink beverages in this order: ";
        tc++;
        for(i = 0;i < n-1;i++)
            cout << st[ans[i]-1] << sp;
        cout << st[ans[i]-1] << ".\n\n";
    }

    return 0;
}
