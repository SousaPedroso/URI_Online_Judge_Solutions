#include <iostream>

using namespace std;

int main(){
    int n, fat=1, last=1, r=0;

    cin >> n;

    while (n > 0){
        last++;
        fat *= last;
        if (fat > n){
            fat /= last;
            last --;
            while (fat > n){
                fat /= last;
                last --;
            }

            r++;
            n -= fat;
        }
    }
    cout<< r<< endl;
    return 0;
}