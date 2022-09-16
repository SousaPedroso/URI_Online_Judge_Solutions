#include <iostream>
#include <string>
#include <map>
#include <utility>

using namespace std;

int main(){

    int N;
    map<string, string> mensagem_natal;
    string mensagem, idioma;

    cin >> N;
    // Ignore \n from buffer
    cin.ignore(1, '\n');

    for (int i=0; i<N; i++){
        cin >> idioma;
        // Ignore \n from buffer
        cin.ignore(1, '\n');
        getline(cin, mensagem);
        mensagem_natal.insert(make_pair(idioma, mensagem));
    }  
    int M;
    cin >> M;
    for (int i=0; i<M; i++){
        cin.ignore(1, '\n');
        getline(cin, mensagem);
        cin >> idioma;
        
        cout << mensagem <<endl;
        cout << mensagem_natal[idioma] <<endl;
        cout <<endl;
    }
    return 0;
}