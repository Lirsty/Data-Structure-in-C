#define qsort QSORT_IS_DISABLED
#include <stdlib.h>
#undef qsort
#include <stdio.h>
#include <string.h>

#define SWAP(a, b, size)            \
    do {                            \
        char tmp[size];             \
        memcpy(tmp, (a), (size));   \
        memcpy((a), (b), (size));   \
        memcpy((b), tmp, (size));   \
    } while (0)

void qsort(void *base, size_t num, size_t size, int (*cmp)(const void *, const void *))
{
    if (num <= 1) return;

    char *arr = base;
    size_t pivot_idx = num - 1;
    char *pivot = base + pivot_idx * size;

    size_t ll = 0;
    for (size_t i=0; i<pivot_idx; ++i)
    {
        char *current = arr + (i * size);
        if (cmp(current, pivot) < 0)
        {
            SWAP(current, arr + (ll * size), size);
            ++ll;
        }
    }

    SWAP(arr + (ll * size), pivot, size);

    qsort(arr, ll, size, cmp);
    qsort(arr+(ll+1), num-ll-1, size, cmp);
}


int int_cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int a[] = {5, 1, 2, 3, 4, 6, 7, 8, 9};
    qsort(a, sizeof(a)/sizeof(a[0]), sizeof(a[0]), int_cmp);

    for(int i=0; i<sizeof(a)/sizeof(a[0]); ++i)
        printf("%d ", a[i]);

    return 0;
}
