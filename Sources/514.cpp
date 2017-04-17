/*Solved by tracing the output! Sorry... Take a piece of paper. Trace the output.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int st[3454];
int top = 0;

void push(int n)
{
    st[top++] = n;
}

void pop()
{
//    st[top] = NULL;
    top--;
}

int tops()
{
    return st[top-1];
}


int main()
{
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);

    int p,k,i=0,flag=1;
    int arr[5000];

    while(scanf("%d",&p))
    {
        if(!p) break;
        while(1)
        {
            for(i=0; i<p; i++)
            {
                scanf("%d",&arr[i]);
                if(!arr[0])
                {
                    flag=0;
                    break;
                }
            }
            if(!flag )
            {
                puts("");
                flag = 1;
                break;
            }
            int ind=1,inf = 0,x,suru;

            for(suru = 0; suru < i; suru++)
            {
                for(; ind <= arr[inf];ind++)
                {
                    push(ind);
                }
//                cout << ind << endl;
                while(tops() == arr[inf] && (x != arr[suru]))
                {
//                    cout << arr[suru] << " ";
                    pop();
                    inf++;

                }
                if(x == arr[inf]){break;}
                x = arr[suru];

            }


            if(top<0)printf("Yes\n");
            else  printf("No\n");

            top=0,flag = 1,x = 0;
            memset(arr,0,sizeof(arr));
            memset(st,0,sizeof(st));

        }

    }




    return 0;
}
