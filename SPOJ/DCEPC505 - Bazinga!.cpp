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
#define MAX        10000000                   //total numbers to check
#define araMAX     10000000/32                //size of flag array; 32 because flag is stored in int type array
int flag[araMAX];

void bitSieve(){
    for(int i = 2;i*i <= MAX;i++){
        if((flag[i/32] & (1<<(i%32))) == 0){           /*i/32 decides which number of the array,
                                                        i%32 decides which bit of the number,
                                                        1<<(i%32) shifts 1 to (i%32) times to the left,
                                                            for example: 1<<5
                                                            1    -> 000...0000001
                                                            1<<5 -> 000...0100000
                                                        flag[i/32] holds the Primality flag of 32 numbers: 0-31, 32-63...
                                                        ((flag[i/32] & (1<<(i%32))) ->
                                                        for 141, ((flag[4] & (1<<13)) will check
                                                            if bit 13(from right) of flag[4] is 1(composite) or not
                                                        if(i=141) is prime then next lines will execute.
                                                        */

            for(int j = i*i;j <= MAX;j+=i){
                flag[j/32] |= (1<<(j%32));              /*this line will set the given bit of the given number to 1
                                                        suppose, flag[4] = 000...001010101
                                                        for 132, i/32 = 4, i%32 = 4,
                                                        so, 4th bit of flag[4] will be 1. How?
                                                        Firstly, 1<<4 will return 000...0001000
                                                        flag[4] | (1<<4) will set 4 th bit to 1
                                                        000...001010101
                                                        000...000001000
                                                        ----------------
                                                        000...001011101
                                                        this is how 132 will be flagged to composite.
                                                        */
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    bitSieve();
    vector <ll> primes(1,2);
    for(ll i = 3;i <= MAX;i+=2){
        if((flag[i/32] & (1<<(i%32))) == 0)primes.PB(i);
    }
    ll kk = sz(primes);
    //cout << kk << en;
    map <ll,ll> gg;
    vector <ll> all;
    ll pp = 0;
    for(ll x = 0; x < kk;x++){
        for(ll y = x+1;y < kk;y++){
            //if(primes[x]*primes[y] > 13400000)break;
            if(primes[x]*primes[y] > 10527451)break;
            all.PB(primes[x]*primes[y]);
            pp++;
        }
    }
    sort(all.begin(), all.end());
    //cout << sz(all) << sp << all[2000000] << en;
    cin >> kk;
    while(kk--){
        ll ggg;
        cin >> ggg;
        cout << all[ggg-1] << en;
    }
    return 0;
}
