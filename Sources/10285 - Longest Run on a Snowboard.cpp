#include <bits/stdc++.h>
#define UNVISITED 0

using namespace std;

long n,m,kase,longRun=-56;
int fx[] = {+1,-1,+0,+0};
int fy[] = {+0,+0,+1,-1};

int in[123][123],table[123][123];

bool isOk(int i,int j) { return (i>=1 && i<=n && j>=1 && j<=m ); }


void clr(){
    for( int i=1; i<=n; i++ ){
        for( int j=1; j<=m; j++ ){
            in[i][j] = 0; table[i][j] = UNVISITED;
        }
    }
}

bool isNoMove( int i, int j ){
    for ( int mm =0; mm<4; mm++ ){
        int x = i + fx[mm];
        int y = j + fy[mm];
        if(isOk(x,y) && in[i][j] > in[x][y]) return false;
    }
    return true;
}


int DP( int i, int j ){
    if ( isNoMove(i,j) ) return table[i][j] = 1;
    if( table[i][j] ) return table[i][j];

    for( int k=0; k<4; k++ ){
        int x = i + fx[k];
        int y = j + fy[k];

        if( isOk(x,y) && in[i][j] > in[x][y] ){
            int ans = DP(x,y);
            table[i][j] = max (ans+1 , table[i][j]);
        }
    }
    return table[i][j];

}


void Solve() {
    for( int i=1; i<=n; i++ ){
        for( int j=1; j<=m; j++ ){
            if( table[i][j] == UNVISITED ){
                int ans = DP(i,j);
                table[i][j] = max ( ans , table[i][j] );
            }
            longRun = table[i][j] > longRun ? table[i][j] : longRun;
        }
    }
}

void Print(){
    for( int i=1; i<=n; i++ ){
        for( int j=1; j<=m; j++ ){
            cout << table[i][j] << " " ;
            longRun = table[i][j] > longRun ? table[i][j] : longRun;
        }
        cout << endl;
    }
}


int main(){

    scanf("%ld",&kase);

    for ( int k=1; k<=kase; k++ ){
        char str[1234]; scanf("%s\n",str);
        scanf("%ld%ld",&n,&m);
        clr();


        for( int i=1; i<=n; i++ ){
            for(int j=1; j<=m; j++ ){
                cin >> in[i][j];
            }
        }

        Solve();
        printf("%s: %d\n",str,longRun);
        longRun = -56;

       // Print();

    }



    return 0;
}
