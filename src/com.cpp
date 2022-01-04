#include "com.h"


com::com()
{
   // TODO USB_Init();
}

bool com::transmit(
   uint8_t const* data [[maybe_unused]],
   uint32_t length [[maybe_unused]] )
{
   // TODO USB_Transmit(data, length);

   return true;
}

void com::request_data()
{
   // TODO USB_RequestData();
}

void com::set_receiver(data_receiver& receiver)
{
   g_receiver = &receiver;
}
