#include <stdio.h>
#include <math.h>
#define pi acos(-1.0)  
#define eps 1e-4

typedef struct Point
{
	double x,y;
}Point;

double dist(Point p1, Point p2){
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
double Angle(double a,double b,double c){
	return acos((a*a+b*b-c*c)/(2*b*a));
}
double gcd(double a,double b){
	if(b+eps>0&&b-eps<0) return a;
	if(a+eps>0&&a-eps<0) return b;
	return gcd(b,fmod(a,b));
}

int main()
{
	/* code */

	Point p1,p2,p3;

	while(~scanf("%lf%lf%lf%lf%lf%lf",&p1.x,&p1.y,&p2.x,&p2.y,&p3.x,&p3.y)){

			double a,b,c,p,s,r;
			double angle1,angle2,angle3,angle;
			a=dist(p1,p2);
			b=dist(p1,p3);
			c=dist(p2,p3);
			//半周长
			p=(a+b+c)/2;
			//三角形面积
			s=sqrt(p*(p-a)*(p-b)*(p-c));
			//外接圆半径
			r=a*b*c/(4*s);
			angle1=Angle(r,r,a);
			angle2=Angle(r,r,b);
			angle3=2*pi - angle1 - angle2;
			angle=gcd(angle1,gcd(angle2,angle3));
			double ans;
			ans=0.5*r*r*sin(angle)*(2*pi/angle);
			printf("%.6lf\n",ans);
	}
	return 0;
}




