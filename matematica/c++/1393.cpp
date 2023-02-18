#include <iostream>
#include <string.h>

using namespace std;

int memo[41], n;

int f(int i){
    if (i > n) return 0;
    if (i == n) return 1;
    if (memo[i] != -1) return memo[i];

    return memo[i] = f(i+1)+f(i+2);
}

int main(){
    ios_base::sync_with_stdio(false);

    while (cin >> n && n != 0){
        memset(memo, -1, sizeof memo);
        cout<< f(0)<<endl;
    }

    return 0;
}