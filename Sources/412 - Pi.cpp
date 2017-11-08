#include<bits/stdc++.h>
#define sf scanf
#define pf printf

using namespace std;

bool sieve[34009];
int prime[34000];
int pos=0;

void generate_prime(){
//prime sieve
	for( int i = 2; i<1001; i++){
		if( !sieve[i] ){
			for( int j = i+i; j<=32768; j+=i ) sieve[j] = true;
		}
	}
	for( int i = 2; i<=505; i++){
		if( !sieve[i] ) prime[pos++] = i;
	}
}




int main(){
    generate_prime();
    int n,m;

    int nums[1234];
    while(sf("%d",&n),n){
        for(int i=0; i<n; i++)sf("%d",&nums[i]);
        int counter = 0,total=0;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                total++;
                int x = nums[i];
                int y = nums[j];

                if(!(x&1) && !(y&1))continue;
                if((!sieve[x] || !sieve[y]) && ((y > x)? (y%x) : (x%y)) )counter++;
                else if ( __gcd(x,y) == 1 )counter++;
            }
        }
        if(!counter){
            pf("No estimate for this data set.\n");
        }
        else{
            double pi = ((6.00 * total)*1.00)/(counter*1.00);
            pf("%0.6lf\n",sqrt(pi));
        }
    }


    return 0;
}
