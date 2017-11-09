#include<bits/stdc++.h>
#define sf scanf
#define mx 1000005
#define pf printf

using namespace std;

unsigned long long int n,cpy;
int coff[12300];
int limit = 1;

void gen_coff(int base){
    memset(coff, 0, sizeof coff);
    int nx = base;
    int i=2,k=0;

    while(nx>1  && i * i<= base){
        while(!(nx%i)){
            coff[i]++;
            nx /= i;
        }
        i++;
    }
    if(nx > 1) {
        coff[nx]++;
        limit = nx;
    }
    else limit = i-1;
}


long cal_zero(int base){
    gen_coff(base);
    int m =1;
    long ans=1234223456;

    for(int k=2; k<=limit; k++){
        cpy = n;
        long sum = 0;
        if( coff[k] ){
            m = k;
            while( (cpy/m) ){
                sum += (cpy/m);
                m = m*k;
            }
            int kk = (sum / coff[k]);
            ans = (kk < ans) ? kk : ans;
        }
    }

    return ans;
}

long digits(int base){
    double x = 0;
    for(int i=1; i<=n; i++)
    {
        x += log10(i) / log10(base);
    }
    int res = ((int)x) + 1;
    return res;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("in.txt","rt",stdin);
        freopen("out.txt","wt",stdout);
    #endif

    int b;
    while( sf("%llu %d",&n,&b) != EOF){
        pf("%d %d\n",cal_zero(b),digits(b));
    }


    return 0;
}
