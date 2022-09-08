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
#define MAX        10000000

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
    primes.push_back(2);
    for(int i = 3;i < MAX;i+=2){
        if(allFlags[i]==false)primes.push_back(i);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    primeFinder();
    vector <ll> x2, y4, pp, ans;
    for(ll i = 1;i * i <= 10000000;i++)
        x2.PB(i*i);
    for(ll i = 1;i * i * i * i<= 10000000;i++)
        y4.PB(i*i*i*i);
    ll p = sz(x2), q = sz(y4);
    map <ll,ll> ss;
    for(int i = 0;i < p;i++){
        for(int j = 0;j < q;j++){
            ss[x2[i]+y4[j]]++;
        }
    }
    for(auto a: ss){
        pp.PB(a.F);
    }
    int r = sz(pp), kk = 0;
    vector <ll> hh(10000001);
    for(int i = 0;i < r && pp[i] <= 10000000;i++){
        ll x = pp[i];
        if((pp[i]%2==1 && allFlags[pp[i]]==0) || pp[i]==2){
            ans.PB(pp[i]);
        }
    }
    ans.PB(10000005);
    ll tc;
    cin >> tc;
    while(tc--){
        ll n, chk=0;
        cin >> n;
        auto it = lower_bound(ans.begin(), ans.end(), n);
        chk = (it-ans.begin());
        if(ans[chk]>n)chk--;
        cout << chk+1 << en;
    }
    return 0;
}
