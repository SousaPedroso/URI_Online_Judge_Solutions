#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int M;

bool mod_comparation(int N1, int N2){
    int mod_n1, mod_n2;

    mod_n1 = N1 % M;
    mod_n2 = N2 % M;

    return mod_n1 < mod_n2 || (mod_n1 == mod_n2 && (N1 % 2 == 1 || N1 % 2 == -1)  && N2 % 2 == 0) ||
    (mod_n1 == mod_n2 && (N1 % 2 == 1 || N1 % 2 == -1) && (N2 % 2 == 1 || N2 % 2 == -1) && N1 > N2) ||
    (mod_n1 == mod_n2 && N1 % 2 == 0 && N2 % 2 == 0 && N1 < N2);
}

int main(){
    int N;

    while (true){
        cin >> N >> M;

        if (N == 0 && N == M){
            cout << 0 << " " << 0 <<endl;
            break;
        }
        vector<int> arranjo(N, 1);

        for (int i=0; i<N; i++){
            cin >> arranjo[i];
        }

        sort(arranjo.begin(), arranjo.end(), mod_comparation);

        cout << N << " " << M <<endl;
        for (int i=0; i<N; i++){
            cout << arranjo[i] <<endl;
        }
    }

    return 0;
}