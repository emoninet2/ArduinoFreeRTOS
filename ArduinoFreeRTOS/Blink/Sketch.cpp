/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>
#include "FreeRTOS.h"
#include "task.h"
/*End of auto generated code by Atmel studio */


//Beginning of Auto generated function prototypes by Atmel Studio
//End of Auto generated function prototypes by Atmel Studio

/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */

void thread_1( void *pvParameters ){
	while(1){
		digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
		vTaskDelay(500);              // wait for a second
		digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
		vTaskDelay(500);              // wait for a second
		Serial.println("Hello World\r\n");
	}

}

void thread_2( void *pvParameters ){
	DDRB |= (1<<DDB0);
	while(1){
		PORTB ^= (1<<PORTB0);
		vTaskDelay(2000);
	}
}

void thread_3( void *pvParameters ){
	DDRB |= (1<<DDB1);
	while(1){
		PORTB ^= (1<<PORTB1);
		vTaskDelay(200);
	}
}



// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600);
  // initialize digital pin 13 as an output.
	pinMode(13, OUTPUT);
  
  	//creating the threads
	xTaskCreate( thread_1, ( const char * ) "t1", 300, NULL, tskIDLE_PRIORITY, NULL );
	xTaskCreate( thread_2, ( const char * ) "t2", 100, NULL, tskIDLE_PRIORITY, NULL );
	xTaskCreate( thread_3, ( const char * ) "t3", 100, NULL, tskIDLE_PRIORITY, NULL );
  
	//starting the scheduler
	vTaskStartScheduler();
}

// the loop function runs over and over again forever
void loop() {
	//will never enter the infinite loop
}
