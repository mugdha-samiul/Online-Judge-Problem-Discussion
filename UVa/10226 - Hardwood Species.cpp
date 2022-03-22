#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F          first
#define S          second
#define PB         push_back
#define sz(x)      (int)x.size()
#define en         '\n'
#define sp         ' '

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll tc, tmp, tot;
    string str;
    cin >> tc;
    getline(cin, str);
    getline(cin, str);
    while(tc--){
        tot = 0;
        map < string, ll > record;
        while(getline(cin, str)){
            if(sz(str) == 0)
                break;
            record[str]++;
        tot++;
        }
        for( auto &a :record)
            cout << a.first << " " << fixed << setprecision(4) << ((double)a.second/(double)tot)*100.0 << "\n";
        if(tc > 0)cout << "\n";
    }
    return 0;
}
