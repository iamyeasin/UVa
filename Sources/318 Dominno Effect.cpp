#include <bits/stdc++.h>
#define     sf      scanf
#define     pf      printf
#define     inf     INT_MAX
#define     dbg     cout << "Debug" << endl;
#define     MAX     2048
#define     block   -1
#define     white   +0
#define     noway   -3
#define     source  -4
#define     goal    -5
#define     MP      make_pair
#define     PB      push_back
#define     F       first
#define     S       second
#define     REP(i,a,b)     for( int i=a; i<=b; i++ )

using namespace std;

typedef   vector    < int > vi;
typedef   pair      < int, int > pi;
typedef   long long ll;

int nodes,edges,flag=0,x1,x2;
double costtime;

vi adjList[2048];
int cost[2048][2048];
int par[2048],d[MAX];
priority_queue < int > q;

void dijkstra( int s ){
    for( int i=0; i<=nodes; i++ ) d[i] = inf;
    q.push( s );
    d[s] = 0;

    while( !q.empty() ){
        int u = q.top(); q.pop();
        int sz = adjList[u].size();
        int ucost = d[u];

        REP( i, 0, (sz-1) ){
            int v = adjList[u][i];
            int vcost = cost[u][v] + ucost;

            if( vcost < d[v] ){
                d[v] = vcost;
                par[v] = u;
                q.push(v);
            }
        }
    }
}

void solve(){
    x1 =1, x2 = -5;
    costtime = d[1];
    REP( i,1, nodes ){
        if( d[i] > costtime && d[i] != inf ){
            costtime = d[i];
            x1 = i;
        } 
    }

    REP(u, 2, nodes ){
        int sz = adjList[u].size();
        REP( j, 0, (sz-1) ){
            int v = adjList[u][j];
            if( d[v] < (d[u] + cost[v][u]) ){
                double calc = d[v] + (abs(d[v] - (d[u]+cost[u][v]))/2.00);
                if( calc > costtime ){
                    costtime = calc ;
                    x1 = u, x2 = v;
                }
            }
        }
    }
}

void clr(){
    for( int i=0; i<=nodes; i++ ){
        adjList[i].clear();
    }
    memset( cost, 0, sizeof cost );
    for( int i=0; i<=nodes; i++ )d[i] = inf;
    x1 = 1;

}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("in.txt","rt",stdin);
        freopen("out.txt","wt",stdout);
    #endif
    
    int kase = 0;
    clr();
    while( sf("%d %d",&nodes,&edges ),nodes + edges ) {
        int c,x,y;
        REP(i,1,edges){
             sf("%d %d %d",&x,&y,&c);
             cost[x][y] = cost[y][x] = c;
             adjList[x].PB(y);
             adjList[y].PB(x);    
        }

        dijkstra(1);
        solve();

        pf("System #%d\nThe last domino falls after %0.1lf seconds, ",++kase,costtime);
        if( x2 != -5 )
            pf("between key dominoes %d and %d.\n",min(x1,x2),max(x1,x2));
        else 
            pf("at key domino %d.\n",x1);

        puts("");
        clr();
    }


    return 0;
}
