#include "producerconsumer.h"
#include <unistd.h>
#include <iostream>

int ProducerConsumer::productNumber = 0;

void *ProducerConsumer::producer(void* monitorArg)
{
    Monitor *monitor = (Monitor *) monitorArg;
    while(productNumber < STEPS) {
        std::cout << "Created: " << productNumber << std::endl;
        monitor->EnqueueAsync(productNumber++);
        sleep(1);
    }
}

void *ProducerConsumer::consumer(void* monitorArg)
{
    Monitor *monitor = (Monitor *) monitorArg;
    while(true) {
        std::cout << "Dequeued: " << monitor->DequeueAsync() << std::endl;
        sleep(7);
    }
}

