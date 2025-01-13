#define radixsort RADIXSORT_IS_DISABLED
#include <stdlib.h>
#undef radixsort
#include <stdio.h>
#include <string.h>

void radixsort(uint64_t *arr, size_t num, size_t bit_count)
{
    size_t size = sizeof(uint64_t) * num; 
    uint64_t *tmp = malloc(size);
    if (tmp == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (size_t bit=0; bit<bit_count; ++bit) {
        size_t pos[2] = {0, 0};

        for (size_t i=0; i<num; ++i)
            pos[(arr[i] >> bit) & 1]++;

        pos[1] = pos[0];
        pos[0] = 0;

        for (size_t i=0; i<num; ++i) 
            tmp[pos[(arr[i] >> bit) & 1]++] = arr[i];

        memcpy(arr, tmp, size);
    }

    free(tmp);
}

int main()
{
    srand(1435227);
    #define LEN 10
    uint64_t arr[LEN];
    for (int i=0; i<LEN; ++i)
        arr[i] ^= (((uint64_t)rand()) << 32) | ((uint64_t)rand());

    radixsort(arr, LEN, 64);

    for (int i=0; i<LEN; ++i)
        printf("%llu \n", arr[i]);
}