#pragma once

#include <inttypes.h>

struct pcap_filehdr{
  uint32_t magic;
  uint16_t mjr_version;
  uint16_t mnr_version;
  uint32_t res1;
  uint32_t res2;
  uint32_t snaplen;
  unsigned int fcs:       3;
  unsigned int fbit:      1;
  unsigned int linktype:  28;
};

