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
    int n, k, p, tmp;
    cin >> n >> k >> p;
    tmp = p % n;
    k += tmp;
    k %= n;
    if(k == 0)k = n;
    cout << k << en;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int tc = 1;
    cin >> tc;
    for(int j = 1;j <= tc;j++){
        cout << "Case "<< j <<": ";
        solve();
    }
    return 0;
}
