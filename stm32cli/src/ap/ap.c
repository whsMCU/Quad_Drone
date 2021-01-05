/*
 * ap.c
 *
 *  Created on: Dec 6, 2020
 *      Author: baram
 */


#include "ap.h"

void apInit(void)
{
  logPrintf("stm32cli v1.0\n\n");

  cliOpen(_DEF_UART1, 57600);
}

void apMain(int argc, char *argv[])
{
  uint8_t  uart_ch;
  char    *uart_port;
  uint32_t uart_baud;


  if (argc != 3)
  {
    logPrintf("wrong args\n");
    apExit();
  }

  uart_ch   = _DEF_UART2;
  uart_port = argv[1];
  uart_baud = (int32_t)strtoul(argv[2], (char **)NULL, (int) 0);

  logPrintf("uart ch   : %d\n", uart_ch);
  logPrintf("uart port : %s\n", uart_port);
  logPrintf("uart baud : %d bps\n", uart_baud);

  if (uartOpenPort(uart_ch, uart_port, uart_baud) == true)
  {
    logPrintf("uart open : OK\n");
  }
  else
  {
    logPrintf("uart open : Fail\n");
    apExit();
  }


  while(1)
  {
    //cliMain();

    if (uartAvailable(_DEF_UART1) > 0)
    {
      uartPrintf(_DEF_UART2, "%c", uartRead(_DEF_UART1));
    }

    if (uartAvailable(_DEF_UART2) > 0)
    {
      uartPrintf(_DEF_UART1, "%c", uartRead(_DEF_UART2));
    }
  }
}

void apExit(void)
{
  for (int i=0; i<UART_MAX_CH; i++)
  {
    uartClose(i);
  }
  printf("\ncli exit\n");
  exit(0);
}
