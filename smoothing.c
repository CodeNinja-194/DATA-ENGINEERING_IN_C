#include<stdio.h>
#include<math.h>
int main()
{
    int n,s;
    float c=0;
    printf("Enter size of array");
    scanf("%d",&n);
    if(n%3!=0)
    {
        n=n+(3-n%3);
    }
    printf("Enter smoothing value");
    scanf("%d",&s);
    int a[]={13,15,16,16,19,20,20,21,22,22,25,25,25,25,30,33,33,35,35,35,35,36,40,45,46,52,70};;
     for(int i=0;i<n;i++)
     {
         c=c+a[i];
         if((i+1)%s==0)
         {
             for(int j=0;j<s;j++)
             {
                a[i-j]=c/s;
             }
             c=0;
         }
     }
     for(int k=0;k<n;k++)
     {
         printf("%d\t",a[k]);
     }
}
