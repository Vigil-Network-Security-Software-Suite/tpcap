#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include "src/decode/decode.h"


int main(int argc, char ** argv){
  if(argc == 1){ 
    printf("Need pcap file\n");
    return 0;
  }
  FILE * fp = fopen(argv[1],"rb");
  if(fp == NULL){
    perror("Failed to open file");
    exit(-1);
  }
  get_pcap_info(fp);
  decode_loop(fp);
}