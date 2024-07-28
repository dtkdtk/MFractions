#define MF__CFG__FORCE_PREFIX

#include "../include/fractions.h"
#include <stdio.h>


static void print_fraction(mf__fraction_i32_t fract)
{
	enum fraction_look_types_e look_type = mf__get_look_of_fraction__i32(fract);
	const char* string_fract = mf__stringify_fraction__i32(fract);
	printf("\t[%s] %s\n",
		look_type == mf__proper_fraction ? "proper"
		: look_type == mf__improper_fraction ? "improper"
		: look_type == mf__integer_fraction ? "integer"
		: look_type == mf__mixed_fraction ? "mixed"
		: "?",
		string_fract
	);
	free(string_fract);
}

int main(int argc, char* argv[])
{
	mf__fraction_i32_t* fract = mf__alloc_fraction__i32();
	fract->numerator = 40;
	fract->denominator = 30;
	
	printf("(A) Normal:\n");
	print_fraction(*fract);
	
	printf("(A) Extracted integer:\n");
	mf__extract_integer__i32(fract);
	print_fraction(*fract);

	printf("(A) Reduced:\n");
	mf__reduce_fraction__i32(fract);
	print_fraction(*fract);

	printf("(B) Normal:\n");
	mf__fraction_i32_t* fract_b = mf__alloc_fraction__i32();
	fract_b->numerator = 12;
	fract_b->denominator = 70;
	print_fraction(*fract_b);

	printf("Converted A & B:\n");
	mf__convert_to_same_look__i32(fract, fract_b);
	print_fraction(*fract);
	print_fraction(*fract_b);

	printf("Sum A + B:\n");
	mf__extract_integer__i32(fract_b);
	mf__fraction_i32_t fract_c = mf__sum_fractions__i32(*fract, *fract_b);
	print_fraction(fract_c);

	free(fract);
	free(fract_b);
	return 0;
}
