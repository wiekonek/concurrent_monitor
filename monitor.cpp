#include "monitor.h"


Monitor::Monitor(const Data &data)
{
    this->data = new Data(data);
}

void Monitor::EnqueueAsync(int resource)
{
    pthread_mutex_lock(&data_mutex);
    while(data->available >= data->capacity)
        pthread_cond_wait(&cond_available_space, &data_mutex);

    data->array[data->current_index_in] = resource;
    data->available++;
    data->current_index_in = (data->current_index_in + 1) % data->capacity;

    pthread_cond_signal(&cond_available_resource);
    pthread_mutex_unlock(&data_mutex);
}

int Monitor::DequeueAsync()
{
    int dequeue;

    pthread_mutex_lock(&data_mutex);
    while(data->available < 1)
        pthread_cond_wait(&cond_available_resource, &data_mutex);

    dequeue = data->array[data->current_index_out];
    data->array[data->current_index_out] = -1;
    data->available--;
    data->current_index_out = (data->current_index_out + 1) % data->capacity;

    pthread_cond_signal(&cond_available_space);
    pthread_mutex_unlock(&data_mutex);

    return dequeue;
}
