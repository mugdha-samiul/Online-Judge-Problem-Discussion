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
#define MAX        2000000
bool allFlags[MAX];
vector <ll> primes;
vector <ll> gg(2000001, 0);
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
        if(allFlags[i]==false){
            primes.push_back(i);
            gg[i] = 1;
        }
    }
    for(auto &a : primes){
        gg[a] = 1;
        for(int i = 2;i*a <= 2000000;i++){
            ll x = i*a;
            while(x%a==0){
                gg[i*a]++;
                x/=a;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    primeFinder();
    map <ll,vector <ll> > m;            //div, nums
    for(int i = 1;i <= 2000000;i++){
        m[gg[i]].PB(i);
    }
    map <ll, ll> ans;
    ll xx = 1;
    for(auto &a : m){
        for(auto &b : a.S){
            ans[xx] = b;
            xx++;
        }
    }
    ll x, tc = 1;
    while(cin >> x && x!=0){
        cout << "Case "<< tc <<": "<<ans[x] << en;
        tc++;
    }
    return 0;
}
