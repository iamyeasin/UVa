#include<bits/stdc++.h>

using namespace std;

int main()
{
    int kase,n,sum = 0;
    char s1[5];
    scanf("%d",&kase);

    while(kase--)
    {
        scanf("%s",&s1);
        if(s1[0] == 'd' && s1[1] == 'o' && s1[5] == 'e')
        {
            scanf("%d",&n);
            sum += n;
        }
        else if(s1[0] == 'r' && s1[5] == 't')
        {
            printf("%d\n",sum);
        }

    }



    return 0;
}
