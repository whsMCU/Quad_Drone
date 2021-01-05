/*
 * i2c.c
 *
 *  Created on: 2020. 12. 20.
 *      Author: WANG
 */


#include "i2c.h"

extern eeror_t Error;

I2C_HandleTypeDef hi2c2;


bool i2cInit(void)
{
  bool ret = true;

  hi2c2.Instance = I2C2;
  hi2c2.Init.ClockSpeed = 400000;
  hi2c2.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c2.Init.OwnAddress1 = 0;
  hi2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c2.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c2.Init.OwnAddress2 = 0;
  hi2c2.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c2.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c2) != HAL_OK)
  {
    Error_Handler();
  }
  return ret;
}


bool I2C_ByteWrite(uint8_t DevAddress, uint8_t MemAddress, uint8_t bitStart, uint8_t length, uint8_t data)
{
  HAL_StatusTypeDef state;
  uint32_t ErrorCode;
	 // 010 value to write
	// 76543210 bit numbers
	// xxx   args: bitStart=4, length=3
	// 00011100 mask byte
	// 10101111 original value (sample)
	// 10100011 original & ~mask
	// 10101011 masked | value
	uint8_t tmp;
	state = HAL_I2C_Mem_Read(&hi2c2, DevAddress, MemAddress, 1, &tmp, 1, 1000);
  ErrorCode = hi2c2.ErrorCode;
//  while(state)
//  {
//  	logPrintf("MPU9250_Tx(read)_Error : %d, %ld\r\n", state, ErrorCode);
//    while (Error.error !=0)
//    {
//      Error.error = 2;
//      error_signal();
//      HAL_Delay(4);
//    }
//  }
	uint8_t mask = ((1 << length) - 1) << (bitStart - length + 1);
	data <<= (bitStart - length + 1); // shift data into correct position
	data &= mask; // zero all non-important bits in data
	tmp &= ~(mask); // zero all important bits in existing byte
	tmp |= data; // combine data with existing byte
	state = HAL_I2C_Mem_Write(&hi2c2, DevAddress, MemAddress, 1, &tmp, 1, 1000);
  ErrorCode = hi2c2.ErrorCode;
  while(state)
  {
  	logPrintf("MPU9250_Tx(write)_Error : %d, %ld\r\n", state, ErrorCode);
    while (Error.error !=0)
    {
      Error.error = 2;
      error_signal();
      HAL_Delay(4);
    }
  }
  return true;
}

void I2C_BitWrite(uint8_t DevAddress, uint8_t MemAddress, uint8_t bitNum, uint8_t data)
{
	uint8_t tmp;
	HAL_I2C_Mem_Write(&hi2c2, DevAddress, MemAddress, 1, &tmp, 1, 1000);
	tmp = (data != 0) ? (tmp | (1 << bitNum)) : (tmp & ~(1 << bitNum));
	HAL_I2C_Mem_Write(&hi2c2, DevAddress, MemAddress, 1, &tmp, 1, 1000);
}

//void I2C_ByteRead(uint8_t DevAddress, uint8_t MemAddress, uint8_t bitStart, uint8_t length, uint8_t *data)
//{
//	// 01101001 read byte
//	// 76543210 bit numbers
//	//    xxx   args: bitStart=4, length=3
//	//    010   masked
//	//   -> 010 shifted
//	uint8_t tmp;
//	HAL_I2C_Mem_Read(&hi2c2, DevAddress, MemAddress, 1, &tmp, 1, 1);
//	uint8_t mask = ((1 << length) - 1) << (bitStart - length + 1);
//	tmp &= mask;
//	tmp >>= (bitStart - length + 1);
//	*data = tmp;
//}

bool I2C_ByteRead(uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size)
{
  HAL_StatusTypeDef state;
  uint32_t ErrorCode;
  state = HAL_I2C_Mem_Read(&hi2c2, DevAddress, MemAddress, MemAddSize, pData, Size, 1);
  ErrorCode = hi2c2.ErrorCode;
  while(state)
  {
  	logPrintf("MPU9250_Rx_Error : %d, %ld\r\n", state, ErrorCode);
    while (Error.error !=0)
    {
      Error.error = 2;
      error_signal();
      HAL_Delay(4);
    }
  }
  return true;
}

bool I2C_ByteWrite_HAL(uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size)
{
  HAL_StatusTypeDef state;
  uint32_t ErrorCode;
  state = HAL_I2C_Mem_Write(&hi2c2, DevAddress, MemAddress, MemAddSize, pData, Size, 1);
  ErrorCode = hi2c2.ErrorCode;
  while(state)
  {
  	logPrintf("MPU9250_Tx_Error : %d, %ld\r\n", state, ErrorCode);
    while (Error.error !=0)
    {
      Error.error = 2;
      error_signal();
      HAL_Delay(4);
    }
  }
  return true;
}

void I2C_BitRead(uint8_t DevAddress, uint8_t MemAddress, uint8_t bitNum, uint8_t *data)
{
	uint8_t tmp;
	HAL_I2C_Mem_Read(&hi2c2, DevAddress, MemAddress, 1, &tmp, 1, 1000);
	*data = tmp & (1 << bitNum);
}

void I2C_Write(uint16_t DevAddress, uint8_t data, uint16_t Size)
{
  HAL_StatusTypeDef state;
  uint32_t ErrorCode;

  if(HAL_I2C_GetState(&hi2c2) == HAL_I2C_STATE_READY){

  state = HAL_I2C_Master_Transmit(&hi2c2, DevAddress, &data, Size, 1000);
  ErrorCode = hi2c2.ErrorCode;
   while(state)
   {
  	 logPrintf("MS5611_Tx_Error : %d, %ld\r\n", state, ErrorCode);
     while (Error.error !=0)
     {
       Error.error = 2;
       error_signal();
       HAL_Delay(4);
     }
   }
  }
}

void I2C_Read(uint16_t DevAddress, uint8_t *pData, uint16_t Size)
{
  HAL_StatusTypeDef state;
  uint32_t ErrorCode;

  if(HAL_I2C_GetState(&hi2c2) == HAL_I2C_STATE_READY){

  state = HAL_I2C_Master_Receive(&hi2c2, DevAddress, pData, Size, 1000);
  ErrorCode = hi2c2.ErrorCode;
    while(state)
    {
    	logPrintf("MS5611_Tx_Error : %d, %ld\r\n", state, ErrorCode);
      while (Error.error !=0)
      {
        Error.error = 3;
        error_signal();
        HAL_Delay(4);
      }
    }
  }
}

void HAL_I2C_MspInit(I2C_HandleTypeDef* i2cHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(i2cHandle->Instance==I2C2)
  {
  /* USER CODE BEGIN I2C2_MspInit 0 */

  /* USER CODE END I2C2_MspInit 0 */

    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**I2C2 GPIO Configuration
    PB10     ------> I2C2_SCL
    PB11     ------> I2C2_SDA
    */
    GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_11;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* I2C2 clock enable */
    __HAL_RCC_I2C2_CLK_ENABLE();
  /* USER CODE BEGIN I2C2_MspInit 1 */

  /* USER CODE END I2C2_MspInit 1 */
  }
}

void HAL_I2C_MspDeInit(I2C_HandleTypeDef* i2cHandle)
{

  if(i2cHandle->Instance==I2C2)
  {
  /* USER CODE BEGIN I2C2_MspDeInit 0 */

  /* USER CODE END I2C2_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_I2C2_CLK_DISABLE();

    /**I2C2 GPIO Configuration
    PB10     ------> I2C2_SCL
    PB11     ------> I2C2_SDA
    */
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_10);

    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_11);

  /* USER CODE BEGIN I2C2_MspDeInit 1 */

  /* USER CODE END I2C2_MspDeInit 1 */
  }
}
