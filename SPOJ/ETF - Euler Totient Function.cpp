#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 1000001
vector <ll> PHI(MAX);
void PHI_generator(){
    for(ll i = 1; i < MAX;i++)
        PHI[i] = i;
    for(ll i = 2;i < MAX;i++){
        if(PHI[i] == i){
            for(ll j = i;j < MAX;j+=i){
                PHI[j] /= i;
                PHI[j] *= (i-1);
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    PHI_generator();
    ll tc, n;
    cin >> tc;
    while(tc--){
        cin >> n;
        cout << PHI[n] << endl;
    }
    return 0;
}
