#ifndef MONITOR_H
#define MONITOR_H

#include <pthread.h>
#include "data.h"

class  Monitor
{
public:
    Monitor(const Data &data);
    void EnqueueAsync(int resource);
    int DequeueAsync();
private:
    Data *data;
    pthread_mutex_t data_mutex = PTHREAD_MUTEX_INITIALIZER;
    pthread_cond_t cond_available_space = PTHREAD_COND_INITIALIZER;
    pthread_cond_t cond_available_resource = PTHREAD_COND_INITIALIZER;
};

#endif // MONITOR_H
