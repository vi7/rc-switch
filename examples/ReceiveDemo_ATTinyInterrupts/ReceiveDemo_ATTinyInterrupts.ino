/*
  Simple example for receiving on ATTiny85 using pin change interrupt

  This allows to connect receiver to literally any ATTiny pin
  and not only INTO (PB2) imposed by mySwitch.enableReceive(0)
  It makes sense because PB2 might not always be available.
  For example it used as Serial TX with Digistump dtiny core

  https://github.com/sui77/rc-switch/
*/

#include <RCSwitch.h>

#define RX_PIN PB0

RCSwitch mySwitch = RCSwitch();

void setupInterrupts() {
  noInterrupts();
  bitClear(GIMSK, INT0);  // disable INT0 external interrupt
  bitSet(GIMSK, PCIE);    // enable pin change interrupt (PCI)
  bitSet(PCMSK, RX_PIN);  // activate PCI for the specific pin
  interrupts();
}

void setup() {
  Serial.begin(9600);  // Serial TX for Digispark USB is on the PB2
  setupInterrupts();
}

void loop() {
  if (mySwitch.available()) {

    Serial.print("Received ");
    Serial.print( mySwitch.getReceivedValue() );
    Serial.print(" / ");
    Serial.print( mySwitch.getReceivedBitlength() );
    Serial.print("bit ");
    Serial.print("Protocol: ");
    Serial.println( mySwitch.getReceivedProtocol() );

    mySwitch.resetAvailable();
  }
}

/*
 * Interrupt handler
 */
ISR(PCINT0_vect) { RCSwitch::handleInterrupt(); }  // handleInterrupt() must be public for that
