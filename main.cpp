#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include "producerconsumer.h"
#include "monitor.h"

using namespace std;

static Monitor monitor(*(new Data(5, -1)));

int main(int argc, char *argv[])
{
    int producerNumber = 1, consumerNumber = 5;

    if(argc > 1)
        producerNumber =  atoi(argv[1]);
    if(argc > 2)
        consumerNumber = atoi(argv[2]);
    for(int i = 0; i < producerNumber; i++) {
        pthread_t producer_thread;
        pthread_create(&producer_thread, NULL, ProducerConsumer::producer, (void *)&monitor);
    }
    for(int i = 0; i < consumerNumber; i++) {
        pthread_t consumer_thread;
        pthread_create(&consumer_thread, NULL, ProducerConsumer::consumer, (void *)&monitor);
    }


    getchar();
    return 0;
}
