#include <bits/stdc++.h>
using namespace std;
int main(){
    int cas = 1, road, alph, tmp;
    while(1){
        cin >> road >> alph;
        if( road == 0 && alph == 0)break;
        cout << "Case " << cas << ": ";
        tmp = ceil((double)road / (double)alph);
        tmp--;
        if(tmp > 26)cout << "impossible\n";
        else cout << tmp << "\n";
        cas++;
    }
    return 0;
}
