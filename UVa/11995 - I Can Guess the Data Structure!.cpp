#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    stack < int > mystack;
    queue < int > myqueue;
    priority_queue < int > mypri;
    int n, comm, data;
    while(cin >> n){
        bool flag1 = 0, flag2 = 0, flag3 = 0;
        while(n--){
            cin >> comm >> data;
            if(comm == 1){
                if(flag1 == 0)mystack.push(data);
                if(flag2 == 0)myqueue.push(data);
                if(flag3 == 0)mypri.push(data);
            }
            else if(comm == 2){
                if(flag1 == 0 && mystack.size() > 0 && mystack.top() == data)mystack.pop();
                else flag1 = 1;
 
                if(flag2 == 0 && myqueue.size() > 0 && myqueue.front() == data)myqueue.pop();
                else flag2 = 1;
 
                if(flag3 == 0 && mypri.size() > 0 && mypri.top() == data)mypri.pop();
                else flag3 = 1;
            }
        }
        int bro = flag1 + flag2 + flag3;
 
        if(bro == 3)cout << "impossible\n";
        else if(bro != 2)cout << "not sure\n";
        else{
            if(flag1 == 0)cout << "stack\n";
            else if(flag2 == 0)cout << "queue\n";
            else if(flag3 == 0)cout << "priority queue\n";
        }
        while(!mystack.empty())mystack.pop();
        while(!myqueue.empty())myqueue.pop();
        while(!mypri.empty())mypri.pop();
    }
    return 0;
}
