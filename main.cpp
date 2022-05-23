#include <getopt.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "src/decode/decode.hpp"
#include <sstream>
#include <string>

using namespace std;
int main(int argc, char ** argv){
  // std::string filename = argv[2];
  ifstream pf(argv[1], ios::out | ios::binary);
  if(!pf){
    printf("Failed to open test file\n");
    return -1;
  }
  get_pcap_info(pf);
  pf.close();
  

}