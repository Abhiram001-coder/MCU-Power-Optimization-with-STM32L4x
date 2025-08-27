#include"PWR_Driver.h"
#include"main.h"

void FlashStateProfile()
{
	/* Enable Flash power down mode during Sleep mode     */
	/* (uncomment this line if power consumption figures  */
	/*  must be measured with Flash still on in Low Power */
	/*  Sleep mode)
	 * 1.                                  */
	__HAL_FLASH_SLEEP_POWERDOWN_ENABLE();

	__HAL_FLASH_PREFETCH_BUFFER_DISABLE();
	__HAL_FLASH_INSTRUCTION_CACHE_DISABLE();
	__HAL_FLASH_DATA_CACHE_DISABLE();

	__HAL_RCC_FLASH_CLK_SLEEP_ENABLE();

	// __HAL_FLASH_PREFETCH_BUFFER_DISABLE();
	__HAL_RCC_FLASH_CLK_DISABLE();
	/* Enable Power Clock :- Setting the PWREN bit in APB1NER1 register*/
	__HAL_RCC_PWR_CLK_ENABLE();
}

void LP_System_Config()
{
	//2. System clock is now reduced from 80MHz to 100KHz
		SystemClock_Config_Decrease();
		//System clock from HSI 80MHz is reduced to 100KHz MSI after this function
		HAL_Delay(2000);
		//3. Voltage Regulator is switched from range-1 to range-2
		if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE2)
				!= HAL_OK) {
			Error_Handler();
		}
}

void Peripheral_Sleep_Enable()
{
	//4. Enabling sleep mode clock for all peripherals
	/* Reset all RCC Sleep and Stop modes register to */
	/* improve power consumption
	 */
	__HAL_RCC_GPIOA_CLK_SLEEP_ENABLE();
	__HAL_RCC_GPIOB_CLK_SLEEP_ENABLE();
	__HAL_RCC_GPIOC_CLK_SLEEP_ENABLE();
	__HAL_RCC_GPIOD_CLK_SLEEP_ENABLE();
	__HAL_RCC_GPIOE_CLK_SLEEP_ENABLE();
	__HAL_RCC_GPIOF_CLK_SLEEP_ENABLE();
	__HAL_RCC_GPIOG_CLK_SLEEP_ENABLE();
	__HAL_RCC_GPIOH_CLK_SLEEP_ENABLE();
	__HAL_RCC_GPIOI_CLK_SLEEP_ENABLE();

	RCC->AHB1SMENR = 0x0;
	RCC->AHB2SMENR = 0x0;
	RCC->AHB3SMENR = 0x0;

	RCC->APB1SMENR1 = 0x0;
	RCC->APB1SMENR2 = 0x0;
	RCC->APB2SMENR = 0x0;
	__HAL_RCC_SYSCFG_CLK_SLEEP_ENABLE();
}

void disableTick()
{
	HAL_SuspendTick();
	__disable_irq();

	SCB->SCR &= ~SCB_SCR_SLEEPDEEP_Msk;

	__HAL_PWR_CLEAR_FLAG(PWR_FLAG_WU); // Clear Wakeup flags
	__HAL_PWR_CLEAR_FLAG(PWR_FLAG_SB); // Clear Standby flags
	// DBGMCU->CR &= ~(DBGMCU_CR_DBG_STOP);
	//  PWR->CR |= PWR_CR1_LPR;
}

