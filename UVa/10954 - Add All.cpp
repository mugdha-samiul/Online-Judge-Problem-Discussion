#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n, x;
    priority_queue < int > pri;
    while(cin >> n && n != 0){
        while(n--){
            cin >> x;
            pri.push(-x);
        }
        int ans = 0;
        while(pri.size() > 1){
            x = pri.top();
            pri.pop();
            x += pri.top();
            pri.pop();
            ans -= x;
            pri.push(x);
        }
        cout << ans << "\n";
        pri.pop();
    }
    return 0;
}
