#include <iostream>
#include <queue>
 
using namespace std;
#define endl '\n';
 
int main() {
 
    string s;
    bool correct;
    
    while (cin >> s){
        queue<int> q;
        correct = true;
        
        for (auto c: s){
            if (c - '(' == 0){
                q.push(1);
            }
            else if (c - ')' == 0){
                if (q.size() == 0){
                    correct = false;
                    break;
                }
                q.pop();
            }
        }
        if (correct && q.size() == 0){
            cout<< "correct"<< endl;
        }
        else {
            cout<< "incorrect"<< endl;
        }
    }
 
    return 0;
}