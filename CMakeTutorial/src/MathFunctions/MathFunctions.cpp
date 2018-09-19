#include <float.h>
#include "MathFunctions.h"

double mysqrt(double A)  
{   /**二分法实现开方
	 需要注意的是：
	 1.初始上界是A+0.25，而不是A
	 2.double型的精度DBL_EPSILON，不能随意指定
	*/
 
	double a = 0.0, b = A + 0.25, m;  // b = A 是错误的上届
	// while(b - a > 2*DBL_EPSILON){  //sometimes dead cycle when m == a or m == b.
	for (;;)
	{
		m = (b + a) / 2;
		if (m - a < DBL_EPSILON || b - m < DBL_EPSILON) break;
		if ((m*m - A) * (a*a - A) < 0) b = m;
		else a = m;
	}
	return m;
}
