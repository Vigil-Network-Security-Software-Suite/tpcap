#include <inttypes.h>
#include "utils.h"
#include <string.h>
#include <stdio.h>
#include <time.h>


static __thread char buffer[1024];


char * decode_hw_addr(uint8_t * bytes){
  memset(&buffer,0,sizeof(buffer));
  sprintf(buffer,"%02x:%02x:%02x:%02x:%02x:%02x",
                  bytes[0],bytes[1],bytes[2],bytes[3],bytes[4],bytes[5]);
  return buffer;
}

char * ts_to_date(uint32_t ts){
  memset(&buffer,0,sizeof(buffer));
  time_t t = (long)ts;
  struct tm __time = *localtime(&t);
    sprintf(buffer,"%d-%02d-%02d %02d:%02d:%02d",
          __time.tm_year + 1900,
          __time.tm_mon + 1,
          __time.tm_mday,
          __time.tm_hour,
          __time.tm_min,
          __time.tm_sec);
  return buffer;

}