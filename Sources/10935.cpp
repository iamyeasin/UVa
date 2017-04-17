#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>

using namespace std;

int rare=0,frnt=0,m=0;

int num[5000];
int disc[5000];


void init(int n)
{
    for(int i=1; i<=n; i++)
    {
        num[rare++] = i;
    }
}

void enq(int x)
{
    num[rare++] = x;
}

void deq()
{
    int x = num[frnt++];
    disc[m++] = x;
}

int main()
{
//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);

    int kount=0,kase,n,flag=0;

    while(scanf("%d",&n)&& n<=50)
    {
        if(!n) break;
        if(n==1 && !flag)
        {
            flag = 1;
            printf("Discarded cards:\n");
            printf("Remaining card: 1\n");
            continue;
        }
        flag =0;

        init(n);

        int i=frnt;
        while(1)
        {
            if(!(i&1))
            {
                deq();
            }
            else
            {
                int m = num[i];
//            cout<<m<<endl;
                enq(m);
                frnt++;
            }
            i++;
            if(abs(rare-frnt) <= 1)break;

        }

        printf("Discarded cards: ");
        for(int i=0; i<m; i++)
        {
            if(i<m-1)
            {
                printf("%d, ",disc[i]);
            }
            else
            {
                printf("%d",disc[i]);
            }
        }
        printf("\nRemaining card: %d\n",num[frnt]);
        frnt = rare = m = i =0;

    }



    return 0;
}

