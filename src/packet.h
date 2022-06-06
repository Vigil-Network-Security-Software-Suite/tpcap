#ifndef PACKET_H
#define PACKET_H
#include <inttypes.h>
typedef struct{
  uint32_t ts_seconds;
  uint32_t ts_var_sec; // ms or ns
  uint32_t cap_len;
  uint32_t var_len;
} packet;

struct pkt_record{
  packet base_info;
  unsigned char * packet_data;
};

#endif /* PACKET_H */