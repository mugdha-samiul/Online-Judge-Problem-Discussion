#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector < ll > vi;
typedef pair < ll, ll > pi;
#define F          first
#define S          second
#define PB         push_back
#define MP         make_pair
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define sz(x)      (int)x.size()
#define en         '\n'
#define sp         ' '
int vec[100001], st[500005];
void BuildTree(ll si, ll ss, ll se){
    if(ss == se){
        st[si] = vec[ss];
        return ;
    }
    ll mid = (ss+se) / 2;
    BuildTree((si*2)+1, ss, mid);
    BuildTree((si*2)+2, mid+1, se);
    st[si] = min(st[(si*2)+1], st[(si*2)+2]);
}
ll query(ll si, ll ss, ll se, ll s, ll e){
    if(s > se || e < ss)
        return LONG_MAX;
    if(s <= ss && e >= se)
        return st[si];
    ll mid = (ss+se)/2;
    ll l = query((si*2)+1, ss,    mid, s, e);
    ll r = query((si*2)+2, mid+1, se,  s, e);
    return min(l, r);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll n, q, s, e, tmp;
    cin >> n;
    for(int i = 0;i < n;i++)
        cin >> vec[i];

    BuildTree(0, 0, n-1);

    cin >> q;
    while(q--){
        cin >> s >> e;
        cout << query(0, 0, n-1, s, e) << en;
    }
    return 0;
}
