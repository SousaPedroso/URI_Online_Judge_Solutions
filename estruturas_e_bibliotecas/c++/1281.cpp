#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;

int main()
{
    int N, M, P, Q;
    map<string, float> feira;
    string fl;
    float valor, total;
    
    cin >> N;
    
    while (N--){
        cin >> M;
        total = 0;
        while (M--){
            cin>> fl >> valor;
            feira[fl] = valor;
        }
        cin >> P;
        while (P--){
            cin>> fl>> Q;
            total += Q*feira[fl];
        }
        printf("R$ %.2f\n", total);
    }

    return 0;
}