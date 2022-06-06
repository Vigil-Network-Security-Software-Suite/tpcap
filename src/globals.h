#ifndef GLOBALS_H
#define GLOBALS_H
#include "packet.h"
#define TT_MS         0x01
#define TT_NS         0x02
extern int time_type;

// remember to free
extern struct pkt_record * packets;

#endif /* GLOBALS_H */