#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
int main(int argc, char **argv){

	int cpid; 
	int status;
	
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
					}
					printf("Exited Now");
					printf("Status %p \n",&status);
				}
				else{ // five
					
					for(int i=0;i<10000;i++){
						for(int j=0;j<10000;j++){
						}
					}					
					printf("I am %d Child is %d \n", getpid(),cpid);
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
		



	/*
	char *myName = argv[1];
	int cpid= fork();
int count0=0;int  count1=0;
	if(cpid == 0){
		for(int i=0;i<10000;i++){
			for(int j=0;j<10000;j++){
			}
		}
		printf("0");
		
		exit(0);
	}
	else{printf("1");
	exit(0);
	}
	
*/




/*
	int level = 0;
	int i;
	int cpid;
	for (i = 0; i < 3; i++) {
    	cpid = fork();
    	if (cpid == 0) {
			level++;
		}
	}
	printf("%d\t%d\n", getpid(), level);
	exit(0);
*/

	/*int level = 0;
	int i,count=0;
	int cpid;
	for (i = 0; i < 3; i++) {
    	cpid = fork();
    	if (cpid == 0) {
			level++;
			
		}
	}
	
	printf("%d\t%d\n", getpid(), level);
	if(level==2 & count==0){
		//printf("2 grandchildren printed");
		count=-1234;
	}
	exit(0);
	*/
/*
	pid_t pid;
     char *const parmList[] = {NULL};
     if ((pid = fork()) == -1)
        perror("fork error");
     else if (pid == 0) {
        execv("one", parmList);
        printf("Return not expected. Must be an execv error.n");
     }
*/

/*
	pid_t pid;
     char *const parmList;
	printf(" parent %d\n", getpid());
     if ((pid = fork()) == -1)
        perror("fork error ");
    else if (pid == 0) {
    	printf("child %d\n", getpid());
        execlp("python", parmList);
        printf("Return not expected. Must be an execv error.n");
     }
*/
return 0;

}
