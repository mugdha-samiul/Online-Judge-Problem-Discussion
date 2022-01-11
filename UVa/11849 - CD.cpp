#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(i, j, n)  for(i = j;i < n;i++)

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
	while(1){
        int n1, n2, cnt = 0, i = 0, j = 0;
        cin >> n1 >> n2;
        if(n1 == n2 && n2 == 0)break;
        vector< int > v1(n1);
        vector< int > v2(n2);
        for(int &it : v1) cin >> it;
        for(int &it : v2) cin >> it;
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        while(1){
            if(i == n1 || j == n2)break;
            if(v1[i] == v2[j]){
                i++;j++;
                cnt++;
            }
            else if(v1[i] > v2[j])
                j++;
            else if(v1[i] < v2[j])
                i++;
        }
        cout << cnt << "\n";
    }
    return 0;
}
