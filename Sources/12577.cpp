#include<stdio.h>
#include<string.h>

int main()
{
    char arr[10];
    int counter=1;

    while(arr[0] != '*')
    {
        scanf("%s",arr);
        if(arr[0] == 'H' || arr[0] == 'h' && arr[3] == 'j')
        {
            printf("Case %d: Hajj-e-Akbar\n",counter++);
        }
        else if(arr[0] == 'U' || arr[0] == 'u' && arr[4] == 'h')
        {
            printf("Case %d: Hajj-e-Asghar\n",counter++);
        }
    }
    counter = 1;


    return 0;
}
