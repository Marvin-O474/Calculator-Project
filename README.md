# Calculator Project 
This repo features the code, schematic and video demonstration of the prototype of a basic arithmetic calculator. The components that where used  in this project are:
* A 16x2 LCD display 
* 1.1k ohms resistor (R1)
* 3.9k ohms resistor (R2)
* 240 ohms resistor (R3)
* A 4x4 keypad
* An Arduino Uno 
* A Breadboard
* Jumper wires

I design the project in autocad which is not commonly used for this purpose but what quite effective. The calcualtor can only compute two value and each value can only have a maximum length of 7 digits. It performs only basic arithmetic which would be addition, subtraction, multiplication and division. It cannot accept floating point values as input as there is no provision for that on the keypad but it can render floating point answers when the need arises (say when dividing 5 by 3) correct to 2 decimal places 

## Using one pin to read the Keypad
The initial design of the calculator made use of a single analog pin on the Arduino uno to interface with the keypad as input for the calcualator. This design made use of a voltage divider to vary the voltage which corresponded to keys on the keypad. This design proved to be unsuccessful because of the the transient fluctuatuion of voltages read by the pin form the voltage divider circuit. In other words, the voltages reading gotten form this method where too unstable for this to be a reliable means of reading the Keypad. 

## Future developments
I hope in future itiration to integrate a component tester into the design. 


