#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int top=0,rare=0;
char bar[256];


void pushs(char ch)
{
    bar[top++] = ch;
}

void pops()
{
    bar[top--] = NULL;

}

char tops()
{
    return bar[top-1];
}

int main()
{
//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);

    char par[140];
    int kase,flag;
    scanf("%d",&kase);
    getchar();

    while(kase--)
    {
        gets(par);
        flag = 0;
        int len = strlen(par);

        if(len&1 && len != 0)
        {
            printf("No\n");
            continue;
        }

        if(len == 0)
        {
            printf("Yes\n");
            continue;
        }
        int i;
        for(i=0; i<len; i++)
        {

            if(par[i] == '(' || par[i] == '[')
            {
                pushs(par[i]);
//                printf("\n%s\n",bar);
            }
            else if(par[i] == ')')
            {

                if(tops() == '(')
                {
                    pops();
                }
                else
                {
                    printf("No\n");
                    flag = 1;
                    break;
                }
            }
            else if(par[i] == ']')
            {
                if(tops() == '[')
                {

                    pops();
                }
                else
                {
                    printf("No\n");
                    flag = 1;
                    break;
                }
            }
//            cout<<top<<endl;
        }

//        printf("\n%s\n",bar);

        if(top > 0 && !flag)
        {
            printf("No\n");
        }
        else if (top <= 0 && !flag)
        {
            printf("Yes\n");
        }

        memset(bar,'\0',sizeof(bar));
        memset(par,'\0',sizeof(par));
        top = 0;
    }



    return 0;
}
