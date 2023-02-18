#include <iostream>
#define endl '\n'
#define fori(i, n) for(int i=0; i<n; i++)
using namespace std;

int f(int n, int k){
    if (n == 1) return 1;
    
    return (f(n-1, k)+ k-1) % n+1;
}

int main()
{
    int t, n, k, m;
    cin >> t;
    fori(i, t){
        cin >> n >> k;
        m = f(n, k);
        cout<< "Case "<< i+1<< ": "<< m<< endl;
    }

    return 0;
}