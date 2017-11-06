#include<stdio.h>
#include<string.h>

int main()
{
    char str[21];
    printf("         NAME                     SOUNDEX CODE\n");
    while(scanf("%s",str) != EOF)
    {
        char ans[5];
        int k=0;
        ans[k++] = str[0];
        for(int i=1; str[i]; i++)
        {
            if(k > 3)break;
            if(str[i] == 'B' || str[i] == 'P' || str[i] == 'F' || str[i] == 'V')
            {
                if(str[i-1] != 'B' && str[i-1] != 'P' && str[i-1] != 'F' && str[i-1] != 'V')ans[k++] = '1';
            }
            else if(str[i] == 'C' || str[i] == 'K' || str[i] == 'G' || str[i] == 'S' || str[i] == 'J' || str[i] == 'Q' || str[i] == 'X' || str[i] == 'Z')
            {
                if(str[i-1] != 'C' && str[i-1] != 'K' && str[i-1] != 'G' && str[i-1] != 'S' && str[i-1] != 'J' && str[i-1] != 'Q' && str[i-1] != 'X' && str[i-1] != 'Z')ans[k++] = '2';
            }
            else if(str[i] == 'D' || str[i] == 'T')
            {
                if(str[i-1] != 'D' && str[i-1] != 'T')ans[k++] = '3';
            }
            else if(str[i] == 'L')
            {
                if(str[i-1] != 'L')ans[k++] = '4';
            }
            else if(str[i] == 'M' || str[i] == 'N')
            {
                if(str[i-1] != 'M' && str[i-1] != 'N')ans[k++] = '5';
            }
            else if(str[i] == 'R')
            {
                if(str[i-1] != 'R')ans[k++] = '6';
            }
        }
        if(k < 4)
        {
            for(int i=k; i<4; i++)ans[i] = '0';
        }
        ans[4] = '\0';
        int len = strlen(str);
        printf("         %s",str);
        for(int i=0; i<25-len; i++)printf(" ");
        printf("%s\n",ans);
    }
    printf("                   END OF OUTPUT\n");
    return 0;
}
