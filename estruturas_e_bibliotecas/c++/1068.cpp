#include <iostream>
#include <string>
#include <list>

using namespace std;

int main(){
    string expressao, answer;

    while (true){
        cin >> expressao;
        if (cin.eof()){
            break;
        }
        answer = "correct";
        list<int> parenteses_esquerdo;
        list<int> parenteses_direito;

        for (int i=0; i<expressao.size(); i++){

            if (expressao[i] == ')'){
                parenteses_direito.push_back(i);

                if(parenteses_direito.size() > parenteses_esquerdo.size()){
                    break;
                }
            }
            else {
                if (expressao[i] == '('){
                    parenteses_esquerdo.push_back(i);
                }
            }
        }
        if (parenteses_esquerdo.size() != parenteses_direito.size()){
            answer = "incorrect";
        }
        cout << answer <<endl;
    }

    return 0;
}