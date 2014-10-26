#include <stdio.h>
#include <string.h>

#define QUEUE_ELEMENTS 	100
#define QUEUE_SIZE 	(QUEUE_ELEMENTS + 1)

const char * DELIMS = " \n";
char Queue[QUEUE_SIZE];
int queueIn, queueOut;
int parse(char *inputLine, char *arguments[], const char *delimters);
void printQueue(void);

void printQueue(void)
{
    int i;
    for(i = 0; i < QUEUE_SIZE; i++)
        printf("[%c]", Queue[i]);
    putchar('\n');
}

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

int dequeue(char * old)
{
    if(queueIn == queueOut)
            return -1; /* Queue empty - nothing to get */
    
    *old = Queue[queueOut];
    queueOut = (queueOut + 1) % QUEUE_SIZE;

    return 0;
}

int parse(char *inputLine, char *arguments[], const char *delimiters)
{
    int count = 0;
    char * p;
    for (p = strtok(inputLine, delimiters); p != NULL; p = strtok(NULL, delimiters))
    {
        arguments[count] = p;
        count++;
    }
    arguments[count] = NULL;
    return count;
}

int main(){
    char * line;
    char * args[10];
     
    printf("> ");
    fgets(line, 1024, stdin);
    while (strcmp(line , "exit\n") != 0){
        printf("> ");
        fgets(line, 1024, stdin);
        int argc = parse(line, args, DELIMS);
        if (argc > 1)
        {   
            if (strcmp(args[0], "enqueue") == 0)
            {   
                enqueue(args[1][0]);
                printQueue();
            }
        }
    }
}
