#include <iostream>

using namespace std;

int main(){
    int t, n;
    while (cin >> t >> n, t != 0) {
        int soma = 0;
        for (int i = 0; i < t; i++) {
            string time;
            int p;
            cin >> time >> p;
            soma += p;
        }

        for (int vit = 0; vit <= soma/3; vit++) {
            int resto = soma - vit*3;
            if (resto % 2 == 0) {
                int partidas = vit + resto / 2;
                if (partidas == n) {
                    cout << resto / 2 << endl;
                    break;
                }
            } 
        }
    }
    return 0;
}