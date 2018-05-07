#include <bits/stdc++.h>
#define     sf      scanf
#define     pf      printf
#define     dbg     cout << "Debug" << endl;

using namespace std;

vector < int > adjList[1024];
vector < int > ans;
queue  < int > q;
int nodes,start,edges,n,ashe=0 ;
int visited[1025] ;

void dfs( int source,int ind ){
	visited[source] = 1;
    int sz = adjList[source].size();
    for( int i=0; i<sz; i++ ){
        int v = adjList[source][i];
        if ( v == ind ) ashe = 1;
        if( !visited[v] ){
            dfs( v ,ind);
        }
    }
}

void printGrid(){
    for( int i=1; i<=nodes; i++ ){
        int sz = adjList[i].size();
        printf("%d -> ", i );
        for( int j=0; j<sz; j++ ){
            printf("%d ", adjList[i][j]);
        }
        puts("");
    }
}

void clr(){
    for( int i=0; i<=nodes; i++ ){
        adjList[i].clear();
    }
}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("in.txt","rt",stdin);
        freopen("out.txt","wt",stdout);
    #endif

    while( sf("%d",&nodes) , nodes ){
        while( sf ("%d",&start ) , start ){
            while( sf("%d",&edges), edges ){
                adjList[start].push_back( edges );
            }
        }
        // printGrid();
        
        sf("%d",&n);
        for( int i=0; i<n; i++ ){
            int x,counter = 0; sf("%d",&x);
            ashe = 0;
            // cout << x << "-> ";
            dfs( x,x );

            if(!ashe){
            	counter++;
            	ans.push_back( x );
            }

            for( int i=1; i<=nodes; i++ ){
            	if( !visited[i] ){
            		counter++;
            		ans.push_back( i );
            	}
            }

            int sz = ans.size();
            if(counter)pf( "%d ",counter );
            else puts("0");
            sort( ans.begin(),ans.end() );

            for( int i=0; i<sz-1; i++ ){
            	pf( "%d ", ans[i] );
            }
            if(counter)pf( "%d\n",ans[sz-1] );
            
           	memset( visited, 0, sizeof visited );
           	ans.clear();

        }
        // puts("");
        clr();
    }

    return 0;
}
