#include <stdio.h>
#include "errno.h"
#include "gsl_types.h"
#include "gsl_combination.h"

gsl_error_handler_t * gsl_error_handler = NULL;

Error_status GSL_ERROR(const char * reason, Error_status gsl_errno)
{
    bool state = true;
    do { 
       gsl_error (reason, __FILE__, __LINE__, (int_type)gsl_errno) ; 
       state = false; 
       } while (state);
    return gsl_errno;
}

int_type GSL_ERROR_VAL(const char * reason, Error_status gsl_errno, int_type value)
{
       bool state1 = true;
       do { 
       gsl_error (reason, __FILE__, __LINE__, (int_type)gsl_errno) ; 
       state1 = false;  
       } while (state1);
      return value;
}

void GSL_ERROR_VOID(const char * reason, Error_status gsl_errno)
{
       bool state2 = true;
       do { 
       gsl_error (reason, __FILE__, __LINE__, (int_type)gsl_errno) ; 
       state2 = false;
       } while (state2);
      return;
}

void
gsl_stream_printf (const char *label, const char *file, int_type line, 
                   const char *reason)
{

  printf ("gsl: %s:%u: %s: %s\n", file, line, label, reason);

}

void
gsl_error (const char * reason, const char * file, int_type line, int_type gsl_errno)
{
  bool valid = false;
  if (gsl_error_handler) 
    {
      (*gsl_error_handler) (reason, file, line, gsl_errno);
      valid = true;
    }
  if(!valid){
      gsl_stream_printf ("ERROR", file, line, reason);

      printf ("Default GSL error handler invoked.\n");

      abort ();
  }
  return;
}

gsl_combination *
gsl_combination_alloc (const int_type p_n, const int_type p_k)
{
  gsl_combination temp = {0};
  gsl_combination * c1 = &temp;

  if (p_n == (int_type)0)
    {
      GSL_ERROR_VAL ("combination parameter n must be positive integer",
                        GSL_EDOM, 0);
    }
  if(p_k > p_n)
    {
      GSL_ERROR_VAL ("combination length k must be an integer less than or equal to n",
                        GSL_EDOM, 0);
    }

  if (p_k < (int_type)0)
    {
      GSL_ERROR_VAL ("combination length k must be an integer greater than or equal to 1",
                        GSL_EDOM, 0);
     
    }

  c1->n = (size_t)p_n;
  c1->k = (size_t)p_k;

  return c1;
}

gsl_combination *
gsl_combination_calloc (const int_type p_n1, const int_type p_k1)
{
  size_t pointer_i;

  gsl_combination * c2 =  gsl_combination_alloc (p_n1, p_k1);

  /* initialize combination to identity */

  for (pointer_i = (size_t)0; pointer_i < (size_t)p_k1; pointer_i++)
    {
      c2->data[pointer_i] = pointer_i;
    }

  return c2;
}
