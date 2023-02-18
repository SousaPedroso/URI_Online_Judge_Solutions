#include <iostream>
#define endl '\n';

using namespace std;

int mdc(int x, int y){
    return (y == 0? x: mdc(y, x%y));
}

int main()
{
    int a, p, e, c;
    
    
    while (cin >> a >> p >> e){
        c = mdc(a, p);
        // Checa se a quantidade de pacotes com canetas (c)
        // é >= ao número de equipes
        if (a/c + p/c >= e){
            cout<< "sim"<< endl;
        }
        else {
            cout<< "nao"<< endl;
        }
    }

    return 0;
}
