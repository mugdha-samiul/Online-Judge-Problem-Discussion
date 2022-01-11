#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(i, j, n)  for(i = j;i < n;i++)
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n, m, p, a, i;
    vector< int > vv;
    while(cin >> n){
        cin >> m;
        if(n == 1){
            cout << "Jolly\n";
            continue;
        }
        p = n - 1;
        while(p--){
            cin >> a;
            m = abs(m - a);
            vv.push_back(m);
            m = a;
        }
        sort(vv.begin(), vv.end());
        int flag = 2;
        for(i = 1;i < n - 1;i++)
            if(vv[i] == vv[i - 1]){
                flag = 5;
                break;
            }
        if(vv[n - 2] != n - 1 || vv[0] != 1)flag = 5;
        if(flag == 2)cout << "Jolly\n";
        else cout << "Not jolly\n";
        vv.clear();
    }
    return 0;
}
