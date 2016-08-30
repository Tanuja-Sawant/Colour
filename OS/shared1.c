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
	char *data;
	int mode;
/*
	key_t ftok(const char *pathname, int proj_id);
	k=ftok("/my/file",0xaa);


	int shmget(key_t key, size_t size, int shmflg);
	id = shmget(key, size, 0644 | IPC_CREAT);

	void *shmat(int shmid, const void *shmaddr, int shmflg);
	shared_memory = (char *) shmat(id, (void *) 0,0);

	sprintf(shared_memory, "Writing to shared memory");

	int shmdt(const void *shmaddr);
	shmdt(shared_memory);

	*/

	key = 9988;
	/*
	if((key = ftok("shmdemo.c", 'R')) ==-1){
		perror("ftok");
		exit(1);
	}
	*/

	if((shmid = shmget(key, SHM_SIZE, 0644 | IPC_CREAT)) == -1){
		perror("shmget");
		exit(1);
	}

	data = shmat(shmid, (void *)0, 0);
	if ( data == (char *) (-1)){
		perror("shmat");
		exit(1);
	}

	if( argc == 2){
		printf("Writing to segment: \"%s\"\n", argv[1]);
		strncpy(data, argv[1], SHM_SIZE);
	} else
	printf("segment contains: \"%s\"\n",data );

	if(shmdt(data) == -1){
		perror("shmdt");
		exit(1);
	}

		while(1==1){
		sleep(1);
	}

	return 0;
}