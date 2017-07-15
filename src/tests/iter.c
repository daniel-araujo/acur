#include <stdio.h>

#include "acur.h"

/*
 * Tests iterating over elements.
 */
int main(void)
{
	int array[] = { 1, 2, 3 };

	struct acur c;
	acur_init1(&c, sizeof(int), array, 3);

	if (acur_begin(&c) != &array[0]) {
		fprintf(stderr, "Pointer to the first element is incorrect.\n");
		return 1;
	}

	if (acur_end(&c) != &array[3]) {
		fprintf(stderr, "Pointer to the end of the array is incorrect.\n");
		return 1;
	}

	if (acur_element(&c) != &array[0]) {
		fprintf(stderr, "Current element is supposed to be pointing to the first element.\n");
		return 1;
	}

	if (acur_index(&c) != 0) {
		fprintf(stderr, "Current index is supposed to be 0.\n");
		return 1;
	}

	acur_next(&c);

	if (acur_element(&c) != &array[1]) {
		fprintf(stderr, "After calling acur_next, current element is supposed to be pointing to the second element.\n");
		return 1;
	}

	if (acur_index(&c) != 1) {
		fprintf(stderr, "After calling acur_next, current index is supposed to be 1.\n");
		return 1;
	}

	acur_next(&c);

	if (acur_element(&c) != &array[2]) {
		fprintf(stderr, "After calling acur_next again, current element is supposed to be pointing to the third and last element.\n");
		return 1;
	}

	if (acur_index(&c) != 2) {
		fprintf(stderr, "After calling acur_next again, current index is supposed to be 2.\n");
		return 1;
	}

	acur_next(&c);

	if (acur_element(&c) != &array[3]) {
		fprintf(stderr, "Expected pointer to the end of the array.\n");
		return 1;
	}

	if (acur_index(&c) != acur_size(&c)) {
		fprintf(stderr, "Expected current index to be the size of the array.\n");
		return 1;
	}

	acur_next(&c);

	if (acur_element(&c) != &array[3]) {
		fprintf(stderr, "The function acur_next should have no effect when reaching the end of the array.\n");
		return 1;
	}

	if (acur_index(&c) != acur_size(&c)) {
		fprintf(stderr, "The function acur_next should have no effect on the index when reaching the end of the array.\n");
		return 1;
	}

	acur_rewind(&c);

	if (acur_element(&c) != &array[0]) {
		fprintf(stderr, "After rewinding, the current element is supposed to be the first element again.\n");
		return 1;
	}

	if (acur_index(&c) != 0) {
		fprintf(stderr, "After rewinding, the current index is supposed to be 0 again.\n");
		return 1;
	}

	return 0;
}
