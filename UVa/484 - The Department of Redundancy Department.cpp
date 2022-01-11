#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int num, i;
    vector< int > vec;
    vector< int > nn;
    vector< int > :: iterator it;
    while(cin >> num){
        it = find (vec.begin(), vec.end(), num);
        if (it != vec.end()){
            nn[it - vec.begin()]++;
        }
        else{
            vec.push_back(num);
            nn.push_back(1);
        }
    }
    num = vec.size();
    for(i = 0;i < num;i++){
        cout << vec[i] << " " << nn[i] << "\n";
    }
    return 0;
}
