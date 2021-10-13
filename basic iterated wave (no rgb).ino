const int ledPin =  LED_BUILTIN;
int ledState = LOW;            
unsigned long previousMillis = 0;        
const long interval = 1000;
const int led_to_switch[10] = {11,10,2,3,4,5,6,7,8,9};
void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);

  for (int i=0; i<sizeof led_to_switch/sizeof led_to_switch[0]; i++) {
    pinMode(led_to_switch[i], OUTPUT);
    digitalWrite(led_to_switch[i], HIGH);
    Serial.println("Enabled");
  }

}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    if (ledState == LOW) {
      ledState = HIGH;
      digitalWrite(ledPin, ledState);
      for (int i=0; i<sizeof led_to_switch/sizeof led_to_switch[0]; i++) {
    		delay(100);
    		digitalWrite(led_to_switch[i], LOW);
   		 	Serial.println("Led OFF");
  	  }
    } else {
      ledState = LOW;
      digitalWrite(ledPin, ledState);
      for (int i=0; i<sizeof led_to_switch/sizeof led_to_switch[0]; i++) {
    	 delay(100);
    	 digitalWrite(led_to_switch[i], HIGH);
   		 Serial.println("Led ON");
  	  }
    }
  }
}
