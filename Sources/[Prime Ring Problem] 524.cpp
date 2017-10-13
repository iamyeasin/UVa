#include<bits/stdc++.h>
#include<cstdio>
#include<algorithm>
#define pf printf
#define sf scanf
#define mx 100

using namespace std;
vector< string > vs;

bool isPrime(int n, int x){
    int sum = n+x;

    if(sum<3) return true;
    if(!(sum&1)) return false;

    for(int i=3; i*i <= sum; i+=2){
        if(!(sum%i)){
            return false;
        }
    }
    return true;

}

void backTrack(int n, int idx, int *ans, int *arr, int *taken){

    if(idx == n) {
        if(ans[0] != 1 || !isPrime(ans[0],ans[n-1])) return;
        for(int k=0; k<n; k++) {
            if(k == (n-1))pf("%d\n",ans[k]);
            else pf("%d ",ans[k]);
        }
        return;
    }

    for(int i=0; i<n; i++){
        if(i > 0 && ans[0] != 1) continue;
        if(!taken[i]){
            taken[i] = 1;

            if(isPrime(ans[idx-1],arr[i])){
                ans[idx] = arr[i];
                backTrack(n, idx+1, ans, arr, taken);
            }

            taken[i] = false;
        }
    }

}


int main(){

//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);

    int n,T=0, arr[2342],ans[2343];

    while(sf("%d",&n) == 1){
        for(int i=0; i<n; i++){
            arr[i] = i+1;
        }

        if(T >= 1) puts("");
        int taken[2343];
        memset(taken,0,sizeof(taken));
        pf("Case %d:\n",++T);
        backTrack(n , 0, ans, arr, taken);
    }

    return 0;
}
