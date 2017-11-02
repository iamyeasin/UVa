/*Eikhane je company sobceye kom dam e beshi product offer kortase oidai ans. eikhane store korar kono dorkar nai
ba kon company kon product ditase oitaw dekhar dorkar nai. karon eikhane duplicate or requirement sara onno kono product thakbo na
*/

#include<bits/stdc++.h>
#define sf scanf
#define pf printf

using namespace std;


int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("out.txt", "wt", stdout);
    #endif

    string reqrs;
    int r,n, T=1;

    while( cin >> r >> n , r||n) {
        if(T>1) puts("");
        cin.ignore();
        for(int i=0; i<r; i++){
            getline(cin, reqrs);
        }

        string fname,propos,gini;
        double cost,previous_cost;
        int mets=0,kotogula,high = -5;

        for(int m=0; m<n; m++){
            getline (cin, propos);
            sf("%lf %d\n",&cost,&kotogula);

            for(int j=0; j<kotogula; j++){
                getline (cin, gini);
            }

            if(kotogula > high){
                fname = propos;
                previous_cost = cost;
                high = kotogula;
            }
            else if(kotogula == high){
                if(cost < previous_cost){
                    fname = propos;
                    previous_cost = cost;
                }
            }
        }

        pf("RFP #%d\n",T++);
        cout << fname << endl;

    }

    return 0;
}
