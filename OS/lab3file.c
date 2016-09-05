    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/types.h>
    #include <sys/ipc.h>
    #include <sys/shm.h>


    
    int main(){

       fclose(fopen("test.txt", "w"));
       FILE *fp;
       fp = fopen("test.txt", "a");

       fprintf(fp, "%d\n", 34);
       fprintf(fp, "%d\n", 45);

       fclose(fp);

       
   
    FILE* file = fopen("test.txt", "r"); /* should check the result */
    char line[256];

    while (fgets(line, sizeof(line), file)) {
        /* note that fgets don't strip the terminating \n, checking its
           presence would allow to handle lines longer that sizeof(line) */
        printf("%d", atoi(line)); 
    }
    /* may check feof here to make a difference between eof and io failure -- network
       timeout for instance */

    fclose(file);


    }