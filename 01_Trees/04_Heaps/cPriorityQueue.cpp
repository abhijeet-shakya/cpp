#include<bits/stdc++.h>
using namespace std;

int main(){

    priority_queue<int> p; // max heap

    p.push(10);
    p.push(20);
    p.push(11);
    p.push(19);
    p.push(101);
    p.push(1);

    cout << p.top() << endl;
    
    p.pop();
    cout<<p.top()<< endl;

    // size
    cout << p.size() << endl;

    while(!p.empty()){
        cout << p.top() << " ";
        p.pop();
    }cout<< endl;

    // min heap
    priority_queue<int, vector<int>, greater<int>> p2;
    p2.push(1);
    p2.push(5);
    p2.push(10);

    cout << p2.top() << endl;

    while(!p2.empty()){
        cout << p2.top() << " ";
        p2.pop();
    }cout<< endl;

    return 0; 
}