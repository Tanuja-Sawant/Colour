    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/types.h>
    #include <sys/ipc.h>
    #include <sys/shm.h>

    int main()
    {
        pid_t child;
        int i;
        int l=0;
        const int size = 1024;
        int memid;
        int *result;
        memid=shmget(IPC_PRIVATE,size,0644|IPC_CREAT);
        result=(int *)shmat(memid,NULL,0);
        result[0]=0;

        for(i=0;i<5;i++)
        {
            child=fork();
            
            if(child == 0)
            {
                l++;
                if(l == 2)
                {

                    int i;
                    for(i=0;i<100000000;i++){

                    }
                    result[0]=result[0]+1;
                    printf("Grandchild dead\n");
                    
                    exit(0);
                }
                

                
                //--printf("in the child:%d,parent:%d\nlevel:%d\n",getpid(),getppid(),i);
                
            }
            else
            {
                printf("in the parent:%d,child:%d level:%d\n",getpid(),child,l);
                if(l == 0)
                {
                while(1==1){

                   // printf(" %d ",result[0]);
                    if(result[0]>=3)
                    {

                        printf("Two grandchildren dead\n");
                        printf("   \n %d   \n",result[0]);
                        exit(0);
                            
                    }
                }
            }
                
            }
            
            
            
        }

        
        

    }