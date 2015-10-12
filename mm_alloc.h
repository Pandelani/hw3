
#pragma once

#ifndef _malloc_H_
#define _malloc_H_

 /* Define the block size since the sizeof will be wrong */
#define BLOCK_SIZE 40
#define S_BLOCK_SIZE 40

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>

void* mm_malloc(size_t size);
void* mm_realloc(void* ptr, size_t size);
void mm_free(void* ptr);


typedef struct s_block *s_block_ptr;

/* block struct */
struct s_block {
    size_t size;
    struct s_block *next;
    struct s_block *prev;
    int free;
    void *ptr;
    /* A pointer to the allocated block */
    char data[0];
 };

/* Split block according to size, b must exist */
void split_block (s_block_ptr b, size_t s);

/* Try fusing block with neighbors */
static s_block_ptr fusion(s_block_ptr b);

/* Get the block from addr */
static s_block_ptr get_block (void *p);

/* Add a new block at the of heap,
 * return NULL if things go wrong
 */
static s_block_ptr extend_heap (size_t s);


#ifdef __cplusplus
}
#endif

#endif
