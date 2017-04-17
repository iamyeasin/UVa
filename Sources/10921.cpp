#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int main()
{
    char s1[50];
    while((scanf("%s",&s1))==1)
    {
        for(int i=0; i<strlen(s1); i++)
        {
            if(s1[i] == '1')
            {
                printf("1");
            }
            else if(s1[i] == '0')
            {
                printf("0");
            }
            else if(s1[i] == ' ')
            {
                printf(" ");
            }
            else if(s1[i] == '-')
            {
                printf("-");
            }
            else if(s1[i] >= 65 && s1[i] <= 67)
            {
                printf("2");
            }
            else if(s1[i] >= 68 && s1[i] <= 70)
            {
                printf("3");
            }
            else if(s1[i] >= 71 && s1[i] <= 73)
            {
                printf("4");
            }
            else if(s1[i] >= 74 && s1[i] <= 76)
            {
                printf("5");
            }
            else if(s1[i] >= 77 && s1[i] <= 79)
            {
                printf("6");
            }
            else if(s1[i] >= 80 && s1[i] <= 83)
            {
                printf("7");
            }
            else if(s1[i] >= 84 && s1[i] <= 86)
            {
                printf("8");
            }
            else if(s1[i] >= 87 && s1[i] <= 90)
            {
                printf("9");
            }
        }

        printf("\n");
    }



    return 0;
}
