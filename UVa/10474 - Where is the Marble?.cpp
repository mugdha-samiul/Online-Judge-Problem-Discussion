#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    int n, q, x, cnt = 1, bro = 1;
    vector < int > vec;
    vector < int > :: iterator it;
    while(cin >> n && cin >> q){
        if(n == 0 && q == 0)break;
        cout << "CASE# " << cnt << ":\n";
        while(n--){
            cin >> x;
            vec.push_back(x);
            bro++;
        }
        sort(vec.begin(), vec.end());
        while(q--){
            cin >> x;
            it = find(vec.begin(), vec.end(), x);
            if(it == vec.end())
                cout << x << " not found\n";
            else
                cout << x << " found at " << it - vec.begin() + 1<< "\n";
        }
        vec.clear();
        cnt++;
    }
    return 0;
}
