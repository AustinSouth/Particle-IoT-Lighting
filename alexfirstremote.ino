// This #include statement was automatically added by the Particle IDE.
#include <HC_SR04.h>

/* Tinker
 * This is a simple application to read and toggle pins on a Particle device.
 * For the extended version of the Tinker app supporting more pins, see
 * https://github.com/particle-iot/device-os/blob/develop/user/applications/tinker/application.cpp
 */
double cm = 0.0;

int trigPin = D10;
int echoPin = D11;

int onB = 1;
int offB = 0;
/* Function prototypes -------------------------------------------------------*/
int outlet1on(String command);
int outlet1off(String command);
int outlet2on(String command);
int outlet2off(String command);
int outlet3on(String command);
int outlet3off(String command);
int num = 0;
String lights = String(0);

 HC_SR04 rangefinder = HC_SR04(trigPin, echoPin);

/* This function is called once at start up ----------------------------------*/
void setup()
{

	Particle.function("2Sring Lights OFF", outlet1off);
	Particle.function("1Sring Lights ON", outlet1on);
	Particle.function("4Lamp OFF", outlet2off);
	Particle.function("3Lamp ON", outlet2on);
	Particle.function("6Bedlights OFF", outlet3off);
	Particle.function("5Bedlights ON", outlet3on);
	Particle.function("8all OFF", alloff);
	Particle.function("7all ON", allon);
  

}
/* This function loops forever --------------------------------------------*/



void loop()
{
    if(num > 3){
        num = 3;
    }
    else if(num < 0){
        num = 0;
    }
        String lights = String(num);    
        Particle.publish("lights", lights, PRIVATE);
        //delay(15001);
        
        
        cm = rangefinder.getDistanceCM();
    String dis = String(cm); 
//    Particle.publish( "Alex", dis, PRIVATE);
    delay(1500);
}



int outlet1off(String command)
{
	    num = num - 1;
	    
        pinMode(D7, OUTPUT);
		digitalWrite(D7, 0);
		delay(200);
		digitalWrite(D7, 1);
		String gaurd = String(offB); 
	      //  	                Particle.publish( "Alex", gaurd, PRIVATE);
	        	           
		return 0;
		
		  
}


int outlet1on(String command)
{
    	num = num + 1;

        pinMode(D8, OUTPUT);
		digitalWrite(D8, 0);
		delay(200);
		digitalWrite(D8, 1);
		
		
		String gaurd = String(onB); 
	     //   	                Particle.publish( "Alex", gaurd, PRIVATE);
	      
		return 1;
	

}

//outlet 2
int outlet2on(String command)
{
    	num = num + 1;

        pinMode(D5, OUTPUT);
		digitalWrite(D5, 0);
		delay(300);
		digitalWrite(D5, 1);
		
		return 2;
}
int outlet2off(String command)
{
	    num = num - 1;

        pinMode(D6, OUTPUT);
		digitalWrite(D6, 0);
		delay(300);
		digitalWrite(D6, 1);
		return 3;
}


//outlet 3
int outlet3off(String command)
{
    	num = num - 1;

        pinMode(D4, OUTPUT);
		digitalWrite(D4, 0);
		delay(200);
		digitalWrite(D4, 1);
		return 4;
}
int outlet3on(String command)
{
        num = num + 1;
	
        pinMode(D3, OUTPUT);
		digitalWrite(D3, 0);
		delay(200);
		digitalWrite(D3, 1);
		return 5;
}

int alloff(String command)
{
	    pinMode(D7, OUTPUT);
		digitalWrite(D7, 0);
		delay(200);
		digitalWrite(D7, 1);
	     delay(400);
	     
	     pinMode(D6, OUTPUT);
		digitalWrite(D6, 0);
		delay(300);
		digitalWrite(D6, 1);
	    delay(400); 
	    
	    pinMode(D4, OUTPUT);
		digitalWrite(D4, 0);
		delay(200);
		digitalWrite(D4, 1);	           
		return 7;
		
		  
}



int allon(String command)
{
	    pinMode(D8, OUTPUT);
		digitalWrite(D8, 0);
		delay(200);
		digitalWrite(D8, 1);
		delay(400);
		
		 pinMode(D5, OUTPUT);
		digitalWrite(D5, 0);
		delay(300);
		digitalWrite(D5, 1);
		delay(400);
		
		pinMode(D3, OUTPUT);
		digitalWrite(D3, 0);
		delay(200);
		digitalWrite(D3, 1);
	        	           
		return 8;
		
		  
}
