#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX        10000000
bool allFlags[MAX];
vector <ll> primes;
void primeFinder(){
    for(ll i = 3;i*i < MAX;i+=2){
        if(allFlags[i] == false){
            for(ll j = i*i;j < MAX;j+=(i+i)){
                allFlags[j] = true;
            }
        }
    }
    primes.push_back(2);
    for(int i = 3;i < MAX;i+=2){
        if(allFlags[i]==false)primes.push_back(i);
    }
}
void segSieve(ll L, ll R){
    bool RangeFlag[R-L+1];
    for(ll i = 0; i < R-L+1;i++)RangeFlag[i] = 0;
    if(L == 1)RangeFlag[0] = 1;

    for(ll i = 0; primes[i]*primes[i] <= R; i++){
        ll curPrime = primes[i];
        ll composite = ((L+curPrime-1)/curPrime)*curPrime;

        if(composite < L || composite == curPrime)composite += curPrime;
        for(;composite <= R;composite+=curPrime){
            RangeFlag[composite-L] = 1;
        }
    }
    for(ll i = 0;i < R-L+1;i++){
        if(RangeFlag[i]==0)
            cout << i+L << endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    primeFinder();
    ll r, l, tc;
    cin >> tc;
    while(tc--){
        cin >> l >> r;
        segSieve(l,r);
    }

    return 0;
}
