#include <getopt.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "include/decode.hpp"
#include <sstream>
#include <string>

using namespace std;
int main(int argc, char ** argv){
  struct pcap_filehdr file_header;
  // std::string filename = argv[2];
  ifstream pf(argv[1], ios::out | ios::binary);
  if(!pf){
    printf("Failed to open test file\n");
    return -1;
  }

  pf.read((char *)&file_header,sizeof(file_header));

  pf.close();
  
  printf("0x%02x\n",file_header.magic);

  if(file_header.magic == 0xa1b2c3d4)
    printf("microsecond timestamp\n");
  else if(file_header.magic == 0xa1b23cd3)
    printf("nanosecond timestamp\n");
  else
    printf("Unrecognized file magic: 0x%02x\n",file_header.magic);

  std::string version;
  std::ostringstream out;

  out << file_header.mjr_version << "." << file_header.mnr_version;

  cout << out.str() << endl;    
  
  cout << file_header.snaplen << endl;
  cout << file_header.fbit << endl;

}