#include<bits/stdc++.h>
#define sf scanf
#define pf printf

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("out.txt", "wt", stdout);
    #endif

    long n,m,c,T=1;
    while( sf("%ld %ld %ld",&n,&m,&c), n|m|c ){
        bool flag[1234567];
        int devices[123457];
        memset(flag,0,sizeof flag);

        for(int i=1; i<=n; i++)sf("%d",&devices[i]);
        int high = 0,cons=0;
        bool blown = false;

        for(int i=0; i<m; i++){
            int x; sf("%d",&x);
            if(!flag[x]){
                flag[x] = true;
                cons += devices[x];

                if(cons > c)blown = true;
                if(cons > high) high = cons;
            }
            else{
                flag[x] = false;
                cons -= devices[x];
            }
        }

        if(blown){
            pf("Sequence %d\nFuse was blown.\n",T++);
        }
        else{
            pf("Sequence %d\nFuse was not blown.\nMaximal power consumption was %d amperes.\n",T++,high);
        }
        if(T>1) puts("");

    }

    return 0;
}
