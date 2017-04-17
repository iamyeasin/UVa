#include<bits/stdc++.h>

using namespace std;

bool isPrime(int p)
{
    int flag;
    if(!p)
        return false;
    else if(p == 1)
        return true;
    else if(p == 2)
        return true;
    else if(!(p&1))
        return false;
    else
    {
        flag =0;
        for(int i=3; i*i<=p; i++)
        {
            if(p%i == 0)
            {
                flag = 1;
                break;
            }
        }
    }

    if(flag)
    {
        return false;
    }
    else
    {
        return true;
    }
}


int main()
{
    int small[52];
    char word[5001];

    while(scanf("%s",&word) != EOF)
    {
        int len = strlen(word);
        int sum = 0;

        for(int i=0; i<len; i++)
        {
            if(word[i] >= 'a' && word[i] <= 'z')
            {
                //cout<<word[i]-'a'+1<<endl;
               sum = sum + (word[i] - 'a'+ 1);
            }
            else if(word[i] >= 'A' && word[i] <= 'Z')
            {
                sum = sum + (word[i] - 'A')+ 27;
               //cout<<word[i]-'A'+ 27<<endl;
            }
        }

        //cout<<sum<<endl;

        if(isPrime(sum))
        {
            printf("It is a prime word.\n");
        }
        else
        {
            printf("It is not a prime word.\n");
        }
    }



    return 0;
}
