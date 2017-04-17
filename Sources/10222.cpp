/*
The C library function int isspace(int c) checks whether the passed character
is white-space.

Standard white-space characters are −

' '     (0x20)	space (SPC)
'\t'	(0x09)	horizontal tab (TAB)
'\n'	(0x0a)	newline (LF)
'\v'	(0x0b)	vertical tab (VT)
'\f'	(0x0c)	feed (FF)
'\r'	(0x0d)	carriage return (CR)

 Header file <ctype.h>
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
   // char chr[] = {"`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./"};
    char chr[] = {"`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./"};
    char ch;

    while(scanf("%c",&ch) != EOF)
    {

        if (ch == 32 || ch == '\n' || ch == '\t' || ch == '\v') printf("%c",ch);
        else
        {
            ch = tolower(ch);
            for(int i=0; chr[i]; i++)
            {
                if(chr[i] == ch)
                {
                    printf("%c",chr[i-2]);
                    break;
                }
            }
        }

    }

    return 0;
}
