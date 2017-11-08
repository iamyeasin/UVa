#include<bits/stdc++.h>
#define pf printf
#define sf scanf

using namespace std;

struct nodes{
    double x1,x2,y1,y2;
    double r;
};

struct nodes data[1234];
double points[1234];

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","rt",stdin);
        freopen("output.txt","wt",stdout);
    #endif

    int kase,T=0;
    sf("%d",&kase);

    while( kase-- ){
        if(T>0)puts("");
        T++;
        int n,m;
        sf("%d",&n);
        int k=0;
        m = n;

        for(int i=0; i<n; i++) {
            cin >> data[i].x1 >> data[i].y1 >> data[i].x2 >> data[i].y2 >> data[i].r;
            if(data[i].x1 > data[i].x2){
                swap(data[i].x1,data[i].x2);
            }

            points[k++] = data[i].x1;
            points[k++] = data[i].x2;
        }

        sort(points,points+k);
        pf("%d\n",2*n+1);
        pf("-inf %0.3lf %0.3lf\n", points[0], 1.000);
        for(int i=1; i<k; i++){
            double f1 = points[i];
            double f2 = points[i-1];
            double cof = 1.000;

            for(int p=0; p<n; p++){
                if((f1 > data[p].x1 && f1 < data[p].x2) || (f2 >= data[p].x1 && f2 < data[p].x2)){
                    cof *= data[p].r;
                }
            }
            pf("%0.3lf %0.3lf %0.3lf\n",f2,f1,cof);
        }
        pf("%0.3lf +inf %0.3lf\n", points[k-1], 1.000);
        memset(data,0,sizeof data);
        memset(points,0.0,sizeof points);

    }


    return 0;
}
