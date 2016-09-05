#include <stdio.h>
#include <unistd.h>

int main(int argc,char* argv[])
{
  int i=0;
  int level=0;
  pid_t cpid ;
for (i=0;i<3;i++)
{
  cpid=fork();
  level++;
  if(cpid==0)
  {
  printf ("Level = %d My cpid is %d and my parent's id is %d\n",level,getpid(),getppid());
  }
  else if(cpid>0)
  {
      wait(NULL);
      level--;
      printf("Level = %d parent %d\n",level,getpid());
      if(level==0 && i==0)
      {
        printf("Two grandchildren have died\nprocess %d signing off adieus\n",getpid());
        //exit(0);
      }
  }
}
}