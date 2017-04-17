#include<bits/stdc++.h>
#define MAX 2000
#define DGT 100

using namespace std;

void d2any(long num,int base,char *res)
{
    char n[DGT];
    int i=0,sign;
    if((sign = num) < 0) num = -num;

    while(num>0)
    {
        int j = (num%base);
        num = num/base;
        n[i] = (j<10) ? (j+'0') : ('A'+ j - 10); //jodi HEX na hoy taile number store korbo. ar 10 er besi hoile hex number store korbo
        i++;
    }
    if(sign < 0) n[i++]='-';
    n[i] = '\0';

    // reversing the string..
    //i-=1;
    int f;
    for(f=0; f < i; f++)
    {
        res[f] = n[i-f-1];
    }
    //i++;
    res[f] = '\0';

    //return n;
}


long toDec(char *ch,int b)
{
    int len = strlen(ch)-1;
    long sum=0;
    int p = len;
    int m=0;

    while(p>=0)
    {
        if(ch[p] >= 'A' && ch[p] <= 'Z')
        {
            int n = ch[p]-'A'+10;
            sum = sum + (n*(pow(b,m)));

        }
        else
        {
            int n = ch[p]-'0';
            sum = sum + (n*(pow(b,m)));
        }
        p--;
        m++;
    }

    return sum;
}

int main()
{
    char ch[MAX];
    char Res[MAX];
    int base,a,b;

    while(scanf("%s %d %d",&ch,&base,&b) != EOF)
    {
        long dec = toDec(ch,base);
        d2any(dec,b,Res);
        int len = strlen(Res);

        if(len>0)
        {

            for(int i=0; i<7-len; i++)
            {
                printf(" ");
            }
            if(len>7)
            {
                printf("  ERROR\n");
            }
            else
            {
                printf("%s\n",Res);
            }
        }
        else
        {
            printf("      0\n");
        }

    }


    return 0;
}
