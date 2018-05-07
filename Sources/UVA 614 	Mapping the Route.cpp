#include <bits/stdc++.h>
#define     sf      scanf
#define     pf      printf
#define     inf     INT_MAX
#define     dbg     cout << "Debug" << endl;
#define     MAX     1024
#define     block   -1
#define     white   +0
#define     noway   -3
#define     source  -4
#define     goal    -5
 
using namespace std;


long grid[ MAX ][ MAX ];
int visited[ MAX ][ MAX ], vis[MAX][MAX];
 
int dx[] = { +0, -1, +0, +1 };
int dy[] = { -1, +0, +1, +0 };

int sx,sy,l,w,gx,gy,flag=0,c=0;

bool isOk( int i, int j ){
    return ( i>=1 && i<=l && j>=1 && j<=w );
}

bool isValid( int x, int y, int pd , int cd ){
    if( (pd == 0 && cd == 2) || (pd == 2 && cd == 0) ||
        (pd == 3 && cd == 1) || (pd == 1 && cd == 3) ) return false;

    int mark = false;
    if( cd == 0 )
        if( isOk(x,y-1) && visited[x][y-1] != 1 && visited[x][y-1] != 3 ) mark = 1;
    if( cd == 1 )
        if( isOk(x-1,y) && visited[x-1][y] != 3 && visited[x-1][y] != 2) mark = 1;
    if( cd == 2 )
        if( isOk(x,y+1) && visited[x][y] != 1 && visited[x][y] != 3 ) mark = 1;
    if( cd == 3 )
        if( isOk(x+1,y) && visited[x][y] != 2 && visited[x][y] != 3 ) mark = 1; 

    return mark;
}

bool isNoMove( int x, int y , int pd ){
    for( int i=0; i<4; i++ ){
        int mdx = dx[i] + x;
        int mdy = dy[i] + y;
        if( isOk(mdx, mdy) && isValid( x,y, pd, i ) ) return false; 
    }
    return true;
}

void solve( int x, int y, int pd, int c ){ // was a fak. But learned Backtrack again
    if( grid[x][y] == goal ){
        flag = 1;
        grid[x][y] = c; return;
    }

    if( isNoMove(x,y,pd) ){ 
        grid[x][y] = noway;
        return;
    }

    for( int i=0; i<4; i++ ){
        int mx = dx[i] + x;
        int my = dy[i] + y;

        if( isOk(mx,my) && !flag && vis[mx][my] != noway && isValid(x,y,pd,i) ){
            vis[mx][my] = noway;
            solve( mx,my,i, c+1);
            if(flag) grid[x][y] = c;
            if(!flag) {
                grid[x][y] = noway; grid[mx][my] = noway; 
            }
        }
    }
}

void clr(){
    flag= false;
    for( int i=1; i<=l; i++ ){
        for( int j=1; j<=w; j++ ){
            vis[i][j] = 0;
            grid[i][j] = 0;
            visited[i][j] = 0;
        }
    }
}

void printGrid(){ // Fucking problem + FUCK YOU PRINT + FFFFUK

    for( int i=0; i<=(w<<2) ; i++ ){
        if(i%4 == 0 )pf("+");
        else pf("-");
    }
    puts("");

    for( int i=1; i<=l; i++ ){
        pf("|");
        for( int j=1; j<=w; j++ ){
            if(grid[i][j] > 0 ){
                pf("%3d",grid[i][j]);
            }
            if(grid[i][j] == 0 || grid[i][j] == goal ){
                pf("   ");
            }
            if( grid[i][j] == noway ){
                pf("???");
            }
            if( visited[i][j] == 1 || visited[i][j] == 3 || j==w )pf("|");
            else pf(" ");
        }
        puts("");
        int ff = 0 ;
        for( int j=1; j<=w && i<l; j++ ){
            if(j == 1) {
                if( visited[i][j] == 2 || visited[i][j] == 3 ) pf("+---");
                else if( visited[i][j] == 0 || visited[i][j] == 1 ) pf("+   "); 
            }
            else if(j == w) {
                if( visited[i][j] == 2 || visited[i][j] == 3 ) pf("---");
                else if( visited[i][j] == 0 || visited[i][j] == 1 ) pf("   ");
            }
            else {
                if( visited[i][j] == 2 || visited[i][j] == 3 ) pf("---");
                else if( visited[i][j] == 1 || visited[i][j] == 0  ) pf("   ");
            }
            pf("+");
            
        }
        if(i<l)puts("");

    }
    for( int i=0; i<=(w<<2) ; i++ ){
        if(i%4 == 0 )pf("+");
        else pf("-");
    }
    puts("");

}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("in.txt","rt",stdin);
        freopen("out.txt","wt",stdout);
    #endif

    int tc = 0;

    while( sf("%d %d %d %d %d %d", &l,&w,&sx,&sy,&gx,&gy) , l+w+sx+sy+gx+gy ){
        clr();
        grid[sx][sy] = source; grid[gx][gy] = goal;
        for( int i=1; i<=l; i++ ){
            for( int j=1; j<=w; j++ ){
                sf( "%d",&visited[i][j] );
            }
        }
        
        solve(sx,sy,source,1);

        pf("Maze %d\n\n",++tc);
        printGrid();
        puts("");
        puts("");

    }

    return 0;
}
