#ifndef FIBONACCI_H
#define FIBONACCI_H

/* fibo_xth, calculate the x-th fibonacci number

	%rdi - number

	Success: result of calculation
	Failure: can it fail?
*/
.extern fibo_xth


/* fibo_check, check if %rdi is a fibonacci number

	%rdi - number which should be checked

	Success: 1 if fibonacci, 0 otherwise
	Failure: can it fail?
*/
.extern fibo_check

#endif /* FIBONACCI_H */
