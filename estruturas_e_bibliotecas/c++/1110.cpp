#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'
 
int main() {
    int n, i;
    cin >> n;
    while (n != 0){
        i = 2;
        queue<int> cartas;
        
        
        if (n > 3){
            cout<< "Discarded cards: ";
            
            while (i <= n){
                cartas.push(i);
                cout<< i-1<< ", ";
                i += 2;
            }
            
            if (cartas.size() != 1 && n%2 != 0){
                cout<< n<< ", ";
            }
            
            if (cartas.size() != 1 && n%2 == 0){
                cout<< cartas.front()<< ", ";
                cartas.pop();
            }
            
            while (cartas.size() != 1){
                cartas.push(cartas.front());
                cartas.pop();
                if (cartas.size() != 2){
                    cout<< cartas.front()<< ", ";
                }
                else {
                    cout<< cartas.front()<< endl;
                }
                cartas.pop();
            }
    
            cout<< "Remaining card: "<< cartas.front()<< endl;
        }
        // Casos com tratamento
        else {
            if (n == 1){
                cout<< "Remaining card: "<< 1 << endl;
            }
            else if (n == 2){
                cout<< "Discarded cards: "<< 1 << endl;
                cout<< "Remaining card: "<< 2 << endl;
            }
            else {
                cout<< "Discarded cards: 1, 3"<< endl;
                cout<< "Remaining card: "<< 2 << endl;   
            }
        }
        cin >> n;
    }
 
    return 0;
}