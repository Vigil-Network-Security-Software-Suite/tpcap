#include "eth.hpp"
#include "../headers/ethhdr.h"
#include <stdio.h>
#include <inttypes.h>
#include "../utils.hpp"
void ethernet_decode(unsigned char * pkt){
  struct ethhdr * ethernet_header = (struct ethhdr *)pkt;
  printf("%s -> %s %d\n",decode_hw_addr(ethernet_header->src_mac),decode_hw_addr(ethernet_header->dest_mac), ethernet_header->type);

}

