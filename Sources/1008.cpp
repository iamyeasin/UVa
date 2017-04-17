#include<stdio.h>
#include<string.h>

int main()
{
    char ch[500];
    int a,b,u,i,j,n;
    scanf("%d",&a);
    int num[30];

         for(j=0;j<30;j++)
            {
                num[j]=0;
            }
        gets(ch);
        for(i=0;i<strlen(ch);i++)
            {
                b=ch[i]-'a';
                num[b]++;
            }
        for(n=0;n<26;n++)
        {
            if(num[n]!=0)
            {
                printf("%c",n+'a');
                for(i=0;i<num[n];i++)
                    printf(" *");

                printf("\n");
            }
        }

    return 0;
}
