#include <bits/stdc++.h>
using namespace std;
int main(){
    int num, last, ans1, i, xx;
    vector < int > bin;
    while(cin >> num && num != 0){
        last = 32, ans1 = 0, xx = num;
        while(last != -1){
            if(pow(2, last) <= num){
                num -= pow(2, last);
                bin.push_back(1);
            }
            else bin.push_back(0);
            last--;
        }
        ans1 = 0;
        int j = 0;
        for(i = 32;i >= 0;i--){
            if(bin[i] == 0)continue;
            else{
                j++;
                if(j % 2 == 0)continue;
                else
                    ans1 += pow(2, (32 - i));
            }
        }
        cout << ans1 << " " << xx - ans1 << "\n";
        bin.clear();
    }
    return 0;
}
