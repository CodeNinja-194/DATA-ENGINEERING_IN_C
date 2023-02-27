#include<stdio.h>
#include<math.h>
int main()
{
float x[]={23,23,27,27,39,41,47,49,50,52,54,54,56,57,58,58,60,61};
float y[]={9.5,26.5,7.8,17.8,31.4,25.9,27.4,27.2,31.2,34.6,42.5,28.8,33.4,30.2,34.1,32.9,41.2,35.7};
float s1=0,s2=0;
float x_sq=0,y_sq=0,x_y=0;
int n=sizeof(x)/sizeof(x[0]);
for(int i=0;i<n;i++)
{
    s1=s1+x[i];
    s2=s2+y[i];
    x_sq=x_sq+x[i]*x[i];
    y_sq=y_sq+y[i]*y[i];
    x_y=x_y+x[i]*y[i];
}
float mean_x=s1/n;
   float mean_y=s2/n;
   float cov=(x_y/n)-(mean_x*mean_y);
    float sigma_x,sigma_y;
   sigma_x=sqrt((x_sq/n)-(mean_x*mean_x));
   sigma_y=sqrt((y_sq/n)-(mean_y*mean_y));
   printf("sigma x=%f",sigma_x);
   printf("\n");
   printf("sigma y=%f",sigma_y);
   printf("\n");
   printf("covariance of x and y =%f",cov);
   printf("\n");
   float r=cov/(sigma_x*sigma_y);
   printf("correlation coefficient=%f",r);
   
    
    
    
    
}

