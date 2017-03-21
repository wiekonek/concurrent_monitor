#ifndef PRODUCERCONSUMER_H
#define PRODUCERCONSUMER_H

#include "monitor.h"

#define STEPS 1000

class ProducerConsumer
{
public:
    static void * producer(void *monitorArg);
    static void * consumer(void *monitorArg);
private:
    static int productNumber;
};

#endif // PRODUCERCONSUMER_H
