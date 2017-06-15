#include<stdio.h>
#define sf scanf
#define pf printf

long heights[60001];
long x,y;

void binSearch(long limit,long test)
{
    if(limit == 1 && (heights[limit-1] == test))
    {
        pf("X X\n");
    }
    else if(test > heights[limit-1])
    {
        pf("%ld X\n",heights[limit-1]);
    }
    else if(test == heights[limit-1])
    {
        pf("%ld X\n",heights[limit-2]);
    }
    else if(test == heights[0])
    {
        pf("X %ld\n",heights[1]);
    }
    else if(test < heights[0])
    {
        pf("X %ld\n",heights[0]);
    }
    else
    {
        int lo = 0;
        int hi = limit-1;

        while((lo < hi))
        {
            int mid = (lo+hi)/2;

            if(lo-hi == -1)
            {
                pf("%ld %ld\n",heights[lo],heights[hi]);
                break;
            }
            else if(heights[mid] == test)
            {
                pf("%ld %ld\n",heights[mid-1],heights[mid+1]);
                break;
            }
            else if(heights[mid] > test)
            {
                hi = mid;
            }
            else
            {
                lo = mid;
            }

        }

    }

}



int main()
{
    long hq;
    sf("%ld",&hq);
    int k=0;

    for(int i=0; i<hq; i++)
    {
        long x;
        sf("%ld",&x);

        if(x != heights[k-1])
        {
            heights[k++] = x;
        }
    }


    long th;
    sf("%ld",&th);

    for(int i=1; i<=th; i++)
    {
        long tt;
        sf("%ld",&tt);
        binSearch(k,tt);
    }



    return 0;
}
