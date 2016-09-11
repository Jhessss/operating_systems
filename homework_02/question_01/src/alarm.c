#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

sig_atomic_t flag = 0;

void signal_handler(int signal_number)
{
	flag = 1;
}

int main ()
{
	pid_t alarm_child;
	struct sigaction sa;
	memset(&sa, 0, sizeof(sa));
	sa.sa_handler = &signal_handler;
	sigaction(SIGALRM, &sa, NULL);

	alarm_child = fork();
	if (alarm_child != 0) {
		pause();
	}
	else {
		sleep(5);
		kill(getppid(), SIGALRM);
		exit(0);
	}
	if(flag) {
		printf("Alarme disparado!\n");
	}
	return 0;
}
