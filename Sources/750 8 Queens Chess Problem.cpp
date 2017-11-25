/*The solutions from shantonu vai*/

#include<bits/stdc++.h>
#define N 8

using namespace std;

int queen[1234],column[1234],digonal1[1234],digonal2[1234];
int ans[100][100];
int k=1;

void solve( int at ){
    if( at ==  N+1){
        for(int row=1; row<=N; row++){
            ans[k][row] = queen[row];
        }
        k++;
        return;
    }

    for(int i=1; i<=N; i++){
        if(column[i] || digonal1[i+at] || digonal2[N + i - at]) continue;
        queen[at] = i;
        column[i] = digonal1[i+at] = digonal2[N + i - at] = 1;
        solve(at + 1);
        column[i] = digonal1[i+at] = digonal2[N + i - at] = 0;
    }

}


int main(){
//    freopen("in.txt","rt",stdin);
//    freopen("out.txt","wt",stdout);

    solve(1);

    int tc;
    scanf("%d",&tc);

    while(tc--){
        int r,c;
        scanf("%d %d",&r,&c);

        int m=1;
        printf("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n");

        for(int i=1; i<=93; i++){
            if(ans[i][c] == r){
                printf("%2d      ",m++);
                for(int k=1; k<=8; k++){
                    if(k != 8)printf("%d ",ans[i][k]);
                    else printf("%d\n",ans[i][k]);
                }
            }
        }
        if(tc>=1)puts("");
    }

    return 0;
}
