
/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "Utility.h"
#include "stdio.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */
void atraso(int valor);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void aula20(void){
	Utility_Init();
	GPIO_Clock_Enable(GPIOA);
	GPIO_Pin_Mode(GPIOA, PIN_6, OUTPUT);

	GPIO_Clock_Enable(GPIOE);
	GPIO_Pin_Mode(GPIOE, PIN_3, INPUT);
	GPIO_Resistor_Enable(GPIOE, PIN_3,PULL_UP);

	while (1){


		if(!GPIO_Read_Pin(GPIOE, PIN_3)){
			GPIO_Toggle_Pin(GPIOA, PIN_6);
			Delay_ms(100);
		} else {
			GPIO_Write_Pin(GPIOA, PIN_6, LOW);
		}
	}
}

void aula27(void){


	int time = 5000;

	Utility_Init();
	GPIO_Clock_Enable(GPIOA);
	GPIO_Pin_Mode(GPIOA, PIN_6, OUTPUT);
	GPIO_Resistor_Enable(GPIOE, PIN_3,PULL_UP);
	GPIO_Resistor_Enable(GPIOE, PIN_4,PULL_UP);

	GPIO_Clock_Enable(GPIOE);
	GPIO_Pin_Mode(GPIOE, PIN_3, INPUT);
	GPIO_Pin_Mode(GPIOE, PIN_4, INPUT);



	while(1){
		if(!GPIO_Read_Pin(GPIOE, PIN_3) && time <= 9999){
			time +=100;

		} else {
			if (!GPIO_Read_Pin(GPIOE, PIN_4) && time >= 1){
				time -=100;
			}
		}

		GPIO_Write_Pin(GPIOA, PIN_6, LOW);
		Delay_us(time);

		GPIO_Write_Pin(GPIOA, PIN_6,HIGH);
		Delay_us(10000-time);


	}

}

void aula01_9(void){

	Utility_Init();
	GPIO_Clock_Enable(GPIOA);
	GPIO_Pin_Mode(GPIOA, PIN_6, OUTPUT);
	GPIO_Resistor_Enable(GPIOE, PIN_3,PULL_UP);
	GPIO_Clock_Enable(GPIOE);
	GPIO_Pin_Mode(GPIOE, PIN_3, INPUT);
	int time = 1000;

	while(1){

		if (!GPIO_Read_Pin(GPIOE, PIN_3)){
			if  (time ==1000){
				time = 100;
			} else {
				time = 1000;
			}

		}
	GPIO_Write_Pin(GPIOA, PIN_6, LOW);
	Delay_ms(time);
	GPIO_Write_Pin(GPIOA, PIN_6, HIGH);
	Delay_ms(time);





		}


}
void aula_10_09(void){
	Utility_Init();
	GPIO_Clock_Enable(GPIOE);
	GPIO_Resistor_Enable(GPIOE, PIN_3,PULL_UP);
	GPIO_Pin_Mode(GPIOE, PIN_3, INPUT);

	GPIO_Clock_Enable(GPIOD);
	GPIO_Pin_Mode(GPIOD, PIN_8, OUTPUT);

	EXTI_Config(EXTI3, GPIOE, FALLING_EDGE);
	NVIC_EnableIRQ(EXTI3_IRQn);

	GPIO_Clock_Enable(GPIOA);
	GPIO_Pin_Mode(GPIOA, PIN_6, OUTPUT);


	EXTI_Config(EXTI4, GPIOE, FALLING_EDGE);
	NVIC_EnableIRQ(EXTI4_IRQn);


	GPIO_Resistor_Enable(GPIOE, PIN_4,PULL_UP);
	GPIO_Pin_Mode(GPIOE, PIN_4, INPUT);



	while (1){

	}
}

void aula08_10(){
	Utility_Init();

	const uint16_t samples[100] = {
	        2048, 2176, 2304, 2431, 2557, 2680, 2801, 2919, 3034, 3144,
	        3251, 3352, 3448, 3538, 3623, 3701, 3774, 3840, 3898, 3949,
	        3993, 4029, 4057, 4077, 4089, 4095, 4089, 4077, 4057, 4029,
	        3993, 3949, 3898, 3840, 3774, 3701, 3623, 3538, 3448, 3352,
	        3251, 3144, 3034, 2919, 2801, 2680, 2557, 2431, 2304, 2176,
	        2048, 1919, 1792, 1665, 1539, 1416, 1295, 1177, 1062,  952,
	         845,  744,  648,  558,  473,  395,  322,  256,  198,  147,
	         103,   67,   39,   19,    7,    1,    7,   19,   39,   67,
	         103,  147,  198,  256,  322,  395,  473,  558,  648,  744,
	         845,  952, 1062, 1177, 1295, 1416, 1539, 1665, 1792, 1919
	    };

	DAC_Init(DAC_CHANNEL1);
	while(1){
		for(uint8_t i=0; i < 100; i++){

			DAC_SetValue(DAC_CHANNEL1, samples[i],  DAC_RES_12BITS);
			Delay_ms(20);


		}
	}}



void aula15_10(){
	Utility_Init();
	USART1_Init();

	ADC_Init(ADC1, SINGLE_CHANNEL, ADC_RES_12BITS );
	ADC_SingleChannel(ADC1, ADC_IN0);



	while(1){
		uint16_t valor_convertido;
		valor_convertido = ADC_GetSingleConversion(ADC1);
		float calculo = (valor_convertido * 3.3)/4095;
		printf("VOLTAGE = %.2f V\n ", calculo);

		Delay_ms(100);
	}
}

void aula27_10(){
	Utility_Init();
	USART1_Init();
	GPIO_Clock_Enable(GPIOA);
	GPIO_Pin_Mode(GPIOA, PIN_6, OUTPUT);
	ADC_Init(ADC1, SINGLE_CHANNEL, ADC_RES_12BITS );
	ADC_SingleChannel(ADC1, ADC_IN0);
	//uint16_t list[50];
	float media=0;


	while(1){
		for(int i=0;i<50;i++){
			media += (ADC_GetSingleConversion(ADC1)*3.3)/4095;
		}
		media = media/50;
		printf("VOLTAGE = %.2f V\n ", media);
		if(media>2){
			GPIO_Write_Pin(GPIOA, PIN_6, LOW);
			printf("B");
		}else{
			printf("A");
			GPIO_Write_Pin(GPIOA, PIN_6, HIGH);
		}
		HAL_Delay(67);

	}
	}

void aula03_11(){
	 Utility_Init();
	 USART1_Init();
	 GPIO_Clock_Enable(GPIOA);
	 //GPIO_Pin_Mode(GPIOA, PIN_6, OUTPUT);
	 ADC_Init(ADC1, SINGLE_CHANNEL, ADC_RES_12BITS );
	 ADC_SingleChannel(ADC1, ADC_IN0);
	 float V;
	 int v1;
	 int v2;
	 while(1){
		 V= (ADC_GetSingleConversion(ADC1)*(1600-20))/4095+20;
		 v1 = (int) V;
		 v2 = (V - v1) *100;
		 printf("%d . %.2d\n", v1, v2);
		 Delay_ms(500);
	 }

}

void aula03_11_2(){
	 Utility_Init();
	 USART1_Init();
	 GPIO_Clock_Enable(GPIOA);
	 //GPIO_Pin_Mode(GPIOA, PIN_6, OUTPUT);
	 ADC_Init(ADC1, SINGLE_CHANNEL, ADC_RES_12BITS );
	 ADC_SingleChannel(ADC1, ADC_IN0);
	 float V;
	 int v1, v2;
	 while(1){
		 V= (ADC_GetSingleConversion(ADC1)*(800-100))/4095+100;
		 v1 = (int) V;
		 v2 = (V - v1) *100;
		 printf("%d . %.2d\n", v1, v2);
		 Delay_ms(301);
	 }

}

void aula05_11(){
	Utility_Init();

	uint16_t samples[100] = {
		        2048, 2176, 2304, 2431, 2557, 2680, 2801, 2919, 3034, 3144,
		        3251, 3352, 3448, 3538, 3623, 3701, 3774, 3840, 3898, 3949,
		        3993, 4029, 4057, 4077, 4089, 4095, 4089, 4077, 4057, 4029,
		        3993, 3949, 3898, 3840, 3774, 3701, 3623, 3538, 3448, 3352,
		        3251, 3144, 3034, 2919, 2801, 2680, 2557, 2431, 2304, 2176,
		        2048, 1919, 1792, 1665, 1539, 1416, 1295, 1177, 1062,  952,
		         845,  744,  648,  558,  473,  395,  322,  256,  198,  147,
		         103,   67,   39,   19,    7,    1,    7,   19,   39,   67,
		         103,  147,  198,  256,  322,  395,  473,  558,  648,  744,
		         845,  952, 1062, 1177, 1295, 1416, 1539, 1665, 1792, 1919
		    };

	//USART1_Init();
	GPIO_Clock_Enable(GPIOA);


	DAC_Init1(DAC_CHANNEL1);
	ADC_Init(ADC1,MULTI_CHANNEL, ADC_RES_12BITS );
	uint8_t a[2] ={ADC_IN0, ADC_IN1};
	ADC_MultiChannel(ADC1, 2, a);
	float p1;
	float p2;
	uint16_t adcs[2];

	while(1){
		 for(uint8_t i = 0; i<100;i++){
			ADC_GetMultiConversions(ADC1, 2, adcs);
			p1 = (adcs[0]*(100-5))/4095 +5;
			p2 = adcs[1]/4095;
			DAC_SetValue(DAC_CHANNEL1, samples[i]*p2,  DAC_RES_12BITS);
			Delay_ms(p1);

		 }
	}

}
void aula10_11(){
	Utility_Init();

	GPIO_Clock_Enable(GPIOA);
	GPIO_Pin_Mode(GPIOA,PIN_6,OUTPUT);
	GPIO_Pin_Mode(GPIOA,PIN_7,OUTPUT);
	SysTick->CTRL = 0; //DESABILITANDO O SYSTICK
	SysTick->LOAD =	10.5e6; //CARREGA O REGISTRADOR
	SysTick->VAL = 0;  //REINICIA O CONTADOR
	SysTick->CTRL = 0b011;
	//LIGA O SYSTICK, HABILITA A INTERRUPÇÃO E SELECIONA A FONTE DE CLOCK



	while(1){
		GPIO_Toggle_Pin(GPIOA, PIN_6);
		Delay_ms(100);
	}


}

void aula12_11(){
	Utility_Init();
	USART1_Init();
	GPIO_Clock_Enable(GPIOA);
	GPIO_Pin_Mode(GPIOA, PIN_6, ALTERNATE);
	//Funcao alternativa 2 TIM5
	GPIOA->AFR[0] |= (0b0010<<24);

	//Habilita Timer clock
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	TIM3->CR1 &= ~TIM_CR1_DIR;
	TIM3-> PSC=219;
	TIM3->ARR = 99;
	TIM3->CCMR1 |= TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1;
	TIM3-> CCMR1 |= TIM_CCMR1_OC1PE;
	TIM3-> CCER |= TIM_CCER_CC1E;
	TIM3-> CCER |= TIM_CCER_CC1P;
	TIM3-> EGR = 1;
	TIM3->CR1 |= TIM_CR1_CEN;

	ADC_Init(ADC1, SINGLE_CHANNEL, ADC_RES_12BITS );
	ADC_SingleChannel(ADC1, ADC_IN0);


	while(1){
		float media=0;
		for(int i=0;i<50;i++){
			media += (ADC_GetSingleConversion(ADC1)*100)/4095;
		}
		media = media/50;
		TIM3->CCR1 = media;

	}
}
void questao2_2(){
	Utility_Init();
	const uint16_t onda[200] = {
			  2110, 2129, 2149, 2168, 2187, 2207, 2226, 2245, 2264, 2283,
			  2301, 2320, 2338, 2356, 2374, 2391, 2408, 2425, 2442, 2458,
			  2474, 2490, 2505, 2520, 2534, 2548, 2562, 2575, 2588, 2600,
			  2612, 2623, 2633, 2644, 2653, 2662, 2671, 2679, 2686, 2693,
			  2700, 2705, 2711, 2715, 2719, 2722, 2725, 2727, 2729, 2730,
			  2730, 2730, 2729, 2727, 2725, 2722, 2719, 2715, 2711, 2705,
			  2700, 2693, 2686, 2679, 2671, 2662, 2653, 2644, 2633, 2623,
			  2612, 2600, 2588, 2575, 2562, 2548, 2534, 2520, 2505, 2490,
			  2474, 2458, 2442, 2425, 2408, 2391, 2374, 2356, 2338, 2320,
			  2301, 2283, 2264, 2245, 2226, 2207, 2187, 2168, 2149, 2129,
			  2110, 2090, 2071, 2051, 2032, 2012, 1993, 1974, 1955, 1936,
			  1918, 1899, 1881, 1863, 1845, 1828, 1811, 1794, 1777, 1761,
			  1745, 1729, 1714, 1699, 1685, 1671, 1657, 1644, 1631, 1619,
			  1608, 1596, 1586, 1575, 1566, 1557, 1548, 1540, 1533, 1526,
			  1519, 1514, 1509, 1504, 1500, 1497, 1494, 1492, 1490, 1489,
			  1489, 1489, 1490, 1492, 1494, 1497, 1500, 1504, 1509, 1514,
			  1519, 1526, 1533, 1540, 1548, 1557, 1566, 1575, 1586, 1596,
			  1608, 1619, 1631, 1644, 1657, 1671, 1685, 1699, 1714, 1729,
			  1745, 1761, 1777, 1794, 1811, 1828, 1845, 1863, 1881, 1899,
			  1918, 1936, 1955, 1974, 1993, 2012, 2032, 2051, 2071, 2090

	};

	DAC_Init(DAC_CHANNEL2);
	while(1){
		for(uint8_t i=0; i < 200; i++){

			DAC_SetValue(DAC_CHANNEL2, onda[i],  DAC_RES_12BITS);
			Delay_us(33);
		}
	}
}



long map(long x, long in_min, long in_max, long out_min, long out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void prova2_7(){

	Utility_Init();

		 const uint16_t SERVO_MIN_US = 1000;
		 const uint16_t SERVO_MAX_US = 2000;
		 uint8_t  channels[2] = {ADC_IN0, ADC_IN1};
		 uint16_t adc[2];
		 uint32_t sumX, sumY;
		 long pulseX, pulseY;

		 GPIO_Clock_Enable(GPIOA);
		 GPIO_Clock_Enable(GPIOB);

		 GPIO_Pin_Mode(GPIOB, PIN_6, ALTERNATE);
		 GPIO_Pin_Mode(GPIOB, PIN_7, ALTERNATE);
		 GPIO_Alternate_Function(GPIOB, PIN_6, AF2);
		 GPIO_Alternate_Function(GPIOB, PIN_7, AF2);
		 RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
		 TIM4->PSC  = 83;
		 TIM4->ARR  = 19999;
		 TIM4->CCMR1 = (6 << 4)  | TIM_CCMR1_OC1PE
				 | (6 << 12) | TIM_CCMR1_OC2PE;
		 TIM4->CCR1 = 1500;
		 TIM4->CCR2 = 1500;
		 TIM4->CCER |= TIM_CCER_CC1E | TIM_CCER_CC2E;
		 TIM4->CR1  |= TIM_CR1_ARPE;
		 TIM4->EGR   = TIM_EGR_UG;
		 TIM4->CR1  |= TIM_CR1_CEN;

		 ADC_Init(ADC1, MULTI_CHANNEL, ADC_RES_12BITS);
		 ADC1->SMPR2 |= (0b111 << 3);
		 ADC_MultiChannel(ADC1, 2, channels);

		 while (1){

			 sumX = 0;
		     sumY = 0;
		     for (int i = 0; i < 8; i++){
		    	 ADC_GetMultiConversions(ADC1, 2, adc);
				 sumX += adc[0];
				 sumY += adc[1];
		     }

		     pulseX = map(sumX / 8, 0, 4095, SERVO_MIN_US, SERVO_MAX_US);
		     pulseY = map(sumY / 8, 0, 4095, SERVO_MIN_US, SERVO_MAX_US);


		     if (pulseX < SERVO_MIN_US) pulseX = SERVO_MIN_US;
		     if (pulseX > SERVO_MAX_US) pulseX = SERVO_MAX_US;
		     if (pulseY < SERVO_MIN_US) pulseY = SERVO_MIN_US;
		     if (pulseY > SERVO_MAX_US) pulseY = SERVO_MAX_US;
		     TIM4->CCR1 = pulseX;
		     TIM4->CCR2 = pulseY;
		     Delay_ms(20);

		 }



}

/* USER CODE END 0 */


/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  //HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();

  /* USER CODE BEGIN 2 */
  /*
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;

  GPIOA->MODER |= 0b01 << 2;
  GPIOC->MODER |= 0b01 << 12;
  GPIOE->MODER |= 0b01 << 24;
  */
  /* USER CODE END 2 */
  //aula20();
  //aula27();
  //aula01_9();
  //aula_10_09();
  //aula08_10();
  //aula05_11();
  //aula12_11();
  //questao2_2();
  prova2_7();
  /* Infinite loop */


  /* USER CODE BEGIN WHILE */
  while (1)
  {
	//atraso(48000000);
	//GPIOA->ODR &= ~(1 << 1);
	//GPIOC->ODR |= 1 << 6;
	//atraso(40000000);
	//GPIOC->ODR &= ~(1 << 6);
	//GPIOE->ODR |= 1 << 12;
	//atraso(48000000);
	//GPIOE->ODR &= ~(1 << 12);


    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */




void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void SysTick_Handler(void){
	GPIOA->ODR ^= (1<<7); //ALTERNA O ESTADO DO PINO PA6
}

void atraso(int valor){
	while (valor>0) --valor;
}
void EXTI3_IRQHandler(){

	int estado=0;

	if (!GPIO_Read_Pin(GPIOE, PIN_3) && estado==0){
		GPIO_Write_Pin(GPIOD, PIN_8, HIGH );
		Delay_ms(50);
		GPIO_Write_Pin(GPIOD, PIN_8, LOW);
		Delay_ms(100);
		GPIO_Write_Pin(GPIOD, PIN_8, HIGH );
		Delay_ms(50);
		GPIO_Write_Pin(GPIOD, PIN_8, LOW);
		estado=1;

	}



	if(estado==1){
		GPIO_Write_Pin(GPIOD, PIN_8, LOW);
		estado=0;

	}

}

void EXTI4_IRQHandler(){

	int estado=0;

	if (!GPIO_Read_Pin(GPIOE, PIN_4) && estado==0){
		GPIO_Write_Pin(GPIOA, PIN_6, HIGH );
		Delay_ms(50);
		GPIO_Write_Pin(GPIOA, PIN_6, LOW);
		Delay_ms(100);
		GPIO_Write_Pin(GPIOA, PIN_6, HIGH );
		Delay_ms(50);
		GPIO_Write_Pin(GPIOA, PIN_6, LOW);
		estado=1;

	}

	if(estado==1){
            			GPIO_Write_Pin(GPIOA, PIN_6, LOW);
			estado=0;

		}
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
