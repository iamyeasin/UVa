/* BFS SOLUTION WITH STL, TIME COST : 50 MS; THE BEST I COULD */ 

#include <bits/stdc++.h>
#define     sf      scanf
#define     pf      printf
#define     dbg     cout << "Debug" << endl;

using namespace std;

vector < int > adjList[1024];
vector < char > ans;
queue  < int > q;
int T,M,steps,n=0,it=0,counter=0,flag=0;

void printGrid();
int front, rear,Trapped,Thesus;
bitset < 1024 > L;


void BFS( int M, int T ) {
    q.push(M);
    int counter=0;

    while( !q.empty() ){
        M = q.front();
        q.pop(); counter++;
        int sz = adjList[M].size();
        bool f = 0;
        if( counter == steps ) {
            counter = 0;
            L[M] = 1;
            ans.push_back( M + 'A');
        }

        for( int i=0; i<sz; i++ ){
            int v = adjList[M][i];
            if ( L[v] == 0 && v != T ){
                q.push(v); f = 1;
                break;
            }
        }
        
        if(!f){
            Trapped = M;
            Thesus = T;
            return;
        }
        T = M;
    }
}


void clr(){
    for( int i=0; i<150; i++ ){
        adjList[i].clear();
    }
    Trapped = Thesus = flag = 0;
    L.reset();
    ans.clear();
}

void printGrid(){

   for( int i=0; i<n; i++ ){
            int sz = adjList[i].size();
            cout << i << " -> ";
            for( int j=0; j<sz; j++ ){
                cout << adjList[i][j] << " ";
        }
        cout << endl;
    }
}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("in.txt","rt",stdin);
        freopen("out.txt","wt",stdout);
    #endif

    char str[1024];
    front = rear = 0;
    clr();

    while ( sf( "%s", str) , str[0] != '#' ) {

        counter = flag = n = 0 ;
        int i=0;

        scanf(" %c %c %d",&M,&T,&steps );

        for( int i=0; str[i]; i++ ){
            if( str[i] == ':' ){
                int nd = str[i-1] - 'A';n++;     

                while( (str[i++] != ';' || str[i] != '.') && str[i] ){
                        if(str[i] == ';' || str[i] == '.' ) break;
                    int nn = str[i] - 'A';
                    if( nn >= 0 ) adjList[nd].push_back( nn );
                }
            }
        }

      BFS( M-'A' , T-'A' );

        for( auto x : ans ){
            if( x != (Trapped+'A') ) printf("%c ",x);
        }
        printf("/%c\n",Trapped+'A');

        clr();
    }


    return 0;
}


/* BFS SOLUTION WITH QUEUE IMPLEMENTATION WITH ARRAY */

#include    <bits/stdc++.h>
#define     sf      scanf
#define     pf      printf
#define     dbg     cout << "Debug" << endl;
#define		MAX		1024

using namespace std;

void clr();
void printGrid();

char str[MAX],ans[MAX];
int adjMat[MAX][MAX],Q[MAX];
vector< int > adjList[1024];
int front,rear,counter=0,it=0,flag = false, T,M,steps,Trapped,Thesus,node = 0;
bitset < 2048 > L;

void push( int x ){
	Q[rear++] = x;
}

void pop(){
	Q[front++] = -1;
}

bool isEmpty(){
	if(front == rear) return true;
	return false;
}

int top(){
	return Q[front];
}

void BFS( int M, int T ){
	front = rear = counter = 0;
	push(M);

	while( !isEmpty() ){
		M = top();
		pop();
		counter++;
		flag = false;

		if( counter == steps ){
			counter = 0 ; ans[it++] = 'A' + M;
			L[M] = 1;
		}

		int sz = adjList[M].size();

		for( int i=0; i < sz; i++ ){
			int v = adjList[M][i];
			if( L[v] == 0 && v != T ){
				push(v); flag = 1;
				break;
			} 
		}		

		if( !flag ){
			Trapped = M;
			Thesus = T;
			return;
		} 

		T = M;
	}
}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("in.txt","rt",stdin);
        freopen("out.txt","wt",stdout);
    #endif
	clr();
	
    while( sf("%s",str), str[0] != '#' ){
        counter = flag = 0 ;
        scanf(" %c %c %d",&M,&T,&steps );

        for( int i=0; str[i]; i++ ){
            if( str[i] == ':' ){
                int nd = str[i-1] - 'A';node++;
                int len = strlen(str);
                while( (str[i++] != ';' || str[i] != '.') && i < len ){
                        if(str[i] == ';' || str[i] == '.' ) break;
                    int nn = str[i] - 'A';
                    if( nn >= 0 ) adjList[nd].push_back( nn );
                }
            }
        }
        //printGrid();

        BFS( M-'A', T-'A' );
        for( int i=0; i<it; i++ ){
        	if( ans[i] != ( 'A' + Trapped ) )
        		printf("%c ", ( ans[i]) );
        }
        printf("/%c\n",( 'A' + Trapped ) );
        clr();
    }

    return 0;
}

void clr(){
	L.reset();
    for( int i=0; i<MAX; i++ ){ 
        adjList[i].clear();
        // Q[i] = -1;
        L[i] = 0;
    }

    Trapped = Thesus = flag = 0;
    node = 0;
	it = Trapped = Thesus = counter = front = rear = steps = T = M = it = 0;
}


void printGrid(){
	//cout << node << endl;
	for( int i=0; i<node; i++ ){
		int sz = adjList[i].size();
		for( int j=0; j<sz; j++ ){
			cout << adjList[i][j] << " ";
		}
		cout << endl;
	}
}
