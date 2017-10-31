#include<bits/stdc++.h>
#define sf scanf
#define pf printf

using namespace std;

int main(){

//    freopen("in.txt","rt",stdin);
//    freopen("out.txt","wt",stdout);


    long N,k=0;
    int arr[20];
    vector <string> vs;

    while( sf("%ld",&N) , N){
        if(k>0)puts("");
        vs.clear();
        k++;
        for(int i=0; i<N; i++)sf("%d",&arr[i]);

        for(int i=0; i< (1 << N); i++){
            string s= "";
            for(int j=0; j<N; j++){
                if( i & (1 << j)){
                    s += (arr[j] + '0');
                }
            }
            if(s.size() == 6){
//                cout << s << endl;
                vs.push_back(s);
            }
        }

        sort(vs.begin(),vs.end());

        int sz = vs.size();
        for(int i=0; i<sz; i++){
            string test = vs[i];
            sort(test.begin(),test.end());

            int szs = test.size();
            for(int m=0; m<szs; m++){
                if(m == szs-1){
                    pf("%d\n",test[m]-'0');
                }
                else{
                    pf("%d ",test[m]-'0');
                }
            }
        }


    }



    return 0;
}
