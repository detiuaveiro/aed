//
// Tomás Oliveira e Silva, AED, October 2021
//
// code to measure the elapsed time used by a program fragment
//
// use as follows:
//
//   double t1 = cpu_time();
//   // put your code to be time measured here
//   double t2 = cpu_time();
//   printf("elapsed time: %.6f seconds\n",t2 - t1);
//


#if defined(__linux__) || defined(__APPLE__)

//
// GNU/Linux and MacOS code to measure elapsed time
//

#include <time.h>

double cpu_time(void)
{
  struct timespec current_time;

  if(clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&current_time) != 0)  // the first argument could also be CLOCK_REALTIME
    return -1.0; // clock_gettime() failed!!!
  return (double)current_time.tv_sec + 1.0e-9 * (double)current_time.tv_nsec;
}

#endif


#if defined(_MSC_VER) || defined(_WIN32) || defined(_WIN64)

//
// Microsoft Windows code to measure elapsed time
//

#include <windows.h>

double cpu_time(void)
{
  static LARGE_INTEGER frequency;
  static int first_time = 1;
  LARGE_INTEGER current_time;

  if(first_time != 0)
  {
    QueryPerformanceFrequency(&frequency);
    first_time = 0;
  }
  QueryPerformanceCounter(&current_time);
  return (double)current_time.QuadPart / (double)frequency.QuadPart;
}

#endif
