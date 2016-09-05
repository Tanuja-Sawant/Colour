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

        for(i=0;i<3;i++)
        {
            child=fork();
            
            if(child == 0){
                l++;
                    int j;
                   // for(j=0;j<100000000;j++){}
                    j=0;
                    while(1==1){
                        if(result[j]==0){
                          //  printf("Grandchild dead\n"); 
                            result[j]=getpid();
                            result[j+1]=getppid();
                            break;
                        }
                        else{
                            j=j+2;
                        }
                    }
                    
                    
            }
            else{
               // printf("In the parent:%d,child:%d level:%d\n",getpid(),child,l);    
            }
            
            
            
        }

        if(l == 0){
                    int j;
                    for(j=0;j<100000000;j++){}

                        j=0;
                        while(result[j]!=0){
                            printf("child is:%d  parent is: %d \n",result[j], result[j+1]);
                            j=j+2;
                        }
                      // printf("%d",j);
                }

        
        

    }