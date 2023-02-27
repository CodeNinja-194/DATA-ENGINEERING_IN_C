#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void minmax(float a[],int);
void sort(float[],char[],int);
int main()
{
    int n=18;
    float height[19]={158,158,158,160,160,163,163,160,163,165,165,165,168,168,168,170,170,170};
    float weight[19]={58,59,63,59,60,60,61,64,64,61,62,65,62,63,66,63,64,68};
    char tshirt[19]={'M','M','M','M','M','M','M','L','L','L','L','L','L','L','L','L','L','L'};
    
    //Data to classify given
    height[n]=161,weight[n]=61;
    
    //Min-Max Standardization of Data i.e, Normalization
    minmax(height,n);
    minmax(weight,n);
    
    //Euclidean Distance
    float dist[18];
    for(int i=0;i<n;i++)
    dist[i]=sqrt(pow(height[i]-height[n],2)+pow(weight[i]-weight[n],2));

    //sort the data according to Distance
    sort(dist,tshirt,n);
    
    int k;
    printf("Enter the K for Classification");
    scanf("%d",&k);
    
    if(k<1||k>n)
        return 0;
    int c1=0,c2=0;
    for(int i=0;i<k;i++)
    {
        if(tshirt[i]=='M')
        c1=c1+1;
        else
        c2=c2+1;
    }
    if(c1>c2)
    printf("T-shirt size is M\n");
    else if(c1<c2)
    printf("T-shirt size is L\n");
    
}
void minmax(float a[],int n)
{
    float min=10000,max=-1;
    for(int i=0;i<=n;i++)
    {
        if(min>a[i])
        min=a[i];
        if(max<a[i])
        max=a[i];
    }
    for(int i=0;i<=n;i++)
    {
        a[i]=(a[i]-min)/(max-min);
    }
}
void sort(float a[],char b[],int n)
{
    int i,j;
    float t1;
    char t2;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                t1=a[j],a[j]=a[j+1],a[j+1]=t1;
                t2=b[j],b[j]=b[j+1],b[j+1]=t2;
            }
        }
    }
}

