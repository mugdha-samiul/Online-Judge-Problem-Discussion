#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void myfunction(int nn){
    stack< int >stacka;
    stack< int >stackb;
    stack< int >station;
    int tmp;
    while(1){
        for(int i = nn;i >= 1;i--)
            stacka.push(i);
        for(int i = nn;i >= 1;i--){
            cin >> tmp;
            if (tmp == 0)return;
            station.push(tmp);
        }
        while(!station.empty()){
            tmp = station.top();
            stackb.push(tmp);
            station.pop();
        }

        while(!stackb.empty()){
            if(stacka.size() != 0 && stacka.top() == stackb.top()){
                stacka.pop();
                stackb.pop();
            }
            else if(station.size() != 0 && stackb.top() == station.top()){
                stackb.pop();
                station.pop();
            }
            else if(stacka.size() != 0 && stacka.top() < stackb.top()){
                tmp = stacka.top();
                stacka.pop();
                station.push(tmp);
            }
            else
                break;
            }
            if(station.size() == 0 && stacka.size() == 0 && stackb.size() == 0)
                cout << "Yes\n";
            else
                cout << "No\n";
            while(!station.empty())station.pop();
            while(!stacka.empty())stacka.pop();
            while(!stackb.empty())stackb.pop();
        }
    }
int main(){
    
    int n;
    while(cin >> n && n != 0){
        myfunction(n);
        cout << "\n";
    }
    return 0;
}
