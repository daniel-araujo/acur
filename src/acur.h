#ifndef ACUR_ACUR_H
#define ACUR_ACUR_H

#include <stdlib.h>

/*
 * The acur struct. Declare variables of this type and initialize them by
 * calling either acur_init1, acur_init2 or acur_init3.
 */
struct acur {
	size_t index;
	size_t size;
	size_t element_size;
	char *data;
};

/*
 * This is an implementation detail. Do not call this function.
 *
 * Translates an index provided by the user to an index that can be used to
 * access the data.
 */
inline size_t acur_data_index(struct acur *c, size_t index)
{
	return index * c->element_size;
}

/*
 * Initializes a cursor. It expects you to pass a pointer to the array, the
 * size of each element and the size of the array.
 */
inline void acur_init1(struct acur *c, size_t element_size, void *data, size_t size)
{
	c->index = 0;
	c->size = size;
	c->element_size = element_size;
	c->data = data;
}

/*
 * Initializes a cursor. It expects you to pass a pointer to the start of the
 * array, a pointer to where it ends and the size of each element.
 */
inline void acur_init2(struct acur *c, size_t element_size, void *start_data, void *end_data)
{
	c->index = 0;
	c->size = ((char *) end_data - (char *) start_data) / element_size;
	c->element_size = element_size;
	c->data = start_data;
}

/*
 * Initializes a cursor. It expects you to pass a pointer to the array, the
 * size of each element, the index of the start element and the index where to
 * end.
 */
inline void acur_init3(struct acur *c, size_t element_size, void *data, size_t start_index, size_t end_index)
{
	c->index = 0;
	c->size = end_index - start_index;
	c->element_size = element_size;
	c->data = data + acur_data_index(c, start_index);
}

/*
 * Checks whether the cursor reached the end.
 *
 * Returns 1 if it is, 0 if not.
 */
inline int acur_finished(struct acur *c)
{
	return c->index == c->size;
}

/*
 * Rewinds the cursor back to the start.
 */
inline void acur_rewind(struct acur *c)
{
	c->index = 0;
}

/*
 * Returns the address of the array.
 */
inline void *acur_data(struct acur *c)
{
	return c->data;
}

/*
 * Returns the size of the array.
 */
inline size_t acur_size(struct acur *c)
{
	return c->size;
}

/*
 * Returns the current index.
 *
 * Will return the size of the array when the cursor has traversed all the
 * elements.
 */
inline size_t acur_index(struct acur *c)
{
	return c->index;
}

/*
 * Returns a pointer to the current element of the array.
 *
 * Will return a pointer to the end of the array when the cursor has traversed
 * all the elements. This pointer cannot be dereferenced.
 */
inline void *acur_element(struct acur *c)
{
	return c->data + acur_data_index(c, c->index);
}

/*
 * Returns a pointer to the first element of the array.
 */
inline void *acur_begin(struct acur *c)
{
	return c->data;
}

/*
 * Returns a pointer to the end of the array.
 *
 * Note that this is not a pointer to the last element of the array.
 *
 * This pointer cannot be dereferenced.
 */
inline void *acur_end(struct acur *c)
{
	return c->data + acur_data_index(c, c->size);
}

/*
 * Moves on to the next element of the array.
 *
 * This function will have no effect if the cursor has reached the end.
 */
inline void acur_next(struct acur *c)
{
	if (acur_finished(c)) {
		// Reached the end. Don't do anything.
		return;
	}

	++c->index;
}

#endif /* ACUR_ACUR_H */
