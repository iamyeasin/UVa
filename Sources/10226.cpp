/*
    You must clear the vector and map after processing a test case
    be carefull about the input output file.

*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("C:\\Users\\Yeasin\\Desktop\\input.txt","rt",stdin);
    //freopen("C:\\Users\\Yeasin\\Desktop\\output.txt","wt",stdout);

    int kase,total; // total is for how many trees in total
    char line[80]; // for taking input the name
    map <string, int> st; // Declaring the map for main logic
    vector < string > s; // for storing the tree names declared a vector
    cin>>kase; // how many cases
    getchar(); // to avoid garbage data

    for(int ii=0; ii<=kase; ii++)
    {
        total = 0;
        while(gets(line)) // taking input first tree
        {

            if(strlen(line) == 0)// if it's a new line then the length of the string would be 0
            {
                break; // then move to the next test case
            }

            if(st[line])// if there is any index match the increase the value by 1
            {
                st[line]++;// increasing the indexed value;
            }
            else
            {
                st[line]++; // if does n't match then create a new index and ++ the value
                s.push_back(line); // send the word to vector.
            }

            total++; // total number of trees
        }

        sort(s.begin(), s.end());// Sorting the vector in the alphabetic order

        for(int i=0; i<s.size(); i++) // it loops through the end of the vector
        {
            string ss = s[i]; // storing the element of the vector
            cout<<ss<<" ";
            cout<<fixed<<setprecision(4)<<((st[ss]*1.00/(total*1.00))*100.00)<<endl; // growth rate law.. but must convert it to double
        }

       if(ii<kase && ii >0) // clear the vector and map after every test case. Else it will change the value
       {
           cout<<"\n";
           st.clear();
           s.clear();
       }
    }


    return 0;
}
