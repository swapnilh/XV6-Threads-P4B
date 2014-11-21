// Do not modify this file. It will be replaced by the grading scripts
// when checking your project.

#include "types.h"
#include "stat.h"
#include "user.h"


#define assert(x) if (x) {} else { \
   printf(1, "%s: %d ", __FILE__, __LINE__); \
   printf(1, "assert failed (%s)\n", # x); \
   printf(1, "TEST FAILED\n"); \
   kill(ppid); \
   exit(); \
}


int x =0;
void testprint(void *args);
void worker(void *arg_ptr);
int ppid;
int global = 1;
int
main(int argc, char *argv[])
{
  printf(1, "%s", "** Placeholder program for grading scripts **\n");
//  void (*func)(void*);
//  func = &testprint;
  int arr = 35;
//  printf(1,"Addr=%p\n",sbrk(0));
//  thread_create(testprint, (void *)arr);
  thread_create(worker, &arr);
  join();
//  printf(1,"Addr=%p\n",sbrk(100));
//  printf(1,"Addr=%p\n",sbrk(0));
  printf(1, "** IN THE PARENT x=%d**\n",x);
  exit();
}
void
worker(void *arg_ptr) {
   int arg = *(int*)arg_ptr;
   assert(arg == 35);
   assert(global == 1);
   global++;
   printf(1,"WAS HERE\n");
   return;
}
void testprint(void *args){
//  int *a = (int *)args;
//  printf(1, "** In the cloned child! a=%d b=%d **\n",a[0],a[1]);
  printf(1, "%s", "** In the child **\n");
  printf(1,"Child Addr=%p\n",sbrk(100));
  printf(1,"Child Addr=%p\n",sbrk(0));
  for(;x<1;x++) {
      printf(1, "T2 :: x = %d\n", x);
      sleep(100);
   }
   return;
}

