/*
 *=======================================================================
 *			Verify FMINBR routine
 */

#include <float.h>
#include <math.h>
#include <stdio.h>

double fminbr(double a, double b, double (*f)(double), double tol);

static int counter;			/* Iteration counter	*/

test(a,b,f,msg)			/* Run a test			*/
double a,b;				/* Range the root is seeked for */
double (*f)(double x);			/* Functiom under examination	*/
char * msg;				/* Explanation message		*/
{
  double minloc;
  counter = 0;
  printf("\nFor function %s\nin [%g,%g] min found is at\t%.9e\n",msg,a,b,
	 (minloc=fminbr(a,b,f,DBL_EPSILON)) );
  printf("Min function value found\t%.4e\nNo. of iterations\t\t%d\n",
	 (*f)(minloc), counter);
}

double f1(double x)				/* Test of the Forsythe book	*/
{
  counter++;
  return (pow(x,2)-2.0)*x - 5.0;
}

double f2(double x)				/* Modified test 1            	*/
{
  counter++;
  return pow( (pow(x,2)-2.0)*x - 5.0, 2 );
}

double f3(double x)				/* My test                  	*/
{
  counter++;
  return pow( cos(x) - x,2 ) - 2;
}

double f4(double x)				/* My test                  	*/
{
  counter++;
  return pow( sin(x) - x,2 ) + 1;
}


int main(void)
{
  test(0.0,1.0,f1,"x^3 - 2*x - 5");
  printf("Exact min is at\t\t0.81650\n");

  test(2.0,3.0,f2,"(x^3 - 2*x - 5)^2");
  printf("Exact root is \t\t2.0945514815\n");

  test(2.0,3.0,f3,"(cos(x)-x)^2 - 2");
  test(-1.0,3.0,f3,"(cos(x)-x)^2 - 2");
  test(-1.0,3.0,f4,"(sin(x)-x)^2 + 1");
}
