#include <iostream>
#include <map>

#define endl '\n';

using namespace std;

int main()
{
    int M, N, v, S, p, lp;
    string C, D;
    map<string, int> dicionario;
    
    cin >> M>> N;

    while (M--){
        cin >> C>> v;
        dicionario[C] = v;
    }
    
    for (int i=0; i<N; i++){
        S=0;
        cin>> D;
        while (D.compare(".") > 0){
            if (dicionario.find(D) != dicionario.end()){
                S += dicionario[D];
            }
            cin >> D;
        }
        cout<< S<< endl;
    }
    
    return 0;
}
