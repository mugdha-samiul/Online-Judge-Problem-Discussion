#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
bool descent(int a, int b){
    return (a > b);
}
int main(){
    int n, five, num, l, ans;
    map< vector< int > , int> mymap;
    map< vector< int > , int> :: iterator it;
    vector< int > vec;
    while(cin >> n && n != 0){
        l = n;
        while(n--){
            five = 5;
            while(five--){
                cin >> num;
                vec.push_back(num);
            }
            sort(vec.begin(), vec.end());
            it = mymap.find(vec);
            if(it == mymap.end())mymap[vec] = 1;
            else mymap[vec] = it->second + 1;
            vec.clear();
        }
        for( auto &itt : mymap){
            vec.push_back(itt.second);
        }
        sort(vec.begin(), vec.end(), descent);
        ans = 0;
        for( auto &itt : vec){
            if(itt == vec[0])ans++;
            else break;
        }
        vec.clear();
        mymap.clear();
        cout << ans * vec[0] << "\n";
    }
    return 0;
}
