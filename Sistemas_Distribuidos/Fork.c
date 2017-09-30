
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


int main(){
    pid_t cpid, w, fpid;
    int status, status2, i;

    cpid = fork();

    do{
        if (cpid == 0){
            printf("Child PID is %ld\n", (long) getpid());
            
            fpid = getppid();
            
            pidof();

        }
        else{
            printf("Parent PID is %ld\n", (long) getpid());

            //waitpid(cpid, &status, WUNTRACED | WCONTINUED);
            exit(EXIT_SUCCESS);

            //cpid = fork();
        }
    }while(1);
}
