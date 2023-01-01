
#include <stdio.h>
#include <stdlib.h>
#include <math.h>




int L=100;
int T=400;
int I0=10;
int k0=50;
double dx,dt,v,c,a,Ir;
double pi=3.1415926;
int main()
{FILE *fpWrite=fopen("data.txt","w");
    if(fpWrite==NULL)
    {
        return 0;
    }
    dt=0.01;
    a=0.1;
    v=0.2;
    c=v*v*dt*dt*L*L;
    Ir=I0*dt/(a*sqrt(pi));
    double mid_value1,mid_value2,mid_value;
    for(int i=0;i<=L;i++)
    {
        u[1][i]=Ir*exp(-100*(i-k0)*(i-k0));
        mid_value2=u[1][i];
        printf("u[1][%d]= %lf\n",j,k,mid_value2);fprintf(fpWrite,"%f ",mid_value2);
    }
    for(int j=2;j<=T;j++)
    {
        for(int k=1;k<=L;k++)
        {
            u[j][k]=c*(u[j-1][k+1]+u[j-1][k-1])+2*(1-c)*u[j-1][k]-u[j-2][k];
            mid_value=u[j][k];
            printf("u[%d][%d]= %lf\n",j,k,mid_value);fprintf(fpWrite,"%f ",mid_value);
        }
    }


    for(int i=0;i<40100;i++);

    fclose(fpWrite);
    return 0;
}



