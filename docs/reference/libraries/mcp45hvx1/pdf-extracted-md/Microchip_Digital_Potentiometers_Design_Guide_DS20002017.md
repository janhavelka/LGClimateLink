# Digital Potentiometers Design Guide Brochure - Extracted Text

- Source PDF: `../Microchip_Digital_Potentiometers_Design_Guide_DS20002017.pdf`
- Manufacturer URL: https://ww1.microchip.com/downloads/aemDocuments/documents/MSLD/ProductDocuments/Digital-Potentiometers-Design-Guide-Brochure-DS20002017.pdf
- Extraction date: 2026-05-09
- Page count: 20
- SHA256: `5F85E814DDB1324A7E7682B2E209508B6435F1416F28D9D158A92D5BBA8FBE95`
- Notes: Raw text extracted with pypdf. Tables, equations, and figures may require checking against the source PDF.

## Page 1

microchip.com
Digital Potentiometers 
Design Guide

## Page 2

microchip.com
2
Digital Potentiometer Solutions
Microchip’s Family of Digital Potentiometers
• End-to-end resistance (Rab) values
• 2.1 kΩ to 100 kΩ (typical)
• Resolution
• 6-bit (64 steps)
• 7-bit (128/129 steps)
• 8-bit (256/257 steps)
• 10-bit (1024 steps)
• Serial interfaces
• Up/down
• SPI
• I2C
• Memory types
• Volatile
• Non-volatile (EEPROM)
• Resistor network conﬁgurations
• Potentiometer (voltage divider)
• Rheostat (variable resistor)
• Single, dual and quad potentiometer options
• Different package options
• Special features
• Shutdown mode
• WiperLock™ technology
• Low-power options
• Low-voltage options (1.8V)
• High-voltage options (36V or ±18V)

## Page 3

Digital Potentiometers Design Guide
3
Microchip’s digital potentiometer portfolio offers a range of devices with end-to-end resistances between 2.1 and 100 kΩ, available 
in 6, 7, 8, or 10-bit resolutions. These devices are designed for easy integration using a mix of interface options. For straightforward 
applications, a simple up/down interface may suffice. Higher resolution devices often require direct read/write access to the 
wiper register, which is supported by SPI or I2C interfaces. While SPI is simpler to implement when only one Digipot is needed, I2C 
requires only two signals (pins) and better supports multiple devices on the same serial bus without additional pins.
Microchip provides both volatile and non-volatile (EEPROM) digital potentiometers, giving you the flexibility to optimize your system 
design. The integrated EEPROM option allows you to save potentiometer settings at power-down and restore them upon power-up.
A common Digipot use case is as a variable resistor (rheostat). In such cases, users only need access to one side of the resistor chain. 
Microchip offers dedicated rheostat products within the Digipot portfolio to support client needs in the most efficient manner. 
Alternatively, there are products such as the MCP42U83 which support a mix of conﬁgurations and interface options. This 
flexibility allows our clients to streamline inventory management while still meeting diverse application requirements.
Packaging options have been chosen to meet your system requirements, balancing device cost, board area, and manufacturing 
considerations (surface mount vs. through-hole).

## Page 4

microchip.com
4
Low-Power Applications
Low power consumption is increasingly important, 
especially in battery-powered applications. Microchip’s 
digital potentiometers are designed with low power 
in mind, featuring maximum Idd as low as 1 μA. The 
lowest current consumption is achieved when both 
the serial interface and non-volatile memory write 
cycle are inactive. Note that this current excludes any 
current through the resistor network (the A, B, and W 
pins). Review the Max Idd column in the Comprehensive 
portfolio table to identify the right product for your 
appllcation. 
Many devices also offer the capability to either shut 
down the resistor network or disconnect it from the 
circuit. This signiﬁcantly reduces the current through 
the resistor network(s). This shutdown mode can be 
activated either through a hardware pin (SHDN) or via 
software using the Terminal Control (TCON) register(s).
When hardware shutdown is engaged, the resistor 
network is forced into a deﬁned condition where it is 
disconnected from the Terminal A pin, and the wiper 
value is set to 00h (wiper connected to Terminal B). The 
wiper register retains its value, thus when the shutdown 
mode is exited, the wiper returns to its previous 
position. This feature is particularly useful in low-power 
applications where the potentiometer settings do not 
change during power down cycles.
Normal vs. Shutdown Mode
The software shutdown mode provides granular control 
over each of the resistor network terminal pins. Each 
resistor network is managed by a 4-bit TCON register, with 
one bit assigned to each terminal pin (A, B, and W) while 
the fourth bit replicates the hardware shutdown state. In 
this state, the resistor network is disconnected from the 
Terminal A pin, and the wiper value is set to 00h. 
The software shutdown mode offers greater flexibility 
than the hardware shutdown pin. It allows devices to 
retain shutdown capabilities even when packaged in the 
smallest form factors where a hardware shutdown pin 
(SHDN) is not implemented. This flexibility ensures that 
you can achieve power savings and maintain control over 
the resistor network conﬁguration, regardless of the 
package size. Normal vs. Shutdown Mode
Normal Mode ShutdownMode
A
W
B
W
A
B

## Page 5

Digital Potentiometers Design Guide
5
Low-Voltage Applications
Some applications require a low operating voltage. To meet these needs, Microchip offers a range of devices featuring digital circuitry 
supporting operation at 1.8V. Analog performance between 1.8V and 2.7V is not explicitly speciﬁed, but it has been characterized 
and reflected in datasheet graphs. These graphs provide the information needed to make informed design decisions for low-voltage 
applications.
The devices supporting Low Voltage applications can be found by looking for the entry 2/5 in the Comprehensive Portfolio table.

## Page 6

microchip.com
6
High-Voltage Applications
In some applications (industrial, audio, e.g.) operation at >5.5V is necessary. Microchip’s offers a family of digital potentiometers 
which address this need, supporting up to 36V operation. These devices feature dual power rails, with the analog voltage range 
determined by the voltage applied to the V and V− pins. Meanwhile, the digital power rail (VL and DGND) supports operation 
from 1.8V to 5.5V, ensuring proper communication with microcontrollers.
Dual rail can be conﬁgured as either symmetric (±18V, e.g.) or asymmetric ( 6V/−30V, e.g.), relative to the digital logic ground (DGND). 
The devices supporting High Voltage applications can be found by looking for the entry <36V in the Comprehensive Portfolio table

## Page 7

Digital Potentiometers Design Guide
7
Non-Volatile Applications
Non-volatile digital potentiometers offer the advantage of saving the desired wiper position during device power-down or 
brownout conditions. When power is restored, the wiper value automatically loads from the non-volatile register, so the device 
powers on with the desired wiper settings intact.
This feature is particularly useful in applications where the wiper value is programmed once and remains unchanged (such as system 
calibration) as well as in applications where the last user setting needs to be saved upon system power-down (such as a volume setting).
Traditionally, mechanical trim pots have been used for device calibration to optimize system performance. Digital 
potentiometers with non-volatile memory are smaller in size with higher reliability. Microchip’s non-volatile digital 
potentiometers utilize a methodology called WiperLock technology, which ensures that once the non-volatile wiper is “locked,” 
the wiper setting can only be modiﬁed with “high-voltage” commands. This precludes unintentional changes to the wiper setting 
during normal operation.
Many of the non-volatile devices include bytes of general-purpose EEPROM memory. This memory can store system information 
such as calibration codes, manufacture dates, serial numbers, or user information.
WiperLock™ Technology Example (up/Down Interface)
WiperLock
Technology
Disabled
EEPROM
V��
twc
x + 4
x + 4x + 3x + 2x + 1x
x x x x x
x
x
x
V��
V��
V��
V��
Wiper
WiperLock
Technology
Enabled
CS
U/D
EEPROM
Wiper
5511 22 33 44 66

## Page 8

microchip.com
8
Small-Footprint Applications
For applications with package-size constraints or where board-space is limited, Microchip provides a variety of compact 
packages, enabling designers to optimize board space without compromising functionality.
Package Area (mm2) Comment
MSOP ~14.7
DFN (3 × 3) ~9 39% Smaller than MSOP
SOT-23 ~8.3 44% Smaller than MSOP
DFN (2 × 3) ~6 59% Smaller than MSOP 33% Smaller than DFN 3 × 3
SC70 ~4.2 71% Smaller than MSOP 55% Smaller than DFN 3 × 3
30% Smaller than DFN 2 × 3
MSOP DFN DFN SC70SOT-23
3 mm
3 mm 3 mm 3 mm 2.1 mm
2 mm2 mm3 mm2.95 mm
4.9 mm

## Page 9

Digital Potentiometers Design Guide
9
SPI Interface
SPI requires three or four I/O pins. Use cases are depicted below. Many microcontrollers support SPI as a hardware module, 
simplifying code development. 
R
Controller to Single Peripheral With
Multiplexed SDI and SDO Pins
Controller Peripheral
SDI/SDO
SCK
Controller to Single Peripheral
Controller to Multiple Peripheral (Multiple Chip Selects)
*This connection is optional and only required for read operations. *This connection is optional and only required for read operations.
*This connection is optional and only required for read operations. 
Additional circuitry may be required for ORing of the peripheral SDO signals based on the device selected.
CS
SDO
SDI*
SCK
CS
Controller Peripheral
SDI
SDO
SCK
CS
SDO
SCK
SDI*
CS
Controller Peripheral
SDI/SDO
SDO*
SCK
CS
Peripheral
SDI
SDO*
SCK
CS
SDO
SCK
SDI*
CS0
CS1

## Page 10

microchip.com
10
I2C Interface
The I2C interface is a two-wire protocol that supports read and write operations via two pins. Multiple devices can share the I2C 
bus, if each has a unique address. While I2C needs just two pins, it requires more ﬁrmware overhead than SPI. Many 
microcontrollers include a dedicated I2C hardware module, simplifying code development. 
Controller to Single Peripheral
Controller Peripheral
*This connection is optional and only required for read operations.
SDA
SCL
SDA
SCL
A0*
A1*
A2*
Controller to Multiple Peripheral (Multiple Chip Selects)
*This signal is device dependent, number of devices depends on number of address signals.
Controller Peripheral
SDA
A0*
A1*
A2*
SCL
Peripheral
SDA
A0*
A1*
A2*
SCL
SDA
SCL

## Page 11

Digital Potentiometers Design Guide
11
Interface Memory
bits
Ch
RAB (in kΩ) [1] Configuration Packages (pin count) [5] Max 
Idd
V 
Range
Device #
U/D
SPI
I2C
type
2.1
5
10
20
50
100
Pot
Rheo
SOT23
SC70
SOIC
MSOP
DFN
PDIP
TSSOP
QFN
VQFN
(μA) [2]
(V) [4]
MCP4011 Y N N V 6 1 Y Y Y N Y N Y N N/A N/A 8 8 8 N/A N/A N/A N/A 1 2/5
MCP4012 Y N N V 6 1 Y Y Y N Y N N Y 6 N/A N/A N/A N/A N/A N/A N/A N/A 1 2/5
MCP4013 Y N N V 6 1 Y Y Y N Y N Y (4) N 6 N/A N/A N/A N/A N/A N/A N/A N/A 1 2/5
MCP4014 Y N N V 6 1 Y Y Y N Y N N Y (4) 5 N/A N/A N/A N/A N/A N/A N/A N/A 1 2/5
MCP4017 N N Y V 7 1 N Y Y N Y Y N Y N/A 6 N/A N/A N/A N/A N/A N/A N/A 5 2/5
MCP4018 N N Y V 7 1 N Y Y N Y Y Y N N/A 6 N/A N/A N/A N/A N/A N/A N/A 5 2/5
MCP4019 N N Y V 7 1 N Y Y N Y Y N Y N/A 5 N/A N/A N/A N/A N/A N/A N/A 5 2/5
MCP4021 Y N N EE 6 1 Y Y Y N Y N Y N N/A N/A 8 8 8 N/A N/A N/A N/A 1 3/5
MCP4022 Y N N EE 6 1 Y Y Y N Y N N Y 6 N/A N/A N/A N/A N/A N/A N/A N/A 1 3/5
MCP4023 Y N N EE 6 1 Y Y Y N Y N Y (4) N 6 N/A N/A N/A N/A N/A N/A N/A N/A 1 3/5
MCP4024 Y N N EE 6 1 Y Y Y N Y N N Y (4) 5 N/A N/A N/A N/A N/A N/A N/A N/A 1 3/5
MCP40D17 N N Y V 7 1 N Y Y N Y Y N Y N/A 6 N/A N/A N/A N/A N/A N/A N/A 5 2/5
MCP40D18 N N Y V 7 1 N Y Y N Y Y Y N N/A 6 N/A N/A N/A N/A N/A N/A N/A 5 2/5
MCP40D19 N N Y V 7 1 N Y Y N Y Y N Y N/A 5 N/A N/A N/A N/A N/A N/A N/A 5 2/5
MCP41010 N Y N V 8 1 N N Y N N N Y N N/A N/A 8 N/A N/A 8 N/A N/A N/A 1 3/5
MCP41050 N Y N V 8 1 N N N N Y N Y N N/A N/A 8 N/A N/A 8 N/A N/A N/A 1 3/5
MCP41100 N Y N V 8 1 N N N N N Y Y N N/A N/A 8 N/A N/A 8 N/A N/A N/A 1 3/5
MCP4131 N Y N V 7 1 N Y Y N Y Y Y N N/A N/A N/A N/A 8 N/A N/A N/A N/A 5 2/5
MCP4132 N Y N V 7 1 N Y Y N Y Y N Y N/A N/A N/A N/A 8 N/A N/A N/A N/A 5 2/5
MCP4141 N Y N EE 7 1 N Y Y N Y Y Y N N/A N/A N/A N/A 8 N/A N/A N/A N/A 5 3/5
MCP4142 N Y N EE 7 1 N Y Y N Y Y N Y N/A N/A N/A N/A 8 N/A N/A N/A N/A 5 3/5
MCP4151 N Y N V 8 1 N Y Y N Y Y Y N N/A N/A N/A N/A 8 N/A N/A N/A N/A 5 2/5
MCP4152 N Y N V 8 1 N Y Y N Y Y N Y N/A N/A N/A N/A 8 N/A N/A N/A N/A 5 2/5
MCP4161 N Y N EE 8 1 N Y Y N Y Y Y N N/A N/A N/A N/A 8 N/A N/A N/A N/A 5 3/5
MCP4162 N Y N EE 8 1 N Y Y N Y Y N Y N/A N/A N/A N/A 8 N/A N/A N/A N/A 5 3/5
MCP41HV31 N Y N V 7 1 N Y Y N Y Y Y N N/A N/A N/A N/A 8 N/A N/A N/A N/A 5 ≤36
MCP41HV51 N Y N V 8 1 N Y Y N Y Y N Y N/A N/A N/A N/A 8 N/A N/A N/A N/A 5 ≤36
MCP42010 N Y N V 8 2 N N Y N N N Y N N/A N/A 8 N/A N/A 8 N/A N/A N/A 1 3/5
MCP42050 N Y N V 8 2 N N N N Y N Y N N/A N/A 8 N/A N/A 8 N/A N/A N/A 1 3/5
MCP42100 N Y N V 8 2 N N N N N Y Y N N/A N/A 8 N/A N/A 8 N/A N/A N/A 1 3/5
MCP4231 N Y N V 7 2 N Y Y N Y Y Y N N/A N/A 14 N/A N/A 14 14 16 N/A 5 2/5
MCP4232 N Y N V 7 2 N Y Y N Y Y N Y N/A N/A 14 N/A N/A 14 14 16 N/A 5 2/5
MCP4241 N Y N EE 7 2 N Y Y N Y Y Y N N/A N/A 14 N/A N/A 14 14 16 N/A 5 3/5
MCP4242 N Y N EE 7 2 N Y Y N Y Y N Y N/A N/A 14 N/A N/A 14 14 16 N/A 5 3/5
MCP4251 N Y N V 8 2 N Y Y N Y Y Y N N/A N/A 14 N/A N/A 14 14 16 N/A 5 2/5
MCP4252 N Y N V 8 2 N Y Y N Y Y N Y N/A N/A 14 N/A N/A 14 14 16 N/A 5 2/5
MCP4261 N Y N EE 8 2 N Y Y N Y Y Y N N/A N/A 14 N/A N/A 14 14 16 N/A 5 3/5
MCP4262 N Y N EE 8 2 N Y Y N Y Y N Y N/A N/A 14 N/A N/A 14 14 16 N/A 5 3/5
Comprehensive Digipot Portfolio

## Page 12

microchip.com
12
Interface Memory
bits
Ch
RAB (in kΩ) [1] Configuration Packages (pin count) [5] Max 
Idd
V 
Range
Device #
U/D
SPI
I2C
type
2.1
5
10
20
50
100
Pot
Rheo
SOT23
SC70
SOIC
MSOP
DFN
PDIP
TSSOP
QFN
VQFN
(μA) [2]
(V) [4]
MCP4331 N Y N V 7 4 N Y Y N Y Y Y N N/A N/A N/A N/A N/A N/A 20 20 N/A 5 2/5
MCP4332 N Y N V 7 4 N Y Y N Y Y N Y N/A N/A N/A N/A N/A N/A 14 N/A N/A 5 2/5
MCP4341 N Y N EE 7 4 N Y Y N Y Y Y N N/A N/A N/A N/A N/A N/A 20 20 N/A 5 3/5
MCP4342 N Y N EE 7 4 N Y Y N Y Y N Y N/A N/A N/A N/A N/A N/A 14 N/A N/A 5 3/5
MCP4351 N Y N V 8 4 N Y Y N Y Y Y N N/A N/A N/A N/A N/A N/A 20 20 N/A 5 2/5
MCP4352 N Y N V 8 4 N Y Y N Y Y N Y N/A N/A N/A N/A N/A N/A 14 N/A N/A 5 2/5
MCP4361 N Y N EE 8 4 N Y Y N Y Y Y N N/A N/A N/A N/A N/A N/A 20 20 N/A 5 3/5
MCP4362 N Y N EE 8 4 N Y Y N Y Y N Y N/A N/A N/A N/A N/A N/A 14 N/A N/A 5 3/5
MCP4431 N N Y V 7 4 N Y Y N Y Y Y N N/A N/A N/A N/A N/A N/A 20 20 N/A 5 2/5
MCP4432 N N Y V 7 4 N Y Y N Y Y N Y N/A N/A N/A N/A N/A N/A 14 N/A N/A 5 2/5
MCP4441 N N Y EE 7 4 N Y Y N Y Y Y N N/A N/A N/A N/A N/A N/A 20 20 N/A 5 3/5
MCP4442 N N Y EE 7 4 N Y Y N Y Y N Y N/A N/A N/A N/A N/A N/A 14 N/A N/A 5 3/5
MCP4451 N N Y V 8 4 N Y Y N Y Y Y N N/A N/A N/A N/A N/A N/A 20 20 N/A 5 2/5
MCP4452 N N Y V 8 4 N Y Y N Y Y N Y N/A N/A N/A N/A N/A N/A 14 N/A N/A 5 2/5
MCP4461 N N Y EE 8 4 N Y Y N Y Y Y N N/A N/A N/A N/A N/A N/A 20 20 N/A 5 3/5
MCP4462 N N Y EE 8 4 N Y Y N Y Y N Y N/A N/A N/A N/A N/A N/A 14 N/A N/A 5 3/5
MCP4531 N N Y V 7 1 N Y Y N Y Y Y N N/A N/A N/A N/A 8 N/A N/A N/A N/A 5 2/5
MCP4532 N N Y V 7 1 N Y Y N Y Y N Y N/A N/A N/A N/A 8 N/A N/A N/A N/A 5 2/5
MCP4541 N N Y EE 7 1 N Y Y N Y Y Y N N/A N/A N/A N/A 8 N/A N/A N/A N/A 5 3/5
MCP4542 N N Y EE 7 1 N Y Y N Y Y N Y N/A N/A N/A N/A 8 N/A N/A N/A N/A 5 3/5
MCP4551 N N Y V 8 1 N Y Y N Y Y Y N N/A N/A N/A N/A 8 N/A N/A N/A N/A 5 2/5
MCP4552 N N Y V 8 1 N Y Y N Y Y N Y N/A N/A N/A N/A 8 N/A N/A N/A N/A 5 2/5
MCP4561 N N Y EE 8 1 N Y Y N Y Y Y N N/A N/A N/A N/A 8 N/A N/A N/A N/A 5 3/5
MCP4562 N N Y EE 8 1 N Y Y N Y Y N Y N/A N/A N/A N/A 8 N/A N/A N/A N/A 5 3/5
MCP45HV31 N N Y V 7 1 N Y Y N Y Y Y N N/A N/A N/A N/A 8 N/A N/A N/A N/A 5 ≤36
MCP45HV51 N N Y V 8 1 N Y Y N Y Y N Y N/A N/A N/A N/A 8 N/A N/A N/A N/A 5 ≤36
MCP4631 N N Y V 7 2 N Y Y N Y Y Y N N/A N/A 14 N/A N/A 14 14 16 N/A 5 2/5
MCP4632 N N Y V 7 2 N Y Y N Y Y N Y N/A N/A 14 N/A N/A 14 14 16 N/A 5 2/5
MCP4641 N N Y EE 7 2 N Y Y N Y Y Y N N/A N/A 14 N/A N/A 14 14 16 N/A 5 3/5
MCP4642 N N Y EE 7 2 N Y Y N Y Y N Y N/A N/A 14 N/A N/A 14 14 16 N/A 5 3/5
MCP4651 N N Y V 8 2 N Y Y N Y Y Y N N/A N/A 14 N/A N/A 14 14 16 N/A 5 2/5
MCP4652 N N Y V 8 2 N Y Y N Y Y N Y N/A N/A 14 N/A N/A 14 14 16 N/A 5 2/5
MCP4661 N N Y EE 8 2 N Y Y N Y Y Y N N/A N/A 14 N/A N/A 14 14 16 N/A 5 3/5
MCP4662 N N Y EE 8 2 N Y Y N Y Y N Y N/A N/A 14 N/A N/A 14 14 16 N/A 5 3/5
MCP42U83 N Y Y MTP 10 2 N Y Y Y Y Y Y Y N/A N/A N/A N/A N/A N/A 14 N/A 16 2 3/5
MCP41U83 N Y Y MTP 10 1 N Y Y Y Y Y Y Y N/A N/A N/A N/A N/A N/A 14 N/A 16 2 3/5
1. When >1 Resistor option is available, the corresponding ordering part numbers are: −202 (2.1 kΩ), −502 (5.0 kΩ), −103 (10.0 kΩ), -203 (20.0 kΩ), −503 (50.0 kΩ) and 
−104 (100.0 kΩ). 
2. This current is with the serial interface inactive, and not during an EEPROM write cycle (for non-volatile devices). 
3. The serial interface has been tested to 1.8V, the device’s analog characteristics (resistor) have been tested from 2.7V to 5.5V. Review the device’s characterization 
graphs for information on analog performance between 1.8V and 2.7V. 
4. One of the terminal pins (A or B) is internally connected to ground, due to the limitation of the number of pins on the package.
5. N/A indicates the device is not available in thie corresponding package style
Comprehensive Digipot Portfolio

## Page 13

Digital Potentiometers Design Guide
13
Step Resistance and Voltage Windowing
The Step Resistance (Rs)
Step resistance refers to the incremental resistance change between adjacent wiper positions. This critical parameter determines 
the resolution and precision of the device. Smaller step resistance allows for ﬁner adjustments and higher precision.
Step resistance is calculated by dividing the total resistance (Rab) by the number of steps minus one. For example, a 10kΩ digital 
potentiometer with 256 steps will have a step resistance of approximately 39.2Ω. Understanding step resistance is essential to 
choosing the right resolution.
Voltage Windowing
Voltage windowing is a technique where Terminal A and Terminal B of a Digipot can be set to any voltage 
within the device’s speciﬁcation limits, denoted as Va and Vb. The voltage across the resistor network, 
Vab, is the absolute difference |Va − Vb|. This voltage is influenced by the values of the resistors R1, R2, 
and Rab. As Vab becomes smaller relative to the overall voltage range, the effective resolution of the 
device increases.
This method allows a less precise digital potentiometer to achieve more precise circuit tuning over a 
narrower voltage range. This conﬁguration is appropriate when replacing a mechanical potentiometer; 
R1 and R2 can be any resistance, including zero. Voltage windowing is a valuable technique for enhancing 
the precision of digital potentiometers in various applications.
Step Resistance
RAB (kΩ) 6-b Ω 7-b Ω 8-b Ω 10-b Ω
2.1 33.33 N/A N/A N/A
5 79.365 39.37 19.608 4.888
10 158.73 78.74 39.216 9.775
20 N/A N/A N/A 19.550
50 793.651 393.701 196.078 48.876
100 N/A 787.402 392.157 97.752
How the Vab Voltage Effects the Effective Resolution
Vab mV per step Effective Resolution vs. 5V Vdd
(in V) 6-bit 7-bit 8-bit 10-bit 6-bit 7-bit 8-bit 10-bit
5 79.4 39.1 19.5 5.0 6 7 8 10
2.5 39.7 19.5 9.8 2.5 7 8 9 11
1.25 19.8 9.8 4.9 1.3 8 9 10 12
Common Digital Potentiometer Applications
1. Volume Control in Audio Systems
2. Sensor and Instrument Calibration
3. Programmable Power Supplies and Oscillators
4. Adjustable Filters
5. LED Dimming and Photographic Light Intensity Control
6. Biasing in RF Circuits
7. Digital Gain Control in Instrumentation Ampliﬁers
8. BMS (Battery Management Systems)
9. Temperature Compensation
10. Automated Test Equipment (ATE)
11. Feedback Control Systems
Voltage Windowing
R1
R2
W
A
B
R��
V�
V�

## Page 14

microchip.com
14
Application Circuits and Techniques
Inverting Amplifier with Offset and Gain Trimming 
Digital potentiometers may be used to trim offset and gain in ampliﬁer circuits. In the following example, a resistor ladder 
establishes a voltage window. Pot1 adjusts the desired offset for the inverting ampliﬁer. Pot2, operating in rheostat mode, 
combined with resistor R3 controls the ampliﬁer’s gain. The step resistance of Pot2 relative to resistor R3 determines the 
granularity of the gain trimming. Capacitor C1 is included for op amp compensation, preventing output oscillation.
In this conﬁguration, there is no interaction between the offset and gain trimming. That said, the input signal (Vin) is affected by 
the combined resistance of R2 and Pot2’s Rbw value.
Band Pass Filter with Offset and Gain Trimming
In this example, a resistor ladder again establishes a voltage window. Here Pot1 is used to adjust the desired offset for a band 
pass ﬁlter. Pot2, operating in rheostat mode, combined with resistors R3 and R4 control the ampliﬁer’s gain. The step resistance 
of Pot2 relative to resistors R3 and R4 determines the granularity of the gain trimming. Capacitor C1, in conjunction with Pot2, 
R3, and R4, is used to set the low pass ﬁlter frequency.
Capacitor C1 also serves to compensate the op amp and prevent output oscillation. If capacitor C1 is not present, the circuit 
functions as a high-pass ﬁlter, whereas if capacitor C2 is not present, the circuit functions as a low-pass ﬁlter.
R1
A
AB
V�
V��
W
V���
W
B
R2
Pot1
C1
R4
Pot 2R3
+
-
R1
A
AB
W
V���V��
C2
W
B
R2
Pot1
C1
R4
Pot 2R3
+
-

## Page 15

Digital Potentiometers Design Guide
15
Non-Inverting Amplifier with Offset and Gain Trimming 
In this example, a resistor ladder establishes a voltage window. Again, Pot1 adjusts the desired offset for the inverting ampliﬁer. 
Here Pot2, operating in rheostat mode, independently control the ampliﬁer’s gain. The step resistance of Pot2 relative to resistor 
R3 also determines the granularity of the gain trimming. Capacitor C1 is included for op amp compensation, preventing output 
oscillation
In this conﬁguration, there is an interaction between the offset and gain trimming. To minimize this interaction, Pot2 should be 
small compared to resistor R3, and Pot1 should be small relative to the sum of R1 and R2. The input signal (Vin) is not loaded.
Programmable Filter
In this example, a resistor ladder again establishes a voltage window. Here Pot1 is used to adjust the desired offset for a band 
pass ﬁlter. Pot2, operating in rheostat mode, combined with resistors R3 and R4 control the ampliﬁer’s gain. The step resistance 
of Pot2 relative to resistors R3 and R4 determines the granularity of the gain trimming. Capacitor C1, in conjunction with Pot2, 
R3, and R4, is used to set the low pass ﬁlter frequency.
Capacitor C1 also serves to compensate the op amp and prevent output oscillation. If capacitor C1 is not present, the circuit 
functions as a high-pass ﬁlter, whereas if capacitor C2 is not present, the circuit functions as a low-pass ﬁlter.
R1
A
V��
V�
V���
W
B
R2
Pot1
C1
B
W
+
-
A
V�� V���
Pot1Pot2
C1C2
B AB
W W
+
-

## Page 16

microchip.com
16
Application Circuits and Techniques
Logarithmic Steps
For audio applications, logarithmic steps are desirable because that is how the human ear perceives sound. A linear 
potentiometer can approximate a logarithmic potentiometer but with fewer steps. An 8-bit potentiometer can achieve fourteen 
3 dB log steps, plus a 100% (0 dB) and a mute setting.
The ﬁgure below shows a block diagram of an MCP44X1 resistor network used to attenuate an input signal, with attenuation 
referenced to ground. Terminal B can be connected to a common mode voltage, but the voltages on terminals A, B, and the 
wiper must not exceed the MCP44X1 device’s Vdd/Vss voltage limits.
Signal Attenuation Block Diagram: Ground Referenced
More detail on this can be found in Section 8.5 of the MCP444X/446X Data Sheet (DS22265).
dB VOUT/VIN Ratio
–3 0.70795
–2 0.79433
–1 0.89125
MCP44X1
POA
POW
POB
R2

## Page 17

Digital Potentiometers Design Guide
17
Wheatstone Bridge Trimming
A Wheatstone Bridge has four resistive elements. In this example, two are ﬁxed values (R1 and R2), one is a resistive sensor 
(Rsensor), and the fourth is a digital potentiometer conﬁgured as a rheostat. The potentiometer is used to calibrate the circuit 
compensating for variations in the resistive sensor. This sensor could be used for temperature or weight measurement.
Under default conditions, the sensor will have a typical value, but this value likely varies from device to device. To compensate 
for the resistive changes in the R1 plus Rsensor leg of the bridge, the digital potentiometer (Rheo2) is adjusted in the other leg of 
the bridge. This adjustment ensures that the voltages at Vbrg1 and Vbrg2 are at their desired levels (often Vbrg1 = Vbrg2).
As the conditions affecting the sensor change, the resistance of the sensor will also change, causing the voltage at Vbrg2 to vary. 
The difference in voltage between Vbrg1 and Vbrg2 can then be used to determine the state of the system (e.g., temperature, 
weight, etc.).
Rheo1 limits or trims the current through the Wheatstone Bridge.
Implementing a More Precise Rheostat
The RAB value of a typical digital potentiometer can vary by ±20%, meaning a 10 kΩ device could range from 8 kΩ to 12 kΩ. If this 
variation is undesirable resolution may be sacriﬁced in favor of calibration.
By designing the circuit to operate the rheostat from 0Ω to 8 kΩ, all digital potentiometer devices will meet this requirement. Via 
calibration the max wiper value can be set to achieve the closest resistance to the target 8 kΩ. For a max RAB of 12 kΩ, a wiper 
value of 171 results in a resistance of 8016Ω. The resultant worst case effective resolution calculates to 7.4 bits, or 0.58%.
Note - In potentiometer mode, RAB variation has less impact since the device functions as a voltage divider.
Microchip Technology offers several boards that support the demonstration and evaluation of the digital potentiometer devices. 
These boards fall into two categories:
• Populated boards to demonstrate/evaluate the speciﬁc device(s)
• Blank printed circuit boards (PCBs)
Blank PCBs allow customers to populate the device and supporting circuit to best evaluate the performance and characteristics 
of the desired device conﬁguration.
Links to the latest eval kits will be found on the product pages at Microchip.com.
R������
V���1V���2
Rheo2
WA
B
R1 R2
Rheo1

## Page 18

microchip.com
18
Application Notes
The following literature is available on the Microchip web site. Any 
application notes newer than the latest revision of this brochure will be 
linked to individual Digipot product pages.
AN219: Comparing Digital Potentiometers to Mechanical 
Potentiometers
This application note compares two types of potentiometers, the 
mechanical potentiometer (also called a trimmer potentiometer) and the 
digital potentiometer.
Resistor potentiometers can be found in electronic circuits across a 
wide spectrum of applications. Most typically, they function in a voltage 
divider conﬁguration in order to execute various types of tasks, such as 
offset or gain adjust.
AN691: Optimizing Digital Potentiometer Circuits to Reduce 
Absolute Temperature Variations
Circuit ideas are presented that use the necessary design techniques to 
mitigate errors, consequently optimizing the performance of the digital 
potentiometer.
AN692: Using Digital Potentiometers to Optimize a Precision Single-
Supply Photo Detect Circuit
This application note shows how the adjustability of the digital 
potentiometer can be used to an advantage in photosensing circuits.
AN737: Using Digital Potentiometers to Design Low-Pass Adjustable 
Filters
A programmable, second-order, low-pass ﬁlter is presented in four 
different scenarios. The ﬁrst three scenarios will illustrate how a dual 
digital potentiometer and a single ampliﬁer can be conﬁgured for 
low-pass second-order Butterworth, Bessel and Chebyshev responses 
with a programmable corner frequency range of 1:100. An example 
of the digital potentiometer setting for these designs is summarized. 
The fourth scenario will show the same circuit design, where all three 
approximation methods (Butterworth, Bessel and Chebyshev) can 
coexist with a programmable corner frequency range of 1:10.
AN746: Interfacing Microchip’s MCP41XXX/ MCP4XXX Digital 
Potentiometer to a PIC® Microcontroller Communications between 
the MCP41XXX and MCP42XXX
family of digital potentiometers and a PIC16F876 microcontroller is 
discussed. These devices communicate using a standard 3-wire SPI 
compatible interface. The code supplied with this application note will 
include both absolute and relocatable assembly code, written for both 
hardware SPI and ﬁrmware SPI implementations.

## Page 19

Digital Potentiometers Design Guide
19
Application Notes
AN747: Communicating with Daisy Chained MCP42XXX Digital 
Potentiometers
The MCP41XXX and MCP42XXX family of digital potentiometers allow 
for daisy chaining of multiple devices on a single SPI bus. It is possible 
to communicate to multiple devices using one 3-wire data bus (CS, 
CLK and DATA), by connecting the SO pin on one device to the SI pin of 
the next device in the chain. This application note details one example 
of source code that is used to communicate with eight daisy chained 
devices.
AN757: Interfacing Microchip’s MCP41XXX/ MCP4XXX Digital 
Potentiometer to the Motorola 68HC12 Microcontroller
Communication between the MCP41XXX and MCP42XXX family of digital 
potentiometers and the Motorola 68HC12 family of microcontrollers 
is discussed. These devices communicate using a standard 3-wire SPI 
compatible interface. Speciﬁcally, the MC68HC912B32 evaluation board 
was used.
AN1080: Understanding Digital Potentiometer Resistance Variations
This application note discusses how process, voltage and temperature 
effect the resistor network’s characteristics, speciﬁcations and 
techniques to improve system performance.
AN1316: Using Digital Potentiometers for Programmable Amplifier 
Gain
This application note will discuss implementations of programmable 
gain circuits using an op amp and a digital potentiometer. This 
discussion will include implementation details for the digital 
potentiometer’s resistor network. It is important to understand these 
details to understand the effects on the application.

## Page 20

Microchip Technology Inc. | 2355 W. Chandler Blvd. | Chandler AZ, 85224-6199 | microchip.com
The Microchip name and logo and the Microchip logo are registered trademarks of Microchip Technology Incorporated in the 
U.S.A. and other countries. All other trademarks mentioned herein are property of their respective companies.
© 2025, Microchip Technology Incorporated and its subsidiaries. All Rights Reserved. 2/25 DS20002017E
Microchip’s Stand-Alone Analog and Interface Portfolio
Linear
Ampliﬁers
Comparators
Timing
Timers
Ultrasound
Ultrasound Products
Mixed Signal
A/D Converters
Voltage References
Power Management
DC/DC Converters
PWM Controllers
Battery Chargers
Power Modules
Power MOSFET Drivers
Power MOSFET
Motor Drivers
System Supervisors
Voltage Detectors
Power Switches
Hot Swap
Power Controllers
DDR and 
SCSI Terminators
Display/LED Drivers
Interface
CAN, CAN FD, LIN
HV Interface
USB and I/O Expanders
Ethernet
Wireless
Real-Time Clock/Calendar
Current/DC Power
Measurement ICs
Power Monitoring
and Metering
DACs and Digital
Potentiometers
Safety and Security
Smoke Detector ICs
Piezoelectric Horn Drivers
Thermal Management
Temperature Sensors
Fan Control and 
Management
