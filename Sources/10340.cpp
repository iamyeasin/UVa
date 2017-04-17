/*
Input file is larger. SO take long chars
*/

#include<bits/stdc++.h>

using namespace std;

static char s[1000005],t[1000005];

int seq()
{
    int l1 = strlen(s);
    int l2 = strlen(t);
    int k=0,sett = 0;

    if(l2 >= l1)
    {
        for(int i=0; i<l2; i++)
        {
            while(t[i] == s[k])
            {
                k++;
            }
            if(k == l1)
            {
                sett=1;
                break;
            }
            if(t[i] != s[k])
            {
                k=0;
                sett = 0;
            }
        }
    }

    if(sett)
        return 5;
    else
        return -5;

}


int caps()
{
    int k=0,sett=0;
    int l1= strlen(s);
    int l2= strlen(t);

    for(int i=0; i<l2; i++)
    {
        if(t[i] == s[k])
        {
            k++;
        }
        if(k == l1)
        {
            sett = 1;
            break;
        }

    }

    if(sett)
    {
        return 5;
    }
    else
    {
        return -5;
    }
}


int main()
{
    while(scanf("%s %s",s,t) != EOF)
    {
        int x = caps();
        int y = seq();

        if(x==5 || y==5)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }

    }

    return 0;
}
