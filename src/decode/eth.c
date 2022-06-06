#include "eth.h"
#include "../headers/ethhdr.h"
#include <string.h>
#include <stdio.h>
#include <inttypes.h>
#include "../utils.h"
void ethernet_decode(unsigned char * pkt){
  struct ethhdr * ethernet_header = (struct ethhdr *)pkt;
  char dest_mac[24];
  char src_mac[24];
  strcpy(dest_mac, decode_hw_addr(ethernet_header->dest_mac));
  strcpy(src_mac, decode_hw_addr(ethernet_header->src_mac));
  printf("%s -> %s\n",src_mac,dest_mac);
  
}

