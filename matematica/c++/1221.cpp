#include <bits/stdc++.h>
using namespace std;

#define endl '\n';

typedef vector<int> vi;

vi primos;
bitset<32769> bs;
int teto=32768;

void crivo(int n){
    bs.set();
    bs[0] = bs[1] = 0;
    
    for (int i=2; i<=n; i++){
        if (bs[i]){
            primos.push_back(i);
            for (int j=i*i; j<=n; j+=i){
                bs[j] = 0;
            }
        }
    }
}

bool ehPrimo(long long N){
    if (N == 2){
        return true;
    }
    if (N % 2 == 0){
        return false;
    }
    if (N == 1){
        return false;
    }
    if (N <= teto){
        return bs[N];
    }
    for (int i=0; i<(int)primos.size(); i++){
        if (N % primos[i] == 0){
            return false;
        }
    }
    return true;
}

using namespace std;

int main()
{
    int N;
    crivo(teto);
    long long X;
    
    cin >> N;
    while (N--){
        cin >> X;
        if (!ehPrimo(X)){
            cout<< "Not Prime"<< endl;
        }
        else {
            cout<< "Prime"<< endl;
        }
    }

    return 0;
}