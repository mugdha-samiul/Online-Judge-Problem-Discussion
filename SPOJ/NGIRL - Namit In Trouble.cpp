#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F          first
#define S          second
#define PB         push_back
#define sz(x)      (int)x.size()
#define en         '\n'
#define sp         ' '
#define inf        LONG_LONG_MAX
#define MAX        100000

bool allFlags[MAX];
vector <ll> primes;

void primeFinder(){
    for(ll i = 3;i*i < MAX;i+=2){      //we'll only work with odd numbers, i <= sqrt(MAX) will be enough to flag all the composites
        if(allFlags[i] == false){       //if prime then mark all of its multiples
            for(ll j = i*i;j < MAX;j+=(i+i)){       //j=i*i will skip some of the prime marking from overlapping, j+=i will be even we only work with odd in this function, so we'll use j+=(i+i)
                allFlags[j] = true;
            }
        }
    }
    primes.push_back(2);                //the only even prime is 2
    for(int i = 3;i < MAX;i+=2){        //all the odd numbers will be checked if it's a prime or not
        if(allFlags[i]==false)primes.push_back(i);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll tc, nn;
    vector <ll> gg;
    cin >> tc;
    primeFinder();
    nn = sz(primes);
    for(int i = 0;i < nn;i++){
        gg.PB(primes[i]*primes[i]);
    }
    while(tc--){
        ll n, k, cnt = 0, cnt2 = 0;
        cin >> n >> k;
        nn = sz(gg);
        for(int i = 0;i < nn;i++){
            if(gg[i] > n){break;}
            cnt++;
            if(gg[i] > k){cnt2++;}
        }
        cout << cnt << sp << cnt2 << en;
    }
    return 0;
}
