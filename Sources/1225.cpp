#include<bits/stdc++.h>

using namespace std;

int main()
{
    int kase;
    scanf("%d",&kase);
    int digit[12];


    while(kase--)
    {
        int n,i;
        scanf("%d",&n);

        for(int ii=0; ii<=11; ii++)
        {
            digit[ii]=0;
        }
        //  cout<<endl;

        for(i=1; i<=n; i++)
        {
            if(i>= 1 && i<=9)
            {
                digit[i]++;
            }
            else
            {
                int xx = i;
                while(xx>0)
                {
                    int d = xx%10;
                    xx /= 10;
                    digit[d]++;
                }
            }
        }

        for(int j=0; j<10; j++)
        {
            if(j == 9)
            {
                printf("%d\n",digit[j]);
            }
            else
            {
                printf("%d ",digit[j]);
            }

        }

    }

    return 0;
}
