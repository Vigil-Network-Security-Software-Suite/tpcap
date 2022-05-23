#include "decode.hpp"
#include <fstream>
#include "../globals.hpp"
#include <iostream>
using namespace std;
void get_pcap_info(std::ifstream& ofs){
  struct pcap_filehdr file_header;
  
  ofs.read((char*)&file_header,sizeof(file_header));
  if(file_header.magic == 0xa1b2c3d4){
    cout << "Microsecond timestamp" << endl;
    time_type = TT_MS;
  } else if(file_header.magic == 0xa1b23cd4){
    cout << "Nanosecond timestamp" << endl;
    time_type = TT_NS;
  } else {
    cout << "Unknown timestamp" << endl;
    exit(EXIT_FAILURE);
  }
}