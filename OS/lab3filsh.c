#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
int main()
{

	fclose(fopen("new_file_l4.txt", "w"));


	pid_t child;
	int gen_num=0;
	int i;
	for(i=0;i<3;i++)
	{
		child=fork();
		if(child == 0)
		{
			gen_num++;
		}
		
	}	
	if(gen_num != 0)
	{
	long long int j;
	for(j=0;j<10000000;j++);



		if(gen_num==2) printf("Goodbye creul World \n");
	FILE *fp;
	fp=fopen("new_file_l4.txt","a+");
	fprintf(fp,"%d",gen_num);
	fclose(fp);
	

	exit(0);


	}

	else
		{
		
		int flag=1; 
		
		while(flag == 1)
		{	char buf[1];
			FILE *fp;
			fp=fopen("new_file_l4.txt","a+");
			int count= 0;
			while (fgets(buf,2,fp)!=NULL)
			{
			//	printf("%s ",buf);
				if(*buf == '2')
				{
					count++;

					if(count == 2)
					{
						//fprintf(fp,"%d",gen_num);
						printf("two grandchildren dead,parent exiting\n");
						fclose(fp);
						flag=0;
						exit(0);	
					}
				}
			}
			
			fclose(fp);
			//printf("parent:can't exit just yet!\n");
		}

		}
}