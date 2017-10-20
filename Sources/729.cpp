/*AC ON 0.000*/
#include<bits/stdc++.h>
#define sf scanf
#define pf printf

using namespace std;

bool taken[1234];
char arr[1234],ans[1234];

void backtrack(int n,int idx)
{
    if(idx == n){
        //print the combination
        ans[idx] = '\0';
        puts(ans);

        return;
    }

    for(int x = 0; arr[x]; x++)
        if( !taken[x]){
        ans[idx] = arr[x]; //save the combination here

        taken[x] = true;
        backtrack( n , idx+1);
        taken[x] = false;

        while( arr[x] == arr[x+1] ) x++;
        }
}


int main()
{
//    freopen("input.txt","rt",stdin);
//    freopen("out.txt","wt",stdout);

    int dataset,T=0;

    sf("%d",&dataset);

    while(dataset--){
        int N,H;

        if(T>=1)puts("");
        sf("%d%d",&N, &H);
        for(int i=0; i<N; i++){
            ans[i] = arr[i] = '0';taken[i] = 0;
        }

        for(int z = N-H; z<N; z++)arr[z] = '1';
        arr[N] = '\0';
        T++;

        backtrack(N,0);


    }

    return 0;
}



/****************************/
/***/****************************///

#include<bits/stdc++.h>
#define sf scanf
#define pf printf

using namespace std;

void com(string soFar, string rest, int N){
    if(rest == ""){
        for(int i=0; i<N; i++)pf("%c",soFar[i]);
        puts("");
    }
    else {
      for(int i=0; i<rest.length(); i++){
        string remain = rest.substr(0,i) + rest.substr(i+1);
            com(soFar+rest[i],remain, N);
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
        com("",combination, N);

        combination = "";

    }

    return 0;
}
