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
gsl_combination_data (const gsl_combination * c)
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
      size_t *temp = c->data;
      temp += pointer_i;
      const size_t ci = *temp;

      if (ci >= n1)
        {
          GSL_ERROR("combination index outside range", GSL_FAILURE) ;
        }

      for (pointer_j = (size_t)0; pointer_j < pointer_i; pointer_j++)
        {
          temp = c->data;
          temp += pointer_j;
          size_t value_j = *temp;
          if (value_j == ci)
            {
              GSL_ERROR("duplicate combination index", GSL_FAILURE) ;
            }
          if (value_j > ci)
            {
              GSL_ERROR("combination indices not in increasing order",
                        GSL_FAILURE) ;
            }
        }
    }
  
  return (int_type)GSL_SUCCESS;
}


int_type
gsl_combination_next (gsl_combination * c)
{
  /* Replaces c with the next combination (in the standard lexicographical
   * ordering).  Returns GSL_FAILURE if there is no next combination.
   */
  const size_t n2 = c->n;
  const size_t k2 = c->k;
  size_t *data2 = c->data;
  size_t pointer, value_temp;
  bool valid = true;

  if(k2 == (size_t)0)
  {
      valid = false;
  }
  else
  {
      pointer = k2 - (size_t)1;

      data2 += pointer;
      value_temp = *data2;
      data2 = c->data;

      size_t w = (n2 - k2) + pointer;
      while(pointer > (size_t)0)
      {
          if(value_temp != w) break;
          pointer--;
      }

      data2 += pointer;
      value_temp = *data2;
      data2 = c->data;

      size_t w2 = n2 - k2;
      if((pointer == (size_t)0) && (value_temp == w2))
      {
          valid = false;
      }
      else
      {

          data2 += pointer;
          *data2 += (size_t)1;
          data2 = c->data;

          for(; pointer < (k2 - (size_t)1); pointer++)
          {
              size_t * temp_data = c->data;
              temp_data += pointer;
              data2 += (pointer + (size_t)1);
              *data2 = *temp_data + (size_t)1;
              data2 = c->data;
          }
      }
  }
  return (valid? (int_type)GSL_SUCCESS : (int_type)GSL_FAILURE);
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
  size_t *data3 = c->data;
  size_t pointer2, value1, value2;
  bool valid2 = true;

  if(k3 == (size_t)0)
  {
      valid2 = false;
  }
  else
  {
      pointer2 = k3 - (size_t)1;

      data3 += pointer2;
      value1 = *data3;
      data3 -= (size_t)1;
      value2 = *data3;
      data3 = c->data;

      while((pointer2 > (size_t)0) && (value1 == (value2 + (size_t)1)))
      {
          pointer2--;
      }
  
      data3 += pointer2;
      value1 = *data3;

      if((pointer2 == (size_t)0) && (value1 == (size_t)0))
      {
          valid2 = false;
      }
      else
      {
          data3 += pointer2;
          pointer2++;
          *data3 -= (size_t)1;
          data3 = c->data;
  
          for(; pointer2 < k3; pointer2++)
          {
              data3 += pointer2;
              *data3 = (n3 - k3) + pointer2;
              data3 = c->data;
          }
      }
  }
  return (valid2? (int_type)GSL_SUCCESS : (int_type)GSL_FAILURE);
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
         size_t *dest_data = dest->data, *src_data = src->data;
         dest_data += j;
         src_data += j;
         *dest_data = *src_data;
       }
   }
   
   return GSL_SUCCESS;
}
