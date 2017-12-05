/*
  The thing is that..I stored all possible solution in an ARRAY named ans,Total possible solution is 92.Then I searched for
  the lowest moves in 92 solutions. Got AC in 0.00 :D
*/

#include<bits/stdc++.h>
#define REP(a,b) for(int i=a; i<=b; i++)

using namespace std;

int row[123],col[123],queens[123],ld[123],rd[123];
int k=0,ans[100][10];

void solve(int at){
    if(at == 9){
        k++;
        for(int i=1; i<=8; i++){
            ans[k][i] = queens[i];
        }
    }

    for(int c=1; c<=8; c++){
        if(col[c] || ld[c+at] || rd[ 8 + c - at ] )continue;

        queens[at] = c;
        col[c] = ld[c+at] = rd[8+c-at] = 1;
        solve(at+1);
        col[c] = ld[c+at] = rd[8+c-at] = 0;
    }
}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("in.txt","rt",stdin);
        freopen("out.txt","wt",stdout);
    #endif

    memset(col,0,sizeof col);
    memset(ld,0,sizeof ld);
    memset(rd,0,sizeof rd);
    solve(1);

    int arr[123],kase=0;
    while( scanf("%d",&arr[1]) != EOF){
        REP ( 2,8) scanf("%d",&arr[i]);

        int fans = 1234,moves=0;

        for(int i=1; i<=92; i++){
            for(int k=1; k<= 8; k++){
                if(ans[i][k] != arr[k])moves++;
            }
            fans = (fans < moves) ? fans : moves;
            moves = 0;
        }
        printf("Case %d: %d\n",++kase, fans);
    }

    return 0;
}
