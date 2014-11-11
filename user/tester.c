// Do not modify this file. It will be replaced by the grading scripts
// when checking your project.

#include "types.h"
#include "stat.h"
#include "user.h"
void testprint(void *args){
  printf(1, "%s", "** In the cloned child! **\n");
}
int
main(int argc, char *argv[])
{
  printf(1, "%s", "** Placeholder program for grading scripts **\n");
  void (*func)(void*);
  func = &testprint;
  thread_create(func, (void *)NULL);
  exit();
}
