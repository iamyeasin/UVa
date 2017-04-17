#include<bits/stdc++.h>

using namespace std;

int main()
{
    int counter,a,b,x;
    char arr[1000];
    while(gets(arr))
    {
        //  ,.\.)(][/@#!%^&*|{+'>`<?/\\\"_:;~}
        counter = 0;
        for(int i=0; arr[i] != '\0'; i++)
        {
            if(((arr[i] >= 'a' && arr[i] <= 'z') || // Here for all values except a-z, A-Z will be counted as a new word
               (arr[i] >= 'A' && arr[i] <= 'Z'))&& //So first I checked that if the current value is in A-Z,or in a-z,Then i
               (arr[i+1] < 'a' || arr[i+1] > 'z') &&// checked the if the next ASCII value character is not in the the english character list
               (arr[i+1] < 'A' || arr[i+1] > 'Z')) // So its a word. I counted ++;
            {
                counter++;
            }

        }
        printf("%d\n",counter);

    }

    return 0;
}
