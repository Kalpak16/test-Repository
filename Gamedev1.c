#include<stdio.h>
#include<math.h>
int main(){
    int x,y,r,a;
    scanf("%d%d%d",&x,&y,&r);
    a=sqrt(x*x+y*y);  //square root of x^2+y^2//
    if(a<=r){printf("True");} //True if the point is inside or on the boundary of the circle//
    else if(a>r){printf("False");}//False if the point is outside the circle//
    return 0;
}