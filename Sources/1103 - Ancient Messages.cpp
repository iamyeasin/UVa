#include <bits/stdc++.h>
#define UNVISITED 0
#define VISITED 1
#define DB cout << " DEBUG " << endl;

using namespace std;

long n,m,counter=0;
string grid[2024],output="";
vector < int > wh;

int dx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int dy[]={-1,+1,+0,+0,+1,+1,-1,-1};
char characters[] = {'W', 'A', 'K', 'J', 'S', 'D'};


bool isOk( int i, int j){
    return ( i>=0 && i<n && j>=0 && j<m );

}

string DecToBin(int num ){
    string str = "";
    unsigned i;
    for( i = 1<< 3; i > 0 ; i/=2 ){
        (num & i) ? str += "1" : str += "0";
    }
    return str;
}

void PrintGrid(){
    for( int i=0; i<n; i++ ){
        for(int j=0; j<m; j++ ){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

void floodFill1( int i, int j, char c1, char c2 ){
    if(!isOk(i,j) || grid[i][j] != c1 ) return;
    grid[i][j] = c2;

    for( int it=0; it<8; it++ ){
        int x = dx[it] + i;
        int y = dy[it] + j;
        floodFill1(x,y, c1,c2);
    }

}

void floodFill2( int i, int j, int c1, int c2 )
{
    if(grid[i][j] == '0'){
        floodFill1(i,j,'0','@');
        counter++;
    }
    else grid[i][j] = c2;// Here it used to crashed. Faaak. I have to choose only one.

//    if(!isOk(i,j) || grid[i][j] != c1 ) return;
//    grid[i][j] = c2;

    for ( int it=0; it<8; it++ )
    {
        int x = dx[it] + i;
        int y = dy[it] + j;
        if(isOk(x,y) && (grid[x][y] == '1' || grid[x][y] == '0'))floodFill2(x,y,c1,c2);
    }

}



int main(){

    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int tc=0;

    while ( scanf("%ld %ld",&n,&m) ,n+m ){
//        cout << n << m << endl;
        output = "";
        for( int i = 0; i<n; i++){
            string line = "";
            for( int j=0; j<m; j++ ){
                int x = 0; char ch;
                cin >> ch;
                if(ch >= 'a' && ch <= 'f'){
                    switch ( ch ){
                        case 'a':
                            x=10; break;
                        case 'b':
                            x=11; break;
                        case 'c':
                            x=12; break;
                        case 'd':
                            x=13; break;
                        case 'e':
                            x=14; break;
                        case 'f':
                            x=15; break;
                    }
                }
                else x = ch - '0';
                line += DecToBin(x);
            }
            grid[i] = line;
        }

        m = m*4;
        //PrintGrid();
       // cout << endl ;

        for( int i=0; i<m; i++ ) {
            if(grid[0][i] == '0')floodFill1(0,i,'0','.');
            if(grid[n-1][i] == '0')floodFill1(n-1,i,'0','.');
        }

        for( int i=0; i<n; i++ ){
            if(grid[i][0] == '0')floodFill1(i,0,'0','.');
            if(grid[i][m-1] == '0')floodFill1(i,m-1,'0','.');
        }

        for(int k=0; k<n; k++ ){
            for( int l=0; l<m; l++ ){
                if(grid[k][l] == '1'){
                    counter =0;
                    floodFill2(k,l,'1','#');
                    output += characters[counter];
                }
            }
        }


        sort( output.begin(), output.end());
        printf("Case %d: ",++tc);
        cout << output << endl;

    }

    return 0;
}
