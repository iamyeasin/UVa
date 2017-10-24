#include<bits/stdc++.h>
#define sf scanf
#define pf printf
#define MAX 1000005

using namespace std;

int arr[MAX];

int main(){
    std::ios_base::sync_with_stdio();
    cin.tie();

    long a,b;
    while(sf("%ld %ld",&a,&b),(a|b)){
        int x, mx=0,id=0;
        for(int i=0; i<a; i++){
            sf("%d",&arr[i]);
        }

        long counter = 0,idx = 0;
        for(int i=0; i<b; i++){
            sf("%d",&x);
            while(arr[idx] <= x){
                if(x == arr[idx]){
                    counter++;
                } idx++;
            }
        }

        pf("%ld\n",counter);

    }

    return 0;
}
