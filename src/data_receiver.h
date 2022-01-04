#pragma once
#include <cstdint>


struct data_receiver
{
   virtual ~data_receiver() = default;
   virtual void data_received(uint8_t const* data, size_t length) = 0;
};

inline data_receiver* g_receiver = nullptr;
