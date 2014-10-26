#include <stdio.h>
#include <string.h>

#define QUEUE_ELEMENTS 	100
#define QUEUE_SIZE 	(QUEUE_ELEMENTS + 1)
char Queue[QUEUE_SIZE];
int queueIn, queueOut;

void queueInit(void)
{
	queueIn = queueOut = 0;
}

int enqueue(char new)
{
	if(queueIn == ((queueOut - 1 + QUEUE_SIZE) % QUEUE_SIZE))
	{
		return -1; /* Queue Full */
	}
	
	Queue[queueIn] = new;
	queueIn = (queueIn + 1) % QUEUE_SIZE;

	return 0; // No errors;
}

int dequeue(int *old)
{
	if(queueIn == queueOut)
		return -1; /* Queue empty - nothing to get */
	
	*old = Queue[queueOut];
	queueOut = (queueOut + 1) % QUEUE_SIZE;

	return 0;
}

int main(){
	char * line;
	
	while (strcmp(line , "exit")){
		fgets(line, 1024, stdin);
	}
}
