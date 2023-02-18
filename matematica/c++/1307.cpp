#include <iostream>
#define endl '\n';
typedef unsigned long long ull;

using namespace std;

ull mdc(ull x, ull y){
    return (y == 0? x: mdc(y, x%y));
}
 
int main() {
    int N;
    string s1, s2;
    ull n1, n2;
    
    cin >> N;
    
    for (int i=1; i<=N; i++){
        cin >> s1;
        cin >> s2;
        n1 = stoul(s1, NULL, 2);
        n2 = stoul(s2, NULL, 2);
        
        cout<< "Pair #"<< i;
        if (mdc(n1, n2) != 1){
            cout<< ": All you need is love!"<< endl;
        }
        else{
            cout<< ": Love is not all you need!"<< endl;
        }
        
    }
 
    return 0;
}