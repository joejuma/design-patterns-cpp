# Circular Swap Buffer (Pattern)

## About

The "Circular Swap Buffer" design pattern is a modification of the more common "Circle Buffer" design pattern. A circle-buffer provides an array-like container of static size which loops around after the end back to the front. It is a powerful pattern for efficient stream reading, but may have a separate read and write pointer. The circular swap buffer is a modification of this designed to store only the last n-many values in ascending order of their staleness.

It employs 1 pointer, and is useful for very efficient storage of values by their age such as in a caching chain.

## Where This Pattern May Be Used

Although this pattern is a minor adjustment of a very common pattern, it may be used in a number of places where high performance is key. These include a rolling buffer for large file-streaming, or as a caching structure for linked-list access pointers to reduce graph walking distances.

## Example Explanation

In this example repository:
1. I've created the circular buffer class. (`CircleBuffer_struct.h`) 
2. In the main file I've create an example `buffer` object, printed its size, written to it 100,000,000 times and printed the performance in microseconds using a naive assessment method, then printed 10 elements from it which will loop 2.5 times due to the buffer being 4 elements long. (`main.cpp`)

## Technical Notes
There may be a few confusing or nuanced aspects of C++ in the structure. I'd like to note them here as they may be good educational examples.

1. The `#pragma` statements directly before and after the buffer are to pack byte-alignment. This helps to reduce the structure size.
2. The order of instantiation was chose to improve possible byte-alignment. Though this is most ritualistic due to compiler variations.
3. There is no use of the `virtual` keyword to avoid per-instance v-table pointers. This helps reduce the size of the buffer.

## More Information
1. [Circular Buffer (Wikipedia)](https://en.wikipedia.org/wiki/Circular_buffer)
2. [pragma pack (GNU C++)][https://web.archive.org/web/20250116210423/https://gcc.gnu.org/onlinedocs/gcc-4.4.4/gcc/Structure_002dPacking-Pragmas.html]
3. [Data Structure Alignment (Wikipedia)][https://en.wikipedia.org/wiki/Data_structure_alignment]
4. [Virtual Method Table][https://en.wikipedia.org/wiki/Virtual_method_table]