# GLASS_CODE

:Author: rev_atomic
:Email: {scratchrev@gmail.com}
:Date: 22/10/2020
:Revision: version 4
:License: Public Domain

= Project: {Augmented Glasses}

This is a personal Google Glass-like glass without Google Assistant. This is very easy to build, and is cheap. It displays battery percentage,
network connection strength, and a clock in digital format and analog format. This connects to mobile device using bluetooth.

== Step 1: Installation
You can download the libraries from here:
https://github.com/adafruit/Adafruit_SSD1306
https://github.com/adafruit/Adafruit-GFX-Library
https://github.com/PaulStoffregen/SoftwareSerial
https://github.com/PaulStoffregen/Wire
https://github.com/PaulStoffregen/SPI

== Step 2: Assemble the circuit

Assemble the circuit following the diagram schematics.svg attached to the sketch

== Step 3: Load the code

Upload the code contained in the main arduino file on to your board

=== Folder structure

....
 Augmented_Glasses        =>  
 ar_glasses_code.ino      =>  
 schematics.svg           =>  
 ReadMe.md                =>  
....

=== Contributing: 
To contribute to this project please contact rev_atomic https://id.arduino.cc/rev_atomic

=== BOM: 
These are the components:


| Part name                         | Quantity
| OLED Display                      | 1
| HC-06 BLE module                  | 1
| Arduino Nano                      | 1
| Battery (rechargeable)            | 1
| Slide Switch (optional            | 1
| Jumper Wires                      | 11 (10 male to male, one female to female)
| Wires                             | 2   
| Magnets (optional)                | 4
| Glasses (metal if adding magnets) | 1
| Mirror                            | 1
| Lens                              | 6
|===


=== Help
This document is written in the _AsciiDoc_ format, a markup language to describe documents.
If you need help you can search the http://www.methods.co.nz/asciidoc[AsciiDoc homepage]
or consult the http://powerman.name/doc/asciidoc[AsciiDoc cheatsheet]
