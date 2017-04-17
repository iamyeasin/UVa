/*
    MAP is one of the coolest system in cpp
    This is really useful for indexing the string type.
    see the problem description.

    In this problem there is nothing to fuck with my rest of the line except first word(country name)
    so I just took the word separately input and took separately rest of the line input.Then just incremented the
    word index by 1.Read fahims web. MAP IS AWESOME
*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
    map <string, int> si; // Declaring map string and int type
    string words,line; // Declaring two string , One is for saving the country and one
                        // is for taking input for the rest of the line input
    vector < string > vs; // for storing the country names
    int kase; // Test kase
    scanf("%d",&kase);
    getchar(); // For avoiding garbage value,space and new line;

    while(kase--)
    {
        cin>>words;// first this will take input the first word. works like %s.
        getchar();// next space
        getline(cin,line);// then it'will take input the rest of the line

        if(si[words]) // If the index was declared before the just increase the value by 1
        {
            si[words]++; // increasing the int value
        }
        else // if there is a new country
        {
            si[words]++; //then increment those value by 1;
            vs.push_back(words); // then push that word into the vector.
        }
    }

    sort(vs.begin(), vs.end()); // Sorting the values of vector in increasing order.

    for(int i=0; i<vs.size(); i++) // running a loop for printing the desired result
    {
        string s = vs[i]; // storing first country .. As a SMAPLE INPUT it is ENGLAND
       // puts("");
        cout<<s<<" "<<si[s]<<"\n"; // after that printout the country and a space the the value for string index integer value
    }


    return 0;
}
