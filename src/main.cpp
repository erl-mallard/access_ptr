#include <memory>
#include <cassert>

#include "com.h"
#include "com_manager.h"


extern "C" {
   void USB_RX_Callback(uint8_t* const data, size_t length)
   {
      if (g_receiver)
         g_receiver->data_received(data, length);
   }
}

alignas(com) uint8_t usb_com_storage[sizeof(com)];

access_ptr<com> init_com_mock()
{
   static auto ptr = access_ptr<com>{ new (&usb_com_storage) com{} };
   return std::move(ptr);
}

int main()
{
   auto com1 = init_com_mock();
   assert(com1);
   auto com2 = init_com_mock();
   assert(!com2);

   com_manager manager{ std::move(com1) };

   USB_RX_Callback(nullptr, 123);
   USB_RX_Callback(nullptr, 234);

   return 0;
}
