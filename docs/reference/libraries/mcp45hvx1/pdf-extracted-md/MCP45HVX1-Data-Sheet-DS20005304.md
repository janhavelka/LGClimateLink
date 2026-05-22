# MCP45HVX1 Data Sheet

- Source PDF: `../MCP45HVX1-Data-Sheet-DS20005304.pdf`
- Extraction tool: pdfplumber
- Page count: 102
- SHA256: `18feae380a4045ff95530f6609ae960dd22215158a112a1b0c04f3513b0528e5`

## Page 1

MCP45HVX1
Package Types (Top View)
Features
MCP45HVX1 Single Potentiometer
• High-Voltage Analog Support:
- +36V Terminal Voltage Range (DGND = V-)
- ±18V Terminal Voltage Range
(DGND = V- + 18V)
• Wide Operating Voltage:
- Analog: 10V to 36V (specified performance)
- Digital: 2.7V to 5.5V
1.8V to 5.5V (V >= V- + 2.7V)
L
• Single-Resistor Network
• Resistor Network Resolution
- 7-bit: 127 Resistors (128 Taps)
- 8-bit: 255 Resistors (256 Taps)
18 17 • R AB Resistance Options: 15
1 - 5 k -10 k 14
2
- 50 k -100 k
3
• High Terminal/Wiper Current (I ) Support:
W
4
- 25 mA (for 5 k)
- 12.5 mA (for 10 k)
- 6.5 mA (for 50 k and 100 k)
• Zero-Scale to Full-Scale Wiper Operation
• Low Wiper Resistance: 75  (typical)
• Low Tempco:
- Absolute (Rheostat): 50 ppm typical
(0°C to +70°C)
- Ratiometric (Potentiometer): 15 ppm typical Description
• I2C Serial Interface: The MCP45HVX1 family of devices have dual power
- 100 kHz, 400 kHz, 1.7 MHz, rails (analog and digital). The analog power rail allows
and 3.4 MHz support high voltage on the resistor network terminal pins. The
• Resistor Network Terminal Disconnect Via: analog voltage range is determined by the V+ and V–
voltages. The maximum analog voltage is +36V, while
- Shutdown Pin (SHDN)
the operating analog output minimum specifications
- Terminal Control (TCON) Register
are specified from either 10V or 20V. As the analog
• Write Latch (WLAT) Pin to Control Update of supply voltage becomes smaller, the analog switch
Volatile Wiper Register (such as Zero Crossing) resistances increase, which affect certain performance
• Power-On Reset/Brown-Out Reset for Both: specifications. The system can be implemented as dual
- Digital supply (V /DGND); 1.5V typical rail (±18V) relative to the digital logic ground (DGND).
L
- Analog supply (V+/V-); 3.5V typical The device also has a Write Latch (WLAT) function,
• Serial Interface Inactive Current (3 μA typical) which will inhibit the volatile Wiper register from being
updated (latched) with the received data, until the
• 500 kHz Typical Bandwidth (-4 dB) Operation
WLAT pin is Low. This allows the application to specify
(5.0 k Device)
a condition where the volatile Wiper register is updated
• Extended Temperature Range (-40°C to +125°C)
(such as zero crossing).
• Package Types: TSSOP-14 and VQFN-20 (5x5)
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B
)2(
CN
)2(
CN
P0W
13 P0B
12 V-
6 7 8 9
NDHS )2(
CN
)2(
CN
20 19
V L
SCL
A1
SDA
)2(
CN
TALW
)2(
CN
P0A
A0 5
10
)2(
CN
16
11 DGND
+V
7/8-Bit Single, +36V (±18V) Digital POT
2
with I C Serial Interface and Volatile Memory
TSSOP (ST)
V 1 14 V+
L
SCL 2 13 PA0
A1 3 12 PW0
SDA 4 11 PB0
A0 5 10 V—
WLAT 6 9 DGND
NC 7 8 SHDN
VQFN 5x5 (MQ)
2 1 EP(1)
Note 1: Exposed Pad (EP)
2: NC = Not Internally Connected

## Page 2

MCP45HVX1
Device Block Diagram
Device Features
Device
DS20005304B-page 2  2014-2023 Microchip Technology Inc. and its subsidiaries
sTOP
fo
#
Wiper
Configuration
lortnoC ecafretnI repiW
ROP
gnitteS Number Specified Operating Resistance (Typical) of: Range
R Options Wiper - AB
(k) R ()
W
R
S spaT
V+ V–
Power-Up/
V L Brown-Out Power-Up/
DGND Control Brown-Out
(Digital) Control
(Analog)
SCL I2C Serial
Interface
SDA
Module and
A0 Control
A1 Logic Resistor P0A
Network 0
WLAT (Pot 0)
P0W
SHDN Wiper 0
and TCON
Register
Memory (2x8) P0B
Wiper0 (V)
TCON
(2) (3) V V+
L
MCP45HV31 1 Potentiometer (1) I2C 3Fh 5.0, 10.0, 75 127 128 1.8V to 10V
(4)
to 36V
50.0, 100.0 5.5V
(4)
MCP45HV51 1 Potentiometer (1) I2C 7Fh 5.0, 10.0, 75 255 256 1.8V to 10V to 36V
50.0, 100.0 5.5V
(5) 5.0, 10.0, 1.8V to 10V
(4)
to 36V
MCP41HV31 1 Potentiometer SPI 3Fh 75 127 128
50.0, 100.0 5.5V
(4)
(5) (5) 5.0, 10.0, 1.8V to 10V to 36V
MCP41HV51 1 Potentiometer SPI 7Fh 75 255 256
50.0, 100.0 5.5V
Note 1: Floating either terminal (A or B) allows the device to be used as a Rheostat (variable resistor).
2: This is relative to the DGND signal. There is a separate requirement for the V+/V- voltages.
V >= V- + 2.7V.
L
3: Relative to V-, the V and DGND signals must be between (inclusive) V- and V+.
L
4: Analog operation will continue while the V+ voltage is above the device’s analog Power-On Reset (POR)/
Brown-out Reset (BOR) voltage. Operational characteristics may exceed specified limits while the V+
voltage is below the specified minimum voltage.
5: For additional information on these devices, refer to DS20005207.

## Page 3

MCP45HVX1
1.0 ELECTRICAL CHARACTERISTICS
Absolute Maximum Ratings †
Voltage on V- with respect to DGND ......................................................................................... DGND + 0.6V to -40.0V
Voltage on V+ with respect to DGND ........................................................................................... DGND - 0.3V to 40.0V
Voltage on V+ with respect to V- .................................................................................................. DGND - 0.3V to 40.0V
Voltage on V with respect to V+ ............................................................................................................ -0.6V to -40.0V
L
Voltage on V with respect to V- ............................................................................................................ -0.6V to +40.0V
L
Voltage on V with respect to DGND ....................................................................................................... -0.6V to +7.0V
L
Voltage on SCL, SDA, A0, A1, WLAT, and SHDN with respect to DGND .......................................... -0.6V to V + 0.6V
L
Voltage on all other pins (PxA, PxW, and PxB) with respect to V- ......................................................-0.3V to V+ + 0.3V
Input clamp current, I (V < 0, V > V , V > V on HV pins) ............................................................................ ±20 mA
IK I I L I PP
Output clamp current, I (V < 0 or V > V ) ................................................................................................... ±20 mA
OK O O L
Maximum current out of DGND pin...................................................................................................................... 100 mA
Maximum current into V pin................................................................................................................................ 100 mA
L
Maximum current out of V- pin ............................................................................................................................. 100 mA
Maximum current into V+ pin ................................................................................................................................100 mA
Maximum current into PXA, PXW, and PXB pins (Continuous)
R = 5 k ............................................................................................................................. ±25 mA
AB
R = 10 k ........................................................................................................................ ±12.5 mA
AB
R = 50 k .......................................................................................................................... ±6.5 mA
AB
R = 100 k ........................................................................................................................ ±6.5 mA
AB
Maximum current into PXA, PXW, and PXB pins (Pulsed)
F > 10 kHz ......................................................................................................... (Max I ) / (Duty Cycle)
PULSE Continuous
F <= 10 kHz ...................................................................................................... (Max I ) / (Duty Cycle)
PULSE Continuous
Maximum output current sunk by any Output pin .................................................................................................. 25 mA
Maximum output current sourced by any Output pin ............................................................................................ 25 mA
Package Power Dissipation (T = + 50°C, T = +150°C)
A J
TSSOP-14 ............................................................................................................................................. 1000 mW
VQFN-20 (5 x 5) .................................................................................................................................... 2800 mW
Soldering temperature of leads (10 seconds) ..................................................................................................... +300°C
ESD protection on all pins
Human Body Model (HBM) ...................................................................................................................... >= ±5 kV
Machine Model (MM)  >=±400V
Maximum Junction Temperature (T ) ..................................................................................................................... 150°C
J
Storage temperature ............................................................................................................................. -65°C to +150°C
Ambient temperature with power applied .............................................................................................. -40°C to +125°C
† Notice: Stresses above those listed under “Maximum Ratings” may cause permanent damage to the device. This
is a stress rating only and functional operation of the device at those or any other conditions above those indicated in
the operational listings of this specification is not implied. Exposure to maximum rating conditions for extended periods
may affect device reliability.
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 3

## Page 4

MCP45HVX1
AC/DC CHARACTERISTICS
Standard Operating Conditions (unless otherwise specified)
Operating Temperature -40°C <= T <= +125°C (extended)
A
All parameters apply across the specified operating ranges unless noted.
DC Characteristics V+ = 10V to 36V (referenced to V-);
V+ = +5V to +18V and V- = -5.0V to -18V (referenced to DGND -> ±5V to ±18V),
V = +2.7V to 5.5V, 5 k, 10 k, 50 k, 100 k devices.
L
Typical specifications represent values for V = 5.5V, T = +25°C.
L A
Parameters Sym. Min. Typ. Max. Units Conditions
Digital Positive V 2.7 — 5.5 V With respect to DGND (Note 4)
L
Supply Voltage (V L ) 1.8 — 5.5 V V L >= V- + 2.7V
(Note 1, Note 4)
— — 0 V With respect to V+
Analog Positive V+ V (16) — 36.0 V With respect to V- (Note 4)
L
Supply Voltage (V+)
Digital Ground V V- — V+ - V V With respect to V- (Note 4, Note 5)
DGND L
Voltage (DGND)
Analog Negative V- -36.0 + V — 0 V With respect to DGND and with V = 1.8V
L L
Supply Voltage (V-)
Resistor Network V — — 36.0 V Delta voltage between V+ and V- (Note 4)
RN
Supply Voltage
V Start Voltage to V — — 1.8 V With respect to DGND, V+ > 6.0V
L DPOR
ensure Wiper Reset RAM retention voltage (V ) < V
RAM DBOR
V+ Voltage to ensure V — — 6.0 V With respect to V-, V = 0V
APOR L
Wiper Reset RAM retention voltage (V ) < V
RAM BOR
Digital to Analog V — — 2.3 V V to V- voltage.
LS L
Level Shifter DGND = V-
Operational Voltage
Power Rail Voltages V — — 5.5 V Digital Powers (V /DGND) up 1st:
LPOR L
during Power-Up V+ and V- floating
(Note 1) or
as V+/V- powers-up
(V+ must be >= to DGND) (Note 18)
V+ — — 36 V Analog Powers (V+/V-) up 1st:
POR
V and DGND floating
L
or
as V /DGND powers-up
L
(DGND must be between V- and V+)
(Note 18)
V Rise Rate to V (Note 6) V/ms With respect to DGND
L LRR
ensure Power-On
Reset
Note 1: This specification by design.
Note 4: V+ voltage is dependent on V- voltage. The maximum delta voltage between V+ and V- is 36V. The digital
logic DGND potential can be anywhere between V+ and V-, the VL potential must be >= DGND and <= V+.
Note 5: Minimum value determined by maximum V- to V+ potential equals 36V and minimum VL = 1.8V for opera-
tion. So 36V - 1.8V = 34.2V.
Note 6: POR/BOR is not rate dependent.
Note 16: For specified analog performance, V+ must be 20V or greater (unless otherwise noted).
Note 18: During the power-up sequence, to ensure expected analog POR operation, the two power systems (analog
and digital) should have a common reference to ensure that the driven DGND voltage is not at a higher
potential than the driven V+ voltage.
DS20005304B-page 4  2014-2023 Microchip Technology Inc. and its subsidiaries

## Page 5

MCP45HVX1
AC/DC CHARACTERISTICS (CONTINUED)
Standard Operating Conditions (unless otherwise specified)
Operating Temperature -40°C <= T <= +125°C (extended)
A
All parameters apply across the specified operating ranges unless noted.
DC Characteristics V+ = 10V to 36V (referenced to V-);
V+ = +5V to +18V and V- = -5.0V to -18V (referenced to DGND -> ±5V to ±18V),
V = +2.7V to 5.5V, 5 k, 10 k, 50 k, 100 k devices.
L
Typical specifications represent values for V = 5.5V, T = +25°C.
L A
Parameters Sym. Min. Typ. Max. Units Conditions
Delay after T — 10 20 μs
BORD
device exits the
Reset state
(V > V )
L BOR
Supply Current I — 45 650 μA Serial Interface Active,
DDD
(Note 7) Write all 0’s to Volatile Wiper 0 (address 0h)
V = 5.5V, F = 3.4 MHz,
L SCL
V- = DGND
— 4 7 μA Serial Interface Inactive,
V = 5.5V, SCL = V , Wiper = 0,
L IH
V- = DGND
I — — 5 μA Current V+ to V-, PxA = PxB = PxW,
DDA
DGND = V- +(V+/2)
Resistance R 4.0 5 6.0 k -502 devices, V+/V- = 10V to 36V
AB
(± 20%)(Note 8) 8.0 10 12.0 k -103 devices, V+/V- = 10V to 36V
40.0 50 60.0 k -503 devices, V+/V- = 10V to 36V
80.0 100 120.0 k -104 devices, V+/V- = 10V to 36V
R Current I — — 9.00 mA -502 devices 36V / R ,
AB AB AB(MIN)
— — 4.50 mA -103 devices V- = -18V, V+ = +18V,
(Note 9)
— — 0.90 mA -503 devices
— — 0.45 mA -104 devices
Resolution N 256 Taps 8-bit No Missing Codes
128 Taps 7-bit No Missing Codes
Step Resistance R — R /(255) —  8-bit Note 1
S AB
(see Appendix
— R /(127) —  7-bit Note 1
AB
B.4)
Note 1: This specification by design.
Note 7: Supply current (IDDD and IDDA) is independent of current through the resistor network.
Note 8: Resistance (RAB) is defined as the resistance between Terminal A to Terminal B.
Note 9: Ensured by the RAB specification and Ohm’s Law.
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 5

## Page 6

MCP45HVX1
AC/DC CHARACTERISTICS (CONTINUED)
Standard Operating Conditions (unless otherwise specified)
Operating Temperature -40°C <= T <= +125°C (extended)
A
All parameters apply across the specified operating ranges unless noted.
DC Characteristics V+ = 10V to 36V (referenced to V-);
V+ = +5V to +18V and V- = -5.0V to -18V (referenced to DGND -> ±5V to ±18V),
V = +2.7V to 5.5V, 5 k, 10 k, 50 k, 100 k devices.
L
Typical specifications represent values for V = 5.5V, T = +25°C.
L A
Parameters Sym. Min. Typ. Max. Units Conditions
Wiper Resistance R W — 75 170  I W = 1 mA V+ = +18V, V- = -18V,
(see Appendix B.5) code = 00h, PxA = floating,
PxB = V-.
— 145 200  I = 1 mA V+ = +5.0V, V- = -5.0V,
W
code = 00h, PxA = floating,
PxB = V-. (Note 2)
Nominal Resistance R /T — 50 — ppm/°C T = -40°C to +85°C
AB A
Tempco — 100 — ppm/°C T = -40°C to +125°C
A
(see Appendix B.23)
Ratiometeric Tempco V /T — 15 — ppm/°C Code = Mid scale (7Fh or 3Fh)
BW
(see Appendix B.22)
Resistor Terminal Input V V V V- — V+ V Note 1, Note 11
A, W, B
Voltage Range
(Terminals A, B and W)
Current through I T , I W — — 25 mA -502 devices I BW(W ≠ ZS) and I AW(W ≠ FS)
Terminals — — 12.5 mA -103 devices I BW(W ≠ ZS) and I AW(W ≠ FS)
(A, B, and Wiper)
(Note 1) — — 6.5 mA -503 devices I BW(W ≠ ZS) and I AW(W ≠ FS)
— — 6.5 mA -104 devices I BW(W ≠ ZS) and I AW(W ≠ FS)
— — 36 mA I , or I
BW(W = ZS) AW(W = FS)
Leakage current into A, I — 5 — nA A = W = B = V-
TL
W or B
Note 1: This specification by design.
Note 2: This parameter is not tested, but specified by characterization.
Note 11: Resistor terminals A, W and B’s polarity with respect to each other is not restricted.
DS20005304B-page 6  2014-2023 Microchip Technology Inc. and its subsidiaries

## Page 7

MCP45HVX1
AC/DC CHARACTERISTICS (CONTINUED)
Standard Operating Conditions (unless otherwise specified)
Operating Temperature -40°C <= T <= +125°C (extended)
A
All parameters apply across the specified operating ranges unless noted.
DC Characteristics V+ = 10V to 36V (referenced to V-);
V+ = +5V to +18V and V- = -5.0V to -18V (referenced to DGND -> ±5V to ±18V),
V = +2.7V to 5.5V, 5 k, 10 k, 50 k, 100 k devices.
L
Typical specifications represent values for V = 5.5V, T = +25°C.
L A
Parameters Sym. Min. Typ. Max. Units Conditions
Full Scale Error V -10.5 — — LSb 5 k V = 20V to 36V
WFSE AB
(Potentiometer) -8.5 — — LSb V = 20V to 36V
(8-bit code = FFh, 8-bit -4 A 0 B °C <= T <= +85°C (Note 2)
A
7-bit code = 7Fh)
-14.0 — — LSb V = 10V to 36V
(Note 10, Note 17) AB
(V A = V+, V B = V- ) -5.5 — — LSb V AB = 20V to 36V
(see Appendix -4.5 — — LSb V = 20V to 36V
7-bit AB
B.10) -40°C <= T <= +85°C (Note 2)
A
-7.5 — — LSb V = 10V to 36V
AB
-4.5 — — LSb 10 k V = 20V to 36V
AB
8-bit
-6.0 — — LSb V = 10V to 36V
AB
-2.65 — — LSb V = 20V to 36V
AB
-2.25 — — LSb V = 20V to 36V
7-bit AB
-40°C <= T <= +85°C (Note 2)
A
-3.5 — — LSb V = 10V to 36V
AB
-1.0 — — LSb 50 k V = 20V to 36V
AB
8-bit
-1.4 — — LSb V = 10V to 36V
AB
-1.0 — — LSb V = 20V to 36V
AB
7-bit
-1.2 — — LSb V = 10V to 36V
AB
-0.7 — — LSb 100 k V = 20V to 36V
AB
8-bit
-0.95 — — LSb V = 10V to 36V
AB
-0.85 — — LSb V = 20V to 36V
AB
7-bit
-0.975 — — LSb V = 10V to 36V
AB
Note 2: This parameter is not tested, but specified by characterization.
Note 10: Measured at VW with VA = V+ and VB = V-.
Note 17: Analog switch leakage affects this specification. Higher temperatures increase the switch leakage.
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 7

## Page 8

MCP45HVX1
AC/DC CHARACTERISTICS (CONTINUED)
Standard Operating Conditions (unless otherwise specified)
Operating Temperature -40°C <= T <= +125°C (extended)
A
All parameters apply across the specified operating ranges unless noted.
DC Characteristics V+ = 10V to 36V (referenced to V-);
V+ = +5V to +18V and V- = -5.0V to -18V (referenced to DGND -> ±5V to ±18V),
V = +2.7V to 5.5V, 5 k, 10 k, 50 k, 100 k devices.
L
Typical specifications represent values for V = 5.5V, T = +25°C.
L A
Parameters Sym. Min. Typ. Max. Units Conditions
Zero Scale Error V — — +9.5 LSb 5 k V = 20V to 36V
WZSE AB
(Potentiometer) — — +8.5 LSb V = 20V to 36V
(8-bit code = 00h, 8-bit -4 A 0 B °C <= T <= +85°C (Note 2)
A
7-bit code = 00h)
— — +14.5 LSb V = 10V to 36V
(Note 10, Note 17) AB
(V A = V+, V B = V- ) — — +4.5 LSb 7-bit V AB = 20V to 36V
(see Appendix — — +7.0 LSb V = 10V to 36V
AB
B.11)
— — +4.25 LSb 10 k V = 20V to 36V
AB
8-bit
— — +6.5 LSb V = 10V to 36V
AB
— — +2.125 LSb V = 20V to 36V
AB
7-bit
— — +3.25 LSb V = 10V to 36V
AB
— — +0.9 LSb 50 k V = 20V to 36V
AB
8-bit
— — +1.3 LSb V = 10V to 36V
AB
— — +0.5 LSb V = 20V to 36V
AB
7-bit
— — +0.7 LSb V = 10V to 36V
AB
— — +0.6 LSb 100 k V = 20V to 36V
AB
8-bit
— — +0.95 LSb V = 10V to 36V
AB
— — +0.3 LSb V = 20V to 36V
AB
7-bit
— — +0.475 LSb V = 10V to 36V
AB
Note 2: This parameter is not tested, but specified by characterization.
Note 10: Measured at VW with VA = V+ and VB = V-.
Note 17: Analog switch leakage affects this specification. Higher temperatures increase the switch leakage.
DS20005304B-page 8  2014-2023 Microchip Technology Inc. and its subsidiaries

## Page 9

MCP45HVX1
AC/DC CHARACTERISTICS (CONTINUED)
Standard Operating Conditions (unless otherwise specified)
Operating Temperature -40°C <= T <= +125°C (extended)
A
All parameters apply across the specified operating ranges unless noted.
DC Characteristics V+ = 10V to 36V (referenced to V-);
V+ = +5V to +18V and V- = -5.0V to -18V (referenced to DGND -> ±5V to ±18V),
V = +2.7V to 5.5V, 5 k, 10 k, 50 k, 100 k devices.
L
Typical specifications represent values for V = 5.5V, T = +25°C.
L A
Parameters Sym. Min. Typ. Max. Units Conditions
Potentiometer P-INL -1 ±0.5 +1 LSb 5 k 8-bit V = 10V to 36V
AB
Integral -0.5 ±0.25 +0.5 LSb 7-bit V = 10V to 36V
AB
Nonlinearity
-1 ±0.5 +1 LSb 10 k 8-bit V = 10V to 36V
(Note 10, AB
Note 17) -0.5 ±0.25 +0.5 LSb 7-bit V AB = 10V to 36V
(see Appendix -1.1 ±0.5 +1.1 LSb 50 k 8-bit V = 10V to 36V
AB
B.12)
-1 ±0.5 +1 LSb V = 20V to 36V, (Note 2)
AB
-1 ±0.5 +1 LSb V = 10V to 36V,
AB
-40°C <= T <= +85°C (Note 2)
A
-0.6 ±0.25 +0.6 LSb 7-bit V = 10V to 36V
AB
-1.85 ±0.5 +1.85 LSb 100 k 8-bit V = 10V to 36V
AB
-1.2 ±0.5 +1.2 LSb V = 20V to 36V, (Note 2)
AB
-1 ±0.5 +1 LSb V = 10V to 36V,
AB
-40°C <= T <= +85°C (Note 2)
A
-1 ±0.5 +1 LSb 7-bit V = 10V to 36V
AB
Potentiometer P-DNL -0.7 ±0.25 +0.7 LSb 5 k 8-bit V = 10V to 36V
AB
Differential -0.5 ±0.25 +0.5 LSb V = 20V to 36V (Note 2)
AB
Nonlinearity
-0.25 ±0.125 +0.25 LSb 7-bit V = 10V to 36V
(Note 10, AB
Note 17) -0.375 ±0.125 +0.375 LSb 10 k 8-bit V AB = 10V to 36V
(see Appendix -0.25 ±0.1 +0.25 LSb 7-bit V = 10V to 36V
AB
B.13)
-0.25 ±0.125 +0.25 LSb 50 k 8-bit V = 10V to 36V
AB
-0.125 ±0.1 +0.125 LSb 7-bit V = 10V to 36V
AB
-0.25 ±0.125 +0.25 LSb 100 k 8-bit V = 10V to 36V
AB
-0.125 ±0.1 +0.125 LSb 7-bit V = 10V to 36V
AB
Note 2: This parameter is not tested, but specified by characterization.
Note 10: Measured at VW with VA = V+ and VB = V-.
Note 17: Analog switch leakage affects this specification. Higher temperatures increase the switch leakage.
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 9

## Page 10

MCP45HVX1
AC/DC CHARACTERISTICS (CONTINUED)
Standard Operating Conditions (unless otherwise specified)
Operating Temperature -40°C <= T <= +125°C (extended)
A
All parameters apply across the specified operating ranges unless noted.
DC Characteristics V+ = 10V to 36V (referenced to V-);
V+ = +5V to +18V and V- = -5.0V to -18V (referenced to DGND -> ±5V to ±18V),
V = +2.7V to 5.5V, 5 k, 10 k, 50 k, 100 k devices.
L
Typical specifications represent values for V = 5.5V, T = +25°C.
L A
Parameters Sym. Min. Typ. Max. Units Conditions
Bandwidth -3 dB BW — 480 — kHz 5 k 8-bit Code = 7Fh
(load = 30 pF) — 480 — kHz 7-bit Code = 3Fh
— 240 — kHz 10 k 8-bit Code = 7Fh
— 240 — kHz 7-bit Code = 3Fh
— 48 — kHz 50 k 8-bit Code = 7Fh
— 48 — kHz 7-bit Code = 3Fh
— 24 — kHz 100 k 8-bit Code = 7Fh
— 24 — kHz 7-bit Code = 3Fh
V Settling Time t — 1 — μs 5 k Code = 00h -> FFh (7Fh);
W S
(V = 10V, V = 0V, FFh (7Fh) -> 00h
A B
±1LSb error band, — 1 — μs 10 k Code = 00h -> FFh (7Fh);
C L = 50 pF) FFh (7Fh) -> 00h
(see Appendix B.17)
— 2.5 — μs 50 k Code = 00h -> FFh (7Fh);
FFh (7Fh) -> 00h
— 5 — μs 100 k Code = 00h -> FFh (7Fh);
FFh (7Fh) -> 00h
DS20005304B-page 10  2014-2023 Microchip Technology Inc. and its subsidiaries

## Page 11

MCP45HVX1
AC/DC CHARACTERISTICS (CONTINUED)
Standard Operating Conditions (unless otherwise specified)
Operating Temperature -40°C <= T <= +125°C (extended)
A
All parameters apply across the specified operating ranges unless noted.
DC Characteristics V+ = 10V to 36V (referenced to V-);
V+ = +5V to +18V and V- = -5.0V to -18V (referenced to DGND -> ±5V to ±18V),
V = +2.7V to 5.5V, 5 k, 10 k, 50 k, 100 k devices.
L
Typical specifications represent values for V = 5.5V, T = +25°C.
L A
Parameters Sym. Min. Typ. Max. Units Conditions
Rheostat Integral R-INL -2.0. — +2.0 LSb 5 k 8-bit I = 6.0 mA, (V+ - V-) = 36V (Note 2)
W
Nonlinearity -2.5 — +2.5 LSb I = 3.3 mA, (V+ - V-) = 20V (Note 2)
W
(Note 12, Note 13,
-4.5 — +4.5 LSb I = 1.7 mA, (V+ - V-) = 10V
Note 14, Note 17) W
(see Appendix -1.0 — +1.0 LSb 7-bit I W = 6.0 mA, (V+ - V-) = 36V (Note 2)
B.5) -1.5 — +1.5 LSb I = 3.3 mA, (V+ - V-) = 20V (Note 2)
W
-2.0 — +2.0 LSb I = 1.7 mA, (V+ - V-) = 10V
W
-1.2 — +1.2 LSb 10 k 8-bit I = 3.0 mA, (V+ - V-) = 36V (Note 2)
W
-1.75 — +1.75 LSb I = 1.7 mA, (V+ - V-) = 20V (Note 2)
W
-2.0 — +2.0 LSb I = 830 μA, (V+ - V-) = 10V
W
-0.6 — +0.6 LSb 7-bit I = 3.0 mA, (V+ - V-) = 36V (Note 2)
W
-0.8 — +0.8 LSb I = 1.7 mA, (V+ - V-) = 20V (Note 2)
W
-1.1 — +1.1 LSb I = 830 μA, (V+ - V-) = 10V
W
-1.0 — +1.0 LSb 50 k 8-bit I = 600 μA, (V+ - V-) = 36V (Note 2)
W
-1.0 — +1.0 LSb I = 330 μA, (V+ - V-) = 20V (Note 2)
W
-1.2 — +1.2 LSb I = 170 μA, (V+ - V-) = 10V
W
-0.5 — +0.5 LSb 7-bit I = 600 μA, (V+ - V-) = 36V (Note 2)
W
-0.5 — +0.5 LSb I = 330 μA, (V+ - V-) = 20V (Note 2)
W
-0.6 — +0.6 LSb I = 170 μA, (V+ - V-) = 10V
W
-1.0 — +1.0 LSb 100 k 8-bit I = 300 μA, (V+ - V-) = 36V (Note 2)
W
-1.0 — +1.0 LSb I = 170 μA, (V+ - V-) = 20V(Note 2)
W
-1.2 — +1.2 LSb I = 83 μA, (V+ - V-) = 10V
W
-0.5 — +0.5 LSb 7-bit I = 300 μA, (V+ - V-) = 36V (Note 2)
W
-0.5 — +0.5 LSb I = 170 μA, (V+ - V-) = 20V (Note 2)
W
-0.6 — +0.6 LSb I = 83 μA, (V+ - V-) = 10V
W
Note 2: This parameter is not tested, but specified by characterization.
Note 12: Nonlinearity is affected by wiper resistance (RW), which changes significantly over voltage and temperature.
Note 13: Externally connected to a Rheostat configuration (RBW), and then tested.
Note 14: Wiper current (IW) condition determined by RAB(max) and Voltage Condition, the delta voltage between V+
and V- (voltages are 36V, 20V, and 10V).
Note 17: Analog switch leakage affects this specification. Higher temperatures increase the switch leakage.
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 11

## Page 12

MCP45HVX1
AC/DC CHARACTERISTICS (CONTINUED)
Standard Operating Conditions (unless otherwise specified)
Operating Temperature -40°C <= T <= +125°C (extended)
A
All parameters apply across the specified operating ranges unless noted.
DC Characteristics V+ = 10V to 36V (referenced to V-);
V+ = +5V to +18V and V- = -5.0V to -18V (referenced to DGND -> ±5V to ±18V),
V = +2.7V to 5.5V, 5 k, 10 k, 50 k, 100 k devices.
L
Typical specifications represent values for V = 5.5V, T = +25°C.
L A
Parameters Sym. Min. Typ. Max. Units Conditions
Rheostat R-DNL -0.5 — +0.5 LSb 5 k 8-bit I = 6.0 mA, (V+ - V-) = 36V (Note 2)
W
Differential -0.5 — +0.5 LSb I = 3.3 mA, (V+ - V-) = 20V (Note 2)
W
Nonlinearity
-0.8 — +0.8 LSb I = 1.7 mA, (V+ - V-) = 10V
(Note 12, Note 13, W
Note 14, Note 17) -0.25 — +0.25 LSb 7-bit I W = 6.0 mA, (V+ - V-) = 36V (Note 2)
(see Appendix -0.25 — +0.25 LSb I = 3.3 mA, (V+ - V-) = 20V (Note 2)
W
B.5)
-0.4 — +0.4 LSb I = 1.7 mA, (V+ - V-) = 10V
W
-0.5 — +0.5 LSb 10 k 8-bit I = 3.0 mA, (V+ - V-) = 36V (Note 2)
W
-0.5 — +0.5 LSb I = 1.7 mA, (V+ - V-) = 20V (Note 2)
W
-0.5 — +0.5 LSb I = 830 μA, (V+ - V-) = 10V
W
-0.25 — +0.25 LSb 7-bit I = 3.0 mA, (V+ - V-) = 36V (Note 2)
W
-0.25 — +0.25 LSb I = 1.7 mA, (V+ - V-) = 20V (Note 2)
W
-0.25 — +0.25 LSb I = 830 μA, (V+ - V-) = 10V
W
-0.5 — +0.5 LSb 50 k 8-bit I = 600 μA, (V+ - V-) = 36V (Note 2)
W
-0.5 — +0.5 LSb I = 330 μA, (V+ - V-) = 20V (Note 2)
W
-0.5 — +0.5 LSb I = 170 μA, (V+ - V-) = 10V
W
-0.25 — +0.25 LSb 7-bit I = 600 μA, (V+ - V-) = 36V (Note 2)
W
-0.25 — +0.25 LSb I = 330 μA, (V+ - V-) = 20V (Note 2)
W
-0.25 — +0.25 LSb I = 170 μA, (V+ - V-) = 10V
W
-0.5 — +0.5 LSb 100 k 8-bit I = 300 μA, (V+ - V-) = 36V (Note 2)
W
-0.5 — +0.5 LSb  I = 170 μA, (V+ - V-) = 20V (Note 2)
W
-0.5 — +0.5 LSb I = 83 μA, (V+ - V-) = 10V
W
-0.25 — +0.25 LSb 7-bit I = 300 μA, (V+ - V-) = 36V (Note 2)
W
-0.25 — +0.25 LSb I = 170 μA, (V+ - V-) = 20V (Note 2)
W
-0.25 — +0.25 LSb I = 83 μA, (V+ - V-) = 10V
W
Note 2: This parameter is not tested, but specified by characterization.
Note 12: Nonlinearity is affected by wiper resistance (RW), which changes significantly over voltage and temperature.
Note 13: Externally connected to a Rheostat configuration (RBW), and then tested.
Note 14: Wiper current (IW) condition determined by RAB(max) and Voltage Condition, the delta voltage between V+
and V- (voltages are 36V, 20V, and 10V).
Note 17: Analog switch leakage affects this specification. Higher temperatures increase the switch leakage.
DS20005304B-page 12  2014-2023 Microchip Technology Inc. and its subsidiaries

## Page 13

MCP45HVX1
AC/DC CHARACTERISTICS (CONTINUED)
Standard Operating Conditions (unless otherwise specified)
Operating Temperature -40°C <= T <= +125°C (extended)
A
All parameters apply across the specified operating ranges unless noted.
DC Characteristics V+ = 10V to 36V (referenced to V-);
V+ = +5V to +18V and V- = -5.0V to -18V (referenced to DGND -> ±5V to ±18V),
V = +2.7V to 5.5V, 5 k, 10 k, 50 k, 100 k devices.
L
Typical specifications represent values for V = 5.5V, T = +25°C.
L A
Parameters Sym. Min. Typ. Max. Units Conditions
Capacitance (P ) C — 75 — pF Measured to V-, f =1 MHz,
A A
Wiper code = Mid Scale
Capacitance (P ) C — 120 — pF Measured to V-, f =1 MHz,
w W
Wiper code = Mid Scale
Capacitance (P ) C — 75 — pF Measured to V-, f =1 MHz,
B B
Wiper code = Mid Scale
Common-Mode I — 5 — nA V = V = V
CM A B W
Leakage
Digital Interface Pin C , — 10 — pF f = 400 kHz
IN C
Capacitance C
OUT
Digital Inputs/Outputs (SDA, SCL, A0, A1, SHDN, WLAT)
Schmitt Trigger High- V 0.7 V — V + 0.3V V 1.8V <= V <= 5.5V
IH L L L
Input Threshold
Schmitt Trigger Low- V DGND - 0.5V — 0.3 V V
IL L
Input Threshold
Hysteresis of Schmitt V — 0.1 V — V
HYS L
Trigger Inputs
Output Low V DGND — 0.2 V V V = 5.5V, I = 5 mA
OL L L OL
Voltage (SDA) DGND — 0.2 V V V = 1.8V, I = 800 μA
L L OL
Input Leakage I -1 1 uA V = V and V = DGND
IL IN L IN
Current
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 13

## Page 14

MCP45HVX1
AC/DC CHARACTERISTICS (CONTINUED)
Standard Operating Conditions (unless otherwise specified)
Operating Temperature -40°C <= T <= +125°C (extended)
A
All parameters apply across the specified operating ranges unless noted.
DC Characteristics V+ = 10V to 36V (referenced to V-);
V+ = +5V to +18V and V- = -5.0V to -18V (referenced to DGND -> ±5V to ±18V),
V = +2.7V to 5.5V, 5 k, 10 k, 50 k, 100 k devices.
L
Typical specifications represent values for V = 5.5V, T = +25°C.
L A
Parameters Sym. Min. Typ. Max. Units Conditions
RAM (Wiper, TCON) Value
Wiper Value Range N 0h — FFh hex 8-bit
0h — 7Fh hex 7-bit
Wiper POR/BOR Value N 7Fh hex 8-bit
POR/BOR
3Fh hex 7-bit
TCON Value Range N 0h — FFh hex
TCON POR/BOR Value N FF hex All Terminals connected
TCON
Power Requirements
Power Supply PSS — 0.0015 0.0035 %/% 8-bit V = 2.7V to 5.5V,
L
Sensitivity V+ = 18V, V- = -18V,
(see Appendix B.20) Code = 7Fh
— 0.0015 0.0035 %/% 7-bit V = 2.7V to 5.5V,
L
V+ = 18V, V- = -18V,
Code = 3Fh
Power Dissipation P — 260 — mW 5 k V = 5.5V, V+ = 18V, V- = -18V
DISS L
— 130 — mW 10 k (Note 15)
— 26 — mW 50 k
— 13 — mW 100 k
Note 15: PDISS = I * V, or ( (IDDD * 5.5V) + (IDDA * 36V) + (IAB * 36V) ).
DS20005304B-page 14  2014-2023 Microchip Technology Inc. and its subsidiaries

## Page 15

MCP45HVX1
DC Notes:
1. This specification by design.
2. This parameter is not tested, but specified by characterization.
3. See Absolute Maximum Ratings.
4. V+ voltage is dependent on V- voltage. The maximum delta voltage between V+ and V- is 36V. The digital logic
DGND potential can be anywhere between V+ and V-, the V potential must be  DGND and  V+.
L
5. Minimum value determined by maximum V- to V+ potential equals 36V and minimum V = 1.8V for operation. So
L
36V - 1.8V = 34.2V.
6. POR/BOR is not rate dependent.
7. Supply current (I and I ) is independent of current through the resistor network.
DDD DDA
8. Resistance (R ) is defined as the resistance between Terminal A to Terminal B.
AB
9. Ensured by the R specification and Ohm’s Law.
AB
10. Measured at V with V = V+ and V = V-.
W A B
11. Resistor terminals A, W and B’s polarity with respect to each other is not restricted.
12. Nonlinearity is affected by wiper resistance (R ), which changes significantly over voltage and temperature.
W
13. Externally connected to a Rheostat configuration (R ), and then tested.
BW
14. Wiper current (I ) condition determined by R and Voltage Condition, the delta voltage between V+ and V-
W AB(max)
(voltages are 36V, 20V, and 10V).
15. P = I * V, or ( (I * 5.5V) + (I * 36V) + (I * 36V) ).
DISS DDD DDA AB
16. For specified analog performance, V+ must be 20V or greater (unless otherwise noted).
17. Analog switch leakage affects this specification. Higher temperatures increase the switch leakage.
18. During the power-up sequence, to ensure expected analog POR operation, the two power systems (analog and
digital) should have a common reference to ensure that the driven DGND voltage is not at a higher potential than
the driven V+ voltage.
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 15

## Page 16

MCP45HVX1
1.1 Timing Waveforms and Requirements
± 1 LSb
New Value
W Old Value
FIGURE 1-1: Settling Time Waveforms.
TABLE 1-1: WIPER SETTLING TIMING
Standard Operating Conditions (unless otherwise specified)
Operating Temperature -40°C <= T <= +125°C (extended)
A
All parameters apply across the specified operating ranges unless noted.
Timing Characteristics V+ = 10V to 36V (referenced to V-);
V+ = +5V to +18V and V- = -5.0V to -18V (referenced to DGND -> ±5V to ±18V),
V = +2.7V to 5.5V, 5 k, 10 k, 50 k, 100 k devices.
L
Typical specifications represent values for V = 5.5V, T = +25°C.
L A
Parameters Sym. Min. Typ. Max. Units Conditions
V Settling Time t — 1 — μs 5 k Code = 00h -> FFh (7Fh); FFh (7Fh) -> 00h
W S
(V A = 10V, V B = 0V, — 1 — μs 10 k Code = 00h -> FFh (7Fh); FFh (7Fh) -> 00h
±1LSb error band,
— 2.5 — μs 50 k Code = 00h -> FFh (7Fh); FFh (7Fh) -> 00h
C = 50 pF )
L
— 5 — μs 100 k Code = 00h -> FFh (7Fh); FFh (7Fh) -> 00h
DS20005304B-page 16  2014-2023 Microchip Technology Inc. and its subsidiaries

## Page 17

MCP45HVX1
SCL
91 93
90 92
SDA
START ACK/ACK STOP
Condition Pulse Condition
94
96 95
96
WLAT
FIGURE 1-2: I2C Bus Start/Stop Bits Timing Waveforms.
TABLE 1-2: I2C BUS START/STOP BITS AND WLAT REQUIREMENTS
I2C AC Characteristics Standard Operating Conditions (unless otherwise specified)
Operating Temperature -40degC <= TA <= +125degC (Extended)
2.7V <= V <= 5.5V; DGND = V- (Note 1)
L
Param. No. Symbol Characteristic Min. Max. Units Conditions
F Standard mode 0 100 kHz C = 400 pF, 1.8V <= V <= 5.5V
SCL b L
Fast mode 0 400 kHz C = 400 pF, 2.7V <= V <= 5.5V
b L
High Speed 1.7 0 1.7 MHz C = 400 pF, 4.5V <= V <= 5.5V
b L
High Speed 3.4 0 3.4 MHz C = 100 pF, 4.5V <= V <= 5.5V
b L
D102 Cb Bus capacitive 100 kHz mode — 400 pF
loading 400 kHz mode — 400 pF
1.7 MHz mode — 400 pF
3.4 MHz mode — 100 pF
90 T Start condition 100 kHz mode 4700 — ns Only relevant for repeated Start
SU:STA
Setup time 400 kHz mode 600 — ns condition
1.7 MHz mode 160 — ns
3.4 MHz mode 160 — ns
91 T Start condition 100 kHz mode 4000 — ns After this period the first clock
HD:STA
Hold time 400 kHz mode 600 — ns pulse is generated
1.7 MHz mode 160 — ns
3.4 MHz mode 160 — ns
92 T Stop condition 100 kHz mode 4000 — ns
SU:STO
Setup time 400 kHz mode 600 — ns
1.7 MHz mode 160 — ns
3.4 MHz mode 160 — ns
93 T Stop condition 100 kHz mode 4000 — ns
HD:STO
Hold time 400 kHz mode 600 — ns
1.7 MHz mode 160 — ns
3.4 MHz mode 160 — ns
94 T WLAT ↑ to SCL↑ (write data ACK 10 — ns Write Data delayed, Note 9
WLSU
bit) Setup time
95 T SCL ↑ to WLAT↑ (write data ACK 250 — ns Write Data delayed, Note 9
WLHD
bit) Hold time
96 T WLAT High or Low Time 2 — μs
WLATL
Note 1: Serial Interface has equal performance when DGND >= V- + 0.9V.
Note 9: The transition of the WLAT signal between 10 ns before the rising edge (Spec 94) and 200 ns after the rising edge
(Spec 95) of the SCL signal is indeterminant if the Write Data is delayed or not.
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 17

## Page 18

MCP45HVX1
103 100 102
101
SCL
90 106
91 107 92
SDA
In
109 109 110
SDA
Out
FIGURE 1-3: I2C Bus Timing Waveforms.
TABLE 1-3: I2C BUS REQUIREMENTS (CLIENT MODE)
I2C AC Characteristics Standard Operating Conditions (unless otherwise specified)
Operating Temperature -40degC <= TA <= +125degC (Extended)
2.7V <= V <= 5.5V; DGND = V- (Note 1)
L
Param. Symbol Characteristic Min. Max. Units Conditions
No.
100 T Clock high time 100 kHz mode 4000 — ns 1.8V-5.5V
HIGH
400 kHz mode 600 — ns 2.7V-5.5V
1.7 MHz mode 120 — ns 4.5V-5.5V
3.4 MHz mode 60 — ns 4.5V-5.5V
101 T Clock low time 100 kHz mode 4700 — ns 1.8V-5.5V
LOW
400 kHz mode 1300 — ns 2.7V-5.5V
1.7 MHz mode 320 — ns 4.5V-5.5V
3.4 MHz mode 160 — ns 4.5V-5.5V
102A (6) T RSCL SCL rise time 100 kHz mode — 1000 ns Cb is specified to be from
400 kHz mode 20 + 0.1Cb 300 ns 10 to 400 pF (100 pF
maximum for 3.4 MHz
1.7 MHz mode 20 80 ns
mode)
1.7 MHz mode 20 160 ns After a Repeated Start
condition or an
Acknowledge bit
3.4 MHz mode 10 40 ns
3.4 MHz mode 10 80 ns After a Repeated Start
condition or an
Acknowledge bit
102B (6) T RSDA SDA rise time 100 kHz mode — 1000 ns Cb is specified to be from
10 to 400 pF (100 pF max
400 kHz mode 20 + 0.1Cb 300 ns
for 3.4 MHz mode)
1.7 MHz mode 20 160 ns
3.4 MHz mode 10 80 ns
Note 1: Serial Interface has equal performance when DGND >= V- + 0.9V.
Note 6: Not tested.
DS20005304B-page 18  2014-2023 Microchip Technology Inc. and its subsidiaries

## Page 19

MCP45HVX1
TABLE 1-4: I2C BUS REQUIREMENTS (CLIENT MODE) (CONTINUED)
I2C AC Characteristics Standard Operating Conditions (unless otherwise specified)
Operating Temperature -40degC <= TA <= +125degC (Extended)
2.7V <= V <= 5.5V; DGND = V- (Note 1)
L
Param. No. Sym. Characteristic Min. Max. Units Conditions
103A (5) T FSCL SCL fall time 100 kHz mode — 300 ns Cb is specified to be from
400 kHz mode 20 + 0.1Cb 300 ns 10 to 400 pF (100 pF max
for 3.4 MHz mode)
1.7 MHz mode 20 80 ns
3.4 MHz mode 10 40 ns
103B (5) T FSDA SDA fall time 100 kHz mode — 300 ns Cb is specified to be from
400 kHz mode 20 + 0.1Cb (4) 300 ns 10 to 400 pF (100 pF max
for 3.4 MHz mode)
1.7 MHz mode 20 160 ns
3.4 MHz mode 10 80 ns
106 T Data input hold 100 kHz mode 0 — ns 1.8V-5.5V, Note 7
HD:DA
T time 400 kHz mode 0 — ns 2.7V-5.5V, Note 7
1.7 MHz mode 0 — ns 4.5V-5.5V, Note 7
3.4 MHz mode 0 — ns 4.5V-5.5V, Note 7
107 T Data input 100 kHz mode 250 — ns Note 3
SU:DAT
setup time 400 kHz mode 100 — ns
1.7 MHz mode 10 — ns
3.4 MHz mode 10 — ns
109 T Output valid 100 kHz mode — 3450 ns Note 2
AA
from clock 400 kHz mode — 900 ns
1.7 MHz mode — 150 ns Cb = 100 pF,
Note 2, Note 8
— 310 ns Cb = 400 pF,
Note 2, Note 6
3.4 MHz mode — 150 ns Cb = 100 pF, Note 2
110 T Bus free time 100 kHz mode 4700 — ns Time the bus must be free
BUF
400 kHz mode 1300 — ns before a new transmission
can start
1.7 MHz mode N.A. — ns
3.4 MHz mode N.A. — ns
T Input filter spike 100 kHz mode — 50 ns NXP Spec states N.A.
SP
suppression 400 kHz mode — 50 ns
(SDA and SCL)
1.7 MHz mode — 10 ns Spike suppression
3.4 MHz mode — 10 ns Spike suppression
Note 1: Serial Interface has equal performance when DGND >= V- + 0.9V.
Note 2: As a transmitter, the device must provide this internal minimum delay time to bridge the undefined region
(minimum 300 ns) of the falling edge of SCL to avoid unintended generation of Start or Stop conditions.
Note 3: A fast-mode (400 kHz) I2C bus device can be used in a standard mode (100 kHz) I2C bus system, but the
requirement tSU;DAT >= 250 ns must then be met. This will automatically be the case if the device does not
stretch the Low period of the SCL signal. If such a device does stretch the Low period of the SCL signal, it
must output the next data bit to the SDA line TR max.+tSU;DAT = 1000 + 250 = 1250 ns (according to the
standard mode I2C bus specification) before the SCL line is released.
Note 6: Not tested.
Note 7: A host transmitter must provide a delay to ensure that difference between SDA and SCL fall times do not
unintentionally create a Start or Stop condition.
Note 8: Ensured by the TAA 3.4 MHz specification test.
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 19

## Page 20

MCP45HVX1
Timing Table Notes:
1. Serial Interface has equal performance when DGND V- + 0.9V.
2. As a transmitter, the device must provide this internal minimum delay time to bridge the undefined region
(minimum 300 ns) of the falling edge of SCL to avoid unintended generation of Start or Stop conditions.
3. A fast-mode (400 kHz) I2C bus device can be used in a standard mode (100 kHz) I2C bus system, but the require-
ment t  250 ns must then be met. This will automatically be the case if the device does not stretch the
SU;DAT
Low period of the SCL signal. If such a device does stretch the Low period of the SCL signal, it must output the
next data bit to the SDA line
T max.+t = 1000 + 250 = 1250 ns (according to the standard mode I2C bus specification) before the SCL
R SU;DAT
line is released.
4. The MCP45HVX1 device must provide a data hold time to bridge the undefined part between V and V of the
IH IL
falling edge of the SCL signal. This specification is not a part of the I2C specification, but must be tested in order
to ensure that the output data will meet the setup and hold specifications for the receiving device.
5. Use Cb in pF for the calculations.
6. Not tested.
7. A host transmitter must provide a delay to ensure that difference between SDA and SCL fall times do not
unintentionally create a Start or Stop condition.
8. Ensured by the T 3.4 MHz specification test.
AA
9. The transition of the WLAT signal between 10 ns before the rising edge (Spec 94) and 200 ns after the rising
edge (Spec 95) of the SCL signal is indeterminant if the Write Data is delayed or not.
DS20005304B-page 20  2014-2023 Microchip Technology Inc. and its subsidiaries

## Page 21

MCP45HVX1
TEMPERATURE CHARACTERISTICS
Electrical Specifications: Unless otherwise indicated, V = +2.7V to +5.5V, V+ = +10V to +36V, V- = DGND = GND.
L
Parameters Sym. Min. Typ. Max. Units Conditions
Temperature Ranges
Specified Temperature Range T -40 — +125 °C
A
Operating Temperature Range T -40 — +125 °C
A
Storage Temperature Range T -65 — +150 °C
A
Thermal Package Resistances
Thermal Resistance, 14L-TSSOP (ST)  — 100 — °C/W
JA
Thermal Resistance, 20L-VQFN (MQ)  — 36.1 — °C/W
JA
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 21

## Page 22

MCP45HVX1
2.0 TYPICAL PERFORMANCE CURVES
Note: The device Performance Curves are available in a separate document. This is done to keep the file size of
this PDF document less than the 10MB file attachment limit of many mail servers.
The MCP45HVX1 Performance Curves document is literature number DS20005307, and can be found on
the Microchip web site. Look at the MCP45HVX1 Product Page under Documentation and Software, in the
Data Sheets category.
DS20005304B-page 22  2014-2023 Microchip Technology Inc. and its subsidiaries

## Page 23

MCP45HVX1
NOTES:
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 23

## Page 24

MCP45HVX1
3.0 PIN DESCRIPTIONS
The descriptions of the pins are listed in Table 3-1.
Additional descriptions of the device pins follows.
TABLE 3-1: PINOUT DESCRIPTION FOR THE MCP45HVX1
Pin
TSSOP VQFN Function
Buffer
Symbol Type
Type
14L 20L
1 1 V P — Positive Digital Power Supply Input
L
2 2 SCL I ST I2C Serial Clock pin
3 3 A1 I ST I2C Address 1
4 4 SDA I/O ST I2C Serial Data pin
5 5 A0 I ST I2C Address 0
6 6 WLAT I ST Wiper Latch Enable
0 = Received I2C Shift Register Buffer (SPBUF) value is
transfered to Wiper register.
1 = Received I2C data value is held in I2C Shift Register
Buffer (SPBUF).
7 8, 9, 10, 17, NC — — Pin not internally connected to die. To reduce noise
18, 19, 20 coupling, connect pin either to DGND or V .
L
8 7 SHDN I ST Shutdown
9 11 DGND P — Ground
10 12 V- P — Analog Negative Potential Supply
11 13 P0B I/O A Potentiometer 0 Terminal B
12 14 P0W I/O A Potentiometer 0 Wiper
Terminal
13 15 P0A I/O A Potentiometer 0 Terminal A
14 16 V+ P — Analog Positive Potential Supply
— 21 EP P — Exposed Pad, connect to V- signal or Not Connected
(floating). (Note 1)
Legend: A = Analog ST = Schmitt Trigger
I = Input O = Output I/O = Input/OutputP = Power
Note 1: The VQFN package has a contact on the bottom of the package. This contact is conductively connected to
the die substrate, and therefore should be unconnected or connected to the same ground as the device’s
V- pin.
DS20005304B-page 24  2014-2023 Microchip Technology Inc. and its subsidiaries

## Page 25

MCP45HVX1
3.1 Positive Power Supply Input (V ) 3.11 Potentiometer Terminal B
L
The V pin is the device’s positive power supply input. The Terminal B pin is connected to the internal
L
The input power supply is relative to DGND and can potentiometer’s Terminal B.
range from 1.8V to 5.5V. A decoupling capacitor on V
L The potentiometer’s Terminal B is the fixed connection
(to DGND) is recommended to achieve maximum
to the zero-scale wiper value of the digital
performance.
potentiometer. This corresponds to a wiper value of
0x00 for both 7-bit and 8-bit devices.
3.2 Digital Ground (DGND)
The Terminal B pin does not have a polarity relative to
The DGND pin is the device’s digital ground reference.
the Terminal W or A pins. The Terminal B pin can
3.3 Analog Positive Voltage (V+) support both positive and negative current. The voltage
on Terminal B must be between V+ and V-.
Analog circuitry positive supply voltage. Must have a
higher potential than the V- pin. 3.12 Potentiometer Wiper (W) Terminal
3.4 Analog Negative Voltage (V-) The Terminal W pin is connected to the internal
potentiometer’s Terminal W (the wiper). The wiper
Analog circuitry negative supply voltage. The V- terminal is the adjustable terminal of the digital
potential must be lower than or equal to the DGND pin potentiometer. The Terminal W pin does not have a
potential. polarity relative to Terminal’s A or B pins. The Terminal
W pin can support both positive and negative current.
3.5 Serial Clock (SCL)
The voltage on Terminal W must be between V+ and V-.
The SCL pin is the serial interface's Serial Clock pin. If the V+ voltage powers-up before the V voltage, the
L
This pin is connected to the Host Controller’s SCL pin. wiper is forced to mid scale once the analog POR
The MCP45HVX1 is an I2C client device, so its SCL pin voltage is crossed.
is an input-only pin.
If the V+ voltage powers-up after the V voltage is
L
3.6 Serial Data (SDA) greater than the digital POR voltage, the wiper is forced
to the value in the Wiper register once the analog POR
The SDA pin is the serial interface’s Serial Data In/Out
voltage is crossed.
pin. This pin is connected to the Host Controller’s SDA
pin. The SDA pin is an open-drain N-Channel driver. 3.13 Potentiometer Terminal A
This pin allows the host controller to read and write the The Terminal A pin is connected to the internal
digital potentiometer registers (Wiper and TCON). potentiometer’s Terminal A.
3.7 Address 0 (A0) The potentiometer’s Terminal A is the fixed connection
to the full scale wiper value of the digital potentiometer.
The A0 pin is the Address 0 input for the I2C interface. This corresponds to a wiper value of 0xFF for 8-bit
At the device’s POR/BOR the value of the A0 address devices or 0x7F for 7-bit devices.
bit is latched. This input along with the A1 pin com-
The Terminal A pin does not have a polarity relative to
pletes the device address. This allows up to four
MCP45HVXX devices to be on a single I2C bus. the Terminal W or B pins. The Terminal A pin can
support both positive and negative current. The voltage
3.8 Address 1 (A1) on Terminal A must be between V+ and V-.
The A1 pin is the I2C interface’s Address 1 pin. Along 3.14 Exposed Pad (EP)
with the A0 pins, up to four MCP45HVXX devices can
This pad is only on the bottom of the VQFN packages.
be on a single I2C bus.
This pad is conductively connected to the device
substrate. The EP pin must be connected to the V-
3.9 Wiper Latch (WLAT)
signal or left floating. This pad could be connected to a
The WLAT pin is used to hold off the transfer of the PCB heat sink to assist as a heat sink for the device.
received wiper value (in the Shift register) to the Wiper
3.15 Not Connected (NC)
register. This allows this transfer to be synchronized to
an external event (such as zero crossing). See This pin is not internally connected to the die. To reduce
Section 4.3.2. noise coupling, these pins should be connected to
either V or DGND.
3.10 Shutdown (SHDN) L
The SHDN pin is used to force the resistor network
terminals into the hardware shutdown state. See
Section 4.3.1.
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 25

## Page 26

MCP45HVX1
4.0 FUNCTIONAL OVERVIEW 4.1 Operating Voltage Range
This data sheet covers a family of two volatile digital The MCP45HVX1 devices have four voltage signals.
potentiometer devices that will be referred to as These are:
MCP45HVX1. These devices are:
• V+ – Analog Power
• MCP45HV31 (7-bit resolution) • V L – Digital Power
• DGND – Digital Ground
• MCP45HV51 (8-bit resolution)
• V- – Analog Ground
As the Device Block Diagram shows, there are six
main functional blocks. These are: Figure 4-1 shows the two possible power-up
sequences; analog power rails power-up first, or digital
• Operating Voltage Range
power rails power-up first. The device has been
• POR/BOR Operation designed so that either power rail may power-up first.
• Memory Map The device has a POR circuit for both digital power
• Control Module circuitry and analog power circuitry.
• Resistor Network If the V+ voltage powers-up before the V voltage, the
L
• Serial Interface (I2C) wiper is forced to mid scale once the analog POR
voltage is crossed.
The POR/BOR operation and the Memory Map are
discussed in this section and the Resistor Network and If the V+ voltage powers-up after the V L voltage is
I2C operation are described in their own sections. The greater than the digital POR voltage, the wiper is forced
Device Commands are discussed in Section 7.0. to the value in the Wiper register, once the analog POR
voltage is crossed.
Figure 4-2 shows the three cases of the digital power
signals (V /DGND) with respect to the analog power
L
signals (V+/V-). The device implements level shifts
between the digital and analog power systems, which
allows the digital interface voltage to be anywhere in
the V+/V- voltage window.
Analog Voltage Powers-Up First Digital Voltage Powers-Up First
Referenced to V- V+ Referenced to V- V+
V V
L L
DGND DGND
V- V-
Referenced to DGND Referenced to DGND
V+ V+
V V
L L
DGND DGND
V- V-
FIGURE 4-1: Power-On Sequences.
DS20005304B-page 26  2014-2023 Microchip Technology Inc. and its subsidiaries

## Page 27

MCP45HVX1
Case 1 V+ Case 2 V+ Case 3 V+ and V L
DGND
Anywhere V
L
High- High- between High-
DGND
Voltage Voltage V+ and V- Voltage
Range Range (V L >= DGND) Range
V
L
V- and DGND V- V-
FIGURE 4-2: Voltage Ranges.
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 27

## Page 28

MCP45HVX1
4.2 POR/BOR Operation 4.2.1.1 Digital Circuitry
The resistor network’s devices are powered by the The Digital Power-On Reset (DPOR) is the case where
analog power signals (V+/V-), but the digital logic the device’s V L signal has power applied (referenced
from DGND) and the voltage rises above the trip point.
(including the wiper registers) is powered by the digital
power signals (V /DGND). So, both the digital circuitry The Brown-out Reset (BOR) occurs when a device had
L
and analog circuitry have independent POR/BOR power applied to it, and the voltage drops below the trip
circuits. point.
The wiper position will be forced to the default state The device’s RAM retention voltage (V RAM ) is lower
than the POR/BOR voltage trip point (V /V ). The
when the V+ voltage (relative to V-) is above the analog POR BOR
maximum V /V voltage is less than 1.8V.
POR/BOR trip point. The Wiper register will be in the POR BOR
default state when the V L voltage (relative to DGND) is When the device powers-up, the device V L will cross
above the digital POR/BOR trip point. the V /V voltage. Once the V voltage crosses
POR BOR L
the V /V voltage, the following happens:
The digital-signal-to-analog-signal voltage level shifters POR BOR
require a minimum voltage between the V L and V- • Volatile wiper registers are loaded with the POR/
signals. This voltage requirement is below the BOR value
operating supply voltage specifications. The wiper • The TCON registers are loaded with the default
output may fluctuate while the V L voltage is less than values
the level shifter operating voltage, since the analog • The device is capable of digital operation
values may not reflect the digital value. Output issues
Table 4-2 shows the default POR/BOR Wiper Register
may be reduced by powering-up the digital supply
Setting Selection.
voltages to their operating voltage, before powering the
analog supply voltage. When V POR /V BOR < V L < 2.7V, the electrical
performance may not meet the data sheet
4.2.1 POWER-ON RESET specifications. In this region, the device is capable of
incrementing, decrementing, reading and writing to its
Each power system has its own independent Power-On
volatile memory if the proper serial command is
Reset circuitry. This is done so that regardless of the
executed.
power-up sequencing of the analog and digital power
rails, the wiper output will be forced to a default value
TABLE 4-2: DEFAULT POR/BOR WIPER
after minimum conditions are met for either power sup-
REGISTER SETTING
ply.
(DIGITAL)
Table 4-1 shows the interaction between the analog
and digital PORs for the V+ and V voltages on the
L Typical
wiper pin state.
R
AB
Value
TABLE 4-1: WIPER PIN STATE BASED
ON POR CONDITIONS
V+ Voltage
V Voltage Comments L V+ < V+ ≥
V V
APOR APOR
V < V Unknown Mid Scale
L DPOR
Unknown Wiper Wiper register
V ≥ V Register can be updated
L DPOR Value (1)
Note 1: Default POR state of the Wiper register
value is the mid-scale value.
DS20005304B-page 28  2014-2023 Microchip Technology Inc. and its subsidiaries
egakcaP
edoC
Default
POR Wiper Device Wiper
Register Resolution Code
Setting(1)
8-bit 7Fh
5.0 k -502 Mid scale
7-bit 3Fh
8-bit 7Fh
10.0 k -103 Mid scale
7-bit 3Fh
8-bit 7Fh
50.0 k -503 Mid scale
7-bit 3Fh
8-bit 7Fh
100.0 k -104 Mid scale
7-bit 3Fh
Note 1: Register setting independent of analog
power voltage.

## Page 29

MCP45HVX1
4.2.1.2 Analog Circuitry TABLE 4-3: DEFAULT POR/BOR WIPER
SETTING (ANALOG)
The Analog Power-On Reset (APOR) is the case
where the device’s V+ pin voltage has power applied
(referenced from V-) and the V+ pin voltage rises above
Typical
the trip point.
R AB
Once the V pin voltage exceeds the digital POR trip Value L
point voltage, the Wiper register will control the wiper
setting.
Table 4-3 shows the default POR/BOR wiper setting for
when the V pin is not powered (< digital POR trip
L
point).
FIGURE 4-3: DGND, V , V+, and V- Signal Waveform Examples.
L
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 29
egakcaP
edoC
Default POR Wiper
Setting(1)
eciveD
noituloseR
Analog Wiper
Output Register
Position Code (hex)
0x7F 8-bit
5.0 k -502 Mid scale
0x3F 7-bit
0x7F 8-bit
10.0 k -103 Mid scale
0x3F 7-bit
0x7F 8-bit
50.0 k -503 Mid scale
0x3F 7-bit
0x7F 8-bit
100.0 k -104 Mid scale
0x3F 7-bit
Note 1: Wiper setting is dependent on the Wiper
register value if the V voltage is greater
L
than the digital POR voltage.
Referenced to DGND
V+
V
L
V /V
POR BOR
DGND
V-
Digital logic has been
Digital logic has been reset (POR). This
reset (POR). This Digital logic has been Brown-out includes the Wiper register.
includes the Wiper register. reset (POR). This condition,
includes the Wiper register. Wiper value Analog Power
unknown is recovering (still Low) and V
L
Brown-out condition rail/pin no longer sources current
Analog Power
Wiper value unknown to V+
is Low
Note: When V is above V+ (floating), the V pin ESD clamping diode will cause the V+ level to be pulled up.
L L

## Page 30

MCP45HVX1
4.2.2 BROWN-OUT RESET Whenever V transitions from V < V to V >
L L DBOR L
V , (a POR event) the wiper’s POR/BOR value is
Each power system has its own independent Brown- DBOR
latched into the Wiper register and the volatile TCON
Out Reset circuitry. This is done so that regardless of
register is forced to the POR/BOR state.
the power-down sequencing of the analog and digital
power rails, the wiper output will be forced to a default When 1.8V <= V L , the device is capable of digital
value after the low-voltage conditions are met for either operation.
power supply. Table 4-5 shows the digital potentiometer’s level of
Table 4-4 shows the interaction between the analog functionality across the entire V L range, while
and digital BORs for the V+ and V voltages on the Figure 4-4 illustrates the Power-Up and Brown-Out
L
wiper pin state. functionality.
4.2.2.2 Analog Circuitry
TABLE 4-4: WIPER PIN STATE BASED
ON BOR CONDITIONS The Analog Brown-Out-Reset (ABOR) is the case
where the device’s V+ pin has power applied (refer-
V+ Voltage
enced from V-) and the V+ pin voltage drops below the
V L Voltage V+ < V+ ≥ Comments trip point. In this case, the resistor network terminal’s
V V pins can become an unknown state.
ABOR ABOR
V < V Unknown Mid Scale
L DBOR
Unknown Wiper Wiper register
V ≥ V Register can be updated
L DBOR
Value (1)
Note 1: Default POR state of the Wiper register
value is the mid-scale value.
4.2.2.1 Digital Circuitry
When the device’s digital power supply powers-down,
the device V pin voltage will cross the digital V /
L DPOR
V voltage.
DBOR
Once the V voltage decreases below the V /
L DPOR
V voltage, the following happens:
DBOR
• Serial Interface is disabled
If the V voltage decreases below the V voltage,
L RAM
the following happens:
• Volatile wiper registers may become corrupted
• TCON registers may become corrupted
Section 4.2.1, Power-on Reset describes what
occurs as the voltage recovers above the V /
DPOR
V voltage.
DBOR
Serial commands not completed due to a brown-out
condition may cause the memory location to become
corrupted.
The brown-out circuit establishes a minimum V
DBOR
threshold for operation (V < 1.8V). The digital
DBOR
BOR voltage (V ) is higher than the RAM retention
DBOR
voltage (V ) so that as the device voltage crosses
RAM
the digital BOR threshold, the value that is loaded into
the volatile Wiper register is not corrupted due to RAM
retention issues.
When V < V , all communications are ignored and
L DBOR
potentiometer terminals are forced to the analog BOR
state.
DS20005304B-page 30  2014-2023 Microchip Technology Inc. and its subsidiaries

## Page 31

MCP45HVX1
TABLE 4-5: DEVICE FUNCTIONALITY AT EACH V REGION
L
Wiper
Serial Potentiometer
V L Level V+/V- Level Interface Terminals (2) Register Output Comment
Setting (2)
V < V < 1.8V Valid range Ignored “Unknown” Unknown Invalid
L DBOR
Invalid range Ignored “Unknown” Unknown Invalid
V <= V < 1.8V Valid range “Unknown” Connected Volatile Valid The volatile registers are
DBOR L
Invalid range “Unknown” Connected Wiper Regis- Invalid forced to the POR/BOR
ter state when V transitions
L
initialized above the V trip
DPOR
point
1.8V <= V <= 5.5V Valid range Accepted Connected Volatile Valid
L
Invalid range Accepted Connected Wiper Regis- Invalid
ter deter-
mines Wiper
Setting
Note 1: For system voltages below the minimum operating voltage, it is recommended to use a voltage supervisor
to hold the system in Reset. This ensures that MCP45HVX1 commands are not attempted out of the
operating range of the device.
2: Assumes that V+ > V .
APOR
Normal Operation Range Normal Operation Range
V Outside Specified
L
AC/DC Range
1.8V
V
POR/BOR
V
RAM
DGND
Device’s Device’s Serial
Serial Interface is V Delay
Interface is “Not Operational” BOR
Wiper Forced to Default POR/BOR setting
“Not Specified”
FIGURE 4-4: Power-Up and Brown Out - V+/V- at Normal Operating Voltage.
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 31

## Page 32

MCP45HVX1
4.3 Control Module 4.3.1.2 Terminal Control Register
The control module controls the following functionality: The Terminal Control (TCON) register allows the
device’s terminal pins to be independently removed
• Shutdown
from the application circuit. These terminal control
• Wiper Latch settings do not modify the wiper setting values. Also,
this has no effect on the serial interface and the
4.3.1 SHUTDOWN
memory/wipers are still under full user control.
The MCP45HVX1 has two methods to disconnect the
The resistor network has four TCON bits associated
terminal’s pins (P0A, P0W, and P0B) from the resistor
with it. One bit for each terminal (A, W, and B) and one
network. These are:
to have a software configuration that matches the
• Hardware Shutdown pin (SHDN) configuration of the SHDN pin. These bits are named
• Terminal Control Register (TCON) R0A, R0W, R0B, and R0HW. Register 4-1 describes
the operation of the R0HW, R0A, R0B, and R0W bits.
4.3.1.1 Hardware Shutdown Pin Operation
The SHDN pin has the same functionality as
Microchip’s family of standard voltage devices. When
the SHDN pin is Low, the P0A terminal will disconnect
(become open) while the P0W terminal simultaneously
connects to the P0B terminal (see Figure 4-5).
Note: When the SHDN pin is Active (V ), the
IL
state of the TCON register bits is
overridden (ignored). When the state of
the SHDN pin returns to the Inactive state
(V ), the TCON register bits return to
IH
controlling the terminal connection state. Figure 4-6 shows how the SHDN pin signal and the
That is, the value in the TCON register is R0HW bit signal interact to control the hardware
not corrupted. shutdown of each resistor network (independently).
The Hardware Shutdown Pin mode does not corrupt
the volatile Wiper register. When Shutdown is exited,
the device returns to the wiper setting specified by the
volatile wiper value. See Section 5.7 for additional
description details.
Note: When the SHDN pin is active, the serial FIGURE 4-6: R0HW bit and SHDN pin
interface is not disabled, and serial Interaction.
interface activity is executed.
A
W
B
FIGURE 4-5: Hardware Shutdown
Resistor Network Configuration.
DS20005304B-page 32  2014-2023 Microchip Technology Inc. and its subsidiaries
krowteN
rotsiseR
Note: When the R0HW bit forces the resistor
network into the hardware SHDN state,
the state of the TCON register R0A, R0W,
and R0B bits is overridden (ignored).
When the state of the R0HW bit no longer
forces the resistor network into the
hardware SHDN state, the TCON register
R0A, R0W, and R0B bits return to
controlling the terminal connection state.
That is, the R0HW bit does not corrupt the
state of the R0A, R0W, and R0B bits.
SHDN (from pin)
To Pot 0 Hardware
Shutdown Control
R0HW
(from TCON register)

## Page 33

MCP45HVX1
4.3.2 WIPER LATCH 4.3.3 DEVICE CURRENT MODES
The wiper latch pin is used to control when the new There are two current modes for volatile devices.
wiper value in the Wiper register is transferred to the These are:
wiper. This is useful for applications that need to
• Serial Interface Inactive (static operation)
synchronize the wiper updates. This may be for
• Serial Interface Active
synchronization to an external event, such as zero
crossing, or to synchronize the update of multiple For the I2C interface, static operation occurs when the
digital potentiometers. SDA and the SCL pins are static (High or Low).
When the WLAT pin is High, transfers from the Wiper
register to the wiper are inhibited. When the WLAT pin
is Low, transfers may occur from the Wiper register to
the wiper. Figure 4-7 shows the interaction of the WLAT
pin during an I2C command and the loading of the
wiper.
If the external event crossing time is long, then the
wiper could be updated the entire time that the WLAT
signal is Low. Once the WLAT signal goes High, the
transfer from the Wiper register is disabled. The Wiper
register can continue to be updated.
If the application does not require synchronized Wiper
register updates, then the WLAT pin should be tied
Low.
Note 1: This feature only inhibits the data transfer
from the Wiper register to the wiper.
2: When the WLAT pin becomes active,
data transferred to the wiper will not be
corrupted due to the Wiper Register
Buffer getting loaded from an active I2C
command.
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 33

## Page 34

MCP45HVX1
I2C Client Address + Write Command + Data (less ACK bit)
or ACK bit Stop bit
I2C Client Address + Inc/Dec Command (less ACK bit)
SDA ACK bit
SCL
WLAT state lock range
(for WLAT rising edge)
Case 1a
WLAT
Wiper Latch D[7:0] D[7:0]’
Wiper D[7:0]
Case 1b
WLAT
Wiper Latch D[7:0] D[7:0]’
Wiper D[7:0] D[7:0]’
Case 1c
WLAT
Wiper Latch D[7:0] D[7:0]’
Wiper D[7:0] D[7:0]’
Case 2a
WLAT
Wiper Latch D[7:0] D[7:0]’
Wiper D[7:0] D[7:0]’
Case 2b
WLAT
Wiper Latch D[7:0] D[7:0]’
Wiper D[7:0] D[7:0]’
Case 3a WLAT
Wiper Latch D[7:0] D[7:0]’
Wiper D[7:0] D[7:0]’
Case 3b
WLAT
Wiper Latch D[7:0] D[7:0]’
Wiper D[7:0] D[7:0]’
FIGURE 4-7: WLAT Interaction with I2C ACK Pulse
DS20005304B-page 34  2014-2023 Microchip Technology Inc. and its subsidiaries

## Page 35

MCP45HVX1
4.4 Memory Map
TABLE 4-6: WIPER REGISTER POR
STANDARD SETTINGS
The device memory supports 16 locations that are 8-
bits wide (16x8 bits). This memory space contains only (DIGITAL)
volatile locations (see Table 4-7).
Wiper
Default
Resistance Typical Code
4.4.1 VOLATILE MEMORY (RAM) POR Wiper
Code R Value
AB Setting
There are two volatile memory locations. These are: 8-bit 7-bit
• Volatile Wiper 0 -502 5.0 k Mid scale 7Fh 3Fh
• Terminal Control (TCON0) Register 0 -103 10.0 k Mid scale 7Fh 3Fh
The volatile memory starts functioning at the RAM -503 50.0 k Mid scale 7Fh 3Fh
retention voltage (V RAM ). The POR/BOR wiper code is -104 100.0 k Mid scale 7Fh 3Fh
shown in Table 4-6.
4.4.1.1 Write to Invalid (Reserved)
Table 4-7 shows this memory map and which serial
Addresses
commands operate (and do not) on each of these
locations. Any write to a reserved address will be ignored and will
generate an error condition. A Start bit is required to
Accessing an “invalid” address (for that device) or an
clear this error condition.
invalid command for that address will cause an error
condition on the serial interface. A Start bit is required
to clear this error condition.
TABLE 4-7: MEMORY MAP AND THE SUPPORTED COMMANDS
Address Function Allowed Commands Disallowed Commands (1) Memory Type
00h Volatile Wiper 0 Read, Write, — RAM
Increment, Decrement
01h-03h Reserved none Read, Write, —
Increment, Decrement
04h Volatile Read, Write Increment, Decrement RAM
TCON Register
05h-0Fh Reserved none Read, Write, —
Increment, Decrement
Note 1: This command on this address will generate an error condition. A Start bit is required to clear this error
condition.
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 35

## Page 36

MCP45HVX1
4.4.1.2 Terminal Control (TCON) Registers The value that is written to this register will appear on
the resistor network terminals when the serial
The Terminal Control (TCON) Register contains four
command has completed.
control bits for wiper 0. Register 4-1 describes each bit
of the TCON register. On a POR/BOR, the registers are loaded with FFh, for
all terminals connected. The host controller needs to
The state of each resistor network terminal connection
detect the POR/BOR event and then update the volatile
is individually controlled. That is, each terminal
TCON register values.
connection (A, B and W) can be individually connected/
disconnected from the resistor network. This allows the
system to minimize the currents through the digital
potentiometer.
REGISTER 4-1: TCON0 BITS (1, 2)
R-1 R-1 R-1 R-1 R/W-1 R/W-1 R/W-1 R/W-1
D7 D6 D5 D4 R0HW R0A R0W R0B
bit 7 bit 0
Legend:
R = Readable bit W = Writable bit U = Unimplemented bit, read as ‘0’
-n = Value at POR ‘1’ = Bit is set ‘0’ = Bit is cleared x = Bit is unknown
bit 7:4 D7-D4: Reserved. Forced to “1”
bit 3 R0HW: Resistor 0 Hardware Configuration Control bit
This bit forces Resistor 0 into the “shutdown” configuration of the Hardware pin
1 = Resistor 0 is NOT forced to the hardware pin “shutdown” configuration
0 = Resistor 0 is forced to the hardware pin “shutdown” configuration
bit 2 R0A: Resistor 0 Terminal A (P0A pin) Connect Control bit
This bit connects/disconnects the Resistor 0 Terminal A to the Resistor 0 Network
1 = P0A pin is connected to the Resistor 0 Network
0 = P0A pin is disconnected from the Resistor 0 Network
bit 1 R0W: Resistor 0 Wiper (P0W pin) Connect Control bit
This bit connects/disconnects the Resistor 0 Wiper to the Resistor 0 Network
1 = P0W pin is connected to the Resistor 0 Network
0 = P0W pin is disconnected from the Resistor 0 Network
bit 0 R0B: Resistor 0 Terminal B (P0B pin) Connect Control bit
This bit connects/disconnects the Resistor 0 Terminal B to the Resistor 0 Network
1 = P0B pin is connected to the Resistor 0 Network
0 = P0B pin is disconnected from the Resistor 0 Network
Note 1: These bits do not affect the Wiper register values.
2: The hardware SHDN pin (when active) overrides the state of these bits. When the SHDN pin returns to the
inactive state, the TCON register will control the state of the terminals. The SHDN pin does not modify the
state of the TCON bits.
DS20005304B-page 36  2014-2023 Microchip Technology Inc. and its subsidiaries

## Page 37

MCP45HVX1
NOTES:
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 37

## Page 38

MCP45HVX1
5.0 RESISTOR NETWORK 5.1 Resistor Ladder Module
The resistor network has either 7-bit or 8-bit resolution. The R AB resistor ladder is composed of the series of
Each resistor network allows zero-scale to full-scale equal value Step resistors (R S ) and the Full-Scale
connections. Figure 5-1 shows a block diagram for the (R FS ) and Zero-Scale (R ZS ) resistances:
resistive network of a device. The resistor network has R AB = R ZS + n * R S + R FS
up to three external connections. These are referred to Where “n” is determined by the resolution of the device.
as Terminal A, Terminal B, and the wiper (or Terminal The R and R resistances are discussed in
FS ZS
W). Section 5.1.3.
The resistor network is made up of several parts. These There is a connection point (tap) between each R
S
include: resistor. Each tap point is a connection point for an
• Resistor Ladder Module analog switch. The opposite side of the analog switch
• Wiper is connected to a common signal which is connected to
• Shutdown Control (terminal connections) the Terminal W (wiper) pin (see Section 5.2).
Terminal A and B as well as the wiper W do not have a Figure 5-1 shows a block diagram of the Resistor
polarity. These terminals can support both positive and Network. The R AB (and R S ) resistance has small
negative current. variations over voltage and temperature.
The end points of the resistor ladder are connected to
A analog switches, which are connected to the device
Terminal A and Terminal B pins. In the ideal case, these
8-Bit 7-Bit switches would have 0 of resistance, that is
R FS N = N = R = R = 0. This will also be referred to as the
255 127 FS ZS
Simplified model.
(FFh) (7Fh)
R (1)
RR W For an 8-bit device, there are 255 resistors in a string
SS
between Terminal A and Terminal B. The wiper can be
254 126
set to tap onto any of these 255 resistors, thus provid-
R S R W (1) (FEh) (7Eh) i T n e g r m 2 i 5 n 6 a l B po ). s A si b w le ip e s r e t s t e in t g tin s g ( i o n f c l 0 u 0 d h in c g o n Te n r e m ct i s n a T l e A rm a in n a d l
253 125
W (wiper) to Terminal B (zero scale). A wiper setting of
(FDh) (7Dh)
R (1) 7Fh is the mid-scale setting. A wiper setting of FFh con-
R W
R S nects Terminal W (wiper) to Terminal A (full scale).
AB
Table 5-2 illustrates the full wiper setting map.
W For a 7-bit device, there are 127 resistors in a string
between Terminal A and Terminal B. The wiper can be
1 1 set to tap onto any of these 127 resistors, thus provid-
(01h) (01h) ing 128 possible settings (including Terminal A and
R (1)
R W Terminal B). A wiper setting of 00h connects Terminal
S
W (wiper) to Terminal B (zero scale). A wiper setting of
0 0
3Fh is the mid-scale setting. A wiper setting of 7Fh con-
(00h) (00h)
R R (1) nects the wiper to Terminal A (full scale). Table 5-2
ZS W
illustrates the full wiper setting map.
Analog MUX
B 5.1.1 R AB CURRENT (I RAB )
The current through the R resistor (A pin to B pin) is
Note 1:The wiper resistance is dependent on AB
dependent on the voltage on the V and V pins and
several factors including wiper code, A B
the R resistance.
device V+ voltage, terminal voltages (on AB
A, B and W), and temperature.
EQUATION 5-1: R
Also for the same conditions, each tap AB
selection resistance has a small variation. | (V - V ) |
A B
This R W variation has greater effect on R AB = R ZS + ( n * R S ) + R FS = (I )
RAB
some specifications (such as INL) for the
V is the voltage on the V pin.
smaller resistance devices (5.0 k) A A
V is the voltage on the V pin.
compared to larger resistance devices B B
I is the current from the P0A pin to the P0B pin.
(100.0 k). RAB
FIGURE 5-1: Resistor Block Diagram.
DS20005304B-page 38  2014-2023 Microchip Technology Inc. and its subsidiaries

## Page 39

MCP45HVX1
5.1.2 STEP RESISTANCE (R ) EQUATION 5-2: R CALCULATION
S S
Step resistance (R S ) is the resistance from one tap set- Simplified Model (assumes R FS = R ZS = 0Ω)
ting to the next. This value will be dependent on the
R = ( n * R )
R value that has been selected (and the full-scale AB S 8-bit 7-bit
AB
and zero-scale resistances). The R resistors are R R R
S R = AB R = AB R = AB
manufactured so that they should be very consistent S S S
n 255 127
with each other, and track each other’s values as
voltage and/or temperature change. Detailed Model
Equation 5-2 shows the simplified and detailed equa- R = R + ( n * R ) + R
AB FS S ZS
tions for calculating the R value. The simplified equa-
S R - R - R
tion assumes R FS = R ZS = 0. Table 5-1 shows R S = AB FS ZS
example step resistance calculations for each device, n
and the variation of the detailed model (R FS  0; or
R  0) from the simplified model (R = R = 0).
ZS FS ZS (V - V )
FS ZS
As the R resistance option increases, the effects of
AB n
the R ZS and R FS resistance decreases. R S =
I
The total resistance of the device has minimal variation AB
due to operating voltage (see device characterization Where:
graphs). “n” = 255 (8-bit) or 127 (7-bit)
V is the wiper voltage at full-scale code
Equation 5-2 shows calculations for the step FS
V is the wiper voltage at zero-scale code
resistance. ZS
I is the current between Terminal A and
AB
Terminal B
TABLE 5-1: EXAMPLE STEP RESISTANCES (R ) CALCULATIONS
S
Example Resistance ()
Variation
R Resolution Comment
R R (3) R (3) S % (1)
AB ZS FS
Equation Value
0 0 5,000 / 127 39.37 0 7-bit Simplified Model (2)
80 60 4,860 / 127 38.27 -2.80 (127 R S )
5,000
0 0 5,000 / 255 19.61 0 8-bit Simplified Model (2)
80 60 4,860 / 255 19.06 -2.80 (255 R S )
0 0 10,000 / 127 78.74 0 7-bit Simplified Model (2)
80 60 9,860 / 127 77.64 -1.40 (127 R S )
10,000
0 0 10,000 / 255 39.22 0 8-bit Simplified Model (2)
80 60 9,860 / 255 38.67 -1.40 (255 R S )
0 0 50,000 / 127 393.70 0 7-bit Simplified Model (2)
80 60 49,860 / 127 392.60 -0.28 (127 R S )
50,000
0 0 50,000 / 255 196.08 0 8-bit Simplified Model (2)
80 60 49,860 / 255 195.53 -0.28 (255 R S )
0 0 100,000 / 127 787.40 0 7-bit Simplified Model (2)
80 60 99,860 / 127 786.30 -0.14 (127 R S )
100,000
0 0 100,000 / 255 392.16 0 8-bit Simplified Model (2)
80 60 99,860 / 255 391.61 -0.14 (255 R S )
Note 1: Delta % from Simplified Model R calculation value:
S
2: Assumes R = R = 0.
FS ZS
3: Zero-Scale (R ) and Full-Scale (R ) resistances are dependent on many operational characteristics of
ZS FS
the device, including the V+/V- voltage, the voltages on the A, B and W terminals, the wiper code selected,
the R resistance, and the temperature of the device.
AB
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 39

## Page 40

MCP45HVX1
5.1.3 R AND R RESISTORS 5.2 Wiper
FS ZS
The R FS and R ZS resistances are artifacts of the R AB The Wiper terminal is connected to an analog switch
resistor network implementation. In the ideal model, the
MUX, where one side of all the analog switches are
R
FS
and R
ZS
resistances would be 0. These resistors
connected together, the W terminal. The other side of
are included in the block diagram to help better model
each analog switch is connected to one of the taps of
the actual device operation. Equation 5-3 shows how to the R resistor string (see Figure 5-1).
AB
estimate the R , R , and R resistances, based on
S FS ZS
The value in the volatile Wiper register selects which
the measured voltages of V , V , and V and the
AB FS ZS
analog switch to close, connecting the W terminal to
measured current I .
AB
the selected node of the resistor ladder. The Wiper
EQUATION 5-3: ESTIMATING R S , R FS , register is 8-bits wide, and Table 5-2 shows the wiper
AND R value state for both 7-bit and 8-bit devices.
ZS
The wiper resistance (R ) is the resistance of the
| ( V - V ) | W
A FS
R = selected analog switch in the analog MUX. This
FS
(I )
RAB resistance is dependent on many operational
| ( V - V ) | characteristics of the device, including the V+/V- volt-
ZS B
R ZS = age, the voltages on the A, B and W terminals, the
(I )
RAB wiper code selected, the R resistance, and the tem-
AB
V S perature of the device.
R =
S (I )
RAB When the wiper value is at zero scale (00h), the wiper
Where: is connected closest to the B terminal. When the wiper
( V FS - V ZS ) value is at full scale (FFh for 8-bit, 7Fh for 7-bit), the
V = (8-bit device)
S 255 wiper is connected closest to the A terminal.
( V - V ) A zero-scale wiper value connects the W terminal
FS ZS
V S = (7-bit device) (wiper) to the B terminal (wiper = 00h). A full-scale
127
wiper value connects the W terminal (wiper) to the A
V is the V voltage when the wiper code is at terminal (wiper = FFh (8-bit), or wiper = 7Fh (7-bit)). In
FS W
full scale. these configurations, the only resistance between the
Terminal W and the other terminal (A or B) is that of the
V is the V voltage when the wiper code is at
ZS W analog switches.
zero scale.
TABLE 5-2: VOLATILE WIPER VALUE VS.
WIPER POSITION
Wiper Setting
Properties
7-bit 8-bit
7Fh FFh Full Scale (W = A), Increment
commands ignored
7Eh-40h FEh-80h W = N
3Fh 7Fh W = N (Mid Scale)
3Eh-01h 7Eh-01h W = N
00h 00h Zero Scale (W = B)
Decrement command
ignored
DS20005304B-page 40  2014-2023 Microchip Technology Inc. and its subsidiaries

## Page 41

MCP45HVX1
5.2.1 WIPER RESISTANCE (R ) 5.2.2 POTENTIOMETER
W
CONFIGURATION
Wiper resistance is significantly dependent on:
• The Resistor Network’s Supply Voltage (V ) In a potentiometer configuration, the wiper resistance
RN
• The Resistor Network’s Terminal (A, B, and W) variation does not affect the output voltage seen on the
Voltages W pin and therefore is not a significant source of error.
• Switch leakage (occurs at higher temperatures)
5.2.3 RHEOSTAT CONFIGURATION
• I current
W
In a rheostat configuration, the wiper resistance varia-
Figure 5-2 show the wiper resistance characterization
tion creates nonlinearity in the R (or R ) value. The
data for all four R resistances and temperatures. BW AW
AB
lower the nominal resistance (R ), the greater the
Each R resistance determined the maximum wiper AB
AB
possible relative error. Also, a change in voltage needs
current based on worst-case conditions
to be taken into account. For the 5.0 k device, the
R = R maximum and at full-scale code, V ~= V+
AB AB BW
maximum wiper resistance at 5.5V is approximately 6%
(but not exceeding V+). The V+ targets were 10V, 20V,
of the total resistance, while at 2.7V it is approximately
and 36V. What this graph shows is that at higher R
AB
6.5% of the total resistance.
resistances (50 k and 100 k) and at the highest tem-
perature (+125°C), the analog switch leakage causes
5.2.4 LEVEL SHIFTERS
an increase in the measured result of R , where R is
W W (DIGITAL TO ANALOG)
measured in a rheostat configuration with R = (V -
W BW
V ) / I . Since the digital logic may operate anywhere within the
BA BW
analog power range, level shifters are present so that
the digital signals control the analog circuitry. This level
2400 shifter logic is relative to the V- and V voltages. A delta
2200 L
2000 voltage of 2.7V between V L and V- is required for the
1800 serial interface to operate at the maximum specified
1600 frequency.
1400
1200
1000
800
FIGURE 5-2: R Resistance vs R ,
W AB
Wiper Current (I ), Temperature and Wiper
W
Code.
Since there is minimal variation of the total device
resistance (R ) over voltage, at a constant tempera-
AB
ture (see device characterization graphs), the change
in wiper resistance over voltage can have a significant
impact on the R and R errors.
INL DNL
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 41
)(cid:58)(
R
ecnatsise
W
-40C(cid:3)5k(cid:3)IW(cid:3)=(cid:3)1.7mA +25C(cid:3)5k(cid:3)IW(cid:3)=(cid:3)1.7mA +85C(cid:3)5k(cid:3)IW(cid:3)=(cid:3)1.7mA +125C(cid:3)5k(cid:3)IW(cid:3)=(cid:3)1.7mA
-40C(cid:3)5k(cid:3)IW(cid:3)=(cid:3)3.3mA +25C(cid:3)5k(cid:3)IW(cid:3)=(cid:3)3.3mA +85C(cid:3)5k(cid:3)IW(cid:3)=(cid:3)3.3mA +125C(cid:3)5k(cid:3)IW(cid:3)=(cid:3)3.3mA -40C(cid:3)5k(cid:3)IW(cid:3)=6.0mA +25C(cid:3)5k(cid:3)IW(cid:3)=(cid:3)6.0mA +85C(cid:3)5k(cid:3)IW(cid:3)=(cid:3)6.0mA +125C(cid:3)5k(cid:3)IW(cid:3)=(cid:3)6.0mA
-40C(cid:3)10k(cid:3)IW(cid:3)=(cid:3)830uA +25C(cid:3)10k(cid:3)IW(cid:3)=(cid:3)830uA +85C(cid:3)10k(cid:3)IW(cid:3)=(cid:3)830uA +125C(cid:3)10k(cid:3)IW(cid:3)=(cid:3)830uA -40C(cid:3)10k(cid:3)IW(cid:3)=(cid:3)1.7mA +25C(cid:3)10k(cid:3)IW(cid:3)=(cid:3)1.7mA +85C(cid:3)10k(cid:3)IW(cid:3)=(cid:3)1.7mA +125C(cid:3)10k(cid:3)IW(cid:3)=(cid:3)1.7mA -40C(cid:3)10k(cid:3)IW(cid:3)=(cid:3)3.0mA +25C(cid:3)10k(cid:3)IW(cid:3)=(cid:3)3.0mA +85C(cid:3)10k(cid:3)IW(cid:3)=(cid:3)3.0mA +125C(cid:3)10k(cid:3)IW(cid:3)=(cid:3)3.0mA
-40C(cid:3)50k(cid:3)IW(cid:3)=(cid:3)170uA +25C(cid:3)50k(cid:3)IW(cid:3)=(cid:3)170uA +85C(cid:3)50k(cid:3)IW(cid:3)=(cid:3)170uA +125C(cid:3)50k(cid:3)IW(cid:3)=(cid:3)170uA -40C(cid:3)50k(cid:3)IW(cid:3)=(cid:3)330uA +25C(cid:3)50k(cid:3)IW(cid:3)=(cid:3)330uA +85C(cid:3)50k(cid:3)IW(cid:3)=(cid:3)330uA +125C(cid:3)50k(cid:3)IW(cid:3)=(cid:3)330uA
-40C(cid:3)50k(cid:3)IW(cid:3)=(cid:3)600uA +25C(cid:3)50k(cid:3)IW(cid:3)=(cid:3)600uA +85C(cid:3)50k(cid:3)IW(cid:3)=(cid:3)600uA +125C(cid:3)50k(cid:3)IW(cid:3)=(cid:3)600uA -40C(cid:3)100k(cid:3)IW(cid:3)=(cid:3)83uA +25C(cid:3)100k(cid:3)IW(cid:3)=(cid:3)83uA +85C(cid:3)100k(cid:3)IW(cid:3)=(cid:3)83uA +125C(cid:3)100k(cid:3)IW(cid:3)=(cid:3)83uA -40C(cid:3)100k(cid:3)IW(cid:3)=170uA +25C(cid:3)100k(cid:3)IW(cid:3)=(cid:3)170uA +85C(cid:3)100k(cid:3)IW(cid:3)=(cid:3)170uA +125C(cid:3)100k(cid:3)IW(cid:3)=(cid:3)170uA
-40C(cid:3)100k(cid:3)IW(cid:3)=(cid:3)300uA +25C(cid:3)100k(cid:3)IW(cid:3)=(cid:3)300uA +85C(cid:3)100k(cid:3)IW(cid:3)=(cid:3)300uA +125C(cid:3)100k(cid:3)IW(cid:3)=(cid:3)300uA
IW=(cid:3)83uA,(cid:3)+125C(cid:3)(100k(cid:58)) I d n u c e re (cid:3)t a o s (cid:3)i e n d c (cid:3) r w e i a p s e e r d (cid:3)r (cid:3)a e n si a s l t o a g n s c w e(cid:3) i ( t R cWh ) (cid:3)l (cid:3)o ea cc k u a r g s e (cid:3)(cid:3) at(cid:3)(cid:3)
higher(cid:3)temperatures(cid:3)(such(cid:3)as(cid:3)+125C)(cid:3)and
800 largerR resistances
600
400
200
0
0 32 64 96 128 160 192 224 256
eR
repiW
IW=(cid:3)170uA,(cid:3)+
I
1
W
25
=
C
(cid:3)1
(cid:3)
7
(1
0
0
u
0
A
k
,
(cid:58)
(cid:3)+
)
125C(cid:3)(50k(cid:58))
larger(cid:3)RABresistances.
IW=(cid:3)300uA,(cid:3)+125C(cid:3)(100k(cid:58))
DAC Wiper Code

## Page 42

MCP45HVX1
5.3 Terminal Currents ues, without violating the maximum terminal current
specification. Table 5-3 shows resistance and current
The terminal currents are limited by several factors, calculations based on the R resistance (R resis-
AB S
including the R AB resistance (R S resistance). The tance) for a system that supports ± 18V ( 36V). In
maximum current occurs when the wiper is at either the
Rheostat configuration, the minimum wiper code value
zero-scale (I BW ) or full-scale (I AW ) code. In this case, is shown (for V BW = 36V). As the V BW voltage
the current is only going through the analog switches decreases, the minimum wiper code value also
(see I T specification in Electrical Characteristics). decreases. Using a wiper code less then this value will
When the current passes through at least one R S cause the maximum terminal current (I T ) specification
resistive element, then the maximum terminal current to be violated.
(I ) has a different limit. The current through the R
T AB
resistor is limited by the R resistance. The worst Note: For high terminal-current applications, it is
AB
case (max current) occurs when the resistance is at the recommended that proper PCB layout
minimum R value. techniques be used to address the ther-
AB
mal implications of this high current. The
Higher current capabilities allow a greater delta voltage
VQFN package has better thermal proper-
between the desired terminals for a given resistance.
ties than the TSSOP package.
This also allows a more usable range of wiper code val-
TABLE 5-3: TERMINAL (WIPER) CURRENT AND WIPER SETTINGS (R = R = R = 0Ω)
W FS ZS
R Resistance () R ()
AB S(MIN)
DS20005304B-page 42  2014-2023 Microchip Technology Inc. and its subsidiaries
)Am(
I
)XAM(BA
)1(
)
R / V63
=(
)NIM(BA
)Am(
) ) I(
W ro ,B
,A(
I
W
T
)1(
)
I ,
I(
SF
= W(WA
)SZ =
W(WB
)(
R WB
)2(
)
I / V63
=(
)XAM(T tatsoehR ’N‘ niM
V63
= V
nehw
WB
V63
*
R * N
)NIM(S
)3(
)Am(
I <=
T tatsoehR
nehW
V
)XAM(WB
)V(
h10 =
repiW
)
R *
I =(
)NIM(S
)XAM(T
Typical Min Max 8-bit 7-bit 8-bit 7-bit 8-bit 7-bit
5,000 4,000 6,000 15.686 31.496 9.00 25.0 1,440 91 45 0.392 0.787
10,000 8,000 12,000 31.373 62.992 4.50 12.5 2,880 91 45 0.392 0.787
50,000 40,000 60,000 156.863 314.961 0.90 6.5 5539 35 17 1.020 2.047
100,000 80,000 120,000 313.725 629.9 0.45 6.5 5539 17 8 2.039 4.094
Note 1: I or I currents can be much higher than this depending on voltage differential between Terminal B and
BW AW
Terminal W or Terminal A and Terminal W.
2: Any R resistance greater than this limits the current.
BW
3: If V = 36V, then the wiper code value must be greater than or equal to Min ‘N’. Wiper codes less than
BW
Min ‘N’ will cause the wiper current (I ) to exceed the specification. Wiper codes greater than Min ‘N’ will
W
cause the wiper current to be less than the maximum. The Min ‘N’ number has been rounded up from the
calculated number to ensure that the wiper current does not exceed the maximum specification.

## Page 43

MCP45HVX1
Figure 5-3 through Figure 5-6 show a graph of the cal-
culated currents (minimum, typical, and maximum) for
each resistor option. These graphs are based on
25 mA (5 k), 12.5 mA (10 k), and 6.5 mA (50 k
and 100 k) specifications.
To ensure no damage to the resistor network (including
long-term reliability) the maximum terminal current
must not be exceeded. This means that the application
must assume that the R resistance is the minimum
AB
R value (R , see blue lines in graphs). AB AB(MIN)
Looking at the 50 k device, the maximum terminal
current is 6.5 mA. That means that any wiper code
value greater than 36 ensures that the terminal current
is less than 6.5 mA. This is ~14% of the full-scale value. FIGURE 5-5: Maximum I vs Wiper
BW
If the application could change to the 100 k device,
Code - 50 k .
which has the same maximum terminal current specifi-
cation, any wiper code value greater than 18 ensures
that the terminal current is less than 6.5 mA. This is
~7% of the full-scale value. Supporting higher terminal
current allows a greater wiper code range for a given
V voltage.
BW
RAB = 5k(cid:58)(cid:3)
30.0E-3
25.0E-3
20.0E-3
15.0E-3
10.0E-3
FIGURE 5-6: Maximum I vs Wiper
5.0E-3 BW
Code - 100 k .
000.0E+0
0 32 64 96 128 160 192 224 256 Figure 5-7 shows a graph of the maximum V BW voltage
Wiper Code vs wiper code (for 5 k and 10 k devices). To ensure
that no damage is done to the resistor network, the
FIGURE 5-3: Maximum I vs Wiper
BW R resistance (blue line) should be used to deter-
AB(MIN)
Code - 5 k .
mine V voltages for the circuit. Devices where the
BW
R
AB
resistance is greater than the R
AB(MIN)
resistance
will naturally support a higher voltage limit.
FIGURE 5-4: Maximum I vs Wiper
BW
Code - 10 k .
FIGURE 5-7: Maximum V vs Wiper
BW
Code (5 k and 10 k devices).
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 43
)A(
I
)XAM(WB
RAB(TYP)
RAB(MIN)
RAB(MAX)
RAB = 10k(cid:58)(cid:3)
14.0E-3
12.0E-3
10.0E-3
8.0E-3
6.0E-3
4.0E-3
2.0E-3
000.0E+0
0 32 64 96 128 160 192 224 256
Wiper Code
)A(
I
)XAM(WB
RR
AABB
== 5500kk(cid:58)(cid:58)
777...000EEE---333
66..00EE--33
R
55.00EE-33 AB(MIN)
4.0E-3
RAB(TYP)
RAB(MIN)
RAB(MAX)
)A(
)XA
R
AB
= 50k(cid:58)
7.0E-3
6.0E-3
R
5.0E-3 AB(MIN)
R AB(TYP)
4.0E-3
3.0E-3
2 0E 3
)A(
I
)XAM(WB
R
AB
= 50k(cid:58)
7.0E-3
6.0E-3
R
5.0E-3 AB(MIN)
R AB(TYP)
4.0E-3
3.0E-3
2.0E-3
1.0E-3
)A(
I
)XAM(WB
R
AB
= 50k(cid:58)
7.0E-3
6.0E-3
R
5.0E-3 AB(MIN)
R AB(TYP)
4.0E-3
3.0E-3
2.0E-3
R 1.0E-3 AB(MAX)
000.0E+0
0 32 64 96 128 160 192 224 256
)A(
I
)XAM(WB
R
AB
= 50k(cid:58)
7.0E-3
6.0E-3
R
5.0E-3 AB(MIN)
R AB(TYP)
4.0E-3
3.0E-3
2.0E-3
R 1.0E-3 AB(MAX)
000.0E+0
0 32 64 96 128 160 192 224 256
Wiper Code
)A(
I
)XAM(WB
R
AB
= 50k(cid:58)
R
AB(MIN)
R AB(TYP)
R AB(MAX)
Wiper Code
RR
AABB
== 110000kk(cid:58)(cid:58)
777...000EEE---333
66..00EE--33
R
55.00EE-33 AB(MIN)
4.0E-3
)A(
)XA
R
AB
= 100k(cid:58)
7.0E-3
6.0E-3
R
5.0E-3 AB(MIN)
R
AB(TYP)
4.0E-3
3.0E-3
2 0E 3
)A(
I
)XAM(WB
R
AB
= 100k(cid:58)
7.0E-3
6.0E-3
R
5.0E-3 AB(MIN)
R
AB(TYP)
4.0E-3
3.0E-3
2.0E-3
1.0E-3
)A(
I
)XAM(WB
R
AB
= 100k(cid:58)
7.0E-3
6.0E-3
R
5.0E-3 AB(MIN)
R
AB(TYP)
4.0E-3
3.0E-3
2.0E-3
1.0E-3
R AB(MAX)
000.0E+0
0 32 64 96 128 160 192 224 256
)A(
I
)XAM(WB
R
AB
= 100k(cid:58)
7.0E-3
6.0E-3
R
5.0E-3 AB(MIN)
R
AB(TYP)
4.0E-3
3.0E-3
2.0E-3
1.0E-3
R AB(MAX)
000.0E+0
0 32 64 96 128 160 192 224 256
Wiper Code
)A(
I
)XAM(WB
R
AB
= 100k(cid:58)
R
AB(MIN)
R
AB(TYP)
R AB(MAX)
Wiper Code
40.0
35.0
30.0
25.0
20.0
15.0
10.0
5.0
0.0
0 32 64 96 128 160 192 224 256
Wiper Code
)V(
V
)XAM(WB
RAB(MAX)
RAB(TYP)
RAB(MIN)

## Page 44

MCP45HVX1
Table 5-4 shows the maximum V voltage that can be
BW
applied across the Terminal B to Terminal W pins for a
given wiper code value (for the 5 k and 10 k
devices). These calculations assume the ideal model
(R = R = R = 0) and show the calculations
W FS ZS
based on R and R . Table 5-5 shows the
S(MIN) S(MAX)
same calculations for the 50 k devices, and Table 5-6
shows the calculations for the 100 k devices. These
tables are supplied as a quick reference.
TABLE 5-4: MAX V AT EACH WIPER CODE (R = R = R = 0Ω) FOR V+ - V- = 36V,
BW W FS ZS
5 KΩ AND 10 KΩ DEVICES
Code V Code V Code V
BW(MAX) BW(MAX) BW(MAX)
Hex Dec R R Hex Dec R R Hex Dec R R
S(MIN) S(MAX) S(MIN) S(MAX) S(MIN) S(MAX)
00h 0 0.000 0.000 20h 32 12.549 18.824 40h 64 25.098
01h 1 0.392 0.588 21h 33 12.941 19.412 41h 65 25.490
02h 2 0.784 1.176 22h 34 13.333 20.000 42h 66 25.882
03h 3 1.176 1.765 23h 35 13.725 20.588 43h 67 25.275
04h 4 1.569 2.353 24h 36 14.118 21.176 44h 68 26.667
05h 5 1.961 2.941 25h 37 14.510 21.765 45h 69 27.059
06h 6 2.353 3.529 26h 38 14.902 22.353 46h 70 27.451
07h 7 2.745 4.118 27h 39 15.294 22.941 47h 71 27.843
08h 8 3.137 4.706 28h 40 15.686 23.529 48h 72 28.235
09h 9 3.529 5.294 29h 41 16.078 24.118 49h 73 28.627
0Ah 10 3.922 5.882 2Ah 42 16.471 24.706 4Ah 74 29.020
0Bh 11 4.314 6.471 2Bh 43 16.863 25.294 4Bh 75 29.412
0Ch 12 4.706 7.059 2Ch 44 17.255 25.882 4Ch 76 29.804
0Dh 13 5.098 7.647 2Dh 45 17.647 26.471 4Dh 77 30.196
0Eh 14 5.490 8.235 2Eh 46 18.039 27.059 4Eh 78 30.588
0Fh 15 5.882 8.824 2Fh 47 18.431 27.647 4Fh 79 30.980
10h 16 5.275 9.412 30h 48 18.824 28.235 50h 80 31.373
11h 17 6.667 10.000 31h 49 19.216 28.824 51h 81 31.765
12h 18 7.059 10.588 32h 50 19.608 29.412 52h 82 32.157
13h 19 7.451 11.176 33h 51 20.000 30.000 53h 83 32.549
14h 20 7.843 11.765 34h 52 20.392 30.588 54h 84 32.941
15h 21 8.235 12.353 35h 53 20.784 31.176 55h 85 33.333
16h 22 8.627 12.941 36h 54 21.176 31.765 56h 86 33.725
17h 23 9.020 13.529 37h 55 21.569 32.353 57h 87 34.118
18h 24 9.412 14.118 38h 56 21.961 32.941 58h 88 34.510
19h 25 9.804 14.706 39h 57 22.353 33.529 59h 89 34.902
1Ah 26 10.196 15.294 3Ah 58 22.745 34.118 5Ah 90 35.294
1Bh 27 10.588 15.882 3Bh 59 23.137 34.706 5Bh 91 35.686
1Ch 28 10.980 16.471 3Ch 60 23.529 35.294 5Ch 92 - 255 36.0 (1, 2)
1Dh 29 11.373 17.059 3Dh 61 23.922 35.882
1Eh 30 11.765 17.647 3Eh 62 24.314 36.0 (1, 2)
1Fh 31 12.157 18.235 3Fh 63 24.706
Note 1: Calculated R voltage is greater than 36V (highlighted in color), must be limited to 36V (V+ - V-).
BW
2: This wiper code and greater will limit the I current to less than the maximum supported terminal
BW
current (I ).
T
DS20005304B-page 44  2014-2023 Microchip Technology Inc. and its subsidiaries

## Page 45

MCP45HVX1
TABLE 5-5: MAX V AT EACH WIPER CODE (R = R = R = 0Ω) FOR V+ - V- = 36V,
BW W FS ZS
50 KΩ DEVICES
Code V Code V Code V
BW(MAX) BW(MAX) BW(MAX)
R
Hex Dec R R Hex Dec R R Hex Dec R S(MA
S(MIN) S(MAX) S(MIN) S(MAX) S(MIN)
X)
00h 0 0.000 0.000 10h 16 16.314 24,471 20h 32 32.627
01h 1 1.020 1.529 11h 17 17.333 26.000 21h 33 33.647
02h 2 2.039 3.059 12h 18 18.353 27.529 22h 34 34.667
03h 3 3.059 4.588 13h 19 19.373 29.059 23h 35 35.686
04h 4 4.078 6.118 14h 20 20.392 30.588 24h - FFh 36 - 255 36.0 (1, 2)
05h 5 5.098 7.647 15h 21 21.412 32.118
06h 6 6.118 9.176 16h 22 22.431 33.647
07h 7 7.137 10.706 17h 23 23.451 35.176
08h 8 8.157 12.235 18h 24 24.471 36.0 (1, 2)
09h 9 9.176 13.765 19h 25 25.490
0Ah 10 10.196 15.294 1Ah 26 26.510
0Bh 11 11.216 16.824 1Bh 27 27.529
0Ch 12 12.235 18.353 1Ch 28 28.549
0Dh 13 13.255 19.882 1Dh 29 29.569
0Eh 14 14.275 21.412 1Eh 30 30.588
0Fh 15 15.294 22.941 1Fh 31 31.608
Note 1: Calculated R voltage is greater than 36V (highlighted in color), must be limited to 36V (V+ - V-).
BW
2: This wiper code and greater will limit the I current to less than the maximum supported terminal current (I ).
BW T
TABLE 5-6: MAX V AT EACH WIPER CODE (R = R = R = 0Ω) FOR V+ - V- = 36V,
BW W FS ZS
100 KΩ DEVICES
Code V Code V
BW(MAX) BW(MAX)
Hex Dec R R Hex Dec R R
S(MIN) S(MAX) S(MIN) S(MAX)
00h 0 0.000 0.000 10h 16 32.627
01h 1 2.039 3.059 11h 17 34.667
02h 2 4.078 6.118 12h - FFh 18 - 255 36.0 (1, 2)
03h 3 6.118 9.176
04h 4 8.157 12.235
05h 5 10.196 15.294
06h 6 12.235 18.353
07h 7 14.275 21.412
08h 8 16.314 24.471
09h 9 18.353 27.529
0Ah 10 20.392 30.588
0Bh 11 22.431 33.647
0Ch 12 24.471 36.0 (1, 2)
0Dh 13 26.510
0Eh 14 28.549
0Fh 15 30.588
Note 1: Calculated R voltage is greater than 36V (highlighted in color), must be limited to 36V (V+ - V-).
BW
2: This wiper code and greater will limit the I current to less than the maximum supported terminal current (I ).
BW T
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 45

## Page 46

MCP45HVX1
5.4 Variable Resistor (Rheostat) 5.5 Analog Circuitry Power
Requirements
A variable resistor is created using Terminal W and
either Terminal A or Terminal B. Since the wiper code This device has two power supplies. One is for the
value of 0 connects the wiper to the Terminal B, the digital interface (VL and DGND) and the other is for the
R BW resistance increases with increasing wiper code high-voltage analog circuitry (V+ and V-). The
value. Conversely, the R AW resistance will decrease maximum delta voltage between V+ and V- is 36V. The
with increasing wiper code value. Figure 5-8 shows the digital power signals must be between V+ and V-.
connections from a potentiometer to create a rheostat
If the digital ground (DGND) pin is at half the potential
configuration.
of V+ (relative to V-), then the terminal pins potentials
can be ±(V+/2) relative to DGND.
Figure 5-9 shows the relationship of the four power sig-
nals. This shows that the V+/V- signals do not need to
A R
AW be symmetric around the DGND signal.
To ensure that the Wiper register has been properly
W R AW or R BW loaded with the POR/BOR value, the V voltage must
L
be at the minimum specified operating voltage (refer-
B R BW
enced to DGND).
Resistor
FIGURE 5-8: Rheostat Configuration.
Equation 5-4 shows the R and R calculations.
BW AW
The R calculation is for the resistance between the
BW
wiper and Terminal B. The R calculation is for the
AW
resistance between the wiper and Terminal A.
DGND
EQUATION 5-4: R AND R
BW AW
CALCULATION
Simplified Model (assumes R = R = 0Ω)
FS ZS
R = ( n * R )
BW S
R = ( ( FSV - n ) * R )
AW S FIGURE 5-9: Analog Circuitry Voltage
Ranges.
Where: 8-bit 7-bit
R
R S = R eso A lu B tion R S = R AB R S = R AB 5.6 Resistor Characteristics
255 127
n = wiper code
5.6.1 V+/V- LOW VOLTAGE OPERATION
FSV = The full-scale value
(255 for 8-bit or 127 for 7-bit) The resistor network is specified from 20V to 36V. At
voltages below 20V, the resistor network will function,
Detailed Model
but the operational characteristics may be outside the
R = R + ( n * R )
BW ZS S specified limits. Please refer to Section 2.0 “Typical
R AW = R FS + ( ( FSV - n ) * R S ) Performance Curves” for additional information.
Where:
5.6.2 RESISTOR TEMPCO
n = wiper code
FSV = The full-scale value Biasing the ends (Terminal A and Terminal B) near mid-
(255 for 8-bit or 127 for 7-bit) supply ((V+ - |V-|) / 2) will give the worst switch
resistance temperature coefficient (tempco).
DS20005304B-page 46  2014-2023 Microchip Technology Inc. and its subsidiaries
DNGD
ot
evitaleR
segatloV
V+
 V+ – V- Voltage
V +36V max L
+10V min
V-
This can be anywhere
between V- and V+.

## Page 47

MCP45HVX1
5.7 Shutdown Control
Shutdown is used to minimize the device’s current
consumption. The MCP45HVX1 has two methods to
achieve this:
• Hardware Shutdown Pin (SHDN)
• Terminal Control Register (TCON)
The Hardware Shutdown pin is backwards compatible
with the MCP42X1 devices.
5.7.1 HARDWARE SHUTDOWN PIN
(SHDN)
The SHDN pin is available on the potentiometer The R0HW bit does NOT corrupt the values in the
devices. When the SHDN pin is forced active (V IL ): volatile wiper registers nor the TCON register. When
• The P0A terminal is disconnected the Shutdown mode is exited (R0HW bit = 1):
• The P0W terminal is connected to the P0B • The device returns to the wiper setting specified
terminal (see Figure 4-5) by the volatile wiper value
• The Serial Interface is NOT disabled, and all • The TCON register bits return to controlling the
Serial Interface activity is executed terminal connection state
The Hardware Shutdown Pin mode does NOT corrupt
the values in the volatile wiper registers nor the TCON
register. When the Shutdown mode is exited (SHDN
pin is inactive (V )):
IH
• The device returns to the wiper setting specified
by the volatile wiper value
• The TCON register bits return to controlling the
terminal connection state
A FIGURE 5-11: Resistor Network Shutdown
State (R0HW = 0).
W 5.7.3 INTERACTION OF SHDN PIN AND
TCON REGISTER
Figure 5-12 shows how the SHDN pin signal and the
R0HW bit signal interact to control the hardware
B shutdown of the resistor network.
FIGURE 5-10: Hardware Shutdown
Resistor Network Configuration.
5.7.2 TERMINAL CONTROL REGISTER
(TCON)
The Terminal Control (TCON) register is a volatile
FIGURE 5-12: R0HW bit and SHDN pin
register used to configure the connection of each
Interaction.
resistor network terminal pin (A, B and W) to the
Resistor Network. This register is shown in Register 4-1.
The R0HW bit forces the selected resistor network into
the same state as the SHDN pin. Alternate low-power
configurations may be achieved with the R0A, R0W
and R0B bits.
When the R0HW bit is “0”:
• The P0A terminal is disconnected
• The P0W terminal is simultaneously connected to
the P0B terminal (see Figure 5-11)
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 47
krowteN
rotsiseR
Note: When the R0HW bit forces the resistor
network into the hardware SHDN state,
the state of the TCON0 register’s R0A,
R0W and R0B bits is overridden (ignored).
When the state of the R0HW bit no longer
forces the resistor network into the
hardware SHDN state, the TCON0
register’s R0A, R0W and R0B bits return
to controlling the terminal connection
state. In other words, the R0HW bit does
not corrupt the state of the R0A, R0W and
R0B bits.
A
W
B
krowteN
rotsiseR
SHDN (from pin)
To Pot 0 Hardware
Shutdown Control
R0HW
(from TCON register)

## Page 48

MCP45HVX1
6.0 SERIAL INTERFACE (I2C) 6.1 Signal Descriptions
The MCP45HVX1 devices support the I2C serial The I2C interface uses up to four pins (signals). These
protocol. The MCP45HVX1 I2C module operates in are:
Client mode (does not generate the serial clock).
• SDA (Serial Data)
Figure 6-1 shows a typical I2C interface connection.
• SCL (Serial Clock)
The MCP45HVX1 devices use the two-wire I2C serial • A0 (Address 0 bit)
interface. This interface can operate in Standard, Fast • A1 (Address 1 bit)
or High-Speed mode. A device that sends data onto the
6.1.1 SERIAL DATA (SDA)
bus is defined as transmitter, and a device receiving
data as receiver. The bus has to be controlled by a host The Serial Data (SDA) signal is the data signal of the
device which generates the serial clock (SCL), controls device. The value on this pin is latched on the rising
the bus access and generates the Start and Stop edge of the SCL signal when the signal is an input.
conditions. The MCP45HVX1 device works as client.
With the exception of the Start and Stop conditions, the
Both host and client can operate as transmitter or
High or Low state of the SDA pin can only change when
receiver, but the host device determines which mode is
the clock signal on the SCL pin is Low. During the High
activated. Communication is initiated by the host
period of the clock, the SDA pin’s value (High or Low)
(microcontroller) which sends the Start bit, followed by
must be stable. Changes in the SDA pin’s value while
the client address byte. The first byte transmitted is
the SCL pin is High will be interpreted as a Start or a
always the client address byte, which contains the
Stop condition.
device code, the address bits, and the R/W bit.
Refer to the NXP I2C document for more details of the 6.1.2 SERIAL CLOCK (SCL)
I2C specifications (UM10204, Ver. 05 Oct 2012).
The Serial Clock (SCL) signal is the clock signal of the
device. The rising edge of the SCL signal latches the
Typical I2C Interface Connections value on the SDA pin. The MCP45HVX1 supports three
I2C interface clock modes:
Host MCP4XXX
Controller • Standard mode: clock rates up to 100 kHz
SCL SCL • Fast mode: clock rates up to 400 kHz
• High-Speed mode (HS mode): clock rates up to
SDA SDA 3.4 MHz
I/O (1) A0 (1) The MCP45HVX1 will not stretch the clock signal (SCL)
since memory read access occurs fast enough.
I/O (1) A1 (1)
Depending on the clock rate mode, the interface will
display different characteristics.
Note 1: This pin could be tied High, Low, or
connected to an I/O pin of the Host 6.1.3 THE ADDRESS BITS (A1:A0)
Controller.
There are up to two hardware pins used to specify the
FIGURE 6-1: Typical I2C Interface Block device address. The number of address pins is
determined by the part number.
Diagram.
The state of the A0 and A1 pins should be static, that is
they should be tied High or tied Low.
DS20005304B-page 48  2014-2023 Microchip Technology Inc. and its subsidiaries

## Page 49

MCP45HVX1
6.2 I2C Operation 6.2.1.3 Acknowledge (A) Bit
The MCP45HVX1 I2C module is compatible with the The A bit (see Figure 6-4) is typically a response from
NXP I2C specification. The following lists some of the the receiving device to the transmitting device.
module’s features: Depending on the context of the transfer sequence, the
A bit may indicate different things. Typically, the client
• 7-bit client addressing
device will supply an A response after the Start bit and
• Supports three clock rate modes:
8 “data” bits have been received. an A bit has the SDA
- Standard mode, clock rates up to 100 kHz
signal Low.
- Fast mode, clock rates up to 400 kHz
- High-Speed mode (HS mode), clock rates up
to 3.4 MHz SDA D0 A
• Support Multi-Host Applications
• General call addressing SCL 8 9
The I2C 10-bit addressing mode is not supported.
The NXP I2C specification only defines the field types, FIGURE 6-4: Acknowledge Waveform.
field lengths, timings, etc. of a frame. The frame
content defines the behavior of the device. The frame
Not A (A) Response
content for the MCP45HVX1 is defined in Section 7.0,
Device Commands. The A bit has the SDA signal High. Table 6-1 shows
some of the conditions where the client device will
6.2.1 I2C BIT STATES AND SEQUENCE
issue a Not A (A).
Figure 6-8 shows the I2C transfer sequence. The serial If an error condition occurs (such as an A instead of A),
clock is generated by the host. The following definitions then a Start bit must be issued to reset the command
are used for the bit states: state machine.
• Start bit (S)
• Data bit TABLE 6-1: MCP45HVX1 A/A RESPONSES
• Acknowledge (A) bit (driven Low)/
Acknowledge
No Acknowledge (A) bit (not driven Low)
Event Bit Comment
• Repeated Start bit (Sr)
Response
• Stop bit (P)
General Call A Only if GCEN bit is
6.2.1.1 Start Bit
set
The Start bit (see Figure 6-2) indicates the beginning of Client Address A
a data transfer sequence. The Start bit is defined as the valid
SDA signal falling when the SCL signal is “High”.
Client Address A
not valid
1st Bit 2nd Bit Device A After device has
SDA
Memory received address
Address and and command
SCL
specified
S
command
FIGURE 6-2: Start Bit. (AD3:AD0 and
C1:C0) are an
6.2.1.2 Data Bit invalid
The SDA signal may change state while the SCL signal combination
is Low. While the SCL signal is High, the SDA signal Bus Collision N.A. I2CTM module
MUST be stable (see Figure 6-3). resets, or a “don’t
care” if the colli-
sion occurs on the
1st Bit 2nd Bit host’s “Start bit”
SDA
SCL
Data Bit
FIGURE 6-3: Data Bit.
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 49

## Page 50

MCP45HVX1
6.2.1.4 Repeated Start Bit 6.2.1.5 Stop Bit
The Repeated Start bit (see Figure 6-5) indicates the The Stop bit (see Figure 6-6) indicates the end of the
current host device will attempt to continue communi- I2C Data Transfer Sequence. The Stop bit is defined as
cating with the current client device without releasing the SDA signal rising when the SCL signal is “High”.
the I2C bus. The Repeated Start condition is the same A Stop bit resets the I2C interface of all MCP45HVX1
as the Start condition, except that the Repeated Start
devices.
bit follows a Start bit (with the Data bits + A bit) and not
a Stop bit.
The Start bit is the beginning of a data transfer SDA A / A
sequence and is defined as the SDA signal falling when
the SCL signal is “High”. SCL
Note 1: A bus collision during the Repeated Start P
condition occurs if:
FIGURE 6-6: Stop Condition Receive or
•SDA is sampled Low when SCL goes Transmit Mode.
from low-to-high.
6.2.2 CLOCK STRETCHING
•SCL goes Low before SDA is
“Clock Stretching” is something that the receiving
asserted Low. This may indicate
device can do, to allow additional time to “respond” to
that another host is attempting to
the “data” that has been received.
transmit a data ‘1’.
The MCP45HVX1 will not stretch the clock signal (SCL)
since memory read access occurs fast enough.
6.2.3 ABORTING A TRANSMISSION
SDA 1st Bit
If any part of the I2C transmission does not meet the
command format, it is aborted. This can be intentionally
accomplished with a Start or Stop condition. This is
SCL done so that noisy transmissions (usually an extra Start
or Stop condition) are aborted before they corrupt the
Sr = Repeated Start device.
FIGURE 6-5: Repeat Start Condition
Waveform.
SDA
SCL
S 1st Bit 2nd Bit 3rd Bit 4th Bit 5th Bit 6th Bit 7th Bit 8th Bit A / A P
FIGURE 6-7: Typical 8-Bit I2C Waveform Format.
SDA
SCL
Start Data allowed Data or Stop
Condition to change A valid Condition
FIGURE 6-8: I2C Data States and Bit Sequence.
DS20005304B-page 50  2014-2023 Microchip Technology Inc. and its subsidiaries

## Page 51

MCP45HVX1
6.2.4 ADDRESSING
Client Address
The address byte is the first byte received following the
Start condition from the host device. The address con- S A6 A5 A4 A3 A2 A1 A0 R/W A/A
tains four (or more) fixed bits and (up to) three user- “0” “1” “1” “1” “1”
defined hardware address bits (pins A1 and A0). These See Table 6-2
7-bits address the desired I2C device. The A6:A2 Start R/W bit
address bits are fixed to ‘01111’ and the device bit R/W = 0 = write
appends the value of following two address pins (A1
R/W = 1 = read
and A0).
A bit (controlled by client device)
Since there are address bits controlled by hardware
A = 0 = Client device Acknowledges byte
pins, there may be up to four MCP45HVX1 devices on
A = 1 = Client device does not Acknowledge byte
the same I2C bus.
FIGURE 6-9: Client Address Bits in the
Figure 6-9 shows the client address byte format, which
I2C Control Byte.
contains the seven address bits. There is also a read/
write (R/W) bit. Table 6-2 shows the fixed address for TABLE 6-2: DEVICE CLIENT ADDRESSES
device.
Device Address Comment
MCP45HVX1 ‘0111 1’b + A1:A0 Supports up to
Hardware Address Pins
4 devices.
The hardware address bits (A1, and A0) correspond to (Note 1)
the logic level on the associated address pins. This Note 1: The fixed portion of the I2C address is
allows up to four devices on the bus. different than the MCP44XX/MCP45XX/
MCP46XX family (‘0101 11’, ‘0101 1’,
or ‘0101’). This allows the maximum
number of both standard and high-voltage
devices on the single I2C bus.
6.2.5 SLOPE CONTROL
The MCP45HVX1 implements slope control on the
SDA output.
As the device transitions from HS mode to FS mode,
the slope control parameter will change from the HS
specification to the FS specification.
For Fast (FS) and High-Speed (HS) modes, the device
has a spike suppression and a Schmitt trigger at SDA
and SCL inputs.
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 51

## Page 52

MCP45HVX1
6.2.6 HS MODE After switching to the High-Speed mode, the next
The I2C specification requires that a High-Speed mode transferred byte is the I2C control byte, which specifies
the device to communicate with, and any number of
device must be ‘activated’ to operate in High-Speed
data bytes plus acknowledgments. The host device can
(3.4 Mbit/s) mode. This is done by the host sending a
then issue either a Repeated Start bit to address a dif-
special address byte following the Start bit. This byte is
ferent device (at high speed) or a Stop bit to return to
referred to as the High-Speed Host Mode Code
Fast/Standard bus speed. After the Stop bit, any other
(HSMMC).
host device (in a multi-host system) can arbitrate for the
The MCP45HVX1 device does not acknowledge this I2C bus.
byte. However, upon receiving this command, the
See Figure 6-10 for illustration of HS mode command
device switches to HS mode. The device can now
sequence.
communicate at up to 3.4 Mbit/s on SDA and SCL
lines. The device will switch out of the HS mode on the For more information on the HS mode, or other I2C
next Stop condition. modes, please refer to the Phillips I2C specification.
The host code is sent as follows:
6.2.6.1 Slope Control
1. Start condition (S)
The slope control on the SDA output is different
2. High-Speed Host Mode Code (0000 1XXX), between the Fast/Standard Speed and the High-Speed
The XXX bits are unique to the High-Speed (HS) Clock modes of the interface.
mode host.
3. No Acknowledge (A) 6.2.6.2 Pulse Gobbler
The pulse gobbler on the SCL pin is automatically
adjusted to suppress spikes < 10 ns during HS mode.
F/S mode HS mode
P
F/S mode
S ‘0 0 0 0 1 X X X’b A Sr ‘Client Address’ R/W A “Data” A/A
HS mode continues
Sr ‘Client Address’ R/W A
HS Select Byte Control Byte Command/Data Byte(s)
S = Start bit Control Byte
Sr = Repeated Start bit
A = Acknowledge bit
A = Not Acknowledge bit
R/W = Read/Write bit
P = Stop bit (Stop condition terminates HS mode)
FIGURE 6-10: HS Mode Sequence.
DS20005304B-page 52  2014-2023 Microchip Technology Inc. and its subsidiaries

## Page 53

MCP45HVX1
6.2.7 GENERAL CALL TABLE 6-3: GENERAL CALL COMMANDS
The General Call is a method that the “host” device can 7-bit
communicate with all other “client” devices. In a multi- Command Comment
host application, the other host devices are operating in (1, 2, 3)
Client mode. The General Call address has two docu-
mented formats. These are shown in Figure 6-11. We
‘1000 Write next byte (third byte) to volatile
have added an MCP45HVX1 format in this figure as
000’b Wiper 0 register
or
well.
‘1000
This will allow customers to have multiple I2C digital
001’b
potentiometers on the bus and have them operate in a
synchronous fashion (analogous to the DAC Sync pin ‘1100 Write Next Byte (Third Byte) to TCON
functionality). If these MCP45HVX1 7-bit commands 000’b Register
conflict with other I2C devices on the bus, then the or
customer will need two I2C buses and ensure that the ‘1100
devices are on the correct bus for their desired
001’b
application functionality. ‘1000 Increment Wiper 0 Register
Dual Pot devices can not update both Pot0 and Pot1
010’b
or
from a single command. To address this, there are
General Call commands for the Wiper 0, Wiper 1, and
‘1000
the TCON registers.
011’b
Table 6-3 shows the General Call commands. Three
‘1000 Decrement Wiper 0 Register
commands are specified by the I2C specification and 100’b
are not applicable to the MCP45HVX1 (so command is or
Not Acknowledged) The MCP45HVX1 General Call ‘1000
commands are Acknowledged. Any other command is 101’b
Not Acknowledged. Note 1: Any other code is Not Acknowledged.
These codes may be used by other
Note: Only one General Call command per issue devices on the I2C bus.
of the General Call control byte. Any 2: The 7-bit command always appends a “0”
additional General Call commands are to form 8-bits.
ignored and Not Acknowledged.
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 53

## Page 54

MCP45HVX1
Second Byte
S 0 0 0 0 0 0 0 0 A X X X X X X X 0 A P
General Call Address “7-bit Command”
Reserved 7-bit Commands (By I2C Specification - NXP UM10204, Ver. 05 October 2012)
‘0000 011’b – Reset and write programmable part of client address by hardware.
‘0000 010’b – Write programmable part of client address by hardware.
‘0000 000’b – NOT Allowed
MCP45HVX1 7-bit Commands
‘1000 01x’b – Increment Wiper 0 Register.
‘1000 10x’b – Decrement Wiper 0 Register.
The Following is a Microchip Extension to this General Call Format
Second Byte Third Byte
S 0 0 0 0 0 0 0 0 A X X X X X X X 0 A d d d d d d d d A P
General Call Address “7-bit Command” “0” for General Call Command
MCP45HVX1 7-bit Commands
‘1000 00x’b – Write Next Byte (Third Byte) to Volatile Wiper 0 Register.
‘1100 00x’b – Write Next Byte (Third Byte) to TCON Register.
The Following is a “Hardware General Call” Format
Second Byte n occurrences of (Data + A)
S 0 0 0 0 0 0 0 0 A X X X X X X 1 A X X X X X X X X A P
General Call Address “7-bit Command”
This indicates a “Hardware General Call”
MCP45HVX1 will ignore this byte and
all following bytes (and A), until
a Stop bit (P) is encountered.
FIGURE 6-11: General Call Formats.
DS20005304B-page 54  2014-2023 Microchip Technology Inc. and its subsidiaries

## Page 55

MCP45HVX1
NOTES:
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 55

## Page 56

MCP45HVX1
7.0 DEVICE COMMANDS 7.1 Command Byte
The MCP45HVX1’s I2C command formats are The MCP45HVX1 command byte has three fields: the
specified in this section. The I2C protocol does not address, the command operation, and two data bits
specify how commands are formatted. (see Figure 7-1). Currently only one of the data bits is
defined (D8).
The MCP45HVX1 supports four basic commands. The
location accessed determines the commands that are The device memory is accessed when the host sends
supported. a proper command byte to select the desired operation.
The memory location getting accessed is contained in
For the volatile wiper registers, these commands are:
the command byte’s AD3:AD0 bits. The action desired
• Write Data is contained in the command byte’s C1:C0 bits, see
• Read Data Figure 7-1. C1:C0 determines if the desired memory
• Increment Data location will be read, written, incremented (wiper set-
• Decrement Data ting +1) or decremented (wiper setting -1). The Incre-
These commands have formats for both a single ment and Decrement commands are only valid on the
command or continuous commands. These commands volatile Wiper register.
are shown in Table 7-1. If the address bits and command bits are not a valid
combination, then the MCP45HVX1 will generate a Not
TABLE 7-1: I2C COMMANDS Acknowledge pulse to indicate the invalid combination.
The I2C host device must then force a Start condition to
Command
# of Bit Clocks reset the MCP45HVX1 I2C module.
(1, 2)
Operation Mode
D9 and D8 are unused data bits. These bits maintain
Write Data Single 29 code compatibility with the MCP44XX, MCP45XX, and
MCP46XX devices.
Continuous 18n + 11
Read Data Single 29
COMMAND BYTE
Random 48
Continuous 18n + 11 A A A A A C C D D A
Increment Single 20 D D D D 1 0 9 8
3 2 1 0
Continuous 9n + 11
Decrement Single 20 MCP45HVXXX MSbits (Data)
Continuous 9n + 11 Memory Address
Note 1: “n” indicates the number of times the Command Operation bits
command operation is to be repeated. 00 = Write Data
01 = Increment
2: These clock counts are for “standard” and
“fast” I2C communication. 10 = Decrement
11 = Read Data
Table 7-2 shows the supported commands for each
FIGURE 7-1: Command Byte Format.
memory location.
Table 7-3 shows an overview of all the device
commands and their interaction with other device
features.
DS20005304B-page 56  2014-2023 Microchip Technology Inc. and its subsidiaries

## Page 57

MCP45HVX1
TABLE 7-2: MEMORY MAP AND THE SUPPORTED COMMANDS
Address Data
Command Comment
Value Function (10-bits) (1)
00h Volatile Wiper 0 Write Data nn nnnn nnnn
Read Data (3) nn nnnn nnnn
Increment Wiper —
Decrement Wiper —
01h-03h Reserved — —
04h (2) Volatile Write Data nn nnnn nnnn
TCON 0 Register Read Data (3) nn nnnn nnnn
05h-FFh Reserved — —
Note 1: The data memory is 8-bits wide, so the two MSbs are ignored by the device. This is for compatibility with
the MCP44XX, MCP45XX, and MCP46XX command formats.
2: Increment or Decrement commands are invalid for these addresses.
3: I2C read operation will read two bytes, of which the 8 bits of data are contained within the Least Significant
Byte (LSB). This is for compatibility with the MCP44XX, MCP45XX, and MCP46XX command formats.
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 57

## Page 58

MCP45HVX1
7.2 Data Byte 7.3 Error Condition
Only the Read command and the Write command have If the four address bits received (AD3:AD0) and the two
data byte(s). Even though only one byte of data is command bits received (C1:C0) are a valid
required for the commands, the supported commands combination, the MCP45HVX1 will Acknowledge the
will be formatted for compatibility with the MCP44XX, I2C bus.
MCP45XX, and MCP46XX command formats with sup-
If the address bits and command bits are an invalid
port of 10 bits of data.
combination, then the MCP45HVX1 will Not
Acknowledge the I2C bus.
Once an error condition has occurred, any following
commands are ignored until the I2C bus is reset with a
Start condition.
7.3.1 ABORTING A TRANSMISSION
A Restart or Stop condition in the expected data bit
position will abort the current command sequence and
data will not be written to the MCP45HVX1.
TABLE 7-3: COMMANDS
# of Bit Clocks
Continuous
Command Name Single
(1)
Write Data 29 18n + 11
Read Data 29 (2) 18n + 11
Increment Wiper 20 9n + 11
Decrement Wiper 20 9n + 11
Note 1: “n” indicates the number of times the command operation is to be repeated.
2: For a random read (read from any memory location), 40 bit clocks are required.
DS20005304B-page 58  2014-2023 Microchip Technology Inc. and its subsidiaries

## Page 59

MCP45HVX1
7.4 Write Data 7.4.1 SINGLE WRITE TO VOLATILE
MEMORY
The Write command format, see Figure 7-2, includes
the I2C control byte, an A bit, the MCP45HVX1 Data is written to the MCP45HVX1 after every byte
command byte, an A bit, the MCP45HVX1 data byte, transfer (during the Acknowledge). If a Stop or Restart
an A bit, and a Stop (or Restart) condition. The condition is generated during a data transfer (before
MCP45HVX1 generates the A / A bits. the A), the data will not be written to the MCP45HVX1.
After the A bit, the host can initiate the next sequence
A Write command to a volatile memory location
with a Stop or Restart condition.
changes that location after a properly formatted Write
command and the A/A clock have been received. Refer to Figure 7-2 for the byte write sequence.
7.4.2 CONTINUOUS WRITES TO
VOLATILE MEMORY
A Continuous Write mode of operation is possible when
writing to the volatile memory registers (address 00h
and 04h). This Continuous Write mode allows writes
without a Stop or Restart condition or repeated trans-
missions of the I2C Control Byte. Figure 7-3 shows the
sequence for three continuous writes. The writes do not
need to be to the same volatile memory address. The
sequence ends with the host sending a Stop or Restart
condition.
Write bit Device
Fixed Variable Memory
Address Address Address Command Write “Data” bits
AD AD AD AD
S 0 1 1 1 1 A1 A0 0 A 3 2 1 0 0 0 x x A D7 D6 D5 D4 D3 D2 D1 D0 A P
Control Byte Write command Reserved Write Data bits
FIGURE 7-2: I2C Write Sequence.
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 59

## Page 60

MCP45HVX1
Write bit Device
Fixed Variable Memory
Address Address Address Command Write “Data” bits
AD AD AD AD
S 0 1 1 1 1 A1 A0 0 A 3 2 1 0 0 0 x x A D7 D6 D5 D4 D3 D2 D1 D0 A
Control Byte Write command Reserved Write Data bits
AD AD AD AD
3 2 1 0 0 0 x x A D7 D6 D5 D4 D3 D2 D1 D0 A
Write command Reserved Write Data bits
Stop bit
AD AD AD AD
3 2 1 0 0 0 x x A D7 D6 D5 D4 D3 D2 D1 D0 A P
Write command Reserved Write Data bits
Note: Only functions when writing the volatile wiper registers (AD3:AD0 = 00h and 01h) or the TCON reg-
isters (AD3:AD0 = 04h)
FIGURE 7-3: I2C Continuous Volatile Wiper Write.
DS20005304B-page 60  2014-2023 Microchip Technology Inc. and its subsidiaries

## Page 61

MCP45HVX1
7.5 Read Data 7.5.1 SINGLE READ
The Read command format, see Figure 7-4, includes Figure 7-4 shows the waveforms for a single read.
the Start condition, I2C control byte (with R/W bit set to
For single reads the host sends a Stop or Restart
“0”), A bit, MCP45HVX1 command byte, A bit, followed
condition after the data byte is sent from the client.
by a Repeated Start bit, I2C control byte (with R/W bit
set to “1”), and the MCP45HVX1 transmitting the 7.5.1.1 Random Read
requested data high byte, and A bit, the data low byte,
Figure 7-5 shows the sequence for a Random Read.
the host generating the A, and Stop condition.
The I2C control byte requires the R/W bit equal to a 7.5.2 CONTINUOUS READS
logic one (R/W = 1) to generate a read sequence. The
Continuous reads allows the devices’ memory to be
memory location read will be the last address
read quickly. Continuous reads are possible to all
contained in a valid write MCP45HVX1 command byte
memory locations.
or address 00h if no write operations have occurred
since the device was reset (Power-On Reset or Brown- Figure 7-6 shows the sequence for three continuous
Out Reset). reads.
For continuous reads, instead of transmitting a Stop
Note: The MSB (Most Significant Byte) of the 16
or Restart condition after the data transfer, the host
read bits is all 0’s to maintain read com-
reads the next data byte. The sequence ends with the
mand format compatibility with the
host Not Acknowledging and then sending a Stop or
MCP44XX/MCP45XX/MCP46XX families
Restart.
of devices.
7.5.3 IGNORING AN I2C TRANSMISSION
AND “FALLING OFF” THE BUS
The MCP45HVX1 expects to receive complete, valid
I2C commands, and will assume any command not
defined as valid is due to a bus corruption, and will
enter a passive High condition on the SDA signal. All
signals will be ignored until the next valid Start
condition and control byte are received.
Read bit
Stop bit
Fixed Variable
Address Address Read Data bits
S 0 1 1 1 1 A1 A0 1 A 0 0 0 0 0 0 0 0 A1 D7 D6 D5 D4 D3 D2 D1 D0 A2 P
Control Byte Read bits
Note 1: Host device is responsible for A/A signal. If a A signal occurs, the MCP45HVX1 will abort this
transfer and release the bus.
2: The host device will Not Acknowledge, and the MCP45HVX1 will release the bus so the host
device can generate a Stop or Repeated Start condition.
3: The MCP45HVX1 retains the last “Device Memory Address” that it has received. That is, the
MCP45HVX1 does not “corrupt” the “Device Memory Address” after Repeated Start or Stop
conditions.
4: The Device Memory Address pointer defaults to 00h on POR and BOR conditions.
FIGURE 7-4: I2C Read (Last Memory Address Accessed).
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 61

## Page 62

MCP45HVX1
Write bit Repeated Start bit
Device
Fixed Variable Memory
Address Address Address Command
AD AD AD AD
S 0 1 1 1 1 A1 A0 0 A 1 1 x X A Sr
3 2 1 0
Control Byte READ command
Stop bit
Read bit Read Data bits
0 1 1 1 1 A1 A0 1 A 0 0 0 0 0 0 0 0 A1 D7 D6 D5 D4 D3 D2 D1 D0 A2 P
Control Byte Read bits
Note 1: Host device is responsible for A/A signal. If a A signal occurs, the MCP45HVX1 will abort this
transfer and release the bus.
2: The host device will Not Acknowledge, and the MCP45HVX1 will release the bus so the host
device can generate a Stop or Repeated Start condition.
3: The MCP45HVX1 retains the last “Device Memory Address” that it has received. This is, the
MCP45HVX1 does not “corrupt” the “Device Memory Address” after Repeated Start or Stop
conditions.
FIGURE 7-5: I2C Random Read.
Read bit
Fixed Variable
Address Address Read Data bits
S 0 1 1 1 1 A1 A0 1 A 0 0 0 0 0 0 0 0 A1 D7 D6 D5 D4 D3 D2 D1 D0 A1
Control Byte Read bits
Read Data bits
0 0 0 0 0 0 0 0 A1 D7 D6 D5 D4 D3 D2 D1 D0 A1
Stop bit
Read Data bits
0 0 0 0 0 0 0 0 A1 D7 D6 D5 D4 D3 D2 D1 D0 A2 P
Note 1: Host device is responsible for A/A signal. If a A signal occurs, the MCP45HVX1 will abort this
transfer and release the bus.
2: The host device will Not Acknowledge, and the MCP45HVX1 will release the bus so the host
device can generate a Stop or Repeated Start condition.
FIGURE 7-6: I2C Continuous Reads.
DS20005304B-page 62  2014-2023 Microchip Technology Inc. and its subsidiaries

## Page 63

MCP45HVX1
7.6 Increment Wiper
Note: The command sequence can go from an
The Increment command provides a quick and easy increment to any other valid command for
method to modify the potentiometer’s wiper by +1 with the specified address. Issuing an
minimal overhead. The Increment command will only increment or decrement to a reserved
function on the volatile wiper setting memory locations location will cause an error condition (A
00h and 01h. will be generated).
Note: Table 7-4 shows the valid addresses for
The advantage of using an Increment command
the Increment Wiper command. Other
instead of a read-modify-write series of commands is
addresses are invalid.
speed and simplicity. The wiper will transition after each
command acknowledge when accessing the volatile
When executing an Increment command, the volatile wiper registers.
wiper setting will be altered from n to n+1 for each
Increment command received. The value will TABLE 7-4: INCREMENT OPERATION VS.
increment up to 100h max on 8-bit devices and 80h on VOLATILE WIPER VALUE
7-bit devices. If multiple Increment commands are
Current Wiper
received after the value has reached 100h (or 80h), the
Setting Increment
value will not be incremented further. Table 7-4 shows Wiper (W)
Command
the Increment command versus the current volatile Properties
7-bit 8-bit Operates[unreadable glyph]
wiper value.
Pot Pot
The Increment command will most commonly be
7Fh FFh Full Scale (W = A) No
performed on the volatile wiper locations until a desired
07Eh FEh W = N
condition is met. The MCP45HVX1 is responsible for
40h 80
generating the A bits.
3Fh 7Fh W = N (Mid Scale) Yes
Refer to Figure 7-7 for the Increment command
sequence. The sequence is terminated by the Stop 3Eh 7Eh W = N
condition. So when executing a continuous command 01h 01
string, the Increment command can be followed by any 00h 00h Zero Scale (W = B) Yes
other valid command. This means that writes do not
need to be to the same volatile memory address.
Write bit Device
Fixed Variable Memory
Address Address Address Command
AD AD AD AD AD AD AD AD
S 0 1 1 1 1 A1 A0 0 A
3 2 1 0
0 1 x x A
4 3 2 1
0 1 x x A P (2)
Control Byte INCR command (n+1) Reserved INCR command (n+2) Reserved
Note 1: Increment command (INCR) only functions when accessing the volatile wiper registers
(AD3:AD0 = 00h and 01h).
2: This command sequence does not need to terminate (using the Stop bit) and can change to
any other desired command sequence (Increment, Read, or Write).
FIGURE 7-7: I2C Increment Command Sequence.
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 63

## Page 64

MCP45HVX1
7.7 Decrement Wiper The advantage of using a Decrement command
instead of a read-modify-write series of commands is
The Decrement command provides a quick and easy speed and simplicity. The wiper will transition after each
method to modify the potentiometer’s wiper by -1 with command acknowledge when accessing the volatile
minimal overhead. The Decrement command will only wiper registers.
function on the volatile wiper setting memory locations
00h and 01h.
TABLE 7-5: DECREMENT OPERATION VS.
VOLATILE WIPER VALUE
Note: Table 7-5 shows the valid addresses for
the Decrement Wiper command. Other Current Wiper
addresses are invalid. Setting Wiper (W) Decrement
Command
Properties
When executing a Decrement command, the volatile 7-bit 8-bit Operates[unreadable glyph]
wiper setting will be altered from n to n-1 for each Pot Pot
Decrement command received. The value will
7Fh FFh Full Scale (W = A) Yes
decrement down to 000h min. If multiple Decrement
7Eh FEh W = N
commands are received after the value has reached
40h 80
000h, the value will not be decremented further.
Table 7-5 shows the Decrement command versus the 3Fh 7Fh W = N (Mid Scale) Yes
current volatile wiper value. 3Eh 7Eh W = N
The Decrement command will most commonly be 01h 01
performed on the volatile wiper locations until a desired 00h 00h Zero Scale (W = B) No
condition is met.
Refer to Figure 7-8 for the Decrement command
sequence. The sequence is terminated by the Stop
condition. So when executing a continuous command
string, the Decrement command can be followed by
any other valid command. This means that writes do
not need to be to the same volatile memory address.
Note: The command sequence can go from a
decrement to any other valid command for
the specified address.
Write bit Device
Fixed Variable Memory
Address Address Address Command
AD AD AD AD AD AD AD AD
S 0 1 1 1 1 A1 A0 0 A 1 0 x x A 1 0 x x A P (2)
3 2 1 0 4 3 2 1
Control Byte DECR command (n-1) Reserved DECR command (n-2) Reserved
Note 1: Decrement command (DECR) only functions when accessing the volatile wiper registers
(AD3:AD0 = 00h and 01h).
2: This command sequence does not need to terminate (using the Stop bit) and can change to
any other desired command sequence (DECR, Read, or Write).
FIGURE 7-8: I2C Decrement Command Sequence.
DS20005304B-page 64  2014-2023 Microchip Technology Inc. and its subsidiaries

## Page 65

MCP45HVX1
NOTES:
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 65

## Page 66

MCP45HVX1
8.0 APPLICATIONS EXAMPLES 8.2 Software Reset Sequence
Digital potentiometers have a multitude of practical Note: This technique is documented in AN1028.
uses in modern electronic circuits. The most popular
At times, it may become necessary to perform a
uses include precision calibration of set point
Software Reset Sequence to ensure the MCP45HVX1
thresholds, sensor trimming, LCD bias trimming, audio
device is in a correct and known I2C Interface state.
attenuation, adjustable power supplies, motor control
This technique only resets the I2C state machine.
overcurrent trip setting, adjustable gain amplifiers and
offset trimming. This is useful if the MCP45HVX1 device powers-up in
an incorrect state (due to excessive bus noise, etc), or
8.1 Using Shutdown Modes if the host device is reset during communication.
Figure 8-2 shows the communication sequence to
Figure 8-1 shows a possible application circuit where software reset the device.
the independent terminals could be used.
Disconnecting the wiper allows the transistor input to
S ‘1’ ‘1’ ‘1’ ‘1’ ‘1’ ‘1’ ‘1’ ‘1’ S P
be taken to the bias voltage level (disconnecting A and
or B may be desired to reduce system current).
Disconnecting Terminal A modifies the transistor input
Nine bits of ‘1’
by the R rheostat value to the Common B.
BW
Disconnecting Terminal B modifies the transistor input Start bit
Start
by the R AW rheostat value to the Common A. The bit Stop bit
Common A and Common B connections could be
connected to V+ and V-. FIGURE 8-2: Software Reset Sequence
Format.
The first Start bit will cause the device to reset from a
state in which it is expecting to receive data from the
Common A
host device. In this mode, the device is monitoring the
data bus in Receive mode and can detect the Start bit
forces an internal Reset.
Input The nine bits of ‘1’ are used to force a Reset of those
A devices that could not be reset by the previous Start bit.
This occurs only if the MCP45HVX1 is driving an A bit
on the I2C bus, or is in Output mode (from a Read
command) and is driving a data bit of ‘0’ onto the I2C
bus. In both of these cases, the previous Start bit could
To base not be generated due to the MCP45HVX1 holding the
W
of Transistor bus Low. By sending out nine ‘1’ bits, it is ensured that
(or Amplifier) the device will see an A bit (the host device does not
drive the I2C bus Low to acknowledge the data sent by
the MCP45HVX1), which also forces the MCP45HVX1
to reset.
The second Start bit is sent to address the rare possi-
B bility of an erroneous write. This could occur if the host
Input device was reset while sending a Write command to the
MCP45HVX1, and then as the host device returns to
normal operation and issues a Start condition while the
MCP45HVX1 is issuing an Acknowledge. In this case,
Common B
if the 2nd Start bit is not sent (and the Stop bit was sent)
the MCP45HVX1 could initiate a write cycle.
Balance Bias
M
FIGURE 8-1: Example Application Circuit Note: The potential for this erroneous write only
using Terminal Disconnects. occurs if the host device is reset while
sending a Write command to the
MCP45HVX1.
The Stop bit terminates the current I2C bus activity. The
MCP45HVX1 waits to detect the next Start condition.
This sequence does not effect any other I2C devices
which may be on the bus, as they should disregard this
as an invalid command.
DS20005304B-page 66  2014-2023 Microchip Technology Inc. and its subsidiaries

## Page 67

MCP45HVX1
8.3 High-Voltage DAC 8.4 Variable Gain Instrumentation
Amplifier
A high-voltage DAC can be implemented using the
MCP45HVX1, with voltages as high as 36V. The circuit A variable gain instrumentation amplifier can be
is shown in Figure 8-3. The equation to calculate the implemented using the MCP45HVX1 along with a high-
voltage output is shown in Equation 8-1. voltage dual analog switch and a high-voltage
instrumentation amplifier.
V+
Figure 8-3. The equation to calculate the voltage output
High-Voltage DAC is shown in Equation 8-2.
V+
V D MCP45HVX1
+
D 1 OPA170 A V+
-
B
W AD8221 V
OUT
A R B
R 1
2
V+ FIGURE 8-4: Variable Gain
+
Instrumentation Amplifier for Data Acquisition
OPA170
System.
V
- OUT
EQUATION 8-2: DAC OUTPUT VOLTAGE
CALCULATION
FIGURE 8-3: High-Voltage DAC.
EQUATION 8-1: DAC OUTPUT VOLTAGE
CALCULATION
8-bit
N R1
V (N) = x ( V x ( 1 + ) ) OUT 255 D R2
N = 0 to 255 (decimal)
7-bit
N R1
V (N) = x ( V x ( 1 + ) )
OUT 127 D R2
N = 0 to 127 (decimal)
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 67
1xVH54PCM
ADG1207
S1A
DA
S8A
S1B
DB
S8B
8-bit
49.4 k
Gain(N) = 1 +
(N / 255) x R
AB
N = 0 to 255 (decimal)
7-bit
49.4 k
Gain(N) = 1 +
(N / 127) x R
AB
N = 0 to 127 (decimal)

## Page 68

MCP45HVX1
8.5 Audio Volume Control 8.6 Programmable Power Supply
A digital volume control can be implemented with the The ADP1611 is a step-up DC-to-DC switching con-
MCP45HVX1. Figure 8-5 shows a simple audio volume verter. Using the MCP45HVX1 device allows the power
control implementation. supply to be programmable up to 20V. Figure 8-7
shows a programmable power supply implementation.
Figure 8-6 shows a circuit-referenced voltage detect
circuit. The output of this circuit could be used to control Equation 8-3 shows the equation to calculate the
the Wiper Latch of the MCP45HVX1 device in the output voltage of the programmable power supply. This
Audio Volume control circuit to reduce zipper noise or output is derived from the R resistance of the
BW
to update the different channels at the same time. MCP45HVX1 device and the R resistor. The ADP1611
2
will adjust its output voltage to maintain 1.23V on the
The op amp (U1) could be an MCP6001, while the gen-
FB pin.
eral purpose comparators (U2 and U3) could be an
MCP6541. U4 is a simple AND gate. When power is connected, L1 acts as a short, and
V is a diode drop below the +5V voltage. The V
U1 establishes the signal zero reference. The upper OUT OUT
voltage will ramp to the programmed value.
limit of the comparator is set above its offset. The WLAT
pin is forced High whenever the voltage falls between
2.502V and 2.497V (a 0.005V window).
The capacitor C1 AC couples the V IN signal into the MCP45HVX1 +5V
circuit, before feeding into the windowed comparator (100 k)
(and MCP45HVX1 Terminal A pin). V+ A C 2
W 10 μF
L1
V+
C ADP1611 4.7 μF
1
0.1 μF B IN
MCP45HVX1 RT D 1
V A V+ FB SW
IN
R
V 1
G L ND + 8.5 k SS
V OUT COMP V OUT
SDA -
S W C L L AT B V- 22 C n 3 F 220 k R  2 1 C 0 5 μ F
C
4
V- 150 pF
FIGURE 8-5: Audio Volume Control.
FIGURE 8-7: Programmable Power
Supply.
+5V
V
IN EQUATION 8-3: POWER SUPPLY OUTPUT
R
3 VOLTAGE
100 k +5V
C CALCULATION
1 +
1 μF
R U2 8-bit
4 N * R
R 200 k - AB
1 255
90 k WLAT V (N) = 1.23V x ( 1 + ( ) )
OUT R
U4 2
R +5V N = 0 to 255 (decimal)
2
10 k +
7-bit
+5V U3 N * R
AB
+ - 127
V (N) = 1.23V x ( 1 + ( ) )
U1 OUT R
2
- R 5 N = 0 to 127 (decimal)
100 k
FIGURE 8-6: Referenced Voltage
Crossing Detect.
DS20005304B-page 68  2014-2023 Microchip Technology Inc. and its subsidiaries

## Page 69

MCP45HVX1
8.7 Programmable Bidirectional 8.8 LCD Contrast Control
Current Source
The MCP45HVX1 can be used for LCD contrast
A programmable bidirectional current source can be control. Figure 8-9 shows a simple programmable LCD
implemented with the MCP45HVX1. Figure 8-8 shows contrast control implementation.
an implementation where U1 and U2 work together to Some LCD panels support a fixed power supply of up
deliver the desired current (dependent on selected to 28V. The high-voltage digital potentiometer's wiper
device) in both directions. The circuit is symmetrical can support contrast adjustments through the entire
(R 1A = R 1B , R 2A = R 2B , R 3A = R 3B ) in order to improve voltage range.
stability. If the resistors are matched, the load current
(I ) calculation is shown below:
L
EQUATION 8-4: LOAD CURRENT (I ) L
(R + R )
2A 3A
I = x V
L R * R W
1A 3A
FIGURE 8-9: Programmable Contrast
Control.
+15V
-
U2
+
C
1 R 3A
50 k
+15V 10 pF
+ R 1A
U1
- 150 k
R 4
500
FIGURE 8-8: Programmable Bidirectional
Current Source.
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 69
1XVH54PCM
R R
1B 2B
150 k 15 k
C
2
10 pF
R
3B
50 k
-15V
V+
A
W
R 2A
V
L
14.95 k
B -15V I L
V-
XXVH54PCM
D LCD Panel
1 V (LCD Bias)
OUT
Fixed
C (up to +28V)
1
10 μF
A
uController W
+16V to +26V
SDA Contrast Adj.
SCL
B

## Page 70

MCP45HVX1
8.9 Implementing Log Steps with a EQUATION 8-5: dB CALCULATIONS
Linear Digital Potentiometer (VOLTAGE)
In audio volume control applications, the use of L = 20 * log 10 (V OUT / V IN )
logarithmic steps is desirable since the human ear
hears in a logarithmic manner. The use of a linear
dB V / V Ratio
potentiometer can approximate a log potentiometer, OUT IN
but with fewer steps. An 8-bit potentiometer can -3 0.70795
achieve fourteen 3 dB log steps plus a 100% (0 dB) -2 0.79433
and a mute setting. -1 0.89125
Figure 8-10 shows a block diagram of one of the
MCP45HVx1 resistor networks being used to attenuate
an input signal. In this case, the attenuation will be EQUATION 8-6: dB CALCULATIONS
ground referenced. Terminal B can be connected to a (RESISTANCE) – CASE 1
Common mode voltage, but the voltages on the A, B
Terminal B connected to Ground (see Figure 8-10)
and wiper terminals must not exceed the
MCP45HVx1’s V+/V- voltage limits. L = 20 * log (R / R )
10 BW AB
MCP45HVX1 EQUATION 8-7: dB CALCULATIONS
(RESISTANCE) – CASE 2
P0A
Terminal B through R to Ground
B2GND
P0W
L = 20 * log ( (R + R ) / (R + R ) )
10 BW B2GND AB B2GND
P0B
Table 8-1 shows the codes that can be used for 8-bit
digital potentiometers to implement the log attenuation.
The table shows the wiper codes for -3 dB, -2 dB, and
FIGURE 8-10: Signal Attenuation Block -1 dB attenuation steps. This table also shows the
Diagram – Ground Referenced. calculated attenuation based on the wiper code’s linear
step. Calculated attenuation values less than the
Equation 8-5 shows the equation to calculate voltage
desired attenuation are shown with red text. At lower
dB gain ratios for the digital potentiometer, while
wiper code values, the attenuation may skip a step. If
Equation 8-6 shows the equation to calculate
this occurs, the next attenuation value is colored
resistance dB gain ratios. These two equations assume
magenta to highlight that a skip occurred. For example,
that the B terminal is connected to ground.
in the -3 dB column the -48 dB value is highlighted
If Terminal B is not directly resistively connected to since the -45 dB step could not be implemented (there
ground, then this Terminal B to ground resistance are no wiper codes between 2 and 1).
(R ) must be included into the calculation.
B2GND
Equation 8-7 shows this equation.
DS20005304B-page 70  2014-2023 Microchip Technology Inc. and its subsidiaries

## Page 71

MCP45HVX1
TABLE 8-1: LINEAR TO LOG ATTENUATION FOR 8-BIT DIGITAL POTENTIOMETERS
-3 dB Steps -2 dB Steps -1 dB Steps
# of
Calculated Calculated Calculated
Steps Desired Wiper Desired Wiper Desired Wiper
Attenuation Attenuation Attenuation
Attenuation Code Attenuation Code Attenuation Code
(1) (1) (1)
0 0 dB 255 0 dB 0 dB 255 0 dB 0 dB 255 0 dB
1 -3 dB 180 -3.025 dB -2 dB 203 -1.981 dB -1 dB 227 -1.010 dB
2 -6 dB 128 -5.987 dB -4 dB 161 -3.994 dB -2 dB 203 -1.981 dB
3 -9dB 90 -9.046 dB -6 dB 128 -5.987 dB -3 dB 180 -3.025 dB
4 -12 dB 64 -12.007 dB -8 dB 101 -8.044 dB -4 dB 161 -3.994 dB
5 -15 dB 45 -15.067 dB -10 dB 81 -9.961 dB -5 dB 143 -5.024 dB
6 -18 dB 32 -18.028 dB -12 dB 64 -12.007 dB -6 dB 128 -5.987 dB
7 -21 dB 23 -20.896 dB -14 dB 51 -13.979 dB -7 dB 114 -6.993 dB
8 -24 dB 16 -24.048 dB -16 dB 40 -16.090 dB -8 dB 101 -8.044 dB
9 -27 dB 11 -27.303 dB -18 dB 32 -18.028 dB -9 dB 90 -9.046 dB
10 -30 dB 8 -30.069 dB -20 dB 25 -20.172 dB -10 dB 81 -9.961 dB
11 -33 dB 6 -32.568 dB -22 dB 20 -22.110 dB -11 dB 72 -10.984 dB
12 -36 dB 4 -36.090 dB -24 dB 16 -24.048 dB -12 dB 64 -12.007 dB
13 -39 dB 3 -38.588 dB -26 dB 13 -25.852 dB -13 dB 57 -13.013 dB
14 -42 dB 2 -42.110 dB -28 dB 10 -28.131 dB -14 dB 51 -13.979 dB
15 -48 dB 1 -48.131 dB -30 dB 8 -30.069 dB -15 dB 45 -15.067 dB
16 Mute 0 Mute -32 dB 6 -32.602 dB -16 dB 40 -16.090 dB
17 -34 dB 5 -34.151 dB -17 dB 36 -17.005 dB
18 -36 dB 4 -36.090 dB -18 dB 32 -18.028 dB
19 -38 dB 3 -38.588 dB -19 dB 29 -18.883 dB
20 -42 dB 2 -42.110 dB -20 dB 25 -20.172 dB
21 -48 dB 1 -48.131 dB -21 dB 23 -20.896 dB
22 Mute 0 Mute -22 dB 20 -22.110 dB
23 -23 dB 18 -23.025 dB
24 -24 dB 16 -24.048 dB
25 -25 dB 14 -25.208 dB
26 -26 dB 13 -25.852 dB
27 -27dB 11 -27.303 dB
28 -28 dB 10 -28.131 dB
29 -29 dB 9 -29.046 dB
30 -30 dB 8 -30.069 dB
31 -31 dB 7 -31.229 dB
32 -33 dB 6 -32.568 dB
33 -34 dB 5 -34.151 dB
34 -36 dB 4 -36.090 dB
35 -39 dB 3 -38.588 dB
36 -42 dB 2 -42.110 dB
37 -48 dB 1 -48.131 dB
38 Mute 0 Mute
Legend: Calculated Attenuation Value Color Code: Black -> Above Target Value; Red -> Below Target Value
Desired Attenuation Value Color Code: Magenta -> Skipped Desired Attenuation Value(s).
Note 1: Attenuation values do not include errors from digital potentiometer errors, such as Full-Scale Error or Zero-
Scale Error.
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 71

## Page 72

MCP45HVX1
8.10 Using the General Call Command Figure 8-11 shows two I2C bus configurations. In many
cases, the single I2C bus configuration will be
The use of the General Call Address Increment, adequate. For applications that do not want all the
Decrement, or Write commands is analogous to the MCP45HVX1 devices to do General Call support or
“Load” feature (LDAC pin) on some DACs (such as the have a conflict with General Call commands, the
MCP4921). This allows all the devices to “Update” the multiple I2C bus configuration would be used.
output level “at the same time”.
For some applications, the ability to update the wiper
Single I2C Bus Configuration
values “at the same time” may be a requirement, since
the delay from writing to one wiper value and then the
next may cause application issues. A possible example Device 1 Device 3 Device n
would be a “tuned” circuit that uses several Host
MCP45HVX1 in rheostat configuration. As the system Controller
condition changes (temperature, load, etc.) these
Device 2 Device 4
devices need to be changed (incremented/decre-
mented) to adjust for the system change. These
changes will either be in the same direction or in oppo- Multiple I2C Bus Configuration
site directions. With the Potentiometer device, the cus-
tomer can either select the PxB terminals (same Device 1a Device 3a Device na
direction) or the PxA terminal(s) (opposite direction).
Host Bus a
Figure 8-12 shows that the update of six devices takes Controller
6*T time in “normal” operation, but only
I2CDLY Device 2a Device 4a
1*T time in “General Call” operation.
I2CDLY
Note: The application system may need to Device 1b Device 3b Device nb
partition the I2C bus into multiple buses to
Bus b
ensure that the MCP45HVX1 General Call
commands do not conflict with the Gen-
eral Call commands that the other I2C Device 2b Device 4b
devices may have defined. Also, if only a
portion of the MCP45HVX1 devices are to Device 1n Device 3n Device nn
require this synchronous operation, then
Bus n
the devices that should not receive these
commands should be on the second I2C
bus. Device 2n Device 4n
FIGURE 8-11: Typical Application I2C Bus
Configurations.
Normal Operation
INC INC INC INC INC INC
POT01 POT02 POT03 POT04 POT05 POT06
T T T T T T
I2CDLY I2CDLY I2CDLY I2CDLY I2CDLY I2CDLY
General Call Operation
INC INC INC INC INC INC
POTs 01-06 POTs 01-06 POTs 01-06 POTs 01-06 POTs 01-06 POTs 01-06
T T T T T T
I2CDLY I2CDLY I2CDLY I2CDLY I2CDLY I2CDLY
T = Time from one I2C command completed to completing the next I2C command.
I2CDLY
FIGURE 8-12: Example Comparison of “Normal Operation” vs. “General Call Operation” Wiper
Updates.
DS20005304B-page 72  2014-2023 Microchip Technology Inc. and its subsidiaries

## Page 73

MCP45HVX1
8.11 Design Considerations 8.11.2 LAYOUT CONSIDERATIONS
In the design of a system with the MCP45HVX1 In the design of a system with the MCP45HVX1
devices, the following considerations should be taken devices, the following layout considerations should be
into account: taken into account:
• Power Supply Considerations • Noise
• Layout Considerations • PCB Area Requirements
• Power Dissipation
8.11.1 POWER SUPPLY
CONSIDERATIONS 8.11.2.1 Noise
The typical application will require a bypass capacitor Inductively-coupled AC transients and digital switching
in order to filter high-frequency noise, which can be noise can degrade the input and output signal integrity,
induced onto the power supply’s traces. The bypass potentially masking the MCP45HVX1’s performance.
capacitor helps to minimize the effect of these noise Careful board layout minimizes these effects and
sources on signal integrity. Figure 8-13 illustrates an increases the Signal-to-Noise Ratio (SNR). Multi-layer
appropriate bypass strategy. boards utilizing a low-inductance ground plane,
isolated inputs, isolated outputs and proper decoupling
In this example, the recommended bypass capacitor
are critical to achieving the performance that the
value is 0.1 μF. This capacitor should be placed as
silicon is capable of providing. Particularly harsh
close (within 4 mm) to the device power pin (V ) as
L environments may require shielding of critical signals.
possible.
If low noise is desired, breadboards and wire-wrapped
The power source supplying these devices should be
boards are not recommended.
as clean as possible. If the application circuit has
separate digital and analog power supplies, V+ and V- 8.11.2.2 PCB Area Requirements
should reside on the analog plane.
In some applications, PCB area is a criteria for device
selection. Table 8-2 shows the package dimensions
V DD and area for the different package options. The table
also shows the relative area factor compared to the
smallest area. For space critical applications, the
VQFN package would be the suggested package.
V L TABLE 8-2: PACKAGE FOOTPRINT (1)
DGND V
SS
FIGURE 8-13: Typical Microcontroller
Connections.
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 73
XXVH54PCM
0.1 μF
®
rellortnocorciM
CIP
0.1 μF
V+
Package Package Footprint
0.1 μF
V-
A
SDA
W SCL
B
V-
sniP
Dimensions
(mm)
Type Code
2 ) mm(
aerA
aerA
evitaleR
X Y
14 TSSOP ST 5.10 6.40 32.64 1.31
20 VQFN MQ 5.00 5.00 25.00 1
Note 1: Does not include recommended land
pattern dimensions.

## Page 74

MCP45HVX1
8.11.3 RESISTOR TEMPCO TABLE 8-3: R POWER DISSIPATION
AB
Characterization curves of the resistor temperature R Resistance () | V | + |V |
AB A B Power
coefficient (tempco) are shown in the device =
(mW) (1)
characterization graphs. Typical Min Max (V)
These curves show that the resistor network is 5,000 4,000 6,000 36 324
designed to correct for the change in resistance as
10,000 8,000 12,000 36 162
temperature increases. This technique reduces the
50,000 40,000 60,000 36 32.4
end-to-end change in R resistance.
AB
100,000 80,000 120,000 36 16.2
8.11.3.1 Power Dissipation Note 1: Power = V * I = V2/R .
AB(MIN)
The power dissipation of the high-voltage digital
potentiometer will most likely be determined by the TABLE 8-4: R BW POWER DISSIPATION
power dissipation through the resistor networks. R () | V | + |V | = IBW (2) Power
AB W B
Table 8-3 shows the power dissipation through the (Typical) (V) (mA) (mW) (1)
resistor ladder (R ) when Terminal A = +18V and
AB 5,000 36 25 900
Terminal B = -18V. This is not the worst-case power
10,000 36 12.5 450
dissipation based on the 25 mA terminal current
specification. Table 8-3 shows the worst-case current 50,000 36 6.5 234
(per resistor network), which is independent of the R AB 100,000 36 6.5 234
value).
Note 1: Power = V * I.
2: See Electrical Specifications (max I ).
W
DS20005304B-page 74  2014-2023 Microchip Technology Inc. and its subsidiaries

## Page 75

MCP45HVX1
NOTES:
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 75

## Page 76

MCP45HVX1
9.0 DEVICE OPTIONS 9.2 Custom Options
Custom options can be made available.
9.1 Standard Options
9.2.1 CUSTOM WIPER VALUE ON POR/
9.1.1 POR/BOR WIPER SETTING BOR EVENT
The default wiper setting (mid scale) is indicated by the Customers can specify a custom wiper setting via the
customer in three digit suffix: -202, -502, -103 and -503. Non-Standard Customer Authorization Request
Table 9-1 indicates the device’s default settings. (NSCAR) process.
TABLE 9-1: DEFAULT POR/BOR WIPER
SETTING SELECTION
Typical
R
AB
Value
DS20005304B-page 76  2014-2023 Microchip Technology Inc. and its subsidiaries
egakcaP
edoC
Note 1: Non-Recurring Engineering (NRE)
charges and minimum ordering
requirements for custom orders. Please
Default
Device Wiper contact Microchip sales for additional
POR Wiper
Resolution Code information.
Setting
2: A custom device will be assigned custom
5.0 k -502 Mid scale 8-bit 7Fh device marking.
7-bit 3Fh
10.0 k -103 Mid scale 8-bit 7Fh
7-bit 3Fh
50.0 k -503 Mid scale 8-bit 7Fh
7-bit 3Fh
100.0 k -104 Mid scale 8-bit 7Fh
7-bit 3Fh

## Page 77

MCP45HVX1
NOTES:
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 77

## Page 78

MCP45HVX1
10.0 DEVELOPMENT SUPPORT 10.2 Technical Documentation
Several additional technical documents are available to
10.1 Development Tools
assist you in your design and development. These
technical documents include Application Notes,
Several development tools are available to assist in
Technical Briefs and Design Guides. Table 10-2 shows
your design and evaluation of the MCP45HVX1
some of these documents.
devices. The currently available tools are shown in
Table 10-1.
Figure 10-1 shows how the TSSOP20EV bond-out
PCB can be populated to easily evaluate the
MCP45HVX1 devices. Evaluation can use the PICkitTM
Serial Analyzer to control the position of the volatile
wiper and state of the TCON register.
Figure 10-2 shows how the SOIC14EV bond-out PCB
can be populated to evaluate the MCP45HVX1
devices. The use of the PICkit Serial Analyzer would
require blue wire since the header H1 is not compatibly
connected.
These boards may be purchased directly from the
Microchip web site at www.microchip.com.
TABLE 10-1: DEVELOPMENT TOOLS
Board Name Part # Comment
20-pin TSSOP and SSOP Evaluation Board TSSOP20EV Can easily interface to PICkitTM Serial Analyzer
(Order #: DV164122)
14-pin SOIC/TSSOP/DIP Evaluation Board SOIC14EV
TABLE 10-2: TECHNICAL DOCUMENTATION
Application Title Literature #
Note Number
TB3073 Implementing a 10-bit Digital Potentiometer with an 8-bit Digital Potentiometer DS90003073
AN1316 Using Digital Potentiometers for Programmable Amplifier Gain DS00001316
AN1080 Understanding Digital Potentiometers Resistor Variations DS00001080
AN737 Using Digital Potentiometers to Design Low-Pass Adjustable Filters DS00000737
AN692 Using a Digital Potentiometer to Optimize a Precision Single Supply Photo Detection DS00000692
Circuit
AN691 Optimizing Digital Potentiometer Circuits to Reduce Absolute and Temperature Vari- DS00000691
ations
AN219 Comparing Digital Potentiometers to Mechanical Potentiometers DS00000219
— Digital Potentiometer Design Guide DS20002017
— Signal Chain Design Guide DS20001825
— Automotive Analog Solutions Design Guide DS00001005
DS20005304B-page 78  2014-2023 Microchip Technology Inc. and its subsidiaries

## Page 79

MCP45HVX1
0 
4.7k 
0 
FIGURE 10-1: Digital Potentiometer Evaluation Board Circuit Using TSSOP20EV.
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 79
1xVH54
MCP45HVX1-xxxE/ST
installed in U3 (bottom 14 pins of TSSOP-20 footprint)
Connected to Connected to
Digital Ground Digital Power (V ) Plane
L
(DGND) Plane
1.0 μF
VL V+
P0A pin shorted
4.7k  (jumpered) to
SCL P0A
V+ pin
A1 4.7k  P0W
Through-hole Test
Point (Orange)
SDA P0B
Wiper 0
4.7k  P0B pin shorted
A0 V-
(jumpered) to
V- pin
4.7k 
WLAT DGND
4.7k 
SHDN NC
Four blue wire jumpers to connect
PICkitTM Serial interface (I2C) o device pins 1x6 male header, with 90° right angle

## Page 80

MCP45HVX1
FIGURE 10-2: Digital Potentiometer Evaluation Board Circuit Using SOIC14EV.
DS20005304B-page 80  2014-2023 Microchip Technology Inc. and its subsidiaries
1XVH54PCM
1.0 μF
LV
LCS
1A
ADS
0A
TALW
NDHS
0

4.7k

4.7k

4.7k

4.7k

4.7k

4.7k

0

+V
A0P
W0P
B0P
-V
DNGD
CN
P0A pin shorted
(jumpered) to
V+ pin
P0B pin shorted
(jumpered) to
V- pin

## Page 81

MCP45HVX1
NOTES:
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 81

## Page 82

MCP45HVX1
11.0 PACKAGING INFORMATION
11.1 Package Marking Information
14-Lead TSSOP (4.4 mm) Example
XXXXXXXX
45H51502
YXYYWWWW
E416
NNN
256
Part Number Code Part Number Code
MCP45HV51-502E/ST 45H51502 MCP45HV31-502E/ST 45H31502
MCP45HV51-103E/ST 45H51103 MCP45HV31-103E/ST 45H31103
MCP45HV51-503E/ST 45H51503 MCP45HV31-503E/ST 45H31503
MCP45HV51-104E/ST 45H51104 MCP45HV31-104E/ST 45H31104
20-Lead QFN (5x5x0.9 mm) Example
PIN 1 PIN 1
45HV31
502E/MQ
e3
1416256
Part Number Code Part Number Code
MCP45HV51-502E/MQ 502E/MQ MCP45HV31-502E/MQ 502E/MQ
MCP45HV51-103E/MQ 103E/MQ MCP45HV31-103E/MQ 103E/MQ
MCP45HV51-503E/MQ 503E/MQ MCP45HV31-503E/MQ 503E/MQ
MCP45HV51-104E/MQ 104E/MQ MCP45HV31-104E/MQ 104E/MQ
Legend: XX...X Customer-specific information
Y Year code (last digit of calendar year)
YY Year code (last 2 digits of calendar year)
WW Week code (week of January 1 is week ‘01’)
NNN Alphanumeric traceability code
e3 RoHS Compliant JEDEC® designator for Matte Tin (Sn)
* This package is RoHS Compliant. The RoHS Compliant
JEDEC designator ( e 3 ) can be found on the outer packaging
for this package.
Note: In the event the full Microchip part number cannot be marked on one line, it will
be carried over to the next line, thus limiting the number of available
characters for customer-specific information.
DS20005304B-page 82  2014-2023 Microchip Technology Inc. and its subsidiaries

## Page 83

MCP45HVX1
14-Lead Thin Shrink Small Outline Package [ST] – 4.4 mm Body [TSSOP]
Note: For the most current package drawings, please see the Microchip Packaging Specification located at
http://www.microchip.com/packaging
D A
B
N
E
2
E1
2
E1 E
2X 7 TIPS
1 2 0.20 C B A
e
TOP VIEW
A
C A2 A
SEATING
PLANE
14X 14X b A1 A
0.10 C
0.10 C B A
SIDE VIEW
SEE DETAIL B
VIEW A–A
Microchip Technology Drawing C04-087 Rev E Sheet 1 of 2
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 83

## Page 84

MCP45HVX1
14-Lead Thin Shrink Small Outline Package [ST] – 4.4 mm Body [TSSOP]
Note: For the most current package drawings, please see the Microchip Packaging Specification located at
http://www.microchip.com/packaging
((cid:537)2)
R1
H
R2
c
L (cid:537)1
(L1)
((cid:537)3)
DETAIL B
Units MILLIMETERS
Dimension Limits MIN NOM MAX
Number of Terminals N 14
Pitch e 0.65 BSC
Overall Height A – – 1.20
Standoff A1 0.05 – 0.15
Molded Package Thickness A2 0.80 1.00 1.05
Overall Length D 4.90 5.00 5.10
Overall Width E 6.40 BSC
Molded Package Width E1 4.30 4.40 4.50
Terminal Width b 0.19 – 0.30
Terminal Thickness c 0.09 – 0.20
Terminal Length L 0.45 0.60 0.75
Footprint L1 1.00 REF
Lead Bend Radius R1 0.09 – –
Lead Bend Radius R2 0.09 – –
Foot Angle (cid:537)1 0° – 8°
Mold Draft Angle (cid:537)2 – 12° REF –
Mold Draft Angle (cid:537)3 – 12° REF –
Notes:
1. Pin 1 visual index feature may vary, but must be located within the hatched area.
2. Dimensioning and tolerancing per ASME Y14.5M
BSC: Basic Dimension. Theoretically exact value shown without tolerances.
REF: Reference Dimension, usually without tolerance, for information purposes only.
Microchip Technology Drawing C04-087 Rev E Sheet 2 of 2
DS20005304B-page 84  2014-2023 Microchip Technology Inc. and its subsidiaries

## Page 85

MCP45HVX1
14-Lead Thin Shrink Small Outline Package [ST] – 4.4 mm Body [TSSOP]
Note: For the most current package drawings, please see the Microchip Packaging Specification located at
http://www.microchip.com/packaging
G
SILK SCREEN
C
Y
X
E
RECOMMENDED LAND PATTERN
Units MILLIMETERS
Dimension Limits MIN NOM MAX
Contact Pitch E 0.65 BSC
Contact Pad Spacing C 5.90
Contact Pad Width (Xnn) X 0.45
Contact Pad Length (Xnn) Y 1.45
Contact Pad to Contact Pad (Xnn) G 0.20
Notes:
1. Dimensioning and tolerancing per ASME Y14.5M
BSC: Basic Dimension. Theoretically exact value shown without tolerances.
Microchip Technology Drawing C04-2087 Rev E
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 85

## Page 86

MCP45HVX1
20-Lead Plastic Quad Flat, No Lead Package (MQ) – 5x5x1.0 mm Body [VQFN]
With 0.40 mm Contact Length
Note: For the most current package drawings, please see the Microchip Packaging Specification located at
http://www.microchip.com/packaging
D A
B
NOTE 1 N
1
2
E
(DATUM B)
(DATUM A)
2X
0.20 C
2X
0.20 C TOP VIEW
0.10 C A1
C
A
SEATING
PLANE
20X
(A3)
0.08 C
SIDE VIEW
0.10 C A B
D2
0.10 C A B
E2
2
1
NOTE 1
N K
L 20X b
e 0.10 C A B
0.05 C
BOTTOM VIEW
Microchip Technology Drawing C04-139C (MQ) Sheet 1 of 2
DS20005304B-page 86  2014-2023 Microchip Technology Inc. and its subsidiaries

## Page 87

MCP45HVX1
20-Lead Plastic Quad Flat, No Lead Package (MQ) – 5x5x1.0 mm Body [VQFN]
With 0.40 mm Contact Length
Note: For the most current package drawings, please see the Microchip Packaging Specification located at
http://www.microchip.com/packaging
Units MILLIMETERS
Dimension Limits MIN NOM MAX
Number of Terminals N 20
Pitch e 0.65 BSC
Overall Height A 0.80 0.90 1.00
Standoff A1 0.00 0.02 0.05
Contact Thickness (A3) 0.20 REF
Overall Length D 5.00 BSC
Exposed Pad Length D2 3.15 3.25 3.35
Overall Width E 5.00 BSC
Exposed Pad Width E2 3.15 3.25 3.35
Contact Width b 0.25 0.30 0.35
Contact Length L 0.35 0.40 0.45
Contact-to-Exposed Pad K 0.20 - -
Notes:
1. Pin 1 visual index feature may vary, but must be located within the hatched area.
2. Package is saw singulated
3. Dimensioning and tolerancing per ASME Y14.5M
BSC: Basic Dimension. Theoretically exact value shown without tolerances.
REF: Reference Dimension, usually without tolerance, for information purposes only.
Microchip Technology Drawing C04-139C (MQ) Sheet 2 of 2
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 87

## Page 88

MCP45HVX1
20-Lead Plastic Quad Flat, No Lead Package (MQ) – 5x5x1.0 mm Body [VQFN]
With 0.40 mm Contact Length
Note: For the most current package drawings, please see the Microchip Packaging Specification located at
http://www.microchip.com/packaging
C1
X2
EV
20
1
ØV
Y2 2 G
C2
EV
Y1
E
X1 SILK SCREEN
RECOMMENDED LAND PATTERN
Units MILLIMETERS
Dimension Limits MIN NOM MAX
Contact Pitch E 0.65 BSC
Optional Center Pad Width W2 3.35
Optional Center Pad Length T2 3.35
Contact Pad Spacing C1 4.50
Contact Pad Spacing C2 4.50
Contact Pad Width (X20) X1 0.40
Contact Pad Length (X20) Y1 0.55
Distance Between Pads G 0.20
Thermal Via Diameter V 0.30
Thermal Via Pitch EV 1.00
Notes:
1. Dimensioning and tolerancing per ASME Y14.5M
BSC: Basic Dimension. Theoretically exact value shown without tolerances.
2. For best soldering results, thermal vias, if used, should be filled or tented to avoid solder loss during
reflow process
Microchip Technology Drawing C04-2139B (MQ)
DS20005304B-page 88  2014-2023 Microchip Technology Inc. and its subsidiaries

## Page 89

MCP45HVX1
APPENDIX A: REVISION HISTORY
Revision B (June 2023)
• Updated Table 7-1.
• Added Automotive Product Identification System
(Automotive).
• Minor typographical errors.
Revision A (June 2014)
• Original release of this document.
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 89

## Page 90

MCP45HVX1
APPENDIX B: TERMINOLOGY B.3 Resolution
This appendix discusses the terminology used in this The resolution is the number of wiper output states that
document and it also describes how a parameter is divide the full-scale range. For the 8-bit digital
measured. potentiometer, the resolution is 28, meaning the digital
potentiometer wiper code ranges from 0 to 255.
B.1 Potentiometer (Voltage Divider)
B.4 Step Resistance (R )
S
The potentiometer configuration is when all three
terminals of the device are tied to different nodes in the The resistance Step size (R S ) equates to one LSb of
circuit. This allows the potentiometer to output a the resistor ladder. <Link>Equation B-1 shows the cal-
voltage proportional to the input voltage. This culation for the step resistance (R S ).
configuration is sometimes called Voltage Divider
mode. The potentiometer is used to provide a variable EQUATION B-1: R CALCULATION
S
voltage by adjusting the wiper position between the two
Ideal
endpoints as shown in Figure B-1. Reversing the R (V - V ) / I
polarity of the A and B terminals will not affect R S(Ideal) = 2 N A - B 1 or A 2 N B - 1 AB
operation.
Measured
V 1 R = (V W(@FS) - V W(@ZS) ) / I AB
S(Measured)
2N - 1
A where:
2N - 1 = 255 (MCP45HV51/61)
V
W 3 = 127 (MCP45HV31/41)
V = Voltage on Terminal A pin
B A
V = Voltage on Terminal B pin
B
V
2 I = Measured Current through A and B pins
AB
FIGURE B-1: POTENTIOMETER V W(@FS) = Measured Voltage on W pin at
CONFIGURATION. Full-Scale code (FFh or 7Fh)
V = Measured Voltage on W pin at
W(@ZS)
The temperature coefficient of the R resistors is
AB Zero-Scale code (00h)
minimal by design. In this configuration, the resistors all
change uniformly, so minimal variation should be seen.
B.5 Wiper Resistance
B.2 Rheostat (Variable Resistor)
Wiper resistance is the series resistance of the analog
The rheostat configuration is when two of the three dig- switch that connects the selected resistor ladder node
ital potentiometer’s terminals are used as a resistive to the Wiper terminal common signal (see Figure 5-1).
element in the circuit. With Terminal W (wiper) and A value in the volatile Wiper register selects which
either Terminal A or Terminal B, a variable resistor is analog switch to close, connecting the W terminal to
created. The resistance will depend on the tap setting the selected node of the resistor ladder.
of the wiper (and the wiper’s resistance). The
The resistance is dependent on the voltages on the
resistance is controlled by changing the wiper setting.
analog switch source, gate, and drain nodes, as well as
Figure B-2 shows the two possible resistors that can be
the device’s wiper code, temperature, and the current
used. Reversing the polarity of the A and B terminals
through the switch. As the device voltage decreases,
will not affect operation.
the wiper resistance increases.
The wiper resistance is measured by forcing a current
through the W and B terminals (I ) and measuring the
WB
voltage on the W and A terminals (V and V ). Termi-
A W A
nal A is not biased. <Link>Equation B-2 shows how to
calculate this resistance.
W R AW or R BW
B
Resistor
FIGURE B-2: RHEOSTAT
CONFIGURATION.
DS20005304B-page 90  2014-2023 Microchip Technology Inc. and its subsidiaries

## Page 91

MCP45HVX1
EQUATION B-2: R CALCULATION B.8 Least Significant Bit (LSb)
W
R = (V W - V A ) This is the difference between two successive codes
W(Measured)
I (either in resistance or voltage). For a given output
WB
range it is divided by the resolution of the device
where:
(<Link>Equation B-5).
V = Voltage on Terminal A pin
A
V = Voltage on Terminal W pin
W EQUATION B-5: LSb CALCULATION
I = Measured current through W and B pins
WB
Ideal
The wiper resistance in potentiometer-generated In Resistance In Voltage
voltage divider applications is not a significant source R V - V
of error (it does not affect the output voltage seen on LSb(Ideal) = A B A B
2N -1 2N - 1
the W pin).
The wiper resistance in rheostat applications can Measured
create significant nonlinearity as the wiper is moved
LSb(Measured) =
toward zero scale (00h). The lower the nominal
(V - V ) / I
resistance, the greater the possible error. W(@FS) W(@ZS) AB
2N - 1
B.6 R ZS Resistance V W(@FS) - V W(@ZS)
2N - 1
The analog switch between the resistor ladder and the
Terminal B pin introduces a resistance, which we call
where:
the Zero-Scale resistance (R ). <Link>Equation B-3
ZS 2N - 1 = 255 (MCP45HV51)
shows how to calculate this resistance.
= 127 (MCP45HV31)
V = Voltage on Terminal A pin
A
EQUATION B-3: R CALCULATION
ZS V = Voltage on Terminal B pin
B
R = (V W(@ZS) - V B ) V AB = Measured Voltage between A and B pins
ZS(Measured) I I AB = Measured Current through A and B pins
AB
V = Measured Voltage on W pin at
where: W(@FS)
Full-Scale code (FFh or 7Fh)
V = Voltage on Terminal W pin
W(@ZS) V = Measured Voltage on W pin at
at Zero-Scale wiper code W(@ZS)
Zero-Scale code (00h)
V = Voltage on Terminal B pin
B
I = Measured Current through A and B pins
WB
B.7 R Resistance
FS
The analog switch between the resistor ladder and the
Terminal A pin introduces a resistance, which we call
the Full-Scale resistance (R ). <Link>Equation B-4
FS
shows how to calculate this resistance.
EQUATION B-4: R CALCULATION
FS
(V - V )
R = A W(@FS)
FS(Measured)
I
AB
where:
V = Voltage on Terminal A pin
A
V = Voltage on Terminal W pin
W(@FS)
at Full-Scale wiper code
I = Measured Current through A and B pins
WB
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 91

## Page 92

MCP45HVX1
B.9 Monotonic Operation B.10 Full-Scale Error (E )
FS
Monotonic operation means that the device’s output The Full-Scale Error (see Figure B-5) is the error of
(resistance (R ) or voltage (V )) increases with the V pin relative to the expected V voltage
BW W W W
every one code step (LSb) increment of the Wiper (theoretical) for the maximum device wiper register
register. code (code FFh for 8-bit and code 7Fh for 7-bit), see
<Link>Equation B-6. The error is defined with no
resistive load on the P0W pin.
0x40
The error in bits is determined by the theoretical voltage
step size to give an error in LSb.
0x3F
0x3E
0x03
0x02
0x01
EQUATION B-6: FULL-SCALE ERROR
0x00
FIGURE B-3: THEORETICAL V
W
OUTPUT VS CODE (MONOTONIC
OPERATION).
FIGURE B-5: FULL-SCALE ERROR
EXAMPLE.
FIGURE B-4: THEORETICAL R
BW
OUTPUT VS CODE (MONOTONIC
OPERATION).
DS20005304B-page 92  2014-2023 Microchip Technology Inc. and its subsidiaries
edoC
repiW
V
S64
V
S63
V
S3
V
S1
V
S0
V (@ tap) W n = [unreadable glyph]
V = V + V W Sn ZS(@ Tap 0)
n = 0
Voltage (V ~= V )
W OUT
0x3F
0x3E
0x3D
0x03
0x02
0x01
0x00
edoC
tupnI
latigiD
Note: Analog switch leakage increases with
temperature. This leakage increases sub-
stantially at higher temperatures (>
~100°C). As analog switch leakage
increases, the full-scale output value
decreases, which increases the Full-
Scale Error.
V - V W(@FS) A
E =
FS
V LSb(IDEAL)
Where:
E is expressed in LSb FS
V is the V voltage when the Wiper
W@FS) W
register code is at Full-scale.
V is the ideal output voltage when the
IDEAL(@FS)
Wiper register code is at Full-scale.
V is the theoretical voltage step size.
LSb(IDEAL)
R
S63
R
S62
R S3
R S1
R
S0
R
W n = [unreadable glyph]
(@ tap)
R = R + R
BW Sn W(@ Tap n)
n = 0
Resistance (R )
BW
V W
V
A
V
FS
Actual
Transfer Full-Scale
Function Error (E FS )
Ideal Transfer
Function
V
ZS
V
B
0 Full-Scale
Wiper Code

## Page 93

MCP45HVX1
B.11 Zero-Scale Error (E )
ZS
The Zero-Scale Error (see Figure B-6) is the difference
between the ideal and measured V voltage with the
OUT
Wiper register code equal to 00h (<Link>Equation B-
7). The error is defined with no resistive load on the
P0W pin.
The error in bits is determined by the theoretical voltage
step size to give an error in LSb.
Note: Analog switch leakage increases with
temperature. This leakage increases sub-
stantially at higher temperatures (>
~100°C). As analog switch leakage
increases the zero-scale output value
decreases, which decreases the Zero-
Scale Error.
EQUATION B-7: ZERO SCALE ERROR
V
W@ZS)
E =
ZS
V
LSb(IDEAL)
Where:
E is expressed in LSb
FS
V is the V voltage when the Wiper
W@ZS) W
register code is at Zero-scale.
V is the theoretical voltage step size.
LSb(IDEAL)
FIGURE B-6: ZERO-SCALE ERROR
EXAMPLE.
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 93
V
W
V
A
V
FS
Actual
Transfer
Function
Ideal Transfer
Function
V
ZS
V
B
0 Full-Scale
Zero-Scale Wiper Code
Error (E )
ZS

## Page 94

MCP45HVX1
B.12 Integral Nonlinearity (P-INL) B.13 Differential Nonlinearity (P-DNL)
Potentiometer Configuration Potentiometer Configuration
The Potentiometer Integral nonlinearity (P-INL) error is The Potentiometer Differential nonlinearity (P-DNL)
the maximum deviation of an actual V transfer error (see Figure B-8) is the measure of V step size
W W
function from an ideal transfer function (straight line). between codes. The ideal step size between codes is
1 LSb. A P-DNL error of zero would imply that every
In the MCP45HVX1, P-INL is calculated using the zero-
code is exactly 1 LSb wide. If the P-DNL error is less
scale and full-scale wiper code end points. P-INL is
than 1 LSb, the digital potentiometer guarantees mono-
expressed in LSb. P-INL is also called relative
tonic output and no missing codes. The P-DNL error
accuracy. <Link>Equation B-8 shows how to calculate
between any two adjacent codes is calculated in
the P-INL error in LSb and Figure B-7 shows an
<Link>Equation B-9.
example of P-INL accuracy.
P-DNL error is the measure of variations in code widths
Positive P-INL means higher V voltage than ideal.
W
from the ideal code width.
Negative P-INL means lower V voltage than ideal.
W
Note: Analog switch leakage increases with
Note: Analog switch leakage increases with
temperature. This leakage increases sub-
temperature. This leakage increases sub-
stantially at higher temperatures
stantially at higher temperatures
(> ~100°C). As analog switch leakage
(> ~100°C). As analog switch leakage
increases, the Wiper output voltage (V )
increases, the Wiper output voltage (V ) W
W
decreases, which affects the DNL Error.
decreases, which affects the INL Error.
EQUATION B-9: P-DNL ERROR
EQUATION B-8: P-INL ERROR
( V - ( V * Code )) ( V - V ) - V )
E = W(@Code) LSb(Measured) E = W(code = n+1) W(code = n) LSb(Measured)
INL V DNL V
LSb(Measured) LSb(Measured)
Where:
Where:
INL is expressed in LSb.
DNL is expressed in LSb.
Code = Wiper Register Value
V = The measured V output
W(Code = n) W
V W(@Code) = The measured V W output voltage with a given Wiper
voltage with a given Wiper register code.
register code
V = For Ideal:
LSb
V LSb = For Ideal: V AB / Resolution
V AB / Resolution For Measured:
For Measured: (V - V ) / # of R
W(@FS) W(@ZS) S
(V - V ) / 255
W(@FS) W(@ZS)
INL < 0
111 111
Actual
110
110 transfer Actual
function transfer
101 function
101
Wiper 100 Ideal transfer
Wiper 100 Code function
Code 011
011
Ideal transfer
010
function Wide code, > 1 LSb
010
001
001
000
Narrow code < 1 LSb
000
INL < 0
V Output Voltage
W
V Output Voltage
W
FIGURE B-8: P-DNL ACCURACY.
FIGURE B-7: P-INL ACCURACY.
DS20005304B-page 94  2014-2023 Microchip Technology Inc. and its subsidiaries

## Page 95

MCP45HVX1
B.14 Integral Nonlinearity (R-INL) B.15 Differential Nonlinearity (R-DNL)
Rheostat Configuration Rheostat Configuration
The Rheostat Integral nonlinearity (R-INL) error is the The Rheostat Differential nonlinearity (R-DNL) error
maximum deviation of an actual R transfer function (see Figure B-10) is the measure of R step size
BW BW
from an ideal transfer function (straight line). between codes in actual transfer function. The ideal
step size between codes is 1 LSb. A R-DNL error of
In the MCP45HVX1, INL is calculated using the Zero-
zero would imply that every code is exactly 1 LSb wide.
Scale and Full-Scale wiper code end points. R-INL is
If the R-DNL error is less than 1 LSb, the R Resis-
expressed in LSb. R-INL is also called relative BW
tance guarantees monotonic output and no missing
accuracy. <Link>Equation B-10 shows how to calcu-
codes. The R-DNL error between any two adjacent
late the R-INL error in LSb and Figure B-9 shows an
codes is calculated in <Link>Equation B-11.
example of R-INL accuracy.
R-DNL error is the measure of variations in code widths
Positive R-INL means higher V voltage than ideal.
OUT
from the ideal code width. A R-DNL error of zero would
Negative R-INL means lower V voltage than ideal.
OUT
imply that every code is exactly 1 LSb wide.
EQUATION B-10: R-INL ERROR
EQUATION B-11: R-DNL ERROR
( R - R )
E = BW(@code) BW(Ideal) E =
INL DNL
R
LSb(Ideal)
( R - R ) - R )
Where: BW(code = n+1) BW(code = n) LSb(Measured)
R
LSb(Measured)
INL is expressed in LSb.
R = The measured R resistance Where:
BW(Code = n) BW
with a given wiper register code
DNL is expressed in LSb.
R = For Ideal:
LSb R = The measured R resistance
BW(Code = n) BW
R / Resolution
AB with a given wiper register code
For Measured:
R = For Ideal:
R / # of R LSb
BW(@FS) S R / Resolution
AB
For Measured:
R / # of R
BW(@FS) S
INL < 0
111
Actual
110 transfer
function 111
101
110
Actual
Wiper 100 transfer
101 function
Code
011 Ideal transfer Wiper 100 Ideal transfer
function Code function
010 011
001 010
Wide code, > 1 LSb
001
000
INL < 0
000
R Resistance Narrow code < 1 LSb
BW
FIGURE B-9: R-INL ACCURACY.
R Resistance
BW
FIGURE B-10: R-DNL ACCURACY.
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 95

## Page 96

MCP45HVX1
B.16 Total Unadjusted Error (E ) B.18 Major-Code Transition Glitch
T
The Total Unadjusted Error (E ) is the difference Major-code transition glitch is the impulse energy
T
between the ideal and measured V voltage. injected into the wiper pin when the code in the Wiper
W
Typically, calibration of the output voltage is register changes state. It is normally specified as the
implemented to improve system performance. area of the glitch in nV-Sec, and is measured when the
digital code is changed by 1 LSb at the major carry tran-
The error in bits is determined by the theoretical voltage
sition (Example: 01111111 to 10000000, or
step size to give an error in LSb.
10000000 to 01111111).
<Link>Equation B-12 shows the Total Unadjusted Error
calculation.
B.19 Digital Feedthrough
Note: Analog switch leakage increases with
The digital feedthrough is the glitch that appears at the
temperature. This leakage increases sub-
analog output caused by coupling from the digital input
stantially at higher temperatures
pins of the device. The area of the glitch is expressed
(> ~100°C). As analog switch leakage
in nV-Sec, and is measured with a full-scale change
increases, the Wiper output voltage (V )
W (Example: all 0s to all 1s and vice versa) on the digital
decreases, which affects the Total
input pins. The digital feedthrough is measured when
Unadjusted Error.
the digital potentiometer is not being written to the out-
put register.
EQUATION B-12: TOTAL UNADJUSTED
ERROR CALCULATION B.20 Power-Supply Sensitivity (PSS)
E = ( V W_Actual(@code) - V W_Ideal(@Code) ) PSS indicates how the output (V W or R BW ) of the digital
T V potentiometer is affected by changes in the supply volt-
LSb(Ideal)
age. PSS is the ratio of the change in V to a change
W
Where: in V for mid-scale output of the digital potentiometer.
L
The V is measured while the V is varied from 5.5V to
E is expressed in LSb. W L
T
2.7V as a step, and expressed in %/%, which is the %
V = The measured W pin output
W_Actual(@code) change of the V output voltage with respect to the %
voltage at the specified code W
change of the V voltage.
L
V = The calculated W pin output
W_Ideal(@code)
voltage at the specified code
EQUATION B-13: PSS CALCULATION
( code * V )
LSb(Ideal)
V LSb(Ideal) = V AB / # R S PSS = ( V W(@5.5V) - V W(@2.7V) ) / V W(@5.5V) )
8-bit = V AB / 255 (5.5V - 2.7V) / 5.5V
7-bit = V / 127
AB
Where:
B.17 Settling Time PSS is expressed in %/%.
V = The measured V output
W(@5.5V) W
The settling time is the time delay required for the V W voltage with V L = 5.5V
voltage to settle into its new output value. This time is
V = The measured V output
W(@2.7V) W
measured from the start of code transition, to when the
voltage with V = 2.7V
L
V voltage is within the specified accuracy. It is related
W
to the RC characteristics of the resistor ladder and
wiper switches. B.21 Power-Supply Rejection Ratio
(PSRR)
In the MCP45HVX1, the settling time is a measure of
the time delay until the V voltage reaches within 0.5
W PSRR indicates how the output of the digital potentiom-
LSb of its final value, when the volatile Wiper register
eter is affected by changes in the supply voltage. PSRR
changes from zero scale to full scale (or full scale to
is the ratio of the change in V to a change in V for full-
zero scale). W L
scale output of the digital potentiometer. The V is
W
measured while the V is varied +/- 10% (V and V
L A B
voltages held constant), and expressed in dB or μV/V.
DS20005304B-page 96  2014-2023 Microchip Technology Inc. and its subsidiaries

## Page 97

MCP45HVX1
B.22 Ratiometric Temperature B.24 -3dB Bandwidth
Coefficient
This is the frequency of the signal at the A terminal, that
The ratiometric temperature coefficient quantifies the causes the voltage at the W pin to be -3dB from its
error in the ratio R /R due to temperature drift. expected value, based on its wiper code. The expected
AW WB
This is typically the critical error when using a digital value is determined by the static voltage value on the A
potentiometer in a voltage divider configuration. terminal and the wiper code value.
B.23 Absolute Temperature Coefficient B.25 Resistor Noise Density (e N_WB )
The absolute temperature coefficient quantifies the This is the random noise generated by the device’s
error in the end-to-end resistance (Nominal resistance internal resistances. It is specified as a spectral density
R ) due to temperature drift. This is typically the (voltage per square root Hertz).
AB
critical error when using the device in an adjustable
resistor configuration.
Characterization curves of the resistor temperature
coefficient (tempco) are shown in Section 2.0, Typical
Performance Curves.
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 97

## Page 98

MCP45HVX1
NOTES:
DS20005304B-page 98  2014-2023 Microchip Technology Inc. and its subsidiaries

## Page 99

MCP45HVX1
PRODUCT IDENTIFICATION SYSTEM
To order or obtain information, e.g., on pricing or delivery, refer to the factory or the listed sales office.
PART NO. [X](1) XXX X /XX Examples:
a) MCP45HV51T-502E/ST
Device Tape and Reel Resistance Temperature Package
5 k, 8-bit, 14-LD TSSOP
Option Version Range
b) MCP45HV51T-103E/ST
10 k, 8-bit, 14-LD TSSOP
Device: MCP45HV31: Single Potentiometer (7-bit) with I2CTM Interface c) MCP45HV31T-503E/ST
50 k, 7-bit, 14-LD TSSOP
MCP45HV51: Single Potentiometer (8-bit) with I2C Interface d) MCP45HV31T-104E/MQ
100 k, 7-bit, 20-LD VQFN (5x5)
Tape and Reel T = Tape and Reel(1)
Option: “blank” = Tube a) MCP45HV51T-502E/MQ
5 k, 8-bit, 20-LD VQFN (5x5)
Resistance 502 = 5 k b) MCP45HV51T-103E/MQ
Version: 103 = 10 k 10 k, 8-bit, 20-LD VQFN (5x5)
503 = 50 k c) MCP45HV31T-503E/MQ
104 = 100 k 50 k, 7-bit, 20-LD VQFN (5x5)
d) MCP45HV31T-104E/MQ
Temperature E = -40°C to +125°C 100 k, 7-bit, 20-LD VQFN (5x5)
Range:
Package: ST = Plastic TSSOP-14, 14-lead Note 1: Tape and Reel identifier only appears in
the catalog part number description. This
MQ = Plastic VQFN-20 (5x5), 20-lead
identifier is used for ordering purposes and
is not printed on the device package.
Check with your Microchip Sales Office for
Class: Blank= Non Automotive
package availability with the Tape and Reel
VAO = Automotive
option.
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 99

## Page 100

MCP45HVX1
PRODUCT IDENTIFICATION SYSTEM (AUTOMOTIVE)
To order or obtain information, e.g., on pricing or delivery, refer to the factory or the listed sales office.
PART NO. [X](1) XXX X /XX Examples:
a) MCP45HV51T-502E/STVAO
Device Tape and Reel Resistance Temperature Package
5 k, 8-bit, 14-LD TSSOP
Option Version Range
b) MCP45HV51T-103E/STVAO
10 k, 8-bit, 14-LD TSSOP
Device: MCP45HV31: Single Potentiometer (7-bit) with I2CTM Interface c) MCP45HV31T-503E/STVAO
50 k, 7-bit, 14-LD TSSOP
MCP45HV51: Single Potentiometer (8-bit) with I2C Interface d) MCP45HV31T-104E/MQVAO
100 k, 7-bit, 20-LD VQFN (5x5)
Tape and Reel T = Tape and Reel(1)
Option: “blank” = Tube a) MCP45HV51T-502E/MQVAO
5 k, 8-bit, 20-LD VQFN (5x5)
Resistance 502 = 5 k b) MCP45HV51T-103E/MQVAO
Version: 103 = 10 k 10 k, 8-bit, 20-LD VQFN (5x5)
503 = 50 k c) MCP45HV31T-503E/MQVAO
104 = 100 k 50 k, 7-bit, 20-LD VQFN (5x5)
d) MCP45HV31T-104E/MQVAO
Temperature E = -40°C to +125°C 100 k, 7-bit, 20-LD VQFN (5x5)
Range:
Package: ST = Plastic TSSOP-14, 14-lead Note 1: Tape and Reel identifier only appears in
the catalog part number description. This
MQ = Plastic VQFN-20 (5x5), 20-lead
identifier is used for ordering purposes and
is not printed on the device package.
Check with your Microchip Sales Office for
Class: Blank= Non Automotive
package availability with the Tape and Reel
VAO = Automotive
option.
DS20005304B-page 100  2014-2023 Microchip Technology Inc. and its subsidiaries

## Page 101

Note the following details of the code protection feature on Microchip products:
• Microchip products meet the specifications contained in their particular Microchip Data Sheet.
• Microchip believes that its family of products is secure when used in the intended manner, within operating specifications, and
under normal conditions.
• Microchip values and aggressively protects its intellectual property rights. Attempts to breach the code protection features of
Microchip product is strictly prohibited and may violate the Digital Millennium Copyright Act.
• Neither Microchip nor any other semiconductor manufacturer can guarantee the security of its code. Code protection does not
mean that we are guaranteeing the product is "unbreakable" Code protection is constantly evolving. Microchip is committed to
continuously improving the code protection features of our products.
This publication and the information herein may be used only Trademarks
with Microchip products, including to design, test, and integrate The Microchip name and logo, the Microchip logo, Adaptec, AVR,
Microchip products with your application. Use of this informa- AVR logo, AVR Freaks, BesTime, BitCloud, CryptoMemory,
tion in any other manner violates these terms. Information CryptoRF, dsPIC, flexPWR, HELDO, IGLOO, JukeBlox, KeeLoq,
Kleer, LANCheck, LinkMD, maXStylus, maXTouch, MediaLB,
regarding device applications is provided only for your conve-
megaAVR, Microsemi, Microsemi logo, MOST, MOST logo,
nience and may be superseded by updates. It is your responsi-
MPLAB, OptoLyzer, PIC, picoPower, PICSTART, PIC32 logo,
bility to ensure that your application meets with your PolarFire, Prochip Designer, QTouch, SAM-BA, SenGenuity,
specifications. Contact your local Microchip sales office for SpyNIC, SST, SST Logo, SuperFlash, Symmetricom, SyncServer,
additional support or, obtain additional support at https:// Tachyon, TimeSource, tinyAVR, UNI/O, Vectron, and XMEGA are
registered trademarks of Microchip Technology Incorporated in the
www.microchip.com/en-us/support/design-help/client-support-
U.S.A. and other countries.
services.
AgileSwitch, APT, ClockWorks, The Embedded Control Solutions
THIS INFORMATION IS PROVIDED BY MICROCHIP "AS IS".
Company, EtherSynch, Flashtec, Hyper Speed Control, HyperLight
MICROCHIP MAKES NO REPRESENTATIONS OR WAR- Load, Libero, motorBench, mTouch, Powermite 3, Precision Edge,
RANTIES OF ANY KIND WHETHER EXPRESS OR IMPLIED, ProASIC, ProASIC Plus, ProASIC Plus logo, Quiet-Wire,
WRITTEN OR ORAL, STATUTORY OR OTHERWISE, SmartFusion, SyncWorld, Temux, TimeCesium, TimeHub,
TimePictra, TimeProvider, TrueTime, and ZL are registered
RELATED TO THE INFORMATION INCLUDING BUT NOT
trademarks of Microchip Technology Incorporated in the U.S.A.
LIMITED TO ANY IMPLIED WARRANTIES OF NON-
INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
Adjacent Key Suppression, AKS, Analog-for-the-Digital Age, Any
PARTICULAR PURPOSE, OR WARRANTIES RELATED TO Capacitor, AnyIn, AnyOut, Augmented Switching, BlueSky,
ITS CONDITION, QUALITY, OR PERFORMANCE. BodyCom, Clockstudio, CodeGuard, CryptoAuthentication,
CryptoAutomotive, CryptoCompanion, CryptoController,
IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDI- dsPICDEM, dsPICDEM.net, Dynamic Average Matching, DAM,
ECAN, Espresso T1S, EtherGREEN, GridTime, IdealBridge, In-
RECT, SPECIAL, PUNITIVE, INCIDENTAL, OR CONSE-
Circuit Serial Programming, ICSP, INICnet, Intelligent Paralleling,
QUENTIAL LOSS, DAMAGE, COST, OR EXPENSE OF ANY IntelliMOS, Inter-Chip Connectivity, JitterBlocker, Knob-on-Display,
KIND WHATSOEVER RELATED TO THE INFORMATION OR KoD, maxCrypto, maxView, memBrain, Mindi, MiWi, MPASM, MPF,
ITS USE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS MPLAB Certified logo, MPLIB, MPLINK, MultiTRAK, NetDetach,
BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES Omniscient Code Generation, PICDEM, PICDEM.net, PICkit,
PICtail, PowerSmart, PureSilicon, QMatrix, REAL ICE, Ripple
ARE FORESEEABLE. TO THE FULLEST EXTENT
Blocker, RTAX, RTG4, SAM-ICE, Serial Quad I/O, simpleMAP,
ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON SimpliPHY, SmartBuffer, SmartHLS, SMART-I.S., storClad, SQI,
ALL CLAIMS IN ANY WAY RELATED TO THE INFORMATION SuperSwitcher, SuperSwitcher II, Switchtec, SynchroPHY, Total
OR ITS USE WILL NOT EXCEED THE AMOUNT OF FEES, IF Endurance, Trusted Time, TSHARC, USBCheck, VariSense,
ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP VectorBlox, VeriPHY, ViewSpan, WiperLock, XpressConnect, and
ZENA are trademarks of Microchip Technology Incorporated in the
FOR THE INFORMATION.
U.S.A. and other countries.
Use of Microchip devices in life support and/or safety applica-
SQTP is a service mark of Microchip Technology Incorporated in
tions is entirely at the buyer's risk, and the buyer agrees to the U.S.A.
defend, indemnify and hold harmless Microchip from any and
all damages, claims, suits, or expenses resulting from such The Adaptec logo, Frequency on Demand, Silicon Storage
use. No licenses are conveyed, implicitly or otherwise, under Technology, and Symmcom are registered trademarks of Microchip
Technology Inc. in other countries.
any Microchip intellectual property rights unless otherwise
stated.
GestIC is a registered trademark of Microchip Technology Germany
II GmbH & Co. KG, a subsidiary of Microchip Technology Inc., in
other countries.
All other trademarks mentioned herein are property of their
respective companies.
© 2014-2023, Microchip Technology Incorporated and its subsidiar-
ies.
All Rights Reserved.
ISBN: 978-1-6683-2734-0
For information regarding Microchip’s Quality Management Systems,
please visit www.microchip.com/quality.
 2014-2023 Microchip Technology Inc. and its subsidiaries DS20005304B-page 101

## Page 102

Worldwide Sales and Service
AMERICAS ASIA/PACIFIC ASIA/PACIFIC EUROPE
Corporate Office Australia - Sydney India - Bangalore Austria - Wels
2355 West Chandler Blvd. Tel: 61-2-9868-6733 Tel: 91-80-3090-4444 Tel: 43-7242-2244-39
Chandler, AZ 85224-6199 Fax: 43-7242-2244-393
China - Beijing India - New Delhi
Tel: 480-792-7200 Tel: 86-10-8569-7000 Tel: 91-11-4160-8631 Denmark - Copenhagen
Fax: 480-792-7277 Tel: 45-4485-5910
China - Chengdu India - Pune
Technical Support: Tel: 86-28-8665-5511 Tel: 91-20-4121-0141 Fax: 45-4485-2829
http://www.microchip.com/
support China - Chongqing Japan - Osaka Finland - Espoo
Tel: 86-23-8980-9588 Tel: 81-6-6152-7160 Tel: 358-9-4520-820
Web Address:
www.microchip.com China - Dongguan Japan - Tokyo France - Paris
Tel: 86-769-8702-9880 Tel: 81-3-6880- 3770 Tel: 33-1-69-53-63-20
Atlanta
Fax: 33-1-69-30-90-79
Duluth, GA China - Guangzhou Korea - Daegu
Tel: 678-957-9614 Tel: 86-20-8755-8029 Tel: 82-53-744-4301 Germany - Garching
Tel: 49-8931-9700
Fax: 678-957-1455 China - Hangzhou Korea - Seoul
Austin, TX Tel: 86-571-8792-8115 Tel: 82-2-554-7200 Germany - Haan
Tel: 49-2129-3766400
Tel: 512-257-3370 China - Hong Kong SAR Malaysia - Kuala Lumpur
Boston Tel: 852-2943-5100 Tel: 60-3-7651-7906 Germany - Heilbronn
Tel: 49-7131-72400
Westborough, MA China - Nanjing Malaysia - Penang
Tel: 774-760-0087 Tel: 86-25-8473-2460 Tel: 60-4-227-8870 Germany - Karlsruhe
Fax: 774-760-0088 Tel: 49-721-625370
China - Qingdao Philippines - Manila
Chicago Tel: 86-532-8502-7355 Tel: 63-2-634-9065 Germany - Munich
Itasca, IL Tel: 49-89-627-144-0
China - Shanghai Singapore
Tel: 630-285-0071 Tel: 86-21-3326-8000 Tel: 65-6334-8870 Fax: 49-89-627-144-44
Fax: 630-285-0075 Germany - Rosenheim
China - Shenyang Taiwan - Hsin Chu
Dallas Tel: 86-24-2334-2829 Tel: 886-3-577-8366 Tel: 49-8031-354-560
Addison, TX Israel - Ra’anana
China - Shenzhen Taiwan - Kaohsiung
Tel: 972-818-7423 Tel: 972-9-744-7705
Tel: 86-755-8864-2200 Tel: 886-7-213-7830
Fax: 972-818-2924
Italy - Milan
China - Suzhou Taiwan - Taipei
Detroit Tel: 39-0331-742611
Tel: 86-186-6233-1526 Tel: 886-2-2508-8600
Novi, MI Fax: 39-0331-466781
Tel: 248-848-4000 China - Wuhan Thailand - Bangkok
Italy - Padova
Tel: 86-27-5980-5300 Tel: 66-2-694-1351
Houston, TX Tel: 39-049-7625286
Tel: 281-894-5983 China - Xian Vietnam - Ho Chi Minh
Netherlands - Drunen
Tel: 86-29-8833-7252 Tel: 84-28-5448-2100
Indianapolis Tel: 31-416-690399
Noblesville, IN China - Xiamen Fax: 31-416-690340
Tel: 86-592-2388138
Tel: 317-773-8323
Norway - Trondheim
Fax: 317-773-5453 China - Zhuhai Tel: 47-7288-4388
Tel: 317-536-2380 Tel: 86-756-3210040
Poland - Warsaw
Los Angeles Tel: 48-22-3325737
Mission Viejo, CA
Romania - Bucharest
Tel: 949-462-9523
Tel: 40-21-407-87-50
Fax: 949-462-9608
Tel: 951-273-7800 Spain - Madrid
Tel: 34-91-708-08-90
Raleigh, NC
Fax: 34-91-708-08-91
Tel: 919-844-7510
Sweden - Gothenberg
New York, NY
Tel: 46-31-704-60-40
Tel: 631-435-6000
Sweden - Stockholm
San Jose, CA
Tel: 46-8-5090-4654
Tel: 408-735-9110
Tel: 408-436-4270 UK - Wokingham
Tel: 44-118-921-5800
Canada - Toronto
Fax: 44-118-921-5820
Tel: 905-695-1980
Fax: 905-695-2078
DS20005304B-page 102  2014-2023 Microchip Technology Inc. and its subsidiaries
09/14/21
