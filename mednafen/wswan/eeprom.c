/* Cygne
 *
 * Copyright notice for this file:
 *  Copyright (C) 2002 Dox dox@space.pl
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "wswan.h"
#include "eeprom.h"
#include "wswan-memory.h"
#include "../state_inline.h"

uint8_t wsEEPROM[2048];
static uint8_t iEEPROM[0x400];
static const uint8_t iEEPROM_Init[0x400] = 
{
   255,255,255,255,255,255,192,255,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,127,0,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255, 
   0,252,255,1,255,253,255,253,255,253,255,253,
   255,253,255,253,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   0,0,3,3,0,0,0,64,128,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,
   135,5,140,9,5,12,139,12,144,0,0,2,
   0,76,165,0,128,0,0,0,255,127,255,127,
   255,127,255,127,255,127,255,127,255,127,255,127,
   255,127,255,127,255,127,255,127,255,127,255,127,
   255,127,255,127,255,127,255,127,255,127,255,127,
   255,127,255,127,255,127,255,127,255,127,255,127,
   255,127,255,127,255,127,255,127,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   0,0,6,6,6,6,6,0,0,0,0,0,
   1,128,15,0,1,1,1,15,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,
   'C'-54,'Y'-54,'G'-54,'N'-54,'E'-54,0,0,0,0,0,0,0,0,0,0,
   0,32,1,1,33,1,4,0,1,
   0,152,60,127,74,1,53,1,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,255,255,255,255,
   255,255,255,255
};

static uint8_t iEEPROM_Command, EEPROM_Command;
static uint16_t iEEPROM_Address, EEPROM_Address;

/* 内置 EEPROM 是 1Kbit = 64 个 16-bit word；前 128 字节与 Oswan.eep 同格式。
 * 元数据借用 iEEPROM 的空闲字节，随即时存档一起序列化。 */
#define IEEP_DATA_LO 0x80
#define IEEP_DATA_HI 0x81
#define IEEP_PROTECT 0x82
#define IEEP_READCMP 0x83

static char iEepPath[4096];
static int iEepPathSet;
static int iEepUseCommand;

static uint16_t iEepWordGet(unsigned a)
{
   a &= 0x3F;
   return (uint16_t)iEEPROM[a * 2] | ((uint16_t)iEEPROM[a * 2 + 1] << 8);
}

static void iEepWordSet(unsigned a, uint16_t v)
{
   a &= 0x3F;
   iEEPROM[a * 2]     = v & 0xFF;
   iEEPROM[a * 2 + 1] = (v >> 8) & 0xFF;
}

static uint16_t iEepDataGet(void)
{
   return (uint16_t)iEEPROM[IEEP_DATA_LO] | ((uint16_t)iEEPROM[IEEP_DATA_HI] << 8);
}

static void iEepDataSet(uint16_t v)
{
   iEEPROM[IEEP_DATA_LO] = v & 0xFF;
   iEEPROM[IEEP_DATA_HI] = (v >> 8) & 0xFF;
}

static int iEepProtectGet(void) { return iEEPROM[IEEP_PROTECT]; }
static void iEepProtectSet(int v) { iEEPROM[IEEP_PROTECT] = v ? 1 : 0; }
static int iEepReadDoneGet(void) { return iEEPROM[IEEP_READCMP]; }
static void iEepReadDoneSet(int v) { iEEPROM[IEEP_READCMP] = v ? 1 : 0; }

static uint8_t iEepStatus(void)
{
   /* bit1 始终 ready；bit0 表示上一次读命令已完成。 */
   return 0x02 | (iEepReadDoneGet() ? 0x01 : 0x00);
}

static void iEepDefaults(void)
{
   static const uint16_t user[6] = {0x211D, 0x180B, 0x1C0D, 0x1D23, 0x0B1E, 0x0016};
   unsigned i;

   /* word 0x00-0x2F：通关/普通数据区，空片为 FF；
    * word 0x30-0x3F：主机用户区，必须给出有效值，否则续作会卡。 */
   memset(iEEPROM, 0xFF, 0x60);
   memset(iEEPROM + 0x60, 0, 0x20);
   for(i = 0; i < 6; i++)
      iEepWordSet(0x30 + i, user[i]);

   iEepDataSet(0);
   iEepProtectSet(0);
   iEepReadDoneSet(0);
   memset(iEEPROM + 0x84, 0, 0x0C);
}

static void iEepSave(void)
{
   char tmp[sizeof(iEepPath) + 5];
   FILE *f;

   if(!iEepPathSet || !iEepUseCommand)
      return;

   snprintf(tmp, sizeof(tmp), "%s.tmp", iEepPath);
   f = fopen(tmp, "wb");
   if(!f)
      return;

   fwrite(iEEPROM, 1, 128, f);
   fclose(f);

   remove(iEepPath);
   rename(tmp, iEepPath);
}

static int iEepBlank(void)
{
   unsigned i;
   int all_zero = 1, all_ff = 1;

   for(i = 0; i < 128; i++)
   {
      if(iEEPROM[i] != 0x00) all_zero = 0;
      if(iEEPROM[i] != 0xFF) all_ff = 0;
   }
   return all_zero || all_ff;
}

static void iEepLoad(void)
{
   FILE *f;
   uint8_t buf[128];
   size_t n;

   iEepDefaults();
   if(!iEepPathSet)
      return;

   f = fopen(iEepPath, "rb");
   if(!f)
   {
      iEepSave();
      return;
   }

   n = fread(buf, 1, sizeof(buf), f);
   fclose(f);

   if(n == sizeof(buf))
      memcpy(iEEPROM, buf, sizeof(buf));

   if(n != sizeof(buf) || iEepBlank())
   {
      iEepDefaults();
      iEepSave();
   }
}

void WSwan_EEPROMSetPersistPath(const char *path)
{
   if(!path || !*path)
      return;
   strncpy(iEepPath, path, sizeof(iEepPath) - 1);
   iEepPath[sizeof(iEepPath) - 1] = 0;
   iEepPathSet = 1;
}

void WSwan_EEPROMSavePersist(void)
{
   iEepSave();
}

uint8_t WSwan_EEPROMRead(uint32_t A)
{
   switch(A)
   {
      default:
         break;
      case 0xBA:
         if(iEepUseCommand)
            return iEEPROM[IEEP_DATA_LO];
         return iEEPROM[(iEEPROM_Address << 1) & 0x3FF];
      case 0xBB:
         if(iEepUseCommand)
            return iEEPROM[IEEP_DATA_HI];
         return iEEPROM[((iEEPROM_Address << 1) | 1) & 0x3FF];
      case 0xBC:
         return(iEEPROM_Address >> 0);
      case 0xBD:
         return(iEEPROM_Address >> 8);
      case 0xBE:
         if(iEepUseCommand)
            return iEepStatus();
         if(iEEPROM_Command & 0x20)
            return iEEPROM_Command|2;
         if(iEEPROM_Command & 0x10)
            return iEEPROM_Command|1;
         return iEEPROM_Command | 3;
      case 0xC4:
         return(wsEEPROM[(EEPROM_Address << 1) & (eeprom_size - 1)]);
      case 0xC5:
         return(wsEEPROM[((EEPROM_Address << 1) | 1) & (eeprom_size - 1)]);
      case 0xC6:
         return(EEPROM_Address >> 0);
      case 0xC7:
         return(EEPROM_Address >> 8);
      case 0xC8:
         if(EEPROM_Command & 0x20)
            return EEPROM_Command|2;
         if(EEPROM_Command & 0x10)
            return EEPROM_Command|1;
         return EEPROM_Command | 3;
   }

   return 0;
}


void WSwan_EEPROMWrite(uint32_t A, uint8_t V)
{
   switch(A)
   {
      case 0xBA:
         if(iEepUseCommand)
            iEEPROM[IEEP_DATA_LO] = V;
         else
            iEEPROM[(iEEPROM_Address << 1) & 0x3FF] = V;
         break;
      case 0xBB:
         if(iEepUseCommand)
            iEEPROM[IEEP_DATA_HI] = V;
         else
            iEEPROM[((iEEPROM_Address << 1) | 1) & 0x3FF] = V;
         break;
      case 0xBC:
         iEEPROM_Address &= 0xFF00; iEEPROM_Address |= (V << 0);
         break;
      case 0xBD:
         iEEPROM_Address &= 0x00FF; iEEPROM_Address |= (V << 8);
         break;
      case 0xBE:
         if(!iEepUseCommand)
         {
            iEEPROM_Command = V;
            break;
         }
      {
         const uint8_t control = V >> 4;   /* 1=读 2=写 4=擦除 8=保护 */
         const unsigned addr = iEEPROM_Address & 0x3F;

         iEEPROM_Command = V;

         switch(control)
         {
            case 1:
               iEepDataSet(iEepWordGet(addr));
               iEepReadDoneSet(1);
               break;
            case 2:
               if(!iEepProtectGet() || addr < 0x30)
               {
                  iEepWordSet(addr, iEepDataGet());
                  iEepSave();
               }
               break;
            case 4:
               if(!iEepProtectGet() || addr < 0x30)
               {
                  iEepWordSet(addr, 0xFFFF);
                  iEepSave();
               }
               break;
            case 8:
               iEepProtectSet(1);
               break;
            default:
               break;
         }
         break;
      }
      case 0xC4:
         wsEEPROM[(EEPROM_Address << 1) & (eeprom_size - 1)] = V;
         break;
      case 0xC5:
         wsEEPROM[((EEPROM_Address << 1) | 1) & (eeprom_size - 1)] = V;
         break;
      case 0xC6:
         EEPROM_Address &= 0xFF00; EEPROM_Address |= (V << 0);
         break;
      case 0xC7:
         EEPROM_Address &= 0x00FF; EEPROM_Address |= (V << 8);
         break;
      case 0xC8:
         EEPROM_Command = V;
         break;
   }
}

void WSwan_EEPROMReset(void)
{
   iEEPROM_Command = EEPROM_Command = 0;
   iEEPROM_Address = EEPROM_Address = 0;
   if(iEepUseCommand)
   {
      iEepDataSet(0);
      iEepProtectSet(0);
      iEepReadDoneSet(0);
   }
}

#define  mBCD16(value) ( (((((value)%100) / 10) <<4)|((value)%10)) | ((((((value / 100)%100) / 10) <<4)|((value / 100)%10))<<8) )
#define INT16_TO_BCD(A)  ((((((A) % 100) / 10) * 16 + ((A) % 10))) | (((((((A) / 100) % 100) / 10) * 16 + (((A) / 100) % 10))) << 8))

void WSwan_EEPROMInit(const char *Name, const uint16_t BYear, const uint8_t BMonth, const uint8_t BDay, const uint8_t Sex, const uint8_t Blood, int IsWSC)
{
   unsigned x;
   uint16_t bcd_BYear;

   memset(wsEEPROM, 0, 2048);
   memcpy(iEEPROM, iEEPROM_Init, 0x400);

   /* 1Kbit 命令协议只用于黑白 WS（WS2 通关数据）。WSC 的内置
    * EEPROM 更大，保持原有直接寻址行为，避免影响 WSC 游戏。 */
   iEepUseCommand = !IsWSC;

   for(x = 0; x < 16; x++)
   {
      uint8_t zechar = 0;

      if(x < strlen(Name))
      {
         char tc = toupper(Name[x]);
         if(tc == ' ') zechar = 0;
         else if(tc >= '0' && tc <= '9') zechar = tc - '0' + 0x1;
         else if(tc >= 'A' && tc <= 'Z') zechar = tc - 'A' + 0xB;
         else if(tc >= 'a' && tc <= 'z') zechar = tc - 'a' + 0xB + 26;
      }
      iEEPROM[0x360 + x] = zechar;
   }

   bcd_BYear      = INT16_TO_BCD(BYear);

   iEEPROM[0x370] = (bcd_BYear >> 8) & 0xFF;
   iEEPROM[0x371] = (bcd_BYear >> 0) & 0xFF;
   iEEPROM[0x372] = mBCD(BMonth);
   iEEPROM[0x373] = mBCD(BDay);
   iEEPROM[0x374] = Sex;
   iEEPROM[0x375] = Blood;

   if(iEepUseCommand)
   {
      /* wsdbg 等非 libretro 前端可用环境变量指定共享本体内存文件。 */
      if(!iEepPathSet)
      {
         const char *env = getenv("WSWAN_EEPROM_FILE");
         if(env && *env)
            WSwan_EEPROMSetPersistPath(env);
      }
      iEepLoad();
   }
}

int WSwan_EEPROMStateAction(StateMem *sm, int load, int data_only)
{
   SFORMAT StateRegs[] =
   {
      SFVARN(iEEPROM_Command, "iEEPROM_Command"),
      SFVARN(iEEPROM_Address, "iEEPROM_Address"),
      SFVARN(EEPROM_Command,  "EEPROM_Command"),
      SFVARN(EEPROM_Address,  "EEPROM_Address"),
      SFARRAYN((iEEPROM), (sizeof(iEEPROM)), "iEEPROM"),
      SFARRAYN(eeprom_size ? wsEEPROM : NULL, eeprom_size, "EEPROM"),
      { 0, 0, 0, 0 }
   };

   if(!MDFNSS_StateAction(sm, load, data_only, StateRegs, "EEPR", false))
      return 0;

   /* 旧核心的 iEEPROM[0x80..0x83] 是 0xFF，新协议会把它们当成
    * protect/read-complete 元数据；读档后统一归零，避免写保护误锁。 */
   if(load && iEepUseCommand)
   {
      iEepDataSet(0);
      iEepProtectSet(0);
      iEepReadDoneSet(0);
   }

   return 1;
}
