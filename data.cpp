#include "data.h"

Data::Data(int capacity, int init_value) : capacity(capacity), array(new int[capacity]) {
    available = 0;

    for(int i = 0; i < capacity; i++) {
        this->array[i] = init_value;
    }
}

Data::Data(const Data &data) : Data(data.capacity) {
    for(int i = 0; i < data.capacity; i++) {
        this->array[i] = data.array[i];
    }
    this->available = data.available;
    this->current_index_in = data.current_index_in;
    this->current_index_out = data.current_index_out;
}
