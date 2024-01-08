#include "test_matrix.h"
#include "main.h"
#include <stdio.h>

void set_matrix(uint32_t mask_red, uint32_t mask_green) {
  // Construct buffer:
  uint8_t buf[] = {
      mask_red >> 4,
      (mask_red & 0xF) << 4 | (mask_green >> 8),
      mask_green & 0xff,
  };

  // Transmit to LED shift registers:
  HAL_SPI_Transmit(&hspi2, buf, 3, 300);

  // Latch:
  HAL_GPIO_WritePin(MATRIX_RCK_GPIO_Port, MATRIX_RCK_Pin, GPIO_PIN_SET);
  HAL_Delay(1);
  HAL_GPIO_WritePin(MATRIX_RCK_GPIO_Port, MATRIX_RCK_Pin, GPIO_PIN_RESET);
}

bool test_matrix(void) {
  printf("Playing matrix test pattern. Hold LEFT to continue or RIGHT to indicate error.\r\n");

  // Ensure RCK is reset:
  HAL_GPIO_WritePin(MATRIX_RCK_GPIO_Port, MATRIX_RCK_Pin, GPIO_PIN_RESET);
  HAL_Delay(1);

  size_t pattern_step = 0;
  while (1) {
    switch (pattern_step) {
      case 0:
        for (int i = 0; i < 12; i++) {
          set_matrix(0, 0x1 << i);
          HAL_Delay(100);
        }
        break;
      case 1:
        for (int i = 0; i < 12; i++) {
          set_matrix(0x1 << i, 0);
          HAL_Delay(100);
        }
        break;
      case 2:
        set_matrix(0xfff, 0x0);
        HAL_Delay(400);
        break;
      case 3:
        set_matrix(0, 0xfff);
        HAL_Delay(400);
        break;
      case 4:
        set_matrix(0xfff, 0xfff);
        HAL_Delay(400);
        break;
    }

    pattern_step = pattern_step == 4 ? 0 : pattern_step + 1;

    if (!HAL_GPIO_ReadPin(BTN_R_GPIO_Port, BTN_R_Pin)) {
      set_matrix(0x0, 0x0);
      return false;
    } else if (!HAL_GPIO_ReadPin(BTN_L_GPIO_Port, BTN_L_Pin)) {
      set_matrix(0x0, 0x0);
      return true;
    }
  }
}
