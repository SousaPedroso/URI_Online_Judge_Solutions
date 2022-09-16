#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

struct team{
    long long subscription;
    long long score;
    long long markedpoints;
    long long receivedpoints;
};

bool team_comparator(team t1, team t2){
    return (t1.score > t2.score
    || (t1.score == t2.score && (t1.receivedpoints == 0 && t2.receivedpoints == 0 && t1.markedpoints > t2.markedpoints ) // checks 0 received points
    || (t1.receivedpoints == 0 && t2.receivedpoints != 0 && t1.markedpoints > (t2.markedpoints / t2.receivedpoints))
    || (t1.receivedpoints != 0 && t2.receivedpoints != 0 && (t1.markedpoints / t1.receivedpoints) > (t2.markedpoints / t2.receivedpoints))
    || (t1.receivedpoints != 0 && t2.receivedpoints == 0 && (t1.markedpoints / t1.receivedpoints) > t2.markedpoints))
    || (t1.score == t2.score && ( // Repeat conditions considering the same cestaaverage
        (t1.receivedpoints == 0 && t2.receivedpoints == 0 && t1.markedpoints == t2.markedpoints )
        || (t1.receivedpoints == 0 && t2.receivedpoints != 0 && t1.markedpoints == (t2.markedpoints / t2.receivedpoints))
        || (t1.receivedpoints != 0 && t2.receivedpoints != 0 && (t1.markedpoints / t1.receivedpoints) == (t2.markedpoints / t2.receivedpoints))
        || (t1.receivedpoints != 0 && t2.receivedpoints == 0 && (t1.markedpoints / t1.receivedpoints) == t2.markedpoints)
        ) && t1.markedpoints > t2.markedpoints)
    || (t1.subscription < t2.subscription)
    );
}

int main()
{
    int n, b, h=1;
    long long x, y, z, w;
    ios_base::sync_with_stdio(0);

    cin >> n;
    
    while (n != 0){
        vector<team> nba(n, {0, 0, 0, 0});
        
        for (int j=0; j<n; j++){
            nba[j].subscription = j+1;
        }
        
        b = (pow(n, 2)-n) / 2;
        for (int i=0; i<b; i++){
            cin >> x >> y >> z >> w;
            
            // set values
            nba[x-1].markedpoints += y;
            nba[z-1].markedpoints += w;
            nba[x-1].receivedpoints += w;
            nba[z-1].receivedpoints += y;
            
            // Checks which one won the game
            if (y > w){
                nba[x-1].score += 2;
                nba[z-1].score += 1;
            }
            else {
                nba[x-1].score += 1;
                nba[z-1].score += 2;
            }
        }
        sort(nba.begin(), nba.end(), team_comparator);
        
        cout<< "Instancia "<< h<< endl;
        h ++;
        int a=0;
        for (int j=0; j<n; j++){
            if (j != n-1){
                cout<< nba[j].subscription<< " ";
            }
            else {
                cout<< nba[j].subscription<< endl;
            }
            a++;
        }
        cout<< endl;

        cin >> n;
    }

    return 0;
}