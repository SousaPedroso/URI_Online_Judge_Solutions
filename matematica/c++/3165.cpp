#include <bits/stdc++.h>

#define endl '\n';
using namespace std;

vector<int> primos;
bitset<33> bs;
int teto=32;
stack<int> gemeos;

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

bool ehPrimo(int n){
    if (n <= teto){
        return bs[n];
    }
    else{
        for (int i=0; i<(int) primos.size(); i++){
            if (n % primos[i] == 0){
                return false;
            }
        }
    }
    return true;
}


int main()
{
    crivo(32);
    int N, anterior=0, encontrado=false;
    
    cin >> N;
    if (ehPrimo(N)){
        gemeos.push(N);
    }
    N--;
    while (!encontrado){
        if (ehPrimo(N)){
            if (gemeos.size() != 0){
                anterior = gemeos.top();
            }
            gemeos.push(N);
            if (anterior - gemeos.top() == 2){
                encontrado = true;
            }
        }
        N--;
    }
    cout<< gemeos.top()<< " ";
    gemeos.pop();
    cout<< gemeos.top()<< endl;

    return 0;
}