#include<bits/stdc++.h>

using namespace std;

int main()
{
    long persons,budget,hotels,weeks,p;
    long avail_seats[10001],price[10001],costs[10001];

    while(scanf("%ld %ld %ld %ld",&persons,&budget,&hotels,&weeks) != EOF)
    {
        memset(avail_seats,0,sizeof(avail_seats));
        memset(price,0,sizeof(price));
        // memset(costs,1,sizeof(costs));

        if(persons >= 1 && persons <= 200 && budget >= 1 && budget <= 500000 && hotels <= 18 && weeks >= 1 && weeks <= 13)
        {
            int i,j,k=0;
            for(i=0; i<hotels; i++)
            {
                //scanf("%d",&price[i]);
                scanf("%ld",&p);
                if(p >= 1 && p <= 10000)
                {
                    for(j=0; j<weeks; j++)
                    {
                        scanf("%ld",&avail_seats[j]);
                        if(avail_seats[j] >= persons && avail_seats[j] >= 1 && avail_seats[j] <= 1000)
                        {
                            costs[k] = p*persons;
                            k++;
                        }
                    }

                }

            }

            sort(costs,costs+k);

            if(costs[0] < budget && k>0)
            {
                printf("%ld\n",costs[0]);
            }
            else
            {
                printf("stay home\n");
            }
        }
    }

    return 0;
}

/*

#include<bits/stdc++.h>

using namespace std;

int main()
{
    long persons,budget,hotels,weeks,p;
    long avail_seats[10001],price[10001],costs[10001];

    while(scanf("%ld %ld %ld %ld",&persons,&budget,&hotels,&weeks) != EOF)
    {
        memset(avail_seats,0,sizeof(avail_seats));
        memset(price,0,sizeof(price));
        // memset(costs,1,sizeof(costs));

        //if(persons >= 1 && persons <= 200 && budget >= 1 && budget <= 500000 && hotels <= 18 && weeks >= 1 && weeks <= 13)
        //{
            int i,j,k=0;
            for(i=0; i<hotels; i++)
            {
                //scanf("%d",&price[i]);
                scanf("%ld",&p);
                //if(p >= 1 && p <= 10000)
                //{
                    for(j=0; j<weeks; j++)
                    {
                        scanf("%ld",&avail_seats[j]);
                        if(avail_seats[j] >= persons)
                        {
                            costs[k] = p*persons;
                            k++;
                        }
                   // }

                }

            }

            sort(costs,costs+k);

            if(costs[0] < budget && k>0)
            {
                printf("%ld\n",costs[0]);
            }
            else
            {
                printf("stay home\n");
            }
        //}
    }

    return 0;
}

*/
