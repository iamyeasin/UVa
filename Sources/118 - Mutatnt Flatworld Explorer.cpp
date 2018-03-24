/*
    EXP: main thing I had to check that is there any robot is lost from that grid or not.
    suppose I have , (0,0) and next point is (0,-1)
    for the first case I checked that is there any scent in (0,0) ?
    if there is any then ignore the command. Else print that the robot is lost.
*/

#include    <bits/stdc++.h>
#define     black   1
#define     white   2
#define     none    0
#define     MAX     10000000
#define     dbg     cout << "DEBUG IS SHOWING " << endl;

int dx[] = { +1, -1, -0 , +0 };
int dy[] = { +0, -0,  +1, -1 };

using namespace std;

long n,m,xi,yi,isLost = false, lostx,losty ;
char iDir;
int grid[100][100]; bool flag[100][100];

char dir[] = { 'N', 'E', 'S' ,'W' };


bool isok( int x, int y ){
    return (x >= 0 && x<=n && y>=0 && y<=m);
}


int main(){

    #ifndef ONLINE_JUDGE
        freopen( "in.txt","rt",stdin );
        freopen( "out.txt","wt",stdout );
    #endif

    scanf( "%ld %ld",&n, &m );

    for( int i=0; i<=n+5; i++ ){
        for( int j=0; j<=m+5; j++ ){
            flag[i][j] = 0;
        }
    }

    while( scanf("%ld %ld %c", &xi,&yi,&iDir ) != EOF ){
        char path[1024];
        scanf( "%s",path );

        int curDir = 0;
        if( iDir == 'N' )curDir = 0;
        else if( iDir == 'E' )curDir = 1;
        else if( iDir == 'S' )curDir = 2;
        else if( iDir == 'W' )curDir = 3;

        int tx,ty;
        for( int i=0; path[i]; i++ ){
            tx = xi; ty = yi; // saving the current point
            if( path[i] == 'L' ){
                curDir--; if(curDir < 0 ) curDir = 3;
            }
            else if ( path[i] == 'R' ){
                curDir++; if( curDir > 3 ) curDir = 0;
            }
            else {
                if( curDir == 0 ) yi++; // N
                else if( curDir == 1 ) xi++; // E
                else if( curDir == 2 ) yi--; // S
                else if( curDir == 3 ) xi--; // W

                if( !isok( xi, yi ) ){ // The main thing you should check that if a robot is lost from that grid or not?
                    if( !flag[tx][ty] ){
                        cout << tx << " " << ty << " " << dir[curDir] << " LOST" << endl;
                        flag[tx][ty] = 1;
                        isLost = true;
                        break;
                    }
                    else {
                        xi = tx; yi = ty; // back at the point where you came from to previous point
                    }
                }
            }
            //cout << path[i] << " " << xi << " " << yi << " " << dir[curDir] << endl;
        }

        if( !isLost )
            cout << xi << " " << yi << " " << dir[curDir] << endl;
        isLost = false;
    }



    return 0;
}
