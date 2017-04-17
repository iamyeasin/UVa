#include<bits/stdc++.h>

using namespace std;

int main()
{

    char ch[2];
    while(scanf("%c",&ch[0]) != EOF)
    {
        if(ch[0] == '\n')
        {
            printf("\n");
        }
        else
        {
            printf("%c",ch[0]-7);
        }
    }


    return 0;
}
