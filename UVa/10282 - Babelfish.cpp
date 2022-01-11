#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int i;
    string a, b, in;
    map< string, string > mymapp;
    map< string, string > :: iterator it;
 
    while(getline(cin, a)){
        if(a.size() == 0)break;
        for(i = 0;i < a.size();i++){
            if(a[i] == ' ')break;
        }
        b = a.substr(0, i);
        a = a.substr(i + 1, a.size());
        mymapp[a] = b;
    }
 
    while(cin >> a){
        if(mymapp[a] == "")cout << "eh\n";
        else cout << mymapp[a] << "\n";
    }
    return 0;
}
