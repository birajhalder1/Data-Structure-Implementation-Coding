#include<iostream>
#include<stack>
#include<queue>

using namespace std;

int main()
{
    stack <int> s;
    s.push(10);
    s.push(20);
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }

    queue<int> q;
    q.push(4);
    q.push(5);
     while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }
}
