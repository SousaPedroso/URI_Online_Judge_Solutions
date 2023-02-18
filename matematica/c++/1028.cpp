#include <iostream>
#define endl '\n';

using namespace std;

int mdc(int x, int y){
    return (y ==0 ? x: mdc(y, x%y));
}
 
int main() {
    int N;
    int F1, F2;
    
    cin>> N;
    while (N--){
        cin>> F1>> F2;
        cout<< mdc(F1, F2)<< endl;
    }
    return 0;
}