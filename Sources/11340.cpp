#include<bits/stdc++.h>

using namespace std;

int main()
{
    int Case,sum;
    cin>>Case;

    while(Case--)
    {
        sum = 0;
        int k;
        cin>>k;

        int pay[k];
        char ch[k];

        for(int i=0; i<k; i++)
        {
            cin>>ch[i];
            cin>>pay[i];
        }
        int lines,counter=0;
        cin>>lines;
        char chs;
        getchar();
        while((scanf("%c",&chs)) != EOF)
        {
            if(chs == '\n')
            {
                counter++;
            }
            if(counter == lines)
            {
               // cout<<sum<<endl;
                break;
            }

            for(int i=0; i<k; i++)
            {
                if(chs == ch[i])
                {
                    sum = sum + pay[i];
                    //cout<<sum<<" "<<chs<<" "<<ch[i]<<endl;
                }
            }
        }

        printf("%.2lf$\n",sum*1/100.00);
        //cout<<sum*1/100.00<<"$"<<endl;
        //}
    }

    return 0;
}


/*Time : .280*//*

#include<bits/stdc++.h>
#define sf scanf
#define pf printf

using namespace std;

int main()
{
//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);

    int kase;
    double cost[5000];
    char let[5000];
    double money;
    scanf("%d",&kase);

    while(kase--)
    {
        int paid;
        scanf("%d\n",&paid);

        for(int i=0; i<paid; i++)
        {
//            cout << i;
            sf("%c %lf\n",&let[i],&cost[i]);
//            sf("%lf",&cost[i]);
        }

        int line;
        sf("%d\n",&line);

        char lines[10000];
        char ch;

        for(int k=0; k<line; k++)
        {
            gets(lines);
//            puts(lines);

            int l = strlen(lines);
            for(int i=0; i<l; i++)
            {
                ch = lines[i];
                for(int m=0; m<paid; m++)
                {
                    if(ch == let[m])
                    {
                        money+=cost[m];
                    }
                }
            }
            memset(lines,0,sizeof(lines));
        }
        pf("%.2lf$\n",money/100.00);
        memset(cost,0,sizeof(cost));
        memset(let,0,sizeof(let));
        money = 0.00;


    }



    return 0;
}
*/
