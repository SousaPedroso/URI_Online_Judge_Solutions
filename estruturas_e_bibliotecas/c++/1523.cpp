#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    int N, K, carros_estacionados, first_car;
    string possivel;

    while (true){

        cin >> N >> K;
        if (N == 0){
            break;
        }

        first_car = -1;
        possivel = "Sim";
        carros_estacionados = 1;
        int horarios_estacionamento[N][2];
        vector<int> estacionamento;

        cin >> horarios_estacionamento[0][0];
        cin >> horarios_estacionamento[0][1];
        
        for (int i=1; i<N; i++){
            cin >> horarios_estacionamento[i][0];
            cin >> horarios_estacionamento[i][1];
            
            if (possivel == "Sim"){
                for (int j=i-1; j>-1; j--){
                    // Sai depois de quem ja queria sair ou entra antes e sai depois de alguem querer
                    if ((horarios_estacionamento[j][1] != -1 &&
                        horarios_estacionamento[i][0] < horarios_estacionamento[j][1] &&
                        horarios_estacionamento[i][1] > horarios_estacionamento[j][1])){
                        possivel = "Nao";
                        break;
                    }
                }
            }

            if (carros_estacionados >= K && possivel == "Sim"){
                for (int j=i-1; j>first_car; j--){
                    // Checar se nao e invalido e se ha carros para remover do estacionamento
                    if (horarios_estacionamento[j][1] != -1
                        && (horarios_estacionamento[i][0] >= horarios_estacionamento[j][1]
                        || horarios_estacionamento[i][1] > horarios_estacionamento[j][1])){
                        carros_estacionados --;
                        horarios_estacionamento[j][1] = -1;
                    }
                }
                // cout << carros_estacionados << " " << i << " " << first_car <<endl;
                // Atingiu limite de carros estacionados, nao da para estacionar
                if (carros_estacionados+1 > K){
                    possivel = "Nao";
                }
            }
            
            carros_estacionados ++;
        }
        cout << possivel <<endl;
    }

    return 0;
}