#pragma once

#ifndef CIRCLE_BUFFER_STRUCT__H
#define CIRCLE_BUFFER_STRUCT__H
/* Deps */
#include <stdint.h>

/* Structures */
#pragma pack(push, 1)
template <typename T, uint8_t SIZE>
struct CircleBuffer
{
	/*
		# Circle Buffer (struct)
		
		## About
		A statically sized buffer which tracks the most recent n-many values 
		added to it. A useful structure for implementing optimized behaviors
		in other data structures and systems.
	*/

	/* Elements */
	T data[SIZE];
	uint8_t ptr;

	/* Methods */
	// Constructors & Destructor
	CircleBuffer()
	{
		this->ptr = 0;
		for (uint64_t i = 0; i < SIZE; i++)
		{
			this->data[i] = T();
		};
	};
	CircleBuffer(const CircleBuffer<T, SIZE>& src)
	{
		this->ptr = src.ptr;
		for (uint64_t i = 0; i < SIZE; i++)
		{
			this->data[i] = src.data[i];
		};
	};
	~CircleBuffer()
	{};

	// Utility Methods
	inline constexpr uint8_t size() const noexcept
	{
		return SIZE;
	};

	// Pointer Methods
	inline void decrementPointer() noexcept
	{
		if (this->ptr == 0)
		{
			this->ptr = (SIZE - 1);
		}
		else
		{
			this->ptr -= 1;
		};
	};
	inline void incrementPointer() noexcept
	{
		this->ptr = (this->ptr + 1) % SIZE;
	};

	// Access Operator
	inline const T& operator[](const uint8_t& i) const noexcept
	{
		return this->data[((ptr + 1 + i) % SIZE) ];
	};

	// Buffer Methods
	inline void push_back(const T& value)
	{
		this->data[this->ptr] = value;
		this->decrementPointer();
	};
};
#pragma push(pop)
#endif