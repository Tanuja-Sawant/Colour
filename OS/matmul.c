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
	int mode,i,j,k,tem;
	int cpid,status;

	key = 9988;
	int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	int b[3][3]={{2,2,3},{8,4,3},{5,7,9}};
	int c[3][3];



	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf(" %d ",a[i][j]);
		}
		printf(" \n");
	}
	printf(" \n");


	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf(" %d ",b[i][j]);
		}
		printf(" \n");
	}
	printf(" \n");


	if((shmid = shmget(key, SHM_SIZE, 0644 | IPC_CREAT)) == -1){
		perror("shmget");
		exit(1);
	}

	data = shmat(shmid, (void *)0, 0);
	if ( data == (int *) (-1)){
		perror("shmat");
		exit(1);
	}
	

	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			for(k=0;k<3;k++){
					cpid= fork();
					if(cpid== 0){
						data[k]=a[i][k]*b[k][j];
				//		printf("%d %d\n",data[k],k);
				//		printf("%d %d %d %d done\n",i,j,k,getpid());
						exit(0);
					}

			}
			wait();
			wait();
			wait();
		//	printf("%d %d %d done\n",i,j,getpid());
			c[i][j]=data[0]+data[1]+data[2];
		}
	}

	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf(" %d ",c[i][j]);
		}
		printf(" \n");
	}

	/*

	cpid1= fork();
	cpid2= fork();
	cpid3= fork();


	if(cpid1 == 0){
		
		data[1]=a+b;
	}
	else{
		wait();
		printf("%d\n",data[1]);
		
	}


	*/
	return 0;
}