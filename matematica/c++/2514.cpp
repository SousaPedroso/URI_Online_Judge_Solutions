#include <iostream>
#define endl '\n';
typedef long long ll;
using namespace std;

ll mdc(ll x, ll y){
    return (y == 0? x: mdc(y, x%y));
}

ll mmc(ll x, ll y, ll z){
    ll mmc_x_y = (x*y)/mdc(x, y);
    return (mmc_x_y * z)/mdc(mmc_x_y, z);
}


int main()
{

    ll M;
    ll L1, L2, L3;
    
    while (cin >> M){
        cin>> L1>> L2>> L3;
        cout<< mmc(L1, L2, L3)-M<< endl;
    }

    return 0;
}