/**STL shows RE verdict. Custom data structure represented rank 203*/


#include<stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<deque>

#define sf scanf
#define pf printf

using namespace std;

int st[1050];
int q[1050];
int pq[1050];

int top=0,frnt=0,rare=0,pqfrnt=0,pqrare=0;

void pushpq(int x) ///for Priority queue
{
    pq[pqrare++] = x;
    sort(pq,pq+pqrare);
}

void poppq()
{
    pqrare = pqrare-1;
}

int frntpq()
{
    return pq[pqrare-1];
}


void pushq(int x) /// For queue
{
    q[rare++] = x;
}

void popq()
{
    frnt++;
    q[frnt-1] = -1;
}

int frntq()
{
    return q[frnt];
}

void pushs(int x)///for stack
{
    st[top++] = x;
}

int tops()
{
    return st[top-1];
}

void pops()
{
    top--;
}


int main()
{
//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);

    int s[42];
    int n[1050];
    int kase;
    int ss,qq,ppqq,nxt,flag,mm,ff,kk;

    while(sf("%d",&kase) != EOF)
    {

        ss = qq = ppqq = 1;
        nxt = flag = mm = ff = kk = 0;

        memset(s,0,sizeof(s));

        for(int j=0; j<kase; j++)
        {
            int x,y;

            sf("%d %d",&x,&y);

            if(x&1)
            {
                pushs(y);
                pushq(y);
                pushpq(y);
            }
            else
            {
                if((tops() != y) && !ff)
                {
                    s[0] = 1;
                    ff = 1;
                }

                if((frntq() != y) && !mm)
                {
                    s[1] = 1;
                    mm = 1;
                }

                if((frntpq() != y) && !kk)
                {
                    s[2] = 1;
                    kk=1;
                }

                    pops();
                    popq();
                    poppq();

            }
        }

        if(!s[0] && (s[1] && s[2]))
        {
            pf("stack\n");
        }
        else if(!s[1] && (s[0] && s[2]))
        {
            pf("queue\n");
        }
        else if(!s[2] && (s[0] && s[1]))
        {
            pf("priority queue\n");
        }
        else if((!s[0] && !s[1]) || (!s[1] && !s[2]) || (!s[0] && !s[2]))
        {
            pf("not sure\n");
        }
        else if(s[0] && s[1] && s[2])
        {
            pf("impossible\n");
        }

            memset(st,0,sizeof(st));
            memset(q,0,sizeof(q));
            memset(pq,0,sizeof(pq));
            top=0,frnt=0,rare=0,pqfrnt=0,pqrare=0;

    }


    return 0;
}
