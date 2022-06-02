#include <getopt.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "src/decode/decode.hpp"


using namespace std;
int main(int argc, char ** argv){
  // std::string filename = argv[2];
  ifstream pf(argv[1], ios::out | ios::binary);
  if(!pf){;
    perror("Failed to open test file");
    return -1;
  }
  get_pcap_info(pf);
  decode_loop(pf);
  pf.close();
  

}