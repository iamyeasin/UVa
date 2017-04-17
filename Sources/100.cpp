#include<stdio.h>

int main()
{
    int i,j,a,b,c,m,d,e;
    while(scanf("%d %d",&a,&b)==2)
    {
        e=0;
        printf("%d %d",a,b);
        if(a>b)
        {
            m=b;
            b=a;
            a=m;
        }
        for(i=a; i<=b; i++)
        {
            c=1;
            j=i;

            while(j>1)
            {
                if(j%2==0)
                    j=j/2;
                else
                    j=(3*j)+1;

                c++;
            }
            if(c>=e)
                e=c;
        }
        printf(" %d\n",e);

    }
    return 0;
}
