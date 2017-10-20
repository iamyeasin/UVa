#include<bits/stdc++.h>
#define sf scanf
#define pf printf

using namespace std;

void com(string soFar, string rest){
    if(rest.empty()){
            cout << soFar << endl;//    return;
            //vc.push_back(soFar);
    }
    else {
      for(int i=0; i<rest.length(); i++){
        string remain = rest.substr(0,i) + rest.substr(i+1);
            com(soFar+rest[i],remain);
            while(rest[i] == rest[i+1])i++;
        }

     }
}


int main()
{
//    freopen("input.txt","rt",stdin);
//    freopen("out.txt","wt",stdout);

    int dataset,T=0;
    string combination = "";
    sf("%d",&dataset);

    while(dataset--){
        int N,H;
        if(T>=1)puts("");
        sf("%d%d",&N, &H);
        for(int z = 0; z<(N-H); z++)combination += "0";
        for(int z = 0; z<H; z++)combination += "1";
        T++;
        com("",combination);

        combination = "";

    }

    return 0;
}

