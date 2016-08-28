<<<<<<< HEAD
	 #include <sys/types.h>
	  #include <unistd.h>
	  #include <stdio.h>
	int main(int argc, char **argv){


	/*
	   char *myName = argv[1];
	   int cpid = fork();
	   if (cpid == 0) {
	     printf("The child of %s is %d\n", myName, getpid());
	     exit(0);}
	   else { 
	 	printf("My child is %d\n", cpid); exit(0);
		}
	*/


	/*
		
		
		int cpid,i; 
		for(i=0;i<3;i++){
			cpid= fork();
			if(cpid!=0){
				printf("I am %d My child is %d at level %d \n ",getpid(),cpid,i);
			}
		}
	*/		
		
		
	int cpid; 
			cpid= fork();

			if(cpid!=0){  // one
				printf("I am %d My child is %d one \n ",getpid(),cpid);
			}
			else{
				cpid= fork();
				if(cpid!=0){ 
					cpid= fork();
					if(cpid!=0){   // two & five
						cpid= fork();
						if(cpid!=0){  // two
							wait();
							printf("I am %d My child is %d two \n ",getpid(),cpid);
						}
						else{ // five
								printf("I am %d My child is %d five \n ",getpid(),cpid);
						}
					}
					else{ // four
							printf("I am %d My child is %d four \n ",getpid(),cpid);
					}

				}
				else{ // three
						printf("I am %d My child is %d three \n ",getpid(),cpid);
				}


			}


		
		//	printf("I am %d My child is %d \n ",getpid(),cpid);


		/*char *myName = argv[1];
		int cpid= fork();
		if(cpid == 0){
			printf("0");
			exit(0);
		}
		else{printf("1");
		exit(0);
		}*/
		

		/*
		char *myName = argv[1];
		int cpid= fork();
		if(cpid == 0){
			
			for()
			printf("0");
			exit(0);
		}
		else{
			
			printf("1");
		exit(0);
		}
		*/
		
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
=======
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
>>>>>>> c93e59a6a420f546152c4f4e06f395a039e361a6
