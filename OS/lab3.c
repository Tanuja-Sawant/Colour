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
        
        for(i=0;i<1024;i++) result[i]=0;

        for(i=0;i<4;i++)
        {
            child=fork();
            
            if(child == 0)
            {
                l++;
                if(l == 2)
                {

                    int j;
                  //  for(j=0;j<100000000;j++){}
                    j=0;
                    while(1==1){
                        if(result[l*10+j]==0){
                            result[l*10+j]=getpid();
                            break;
                        }
                        else{
                            j++;
                        }
                    }
                    printf("Grandchild dead\n");
                    
                    exit(0);
                }
                

                
                //--printf("in the child:%d,parent:%d\nlevel:%d\n",getpid(),getppid(),i);
                
            }
            else
            {
                printf("in the parent:%d,child:%d level:%d\n",getpid(),child,l);
                
                
            }
            
            
            
        }

        if(l == 0){
                    int j;
                    for(j=0;j<10000000;j++){}
                    j=0;
                    while(result[20+j]!=0){
                        printf("Grandchilden:%d  ",result[20+j]);
                        j++;
                    }
                    printf("\n");

                }

        
        

    }