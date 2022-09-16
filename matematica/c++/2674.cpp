#include <bits/stdc++.h>

using namespace std;
#define endl '\n';

bitset<318> bs;
vector<int> primos;
int teto=317;

void crivo(int n){
    bs.set();
    bs[0] = bs[1] = 0;
    
    for (int i=2; i<=n; i++){
        if (bs[i]){
            primos.push_back(i);
            for (int j=i*i; j<=n; j+=i){
                bs[j]=0;
            }
        }
    }
}

bool ehPrimo(int n){
    if (n <= teto){
        return bs[n];
    }
    for (int i=0; i<(int)primos.size(); i++){
        if (n % primos[i] == 0){
            return false;
        }
    }
    return true;
}

int main()
{
    int N;
    crivo(teto);
    
    while (cin >> N){
        if (ehPrimo(N)){
            while (ehPrimo(N % 10) && N > 10){
                N /= 10;
            }
            if (ehPrimo(N%10)){
                cout<< "Super"<< endl;
            }
            else {
                cout<< "Primo"<< endl;
            }
        }
        else{
            cout<< "Nada"<< endl;
        }
    }

    return 0;
}