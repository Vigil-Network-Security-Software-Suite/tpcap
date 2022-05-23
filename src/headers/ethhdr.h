#ifndef ETHHDR_H
#define ETHHDR_H
#include <inttypes.h>

struct ethhdr{
  uint8_t dest_mac[6];
  uint8_t src_mac[6];
  uint16_t type;
};

#endif /* ETHHDR_H */