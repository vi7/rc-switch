# rc-switch
[![arduino-library-badge](https://www.ardu-badge.com/badge/rc-switch.svg?)](https://www.ardu-badge.com/rc-switch)
[![Build Status](https://travis-ci.org/sui77/rc-switch.svg?branch=master)](https://travis-ci.org/sui77/rc-switch)

Use your Arduino or [Raspberry Pi](https://github.com/r10r/rcswitch-pi) to operate remote radio controlled devices

## Fork notes

Differences of this fork from the [official library](https://github.com/sui77/rc-switch):
* Receiving support on ATTinyX5 chips, which was successfully tested on the ATTiny85.
Also see [examples/ReceiveDemo_ATTinyInterrupts](examples/ReceiveDemo_ATTinyInterrupts) for manual interrupts configuration
on the ATTiny85
* [ESP8266_RTOS_SDK framework v3.x](https://github.com/espressif/ESP8266_RTOS_SDK) support. Transmit only for now

### TODO

- Implement receiving for FreeRTOS
- Add FreeRTOS examples

## Download
https://github.com/sui77/rc-switch/releases/latest

rc-switch is also listed in the arduino library manager.

## Wiki
https://github.com/sui77/rc-switch/wiki

## Info
### Send RC codes

Use your Arduino or Raspberry Pi to operate remote radio controlled devices.
This will most likely work with all popular low cost power outlet sockets. If
yours doesn't work, you might need to adjust the pulse length.

All you need is a Arduino or Raspberry Pi, a 315/433MHz AM transmitter and one
or more devices with one of the supported chipsets:

 - SC5262 / SC5272
 - HX2262 / HX2272
 - PT2262 / PT2272
 - EV1527 / RT1527 / FP1527 / HS1527
 - Intertechno outlets
 - HT6P20X

### Receive and decode RC codes

Find out what codes your remote is sending. Use your remote to control your
Arduino.

All you need is an Arduino, a 315/433MHz AM receiver (altough there is no
instruction yet, yes it is possible to hack an existing device) and a remote
hand set.

For the Raspberry Pi, clone the https://github.com/ninjablocks/433Utils project to
compile a sniffer tool and transmission commands.
