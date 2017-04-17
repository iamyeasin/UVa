/*Simply you can also solve this by using strstr function. Time eats 1.9sec.*/

#include<stdio.h>
#include<string.h>
//#include<algorithm>

int main()
{
    char c1[100010],c2[100010];
    long kase;
    scanf("%ld",&kase);
    getchar();

    while(kase--)
    {
//        getline(cin,c1);
        gets(c1);
        int n,flag=0;
        scanf("%d",&n);
        getchar();
//        cout << c1 << endl;

        while(n--)
        {
//            getline(cin,c2);
            gets(c2);
            long l1 = strlen(c1);
            long l2 = strlen(c2),j=0,k=0,i=0,l;

            for(i=0; i < l1; i++)
            {
                if(c2[0] == c1[i])
                {
                    k++;
                    for(l=1; l<l2; l++)
                    {
                        if(c2[l] == c1[++i])k++;
                    }
                    break;
                }

            }

            if(k==l2)printf("y\n");
            else printf("n\n");
            k=0;
        }

    }


    return 0;
}

///This part GOT AC only using strstr

/*

#include<bits/stdc++.h>

using namespace std;

int main()
{
    char c1[100010],c2[100010];
    long kase;
    scanf("%ld",&kase);
    getchar();

    while(kase--)
    {
//        getline(cin,c1);
        gets(c1);
        int n,flag=0;
        scanf("%d",&n);
        getchar();
//        cout << c1 << endl;

        while(n--)
        {
//            getline(cin,c2);
            gets(c2);
            if(strstr(c1,c2))printf("y\n");
            else printf("n\n");
        }

    }


    return 0;
}
