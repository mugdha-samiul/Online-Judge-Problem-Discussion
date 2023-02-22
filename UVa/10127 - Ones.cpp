#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define F          first
#define S          second
#define PB         push_back
#define sz(x)      (int)x.size()
#define en         '\n'
#define sp         ' '
#define inf        LONG_LONG_MAX

ll num=0;

ll flag(string str){
    ll n = 0;
    for(int i = 0;i < sz(str);i++){
        ll x = str[i] - '0';
        n = n*10;
        n = n%num;
        n = n+x;
        n = n%num;
    }
    if(n==0)return 1;
    else return 0;
}
ll gg(string str){
    if(flag(str)==1){
        return sz(str);
    }
    ll pp = gg((str+"1"));
    return pp;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    while(cin >> num){
        cout << gg("1") << en;
    }
    return 0;
}
