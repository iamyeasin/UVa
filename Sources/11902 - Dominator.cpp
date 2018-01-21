#include <bits/stdc++.h>
#define VISITED 1
#define UNVISITED 0

using namespace std;

bitset <123> mark,a,b;
long kase,n;
char grid[123][123];
vector < int > adjList[123];
int cur=0;

void Print(){
    int N = n;
    printf("+");
    for(int i=1; i<=2*N-1; i++ ){
        printf("-");
    }
    puts("+");

    for (int m=0; m<N; m++ ){
        printf("|");
        for( int k=0; k<N; k++) {
            printf("%c|",grid[m][k]);
        }
        printf("\n+");
        for(int i=1; i<=2*N-1; i++ ){
            printf("-");
        }
        puts("+");

    }
}

void dfs ( int u ){
    mark[u] = VISITED;
    int sz = adjList[u].size();

    for( int i=0; i<sz; i++ ){
        int v = adjList[u][i];
        if( mark[v] == UNVISITED && v != cur) dfs(v);
    }
}



int main (){

    #ifndef ONLINE_JUDGE
        freopen( "in.txt", "rt",stdin );
        freopen( "out.txt", "wt",stdout );
    #endif

    scanf("%ld",&kase);

    for( int k=1; k<=kase; k++ ){
        scanf("%ld",&n);
        for ( int i=0; i<n; i++ ){
            for ( int j=0; j<n; j++ ){
                int x; scanf("%d",&x);
                if( x ) adjList[i].push_back( j );
            }
        }

        dfs(0);

        for ( int j=0; j<n; j++ ){
            if( mark[j] ) a[j] = true;
            if( a[j] ) grid[0][j] = 'Y';
            else grid[0][j] = 'N';
        }

        for( int i=1; i<n; i++ ){
            cur = i;
            mark.reset();
            dfs(0);

            for ( int j=0; j<n; j++ ){
                if( a[j]^mark[j] ) grid[i][j] = 'Y';
                else grid[i][j] = 'N';
            }
        }
        printf("Case %d:\n",k);
        Print();

        a.reset(); b.reset(),mark.reset();

        for( int c=0; c<n; c++ ){
            adjList[c].clear();
        }

        for ( int c=0; c<n; c++ ){
            for ( int cc=0; cc<n; cc++ ){
                grid[c][cc] = '\0';
            }
        }
        cur=0; // That was the fucking BUG > FUCK FAAAAAAAAAAAK

    }


    return 0;
}
