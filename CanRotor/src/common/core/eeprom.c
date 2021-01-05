/*
 * eeprom.c
 *
 *  Created on: 2020. 12. 26.
 *      Author: WANG
 */


#include "eeprom.h"
#include "i2c.h"
#include "uart.h"




eeprom_t eeprom;
uint8_t _b[8];

extern pidc_t pid;
extern float magBias[3], magScale[3];
extern PID_PARAM posholdPID_PARAM;
extern PID_PARAM poshold_ratePID_PARAM;
extern PID_PARAM navPID_PARAM;


void EEPROM_Test()
{
  // read and write byte
	uartPrintf(_DEF_UART1, "Write 42 to address 12\r\n");
	 write(12, 42);
	 uartPrintf(_DEF_UART1, "Read byte from address 12 ...\r\n");
     uint8_t b = read(12);
	 uartPrintf(_DEF_UART1, "read value : %d\r\n\n", b);

	 // read and write integer
	 uartPrintf(_DEF_UART1, "Write 65000 to address 15\r\n");
	 writeInt(15, 65000);
	 uartPrintf(_DEF_UART1, "Read integer from address 15 ...\r\n");
	 unsigned int i = readInt(15);
	 uartPrintf(_DEF_UART1, "read value : %d\r\n\n", i);
	 // read and write long
   uartPrintf(_DEF_UART1, "Write 3293732729 to address 20\r\n");
   writeLong(20, 3293732729UL);
   uartPrintf(_DEF_UART1, "Read long from address 20 ...\r\n");
   unsigned long l = readLong(20);
   uartPrintf(_DEF_UART1, "read value : %lu\r\n\n", l);


   // read and write long
   uartPrintf(_DEF_UART1, "Write 1111111111 to address 31\r\n");
   writeLong(31, 1111111111);
   uartPrintf(_DEF_UART1, "Read long from address 31 ...\r\n");
   unsigned long l2 = readLong(31);
   uartPrintf(_DEF_UART1, "read value : %lu\r\n\n", l2);


   // read and write float
   uartPrintf(_DEF_UART1, "Write 3.14 to address 40\r\n");
   writeFloat(40, 3.14);
   uartPrintf(_DEF_UART1, "Read float from address 40 ...\r\n");
   float f = readFloat(40);
   uartPrintf(_DEF_UART1, "read value : %f\r\n\n", f);

   // read and write double
   uartPrintf(_DEF_UART1, "Write 3.14159265359 to address 50\r\n");
   writeDouble(50, 3.14159265359);
   uartPrintf(_DEF_UART1, "Read double from address 50 ...\r\n");
   double d = readDouble(50);
   uartPrintf(_DEF_UART1, "read value : %f\r\n\n", d);

   // read and write char
   uartPrintf(_DEF_UART1, "Write chars: '");
   char msg[] = "This is a message";
   uartPrintf(_DEF_UART1, "%s", msg);
   uartPrintf(_DEF_UART1, "' to address 200\r\n");
   writeChars(200, msg, sizeof(msg));
   uartPrintf(_DEF_UART1, "Read chars from address 200 ...\r\n");
   char msg2[30];
   readChars(200, msg2, sizeof(msg2));
   uartPrintf(_DEF_UART1, "read value : '%s'\r\n\n", msg2);

   // write array of bytes
   uartPrintf(_DEF_UART1, "Write array of 80 bytes at address 1000\r\n");
   uint8_t xy[] = {0,0,0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9,    // 10 x 3 = 30
                  10,11,12,13,14,15,16,17,18,19,                                   //          10
                  120,121,122,123,124,125,126,127,128,129,                         //          10
                  130,131,132,133,134,135,136,137,138,139,                         //          10
                  200,201,202,203,204,205,206,207,208,209,                         //          10
                  210,211,212,213,214,215,216,217,218,219};                        //          10
   write_1(1000, (uint8_t*)xy, sizeof(xy));

   // read bytes with multiple steps
   uartPrintf(_DEF_UART1, "Read 80 single bytes starting at address 1000\r\n");
   for (int i=0; i<sizeof(xy); i++) {
     uint8_t sb = read(1000+i);
     uartPrintf(_DEF_UART1, "[ %d ] = %d\r\n", 1000+i, sb);
   }
   uartPrintf(_DEF_UART1, "\n");

   // read bytes with one step
   uint8_t z[80];
   memset(&z[0], 32, sizeof(z));
   read_1(1000, z, sizeof(z));
   for (int i=0; i<sizeof(z); i++) {
     uartPrintf(_DEF_UART1, "[ %d ] = %d\r\n", 1000+i, z[i]);
   }
}

void EEPROM_Init()
{

  posholdPID_PARAM.kP = readFloat(0); //GPS PID
  posholdPID_PARAM.kI = readFloat(4);

  poshold_ratePID_PARAM.kP = readFloat(8);
  poshold_ratePID_PARAM.kI = readFloat(12);
  poshold_ratePID_PARAM.kD = readFloat(16);

  navPID_PARAM.kP = readFloat(20);
  navPID_PARAM.kI = readFloat(24);
  navPID_PARAM.kD = readFloat(28);
  posholdPID_PARAM.Imax = readFloat(32);
  poshold_ratePID_PARAM.Imax = readFloat(32);
  navPID_PARAM.Imax = readFloat(32);

   for(int i = 0; i < 3; i++){
     pid.kp1[i] = readFloat(36 + (4*i));  //Dual_PID
     pid.ki1[i] = readFloat(48 + (4*i));
     pid.kp2[i] = readFloat(60 + (4*i));
     pid.ki2[i] = readFloat(72 + (4*i));
     pid.kd2[i] = readFloat(84 + (4*i));

     pid.kp_rate[i] = readFloat(96 + (4*i)); // Rate_PID
     pid.ki_rate[i] = readFloat(108 + (4*i));
     pid.kd_rate[i] = readFloat(120 + (4*i));

   }
   magBias[0] = readFloat(132);
   magBias[1] = readFloat(136);
   magBias[2] = readFloat(140);
   magScale[0] = readFloat(144);
   magScale[1] = readFloat(148);
   magScale[2] = readFloat(152);
}

uint8_t EEPROM_read(uint32_t dataAddress)
{
  uint8_t pData[1] = {0};
  I2C_ByteRead(EEPROM_ADDRESS, dataAddress, ADDRESS_SIZE, pData, 1);
  HAL_Delay(1);
  return pData[0];
}

void EEPROM_readPage(uint32_t dataAddress, uint8_t *pData, uint16_t ReadSize)
{
  I2C_ByteRead(EEPROM_ADDRESS, dataAddress, ADDRESS_SIZE, pData, ReadSize);
}

/**
 * Write byte
 */
void write(unsigned int address, uint8_t data) {
  uint8_t* tmp;
  tmp = &data;
  I2C_ByteWrite_HAL(EEPROM_ADDRESS, address, ADDRESS_SIZE, tmp, 1);
  HAL_Delay(5);
}

/**
 * Write integer
 */
void writeInt(unsigned int address, unsigned int data) {
  write_1(address, (uint8_t*)&data, 2);
}

/**
 * Write long
 */
void writeLong(unsigned int address, unsigned long data) {
  write_1(address, (uint8_t*)&data, 4);
}

/**
 * Write float
 */
void writeFloat(unsigned int address, float data) {
  write_1(address, (uint8_t*)&data, 4);
}

/**
 * Write double
 */
void writeDouble(unsigned int address, double data) {
  write_1(address, (uint8_t*)&data, 8);
}

/**
 * Write chars
 */
void writeChars(unsigned int address, char *data, int length) {
  write_1(address, (uint8_t*)data, length);
}

/**
 * Read byte
 */
uint8_t read(unsigned int address) {
  uint8_t b[1];
  I2C_ByteRead(EEPROM_ADDRESS, address, ADDRESS_SIZE, b, 1);
  return *b;
}

/**
 * Read integer
 */
unsigned int readInt(unsigned int address) {
  read_1(address, _b, 2);
  return *(unsigned int*)&_b[0];
}

/**
 * Read long
 */
unsigned long readLong(unsigned int address) {
  read_1(address, _b, 4);
  return *(unsigned long*)&_b[0];
}

/**
 * Read float
 */
float readFloat(unsigned int address) {
  read_1(address, _b, 4);
  return *(float*)&_b[0];
}

/**
 * Read double
 */
double readDouble(unsigned int address) {
  read_1(address, _b, 8);
  return *(double*)&_b[0];
}

/**
 * Read chars
 */
void readChars(unsigned int address, char *data, int n) {
  read_1(address, (uint8_t*)data, n);
}

/**
 * Write sequence of n bytes
 */
void write_1(unsigned int address, uint8_t *data, int n) {
  // status quo
  int c = n;            // bytes left to write
  int offD = 0;         // current offset in data pointer
  int offP;           // current offset in page
  int nc = 0;           // next n bytes to write

  // write alle bytes in multiple steps
  while (c > 0) {
    // calc offset in page
    offP = address % PAGE_SIZE;
    // maximal 30 bytes to write
    nc = min(min(c, 30), PAGE_SIZE - offP);
    write_2(address, data, offD, nc);
    c-=nc;
    offD+=nc;
    address+=nc;
  }
}

/**
 * Write sequence of n bytes from offset
 */
void write_2(unsigned int address, uint8_t *data, int offset, int n) {
    uint8_t *adr = data+offset;
    I2C_ByteWrite_HAL(EEPROM_ADDRESS, address, ADDRESS_SIZE, adr, n);
    HAL_Delay(10);
}

/**
 * Read sequence of n bytes
 */
void read_1(unsigned int address, uint8_t *data, int n) {
  int c = n;
  int offD = 0;
  // read until are n bytes read
  while (c > 0) {
    // read maximal 32 bytes
    int nc = c;
    if (nc > 32)
      nc = 32;
    read_2(address, data, offD, nc);
    address+=nc;
    offD+=nc;
    c-=nc;
  }
}


/**
 * Read sequence of n bytes to offset
 */
void read_2(unsigned int address, uint8_t *data, int offset, int n) {
  int r = 0;
  uint8_t pData[80];
  memset(&pData[0], n, sizeof(pData));
  I2C_ByteRead(EEPROM_ADDRESS, address, ADDRESS_SIZE, pData, n);
  while (r<n) {
    data[offset+r] = pData[r];
    r++;
  }
}
