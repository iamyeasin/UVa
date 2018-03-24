#include <bits/stdc++.h>
#define UNVISITED 0
#define MAX 50005
#define DB cout << "DEBUG TESTING " << endl;

using namespace std;

vector < int > G[MAX];
set < int > st;
int marks[MAX],store[MAX];
int counter=0;

void clr(){
    counter = 0;
    for( int i=1; i<MAX; i++ ){
        marks[i] = 0;
        store[i] = 0;
       // G[i].clear();
    }
    st.clear();
}

int dfs( int u ){

    marks[u] = 1;
    int counter = 0;
    int v = G[u][0];
    if( marks[u] && !marks[v]) counter += (1 + dfs(v));
    marks[u] = 0;
    return store[u] = counter;
}


int main(){

    #ifndef ONLINE_JUDGE
        freopen("in.txt","rt",stdin);
       // freopen("out.txt","wt",stdout);
    #endif

    long kase;
    cin >> kase;

    for( int k=1; k<=kase; k++ ){
        clr();
        long edges;
        cin >> edges;

        for( int i=0; i<edges; i++ ){
            long x,y;
            cin >> x >> y;
            G[x].push_back( y );
        }

        int ans = INT_MIN,idx=0;
        for( int i=1; i<=edges; i++ ){
            if( store[i] == UNVISITED ) dfs(i);
            if(store[i] > ans ){
                ans = store[i];
                idx = i;
            }
        }

        printf("Case %d: %d\n",k,idx);
        for( int i=0; i<=edges; i++ ) G[i].clear();

    }


	return 0;
}
