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

#include "Utility.h"
#include "LCD_Blio.h"
#include <stdio.h>
/* USER CODE BEGIN Includes */

volatile int solicitacao_pedestre = 0;



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
const uint8_t mask[16]={
	0b00111111,
	0b00000110,
	0b01011011,
	0b01001111,
	0b01100110,
	0b01101101,
	0b01111101,
	0b00000111,
	0b01111111,
	0b01101111,
	0b01110111,
	0b01111100,
	0b00111001,
	0b01011110,
	0b01111001,
	0b01110001
};

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */


void video_interrupcoes(){

	Utility_Init();
	GPIO_Clock_Enable(GPIOA);
	GPIO_Clock_Enable(GPIOE);

	GPIO_Pin_Mode(GPIOE,PIN_3,INPUT);
	GPIO_Resistor_Enable(GPIOE,PIN_3,PULL_UP);

	// CORREÇÃO 1 e 2: Letras minúsculas na função e remoção do underline no GPIOA
	GPIO_Write_Pin(GPIOA, PIN_6, HIGH);
	GPIO_Pin_Mode(GPIOA, PIN_6, OUTPUT);

	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;

	// CORREÇÃO 3: Substituído o erro de digitação pelo valor hexadecimal correto (0x04) para a Porta E
	SYSCFG->EXTICR[0] |= (0x04 << 12);
	EXTI->FTSR |= 1<<3;
	EXTI->IMR |= 1<<3;

	// CORREÇÃO 4: O sufixo correto para interrupção é IRQn (com Q e n minúsculo)
	NVIC_EnableIRQ(EXTI3_IRQn);
}




void questao3(){

	Utility_Init();

		GPIO_Clock_Enable(GPIOF);
		GPIO_Pin_Mode(GPIOF, PIN_8, OUTPUT);

		GPIO_Clock_Enable(GPIOE);
		GPIO_Pin_Mode(GPIOE,PIN_3,INPUT);

		while(1){


			for ( int var = 0; var < 4; ++var) {

			GPIO_Write_Pin(GPIOF, PIN_8, HIGH );
			Delay_ms(50);
				GPIO_Write_Pin(GPIOF, PIN_8, LOW);
				Delay_ms(50);


			}
			Delay_ms(2000);



		}
 }

void questao4(){


	Utility_Init();

	GPIO_Clock_Enable(GPIOF);
	GPIO_Pin_Mode(GPIOF, PIN_9, OUTPUT);


	int time = 0;
	int passo = 100;
	int subindo = 1;


	while(1){

		GPIO_Write_Pin(GPIOF,PIN_9,HIGH);
		Delay_us(time);

		GPIO_Write_Pin(GPIOF, PIN_9,LOW);
		Delay_us(10000-time);

		if(subindo ==1){
			time =time +passo;
			if(time >=10000){
				subindo =0;
			}

		}	else{
				time= time-passo;
				if(time<=0){
					subindo =1;
				}
			}
		}



}

void questao5(){
	Utility_Init();

	GPIO_Clock_Enable(GPIOA);
	GPIO_Pin_Mode(GPIOA, PIN_1, OUTPUT);
	GPIO_Pin_Mode(GPIOA, PIN_2, OUTPUT);
	GPIO_Pin_Mode(GPIOA, PIN_3, OUTPUT);


	while(1){
		for(int i = 0;i <7;i++){

			if(i & 0x01){
				GPIO_Write_Pin(GPIOA, PIN_1, HIGH);
			}else{
				GPIO_Write_Pin(GPIOA, PIN_1, LOW);
			}

			if(i & 0x02){
				GPIO_Write_Pin(GPIOA, PIN_2, HIGH);
			}else{
				GPIO_Write_Pin(GPIOA, PIN_2, LOW);
			}
			if(i & 0x04){
				GPIO_Write_Pin(GPIOA, PIN_3, HIGH);
			}else{
				GPIO_Write_Pin(GPIOA, PIN_3, LOW);
					}
			Delay_ms(1000);

			}
		}




	}

void questao6(){

	Utility_Init();

	GPIO_Clock_Enable(GPIOA);
	GPIO_Pin_Mode(GPIOA, PIN_1, OUTPUT);
	GPIO_Pin_Mode(GPIOA, PIN_2, OUTPUT);

	int time = 0;
	int passo = 100;
	int subindo = 1;


	while(1){

		GPIO_Write_Pin(GPIOA,PIN_1,HIGH);
		GPIO_Write_Pin(GPIOA, PIN_2, LOW);
		Delay_us(time);

		GPIO_Write_Pin(GPIOA, PIN_1,LOW);
	GPIO_Write_Pin(GPIOA, PIN_2,HIGH);
		Delay_us(10000-time);

		if(subindo ==1){
			time =time +passo;
			if(time >=10000){
				subindo =0;
			}

		}	else{
				time= time-passo;
				if(time<=0){
					subindo =1;
				}
			}
		}
	}


void questao7(){

	Utility_Init();

	GPIO_Clock_Enable(GPIOA);

	GPIO_Pin_Mode(GPIOA, PIN_1, OUTPUT);
	GPIO_Pin_Mode(GPIOA, PIN_2, OUTPUT);
	GPIO_Pin_Mode(GPIOA, PIN_3, OUTPUT);
	GPIO_Pin_Mode(GPIOA, PIN_4, OUTPUT);
	GPIO_Pin_Mode(GPIOA, PIN_5, OUTPUT);
	GPIO_Pin_Mode(GPIOA, PIN_6, OUTPUT);
	GPIO_Pin_Mode(GPIOA, PIN_7, OUTPUT);


	while(1){

		for(int count =0; count<=255;count ++){

			GPIO_Write_Port(GPIOA,count );

			Delay_ms(200);
		}
	}

}

void questao8(){
	Utility_Init();

		GPIO_Clock_Enable(GPIOA);
		GPIO_Clock_Enable(GPIOB);
		GPIO_Pin_Mode(GPIOA, PIN_1, OUTPUT);
		GPIO_Pin_Mode(GPIOA, PIN_2, OUTPUT);
		GPIO_Pin_Mode(GPIOA, PIN_3, OUTPUT);
		GPIO_Pin_Mode(GPIOA, PIN_4, OUTPUT);
		GPIO_Pin_Mode(GPIOA, PIN_5, OUTPUT);
		GPIO_Pin_Mode(GPIOA, PIN_6, OUTPUT);
		GPIO_Pin_Mode(GPIOB, PIN_1, OUTPUT);
		GPIO_Pin_Mode(GPIOB, PIN_2, OUTPUT);

		while(1){

			GPIO_Write_Pin(GPIOA, PIN_1, HIGH);
			Delay_ms(100);
			GPIO_Write_Pin(GPIOA, PIN_1, LOW);
			GPIO_Write_Pin(GPIOA, PIN_2, HIGH);
			Delay_ms(100);

			GPIO_Write_Pin(GPIOA, PIN_2, LOW);
			GPIO_Write_Pin(GPIOA, PIN_3, HIGH);
			Delay_ms(100);
			GPIO_Write_Pin(GPIOA, PIN_3, LOW);
			GPIO_Write_Pin(GPIOA, PIN_4, HIGH);
			Delay_ms(100);
			GPIO_Write_Pin(GPIOA, PIN_4, LOW);
			GPIO_Write_Pin(GPIOA, PIN_5, HIGH);
			Delay_ms(100);

			GPIO_Write_Pin(GPIOA, PIN_5, LOW);
			GPIO_Write_Pin(GPIOA, PIN_6, HIGH);
			Delay_ms(100);
			GPIO_Write_Pin(GPIOA, PIN_6, LOW);
			GPIO_Write_Pin(GPIOB, PIN_1, HIGH);
			Delay_ms(100);
			GPIO_Write_Pin(GPIOB, PIN_1, LOW);
			GPIO_Write_Pin(GPIOB, PIN_2, HIGH);
			Delay_ms(100);
			GPIO_Write_Pin(GPIOB, PIN_2, LOW);



			GPIO_Write_Pin(GPIOB, PIN_1, HIGH);
			Delay_ms(100);
			GPIO_Write_Pin(GPIOB, PIN_1, LOW);
			GPIO_Write_Pin(GPIOA, PIN_6, HIGH);
			Delay_ms(100);
			GPIO_Write_Pin(GPIOA, PIN_6, LOW);
			GPIO_Write_Pin(GPIOA, PIN_5, HIGH);
			Delay_ms(100);
			GPIO_Write_Pin(GPIOA, PIN_5, LOW);
			GPIO_Write_Pin(GPIOA, PIN_4, HIGH);
			Delay_ms(100);
			GPIO_Write_Pin(GPIOA, PIN_4, LOW);
			GPIO_Write_Pin(GPIOA, PIN_3, HIGH);
			Delay_ms(100);
			GPIO_Write_Pin(GPIOA, PIN_3, LOW);
			GPIO_Write_Pin(GPIOA, PIN_2, HIGH);
			Delay_ms(100);
			GPIO_Write_Pin(GPIOA, PIN_2, LOW);


			}

			}


void questao9(){



	Utility_Init();

		GPIO_Clock_Enable(GPIOA);
		GPIO_Clock_Enable(GPIOB);
		GPIO_Pin_Mode(GPIOA, PIN_1, OUTPUT);
		GPIO_Pin_Mode(GPIOA, PIN_2, OUTPUT);
		GPIO_Pin_Mode(GPIOA, PIN_3, OUTPUT);
		GPIO_Pin_Mode(GPIOA, PIN_4, OUTPUT);
		GPIO_Pin_Mode(GPIOA, PIN_5, OUTPUT);
		GPIO_Pin_Mode(GPIOA, PIN_6, OUTPUT);


		while(1){

			GPIO_Write_Pin(GPIOA, PIN_5, LOW);
			GPIO_Write_Pin(GPIOA, PIN_1, LOW);
			GPIO_Write_Pin(GPIOA, PIN_2, LOW);
			GPIO_Write_Pin(GPIOA, PIN_6, LOW);

			GPIO_Write_Pin(GPIOA, PIN_3, HIGH);//VERDE-LIGOU
			GPIO_Write_Pin(GPIOA, PIN_4, HIGH);//VERMELHO  - LIGOU
			Delay_ms(5000);
			GPIO_Write_Pin(GPIOA, PIN_3, LOW); // VERDE = OF
			GPIO_Write_Pin(GPIOA, PIN_2, HIGH);
			GPIO_Write_Pin(GPIOA, PIN_4, HIGH);
			Delay_ms(5000);
			GPIO_Write_Pin(GPIOA, PIN_3, LOW);
			GPIO_Write_Pin(GPIOA, PIN_4, LOW);
			GPIO_Write_Pin(GPIOA, PIN_2, LOW);
			GPIO_Write_Pin(GPIOA, PIN_1, HIGH);
			GPIO_Write_Pin(GPIOA, PIN_6, HIGH);
			Delay_ms(5000);
			GPIO_Write_Pin(GPIOA, PIN_6, LOW);
			GPIO_Write_Pin(GPIOA, PIN_5, HIGH);
			GPIO_Write_Pin(GPIOA, PIN_1, HIGH);
			Delay_ms(5000);



			}

void questao10(void) {
    Utility_Init();
    GPIO_Clock_Enable(GPIOA);
    GPIO_Clock_Enable(GPIOE);


    GPIO_Pin_Mode(GPIOA, PIN_1, OUTPUT);
    GPIO_Pin_Mode(GPIOA, PIN_2, OUTPUT);
    GPIO_Pin_Mode(GPIOA, PIN_3, OUTPUT);
    GPIO_Pin_Mode(GPIOA, PIN_4, OUTPUT);
    GPIO_Pin_Mode(GPIOA, PIN_5, OUTPUT);


    GPIO_Resistor_Enable(GPIOE, PIN_3, PULL_UP);
    GPIO_Pin_Mode(GPIOE, PIN_3, INPUT);


    EXTI_Config(EXTI3, GPIOE, FALLING_EDGE);
    NVIC_EnableIRQ(EXTI3_IRQn);

    int estado_veiculo = 0;

    while(1) {

        GPIO_Write_Pin(GPIOA, PIN_4, LOW);
        GPIO_Write_Pin(GPIOA, PIN_5, HIGH);

        if(estado_veiculo == 0) {

            GPIO_Write_Pin(GPIOA, PIN_1, HIGH);
            GPIO_Write_Pin(GPIOA, PIN_2, LOW);
            GPIO_Write_Pin(GPIOA, PIN_3, LOW);

            for(int i = 0; i < 400; i++) {
                if(solicitacao_pedestre == 1) break;
                Delay_ms(10);
            }
            estado_veiculo = 1;
        }
        else if(estado_veiculo == 1) {

            GPIO_Write_Pin(GPIOA, PIN_1, LOW);
            GPIO_Write_Pin(GPIOA, PIN_2, HIGH);
            GPIO_Write_Pin(GPIOA, PIN_3, LOW);

            for(int i = 0; i < 200; i++) {
                Delay_ms(10);
            }
            estado_veiculo = 2;
        }
        else if(estado_veiculo == 2) {

            GPIO_Write_Pin(GPIOA, PIN_1, LOW);
            GPIO_Write_Pin(GPIOA, PIN_2, LOW);
            GPIO_Write_Pin(GPIOA, PIN_3, HIGH);


            Delay_ms(2000);


            if(solicitacao_pedestre == 1) {


                GPIO_Write_Pin(GPIOA, PIN_5, LOW);
                GPIO_Write_Pin(GPIOA, PIN_4, HIGH);
                Delay_ms(3000);

                GPIO_Write_Pin(GPIOA, PIN_4, LOW);
                for(int i = 0; i < 4; i++) {
                    GPIO_Write_Pin(GPIOA, PIN_5, HIGH);
                    Delay_ms(250);
                    GPIO_Write_Pin(GPIOA, PIN_5, LOW);
                    Delay_ms(250);
                }


                solicitacao_pedestre = 0;
            }
            estado_veiculo = 0;
        }
    }
}

}

void questao11(){

	Utility_Init();

	GPIO_Clock_Enable(GPIOD);
	GPIO_Pin_Mode(GPIOD, PIN_0, OUTPUT);
	GPIO_Pin_Mode(GPIOD, PIN_1, OUTPUT);
	GPIO_Pin_Mode(GPIOD, PIN_2, OUTPUT);
	GPIO_Pin_Mode(GPIOD, PIN_3, OUTPUT);
	GPIO_Pin_Mode(GPIOD, PIN_4, OUTPUT);
	GPIO_Pin_Mode(GPIOD, PIN_5, OUTPUT);
	GPIO_Pin_Mode(GPIOD, PIN_6, OUTPUT);

	while(1){

		for(int i =0;i<15;i++){

				GPIO_Write_Port(GPIOD, ~mask[i]);
				Delay_ms(1000);

		}


		for(int i =15;i>0;i--){

						GPIO_Write_Port(GPIOD, ~mask[i]);
						Delay_ms(1000);

				}
			}


	}


void questao12(){

	Utility_Init();
	LCD_Init(4,20);
	int cont = 0;


	LCD_Write_String(1, 1, "CAROL");


	 while(1){


}
}
/* USER CODE END 0 */


void questao13(){

	Utility_Init();


	    GPIO_Clock_Enable(GPIOA);
	    GPIO_Pin_Mode(GPIOA, PIN_1, OUTPUT);

	    while(1) {


	        for(int tempo_alto = 500; tempo_alto <= 2500; tempo_alto = tempo_alto + 10) {


	            GPIO_Write_Pin(GPIOA, PIN_1, HIGH);
	            Delay_us(tempo_alto);

	            GPIO_Write_Pin(GPIOA, PIN_1, LOW);
	            Delay_us(20000 - tempo_alto);
	        }


	        for(int tempo_alto = 2500; tempo_alto >= 500; tempo_alto = tempo_alto - 10) {


	            GPIO_Write_Pin(GPIOA, PIN_1, HIGH);
	            Delay_us(tempo_alto);

	            GPIO_Write_Pin(GPIOA, PIN_1, LOW);
	            Delay_us(20000 - tempo_alto);
	        }


}
}
void questao14(){

	int duty;

	    Utility_Init();


	    GPIO_Clock_Enable(GPIOA);
	    GPIO_Pin_Mode(GPIOA, PIN_1, OUTPUT);
	    GPIO_Output_Type(GPIOA, PIN_1, PUSH_PULL);
	    GPIO_Pin_Mode(GPIOA, PIN_2, OUTPUT);
	    GPIO_Output_Type(GPIOA, PIN_2, PUSH_PULL);
	    GPIO_Pin_Mode(GPIOA, PIN_3, ALTERNATE);
	    GPIO_Alternate_Function(GPIOA, PIN_3, 2);

	    RCC->APB1ENR |= RCC_APB1ENR_TIM5EN;
	    TIM5->PSC = 83;
	    TIM5->ARR = 499;
	    TIM5->CCMR2 &= ~(0b111 << 12);
	    TIM5->CCMR2 |= (0b110 << 12);
	    TIM5->CCMR2 |= TIM_CCMR2_OC4PE;
	    TIM5->CCER |= TIM_CCER_CC4E;
	    TIM5->CCR4 = 0;
	    TIM5->EGR = TIM_EGR_UG;
	    TIM5->CR1 |= TIM_CR1_CEN;

	    while(1) {

	        // --- SENTIDO 1 ---
	        GPIO_Write_Pin(GPIOA, PIN_1, LOW);
	        GPIO_Write_Pin(GPIOA, PIN_2, HIGH);

	        for(duty = 0; duty <= 499; duty++) {
	            TIM5->CCR4 = duty;
	            Delay_ms(10);
	        }

	        for(duty = 499; duty >= 0; duty--) {
	            TIM5->CCR4 = duty;
	            Delay_ms(10);
	        }

	        // --- SENTIDO 2 ---
	        GPIO_Write_Pin(GPIOA, PIN_1, HIGH);
	        GPIO_Write_Pin(GPIOA, PIN_2, LOW);

	        for(duty = 0; duty <= 499; duty++) {
	            TIM5->CCR4 = duty;
	            Delay_ms(10);
	        }

	        for(duty = 499; duty >= 0; duty--) {
	            TIM5->CCR4 = duty;
	            Delay_ms(10);
	        }
	    }
}
void questao15(){

	Utility_Init();
	GPIO_Clock_Enable(GPIOA);
	GPIO_Pin_Mode(GPIOA,PIN_1,OUTPUT);


	GPIO_Clock_Enable(GPIOE);
	GPIO_Pin_Mode(GPIOE, PIN_3, INPUT);
	GPIO_Resistor_Enable(GPIOE, PIN_3, PULL_UP);
	int estado =0;


	while(1){

		Delay_ms(50);

		if(!GPIO_Read_Pin(GPIOE,PIN_3)){

			if(estado==0){
				estado=1;
				GPIO_Write_Pin(GPIOA,PIN_1,HIGH);

			}else{
				estado=0;
				GPIO_Write_Pin(GPIOA,PIN_1,LOW);
			}
		}
	}

	}


void questao16(void) {
    Utility_Init();


    GPIO_Clock_Enable(GPIOA);
    GPIO_Pin_Mode(GPIOA, PIN_1, OUTPUT);
    GPIO_Clock_Enable(GPIOE);
    GPIO_Pin_Mode(GPIOE, PIN_3, INPUT);
    GPIO_Resistor_Enable(GPIOE, PIN_3, PULL_UP);
    GPIO_Pin_Mode(GPIOE, PIN_4, INPUT);
    GPIO_Resistor_Enable(GPIOE, PIN_4, PULL_UP);
	GPIO_IntRegister(GPIOE, PIN_3, minha_isr, FALLING_EDGE);
    NVIC_EnableIRQ(EXTI3_IRQn);

    int estado = 0;
    while (1) {
        if (!GPIO_Read_Pin(GPIOE, PIN_4) && estado == 0) {
        	int tempo = 0;

            for (int i = 0; i <= 20; i++) {

            	tempo++;

                if (!GPIO_Read_Pin(GPIOE, PIN_4) && !GPIO_Read_Pin(GPIOE, PIN_3) && estado == 0 && tempo<=5) {
                    estado = 1;
                    GPIO_Write_Pin(GPIOA, PIN_1, HIGH);
                } else if (estado == 0){
                	GPIO_Write_Pin(GPIOA, PIN_1, LOW);
                }
                Delay_ms(100);
            }


            if (estado == 1 && (GPIO_Read_Pin(GPIOE, PIN_4) || GPIO_Read_Pin(GPIOE, PIN_3))) {
                estado = 0;
                GPIO_Write_Pin(GPIOA, PIN_1, LOW);
            }
        }
    }
}


void questao17(){

	Utility_Init();

    GPIO_Clock_Enable(GPIOA);
    GPIO_Pin_Mode(GPIOA, PIN_1, OUTPUT);
    GPIO_Pin_Mode(GPIOA, PIN_2, OUTPUT);
    GPIO_Clock_Enable(GPIOE);
    GPIO_Pin_Mode(GPIOE, PIN_3, INPUT);
    GPIO_Resistor_Enable(GPIOE, PIN_3, PULL_UP);
    GPIO_Pin_Mode(GPIOE, PIN_4, INPUT);
    GPIO_Resistor_Enable(GPIOE, PIN_4, PULL_UP);
    int estado = 0;
    GPIO_Pin_Mode(GPIOA, PIN_3, INPUT);
    GPIO_Resistor_Enable(GPIOA, PIN_3, PULL_UP);

    while(1){

    	if(!GPIO_Read_Pin(GPIOE, PIN_3) && estado ==0){

    		GPIO_Write_Pin(GPIOA, PIN_1, HIGH);
    		estado=1;
    	}
    	if(!GPIO_Read_Pin(GPIOE, PIN_4) && estado ==0){

    	    	GPIO_Write_Pin(GPIOA, PIN_2, HIGH);
    	    	estado=1;
    	}
    	if(!GPIO_Read_Pin(GPIOA, PIN_3) && estado ==1){

    		GPIO_Write_Pin(GPIOA, PIN_1, LOW);
    		GPIO_Write_Pin(GPIOA, PIN_2, LOW);
    		estado=0;
    	}



    }
}



void questao18(){

	Utility_Init();
	    GPIO_Clock_Enable(GPIOA);
	    GPIO_Clock_Enable(GPIOE);
	    GPIO_Pin_Mode(GPIOA, PIN_1, OUTPUT);
	    GPIO_Pin_Mode(GPIOE, PIN_3, INPUT);
	    GPIO_Resistor_Enable(GPIOE, PIN_3, PULL_UP);
	    GPIO_Pin_Mode(GPIOE, PIN_4 , INPUT);
	    GPIO_Resistor_Enable(GPIOE, PIN_4, PULL_UP);

	    while(1) {



	    	if (!GPIO_Read_Pin(GPIOE, PIN_4)){


	            GPIO_Write_Pin(GPIOA, PIN_1, HIGH);
	            Delay_us(500);

	            GPIO_Write_Pin(GPIOA, PIN_1, LOW);
	            Delay_us(1950);


	    	}

	    	if(!GPIO_Read_Pin(GPIOE, PIN_3)){



	            GPIO_Write_Pin(GPIOA, PIN_1, HIGH);
	            Delay_us(2500);

	            GPIO_Write_Pin(GPIOA, PIN_1, LOW);
	            Delay_us(17500 );



	    	}
}

}


void questao20(){

	Utility_Init();
	    GPIO_Clock_Enable(GPIOA);
	    GPIO_Pin_Mode(GPIOA, PIN_1, OUTPUT);
	    GPIO_Write_Pin(GPIOA, PIN_1, LOW);
	    GPIO_Pin_Mode(GPIOA, PIN_6, OUTPUT);
	    GPIO_Pin_Mode(GPIOA, PIN_7, INPUT);


	    GPIO_Resistor_Enable(GPIOA, PIN_7, PULL_DOWN);

	    int distancia_cm = 0;
	    int tempo_eco = 0;
	    int timeout = 0;

	    while(1) {


	        GPIO_Write_Pin(GPIOA, PIN_6, LOW);
	        Delay_us(2);
	        GPIO_Write_Pin(GPIOA, PIN_6, HIGH);
	        Delay_us(10);
	        GPIO_Write_Pin(GPIOA, PIN_6, LOW);


	        timeout = 10000;
	        while(!GPIO_Read_Pin(GPIOA, PIN_7) && timeout > 0) {
	            Delay_us(1);
	            timeout--;
	        }


	        tempo_eco = 0;

	        while(GPIO_Read_Pin(GPIOA, PIN_7) && tempo_eco < 30000) {
	            Delay_us(1);
	            tempo_eco++;
	        }


	        distancia_cm = tempo_eco / 58;



	        if (distancia_cm > 50 || distancia_cm == 0) {

	            GPIO_Write_Pin(GPIOA, PIN_1, LOW);
	            Delay_ms(100);
	        }
	        else if (distancia_cm > 40 && distancia_cm <= 50) {

	            GPIO_Write_Pin(GPIOA, PIN_1, HIGH);
	            Delay_ms(500);
	            GPIO_Write_Pin(GPIOA, PIN_1, LOW);
	            Delay_ms(500);
	        }
	        else if (distancia_cm > 20 && distancia_cm <= 40) {

	            GPIO_Write_Pin(GPIOA, PIN_1, HIGH);
	            Delay_ms(200);
	            GPIO_Write_Pin(GPIOA, PIN_1, LOW);
	            Delay_ms(200);
	        }
	        else if (distancia_cm <= 20) {

	            GPIO_Write_Pin(GPIOA, PIN_1, HIGH);
	            Delay_ms(50);
	            GPIO_Write_Pin(GPIOA, PIN_1, LOW);
	            Delay_ms(50);
	        }
	    }
}



void aula01_09(){

	Utility_Init();


	GPIO_Clock_Enable(GPIOF);
	GPIO_Pin_Mode(GPIOF, PIN_9, OUTPUT);


	GPIO_Clock_Enable(GPIOE);
	GPIO_Pin_Mode(GPIOE, PIN_3, INPUT);
	GPIO_Resistor_Enable(GPIOE, PIN_3, PULL_UP);

	int time = 1000;
	while(1){


		if (!GPIO_Read_Pin(GPIOE,PIN_3 )){
			if(time ==1000){
				time = 100;
			}else{
				 time=1000;
			}
		}

	GPIO_Write_Pin(GPIOF, PIN_9, LOW);
		Delay_ms(time);


		GPIO_Write_Pin(GPIOF, PIN_9, HIGH);
		Delay_ms(time);





		//if(!!GPIO_Read_Pin(GPIOE,PIN_3  )&& estado ==1){
		// Liga o LED (Nessas placas, LOW costuma ligar o LED)
		//GPIO_Write_Pin(GPIOF, PIN_9, LOW);
		//Delay_ms(1000);

		// Desliga o LED
		//GPIO_Write_Pin(GPIOF, PIN_9, HIGH);
		//Delay_ms(100);

		//estado =0;


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
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
//questao3();
//questao6();
//questao8();
//questao9();
//questao4();
//questao5();
//questao12();
//questao11();
//questao7();
//questao10();
//questao15();
//questao16();
//questao13();
//questao18();
//questao17();
// questao20();
//questao14();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
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





void EXTI3_IRQHandler(void) {
    Delay_ms(50);
    solicitacao_pedestre = 1;
    EXTI_Clear_Pending(EXTI3);
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
