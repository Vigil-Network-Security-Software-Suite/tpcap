#ifndef ETHERNET_H
#define ETHERNET_H

#include <inttypes.h>
void ethernet_decode(unsigned char *);
char * decode_hw_addr(uint8_t *);
#endif /* ETHERNET_H */