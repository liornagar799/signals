#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void sig_handler(int signum)
{
	int i=5;
	int j=0;
	int k;
	switch (signum) {
		case SIGCHLD:
			printf("I am in sighandler1 - process of the child ended\n");
			fflush(stdout);
			raise(SIGUSR1);
		case SIGUSR1: 
			printf("I am in sighandler2 - Sends a signal to the calling thread.\n");
			fflush(stdout);
			k=i/j;
		case SIGFPE:
			printf("I am in sighandler3 - division by 0\n");
			fflush(stdout);
			int arr[2];
            arr[3] = 10;
			
		case SIGSEGV:	
		     printf("I am in sighandler4 - Unallocated memory access\n");
			 fflush(stdout);
			 alarm(2);

		case SIGALRM:
		    printf("I am in sighandler5 - alarm\n");
			fflush(stdout);	
			exit(1);
			}
}

int main()
{
	int status;
    // when the process of the child ended
	signal (SIGCHLD, sig_handler);
	//Sends a signal to the calling thread.
	signal (SIGUSR1, sig_handler);
    // Defective arithmetic operation - division by 0
	signal (SIGFPE, sig_handler);
	// Unallocated memory access
	signal ( SIGSEGV, sig_handler);
    // alarm
    signal(SIGALRM, sig_handler);
	if (!(fork())) {
		exit(1);
	}
	wait(&status);

}