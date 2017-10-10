#include<bits/stdc++.h>

using namespace std;

vector < string > vs;

void comb(string soFar, string org, int k, int r){

    if(soFar.length() == r){
        vs.push_back(soFar);
    }

    for(int i=k; i<org.length(); i++){
        comb(soFar+org[i] , org, i+1, r);
        while( org[i+1] == org[i]) i++;
    }
}


int main(){

//    freopen("in.txt","rt",stdin);
//    freopen("out.txt","wt",stdout);

    string s1;
    int r;

    while(cin >> s1 >> r){
        sort(s1.begin(), s1.end());
        comb("", s1, 0, r);
        for(int i=0; i<vs.size(); i++){ cout << vs[i] << endl; }
//        puts("");

        vs.clear();
    }
    return 0;
}
