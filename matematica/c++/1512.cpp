#include <bits/stdc++.h>
using namespace std;


int algoritmo_eclidiano(int B, int A);
int calcula_mmc(int B, int A);

int main()
{
    int N, A, B, C, mmc, tiles;
    
    while (cin >> N >> A >> B && N != 0){
        if (B % A == 0){
            mmc = B;
        }
        else{
            mmc = calcula_mmc(B, A);
        }
        tiles = (N / A) + (N/B) - (N/ mmc);
        cout << tiles << endl;
    }

    return 0;
}

int algoritmo_eclidiano(int B, int A){
    if (A == 0){
        return B;
    }
    return algoritmo_eclidiano(A, B%A);
}

int calcula_mmc(int B, int A){
    int mmc;
    
    mmc = (A * B)/ algoritmo_eclidiano(B, A);
    return mmc;
}
