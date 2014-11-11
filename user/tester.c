// Do not modify this file. It will be replaced by the grading scripts
// when checking your project.

#include "types.h"
#include "stat.h"
#include "user.h"
int x =0;
void testprint(void *args){
//  int *a = (int *)args;
//  printf(1, "** In the cloned child! a=%d b=%d **\n",a[0],a[1]);
  printf(1, "%s", "** In the child **\n");
  for(;x<3;x++) {
      printf(1, "T2 :: x = %d\n", x);
      sleep(100);
   }
}
int
main(int argc, char *argv[])
{
  printf(1, "%s", "** Placeholder program for grading scripts **\n");
  void (*func)(void*);
  func = &testprint;
  int *arr=(int *) malloc(2*sizeof(int));
  arr[0] = 123;
  arr[1] = 234;
  thread_create(func, (void *)arr);
  join();
  printf(1, "** IN THE PARENT x=%d**\n",x);
// exit();
 return 0;
}
