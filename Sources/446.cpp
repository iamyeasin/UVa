#include<bits/stdc++.h>

using namespace std;

char bin1[15];
char bin2[15];

int e1,e2;

long toDec(char *str)//Converting HEX TO BIN
{
    int len = strlen(str)-1;
    long sum = 0;
    int p = len,n;
    int m = 0;

    while(p>=0)
    {
        if(str[p] >= 'A' && str[p] <= 'F')
        {
            n = str[p] - 'A'+10;
            sum += (n*pow(16,m));
        }
        else
        {
            n = str[p]-'0';
            sum += (n*pow(16,m));
        }

        // cout<<p<<" "<<m<<" "<<sum<<endl;
        m++;
        p--;

    }

    return sum;
}


void bin(int s1,int s2)
{
    memset(bin1,0,sizeof(bin1));
    memset(bin2,0,sizeof(bin2));
    e1=e2=0;
    int i=0,j=0;

    while(s1)
    {
        if(s1&1) // Converting & Storing s1 into BIN1
        {
            bin1[i++] = '1';
        }
        else
        {
            bin1[i++] = '0';
        }
        s1=s1>>1;

    }
    bin1[i]='\0';

    while(s2)
    {
        if(s2&1) //Converting & Storing Into BIN2
        {
            bin2[j++] = '1';
            s2=s2>>1;
        }
        else
        {
            bin2[j++] = '0';
            s2=s2>>1;
        }
    }
    bin2[j]='\0';

    e1 = i-1;
    e2 = j-1;

}


int main()
{
    //freopen("C:\\Users\\Yeasin\\Desktop\\input.txt","rt",stdin);
    //freopen("C:\\Users\\Yeasin\\Desktop\\output.txt","wt",stdout);

    char num[15],num2[15],ch;
    int n,sum,sub,flag;
    cin>>n;

    while(n--)
    {
        scanf("%s ",num);
        scanf(" %c ",&ch);
        scanf("%s",num2);
        sum=sub=0;
        int d1 =toDec(num);
        int d2 =toDec(num2);
        if(ch== '+')
        {
            flag =1;
            sum = d1+d2;
        }
        else if(ch == '-')
        {
            flag = 0;
            sub = d1-d2;
        }
        bin(d1,d2);

        int t1= 13-e1-1;
        for(int i=0; i<t1; i++)
        {
            printf("0");
        }
        for(int j=e1; j>=0; j--)
        {
            printf("%c",bin1[j]);
        }
        printf(" %c ",ch);


        int t2 = 13-e2-1;
        for(int i=0; i<t2; i++)
        {
            printf("0");
        }
        for(int j=e2; j>=0; j--)
        {
            printf("%c",bin2[j]);
        }

        if(!flag)
        {
            printf(" = %d\n",sub);
        }
        else
        {
            printf(" = %d\n",sum);
        }

    }



    return 0;
}
