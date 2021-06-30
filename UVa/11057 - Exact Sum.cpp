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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll i, n, x, diff, p, q;
    while(cin >> n){
        map < ll, ll > num;
        for(i = 0;i < n;i++){
            cin >> x;
            num[x] = 1;
        }
        cin >> x;
        diff = INT_MAX;
        for(auto &a : num){
            if(a.F > x/2)break;
            if(num[x - a.F] == 1){
                if(x - a.F - a.F < diff){
                    diff = x - a.F - a.F;
                    p = a.F;
                    q = x - a.F;
                }
            }
        }
        cout << "Peter should buy books whose prices are "<< p <<" and "<< q <<".\n\n";
    }
    return 0;
}
