#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(i, j, n)  for(i = j;i < n;i++)
 
int main(){
 
    int num, i, j, l;
    vector< int > v;
    vector< int > :: iterator it;
    while(cin >> num && num != 0){
        for(i = 1;i <= num;i++)
            v.push_back(i);
        j = 0;
        if(num == 1)cout  << "Discarded cards:";
        else cout << "Discarded cards: ";
        while(v.size() != 1){
            l = v.size();
            for(it = v.begin() + j;it < v.end();it++){
                cout << *it;
                v.erase(it);
                if(v.size() > 1)
                    cout << ", ";
            }
            if(l % 2 == 1 && j == 0)j = 1;
            else if(l % 2 == 0 && j == 1)j = 1;
            else j = 0;
        }
        cout  << "\nRemaining card: " << v[0] << "\n";
        v.clear();
    }
    return 0;
}
