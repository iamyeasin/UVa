#include<bits/stdc++.h>
#define sf scanf
#define pf printf

using namespace std;

int arr[1234],ans2[1234],ans[1234],acopy[1234],taken[1234];
vector < pair < int , int > > vc;
int t,n,flag=0,till=0,h_sum=0;

void backTrack(int idx, int id, int sum1){
    if(n == sum1){
        till = id; h_sum = sum1;
        for(int i=0; i<id; i++){
            ans2[i] = ans[i];
        }
        flag=1;
        return;
    }

    if(sum1 < n && sum1 > h_sum){
        h_sum = sum1; till = id;
        for(int i=0; i<id; i++) ans2[i] = ans[i];
    }


    for(int i=idx; i<t; i++){
        if(flag)return;

        if(!taken[i]){
            int s = vc[i].first + sum1;
            if(s <= n) {
                taken[i] = 1;
                ans[id] = vc[i].second;
                backTrack(i+1,id+1,s);
                taken[i] = false;
            }
        }

    }
}


int main(){

//    freopen("input.txt", "rt", stdin);
//    freopen("out.txt", "wt", stdout);


    while( sf("%d %d",&n,&t) != EOF ){
        flag = till = h_sum = 0 ;
        vc.clear();
        for(int i=0; i<t; i++){
            arr[i] = ans[i] = ans2[i] = taken[i] = 0;
        }

        int sum=0;
        for(int i=0; i<t; i++){
            sf("%d",&arr[i]);
            vc.push_back( make_pair(arr[i], i) );
            acopy[i] = arr[i];
            sum += arr[i];
        }

        if(sum < n){
            for(int i=0; i<t; i++){
                pf("%d ",arr[i]);
            }
            pf("sum:%d\n",sum);
            continue;
        }

        sort(vc.begin(), vc.end());
        backTrack(0,0,0);
        sort(ans2,ans2+till);

        sum = 0;
        for(int i=0; i<till; i++){
            pf("%d ",acopy[ans2[i]]);
            sum += acopy[ans2[i]];
        }
        pf("sum:%d\n",sum);

    }


    return 0;
}
