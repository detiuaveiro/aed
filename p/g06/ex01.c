#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <error.h>

// Para instrumentar funções:
long nadd = 0;  // number of additions
long ncall = 0;  // number of calls (recursive + 1)

// Recursive
int delannoyR(int m, int n) {
  ncall++;
  int r;
  if (m ==0 || n == 0) {
    r = 1;
  } else {
    nadd += 2;
    r = delannoyR(m-1, n) + delannoyR(m-1, n-1) + delannoyR(m, n-1);
  }
  return r;
}

#define LIMIT 100
static int cacheM[1+LIMIT][1+LIMIT] = {{0}};  // everything else = 0

// Recursive Memoized
int delannoyM(int m, int n) {
  assert(m <= LIMIT && n <= LIMIT);
  ncall++;
  int r = cacheM[m][n];  // recall
  if (r == 0) {  // not computed yet...
    if (m ==0 || n == 0) {
      r = 1;
    } else {
      nadd += 2;
      r = delannoyM(m-1, n) + delannoyM(m-1, n-1) + delannoyM(m, n-1);
    }
    cacheM[m][n] = r;  // store new
  }
  return r;
}

int delannoyPD(int m, int n) {
  ncall++;
  int mem[1+m][1+n];
  
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == 0 || j == 0) {
        mem[i][j] = 1;
      } else {
        //printf("(%d,%d)\n", i, j);  // debuging
        assert(mem[i-1][j] > 0);
        assert(mem[i-1][j-1] > 0);
        assert(mem[i][j-1] > 0);
        nadd += 2;
        mem[i][j] = mem[i-1][j] + mem[i-1][j-1] + mem[i][j-1];
      }
    }
  }
  return mem[m][n];
}

static inline int max(int a, int b) { return a >= b ? a : b; }
static inline int min(int a, int b) { return a <= b ? a : b; }

// PD Memoizada

// cache para delannoyPDM:
static int cachePDM[1+LIMIT][1+LIMIT] = {{1}};  // everything else = 0
static int m_cache = 0;  // last row filled in cachePDM
static int n_cache = 0;  // last col filled in cachePDM
// INVARIANT: cachePDM[i][j] filled for all i < m_cache and j < n_cache

void update_cache(int i, int j) {
  if (i == 0 || j == 0) {
    cachePDM[i][j] = 1;
  } else {
    //printf("(%d,%d)\n", i, j);  // debuging
    assert(cachePDM[i-1][j] > 0);
    assert(cachePDM[i-1][j-1] > 0);
    assert(cachePDM[i][j-1] > 0);
    nadd += 2;
    cachePDM[i][j] = cachePDM[i-1][j] + cachePDM[i-1][j-1] + cachePDM[i][j-1];
  }
}

int delannoyPDM(int m, int n) {
  assert(m <= LIMIT && n <= LIMIT);
  ncall++;
  int mmax = max(m, m_cache);
  int nmax = max(n, n_cache);
  for (int i = m_cache+1; i <= mmax; i++)
    for (int j = 0; j <= n_cache; j++)
      update_cache(i, j);
  m_cache = mmax;
  for (int i = 0; i <= mmax; i++)
    for (int j = n_cache+1; j <= nmax; j++)
      update_cache(i, j);
  n_cache = nmax;
  return cachePDM[m][n];
}


void printMatrix(int a[][1+LIMIT], int m, int n) {
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      printf("%7d ", a[i][j]);
    }
    printf("\n");
  }
}


// test all funcs for (m, n)
void test(int m, int n) {
  int res;
 
  printf("\n%-7s\t%4s\t%4s\t%12s\t%12s\t%12s\n", "Method", "m", "n", "del(m,n)", "nadd", "ncall");
  
  if (m <= 13 && n <= 13) {  // avoid long waits!
  nadd = 0l; ncall = 0l;
  res = delannoyR(m, n);
  printf("%-7s\t%4d\t%4d\t%12d\t%12ld\t%12ld\n", "R", m, n, res, nadd, ncall);
  }

  nadd = 0l; ncall = 0l;
  res = delannoyM(m, n);
  printf("%-7s\t%4d\t%4d\t%12d\t%12ld\t%12ld\n", "RM", m, n, res, nadd, ncall);
  
  nadd = 0l; ncall = 0l;
  res = delannoyPD(m, n);
  printf("%-7s\t%4d\t%4d\t%12d\t%12ld\t%12ld\n", "PD", m, n, res, nadd, ncall);

  nadd = 0l; ncall = 0l;
  res = delannoyPDM(m, n);
  printf("%-7s\t%4d\t%4d\t%12d\t%12ld\t%12ld\n", "PDM", m, n, res, nadd, ncall);

}

int main(int argc, char* argv[]) {
  switch (argc) {
    case 1:
      error(1, 0, "Usage: %s m,n ...\n", argv[0]);
  }

  for (int k = 1; k < argc; k++) {
    int m, n;
    if (sscanf(argv[k], "%d,%d", &m, &n) != 2) {
      error(2, 0, "Invalid arg: %s", argv[k]);
    }
    test(m, n);

    printMatrix(cachePDM, m, n);
  }

  return 0;
}

