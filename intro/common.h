#ifndef COMMON_H //include guard. prvents the file from being included multiple times in the same project. causes redifinition errors
#define COMMON_H // this ensures the file contents are included only once during compilation

#include <sys/time.h> // provides functions and data structures for working with time, like struct timevale and gettimeofday()


static inline void Spin(int seconds){
  // static ensures the function is local to the file, prventing linkage errors if multiple files include common.h
  // inline suggest the compiler replace the function call with its code to avoid function call overhead.

  struct timeval start, end;
  // declare two variable of type struct timeval,

  gettimeofday(&start,NULL); // pointer to start variable
  // time is stored as start.tv_sec, start.tv_usec
  while(1){
    gettimeofday(&end, NULL);
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;

  if (elapsed >= seconds) { break; }  

  }
  
  
}

#endif // end the ifndef block. ensures the contents of the file are included only once
