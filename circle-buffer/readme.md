# Circular Swap Buffer (Pattern)

## About

The "Circular Swap Buffer" design pattern is a modification of the more common "Circle Buffer" design pattern. A circle-buffer provides an array-like container of static size which loops around after the end back to the front. It is a powerful pattern for efficient stream reading, but may have a separate read and write pointer. The circular swap buffer is a modification of this designed to store only the last n-many values in ascending order of their staleness.

It employs 1 pointer, and is useful for very efficient storage of values by their age such as in a caching chain.

## Where This Pattern May Be Used

Although this pattern is a minor adjustment of a very common pattern, it may be used in a number of places where high performance is key. These include a rolling buffer for large file-streaming, or as a caching structure for linked-list access pointers to reduce graph walking distances.

## Example Explanation

In this example repository:
1. I've created the circular buffer class. (`CircleBuffer_struct.h`) 
2. In the main file I've create an example `buffer` object, written to it 100,000,000 times and printed the output as well as performance in microseconds using a naive assessment method. (`main.cpp`)

## More Information
1. [Circular Buffer (Wikipedia)](https://en.wikipedia.org/wiki/Circular_buffer)