// This #include statement was automatically added by the Particle IDE.
#include <elapsedMillis.h>

// This #include statement was automatically added by the Particle IDE.
#include <HC_SR04.h>

elapsedMillis timeElapsed;

unsigned int interval = 15000;

int cm = 0;

int trigPin = D10;
int echoPin = D11;

int var1;
int varold1;

int onB = 1;
int offB = 0;

int num = 0;
String lights = String(0);

HC_SR04 rangefinder = HC_SR04(trigPin, echoPin);

void setup()
{
    Particle.subscribe("Outlet1", Outlet1val);

	            
}
void loop()
{
    
       //this section of code is designed to publish the current number of lights to thinkspeak
     if(num > 3){
        num = 3;
    }
    else if(num < 0){
        num = 0;
    }
    
    String lights = String(num); 
    
  if (timeElapsed > interval) 
  {				
      Particle.publish("lights", lights, PRIVATE);
      timeElapsed = 0;             
  }
        //this part of the code compares the information directly from the Alex ultrasonic sensor
        cm = rangefinder.getDistanceCM();
        
        
        if (cm>0 && cm<50){
            var1 = 1;
            }
            else if(cm == -1){
                 var1 = var1; 
                 //this part of the code is to prevent the "error" return value of -1 from affecting the code
            }
            else{
                var1 = 2;
            }
        
        
                if(var1 != varold1){
                    
                        if(var1 == 1){
                                num = num + 2;
                                pinMode(D8, OUTPUT);
	        	                digitalWrite(D8, 0);
	                        	delay(300);
	        	                digitalWrite(D8, 1);
	        	                
	        	                String gaurd = String(onB); 
	        	                Particle.publish( "Alex", gaurd, PRIVATE);
                               delay(500);
                        }
                         
                        else if(var1 == 2){
                                num = num - 1;
                                pinMode(D7, OUTPUT);
		                        digitalWrite(D7, 0);
		                        delay(300);
		                        digitalWrite(D7, 1);
		                        
		                        String gaurd = String(offB); 
		                        Particle.publish( "Alex", gaurd, PRIVATE);
                        }
            
                }
           varold1 = var1;
             delay(1100);
}
//this last part of the code takes data from the Taylor device and changes the lights in the Taylor area
void Outlet1val(const char *event, String data){
    
    int data1val;
		data1val = String(data).toInt(); 
		
	if (data1val>0 && data1val<50){
	    
	           num = num + 1;
                pinMode(D5, OUTPUT);
		        digitalWrite(D5, 0);
		        delay(500);
	        	digitalWrite(D5, 1);

	            
    }
    
    else if(data1val == -1)
    {
      
        
    }
        else{
                num = num - 1;
                pinMode(D6, OUTPUT);
	        	digitalWrite(D6, 0);
	        	delay(500);
	        	digitalWrite(D6, 1);
        }
        
        if (data1val>=100 && data1val<200){
	    
                    num = num + 1;
	                pinMode(D3, OUTPUT);
	                digitalWrite(D3, 0);
	                delay(300);
	                digitalWrite(D3, 1);
        }
        else if(data1val == -1)
        {
      
        
        }
        else{
                
                num = num - 1;
            	pinMode(D4, OUTPUT);
	        	digitalWrite(D4, 0);
	            delay(300);
	        	digitalWrite(D4, 1);
        }
       
}


       
		
		



