#ifndef __WSWAN_EEPROM_H
#define __WSWAN_EEPROM_H

#include <stdint.h>

#include "../state.h"

#ifdef __cplusplus
extern "C" {
#endif

void WSwan_EEPROMReset(void);
int WSwan_EEPROMStateAction(StateMem *sm, int load, int data_only);
void WSwan_EEPROMSetPersistPath(const char *path);
void WSwan_EEPROMSavePersist(void);

uint8_t WSwan_EEPROMRead(uint32_t A);
void WSwan_EEPROMWrite(uint32_t A, uint8_t V);
void WSwan_EEPROMInit(const char *Name, const uint16_t BYear, const uint8_t BMonth, const uint8_t BDay, const uint8_t Sex, const uint8_t Blood, int IsWSC);

#ifdef __cplusplus
}
#endif

#endif
