#include "decode.hpp"
#include <fstream>
#include "../globals.hpp"
#include <stdio.h>
#include "eth.hpp"
using namespace std;
void get_pcap_info(std::ifstream& ofs){
  struct pcap_filehdr file_header;
  
  ofs.read((char*)&file_header,sizeof(file_header));
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

void decode_loop(std::ifstream& ifs){
  while(ifs.peek() != EOF){
    
    packet temp;
    ifs.read((char *)&temp,sizeof(temp));
    unsigned char pkt_data[1550];
    ifs.read((char*)&pkt_data,temp.cap_len);
    ethernet_decode(pkt_data);


  }
}