// Copyright (c) 2020 udv. All rights reserved.

#ifndef UMALLOC_MALLOC
#define UMALLOC_MALLOC

#include <string.h>
#include <unistd.h>

#include "common.h"

memhdr_t *get_free_block(size_t size);
void *umalloc(size_t size);
void *ucalloc(size_t num, size_t nsize);
void *urealloc(void *block, size_t size);
void ufree(void *block);

#endif //UMALLOC_MALLOC
