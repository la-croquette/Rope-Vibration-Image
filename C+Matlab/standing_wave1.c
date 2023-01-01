#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int L = 100;
int T = 100;
double dx, dt, v, c;
double pi = 3.1415926;
int main()
{
    FILE *fpWrite = fopen("data_102_102.txt", "w");
    if (fpWrite == NULL)
    {
        return 0;
    }
    dt = 0.01;

    v = 0.8;
    c = v * v * dt * dt * L * L;
    double u[102][102] = {0};
    double mid_value1;
    for (int i = 0; i <= L - 1; i++)
    {
        u[0][i] = sin(pi * i / L);
        u[1][i] = sin(pi * i / L);
    }
    for (int j = 2; j <= T; j++)
    {
        for (int k = 1; k <= L - 1; k++)
        {
            u[j][k] = c * (u[j - 1][k + 1] + u[j - 1][k - 1]) + 2 * (1 - c) * u[j - 1][k] - u[j - 2][k];
            mid_value1 = u[j][k];

            // fprintf(fpWrite,"%f ",mid_value1);
            // printf("u[%d][%d]= %lf\n",j,k,mid_value1);
        }
    }

    for (int j = 0; j <= T; j++)
    {
        for (int k = 0; k <= L; k++)   
        {

            mid_value1 = u[j][k];
            fprintf(fpWrite, "%lf ", mid_value1);
            // fprintf(fpWrite,"%f ",mid_value1);
            // printf("u[%d][%d]= %lf\n",j,k,mid_value1);
        }
    }

    for (int i = 0; i < 10201; i++)
        ;

    fclose(fpWrite);
    return 0;
}
