#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F          first
#define S          second
#define PB         push_back
#define sz(x)      (int)x.size()
#define en         '\n'
#define sp         ' '

void solve(){
    ll pp;
    while(cin >> pp){
        if(pp == 0)return;
        vector < ll > nums(pp);
        for(auto &a : nums)cin >> a;
        sort(nums.begin(), nums.end());
        for(int i = 0;i < pp;i++){
            cout << nums[i];
            if(i != pp-1)cout << " ";
        }
        cout << en;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    solve();
    return 0;
}
