/*
 *
 * GPS based Geiger-Muller tube click recorder
 *
 *
 *
 */

#include <TinyGPS++.h>

#define PIN_INTERRUPT 2
#define PIN_LED 13


TinyGPSPlus gps;

int clicks = 0;
int clickstotal = 0;
int clicksmin = 0;
int cpm;
int cpms[5] = {0,0,0,0,0};
long timerCPM;
int seconds = 0;

// the setup routine runs once when you press reset:
void setup()
{
	// initialize serial communication at 9600 bits per second:
	Serial.begin(9600);
	Serial1.begin(9600);

	// make the pushbutton's pin an input:

	pinMode(PIN_LED, OUTPUT);
	pinMode(PIN_INTERRUPT, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(PIN_INTERRUPT), count, FALLING);

	timerCPM = millis();
}



// the loop routine runs over and over again forever:
void loop()
{
	/*
	if(timerCPM + 1000 < millis())
	{


		seconds++;
		Serial.print("[");
		if(seconds > 12)
		{
			cpms[4] = clicks * 5;

			cpm = (cpms[0] + cpms[1] + cpms[2] + cpms[3] + cpms[4]) / 5;

			clicks = 0;
			seconds = 0;


			for(int x=0; x<4; x++)
			{
				Serial.print(" ");
				Serial.print(x);
				Serial.print("=");
				Serial.print(cpms[x]);
				cpms[x] = cpms[x+1];
			}
		}


		Serial.print("] seconds: ");
		Serial.print(seconds);
		Serial.print(" clicks: ");
		Serial.print(clicks);
		Serial.print(" CPM: ");
		Serial.print(cpm);
		Serial.print(" Total: ");
		Serial.println(clickstotal);

		timerCPM = millis();
	}
*/
	delay(100);
	digitalWrite(PIN_LED, LOW);


}



void count()
{
	clicks++;
	clickstotal++;
	digitalWrite(PIN_LED, HIGH);
	Serial.print("CLICK ");
	Serial.println(clicks);
}
