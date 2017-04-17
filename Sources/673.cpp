#include<bits/stdc++.h>

using namespace std;

int main()
{

    int kase;
    cin>>kase;
    getchar();

    while(kase--)
    {
        stack< char > st;
        char chs[150];

        gets(chs);

        for(int i=0; i<strlen(chs); i++)
        {
            char ch = chs[i];

            if(ch == '{' || ch == '[' || ch == '(')
            {
                st.push(ch);

            }
            else if(ch == ')' && !st.empty())
            {
                char top = st.top();
                if(top == '(')
                {
                    st.pop();
                }
                //cout<<top<<endl;
            }
            else if(ch == '}' && !st.empty())
            {
                char top = st.top();
                if(top == '{')
                {
                    st.pop();
                }
                //cout<<top<<endl;
            }
            else if(ch == ']' && !st.empty())
            {
                char top = st.top();
                if(top == '[')
                {
                    st.pop();
                }
                //cout<<top<<endl;
            }
            else
            {
                st.push(ch);
                break;
            }

        }

        if(st.empty())
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
            while(!st.empty())
            {
                st.pop();
            }
        }

    }


    return 0;
}
