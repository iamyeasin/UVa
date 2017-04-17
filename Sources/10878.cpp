#include<bits/stdc++.h>

using namespace std;

char first[5000];
char str[5000];
char bin[5000];
int decs[5000];
int in=0;

void b2d()
{
    int x = atoi(bin);
    int ans=0,m=0;

    while(x>0)
    {
        int n = x%10;
        x = x/10;

        ans = ans + (n*pow(2,m));
        m++;
    }

    decs[in++] = ans;
}

void print()
{
    for(int i=0; i<in; i++)
    {
        printf("%c",decs[i]);
    }
  //  printf("\n");
}

int main()
{

    scanf(" %[^\n]",first);
    while(scanf(" %[^\n]",str) != EOF)
    {

        if(!strcmp(str,first))
        {
            break;
        }
        int len = strlen(str);
        int k=0;

        for(int i=0; i<len; i++)
        {
            if(str[i] == ' ')
            {
                bin[k++] = '0';
            }
            else if(str[i] == 'o')
            {
                bin[k++] = '1';
            }
        }

        b2d();
        memset(str,0,sizeof(str));
    }

    print();


    return 0;
}
