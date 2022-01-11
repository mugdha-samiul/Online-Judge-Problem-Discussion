#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector < ll > vi;
typedef pair < ll, ll > pi;
#define F          first
#define S          second
#define PB         push_back
#define MP         make_pair
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define sz(x)      (int)x.size()
#define en         '\n'
#define sp         ' '

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll tc;
    cin >> tc;
    string tmp;
    getline(cin, tmp);
    while(tc--){
        string str;
        getline(cin, str);
        ll len = sz(str), xx = 0;
        stack < char > s1;
        for(int i = 0;i < len;i++){
            if(str[i] == '(' || str[i] == '['){
                s1.push(str[i]);
            }
            else if(str[i] == ')' || str[i] == ']'){
                if(!s1.empty()){
                    if(str[i] == ')' && s1.top() == '(' ){
                        xx+= 2;
                        s1.pop();
                    }
                    else if(str[i] == ']' && s1.top() == '[' ){
                        xx += 2;
                        s1.pop();
                    }
                }
            }
        }
        //cout << xx << en << len << sp << str << en;
        if(xx == len)cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
