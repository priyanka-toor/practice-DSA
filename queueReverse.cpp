#include<iostream>
using namespace std;
#include<queue>
void reverseQueue(queue<int> &input){
    int temp=input.front();
    if(input.size()==1){
        return;
    }
    input.pop();
     reverseQueue(input);
    input.push(temp);  
}
int main()
{
     queue<int> q;
        int size;
        cin >> size;

        for (int i = 0, val; i < size; i++) {
            cin >> val;
            q.push(val);
        }

        reverseQueue(q);
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }
    return 0;
}