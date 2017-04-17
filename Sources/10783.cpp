#include<stdio.h>

int main()
{
    int a,b,c,d,e,f,i,j;

while(scanf("%d",&a)==1)//Eikhane eita howar karon hoilo ...prosne multiple test case koise...so multiple korte ei tecnique use kora hoise...
{
    for(i=1; i<=a; i++)
    {
        scanf("%d %d",&b,&c);
        f=0;

        if(b%2==0)
            b=b+1;
        for(j=b; j<=c; j+=2)
            f+=j;
        printf("Case %d: %d\n",i,f);
    }

}
    return 0;
}

