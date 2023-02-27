#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float absoluteError(float**,int[],int[]);
int main()
{
    int i,j,k;
    float q[8][2]={{2,10},{2,5},{8,4},{5,8},{7,5},{6,4},{1,2},{4,9}};
    float **p=(float**)malloc(8*sizeof(float*));
    for(int i=0;i<8;i++)
    {
        p[i]=(float*)malloc(2*sizeof(float));
        p[i]=q[i];
    }
    //k=2
    float mediod[2][2],e=10000,t;
    int c[2];

    int cluster[8],temp[8];

    for(i=0;i<8;i++)
    for(j=i+1;j<8;j++)
    {
        c[0]=i,c[1]=j;
        t=absoluteError(p,c,temp);
        if(t<e)
        {
            for(k=0;k<8;k++)
            cluster[k]=temp[k];
            e=t;
            for(k=0;k<2;k++)
            mediod[k][0]=p[c[k]][0],mediod[k][1]=p[c[k]][1];
        }
    }

    printf("\nFinal Mediod points are :\n");
    for(k=0;k<2;k++)
    printf("Mediod of Cluster %d - (%.0f, %.0f)\n",k+1,mediod[k][0],mediod[k][1]);

    printf("\nMinimum Absolute Error (Euclidean distance used) = %.2f\n",e);

    printf("\nAssign of Clusters to Points:\n");
    for(i=0;i<8;i++)
    printf("(%.0f, %.0f)--%d ",p[i][0],p[i][1],cluster[i]+1);
}

float absoluteError(float **p,int c[],int temp[])
{
    int i,j,q;
    float min,k,e=0;
    for(i=0;i<8;i++)
    {
        min=10000;
        for(j=0;j<2;j++)
        {
            k=sqrt(pow(p[i][0]-p[c[j]][0],2)+pow(p[i][1]-p[c[j]][1],2));
            if(min>k)
            {
                min=k;
                q=j;
            }
        }
        temp[i]=q;
        e=e+min;
    }
    return e;
}
