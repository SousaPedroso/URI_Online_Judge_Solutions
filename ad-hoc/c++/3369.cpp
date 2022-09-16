#include <bits/stdc++.h>

using namespace std;

#define endline '\n'

int main(){
    ios_base::sync_with_stdio(0);

    int N;
    set<string> palavras;
    set<char> letras;
    string s;

    cin>> N;
    bool achou = false;

    while (N--){
        cin >> s;
        palavras.insert(s);
        letras.insert(s[0]);
    }

    for (auto palavra: palavras){
        // Palavras de letras unicas
        if (palavra.size() == 1){
            achou = true;
            break;
        }

        achou = true;
        for (int i=1; i<palavra.size(); i++){
            // checa se palavra unica ou há o caractere no conjunto
            if (palavra[i] != palavra[i-1] && letras.find(palavra[i]) == letras.end()){
                achou = false;
                break;
            }
        }

        if (achou){
            break;
        }
    }

    if (achou){
        cout<< "Y"<< endline;
    }
    else{
        cout<< "N"<< endline;
    }

    return 0;
}