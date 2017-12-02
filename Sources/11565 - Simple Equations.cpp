#include<bits/stdc++.h>
#define debug(x)cout << #x << "=" << (x) << endl;


using namespace std;

int main(){
    long kase;
    scanf("%ld",&kase);

    while( kase-- ){

        int A,B,C;
        scanf("%d%d%d",&A,&B,&C);
        bool sol = false;

        for(int x = -22; x <= 22 && !sol; x++){
            if(x*x <= C){
                for(int y = -100; y <= 100 && !sol; y++){
                    if(x != y && x*x + y*y <= C){
                        for(int z = -100; z <= 100 && !sol; z++){
                            if((x != y && y != z && z != x && x*y*z == B && x+y+z == A && x*x+y*y+z*z==C )){
                                printf("%d %d %d\n",x,y,z);
                                sol=1;
                            }
                        }
                    }
                }
            }
        }
        if(!sol)puts("No solution.");

    }

    return 0;
}
