#ifndef ETHERNET_HPP
#define ETHERNET_HPP

#include <inttypes.h>
void ethernet_decode(unsigned char *);
char * decode_hw_addr(uint8_t *);
#endif /* ETHERNET_HPP */