
#include <stdio.h>
#include <math.h>


bool isprime(int n)
{
    int pkp = sqrt(n);
    int j;
    
    for( j = 2 ; j<=pkp ; j++)
    {
    if(n%j==0)
    return true;
    }
    return false;

}

int main()
{
    int n;

    // int arr[4];
    int k =-1;

    int arr[]={7, 32342, 34242, 23423};


    for(int hh =0 ; hh <5 ;hh++)
    {
    // cout<<"enter the no. \n";
    n = arr[hh];
    if(!isprime(n))
        printf("Yes Prime\n");
    else
        printf("No Not Prime\n");
    }
    return 0;
}
