#include<bits/stdc++.h>

using namespace std;

int main()
{
    int kase,T=0;
    int ages[11];
    scanf("%d",&kase);

    while(kase--)
    {
       int age,n,k=0;
       cin>>age;

       for(int i=0; i<age; i++)
       {
           scanf("%d",&n);
           if(n >= 11 && n <= 20)
           {
               ages[i] = n;
               k++;
           }
       }
       //sort(ages,ages+k);

       printf("Case %d: %d\n",++T,ages[k/2]);
    }


    return 0;
}
