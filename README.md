# Acur 1.1.1

A cursor for arrays in C.


## Table of contents

1. Introduction
2. Example
3. How to use
4. Reporting Bugs
5. License


## 1. Introduction

Acur is a C library that provides a structure that can keep track of your
position in an array as you traverse over its elements.

The functions in this library assume that they're going to be used correctly.
This is in the same spirit that the C language is designed with that allows it
to be efficient.

All functions are marked `inline` so that no operation incurs a function call
overhead if the compiler agrees that it's worth it.


## 2. Example

```C
#include <stdio.h>

// Include the header.
#include <acur.h>

int main(void)
{
	int array[] = { 1, 2, 3 };

	// Declare cursor variable
	struct acur cursor;

	// Initialize the cursor.
	acur_init(&cursor, sizeof(int), array, 3);

	// Iterate to the end.
	while (!acur_finished(&cursor)) {
		int i = acur_index(&cursor);
		int *e = acur_element(&cursor);

		printf("Element #%d contains the value %d.\n", i + 1, *e);

		// Move on to the next element.
		acur_next(&cursor);
	}

	return 0;
}
```


## 3. How to use

You can either copy the source files into your own project or install the
header file and the static library in your system and have your compiler link
to `libacur.a`. Then include `acur.h` in your code.

```C
#include <acur.h>
```

This lets you declare variables of type `struct acur`.

```C
struct acur my_cursor;
```

While the struct is not an opaque data structure, you're not supposed to access
its data members directly. You're going to call functions that operate on it,
instead.

The first thing you will want to do is to initialize the struct. You have 3
functions that allow you to initialize the struct:

- `acur_init`: Takes the size of each element, a pointer to the array and its
  size.
- `acur_init2`: Takes the size of each element, a pointer to the first element
  and a pointer to where it ends.
- `acur_init3`: Takes the size of each element, a pointer to the array, the
  index where the first element starts and the index where it ends.

```C
int array[5];

acur_init(&my_cursor1, sizeof(int), array, 5);
acur_init2(&my_cursor2, sizeof(int), array, array + 5);
acur_init3(&my_cursor3, sizeof(int), array, 0, 5);
```

Use the one which suits best for the situation at hand.

You can get a pointer to the element that the cursor is currently pointing to
by calling `acur_element`.

```C
int *element = acur_element(&my_cursor);
```

To move to the next element you call `acur_next`.

```C
acur_next(&my_cursor);
```

Call `acur_finished` to check if the cursor traversed through all the elements.

```C
int finished = acur_finished(&my_cursor);
```

Call `acur_rewind` to move the cursor back to the first element.

```C
acur_rewind(&my_cursor);
```

Read the comments in the `acur.h` header file for detailed descriptions of all
functions


## 4. Reporting bugs

If you encounter a bug, please open an issue on GitHub:

	https://github.com/daniel-araujo/acur/issues


## 5. License

This program is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
