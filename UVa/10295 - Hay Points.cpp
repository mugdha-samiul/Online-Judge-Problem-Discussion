#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    int n, tc, tmp;
    string ss;
    cin >> n >> tc;
    map < string, int > mymap;
    while(n--){
        cin >> ss;
        cin >> tmp;
        mymap[ss] = tmp;
    }
    int ans = 0;
    while(tc--){
        ans = 0;
        while(cin >> ss && ss != "."){
            ans += mymap[ss];
        }
        cout << ans << "\n";
    }
    return 0;
}
