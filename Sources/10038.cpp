/*Ami ekta gadha. successive elements take on all the values 1 through n-1.
Eitar mane  1 theika n-1 porjonto sequence er sobgula number thaklei seita jolly jumper.
dhoro.. jodi difference thake 1 3 2 ar number gula jodi thake 1 2 5 7 tailei eita jolly jumper
karon 1- theika to n-1 mane 3 porjonto sobgula number e ase.. difference e .. kintu sequentially
howar dorkar nai... tai eita jolly jumper.kintu difference e kono number na thakle jamon 1 3 2 er
bodole 1 4 2 thakto taile jolly jumper hoito na..
*/

#include<bits/stdc++.h>

using namespace std;

int num[3005];
int flag=0;
bool flags[3025];

int isJolly(int x)
{
    int k=0,flag=0;

    for(int i=0; i<3025; i++)
    {
        flags[i] = false;
    }

    int m = x-1;
    for(int i=0; i<m; i++)
    {
        int di = abs(num[i] - num[i+1]);

        flags[di] = 1;
        //cout<<di<<endl;
    }

    for(int i=1; i<=m; i++)
    {
        if(flags[i] == 0)
        {
            flag = 1;
            return flag;
        }
        //cout<<flags[i]<<endl;
    }

    return flag;
}


void in(int n) // Just normal input
{
    for(int i=0; i<n; i++)
    {
        num[i] = 0;
    }

    for(int i=0; i<n; i++)
    {
        scanf("%d",&num[i]);
    }
}


int main()
{
    //freopen("C:\\Users\\Yeasin\\Desktop\\input.txt","rt",stdin);
    //freopen("C:\\Users\\Yeasin\\Desktop\\output.txt","wt",stdout);


    int n;
    while(scanf("%d",&n) != EOF)
    {
        in(n);
        int m = isJolly(n);

        //cout<<m<<endl;

        if(m)
        {
            printf("Not jolly\n");
        }
        else
        {
            printf("Jolly\n");
        }
        flag = 0;

    }


    return 0;
}
