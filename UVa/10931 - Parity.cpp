#include <bits/stdc++.h>
using namespace std;
int main(){
    int num, last, ans, flag, x;
    while(cin >> num && num != 0){
        last = 32, ans = 0, flag = 0;
        cout << "The parity of ";
        x = num;
        while(last != -1){
            if(pow(2, last) <= num){
                num -= pow(2, last);
                flag = 1;
                cout << 1;
                ans++;
            }
            else if(flag == 1)cout << 0;
            last--;
        }
        cout <<" is " << ans << " (mod 2).\n";
    }
    return 0;
}
