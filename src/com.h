#pragma once
#include <cstdint>

#include "access_ptr.h"
#include "data_receiver.h"

class com
{
public:
   bool transmit(uint8_t const* data, uint32_t length);

   void request_data();
   void set_receiver(data_receiver&);

   com(com const&) = delete;
   com(com&&) = delete;
   com& operator=(com const&) = delete;
   com& operator=(com&&) = delete;
   ~com() = default;
private:
   com();
   uint8_t m_com_buffer[13]{ '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@' };

   friend access_ptr<com> init_com_mock();
};

