#include<bits/stdc++.h>

using namespace std;

void toDec(char *str)
{
    int len = strlen(str);
    int p = len-1;
    int k=0,n;
    int sum = 0;

    while(p>0)
    {
        if(str[p] == 'x' && str[p-1] == '0')
        {
            break;
        }

        if(str[p] >= 'A' && str[p] <= 'F')
        {
            n = str[p]-'A'+10;
            sum += (n*(pow(16,k)));
        }
        else
        {
            n = str[p]-'0';
            sum += (n*(pow(16,k)));
        }

      //  cout<<k<<" "<<n<<" "<<sum<<endl;
        k++;
        p--;

    }

    cout<<sum<<endl;
}


int main()
{
    //freopen("C:\\Users\\Yeasin\\Desktop\\input.txt","rt",stdin);
    //freopen("C:\\Users\\Yeasin\\Desktop\\output.txt","wt",stdout);

    int kase,sum;
    char n[1000],res[1000];

    while(scanf("%s",n))
    {
        sum = 0;
        if(n[0] =='-')
        {
            break;
        }
        if(n[0]=='0' && n[1] == 'x')
        {
            toDec(n);
        }
        else
        {
            int num = atoi(n);
            printf("0x%X\n",num);
        }
    }



    return 0;
}
