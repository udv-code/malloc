// Copyright (c) 2020 udv. All rights reserved.

#include "umalloc/malloc.h"

void *umalloc(size_t size) {
	void *block;
	memhdr_t *header;

	if (!size) {
		return NULL;
	}
	pthread_mutex_lock(&global_memlock);
	header = get_free_block(size);

	if (header) {
		header->is_free = 0;
		pthread_mutex_unlock(&global_memlock);
		return (void *) (header + 1);
	}
	size_t total_size = sizeof(memhdr_t) + size;
	block = sbrk(total_size);
	if (block == (void *) -1) {
		pthread_mutex_unlock(&global_memlock);
		return NULL;
	}

	header = block;
	header->size = size;
	header->is_free = 0;
	header->next = NULL;
	if (!head) {
		head = header;
	}
	if (tail) {
		tail->next = header;
	}
	tail = header;

	pthread_mutex_unlock(&global_memlock);

	return (void *) (header + 1);
}

memhdr_t *get_free_block(size_t size) {
	memhdr_t *current = head;
	while (current) {
		if (current->is_free && current->size >= size) {
			return current;
		}
		current = current->next;
	}
	return NULL;
}
