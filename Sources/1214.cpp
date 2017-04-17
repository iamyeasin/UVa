#include <stdio.h>
#include <string.h>

int main()
{
    char n1[201];
    int kase,T=0,n2;
    long long int remainder;
    scanf("%d",&kase);

    while(kase--)
    {
        scanf("%s %d",&n1,&n2);
        remainder = 0;
        for(int i=0; i<strlen(n1); i++)
        {
            if(n1[i] == 45)
            {
                continue;
            }
            else if(n1[i] >= 48 && n1[i] <= 57)
            {
                remainder = remainder*10 + n1[i]-48;
                remainder = remainder%n2;
            }
        }
        if(!remainder)
        {
            printf("Case %d: divisible\n",++T);
        }
        else
        {
            printf("Case %d: not divisible\n",++T);
        }

    }




    return 0;
}
