/*Techinques of SOJOL vai. I tried to solve. But Stuck uped.*/

#include<bits/stdc++.h>

using namespace std;

///reversing string
void rev(char *from, char *to) // General function which will reverse the string
{

    int len = strlen(from);
    int i;

    for(i=0; i<len; i++)
    {
        to[i]=from[len-i-1];
    }

    to[i] = '\0';

}


int main()
{

//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);

    char from[5000],to[5000],ch;

    while( scanf("%s%c", from, &ch) != EOF) /// WIll take a word and a character.
    {
        rev(from,to); // just putting that word in reverse order.
        printf("%s%c", to,ch); ///printing that character in ulta order.Then the space or something.
    }




    return 0;
}
