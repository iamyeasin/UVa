#include<bits/stdc++.h>
#include<algorithm>
#define pf printf
#define sf scanf

using namespace std;

vector < string > vs;

int distance(string str , int len){
    int sum = 1235678;
    for(int i=0; i<len-1; i++){
        int x = abs (str[i] - str[i+1]);
        if(x < sum) sum = x;
    }
    return sum;
}


int main(){

//    freopen("in.txt", "rt", stdin);

    string str,str1;

     while( cin >> str ){
        int l = str.length();
        str1 = str;
        vs.push_back(str);
        for(int i=1; i<=10; i++){
            prev_permutation(str.begin(),str.end());
            vs.push_back(str);
        }
        for(int i=1; i<=10; i++){
            next_permutation(str1.begin(),str1.end());
            vs.push_back(str1);

        }
        int idx;
        int mxlen = -1  ;
        sort(vs.begin(), vs.end());
        
        int sz = vs.size();
        for(int i=0; i<sz; i++){
            int m = distance(vs[i], l);
            if( m > mxlen ) {
                mxlen = m;
                idx = i;
            }
        }

        cout << vs[idx] << mxlen << endl;
        vs.clear();
     }



    return 0;
}
