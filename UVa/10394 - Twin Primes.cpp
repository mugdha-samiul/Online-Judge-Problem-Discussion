#include <bits/stdc++.h>
using namespace std;
bool isprime[20000005];
vector < pair < int, int >> value;
void sieve(void){
    int i, j;
    for(i = 2;i < 20000005;i++){
        if(isprime[i] == 0){
            for(j = i + i;j < 20000005 ; j += i){
                isprime[j] = 1;
            }
        }
    }
}
void makevalue(void){
    int i, j = 1;
    for(i = 3;i < 20000005;i = i + 2){
        if(isprime[i] == 0 && isprime[i + 2] == 0){
            value.push_back(make_pair(i, i + 2));
            j++;
        }
        if(j > 100001)break;
    }
}
int main(){
    int num;
    sieve();
    makevalue();
    while(cin >> num){
        cout << "(" << value[num - 1].first << ", " << value[num - 1].second << ")\n";
    }
    return 0;
}
