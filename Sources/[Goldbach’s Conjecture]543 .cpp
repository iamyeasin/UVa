#include <bits/stdc++.h>
using namespace std;
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
typedef pair<int, int>     												ii;
typedef vector<int>        												vi;
typedef vector<ii>         												vii;
typedef unsigned long long 												ULL;
typedef long long          												LL;
typedef priority_queue< int, vector<int>, greater<int> > 				IPQ;
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#define r()                		freopen("file.in", "r", stdin);
#define w()                		freopen("file.out", "w", stdout);
#define fast_IO            		ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define min3(a,b,c)        		min(a, min(b,c));
#define max3(a,b,c) 	   		max(a, max(b,c));
#define rep(id,start,end)  		for( int id = start; id < end; id++ )
#define ms(var, value)     		memset(var, value, sizeof var)
#define swap(a,b)				{ (a) ^= (b); (b) ^= (a); (a) ^= (b); }
#define all(x)					x.begin(), x.end()
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
inline LL bigmod(LL p, LL e, LL M){ LL ret = 1; for(; e > 0; e >>= 1){
	if(e & 1) ret = (ret * p) % M; p = (p * p) % M;} return ret;}
inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){
	if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')
	{x=x*10+ch-'0';ch=getchar();}return x*f;}
inline LL inversemod(LL a, LL M){ return bigmod(a,M-2,M); }
inline LL gcd(LL a,LL b){while(b>0){a=a%b; swap(a,b);}return a;}
inline LL lcm(LL m,LL n){return m*n/gcd(m,n);}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

bool sieve[1000000];

int prime[100], pos = 0, n, ans;


int main(){
	//r();w();

	//prime sieve
	for( int i = 2; i<1001; i++){
		if( !sieve[i] ){
			for( int j = i+i; j<1000000; j+=i ) sieve[j] = true;
		}
	}

	//list of primes
	for( int i = 2; i<550; i++){
		if( !sieve[i] ) prime[pos++] = i;
	}

	//main program
	while( true ){
		n = read();
		if(n==0) break;
		for(int i = 0; i<99; i++ ){
			ans = n - prime[i];
			if( !sieve[ ans ] ){
				printf("%d = %d + %d\n", n, prime[i], ans);
				break;
			}
		}
	}
	return 0;
}

