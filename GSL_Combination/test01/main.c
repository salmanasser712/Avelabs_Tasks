#include <stdio.h>
#include "gsl_combination.h"

int_type main(void);

int_type main(void)
{
    const int_type n1 = 18, k1 = 2;

    printf("for 18C2, ");

    gsl_combination * c1 = gsl_combination_calloc (n1, k1);

    size_t ans = 1;
    while(gsl_combination_next(c1) == GSL_SUCCESS){
        ans++;
    }

    printf("The Result: %llu\n", ans);
    
    return (int_type)0;
}
