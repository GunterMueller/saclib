/*======================================================================
                        SIPESLBR(A,a; t,s)

Software interval polynomial evaluation of sign at a binary rational.

Inputs
   A : a software interval polynomial.
   a : a logarithmic binary rational number.  a must be exactly
       convertiple to a precision p software floating-point
       number, where p is the precision of A.

Outputs
   t : 0 or 2.
   s : the sign of A(a), if this can be determined with floating
       point arithmetic of precision p, where p is the precision
       of A; in this case t = 0.  Otherwise t = 2 and s is undefined.
======================================================================*/
#include "saclib.h"

void SIPESLBR(A,a, t_,s_)
	BDigit *A;
	Word a;
	BDigit *t_;
	Word *s_;
{
	Word *b,s;
	BDigit p,t;

Step1: /* Convert a to floating point and apply SIPES. */
	p = A[3];
	b = GETARRAY(p + 3);
	LBRNF(a,p,0,b);
	s = SIPES(A,b);
	FREEARRAY(b);
	if (s == NIL)
	   t = 2;
	else
	   t = 0;

Return: /* Return t and s. */
	*t_ = t;
	*s_ = s;
}
