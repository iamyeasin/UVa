/*
Eikhane theory ta hoilo .. je protibar amar permutation calanor dorkar nai
suppose amar ase "abc", n = 3
so for 3 character it'll be 3! = 6;
so for 1 character it'll be 6/3 = 2;
if n = 3 then, it'll 

*/

#include<bits/stdc++.h>
#define sf scanf
#define pf printf

using namespace std;

unsigned long long fact[25];
unsigned long long n;
int arr[1234]; int sz=0;
string ans = "";

void f(){
    fact[0] = 1;
    fact[1] = 1;
    for(int i=2; i<22; i++) fact[i] = i * fact[i-1];
}


void magic(string s, unsigned long long int n){
    long len = s.length();
    if(len > 0){
        unsigned long long int fct = fact[len]/len; // for 1 char = fct permutations

        long long rem = n%fct;
        long long div = n/fct;

        ans += s[div];
        string temp = "";

        for(int i=0; s[i]; i++){
            if(s[i] != s[div]){
                temp += s[i];
            }
        }
        magic(temp , rem);
    }
    else
    {
        cout << ans << endl;
        ans = "";
    }

}

int main(){

    std :: ios_base::sync_with_stdio();
    cin.tie();

    f();
    long long tc;
    sf("%lld",&tc);

    while(tc--){
        string s = "";
        cin >> s;

        sort(s.begin(), s.end());
        sf("%llu",&n);
        sz = s.length();
        magic(s, n);

    }

    return 0;
}
