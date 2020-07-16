// Copyright (c) 2020 udv. All rights reserved.
#include <umalloc/malloc.h>
#include <stdio.h>

int main(int argc, char **argv) {
	int *test = (int *) umalloc(sizeof(int *));

	*test = 5;
	printf("%i\n", *test);

	ufree(test);

	return 0;
}