#include <bits/stdc++.h>
using namespace std;

#define endl '\n';
typedef vector<int> vi;

vi primos;
bitset<247> bs;
int teto=247, S=0;

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

int somaPrimos(int N){
    int encontrados=0;
    int p=N;
    bool primo;
    
    while (encontrados != 10){
        if (p < teto){
            if (bs[p]){
                S += p;
                encontrados ++;
            }
        }
        else{
            primo = true;
            for (int i=0; i<(int)primos.size(); i++){
                if (p % primos[i] == 0){
                    primo = false;
                    break;
                }
            }
            if (primo){
                primos.push_back(p);
                S += p;
                encontrados ++;
            }
        }
        p ++;
    }
    return S;
}

int main()
{
    int N, H;
    crivo(teto);
    
    cin >> N;
    cout<< somaPrimos(N)<< " km/h"<< endl;
    H = 60000000 / S;
    cout<< H<< " h / "<< H/24<< " d"<< endl;
    
    return 0;
}
