#include "decode.h"
#include "../globals.h"
#include <stdio.h>
#include <stdlib.h>
#include "../utils.h"
#include "eth.h"
void get_pcap_info(FILE* fp){
  struct pcap_filehdr file_header;
  
  // fre((char*)&file_header,sizeof(file_header));
  fread(&file_header,sizeof(file_header),1,fp);
  if(file_header.magic == 0xa1b2c3d4){
    printf("Microsecond timestamp\n");
    time_type = TT_MS;
  } else if(file_header.magic == 0xa1b23cd4){
    printf("Nanosecond timestamp\n");
    time_type = TT_NS;
  } else {
    printf("Unknown timestamp: 0x%02x",file_header.magic);
    exit(EXIT_FAILURE);
  }
  printf("Version: %d.%d\n",file_header.mjr_version,file_header.mnr_version);

  printf("Snaplen: %d\n",file_header.snaplen);
}

void decode_loop(FILE * fp){
  while(!feof(fp)){
    packet temp;
    fread(&temp,sizeof(temp),0,fp);
    unsigned char pkt_data[1550];
    fread((char*)&pkt_data,temp.cap_len,1,fp);
    // printf("%s ",ts_to_date(temp.ts_seconds));
    ethernet_decode(pkt_data);


  }
}