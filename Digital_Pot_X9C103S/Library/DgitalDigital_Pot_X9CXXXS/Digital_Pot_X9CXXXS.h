#ifndef __Digital_Pot_X9CXXXS__
#define __Digital_Pot_X9CXXXS__

/************************************************************************/
/* This function will initialize the potentiometer's pin. it should be  */
/* called first before call other functions are associated with it. you */
/*should define your desired pin configuration in below function.       */
/************************************************************************/
void DPX9CXXXS_Init(){
/************************************************************************/
/*Port Defination :														*/
/* Define your port direction to use module (e.g.) DDRD					*/
#ifndef DIRECTIONPORT
	#define DIRECTIONPORT DDRD
#endif
/* Define your port operating to use module (e.g.) PORTD				*/
#ifndef CONTROLPORT
	#define CONTROLPORT PORTD
#endif
/*Warning:The Port operating and port direction should be the same port.*/
/************************************************************************/
/*Setup Port :															*/
/*Module's pin configuration "U/D"==>PD0 "INC"==>PD1 "CS"==>PD2         */
/*Pin direction : pin2:out   pin1:out   pin0:out						*/
DIRECTIONPORT |=  (1<<2)  |  (1<<1)  |  (1<<0);
/*Pin buffer status: 0v		   	0v			0v						    */
CONTROLPORT   |=  (0<<2)  |  (0<<1)  |  (0<<0);
/************************************************************************/
}

/************************************************************************/
/* This function will move up module's wiper(middle pin in mechanical   */
/* potentiometer) and it get an argument that is the steps number.but   */
/* the step value has a default value that is one.					    */
/************************************************************************/
void Pot_Up(uint8_t Step=1){
	
	for (;Step>0;Step--){
		sbi(CONTROLPORT,0);
		cbi(CONTROLPORT,2);
		_delay_us(100);
		cbi(CONTROLPORT,1);
		_delay_us(100);
		sbi(CONTROLPORT,1);
	}
	_delay_us(100);	
	sbi(CONTROLPORT,2);
}

/************************************************************************/
/* This function will move down module's wiper(middle pin in mechanical */
/* potentiometer) and it get an argument that is the steps number.but   */
/* the step value has a default value that is one.					    */
/************************************************************************/
void Pot_Down(uint8_t Step=1){
	
	for (;Step>0;Step--){
		cbi(CONTROLPORT,0);
		cbi(CONTROLPORT,2);
		_delay_us(100);
		cbi(CONTROLPORT,1);
		_delay_us(100);
		sbi(CONTROLPORT,1);
	}
	_delay_us(100);
	sbi(CONTROLPORT,2);
}

/************************************************************************/
/* This function will save your wiper's position that help you to retri-*/
/* eve the last wiper's position.										*/
/* warning: take care when you are using it. it may be damaged if you   */
/* use it all time. just use it when you are turning it off.			*/
/************************************************************************/
void Pot_Save_Pos(){
	
	sbi(CONTROLPORT,1);
	cbi(CONTROLPORT,2);
	_delay_us(100);
	sbi(CONTROLPORT,2);
	
}

#endif