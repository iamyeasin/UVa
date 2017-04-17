/*Read CP book for understanding the teching for printing a new line between the two test cases. String input newa eita manage koira dise sojol vai..*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char st[1024];
int top=0;

void push(char c)
{
    st[top++] = c;
}

void pop()
{
    st[top] = NULL;
    top--;
}

char tops()
{
    return st[top-1];
}

int isPrec(char ch)
{
    switch(ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    }
    return -1;
}

int isOperand(char c)
{
    if(c >= '0' && c <= '9')return 1;
    else return 0;
}

int main()
{
//    freopen("input.txt", "rt", stdin);
//    freopen("output.txt", "wt", stdout);

    int testCases,i=0,e=0,c=1;
    char letter[10], word[1024],eqn[1201];
    scanf("%d\n", &testCases);
//    gets(letter);

    int k,f;

    for( k=1; k<=testCases; k++ )
    {
        while( gets(letter) )
        {
            if(!letter[0]) break;
            word[i++] = letter[0];
        }
        word[i] = '\0';

        for(f=0; f<i; f++)
        {
            char ch = word[f];

            if(isOperand(ch))
            {
                eqn[e++] = ch;
            }
            else if(ch == '(')
            {
                push(ch);
            }
            else if(ch == ')')
            {
                while(tops() != '(')
                {
                    eqn[e++] = tops();
                    pop();
                }
                if(tops() == '(')pop();
            }
            else
            {
                if(isPrec(ch) > isPrec(tops()) || top == 0)
                {
                    push(ch);
                }
                else if(isPrec(ch) <= isPrec(tops()))
                {
                    while(isPrec(ch) <= isPrec(tops()))
                    {
                        eqn[e++] = tops();
                        pop();
                    }
                    push(ch);
                }
            }
//            cout << top << endl;
        }

        if(top >= 0)
        {
            while(!(top < 0))
            {
                eqn[e++] = tops();
                pop();
            }
        }

        eqn[e-1] = '\0';
        if(c>1) printf("\n");
        c++;
        puts(eqn);



        memset(eqn,'\0',sizeof(eqn));
        memset(st,'\0',sizeof(st));
        top = 0;
        e=0,i=0;
    }

    return 0;
}


