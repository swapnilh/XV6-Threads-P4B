#include "types.h"
#include "x86.h"
#include "defs.h"
#include "param.h"
#include "mmu.h"
#include "proc.h"
#include "sysfunc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  cprintf("In getpid() esp=%x\n",proc->tf->esp);
  int i=0;
  for(i=proc->tf->esp; i<proc->tf->esp+20; i++)
	  cprintf("stack entry=%x\n",*(char*)i);	 
  return proc->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = proc->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;
  
  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(proc->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since boot.
int
sys_uptime(void)
{
  uint xticks;
  
  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}
int
sys_clone(void)
{ 
  void * stack;	  
  if(argptr(0, (void *)&stack, sizeof(void *)) < 0) //Is the size correct?
    return -1;
  return clone(stack);
}
int
sys_lock(void)
{
/*  int n;
  void *argLock;
  if(argint(0,&n) < 0)
	return -1;
  if(argptr(0, (void *)&argLock, sizeof(void *)) < 0) //FIXME should arglock be of type int directly?
    return -1;
  int *intLock= (int*)argLock;//FIXME this seems redundant

 
  cprintf("Process:%d trying for guard lock\n",proc->pid);
  acquire(&guardlock);
  //acuqire the intLock
  while( xchg((unsigned int*)intLock,1)==1 )
  { 
  cprintf("Child Process:%d failed intlock\n",proc->pid);
   //release(&guardlock);
   //race condition as this releases guardlock and ... don't think so?
   mySleep(&guardlock);
  cprintf("Child Process:%d got woken up\n",proc->pid);
   //acquire(&guardlock);
  }
  cprintf("Process:%d got int lock\n",proc->pid);
  release(&guardlock);
  cprintf("Process:%d left guardlock\n",proc->pid);
  return 0;
  */
	return proc->pid;
}
int
sys_unlock(void)
{
/*  int n;
  void *argLock;
  if(argint(0,&n) < 0)
	return -1;
  if(argptr(0, (void *)&argLock, sizeof(void *)) < 0) //FIXME should arglock be of type int directly?
    return -1;
  int *intLock= (int*)argLock;//FIXME this seems redundant
 
  acquire(&guardlock);
  xchg((unsigned int*)intLock,0);//unlock init lock
  myWakeup();//wake up a sleeping thread
  release(&guardlock);
  return 0;*/
	return proc->pid;
}
int
sys_join(void)
{
  return join();
}
