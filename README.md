# Complex_Ohm_METer
COMET for short

Had a bunch of THT resistors so I took a minute to design (over-design) a simple PCB to quickly measure the value of those resistors. 

The method of operation is simple:
    Connect the PCB's output headers on a breadboard and then connect Vin to 5V (or whatever you want but be sure to change the #define Vcc in the beggining of the code)
GND to GND and Vmeas to arduino A1 (or whatever you want but again modify the code accordingly).
    Plug in your arduino and upload the code.
    Either put the THT resistor in the pin sockets or press it against the pin headers and hold there until you get 3-4 readings of the same value.
I tested it on A LOT of resistors and got some pretty good results. Even suprised myself on COMET's accuracy...

The purpose of this small PCB is to plug it onto a breadboard to easily and without using a bunch of cables and creating a multicolored spaghetti on your bench to batch measure THT resistances. 
I included in the code a set of known and common resistance values that I found on a reddit post (https://us.reddit.com/r/AskElectronics/wiki/starter_components/#wiki_resistors) and I used a simple logic to 
help Arduino decide the possible resistor value based on the analogRead value (based on this: https://projecthub.arduino.cc/xristos_xatz/ohm-meter-with-arduino-uno-5576cd). The logic I came up with was meant 
to be quick because I wanted to measure load of resistors to use on another project so it is not optimized time complexity-wise. But again it is a small matrix so the complexity O(N) is not harmfull to the application.
The code is kinda slopy but again it was a means to an end...

The logic is based on the differnce beteween the measured resistance and every value of the common_resistor_values array and a tolerance which I set to 10 (can be changed though, but 10 worked well for me). Whichever 
differnce is closest smallest this is the recommended resistor value.

Should an enthousiast reading this be interested, he/she could create a pull request to make the list of values dynamic and create a function to sort the list and maybe binary search? Works for me though so... 👍!

Layout was designed in KiCAD and it includes more pins to connect to the breadboard than used for possible upscaling needs in the future, like adding 2 pins on the breadboard to plug the resistor on the breadboard 
than just placing on the TPs of the PCB.
