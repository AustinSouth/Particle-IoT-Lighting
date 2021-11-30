// This #include statement was automatically added by the Particle IDE.
#include <HC_SR04.h>

int cm = 0;
int cm2 = 0;
int trigPin = D4;
int echoPin = D5;

int var1;
int varold1;
int var2;
int varold2;
int var3;
int varold3;

int on = 1;
int off = 0;

int data1val = 0;

HC_SR04 rangeFinder = HC_SR04(trigPin, echoPin);


void setup() {
    Particle.subscribe("Alex", dis2); // this is the security feature
    pinMode(D7, OUTPUT);
}

void loop() {
  //this part of the code compares values from the sensor and publishes the output if the sensor value changes range
    cm = rangeFinder.getDistanceCM();
    
    
    if (cm>0 && cm<50){
        var1 = 1;
    }
    else if(cm == -1){
        var1 = var1; 
    }
        else{
                var1 = 2;
        }
        
        
    if (cm>=100 && cm<150){
        var2 = 1;
    }
    else if(cm == -1){
        var2 = var2; 
    }
    else{
                var2 = 2;
    }
        
        
        if(var1 != varold1 || var2 != varold2){
                Particle.publish( "Outlet1", (String (cm)));
        }
        
        delay(1500);
        
       
        varold1 = var1;
        varold2 = var2;
        varold3 = var3;

}

void dis2(const char *event, String data){
    //this part of the code turns on the LED when a person is in front of the Alex device 
    int data1val;
	data1val = String(data).toInt(); 
		if(data1val == 1){
		    digitalWrite(D7, HIGH);
		}
		else
		{
		    digitalWrite(D7, LOW);
		}

}



