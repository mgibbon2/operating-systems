#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <pthread.h>

#define MAX 1024
#define NUM_THREAD 4

int n1,n2;
char *s1,*s2;
FILE* fp;

// used when passing args to threads
typedef struct {
    int charIndex;
    int* substringCountAddr;
} ThreadArgs;

// reads file w/ new line characters
int readf(FILE *fp, char* fileName) {
	if((fp=fopen(fileName, "r"))==NULL){
		printf("ERROR: can't open %s!\n", fileName);
		return 0;
	}
	s1=(char *)malloc(sizeof(char)*MAX);
	if(s1==NULL){
		printf("ERROR: Out of memory!\n");
		return -1;
	}
	s2=(char *)malloc(sizeof(char)*MAX);
	if(s2==NULL){
		printf("ERROR: Out of memory\n");
		return -1;
	}
	/*read s1 s2 from the file*/
	s1=fgets(s1, MAX, fp);
	s2=fgets(s2, MAX, fp);
	n1=strlen(s1)-1;  /*length of s1*/
	n2=strlen(s2)-1; /*length of s2*/
	
	if(s1==NULL || s2==NULL || n1<n2)  /*when error exit*/
		return -1;
}

void* threadFunction(void* arg) {
	ThreadArgs* args = (ThreadArgs*)arg;

    int charIndex = args->charIndex;
    int* substringCountAddr = args->substringCountAddr;

	do {
		bool weIncrement = true;
		for (int i = 0; i < n2; i++) {
			if (s1[charIndex + i] != s2[i]) {
				weIncrement = false;
			}
		}
		if (weIncrement) {
			(*substringCountAddr)++;
		}
		charIndex += NUM_THREAD;
	}
	while (charIndex <= n1 - n2);

	// important to free args in threadFunction not main
	free(args);
	pthread_exit(NULL);
}

int num_substring() {
	int substringCount = 0;
    pthread_t threads[NUM_THREAD];
	ThreadArgs *args;

    for (int i = 0; i < NUM_THREAD; i++) {
		// only way I figured out how to pass args to threads
        args = (ThreadArgs *)malloc(sizeof(ThreadArgs));
        if (args == NULL) {
            printf("ERROR: Out of memory!\n");
            exit(EXIT_FAILURE);
        }
        args->charIndex = i;
        args->substringCountAddr = &substringCount;

        pthread_create(&threads[i], NULL, threadFunction, (void *)args);
    }

	for (int i = 0; i < NUM_THREAD; i++) {
        pthread_join(threads[i], NULL);
    }

    return substringCount;
}

int main() {
	printf("\n----------------------------\n       BEGIN TEST 0\n----------------------------\n\n");
	readf(fp, "strings.txt");
	printf("s1 = %ss2 = %sExpected number of substrings: %d\n\n", s1, s2, 4);
	printf("The number of substrings is: %d\n", num_substring());

	printf("\n----------------------------\n       BEGIN TEST 1\n----------------------------\n\n");
	readf(fp, "strings1.txt");
	printf("s1 = %ss2 = %sExpected number of substrings: %d\n\n", s1, s2, 2);
	printf("The number of substrings is: %d\n", num_substring());

	printf("\n----------------------------\n       BEGIN TEST 2\n----------------------------\n\n");
	readf(fp, "strings2.txt");
	printf("s1 = %ss2 = %sExpected number of substrings: %d\n\n", s1, s2, 3);
	printf("The number of substrings is: %d\n", num_substring());

	printf("\n----------------------------\n       BEGIN TEST 3\n----------------------------\n\n");
	readf(fp, "strings3.txt");
	printf("s1 = %ss2 = %sExpected number of substrings: %d\n\n", s1, s2, 0);
	printf("The number of substrings is: %d\n", num_substring());

	return 1;
}