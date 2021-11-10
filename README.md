# GuidingCane
**by Dominic S., Qassim A., Zach S., Nathan M., Kierra C., and Erika J.**

Code for guiding cane vibrating navigation system for people with impaired vision.

Vibrating motor vibrates a certain number of times corresponding to the direction the user needs to turn based off of Google Maps GPS navigation:

- Turn right - vibrate once
- Turn left - vibrate twice
- Stop / Arrived at Destination - vibrate three times
- Before each turn, a beeeep-beep-beep pattern occurs

**To Do**
- Navigation System
- Connecting to phone
- Google Maps Integeration
- Handling JSON files from Google Maps API

## Notes and Resources

**Parts Used:**

1. Arduino UNO
2. Adafruit Bluefruit LE UART Module
3. 9V battery

**Google Maps Directions API**

https://developers.google.com/maps/documentation/directions/overview

**Google Maps API Arduino Library**

https://github.com/witnessmenow/arduino-google-maps-api

**JSON Handler (might need it to parse directions)**

https://github.com/squix78/json-streaming-parser

**Adafruit Bluetooth Module**

https://learn.adafruit.com/introducing-the-adafruit-bluefruit-le-uart-friend/
