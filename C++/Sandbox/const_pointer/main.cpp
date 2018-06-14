
int main ()
{
	int var = 9, x = var;
	const int* var_ptr1 = &var; /* Pointer to constant variable */
	int const* var_ptr2 = &var; /* Pointer to constant variable */
	int *const var_ptr3 = &var; /* Constant Pointer to variable */
	var_ptr1 = &x;
	var_ptr2 = var_ptr1;
	*var_ptr3 = *var_ptr2;
}
