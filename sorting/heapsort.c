#define heapsort HEAPSORT_IS_DISABLED
#include <stdlib.h>
#undef heapsort
#include <stdio.h>
#include <string.h>

#define SWAP(a, b, size)            \
    do {                            \
        char tmp[size];             \
        memcpy(tmp, (a), (size));   \
        memcpy((a), (b), (size));   \
        memcpy((b), tmp, (size));   \
    } while (0)


void heapify(void *base, size_t num, size_t size, size_t root, int (*cmp)(const void *, const void *))
{
    char *arr = base;
    size_t largest = root;
    size_t left = (root << 1) + 1;
    size_t right = (root << 1) + 2;

    if (left < num && cmp(arr+(left*size), arr+(largest*size)) > 0)
        largest = left;
    if (right < num && cmp(arr+(right*size), arr+(largest*size)) > 0)
        largest = right;
    if (largest != root)
    {
        SWAP(arr+(root*size), arr+(largest*size), size);
        heapify(base, num, size, largest, cmp);
    }
}

void heapsort(void *base, size_t num, size_t size, int (*cmp)(const void *, const void *))
{
    char *arr = base;

    for (size_t i = num>>1; i>0; --i)
        heapify(arr, num, size, i-1, cmp);

    for (size_t i = num-1; i>0; --i) 
    {
        SWAP(arr, arr+(i*size), size);
        heapify(arr, i, size, 0, cmp);
    }
}


int int_cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int a[] = {5, 1, 2, 3, 4, 6, 7, 8, 9};
    heapsort(a, sizeof(a)/sizeof(a[0]), sizeof(a[0]), int_cmp);

    for(int i=0; i<sizeof(a)/sizeof(a[0]); ++i)
        printf("%d ", a[i]);

    return 0;
}
