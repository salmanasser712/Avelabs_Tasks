#include <stdio.h>
#include "gsl_combination.h"

int main(){
    const size_t  n, k;
    printf("Please Enter n and k of the combination you want to calculate:\n");
    scanf("%llu%llu", &n, &k);

    gsl_combination * c = gsl_combination_calloc (n, k);

    size_t ans = 1;
    while(gsl_combination_next(c) == GSL_SUCCESS){
        ans++;
    }

    printf("The Result: %llu\n", ans);
    
    return 0;
}