#pragma once
#include <memory>


struct noop_deleter {
   template <class T>
   void operator()(T*) { /* I don't do anything */ }
};

template <class T>
using access_ptr = std::unique_ptr<T, noop_deleter>;
