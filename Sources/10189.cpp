#include<bits/stdc++.h>

using namespace std;

int main()
{
    int x,y,T=0;

    while(1)
    {
        scanf("%d %d",&x,&y);
        if(x == 0 || y == 0)
        {
            break;
        }
        else
        {
            int mine[x+1][y+1];// array er sathe 1 jog kora valo. karon eitar jonno ami 4 ghonta dhoira boisha asi
            int cmine[x+1][y+1];

            for(int i=0; i<x; i++) //initializing all values are zeroos except stars
            {
                for(int j=0; j<y; j++)
                {
                    char ch;
                    cin>>ch;
                    if(ch == '*')
                    {
                        cmine[i][j] = -101;
                    }
                    else
                    {
                        cmine[i][j] = 0;
                    }

                }
            }

            /*for(int i=0; i<x; i++) //printing format
            {
                for(int j=0; j<y; j++)
                {
                    cout<<cmine[i][j];

                }
                cout<<endl;
                cout<<endl;
            }*/

            for(int i=0; i<x; i++) // Finding mines and setting up the values
            {
                for(int j=0; j<y; j++)
                {
                    if(cmine[i][j] == -101)
                    {
                        if(cmine[i-1][j-1] != -101 && (i-1 >= 0 || j-1 >= 0)) // && er pore condition ta check kortase je.. pore jeno kono garbage value na rakhe
                        {
                            cmine[i-1][j-1]++;
                        }
                        if(cmine[i+1][j+1] != -101 && (i+1 >= 0 || j+1 >= 0))
                        {
                            cmine[i+1][j+1]++;
                        }
                        if(cmine[i][j+1] != -101 && (i >= 0 || j+1 >= 0))
                        {
                            cmine[i][j+1]++;
                        }
                        if(cmine[i][j-1] != -101 && (i >= 0 || j-1 >= 0))
                        {
                            cmine[i][j-1]++;
                        }
                        if(cmine[i-1][j] != -101 && (i-1 >= 0 || j >= 0))
                        {
                            cmine[i-1][j]++;
                        }
                        if(cmine[i+1][j] != -101 && (i+1 >= 0 || j >= 0))
                        {
                            cmine[i+1][j]++;
                        }
                        if(cmine[i+1][j-1] != -101 && (i+1 >= 0 || j-1 >= 0))
                        {
                            cmine[i+1][j-1]++;
                        }
                        if(cmine[i-1][j+1] != -101 && (i-1 >= 0 || j+1 >= 0))
                        {
                            cmine[i-1][j+1]++;
                           // cout<<"cmine[i-1][j+1]++: "<<cmine[i-1][j+1]++<<endl;
                        }

                    }
                }
            }


            if(!T)
            {
                printf("Field #%d:\n",++T);
            }
            else
            {
                printf("\nField #%d:\n",++T);
            }


            for(int i=0; i<x; i++)
            {
                for(int j=0; j<y; j++)
                {
                    if(cmine[i][j] == -101)
                    {
                        printf("*");
                    }
                    else
                    {
                        printf("%d",cmine[i][j]);
                    }

                }
                printf("\n");

            }

        }

    }


    return 0;
}
