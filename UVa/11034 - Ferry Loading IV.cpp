#include <bits/stdc++.h>
using namespace std;
int main(){
    int tc, len, cars, carlen, sum, ans;
    string side;
    queue < int > left;
    queue < int > right;
    cin >> tc;
    while(tc--){
        cin >> len >> cars;
        len *= 100;
        while(cars--){
            cin >> carlen;
            cin >> side;
            if(side == "left")left.push(carlen);
            else if(side == "right")right.push(carlen);
        }
        ans = 0;
        while(1){
            if(left.size() == 0 && right.size() == 0)break;
            sum = 0;
            while(left.size() > 0){
                sum += left.front();
                if(sum > len)break;
                left.pop();
            }
            ans++;
            if(left.size() == 0 && right.size() == 0)break;
            sum = 0;
            while(right.size() > 0){
                sum += right.front();
                if(sum > len)break;
                right.pop();
            }
            ans++;
        }
        cout << ans << "\n";
        while(!left.empty())
            left.pop();
        while(!right.empty())
            right.pop();
    }
    return 0;
}
