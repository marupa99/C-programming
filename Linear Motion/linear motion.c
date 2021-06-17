#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void uniform(int n);
void non_uniform(int n);
void non_uniform_2(int n);
void non_uniform_3(int n);
int main()
{
    int n;
    printf("\t:Linear Motion Master:");
    printf("Enter Number From 1-15 To Do The Corresponding Operations\n\n");

    printf("[A] S=V*T Uniform Linear Motion\n\n");

    printf("[1] To get Displacement From Velocity & Time\n");
    printf("[2] To get Velocity From Displacement & Time\n");
    printf("[3] To get Time From Displacement & Velocity\n\n");

    printf("[B] S= UT+1/2AT^2 Non-Uniform Linear Motion\n\n");


    printf("[4] To get Initial Velocity From Acceleration,Displacement & Time\n");
    printf("[5] To get Acceleration From Initial Velocity,Displacement & Time\n");
    printf("[6] To get Displacement From Initial Velocity,Acceleration & Time\n");
    printf("[7] To get Time From Initial Velocity,Acceleration & Displacement\n\n");

    printf("[C] V=U+AT Non-Uniform With Initial Velocity\n\n");

    printf("[8] To get Initial Velocity From Acceleration,Final Velocity & Time\n");
    printf("[9] To get Acceleration From Initial Velocity,Final Velocity & Time\n");
    printf("[10] To get Final Velocity From Initial Velocity,Acceleration & Time\n");
    printf("[11] To get Time From Initial Velocity,Acceleration & Final Velocity\n\n");

    printf("[D] V^2=U^2+2AS Non-Uniform With Initial Velocity Along With Displacement\n\n");

    printf("[12] To get Initial Velocity From Acceleration,Final Velocity & Displacement\n");
    printf("[13] To get Acceleration From Initial Velocity,Final Velocity & Displacement\n");
    printf("[14] To get Final Velocity From Initial Velocity,Acceleration & Displacement\n");
    printf("[15] To get Displacement From Initial Velocity,Acceleration & Final Velocity\n\n");

    printf("Enter A Number Please:\n");
    printf("**Note:Don't Enter Negative Value for Time(t)**\n");


    while(scanf("%d",&n)!=0)
    {
    if(n>=1&&n<=3)
    {
        uniform(n);
    }
    else if(n>=4&&n<=7)
    {
        non_uniform(n);
    }
    else if(n>=8&&n<=11)
    {
        non_uniform_2(n);
    }
    else if(n>=12&&n<=15)
    {
        non_uniform_3(n);
    }
    else
    {
        printf("Please Enter A Number Between 1-15 To Perform Operations\n");
    }
    }

    return 0;
}
void uniform(int n)
{

    double t,s,v;
    if(n==1)
    {
        printf("Enter Velocity And Time Respectively\n");
        scanf("%lf%lf",&v,&t);
        printf("Displacement :%.4lfm\n",s=v*t);
    }
    if(n==2)
    {
        printf("Enter Time And Displacement Respectively\n");
        scanf("%lf%lf",&t,&s);
        printf("Velocity :%.4lfm/s\n",v=(s/t));
    }
    if(n==3)
    {
        printf("Enter Velocity And Displacement Respectively\n");
        scanf("%lf%lf",&v,&s);
        printf("Time :%.4lfsec\n",t=(s/v));
    }
}
void non_uniform(int n)
{
    double t,s,a,u;
    if(n==4)
    {
        printf("Enter Displacement,Time And Acceleration Respectively\n");
        scanf("%lf%lf%lf",&s,&t,&a);
        printf("Initial Velocity:%.4lfm/s\n",u=(s-(0.5*a*t*t))/t);

    }
    if(n==5)
    {
        printf("Enter Initial Velocity,Displacement And Time Respectively\n");
        scanf("%lf%lf%lf",&u,&s,&t);
        printf("Acceleration:%.4lfm/s^2\n",a=2*(s-(a*t)/(t*t)));

    }
    if(n==6)
    {
        printf("Enter Initial Velocity,Acceleration And Time Respectively\n");
        scanf("%lf%lf%lf",&u,&a,&t);
        printf("Displacement:%.4lfm\n",s=(u*t)+(0.5*a*t*t));
    }
    if(n==7)
    {
        printf("Enter Initial Velocity,Acceleration And Displacement Respectively\n");
        scanf("%lf%lf%lf",&u,&a,&s);
        t=(2*s/a)-((u/a)*(u/a))-(u/a);
        if(t>0){
        printf("Time:%.4lfsec\n",t=(sqrt((2*s/a)-((u/a)*(u/a)))-(u/a)));}
        else{
            printf("Input is not vlaid");
        }
    }

}
void non_uniform_2(int n)
{
    double t,u,v,a;
    if(n==8)
    {
        printf("Enter Final Velocity,Acceleration And Time Respectively\n");
        scanf("%lf%lf%lf",&v,&a,&t);
        printf("Intial Velocity:%.4lfm/s\n",u=(v-(a*t)));
    }
    if(n==9)
    {
        printf("Enter Final Velocity,Intial Velocity And Time Respectively\n");
        scanf("%lf%lf%lf",&v,&u,&t);
        printf("Acceleration:%.4lfm/s^2\n",a=((v-u)/t));
    }
    if(n==10)
    {
        printf("Enter Initial Velocity,Acceleration And Time Respectively\n");
        scanf("%lf%lf%lf",&u,&a,&t);
        printf("Final Velocity:%.4lfm/s\n",v=(u+(a*t)));
    }
    if(n==11)
    {
        printf("Enter Final Velocity,Acceleration And Initial Velocity Respectively\n");
        scanf("%lf%lf%lf",&v,&a,&u);
        printf("Time:%.4lfsec\n",t=((v-u)/a));
    }
}
void non_uniform_3(int n)
{
    double u,v,a,s;
    if(n==12)
    {
        printf("Enter Final Velocity,Acceleration And Displacement Respectively\n");
        scanf("%lf%lf%lf",&v,&a,&s);
        u=((v*v)-(2*a*s));
        if(u>0)
        {

            printf("Initial Velocity:%.4lfm/");
        }
    }
}
