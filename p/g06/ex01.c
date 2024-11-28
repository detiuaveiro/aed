#include <stdio.h>
#include <assert.h>
#include <error.h>

// Para instrumentar funções:
size_t nadd = 0;  // number of additions
size_t ncall = 0;  // number of calls (recursive + 1)

// Recursive
size_t delannoyR(size_t m, size_t n) {
  ncall++;
  size_t r;
  if (m ==0 || n == 0) {
    r = 1;
  } else {
    nadd += 2;
    r = delannoyR(m-1, n) + delannoyR(m-1, n-1) + delannoyR(m, n-1);
  }
  return r;
}

#define LIMIT 100
static size_t cacheM[1+LIMIT][1+LIMIT] = {{0}}; // everything else = 0

// Recursive Memoized
size_t delannoyM(size_t m, size_t n) {
  assert(m <= LIMIT && n <= LIMIT);
  ncall++;
  size_t r = cacheM[m][n];  // recall
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

size_t delannoyPD(size_t m, size_t n) {
  ncall++;
  size_t mem[1+m][1+n];
  
  for (size_t i = 0; i <= m; i++) {
    for (size_t j = 0; j <= n; j++) {
      if (i == 0 || j == 0) {
        mem[i][j] = 1;
      } else {
        //prsize_tf("(%d,%d)\n", i, j);  // debuging
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

static inline size_t max(size_t a, size_t b) { return a >= b ? a : b; }
static inline size_t min(size_t a, size_t b) { return a <= b ? a : b; }

// PD Memoizada

// cache para delannoyPDM:
static size_t cachePDM[1+LIMIT][1+LIMIT] = {{1}};  // everything else = 0
static size_t m_cache = 0;  // last row filled in cachePDM
static size_t n_cache = 0;  // last col filled in cachePDM
// INVARIANT: cachePDM[i][j] filled for all i < m_cache and j < n_cache

void update_cache(size_t i, size_t j) {
  if (i == 0 || j == 0) {
    cachePDM[i][j] = 1;
  } else {
    //prsize_tf("(%d,%d)\n", i, j);  // debuging
    assert(cachePDM[i-1][j] > 0);
    assert(cachePDM[i-1][j-1] > 0);
    assert(cachePDM[i][j-1] > 0);
    nadd += 2;
    cachePDM[i][j] = cachePDM[i-1][j] + cachePDM[i-1][j-1] + cachePDM[i][j-1];
  }
}

size_t delannoyPDM(size_t m, size_t n) {
  assert(m <= LIMIT && n <= LIMIT);
  ncall++;
  size_t mmax = max(m, m_cache);
  size_t nmax = max(n, n_cache);
  for (size_t i = m_cache+1; i <= mmax; i++)
    for (size_t j = 0; j <= n_cache; j++)
      update_cache(i, j);
  m_cache = mmax;
  for (size_t i = 0; i <= mmax; i++)
    for (size_t j = n_cache+1; j <= nmax; j++)
      update_cache(i, j);
  n_cache = nmax;
  return cachePDM[m][n];
}


void prsize_tMatrix(size_t a[][1+LIMIT], size_t m, size_t n) {
  for (size_t i = 0; i <= m; i++) {
    for (size_t j = 0; j <= n; j++) {
      printf("%7ld ", a[i][j]);
    }
    printf("\n");
  }
}


// test all funcs for (m, n)
void test(size_t m, size_t n) {
  size_t res;
 
  printf("\n%-7s\t%4s\t%4s\t%12s\t%12s\t%12s\n", "Method", "m", "n", "del(m,n)", "nadd", "ncall");
  
  if (m <= 13 && n <= 13) {  // avoid long waits!
  nadd = 0l; ncall = 0l;
  res = delannoyR(m, n);
  printf("%-7s\t%4ld\t%4ld\t%12ld\t%12ld\t%12ld\n", "R", m, n, res, nadd, ncall);
  }

  nadd = 0l; ncall = 0l;
  res = delannoyM(m, n);
  printf("%-7s\t%4ld\t%4ld\t%12ld\t%12ld\t%12ld\n", "RM", m, n, res, nadd, ncall);
  
  nadd = 0l; ncall = 0l;
  res = delannoyPD(m, n);
  printf("%-7s\t%4ld\t%4ld\t%12ld\t%12ld\t%12ld\n", "PD", m, n, res, nadd, ncall);

  nadd = 0l; ncall = 0l;
  res = delannoyPDM(m, n);
  printf("%-7s\t%4ld\t%4ld\t%12ld\t%12ld\t%12ld\n", "PDM", m, n, res, nadd, ncall);

}

int main(int argc, char* argv[]) {
  switch (argc) {
    case 1:
      error(1, 0, "Usage: %s m,n ...\n", argv[0]);
  }

  for (size_t k = 1; k < argc; k++) {
    size_t m, n;
    if (sscanf(argv[k], "%ld,%ld", &m, &n) != 2) {
      error(2, 0, "Invalid arg: %s", argv[k]);
    }
    test(m, n);

    prsize_tMatrix(cachePDM, m, n);
  }

  return 0;
}
