#include <iostream>
#include <cmath>

using namespace std;

int main(){
    long int n, k, m, nc;

    cin >> nc;

    for (int i=1; i<=nc; i++){
        cin >> n >> k;
        // Número mínimo de passos mais o deslocamento em função de k para quantas pessoas forem por "turno"
        m = ((n-1) * k) + pow(k, n/k);
        // O próximo é quem sobrou
        m ++;
        // O resto por n indica quem é
        m %= n;

        cout << "Case "<< i << ": "<< m <<endl;
    }

    return 0;
}