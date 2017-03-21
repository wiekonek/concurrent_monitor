#ifndef DATA_H
#define DATA_H

class Data
{
public:
    Data(int capacity, int init_value = 0);
    Data(const Data &data);

    const int capacity;
    int current_index_in = 0;
    int current_index_out = 0;
    int available = 0;
    int *array;
};

#endif // DATA_H
