/*======================================================================
                      B <- SIPDER(A)

Software interval polynomial derivative.

Input
   A : a software interval polynomial.

Output
   B : the derivative of A.
======================================================================*/
#include "saclib.h"

BDigit *SIPDER(A)
	BDigit *A;
{
	BDigit *B,*I;
	BDigit i,m,n,p,q1,q2,t;

Step1: /* Get an array for B. */
	n = A[0];
	m = MAX(n,1);
	p = A[3];
	q1 = p + 3;
	q2 = q1 + q1;
	t = m * q2;
        B = GETARRAY(t + 1);

Step2: /* Compute B. */
	if (n == 0) {
	   B[0] = 0;
	   ISI(0,p,B + 1);
	   goto Return; }
	B[0] = n - 1;
	I = GETARRAY(q2);
	t = 1;
	for (i = 1; i <= n; i++) {
	   ISI(i,p,I);
	   SIPROD(A + t + q2,I,B + t);
	   t = t + q2; }
	FREEARRAY(I);

Return: /* Return B. */
	return(B);
}
