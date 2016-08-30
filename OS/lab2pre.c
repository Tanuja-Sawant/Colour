#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main(int argc, char * argv[]){
	key_t key;
	int shmid;
	int *data;
	int mode,j,k,tem;
	int cpid,status;

	key = 9988;

	if((shmid = shmget(key, SHM_SIZE, 0644 | IPC_CREAT)) == -1){
		perror("shmget");
		exit(1);
	}

	data = shmat(shmid, (void *)0, 0);
	if ( data == (int *) (-1)){
		perror("shmat");
		exit(1);
	}

    pid_t child;
    int i,l=0;

    for(i=0;i<10;i++){
    	data[i]=0;
    }
    
    for(i=0;i<3;i++)
    {
        child=fork();
        if(child == 0)
        {
        	l++;
          //  printf("in the child:%d,parent:%d\nlevel:%d\n",getpid(),getppid(),i);
            
        }
        else
        {
            printf("I am :%d, child is :%d level:%d\n",getpid(),child,l);
        }

        if(l==2){
        	data[0]++;
        	printf("dead\n");
        	exit(0);
        }

        
        
    }

    if(l==0){
        	while(1==1){

        		if(data[0]>=1)
        			break;

        	}
        	printf("Grandchildren dead\n");
        	exit(0);
        	
        }

    
    

}