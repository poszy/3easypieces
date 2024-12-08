
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include <assert.h>

int main (int argc, char *argv[]){

  int *p = malloc(sizeof(int)); // malloc allocates memory, assignes it to p a1

  assert(p !=  NULL);
  printf(" (%d) address pointed to by p : %p\n", getpid(), p); //a2

  *p=0;// a3
  
  while(1) {

    Spin(1);
    *p = *p + 1;
    printf("(%d) [: %d\n", getpid(), *p); //a4

  }

  return 0;


}
//
//a1 allocated new memory
//a2 prints out the address of the memory 
//a3 puts a number 0 in that new allocated memory
//a4 then delays one second while incremending the value in the memory address

// if we run this multiple times, we will have two process ID's while the p gets updated in each program seperatley
// it will not interfere with each other.
/*

  prompt> ./mem & ./mem &
[1] 24113
[2] 24114
(24113) address pointed to by p: 0x200000
(24114) address pointed to by p: 0x200000
(24113) p: 1
(24114) p: 1
(24114) p: 2
(24113) p: 2
(24113) p: 3
(24114) p: 3
(24113) p: 4
(24114) p: 4

*/
