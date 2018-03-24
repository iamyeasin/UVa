#include<bits/stdc++.h>
#define MAX 1000000001
#define pf printf
#define sf scanf

using namespace std;

long kase,flag=0;
int r,c,n,m;
int dr[] = { +1, -1 };
int grid[200][200],vis[200][200];


bool isOk( int i, int j ){
    return ( i>=0 && i<r && j>=0 && j<c && grid[i][j] != -5);
}

void printGrid(){
    for ( int i=0; i<r; i++ ){
        for ( int j=0; j<c; j++ ){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

void dfs( int i, int j ){
    if(!vis[i][j]){
        vis[i][j] = 1;
        for ( int ii=0; ii<2; ii++ ){
            for( int jj=0; jj<2; jj++) {
                int x = i + (dr[ii] * n);
                int y = j + (dr[jj] * m);

                if( isOk(x,y) ) {
                    grid[x][y]++;
                    dfs(x, y);
                }

                x = i + (dr[ii] * m);
                y = j + (dr[jj] * n);

                if( isOk( x, y) ){
                    grid[x][y]++;
                    dfs(x,y);
                }
            }
        }

    }
}

void clr(){
    for ( int i=0; i<r; i++ ){
        for ( int j=0; j<c; j++ ){
            grid[i][j] = vis[i][j]= 0;
        }
    }
}


int main(){

    #ifndef ONLINE_JUDGE
        freopen("in.txt","rt",stdin);
        freopen("output.txt","wt",stdout);

    #endif // ONLINE_JUDGE

        scanf("%d,",&kase);
        for ( int k=1; k<=kase; k++ ){
            clr();
            scanf("%d %d %d %d",&r,&c,&n,&m);
            int w; scanf("%d",&w);
            for(int i=1; i<=w; i++){
                int x,y; scanf("%d%d",&x,&y);
                grid[x][y] = -5;
            }

            dfs(0,0);

            //printGrid();
            int odd = 0,even = 0;

            for( int i=0; i<r; i++){
                for( int j=0; j<c; j++ ){
                    if(grid[i][j] == -5 || !vis[i][j]  ) continue;
                    if( !m || !n || m == n ) grid[i][j] /= 2;
                    if(grid[i][j] || (!i && !j)) {
                        if( grid[i][j] & 1 ) odd++;
                        else even++;
                    }
                }
            }
            printf("Case %d: %d %d\n",k,even,odd);
            //printGrid();

    }

    return 0;
}
