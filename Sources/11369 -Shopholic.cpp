#include<bits/stdc++.h>
#define sf scanf
#define pf printf

using namespace std;


int main(){
//    freopen("in.txt", "rt" , stdin);

    long kase;
    sf("%ld",&kase);

    while(kase--){
        int shops;
        sf("%d",&shops);

        long product[shops+5];
        memset(product,0,sizeof product);

        for(int i=0; i<shops; i++){
            sf("%d",&product[i]);
        }

        sort(product,product+shops,greater<int>());
        long sum = 0;

        for(int s = 2; s < shops; s+=3){
            sum += product[s];
        }

        pf("%ld\n",sum);
        sum = 0;

    }


    return 0;
}
