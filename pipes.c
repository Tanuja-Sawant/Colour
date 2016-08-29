#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

int main(int argc, char **argv){

	int cpid,gpid1,gpid2,gpid3; 
	int status;
	int fd[2];
    	int val = 0;

    pipe(fd);
	
	cpid= fork();

	if(cpid == 0){
		gpid1= fork();
		if(gpid1 != 0){
			gpid2= fork();
			if(gpid2 != 0){
				gpid3= fork();
				if(gpid3 != 0){ // two
					printf("I am %d Child is %d \n", getpid(),cpid);
		
					int w=0,a,b,c;
					while(w==0){

						a = waitpid(gpid1, &status,WNOHANG);
						b = waitpid(gpid2, &status,WNOHANG);
						c = waitpid(gpid3, &status,WNOHANG);
						w=(a&&b)||(b&&c)||(a&&c);
						//printf("%d  \n",w);

						
						// send the value on the write-descriptor.
						val = w;
						write(fd[1], &val, sizeof(val));					
						// close the write descriptor
						
					}
					
					//printf("Status %p \n",&status);
				}
				else{ // five


					int i,j;
					for(i=0;i<90000;i++){
						for(j=0;j<10000;j++){
						}
					}					
					//printf("I am %d Child is %d Excited\n", getpid(),cpid);
					printf("Dead!\n");
				}
			}
			else{ // four

									int i,j;
					for(i=0;i<50000;i++){
						for(j=0;j<10000;j++){
						}
					}	

				//printf("I am %d Child is %d \n", getpid(),cpid);					
				printf("Dead!\n");
			}
		}
		else{ // three

					int i,j;
					for(i=0;i<100000;i++){
						for(j=0;j<10000;j++){
						}
					}	

			//printf("I am %d Child is %d \n", getpid(),cpid);
			printf("Dead!\n");
		}
	}
	else{ // one
		//printf("I am %d Child is %d \n", getpid(),cpid);
		while(val!=1){
			read(fd[0], &val, sizeof(val));
			if(val)
			printf("Two are dead\n");
		// close the read-descriptor		
		}
		exit(0);


	}
		


return 0;

}
