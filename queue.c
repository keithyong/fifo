#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define QUEUE_ELEMENTS 	100
#define QUEUE_SIZE 	(QUEUE_ELEMENTS + 1)

const char * DELIMS = " \n";
char Queue[QUEUE_SIZE];
int queueIn, queueOut;
int parse(char *inputLine, char *arguments[], const char *delimters);
void printQueue(void);
void printIntro(void);


void printIntro(void)
{
    printf("\n\n");
    printf("+-----------------------+\n");
    printf("| WELCOME TO FIFO QUEUE |\n");
    printf("| By Keith Yong         |\n");
    printf("|                       |\n");
    printf("| - Commands -          |\n");
    printf("| 1. enqueue [char]     |\n");
    printf("| 2. dequeue [char]     |\n");
    printf("| 3. print              |\n");
    printf("| 4. exit               |\n");
    printf("+-----------------------+\n\n\n");
}
void printQueue(void)
{
    int i;
    for(i = queueOut; i <= queueIn; i++)
    {
        if(Queue[i] != '\0')
            printf("[%c]", Queue[i]);
    }
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
    printIntro();
    queueInit();
    char * line;
    char * args[10];
     
    while (1)
    {
        printf("> ");
        fgets(line, 1024, stdin);
        int argc = parse(line, args, DELIMS);

        if (argc > 1)
        {   
            if (strcmp(args[0], "enqueue") == 0)
            {   
                char temp = args[1][0];
                enqueue(temp);
                printf("Enqueued %c to the queue\n", temp);
                printQueue();
            }
        } else if (argc == 1) {
            if (strcmp(args[0], "print") == 0)
            {
                printQueue();
            } else if (strcmp(args[0], "dequeue") == 0) {
                char temp;
                int a = dequeue(&temp);
                
                if (a == -1)
                    printf("Nothing to dequeue");
                else
                    printf("Dequeued %c from the queue\n", temp);

                printQueue();
            }
            else if (strcmp(args[0], "exit") == 0) {
                exit(1);
            } else {
                printf("Command not found\n");
            }
        } 
    }
}
