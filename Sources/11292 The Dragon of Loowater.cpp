#include<bits/stdc++.h>
#define sf scanf
#define pf printf

using namespace std;

int main(){
//    freopen("in.txt","rt",stdin);

     long a,b,heights,head;
     int h[200001],hit[200001];

    while( sf("%ld %ld",&head, &heights) , head|heights){
        for(int i=0; i<head; i++){
            sf("%ld",&h[i]);
        }
        for(int i=0; i<heights; i++){
            sf("%ld",&hit[i]);
        }
        sort(h, h+head);
        sort(hit, hit+heights);

        int idx = 0,counter = 0, ans=0;
        for(int m=0; m<head; m++){
            while( hit[idx] < h[m]) idx++;
            if(hit[idx] >= h[m] && idx<heights) {
                counter++;
                ans += hit[idx]; idx++;
            }
        }

        if(counter < head)
            pf("Loowater is doomed!\n");
        else
            pf("%d\n",ans);
    }

    return 0;
}
