/*Simple simulation problem. Just used recursion to solve that problem. Recursion is dangerous powerful*/

#include<bits/stdc++.h>
#define pf printf
#define sf scanf

using namespace std;

long times=0;
char s[1024];

void rev(char *from, char *to)
{
    unsigned long long len = strlen(from);
    for(int i=0; i<len; i++)
    {
        to[i] = from[len-i-1];
    }
    to[len] = '\0';
}



bool isPaling(char *str)
{
    int n = strlen(str);
    for(int i=0; i<n/2; i++)
    {
        if(str[i] != str[n-i-1])
        {
            return false;
            break;
        }
    }

    return true;
}



void toString(unsigned long long num, char *st2,char *st1)
{
    memset(st2,0,sizeof(st2));
    memset(st1,0,sizeof(st1));

    int i=0;
    while(num > 0)
    {
        st2[i++] = num%10 + '0';
        num = num/10;
    }
    st2[i] = '\0';

    rev(st2,st1);
}



void addTwo(char *st1, char *st2)
{
//    if(times > 1000) return NULL;

    unsigned long long n = atol(st1);
    unsigned long long m = atol(st2);

    unsigned long long sum = n+m;
    toString(sum,st2,st1);
    times++;

    if(isPaling(st1))
    {
        pf("%ld %s\n",times,st1);
        return;
    }
    else
    {
        addTwo(st1,st2); // Recursive.This is so fucking cool
    }

//    pf("%s %s\n",st1,st2);

}

int main()
{
//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);


    long kase;
    char num1[1024],num2[1024];
    sf("%ld\n",&kase);

    while(kase--)
    {
        times = 0;
        gets(num1);
        rev(num1,num2);
        addTwo(num1,num2);

        memset(num1,'\0',sizeof(num1));
        memset(num2,'\0',sizeof(num2));
    }



    return 0;
}
