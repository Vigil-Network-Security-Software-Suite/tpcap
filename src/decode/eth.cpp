#include "eth.hpp"
#include "../headers/ethhdr.h"
#include <stdio.h>
void ethernet_decode(unsigned char * pkt){
  struct ethhdr * ethernet_header = (struct ethhdr *)pkt;
  printf("%d\n",ethernet_header->type);
}