#include<stdio.h>
#include<iostream>
#include<math.h>
#include<algorithm>
#include<string.h>

using namespace std;

char s1[101],s2[101];
char m1[] = {'E','J','L','S','Z','2','3','5','O'};
char m2[] = {'3','L','J','2','5','S','E','Z','0'};
char m3[] = {'A','H','I','M','O','T','U','V','W','X','Y','8','1','0','L'};


int miror_palin(char *str,int l)
{
    int counter=0;
    int len = l;

    for(int i=0; i<=len; i++)
    {
        for(int j=0; j<15; j++)
        {
            if(str[i] == m3[j])
            {
                counter++;
                break;
            }
        }
    }


    if(len == counter)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}


int ispalin(char *str)
{
    int len = strlen(str),flag = 1;

    for(int i=0; i<len/2; i++)
    {
        if(str[i] != str[len-i-1])
        {
            flag = 0;
            break;
        }
    }

    return flag;

}

int mirString(char *str)
{
    char s[101],ss[101];
    int flag=1;

    memset(s,0,sizeof(s)); // Clearing the array
    memset(ss,0,sizeof(ss)); //Clearing the array

    strcpy(s,str);
    int len = strlen(s);

    for(int i=0; i<len; i++)
    {
        for(int j=0; j<=8; j++)
        {
            if(s[i] == m1[j])
            {
                s[i] = m2[j];
                break;
            }
        }
    }

    //cout<<s<<endl;

    for(int i=0; i<len; i++)
    {
        ss[i] = s[len-i-1];
    }

    for(int i=0; i<len; i++)
    {
        if(str[i] != ss[i])
        {
            flag = 0;
            break;
        }
    }

    return flag;
}


int main()
{

    int i,j,ii,jj,k,l,m,n,counter=0;

    while(scanf("%s",&s1) != EOF)
    {
        l = ispalin(s1);
        strcpy(s2,s1);

        if(!l)
        {
            m = mirString(s1);
            if(m)
            {
                printf("%s -- is a mirrored string.\n",s1);
            }
            else
            {
                printf("%s -- is not a palindrome.\n",s1);
            }
        }
        else if(l)
        {
            int len = strlen(s1);
            k = miror_palin(s1,len);

            if(k)
            {
                printf("%s -- is a mirrored palindrome.\n",s1);
            }
            else
            {
                printf("%s -- is a regular palindrome.\n",s1);
            }
        }
    printf("\n");

    }


    return 0;
}
