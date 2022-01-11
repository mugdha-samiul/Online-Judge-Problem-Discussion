#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long long
 
int main(){
    priority_queue < pair < pair< int, int > , int > > pq;
    pair < pair< int, int > , int > tmp;
    pair< int, int > tmp2;
    string str;
    int num, per;
 
    while(1){
        cin >> str;
        if(str == "#")break;
        cin >> num >> per;
        pq.push(mp(mp(-per, -num), -per));
    }
 
    int koybar;
    cin >> koybar;
 
    while(koybar--){
 
        tmp = pq.top();
        tmp2 = tmp.first;
        cout << -tmp2.second << "\n";
        pq.pop();
        pq.push(mp(mp(tmp2.first + tmp.second, tmp2.second), tmp.second));
    }
 
    return 0;
}
