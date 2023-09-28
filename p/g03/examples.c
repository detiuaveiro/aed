//
// Tomás Oliveira e Silva, AED, November 2021
//
// empirical computational complexity (the first function is already fully instrumented)
//

#include <math.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>


//
// counter for the number of inner loop iterations (to simplify things, we make it a global variable)
//

static unsigned long count; // counts the number of inner loop iterations


//
// O(n) algorithms
//

double vector_sum(unsigned int n,double a[n])
{
  double r = a[0];
  for(unsigned int i = 1u;i < n;i++)
  {
    count++; // count the number of inner loop iterations
    r += a[i];
  }
  return r;
}

double vector_inner_product(unsigned int n,double a[n],double b[n])
{
  double r = a[0] * b[0];
  for(unsigned int i = 1u;i < n;i++)
    r += a[i] * b[i];
  return r;
}

void vector_addition(unsigned int n,double a[n],double b[n],double r[n])
{ // r = a + b
  for(unsigned int i = 0u;i < n;i++)
    r[i] = a[i] + b[i];
}

unsigned int find_index(unsigned int n,unsigned int a[n],unsigned int x)
{ // returns n when x is not found
  unsigned int i;

  for(i = 0u;i < n && a[i] != x;i++)
    ;
  return i;
}

unsigned int count_indices(unsigned int n,unsigned int a[n],unsigned int x)
{
  unsigned int c = 0u;

  for(unsigned int i = 0u;i < n;i++)
    if(a[i] == x)
      c++;
  return c;
}

double factorial(unsigned int n)
{
  return (n < 2u) ? 1.0 : (double)n * factorial(n - 1u);
}


//
// O(n^2) algorithms --- in mathematical expressions inside comments, by ^ we mean exponentiation
//

void carry_propagation(unsigned int n,unsigned int a[n])
{ // count the number of iteratations of the inner loop an belonging to the function that called this one
  unsigned int carry = 0u;
  for(unsigned int i = 0u;i < n;i++)
  {
count++,
    carry += a[i];
    a[i] = carry % 10u;
    carry /= 10u;
  }
  assert(carry == 0u);
}

void multiplication(unsigned int n,unsigned int a[n],unsigned int b[n],unsigned int r[2u * n])
{ // r = a * b
  assert(sizeof(n) >= (size_t)4 && n <= 47721858u);
  for(unsigned int i = 0u;i < 2u * n;i++)
count++,
    r[i] = 0u;
  for(unsigned int i = 0u;i < n;i++)
    if(a[i] != 0u)
      for(unsigned int j = 0u;j < n;j++)
count++,
        r[i + j] += a[i] * b[j];
  carry_propagation(2u * n,&r[0]);
}

void matrix_addition(unsigned int n,double A[n][n],double B[n][n],double R[n][n])
{ // R = A + B
  unsigned int i,j;

  for(i = 0u;i < n;i++)
    for(j = 0u;j < n;j++)
      R[i][j] = A[i][j] + B[i][j];
}

void insertion_sort(unsigned int n,double a[n])
{
  unsigned int i,j;
  double v;

  for(i = 1u;i < n;i++)
  {
    v = a[i];
    for(j = i;j > 0u && v < a[j - 1u];j--)
      a[j] = a[j - 1u];
    a[j] = v;
  }
}


//
// O(n^3) algorithms
//

void matrix_matrix_product(unsigned int n,double A[n][n],double B[n][n],double R[n][n])
{ // R = A * B
  for(unsigned int i = 0u;i < n;i++)
    for(unsigned int j = 0u;j < n;j++)
      R[i][j] = 0.0;
  for(unsigned int i = 0u;i < n;i++)
    for(unsigned int j = 0u;j < n;j++)
      for(unsigned int k = 0u;k < n;k++)
        R[i][j] += A[i][k] * B[k][j];
}

double matrix_determinant(unsigned int n,double A[n][n])
{ // warning: A is modified
  unsigned int i,j,k;
  double r,t;

  r = 1.0;
  for(i = 0u;i < n;i++)
  {
    // find the biggest element (the pivot)
    j = i;
    for(k = i + 1u;k < n;k++)
      if(fabs(A[k][i]) > fabs(A[j][i]))
        j = k;
    // exchange lines (if necessary)
    if(j != i)
      for(r = -r,k = i;k < n;k++)
      {
        t = A[i][k];
        A[i][k] = A[j][k];
        A[j][k] = t;
      }
    // Gauss-Jordan elimination
    for(r *= A[i][i],j = i + 1u;j < n;j++)
      for(k = i + 1u;k < n;k++)
        A[j][k] -= (A[j][i] / A[i][i]) * A[i][k];
  }
  return r;
}


//
// algorithms with exponential complexity
//

double F(unsigned int n)
{
  return (n < 2u) ? (double)n : F(n - 1u) + F(n - 2u);
}

double Fi(unsigned int n)
{
  static double Ft[10] =
  {
     0.0, 1.0, 1.0, 2.0, 3.0, // 0 to 4
     5.0, 8.0,13.0,21.0,34.0  // 5 to 9
  };

  return (n < 10u) ? Ft[n] : Fi(n - 1u) + Fi(n - 2u);
}

void print_all_sums(unsigned int n,double a[n])
{
  unsigned long mask;
  unsigned int i,j;
  double sum;

  mask = 0ul; // if the bit number i is set to 0 then
              // a[i] will not contribute to the sum
              // we begin with the empty set
  do
  {
    // do sum
    sum = 0.0;
    for(i = j = 0u;i < n;i++)
      if(((mask >> i) & 1ul) != 0ul)
      {
        sum += a[i];
        printf("%sa[%u]",(j == 0u) ? "" : "+",i);
        j = 1u; // next time print a + sign
      }
    printf("%s = %.3f\n",(j == 0u) ? "empty" : "",sum);
    // next subset (discrete binary counter)
    mask++;
  }
  while(mask < (1ul << n));
}

void print_all_sums_recursive(unsigned int n,unsigned int m,double a[n],double sum,unsigned long mask)
{
  if(m == n)
  { // nothing more to do; print sum
    unsigned int i,j;

    for(i = j = 0u;i < n;i++)
      if(((mask >> i) & 1ul) != 0ul)
      {
        printf("%sa[%u]",(j == 0u) ? "" : "+",i);
        j = 1u; // next time print a + sign
      }
    printf("%s = %.3f\n",(j == 0u) ? "empty" : "",sum);
  }
  else
  {
    print_all_sums_recursive(n,m + 1u,&a[0],sum       ,mask             ); // do not use a[m]
    print_all_sums_recursive(n,m + 1u,&a[0],sum + a[m],mask | (1ul << m)); // use a[m]
  }
}


//
// algorithm with worst than exponential complexity (in this case, factorial complexity)
//

void print_all_permutations_recursive(unsigned int n,unsigned int m,int a[n])
{
  unsigned int i;

  if(m == n - 1u)
  { // nothing more to do, visit permutation (in this example, just print it)
    // in the instrumented version of this function just count the number of visitations (don't print the permutations!)
    for(i = 0u;i < n;i++)
      printf("%s%d",(i == 0u) ? "" : " ",a[i]);
    printf("\n");
  }
  else // not yet at the end, place in a[m] each remaining integer and recurse
    for(i = m;i < n;i++)
    {
#define swap(i,j)  do { int t = a[i]; a[i] = a[j]; a[j] = t; } while(0)
      swap(i,m);                                        // swap a[i] with a[m]
      print_all_permutations_recursive(n,m + 1u,&a[0]); // recurse
      swap(i,m);                                        // undo the swap of a[i] with a[m]
#undef swap
    }
}


//
// algorithms with small complexity
//

double power_dd(double x,double y)
{
  return exp(y * log(x));
}

double power_di(double x,int n)
{
  if(n < 0)  return power_di(1.0 / x,-n);
  if(n == 0) return 1.0;
  double t = power_di(x * x,n / 2); // the integer division discards a fractional part
  return (n % 2 == 0) ? t : x * t;  // take care of the discarded fractional part
}


//
// functions to do random initialization of vectors or matrices
//

unsigned int rand_uint(unsigned int range)
{
  return (unsigned int)rand() % range; // almost uniform distribution in the integers of the interval [0,range[
}

void rand_uint_vector(unsigned int n,unsigned int a[n],unsigned int range)
{
  for(unsigned int i = 0u;i < n;i++)
    a[i] = rand_uint(range);
}

double rand_double(double d_min,double d_max)
{
  return d_min + (d_max - d_min) * (double)rand() / (double)RAND_MAX; // uniform distribution in the interval [d_min,d_max[
}

void rand_double_vector(unsigned int n,double a[n],double d_min,double d_max)
{
  for(unsigned int i = 0u;i < n;i++)
    a[i] = rand_double(d_min,d_max);
}


//
// main
//
// TODO: do even more random experiments, and print only the maximum and the mean of the count values
//

int main(int argc,char **argv)
{
  unsigned int n,n_idx;

  // O(n)
  if(argc == 2 && strcmp(argv[1],"vector_sum") == 0)
  {
    printf("# vector_sum data\n");
    for(n_idx = 10u;n_idx <= 40u;n_idx++)
    {
      n = (unsigned int)round(pow(10.0,0.1 * (double)n_idx));
      printf("%u",n);
      for(unsigned int k = 0u;k < 4u;k++)
      { // do 5 random experiments
        double a[n];
        rand_double_vector(n,&a[0],-1.0,+1.0);
        count = 0ul;
        if(vector_sum(n,&a[0]) == 1.0e100)
          return 99; // this will never happen, but the test ensures the function call is not optimized out
        printf(" %lu",count);
      }
      printf("\n");
    }
    return 0; // done
  }
  if(argc == 2 && strcmp(argv[1],"vector_inner_product") == 0)
  {
    printf("# vector_inner_product data\n");
    for(n_idx = 10u;n_idx <= 40u;n_idx++)
    {
      n = (unsigned int)round(pow(10.0,0.1 * (double)n_idx));
      printf("%u",n);
      for(unsigned int k = 0u;k < 4u;k++)
      { // do 5 random experiments
        double a[n];
        double b[n];
        rand_double_vector(n,&a[0],-1.0,+1.0);
        rand_double_vector(n,&b[0],-1.0,+1.0);
        count = 0ul;
        if(vector_inner_product(n,&a[0],&b[0]) == 1.0e100)
          return 99; // this will never happen, but the test ensures the function call is not optimized out
        printf(" %lu",count);
      }
      printf("\n");
    }
    return 0; // done
  }
  if(argc == 2 && strcmp(argv[1],"vector_addition") == 0)
  {
    printf("# vector_addition data\n");
    for(n_idx = 10u;n_idx <= 40u;n_idx++)
    {
      n = (unsigned int)round(pow(10.0,0.1 * (double)n_idx));
      printf("%u",n);
      for(unsigned int k = 0u;k < 4u;k++)
      { // do 5 random experiments
        double a[n];
        double b[n];
        double r[n];
        rand_double_vector(n,&a[0],-1.0,+1.0);
        rand_double_vector(n,&b[0],-1.0,+1.0);
        count = 0ul;
        vector_addition(n,&a[0],&b[0],&r[0]);
        printf(" %lu",count);
      }
      printf("\n");
    }
    return 0; // done
  }
  if(argc == 2 && strcmp(argv[1],"find_index") == 0)
  {
    printf("# find_index data\n");
    for(n_idx = 10u;n_idx <= 40u;n_idx++)
    {
      n = (unsigned int)round(pow(10.0,0.1 * (double)n_idx));
      printf("%u",n);
      for(unsigned k = 0u;k < 5u;k++)
      { // do 5 random experiments
        unsigned int a[n];
        rand_uint_vector(n,&a[0],n);
        count = 0ul;
        if(find_index(n,&a[0],rand_uint(n)) == 2u * n)
          return 99; // this will never happen, but the test ensures the function call is not optimized out
        printf(" %lu",count);
      }
      printf("\n");
    }
    return 0; // done
  }
  if(argc == 2 && strcmp(argv[1],"count_indices") == 0)
  {
    printf("# count_indices data\n");
    for(n_idx = 10u;n_idx <= 40u;n_idx++)
    {
      n = (unsigned int)round(pow(10.0,0.1 * (double)n_idx));
      printf("%u",n);
      for(unsigned k = 0u;k < 5u;k++)
      { // do 5 random experiments
        unsigned int a[n];
        rand_uint_vector(n,&a[0],1000u);
        count = 0ul;
        if(count_indices(n,&a[0],1000000u) != 0u)
          return 99; // this will never happen, but the test ensures the function call is not optimized out
        printf(" %lu",count);
      }
      printf("\n");
    }
    return 0; // done
  }
  if(argc == 2 && strcmp(argv[1],"factorial") == 0)
  {
    printf("# factorial data\n");
    for(n = 0u;n <= 40u;n++)
    {
      printf("%u",n);
      for(unsigned k = 0u;k < 5u;k++)
      { // do 5 random experiments
        count = 0ul;
        if(factorial(n) == 0.0)
          return 99; // this will never happen, but the test ensures the function call is not optimized out
        printf(" %lu",count);
      }
      printf("\n");
    }
    return 0; // done
  }
  // O(n^2)
  if(argc == 2 && strcmp(argv[1],"multiplication") == 0)
  {
    printf("# multiplication data\n");
    for(n_idx = 10u;n_idx <= 40u;n_idx++)
    {
      n = (unsigned int)round(pow(10.0,0.1 * (double)n_idx));
      printf("%u",n);
      for(unsigned k = 0u;k < 5u;k++)
      { // do 5 random experiments
        unsigned int a[n];
        unsigned int b[n];
        unsigned int r[2u * n];
        rand_uint_vector(n,&a[0],10u);
        rand_uint_vector(n,&b[0],10u);
        count = 0ul;
        multiplication(n,&a[0],&b[0],&r[0]);
        if(r[0] == 10u)
          return 99; // this will never happen, but the test ensures the function call is not optimized out
        printf(" %lu",count);
      }
      printf("\n");
    }
    return 0; // done
  }

  // we get here if nothing was done, so we print an error message and exit
  fprintf(stderr,"usage: %s function_ name\n",argv[0]);
  fprintf(stderr,"List of funcion names:\n");
  fprintf(stderr,"  vector_sum\n");
  fprintf(stderr,"  vector_inner_product\n");
  fprintf(stderr,"  vector_addition\n");
  fprintf(stderr,"  find_index\n");
  fprintf(stderr,"  count_indices\n");
  fprintf(stderr,"  factorial\n");
  return 1;
}
