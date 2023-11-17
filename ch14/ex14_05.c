/*
14.5 (Signal Handling)
Read the documentation for your compiler to determine what signals are supported by the
signal-handling library ( <signal.h> ). Write a program that contains signal handlers
for the standard signals SIGABRT and SIGINT . The program should test the trapping of
these signals by calling function abort to generate a signal of type SIGABRT and by
having the user type <Ctrl> c (<control> C on OS X) to generate a signal of type SIGINT.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>//for alarm

//declare signal handlers
void handleSIGABRT(int signalValue);
void handleSIGINTnSIGALRM(int signalValue);

int main (int argc, char *argv[])
{
	//register signal handlers
	signal(SIGINT, handleSIGINTnSIGALRM);
	signal(SIGALRM, handleSIGINTnSIGALRM);
	srand(time(NULL));
	//let's issue random numbers [0 .. 999]
	alarm(2);
	int num = 0;
	do {
		num = rand() % 1000;
		printf("Number %d has been generated\n", num);
		/*//I've commented out this piece of code to test SIGINT and SIGALRM
		if (num == 500) {
			raise(SIGABRT);
		}
		*/
	} while (1);
	//raise SIGABRT when 0 is issued
	//send SIGINT via shell by Ctrl+C
	return 0;
}
void handleSIGABRT(int signalValue) {
	printf("%s%d%s\n", "\nAbort signal (", signalValue, ") received. Aborting...");
	/* Now reraise the signal. We reactivate the signal’s
	default handling, which is to terminate the process.
	We could just call exit or abort,
	but reraising the signal sets the return status
	from the process correctly. */
	signal(signalValue, SIG_DFL);
	raise(signalValue);
}

//define signal handlers
void handleSIGINTnSIGALRM(int signalValue) {
	if (signalValue == SIGINT) {
		printf("%s%d%s\n", "\nInterrupt signal (", signalValue, ") received.");
	} else if (signalValue == SIGALRM) {
		printf("%s%d%s\n", "\nAlarm signal (", signalValue, ") received.");
	} else {
		exit(EXIT_FAILURE);
	}
	
	puts("Do you wish to continue (1 = yes or 2 = no)? ");
	int response; // user's response to signal (1 or 2)
	scanf("%d", &response);
	
	// check for invalid responses
	while (response != 1 && response != 2) {
		puts("Do you wish to continue (1 = yes or 2 = no)? ");
		scanf("%d", &response);
	}
	
	// determine whether it's time to exit
	if (response == 1) {
		// reregister signal handler for next SIGINT/SIGALRM
		signal(SIGINT, handleSIGINTnSIGALRM);
	}
	else {
		exit(EXIT_SUCCESS);
	}
}