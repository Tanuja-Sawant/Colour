#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
int main()
{


	pid_t child;
	
	FILE *fp;
	fp=fopen("new_file_l4.txt","r");
	
	//fprintf(fp,"Greggie <3");
			
			char buf[1];
			int count= 0;
			while (fgets(buf,3,fp)!=NULL)
			{
				printf("%s",buf);
			}
			
			fclose(fp);
	return 0;
}