/*

Using looop RT : 0.010ms
#include<bits/stdc++.h>
#define debug(x)cout << #x << "=" << (x) << endl;


using namespace std;

int main(){
    long n,k=0;

    while ( scanf("%ld",&n) ,n ){
        int used,fghij,abcde;
        int f=0;
        if(k>0)puts("");
        k++;

        for(fghij = 1234; fghij<=(98765/n); fghij++){
            int tmp; used = (fghij<10000);
            abcde = fghij * n;

            tmp = (abcde); while ( tmp ) { used |= 1 << (tmp%10); (tmp/=10);} // Ultimately it makes every th bit set. so last we just check that if every bit is on or off
            tmp = (fghij); while ( tmp ) { used |= 1 << (tmp%10); (tmp/=10);} // Setting temp%10 th bit on. 
            if(used == (1 << 10)-1){
                printf("%0.5d / %0.5d = %d\n",abcde,fghij,n);
                f=1;
            }
        }
        if(!f)printf("There are no solutions for %d.\n",n);

    }


    return 0;
}











*/

#include<bits/stdc++.h>
#define sf scanf
#define pf printf
#define mx 1000000000

using namespace std;

int arr[14]; char ans[14];
bool taken[14];
vector < pair <string , long > > num;
char ans2[1234];
bool flag[12];

bool isFound(string s, long test){
    while(test){
        int x = test%10;
        char n = x + '0';

        if(!flag[x])flag[x] = 1;
        else return false;


        for(int i=0; s[i]; i++ ){
            if(s[i] == n){
                return false;
            }
        }
        test = test/10;
    }

    return true;
}


void backTrack(int idx, int n, int N){
    if(idx == n) {
        long nn = atol(ans);
        long maal = N*nn;
        int x = log10(maal);
        if(x != 4)return;

        if(isFound(ans,maal)){
            num.push_back(make_pair(ans,maal ));
        }
        memset(flag,0,12);
        return;
    }

    for(int i=0; i<10; i++){
        if(ans[0] == '5')return;
        if(!taken[i]){
            taken[i] = 1;
            ans[idx] = arr[i] + '0';
            backTrack(idx+1,n, N);
            taken[i] = false;
        }

    }

}


int main(){

    #ifndef ONLINE_JUDGE
        freopen("in.txt", "rt", stdin);
        freopen("out.cpp", "wt", stdout);
    #endif // ONLINE_JUDGE

    for(int i=0; i<10; i++) arr[i]=i;
    long kase=1,Nm;

    while( sf("%ld", &Nm) , Nm){
        num.clear();
        memset(taken,0,sizeof taken);
        memset(ans,'\0',sizeof ans);

        if(kase > 1)puts("");
        kase++;

        backTrack(0,5,Nm);
        if(num.empty()) {
            printf("There are no solutions for %ld.\n",Nm);
            continue;
        }

        int sx =num.size();
        for(int i=0; i<sx; i++){
            cout << num[i].second << " / " << num[i].first << " = " << Nm << endl;
        }


    }

    return 0;
}
