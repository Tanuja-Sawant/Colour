 #include <sys/types.h>
  #include <unistd.h>
  #include <stdio.h>
int main(int argc, char **argv){
	/*char *myName = argv[1];
	int cpid; 

	for(int i=0;i<3;i++){
		cpid= fork();
	}
	if(cpid == 0){

		printf("0");
		exit(0);
	}
	else{printf("1");

	exit(0);
	}*/

	/*char *myName = argv[1];
	int cpid= fork();

	if(cpid == 0){

		printf("0");
		exit(0);
	}
	else{printf("1");

	exit(0);
	}*/

	/*char *myName = argv[1];
	int cpid= fork();

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
	}*/
	/*
	int gennum = 0;
	int i;
	int cpid;
	for (i = 0; i < 3; i++) {
    	cpid = fork();
    	if (cpid == 0) {
			gennum++;
		}
	}


	printf("%d\t%d\n", getpid(), gennum);
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
