#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 12

char buffer[BUFFER_SIZE];  // Circular buffer to store characters
int count = 0;  // Number of items in the buffer
int in = 0;  // Index for the producer to write
int out = 0;  // Index for the consumer to read
int producer_finished = 0; // Flag to indicate producer finished

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;  // Mutex for thread synchronization
pthread_cond_t cond_producer = PTHREAD_COND_INITIALIZER;  // Condition variable for the producer
pthread_cond_t cond_consumer = PTHREAD_COND_INITIALIZER;  // Condition variable for the consumer

// Function prototypes
void *producer(void *arg);
void *consumer(void *arg);

int main() {
    pthread_t producer_thread, consumer_thread;

    // Create threads
    if(pthread_create(&producer_thread, NULL, producer, NULL) != 0) {
        perror("Error creating producer thread");
        exit(1);
    }
    if(pthread_create(&consumer_thread, NULL, consumer, NULL) != 0) {
        perror("Error creating consumer thread");
        exit(1);
    }

    // Join threads
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    return 0;
}

// Producer thread function
void *producer(void *arg) {
    FILE *file;
    char ch;

    // Open file for reading
    if ((file = fopen("message.txt", "r")) == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Read characters from the file until end of file
    while ((ch = fgetc(file)) != EOF) {
        // Lock mutex to access shared resources
        pthread_mutex_lock(&mutex);

        // Wait if buffer is full
        while (count == BUFFER_SIZE) {
            pthread_cond_wait(&cond_producer, &mutex);
        }

        // Write character to buffer
        buffer[in] = ch;
        in = (in + 1) % BUFFER_SIZE;
        count++;

        // Signal consumer that there's data available
        pthread_cond_signal(&cond_consumer);

        // Unlock mutex
        pthread_mutex_unlock(&mutex);
    }

    // Set producer_finished flag
    pthread_mutex_lock(&mutex);
    producer_finished = 1;
    pthread_cond_signal(&cond_consumer);
    pthread_mutex_unlock(&mutex);

    // Close file
    fclose(file);

    // Exit thread
    pthread_exit(NULL);
}

// Consumer thread function
void *consumer(void *arg) {
    while (1) {
        // Lock mutex to access shared resources
        pthread_mutex_lock(&mutex);

        // Wait if buffer is empty and producer hasn't finished
        while (count == 0 && !producer_finished) {
            pthread_cond_wait(&cond_consumer, &mutex);
        }

        // Break out of loop if producer finished and buffer is empty
        if (producer_finished && count == 0) {
            pthread_mutex_unlock(&mutex);
            break;
        }

        // Read character from buffer and print
        printf("%c", buffer[out]);
        out = (out + 1) % BUFFER_SIZE;
        count--;

        // Signal producer that there's space available
        pthread_cond_signal(&cond_producer);

        // Unlock mutex
        pthread_mutex_unlock(&mutex);
    }

    // Exit thread
    pthread_exit(NULL);
}




