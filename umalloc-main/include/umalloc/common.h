// Copyright (c) 2020 udv. All rights reserved.

#ifndef UMALLOC_COMMON
#define UMALLOC_COMMON

#include <pthread.h>

typedef char ALIGN[16];

union memhdr {
	struct {
		size_t size;
		unsigned is_free;

		union memhdr *next;
	};
	ALIGN stub;
};

typedef union memhdr memhdr_t;

pthread_mutex_t global_memlock;
memhdr_t *head, *tail;

#endif //UMALLOC_COMMON
