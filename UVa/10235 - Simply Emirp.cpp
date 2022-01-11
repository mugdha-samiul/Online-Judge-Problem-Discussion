#include <bits/stdc++.h>
using namespace std;
bool isprime[1000005];
void sieve(void){
    int i, j;
    for(i = 2;i < 1000005;i++){
        if(isprime[i] == 0){
            for(j = i + i;j < 1000005 ; j += i){
                isprime[j] = 1;
            }
        }
    }
}
int revrese(int n){
    int r = 0;
    while(n != 0){
        r *= 10;
        r += (n % 10);
        n /= 10;
    }
    return r;
}
int main(){
    int num;
    sieve();
    while(cin >> num){
        if(num < 2 || isprime[num] == 1)
            cout << num << " is not prime.\n";
        else if(isprime[revrese(num)] == 0 && isprime[num] == 0 && revrese(num) != num)
            cout << num << " is emirp.\n";
        else
            cout << num << " is prime.\n";
    }
    return 0;
}
