#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

int main(int argc, char **argv){

	int cpid; 
	int status;
	int     fd[2], nbytes;
    char    string[] = "NO\n";
    char    string2[] = "Yes\n";
    int   readbuffer;

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
						close(fd[1]);

               			 /* Read in a string from the pipe */
               			 nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
               			 printf("Received string: %d \n", readbuffer);
					}
					printf("Exited Now");
					printf("Status %p \n",&status);
				}
				else{ // five

					close(fd[0]);

                	/* Send "string" through the output side of pipe */
               		 write(fd[1],0, sizeof(readbuffer));

					int i,j;
					for(i=0;i<100;i++){
						for(j=0;j<10000;j++){
						}
					}					
					printf("I am %d Child is %d Excited\n", getpid(),cpid);
					close(fd[0]);

                	/* Send "string" through the output side of pipe */
               		 write(fd[1],1, sizeof(readbuffer));
                	exit(0);
				}
			}
			else{ // four
				printf("I am %d Child is %d \n", getpid(),cpid);
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

