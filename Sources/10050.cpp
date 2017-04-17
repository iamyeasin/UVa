#include<bits/stdc++.h>
#define sf scanf
#define pf printf

using namespace std;

int main()
{
//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);

    int flag[4000];
    long kase,days,n,p;

    scanf("%ld",&kase);

    while(kase--)
    {
        memset(flag,0,sizeof(flag));
        int counter = 0;

        sf("%d %d",&days,&n);

        for(int i=1; i<=n; i++)
        {
            sf("%d",&p);

            for(int j=p; j<=days; j+=p)
            {
                if(!flag[j])flag[j] = 1;
            }

            for(int f=6; f<=days; f+=6)
            {
                if(flag[f])flag[f] = 0;
                if(flag[f+1])flag[f+1] = 0;
                f+=1;
            }
        }
//            for(int l=0; l<days; l++)
//            {
//                printf("%d -> %d\n",l+1,flag[l]);
//            }

            for(int kk=1; kk<=days; kk++)
            {
                if(flag[kk])counter++;
            }
            cout << counter << endl;
            counter =0;

    }


    return 0;
}
