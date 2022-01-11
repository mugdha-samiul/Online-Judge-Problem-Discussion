#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(i, j, n)  for(i = j;i < n;i++)

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
	int num, i = 0, ans;
	vector< int > v;
    while(cin >> num){
        i++;
        v.push_back(num);
        sort(v.begin(), v.end());
        if(i&1)ans = v[i / 2];
        else ans = (v[i / 2] + v[(i / 2) - 1]) / 2;
        cout << ans << "\n";
    }
    return 0;
}
