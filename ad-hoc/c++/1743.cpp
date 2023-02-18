#include <iostream>

using namespace std;

int main(){
    string x, y;
    bool plug=true;

    getline(cin, x);
    getline(cin, y);
    for(int i=0; i<9; i=i+2){
        if (x[i] == y[i]){
            plug=false;
            break;
        }
    }
    if (plug) cout<< "Y\n";
    else cout<< "N\n";

    return 0;
}