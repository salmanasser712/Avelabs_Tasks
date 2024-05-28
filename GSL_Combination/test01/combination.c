/* combination/combination.c
 * based on permutation/permutation.c by Brian Gough
 * 
 * Copyright (C) 2001 Szymon Jaroszewicz
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#include "config.h.in"
#include "gsl_errno.h"
#include "gsl_combination.h"

size_t
gsl_combination_n (const gsl_combination * c)
{
  return c->n ;
}

size_t
gsl_combination_k (const gsl_combination * c)
{
  return c->k ;
}

size_t *
gsl_combination_data (gsl_combination * c)
{
  return c->data ;
}

int_type
gsl_combination_valid (gsl_combination * c)
{
  const size_t n1 = c->n ;
  const size_t k1 = c->k ;

  size_t pointer_i, pointer_j ;

  if( k1 > n1 )
    {
      GSL_ERROR("combination has k greater than n", GSL_FAILURE) ;
    }
  for (pointer_i = (size_t)0; pointer_i < k1; pointer_i++) 
    {
      size_t ci = c->data[pointer_i];

      if (ci >= n1)
        {
          GSL_ERROR("combination index outside range", GSL_FAILURE) ;
        }

      for (pointer_j = (size_t)0; pointer_j < pointer_i; pointer_j++)
        {
          size_t cj = c->data[pointer_j];
          if (cj == ci)
            {
              GSL_ERROR("duplicate combination index", GSL_FAILURE) ;
            }
          if (cj > ci)
            {
              GSL_ERROR("combination indices not in increasing order",
                        GSL_FAILURE) ;
            }
        }
    }
  
  return GSL_SUCCESS;
}


int_type
gsl_combination_next (gsl_combination * c)
{
  /* Replaces c with the next combination (in the standard lexicographical
   * ordering).  Returns GSL_FAILURE if there is no next combination.
   */
  const size_t n2 = c->n;
  const size_t k2 = c->k;
  size_t (*data2)[N];
  data2 = &(c->data);
  size_t pointer1;

  bool valid = true;

  if(k2 == (size_t)0)
    {
      valid = false;
    }
  if(valid){
      pointer1 = k2 - (size_t)1;

      while((pointer1 > (size_t)0) && ((*data2)[pointer1] == ((n2 - k2) + pointer1)))
        {
          pointer1--;
        }
      if((pointer1 == (size_t)0) && ((*data2)[pointer1] == (n2 - k2)))
        {
          valid = false;
        }
      if(valid){
          (*data2)[pointer1]++;
          for(; pointer1 < (k2 - (size_t)1); pointer1++)
            {
              (*data2)[pointer1 + (size_t)1] = (*data2)[pointer1] + (size_t)1;
            }
      }
  }
  return (valid? (int_type)GSL_SUCCESS: (int_type)GSL_FAILURE);
}

int_type
gsl_combination_prev (gsl_combination * c)
{
  /* Replaces c with the previous combination (in the standard
   * lexicographical ordering).  Returns GSL_FAILURE if there is no
   * previous combination.
   */
  const size_t n3 = c->n;
  const size_t k3 = c->k;
  size_t (*data3)[N];
  data3 = &(c->data);
  size_t pointer2;

  bool valid1 = true;

  if(k3 == (size_t)0)
    {
      valid1 = false;
    }
  if(valid1){
      pointer2 = k3 - (size_t)1;

      while((pointer2 > (size_t)0) && ((*data3)[pointer2] == ((*data3)[pointer2 - (size_t)1] + (size_t)1)))
        {
          pointer2--;
        }
      if((pointer2 == (size_t)0) && ((*data3)[pointer2] == (size_t)0))
        {
          valid1  = false;
        }
      if(valid1 == true){
          (*data3)[pointer2]--;
          pointer2++;
          for(; pointer2 < k3; pointer2++)
            {
              (*data3)[pointer2] = (n3 - k3) + pointer2;
            }
      }
  }
  return (valid1? (int_type)GSL_SUCCESS: (int_type)GSL_FAILURE);
}

int_type
gsl_combination_memcpy (gsl_combination * dest, const gsl_combination * src)
{
   const size_t src_n = src->n;
   const size_t src_k = src->k;
   const size_t dest_n = dest->n;
   const size_t dest_k = dest->k;

   if ((src_n != dest_n) || (src_k != dest_k))
     {
       GSL_ERROR ("combination lengths are not equal", GSL_EBADLEN);
     }
   
   {
     size_t j;
     
     for (j = (size_t)0; j < src_k; j++)
       {
         dest->data[j] = src->data[j];
       }
   }
   
   return GSL_SUCCESS;
}
