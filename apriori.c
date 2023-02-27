#include<stdio.h>
int main()
{
        int t,n,i,j,k,p,f,count,q,r;
        printf("Enter number of id's: ");
        scanf("%d",&t);
        printf("Enter maximum number of items: ");
        scanf("%d",&n);
        printf("Enter number of items and list of items for every id\n");
        int a[t][n],g[t];
        for(i=0;i<t;i++)
        {
                scanf("%d",&g[i]);
                for(j=0;j<g[i];j++)
                        scanf("%d",&a[i][j]);
        }
        // int i,j,t=9,n=5,k,p,f,count,q,r;
        // int g[9]={3,2,2,3,2,2,2,4,3};
        // int a[9][5]={{1,2,5},{2,4},{2,3},{1,2,4},{1,3},{2,3},{1,3},{1,2,3,5},{1,2,3}};
       
       
        int c1[n+1];
        for(i=1;i<=n;i++)
                c1[i]=0;
        for(i=0;i<t;i++)
                for(j=0;j<g[i];j++)
                        c1[a[i][j]]=c1[a[i][j]]+1;
              printf("%d ",c1[i]);
               
        int ms;
        printf("Enter minimum support count: ");
        scanf("%d",&ms);
       
        int l1[n+1];
        printf("\nPrinting L1\n");
        for(i=1;i<=n;i++)
        {
        if(c1[i]>=ms)
        {
        l1[i]=c1[i];
        printf("(%d) - %d\n",i,l1[i]);
        }
        else
        l1[i]=-1;
        }
       
        int c2[n+1][n+1];
        for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
        c2[i][j]=-1;
       
        for(i=1;i<=n;i++)
        {
            if(l1[i]==-1)
            continue;
            for(j=i+1;j<=n;j++)
            {
                if(l1[j]==-1)
                continue;
                count=0;
                for(k=0;k<t;k++)
               {
                   f=0;
                for(p=0;p<g[k];p++)
                {
                   
                        if(a[k][p]==i)
                        f=f+1;
                        if(a[k][p]==j)
                        f=f+1;
                       
                       
                }
                if(f==2)
                count=count+1;
               }
               c2[i][j]=count;
            }
           
        }
       
        int l2[n+1][n+1];
        printf("\nPrinting L2\n");
        for(i=1;i<=n;i++)
        {
        for(j=i+1;j<=n;j++)
        {
        if(c2[i][j]>=ms)
        {
        l2[i][j]=c2[i][j];
        printf("(%d %d) - %d\n",i,j,l2[i][j]);
        }
        else
        l2[i][j]=-1;
        }
        }
       
        printf("\nPrinting L3\n");
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                for(k=j+1;k<=n;k++)
                {
                    if(l2[i][j]<ms || l2[i][k]<ms || l2[j][k]<ms)
                    continue;
                    count=0;
                    for(p=0;p<t;p++)
                    {
                        f=0;
                        for(q=0;q<g[p];q++)
                        {
                            if(a[p][q]==i)
                            f=f+1;
                            if(a[p][q]==j)
                            f=f+1;
                            if(a[p][q]==k)
                            f=f+1;
                        }
                        if(f==3)
                        count=count+1;
                    }
                    if(count>=ms)
                    printf("(%d, %d, %d) - %d\n",i,j,k,count);
                }
            }
        }

}

	



