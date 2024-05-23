#include <stdio.h>
#include "errno.h"
#include "gsl_types.h"
#include "gsl_combination.h"

gsl_error_handler_t * gsl_error_handler = NULL;

void
gsl_stream_printf (const char *label, const char *file, int line, 
                   const char *reason)
{

  printf ("gsl: %s:%d: %s: %s\n", file, line, label, reason);

}

void
gsl_error (const char * reason, const char * file, int line, int gsl_errno)
{
  if (gsl_error_handler) 
    {
      (*gsl_error_handler) (reason, file, line, gsl_errno);
      return ;
    }

  gsl_stream_printf ("ERROR", file, line, reason);

  printf ("Default GSL error handler invoked.\n");

  abort ();
}

gsl_combination *
gsl_combination_alloc (const size_t n, const size_t k)
{
  gsl_combination * c;

  if (n == 0)
    {
      GSL_ERROR_VAL ("combination parameter n must be positive integer",
                        GSL_EDOM, 0);
    }
  if (k > n)
    {
      GSL_ERROR_VAL ("combination length k must be an integer less than or equal to n",
                        GSL_EDOM, 0);
    }
  c = (gsl_combination *) malloc (sizeof (gsl_combination));

  if (c == 0)
    {
      GSL_ERROR_VAL ("failed to allocate space for combination struct",
                        GSL_ENOMEM, 0);
    }

  if (k > 0)
    {
      c->data = (size_t *) malloc (k * sizeof (size_t));

      if (c->data == 0)
        {
          free (c);             /* exception in constructor, avoid memory leak */

          GSL_ERROR_VAL ("failed to allocate space for combination data",
                         GSL_ENOMEM, 0);
        }
    }
  else
    {
      c->data = 0;
    }

  c->n = n;
  c->k = k;

  return c;
}

gsl_combination *
gsl_combination_calloc (const size_t n, const size_t k)
{
  size_t i;

  gsl_combination * c =  gsl_combination_alloc (n, k);

  if (c == 0)
    return 0;

  /* initialize combination to identity */

  for (i = 0; i < k; i++)
    {
      c->data[i] = i;
    }

  return c;
}