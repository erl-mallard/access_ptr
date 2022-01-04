#pragma once

#include "access_ptr.h"
#include "data_receiver.h"
#include "com.h"


struct com_manager : private data_receiver
{
   explicit com_manager(access_ptr<com> com)
      : com_{ std::move(com) }
   {
      com_->set_receiver(*this);
      com_->request_data();
   }

private:
   void data_received(uint8_t const* data, size_t length) override
   {
      printf("got: %llu bytes\n", length);
      com_->transmit(data, static_cast<uint32_t>(length));
      com_->request_data();
   }

   access_ptr<com> com_;
};
