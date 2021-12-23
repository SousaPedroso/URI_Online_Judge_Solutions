#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int main(){
    
    string caso_teste;
    int N, diamantes=0;


    cin >> N;
    for (int i=0; i<N; i++){
        diamantes = 0;
        vector<int> veia_esquerda;
        vector<int> veia_direita;

        cin >> caso_teste;

        for (int j=0; j<caso_teste.size(); j++){
            if (caso_teste[j] == '<'){
                veia_esquerda.push_back(j);
            }
            if (caso_teste[j] == '>'){
                veia_direita.push_back(j);
            }
        }
        int pos_veia_esquerda = 0;
        for (int j=0; j<veia_direita.size(); j++){
            for (int k=pos_veia_esquerda; k<veia_esquerda.size(); k++){
                if (veia_esquerda[k] < veia_direita[j]){
                    diamantes ++;
                    pos_veia_esquerda ++;
                    break;
                }
            }
        }

        cout << diamantes <<endl;
    }

    return 0;
}