#include <stdio.h>

#include "acur.h"

/*
 * Tests whether the initialization functions work correctly.
 */
int main(void)
{
	int array[] = { 1, 2, 3 };

	size_t array_size = 3;
	size_t array_element_size = sizeof(int);
	size_t array_start_index = 0;
	size_t array_end_index = 3;
	int *array_end = &array[array_size];

	struct acur c[3];

	acur_init(&c[0], array_element_size, array, array_size);
	acur_init2(&c[1], array_element_size, array, array_end);
	acur_init3(&c[2], array_element_size, array, array_start_index, array_end_index);

	for (int i = 0; i < 3; ++i) {
		if (acur_data(&c[i]) != array) {
			fprintf(stderr, "%d: Data pointer is incorrect.\n", i);
			return 1;
		}

		if (acur_size(&c[i]) != array_size) {
			fprintf(stderr, "%d: Size is incorrect.\n", i);
			return 1;
		}

		if (acur_index(&c[i]) != 0) {
			fprintf(stderr, "%d: Current index is not pointing to the start.\n", i);
			return 1;
		}

		if (acur_element(&c[i]) != &array[array_start_index]) {
			fprintf(stderr, "%d: Current element is not pointing to the first element.\n", i);
			return 1;
		}

		if (acur_begin(&c[i]) != &array[array_start_index]) {
			fprintf(stderr, "%d: Pointer to the first element is incorrect.\n", i);
			return 1;
		}

		if (acur_end(&c[i]) != &array[array_end_index]) {
			fprintf(stderr, "%d: Pointer to the end of the array is incorrect.\n", i);
			return 1;
		}
	}

	return 0;
}
