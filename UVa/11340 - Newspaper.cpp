#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(i, j, n)  for(i = j;i < n;i++)
 
int main(){
    int tc, n, i;
    cin >> tc;
    double tmp, ans;
    char ch;
    string str;
    map< char, double >mymap;
    map< char, double > :: iterator it;
    while(tc--){
        ans = 0;
        cin >> n;
        while(n--){
            cin >> ch;
            cin >> tmp;
            mymap[ch] = tmp;
        }
        cin >> n;
        getchar();
        while(n--){
            getline(cin, str);
            for(i = 0;i < str.size();i++){
                it = mymap.find(str[i]);
                if(it != mymap.end())
                    ans += it->second;
            }
        }
        cout << fixed << setprecision(2) <<ans/100 << "$\n";
        mymap.clear();
    }
    return 0;
}
