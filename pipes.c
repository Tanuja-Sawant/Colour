#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

int main(int argc, char **argv){

	int cpid; 
	int status;
	int fd[2];
    	int val = 0;

    pipe(fd);
	
	cpid= fork();

	if(cpid == 0){
		cpid= fork();
		if(cpid != 0){
			cpid= fork();
			if(cpid != 0){
				cpid= fork();
				if(cpid != 0){ // two
					printf("I am %d Child is %d \n", getpid(),cpid);
		
					int w = waitpid(cpid, &status,WNOHANG);
					while(w==0){
						w = waitpid(cpid, &status,WNOHANG);
						
						// now read the data (will block)
						read(fd[0], &val, sizeof(val));
						printf("Parent(%d) received value: %d\n", getpid(), val);

						// close the read-descriptor
						close(fd[0]);
					}
					printf("Exited Now");
					printf("Status %p \n",&status);
				}
				else{ // five


					int i,j;
					for(i=0;i<10000;i++){
						for(j=0;j<10000;j++){
						}
					}					
					printf("I am %d Child is %d Excited\n", getpid(),cpid);
					

					close(fd[0]);
					// send the value on the write-descriptor.
					val = 100;
					write(fd[1], &val, sizeof(val));					
					// close the write descriptor
					close(fd[1]);


				}
			}
			else{ // four
				printf("I am %d Child is %d \n", getpid(),cpid);

					close(fd[0]);
					// send the value on the write-descriptor.
					val = 1000;
					write(fd[1], &val, sizeof(val));					
					// close the write descriptor
					
			}
		}
		else{ // three
			printf("I am %d Child is %d \n", getpid(),cpid);
		}
	}
	else{ // one
		printf("I am %d Child is %d \n", getpid(),cpid);
	}
		


return 0;

}

