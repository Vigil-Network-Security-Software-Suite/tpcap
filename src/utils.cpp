#include <inttypes.h>
#include "utils.hpp"
#include <string.h>
#include <stdio.h>


static __thread char buffer[1024];


char * decode_hw_addr(uint8_t * bytes){
  sprintf(buffer,"%x:%x:%x:%x:%x:%x",
                  bytes[0],bytes[1],bytes[2],bytes[3],bytes[4],bytes[5]);
  return buffer;
}