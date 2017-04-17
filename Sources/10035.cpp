/*
    This problem also can be done in easy system. by dividing
    but treating as character it got my rank faster.I am an ASS! or BHODAI
*/
#include<bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("C:\\Users\\Yeasin\\Desktop\\input.txt","rt",stdin);
    //freopen("C:\\Users\\Yeasin\\Desktop\\output.txt","wt",stdout);

    char s1[50],s2[50];

    while(scanf("%s %s",s1,s2))
    {
        if(s1[0]=='0' && s2[0] == '0')
        {
            break;
        }

        int l1 = strlen(s1);
        int l2 = strlen(s2);

        int now1,now2,counter=0,sum;
        int carry=0;

        for(now1 = l1-1, now2=l2-1; (now1 >=0 && now2 >= 0); now1--,now2--)
        {

            sum = (s1[now1]-'0') + (s2[now2]-'0') + carry;

            carry = sum/10;
            if(carry>0)
            {
                counter++;
            }
        }

        for(;now1 >= 0; now1--)
        {
            sum = s1[now1]-'0'+carry;
            carry = sum/10;
            if(carry>0)
            {
                counter++;
            }
        }

        for(;now2 >= 0; now2--)
        {
            sum = s2[now2]-'0' + carry;
            carry = sum/10;
            if(carry>0)
            {
                counter++;
            }

        }

        if(!counter)
        {
            printf("No carry operation.\n");
        }
        else if(counter == 1)
        {
            printf("%d carry operation.\n",counter);
        }
        else
        {
            printf("%d carry operations.\n",counter);
        }


    }


    return 0;
}
