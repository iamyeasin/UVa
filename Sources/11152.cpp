#include<bits/stdc++.h>
#define pi 3.14159265359

using namespace std;

int main()
{
    int a,b,c,l1,l2,l3;
    int arr[3];
    double aa,bb,cc;

    while(scanf("%d %d %d",&a,&b,&c) != EOF)
    {
        int p = (a+b+c); //Perimeter of a triangle
        double s = p*0.5;  //
        double A = sqrt(s*(s-a)*(s-b)*(s-c)); //Hiron's Formula

        double InRad = A/s; // Inner radius of circle inside a triangle. Formula found from CP1-halim
        double InCir = InRad*InRad*1.00*pi; // Area of sunflower
        double OutRad = (a*b*c)/(4*A); //Rad of triangle
        double OutCir = pi*(OutRad*OutRad); // Radius of outer triangle

        printf("%0.4lf %0.4lf %0.4lf\n",OutCir-A,A-InCir,InCir);

    }

    return 0;
}
