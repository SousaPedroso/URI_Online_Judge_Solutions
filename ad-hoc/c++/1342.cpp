#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int p, s;
    while (cin >> p >> s && p != 0) {
        vector<int> trail(s+1, 0);
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        trail[t1] = trail[t2] = trail[t3] = -1;

        int n;
        cin >> n;
        vector<int> pos(p, 0);
        vector<int> trapped(p, 0);
        int i=-1;

        while (true){
            i++;
            int player = i%p;
            if (!trapped[player]){
                int d1, d2;
                cin >> d1 >> d2;
                pos[player] += d1 + d2;
                if (pos[player] > s){
                    cout<< player+1<< endl;
                    break;
                }
                if (trail[pos[player]] == -1) {
                    trapped[player] = 1;
                }
            }
            else {
                trapped[player]=0;
            }
        }
    }
    return 0;
}