#include <iostream>
#include <set>

#define endl '\n';

using namespace std;

int main()
{
    int N, fig, U=0, R=0;
    set<int> figs;
    
    cin >> N;
    while (N--){
        cin >> fig;
        if (figs.find(fig) == figs.end()){
            U ++;
            figs.insert(fig);
        }
        else {
            R ++;
        }
    }
    cout<< U<< endl;
    cout<< R<< endl;

    return 0;
}