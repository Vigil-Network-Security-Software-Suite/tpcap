#pragma once

#include "packet.hpp"
#define TT_MS         0x01
#define TT_NS         0x02
extern int time_type;

// remember to free
extern struct pkt_record * packets;

