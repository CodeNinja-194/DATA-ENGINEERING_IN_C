#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    printf("Enter n value");
    scanf("%d",&n);
    float a[n];
    printf("enter array elements");
    for(int i=0;i<n;i++)
    {
        scanf("%f",&a[i]);
    }
    printf("\n");
    printf("Min_Max Normalization");
    printf("\n-----------------------\n");
    int b1,b2;
    float max,min,s=0;
    printf("min-max normalization\n");
    printf("enter first boundary value 1:");
    scanf("%d",&b1);
    printf("enter second boundary value 2:");
    scanf("%d",&b2);
    for(int i=0;i<n;i++)
    {
        s=s+a[i];
    }
    max=a[0];
    min=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
        if(a[i]<min)
        {
            min=a[i];
        }
    }
    float b[n];
    for(int i=0;i<n;i++)
    {
        b[i]=((a[i]-min)/(max-min))*(b2-b1)+b1;
    }
    printf("original data\tnormalized data\n");
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("%f\t",a[i]);
        printf("%f\n",b[i]);
    }
        printf("\n");
    printf("Z-Score Normalization");
    printf("\n-----------------------\n");
    float s1;
    printf("z-score normalization\n");
    for(int i=0;i<n;i++)
    {
        s1=s1+a[i];
    }
    float mean=s1/n;
    float sd=0;
    for(int i=0;i<n;i++)
    {
        sd=sd+(a[i]-mean)*(a[i]-mean);
    }
    sd=sqrt(sd/n);
    float z[n];
    for(int i=0;i<n;i++)
    {
        z[i]=(a[i]-mean)/sd;
    }
     printf("original data\t\tnormalized data\n");
    printf("\n");
    printf("standard deviation=%f\n",sd);
    printf("mean=%f\n",mean);
    for(int i=0;i<n;i++)
    {
        printf("%f\t",a[i]);
        printf("%f\n",z[i]);
    }
    int func(int n)  
    {  
    int counter=0;
    while(n!=0)  
    {  
        n=n/10;  
        counter++;  
    }  
    return counter;  
    }  
    printf("decimal scaling normlization\n");
    int max1=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]>max1)
        {
            max1=a[i];
        }
    }
    int length=func(max1);
    float d[n];
    for(int i=0;i<n;i++)
    {
        d[i]=a[i]/length;
    }
    printf("original data\tnormalized data\n");
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("%f\t",a[i]);
        printf("%f\n",d[i]);
    }
}

