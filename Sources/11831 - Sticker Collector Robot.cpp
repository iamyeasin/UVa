#include <bits/stdc++.h>
#define UNVISITED 0
#define VISITED 1
#define DB cout << " DEBUG " << endl;

using namespace std;

int dx[]= {+0,+0,-1,+1};
int dy[]= {+1,-1,+0,+0};
char dir[] = {'L','O','N','S'};
int pos = 0,n,m,d,sticker=0;;
char grid[104][104],order[123456];


bool isOk( int i, int j ){
    return (i>=0 && i<n && j>=0 && j<m && grid[i][j] != '#');
}


int main(){
    #ifndef ONLINE_JUDGE
         freopen("in.txt", "r", stdin);
         freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    while( scanf("%d %d %d",&n,&m,&d) , n+m+d ){
        sticker = 0;
        for( int i=0; i<n; i++){
            scanf("%s",&grid[i]);
        }
        int x,y;

        for( int i=0; i<n; i++ ){
            for( int j=0; j<m; j++ ){
                if(grid[i][j] == 'N') { pos = 0;  x=i,y=j; }
                if(grid[i][j] == 'S') { pos = 2;  x=i,y=j; }
                if(grid[i][j] == 'L') { pos = 1;  x=i,y=j; }
                if(grid[i][j] == 'O') { pos = 3;  x=i,y=j; }
            }
        }

        scanf("%s",order);
        
        for( int i=0; order[i]; i++ ){
            if( order[i] == 'D' ){
                pos = ((pos+1) > 3 ) ? 0 : pos+1 ;
            }
            else if( order[i] == 'E'){
                pos = ((pos-1) < 0 ) ? 3 : pos-1;
            }
            else if( order[i] ==  'F' ){

                int mv;
                char ch;

                if(pos == 0) ch = 'N';
                else if(pos == 1) ch = 'L';
                else if(pos == 2) ch = 'S';
                else if(pos == 3) ch = 'O';

                for( int ii=0; ii<4; ii++) {
                    if( dir[ii] == ch ) {
                        mv = ii; break;
                    }
                }

                if( isOk( x + dx[mv] , y+dy[mv] ) ){
                    x = x + dx[mv];
                    y = y + dy[mv];
//                     cout << grid[x][y] << endl;
                    if(grid[x][y] == '*'){
                        sticker++;
                        grid[x][y] = '.';
                    }
                }

            }

        }

        printf("%d\n",sticker);

    }


    return 0;
}
