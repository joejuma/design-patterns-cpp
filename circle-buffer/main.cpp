#include <cstdlib>
#include <iostream>
#include <chrono>
#include <string>

#include "CircleBuffer_struct.h"

/* Type Definitions */
typedef std::chrono::time_point<std::chrono::high_resolution_clock> timepoint;

int main(int argc, char* argv[])
{
    // Create the buffer,
    CircleBuffer<uint8_t, 4> buffer;
    
    // Print the size of the buffer,
    std::cout << "Size of CircleBuffer<uint8_t,4>:" << std::to_string(sizeof(CircleBuffer<uint8_t,4>)) << " bytes\n";

    // Time 100 million inserts,
    timepoint start = std::chrono::high_resolution_clock::now();
    for(uint64_t i = 0; i < 100000000; i++)
    {
        buffer.push_back(i);
    };
    timepoint end = std::chrono::high_resolution_clock::now();

    // Log the naive time in microseconds.
    std::cout << "100 Mn inserts: " << std::chrono::duration<double, std::micro>(end - start).count() << " ms\n";
    
    // Print out 10 values, which should loop the buffer 2.5 times starting with the most fresh element.
    for(uint64_t i = 0; i < 10; i++)
    {
        std::cout << std::to_string(buffer[i]) << "\n";
    };

    return 0;
};