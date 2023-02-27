#include<stdio.h>
#include<math.h>
int main()
{
    float p[8][2]={{2,10},{2,5},{8,4},{5,8},{7,5},{6,4},{1,2},{4,9}};
    int cluster[8]={-1,-1,-1,-1,-1,-1,-1,-1};
    
    //k-->3
    float clusterMean[3][2]={{2,10},{5,8},{1,2}};
    int f=-1,t,i,j,q;
    float m[3],min;
    while(f!=0)
    {
        t=f,f=0;
        for(int i=0;i<8;i++)
        {
            min=10000;
            for(int j=0;j<3;j++)
            {
               m[j]=sqrt(pow(p[i][0]-clusterMean[j][0],2)+pow(p[i][1]-clusterMean[j][1],2));
                if(min>m[j])
                {
                    min=m[j];
                    q=j;
                }
            }
            if(cluster[i]!=q)
            {
                cluster[i]=q;
                f=1;
            }
        }

        float count[3]={0,0,0},sumx[3]={0,0,0},sumy[3]={0,0,0};
        for(i=0;i<8;i++)
        {
            j=cluster[i];
            count[j]=count[j]+1;
            sumx[j]=sumx[j]+p[i][0];
            sumy[j]=sumy[j]+p[i][1];
        }
        for(j=0;j<3;j++)
        {
            clusterMean[j][0]=sumx[j]/count[j];
            clusterMean[j][1]=sumy[j]/count[j];
        }

        if(t==-1)//After first round of execution
        {
            printf("\nThe three cluster centers after first round of execution:\n");
            for(j=0;j<3;j++)
            printf("(%.2f, %.2f)\n",clusterMean[j][0],clusterMean[j][1]);
        }
    }


    printf("\nThe final three clusters are:\n");
    for(j=0;j<3;j++)
    printf("(%.2f, %.2f)\n",clusterMean[j][0],clusterMean[j][1]);

    printf("\nAssign of Clusters to Points:\n");
    for(i=0;i<8;i++)
    printf("(%.1f, %.1f)--%d   ",p[i][0],p[i][1],cluster[i]+1);

}