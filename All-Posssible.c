4#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int power,i=0,j=1,iteration;
int coeff[10]={0};
double a,b,x,x0,x1,x2,f1,f2,f0,e,root;

double f(double x){
    double val = 0;
    int i;
    for(i=power;i>=0;i--){
        val=val+pow(x,i)*coeff[i];
    }
    return val;
}
void main()
{
    printf("Enter the highest power:\n");
    scanf("%d",&power);

    printf("Enter the highest power:\n");
    for(i=0;i<=power;i++)
    {
        printf("\nx^%d:",i);
        scanf("%d",&coeff[i]);
    }
    printf("\nThe polynomial is: ");
    for(i=power;i>=0;i--)
    {
        printf(" %dx^%d",coeff[i],i);
    }
    printf(" = 0\n");

    printf("\nEnter the bracket:\n");
    scanf("%lf %lf",&a,&b);

    printf("\nEnter the interval:\n");
    scanf("%lf",&x);

    x1=a;
    x2=x1+x;

    while(x2<b){
        f1=f(x1);
        f2=f(x2);

        if(f1*f2<0){
            e=x2-x1;
            x0=(x1+x2)/2;
            f0=f(x0);
            while(e>0.001&&f0!=0)
            {
                if(f0*f1<0)
                    x2=x0;
                else
                    x1=x0;
                e=x2-x1;
                x0=(x1+x2)/2;
                f0=f(x0);
            }
            root=(x1+x2)/2;
            printf("\nRoot #%d : %lf after %d iterations",j,root,iteration);
            j++;
        }
        a=x2;
        x1=a;
        x2=x1+x;
        iteration++;

    }
    printf("\n");
}


