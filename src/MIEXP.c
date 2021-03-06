/*======================================================================
                      B <- MIEXP(M,A,N)

Modular integer exponentiation.  

Inputs
   M : an integer,M >= 2.  
   A : an element of Z_M.  
   N : a non-negative integer.  

Output
   B : A^N in Z_M.
======================================================================*/
#include "saclib.h"

Word MIEXP(M,A,N)
       Word M,A,N;
{
        Word B,Np;
	BDigit t;

Step1: /* Single precision. */
        if (M < BETA && N < BETA) {
           B = MDEXP(M,A,N);
           goto Return; }

Step2: /* N <= 1. */
        if (N == 0) {
           B = 1;
           goto Return; }
        if (N == 1) {
           B = A;
           goto Return; }

Step3: /* A=0. */
        if (A == 0) {
           B = 0;
           goto Return; }

Step4: /* Recursion. */
        IDQR(N,2,&Np,&t);
        B = MIEXP(M,A,Np);
        B = MIPROD(M,B,B);
        if (t == 1)
           B = MIPROD(M,B,A);

Return: /* Return B. */
        return(B);
}
