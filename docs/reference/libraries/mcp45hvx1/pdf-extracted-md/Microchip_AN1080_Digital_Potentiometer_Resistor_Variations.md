# Understanding Digital Potentiometer Resistor Variations - Extracted Text

- Source PDF: `../Microchip_AN1080_Digital_Potentiometer_Resistor_Variations.pdf`
- Manufacturer URL: https://ww1.microchip.com/downloads/aemDocuments/documents/OTH/ApplicationNotes/ApplicationNotes/01080a.pdf
- Extraction date: 2026-05-09
- Page count: 14
- SHA256: `430EE0653CF4EDD1A10CF76CB2208C0B8C7BC1EAE7345FE3664FCECD3D2B3625`
- Notes: Raw text extracted with pypdf. Tables, equations, and figures may require checking against the source PDF.

## Page 1

© 2007 Microchip Technology Inc. DS01080A-page 1
AN1080
INTRODUCTION
All semiconductor devices have variations over
process. In the case of digital potentiometer devices,
this process variation affe cts the device resistive
elements (R AB -> R S and R W). These resistive
elements also have variations with respect to voltage
and temperature, which will also be discussed.
This application note will discuss how process, voltage,
and temperature affect the Resistor Network’s
characteristics and specif ications. Also, application
techniques will be covered that can assist in optimizing
the operation of the device to improve performance in
the application.
The process technology used also affects the
operational characteristics. We will focus on the
characteristics for devices fabricated in CMOS.
TERMINOLOGY
To assist with the discussions in this application note,
the following terminology will be used. Figure 1
illustrates several of these terms.
Resolution - The number of unique wiper positions
that can be selected between Terminal B and Terminal
A.
Wiper Value - The value in the wiper register which
selects the one wiper switch to close so that the Wiper
Terminal is connected to the Resistor Network.
R
AB - The total resistance between the A Terminal and
the B Terminal. 
RS - The Step resistance. This is the change in resis-
tance that occurs between two adjacent wiper register
values. It is also the RAB resistance divided by the num-
ber of RS resistors (resolution) in the Resistor Ladder.
RW - The resistance of the analog switch that connects
the Wiper Terminal to the Resistor Ladder. Each analog
switch will have slightly diff erent resistive characteris-
tics.
Resistor Ladder - Is the serial string of R S resistors
between Terminal B and Terminal A. The total resis-
tance of this string equals R
AB. 
Resistor Network - Is the combination of RS resistors
and RW resistor that create the voltage levels and cur-
rent paths between the A Terminal, B Terminal, and
Wiper Terminal.
R
BW - The total resistance from Terminal B to the Wiper
Terminal. This resistance equals: 
RS * (Wiper Register value) + RW. 
RAW - The total resistance from Terminal A to the Wiper
Terminal. This resistance equals: 
RS * (Full Scale value - Wiper Register value) + RW. 
Full Scale  - When the Wiper is connected to the
closest tap point to Terminal A.
Zero Scale  - When the Wiper is connected to the
closest tap point to Terminal B.
FIGURE 1: 8-Bit Resistor Network.
Author: Mark Palmer 
Microchip Technology Inc.
W
B
A
n = 0
n = 1
n = 2
n = 254
n = 255
n = 256
(Zero 
(Full Scale)
RS
RAB
RBW
RAW
RW
RS
RS
RS
RW
RW
RW
RW
RW
 Scale)
Understanding Digital Potentiometer Resistor Variations

## Page 2

AN1080
DS01080A-page 2 © 2007 Microchip Technology Inc.
THE RAB RESISTANCE 
The R AB resistance is the total resistance between
Terminal A and Terminal B. The RAB resistance is really
a resistor string of R S resistors. The R S resistors are
designed to be uniform, so they have minimal variation
with respect to each other. The R
S resistors, and the
RAB resistance, will track each other over voltage, tem-
perature, and process.
Many manufacturers specify the devices R AB resis-
tance to be ±20% from the targeted (typical) value. This
specification is to indicate that from “device-to-device”
the resistance could range ±20% from the typical value.
This specification is NOT meant that a given devices
resistance will vary ±20% over voltage and
temperature. 
So, when the R
AB resistance is +10% from the typical
value, then each R S resistor is also +10% from the
typical value.
The “device-to-device” RAB resistance could be off by
up to 40% of the typical value. This occurs if one device
has a resistance (R AB) that is -20% and the other
device is +20%.
FIGURE 2: RAB Variations.
So, naturally the RAB resistance may have some effect
in a Potentiometer configuration (voltage divider), but
this variation can have a real effect in a Rheostat
configuration (variable resistor). 
In the Potentiometer config uration, if the A and B
terminals are connected to a fixed voltage, then this
variation should not effect the system. But, if either (or
both) the A or/and B terminals are connected through
resistors to the fixed voltage source, then the change in
R
AB value could effect the voltage at the W terminal (for
a given wiper code value).
In the Rheostat configuration, the RBW resistance value
will vary as R S varies. So, at full scale R BW
approximately equals R AB, and will have the same
±20% from the typical value.
The Step Resistance (RS)
Microchip offers Digital Potentiometer devices with
typical RAB resistances of 2.1 k Ω, 5 kΩ, 10 kΩ, 50 kΩ
and 100 kΩ. These devices will either offer 6-bits or 8-
bits of resolution. The step resistance (R S) is the R AB
resistances divided by the number of wiper steps.
The step resistance is important to understand when
you are using the device in a rheostat mode, or the
potentiometer is being windowed by resistors on the
Terminal A and/or on the Terminal B. Table 1 shows the
step resistances available for the different R AB values
available. 
TABLE 1: STEP RESISTANCE
On a semiconductor device, a resistor can be made
with metal/poly/contact components. Designing a
structure from these components can be used to form
a resistive element (R
S). Repeating this resistive
element into a string of resistors (RS) creates the RAB
resistance. The node between each R S resistor is a
contact point (source or drain) for the wiper switch.
RAB(TYP) = 10 kΩ 
RAB(MAX) = 12 kΩ 
RAB(MIN) = 8 kΩ 
-20% 
+20% 
Δ40% 
RAB 
Resistance 
(kΩ - typ.)
Step Resistance 
(RS) (Ω - typ.)
Comment6-Bit 
Device
(63 RS)
8-Bit 
Device
(256 RS)
2.1 33.33 — Smallest Step 
resistance available
5.0 79.37 —
10.0 158.73 39.06 Can trade off between 
cost and Step Resis-
tance (resolution)
50.0 793.65 195.31 Can trade off between 
cost and Step Resis-
tance (resolution)
100.0 — 390.63 Largest R AB resistance

## Page 3

© 2007 Microchip Technology Inc. DS01080A-page 3
AN1080
Devices with Multiple Potentiometers
Some devices are offered that have two or more
independent potentiometers. Each potentiometer will
exhibit similar characteristics given similar conditions
(terminal voltages, wiper settings, …).
The R
AB variation between potentiometers on the
same silicon is relatively small. In dual potentiometer
devices, the variation is typically specified as a
maximum variation (R AB1-RAB2/RAB1 or R AB1-RAB2/
RAB2) of 1%. This is true even though from device-to-
device, the RAB variation can be ±20% over process.
The R AB of both potentiometers (and therefore the
RSs) will track each other as the device conditions
change. It is assumed t hat the terminals of each
potentiometer are at the same voltages (and wiper
value). If not, then they may not track each other to the
same degree.
RAB vs. RBW Resistance 
The RAB resistance is “constant” in that it is indepen-
dent of the value in the wi per register. While the R BW
(or RAW) resistance is directly related to the value in the
wiper register. When the wiper register is loaded with
it’s maximum value, the R
BW resistance is close to RAB
resistance. The “closeness” depends on the Resistor
Network implementation (see Figure 4), the R
S resis-
tance, and the wiper resistance (RW). 
THE RW RESISTANCE 
Figure 4 show the common way to illustrate the block
diagram. In this figure, the wiper resistance is
represented as a resistor. In actuality, the wiper is con-
nected to each R S node with an analog switch (see
Figure 3). Each of these analog switches has a resis-
tive property to them and will vary from switch to switch.
Also, the resistive nature of these analog switches is
more susceptible to process variations, voltage, and
temperature than the step resistors (RS) in the resistor
ladder.
FIGURE 3: RW Implementation.
The characteristics of the analog switch depends on
the voltages on the switch nodes (source, drain, and
gate). The characterization graphs shown in Figure 10
through Figure 13 had Terminal B to VSS and Terminal
A to VDD. 
Within a voltage range, the change in resistance will be
linear relative to the device voltage. At some point as
the voltage decreases, the resistive characteristics of
the switches will become non-linear at increase
exponentially. This is related to the operational charac-
teristics of the switch devices at the lower voltage.
All the wiper switches will start to increase non-linearly
at about the same voltage.
Temperature also effects th e resistive nature of the
wiper switches greater than the R
AB (RS) resistance.
The wiper resistance increases as the voltage delta
between the resistor network node and the voltage on
the analog mux switch beco mes “small”, so that the
switch is not fully turned on. The wiper resistance curve
would look different if Terminal A was at V
DD/2 while
Terminal B is at V SS. In this case, the higher value
wiper codes would have the higher wiper resistance
(RW).
A 
RS 
RS
RS 
B 
N = 256
N = 255
N = 1
N = 0
RW 
W 
Analog
Mux
RW 
RW 
RW 
(00h)
(01h)
(FFh)
(100h)

## Page 4

AN1080
DS01080A-page 4 © 2007 Microchip Technology Inc.
The Resistor Network 
Figure 4 shows three possible Resistor Network
implementations for an 8-bit resistor network. Each has
an advantage and a disadvantage. The system
designer needs to understand which implementation
the device uses to ensure the circuit meets the system
requirements.
Implementation A has 256 steps (2
8 steps) and 256
Step Resistors (RS), but the wiper register must be 9-
bits wide to allow the selection of N = 256 (Full Scale).
This increases the complexity of the wiper decode logic
(increases cost), but this implementation allows the
Wiper (W) to be connected to Terminal A. 
Implementation B has 255 steps (2
8 - 1 steps) but 256
Step Resistors (RS). This allows the wiper register to be
8-bits wide, but now the Wiper (W) can no longer
connect to Terminal A, since there is one R S resistor
between the maximum wiper tap position and the
Terminal A connection. 
Implementation C has 255 steps (2
8 - 1 steps) and 255
Step Resistors (RS). This allows the wiper register to be
8-bits wide, and to allow the selection of N = 255 (Full
Scale).
TABLE 2: IMPLEMENTATION DIFFERENCES
FIGURE 4: Possible 8-Bit Resistor Network Implementations.
Note: The possible nodes that the wiper can
connect to on the resistor ladder will
depend on the digital potentiometer
device. 
Implementation
“True”
Full 
Scale
Wiper 
Register RAB =R BW =C o m m e n t
A Yes 9-bits 256 R S 256 R S + RW Wiper can connect to the full range of taps from 
Terminal A and Terminal B, but firmware must take 
into account the extra addressing bit. The increased 
complexity of the addressing decode adds cost to the 
device.
BN o 8 - b i t s 2 5 6  R
S 255 R S + RW Wiper can not connect to the Terminal A tap. The 
application design or the controller firmware may be 
required to take this into account.
C Yes 8-bits 255 R S 255 R S + RW Wiper can connect to the full range of taps from 
Terminal A and Terminal B, but the controller firmware 
would need to ensure it addressed that there are 255 
RS resistors and not 256 RS resistors. 
A 
RS 
RS
RS 
B 
N = 256
N = 255
N = 1
N = 0
RW 
W 
Analog
Mux
RW 
RW 
RW 
(00h)
(01h)
(FFh)
(100h)
A 
RS
RS
RS 
B 
N = 255
N = 1
N = 0
RW 
W 
Analog
Mux
RW 
RW 
(00h)
(01h)
(FFh)
A 
RS
RS 
B 
N = 255
N = 1
N = 0
RW 
W 
Analog
Mux
RW 
RW 
(00h)
(01h)
(FFh)
Implementation A Implementation B Implementation C

## Page 5

© 2007 Microchip Technology Inc. DS01080A-page 5
AN1080
THE RBW OR RAW RESISTANCE 
When using a Digital Potentiometer device in a Rheo-
stat configuration, should the variable resistor be
created from the Wiper to Terminal B (RBW) or from the
Wiper to Terminal A (RAW)?
This question really depends on which Terminal (A or
B) that the Wiper connects to when the wiper register is
loaded with 0h (Zero Scale). For this discussion, we will
assume that the Wiper will connect to Terminal B.
In either case, you can load the wiper register to get the
desired resistance value, but if you recall Terminal B is
at Zero-Scale. So, that means when using the R
BW
configuration, as the wiper register is incremented, the
resistance increases. Conversely, when using the RAW
configuration, as the wiper register is incremented, the
resistance decreases. Which configuration is used
depends more on any advantages that may occur in
the applications firmware algorithm for the control of
the resistance.
The Floating Terminal, What to do?
When the Digital Potentiometer device is used in a
Rheostat configuration, the third terminal (let’s say Ter-
minal A) is “floating”. So what should be done with it?
There are two possibilities:
1. “Tie” it to the W Terminal.
2. Leave it floating.
FIGURE 5: Rheostat Configurations.
Method 1: “Tie” it to the W Terminal
In this case, the effectiv e resistance of the wiper
resistance (RWEFF) will be RW || RAB1. This resistance
will always be less than R W, but it will vary over the
selected tap position. The R WEFF resistance can be
calibrated out of the system, but it  becomes a much
more complicated controller firmware task.
Method 2: Leave it floating
This way, the wiper resistance remains “constant” over
the selected tap position. This becomes much easier
for the controller firmware to calibrate out of the
system.
W 
A
B
W 
A
B
Method 1 Method 2
RW RW 
RBW1 RAW1 
RBW1 RAW1

## Page 6

AN1080
DS01080A-page 6 © 2007 Microchip Technology Inc.
VARIATIONS OVER VOLTAGE AND 
TEMPERATURE
There are two variations that occur over voltage and
temperature that we will look at. These are the
variations of the RAB resistance and the RW resistance.
The characterization graphs also show how these
variations effect the INL and DNL error of the device.
RAB Variation
For this discussion, we will look at the characterization
graphs from the MCP402X Data Sheet (DS21945D).
These graphs are shown in Figure 6 through Figure 9.
These graphs are used to illustrate several points, but
the general characteristics will be seen on all digital
potentiometers.
Depending on the silicon implementation of the R
S
resistors will determine the characteristic shape of the
resistance over temperature. For these devices, the RS
resistor was designed so that one part of the resistor
has a negative temperature coefficient and another
part of the resistor has a positive coefficient. That is the
reason why the resistance bows over the temperature
range. This is done to minimize the end-to-end change
in resistance, and in effect reduces the worst-case
delta resistance over temperature.
Table 3 shows the R
AB data from the MCP402X Data
Sheet (DS21945D) Characterization Graphs at 5.5V
and 2.7V, and over temperature (@ -40°C, +25°C and
+125°C). The minimum and maximum resistance
values are also captured. This data was then analyzed
over this characterization range.
FIGURE 6: MCP402X 2.1 kΩ – Nominal 
Resistance (Ω) vs. Ambient Temperature and 
VDD.
FIGURE 7: MCP402X 5 kΩ – Nominal 
Resistance (Ω) vs. Ambient Temperature and 
VDD.
FIGURE 8: MCP402X 10 kΩ – Nominal 
Resistance (Ω) vs. Ambient Temperature and 
VDD.
FIGURE 9: MCP402X 50 kΩ – Nominal 
Resistance (Ω) vs. Ambient Temperature and 
VDD.
Note 1: The MCP401X and MCP402X devices
have 6-bits of resolution (RAB = 63 RS). 
2: For this characterization, Terminal A =
VDD and Terminal B = VSS.
Note: The RS value can be calculated by:
RAB / (# RS resistors in RAB) 
2000
2020
2040
2060
2080
-40 0 40 80 120
Ambient Temperature  (°C)
Nominal Resistance (R AB) 
(Ohms)
VDD = 2.7V
VDD = 5.5V
4800
4825
4850
4875
4900
4925
4950
-40 -20 0 20 40 60 80 100 120
Ambient Temperature (°C)
Nominal Resistance (R AB) 
(Ohms)
2.7V Vdd
5.5V Vdd
VDD = 2.7V
VDD = 5.5V
10050
10070
10090
10110
10130
10150
10170
10190
10210
10230
10250
- 4 0 - 2 00 2 04 06 08 0 1 0 0 1 2 0
Ambient Temperature  (°C)
Nominal Resistance (R AB) 
(Ohms)
VDD = 2.7V
VDD = 5.5V
48000
48200
48400
48600
48800
49000
49200
49400
49600
49800
- 4 0 - 2 00 2 04 06 08 0 1 0 0 1 2 0
Ambient Temperature  (°C)
Nominal Resistance (R AB) 
(Ohms) VDD = 2.7V
VDD = 5.5V

## Page 7

© 2007 Microchip Technology Inc. DS01080A-page 7
AN1080
From the analysis, it can be determined that the smaller
the RAB resistance, the greater the effect that voltage
and temperature has as a percentage of the target
resistance.
Also, if the application is operating at a narrower
voltage or temperature window, the R AB variation will
be less than across the entire voltage/temperature
range.
It is interesting to note that depending on the devices
target RAB value, either limiting the voltage of operation
or limiting the temperature range will lead to minimizing
the variation. In the case of the 2.1 k Ω device, if the
voltage is held constant, the variation is about 1%,
while the variation over temperature is about 2.2%. On
the 5.0 kΩ device, variation over temperature is about
the same as the variation over voltage. for the 10.0 kΩ
and 50.0 kΩ devices, the variation over voltage is much
larger than the variation over temperature.
TABLE 3: R AB VALUES AND VARIATION OVER VOLTAGE AND TEMPERATURE    
Device RAB 
Voltage
Characterization RAB Value 
-40°C
+25°C
+125°C
Min.
Max.
Delta
% (of Target 
Resistance)
Lowest Min.(1) to 
Highest Max.(1) 
% (of Target 
Resistance)
2.1 kΩ 5.5V 2065 2053 2075 2052 2075 22 0.95% 68 3.24%2.7V 2030 2010 2018 2007 2030 23 1.10%
Delta Resistance over Voltage 35 43 57 48 45
% (of Target Resistance: 2.1 kΩ) 1.67% 2.05% 2.71% 2.29% 2.14%
5.0 kΩ 5.5V 4895 4873 4920 4873 4920 47 0.94% 96 1.92%2.7V 4860 4825 4860 4824 4860 36 0.72%
Delta Resistance over Voltage 35 48 60 49 60
% (of Target Resistance: 5.0 kΩ) 0.70% 0.96% 1.20% 0.98% 1.20%
10.0 kΩ 5.5V 10223 10113 10152 10092 10223 131 1.31% 173 1.73%2.7V 10200 10073 10102 10050 10200 150 1.50%
Delta Resistance over Voltage 23 50 40 42 23
% (of Target Resistance: 
10.0 kΩ)
0.23% 0.50% 0.40% 0.42% 0.23%
50.0 kΩ 5.5V 49590 48880 49220 48810
49590 780 1.56% 800 1.6%2.7V 49510 48880 49080 48790 49510 720 1.44%
Delta Resistance over Voltage 80 0 140 20 80
% (of Target Resistance: 
50.0 kΩ)
0.16% 0.00% 0.28% 0.04% 0.16%
Note 1: The lowest Minimum is typically found at 2.7V and the highest Maximum is typically found at 5.5V.
See shaded cells.

## Page 8

AN1080
DS01080A-page 8 © 2007 Microchip Technology Inc.
RW Variation
For this discussion, we will look at the characterization
graphs from the MCP402X Data Sheet (DS21945D).
These graphs are shown in Figure 10 through
Figure 13. These graphs are used to illustrate several
points, but the general characteristics will be seen on
all digital potentiometers.
When the device is at 5.5V, the wiper resistance is
relatively stable over the wiper code settings. As the
device voltage drops, the wiper resistance increases.
Then, at some threshold voltage, the middle codes of
the wiper will start to have the highest resistance (see
Figure 11). This is due to the resistive characteristics of
the analog switch with respect to the voltages on the
switch nodes (source, drain, and gate). 
The variation of the wiper resistance is also influenced
by the wiper code selected and the voltages on
Terminal A and Terminal B.
Depending on the configuration of the digital potenti-
ometer in the application (V
DD, V A, V B, and wiper
code), the wiper resistance may show waveform over
wiper code.
This change in wiper resistance (RW) effects the INL of
the device much greater for devices with the smaller
RAB (and therefore R S) resistance value. This can be
seen in comparing the wiper resistance and INL error in
the graphs of Figure 11 and Figure 13.
FIGURE 10: MCP402X 2.1 kΩ Rheo 
Mode – RW (Ω), INL (LSb), DNL (LSb) vs. Wiper 
Setting and Ambient Temperature (VDD = 5.5V).
FIGURE 11: MCP402X 2.1 kΩ Rheo 
Mode – RW (Ω), INL (LSb), DNL (LSb) vs. Wiper 
Setting and Ambient Temperature (VDD = 2.7V).
FIGURE 12: MCP402X 50 kΩ Rheo 
Mode – RW (Ω), INL (LSb), DNL (LSb) vs. Wiper 
Setting and Ambient Temperature (VDD = 5.5V).
FIGURE 13: MCP402X 50 kΩ Rheo 
Mode – RW (Ω), INL (LSb), DNL (LSb) vs. Wiper 
Setting and Ambient Temperature (VDD = 2.7V).
Note 1: The MCP401X and MCP402X devices
have 6-bits of resolution (RAB = 63 RS). 
2: For this characterization, Terminal A =
VDD and Terminal B = VSS. 
0
20
40
60
80
100
120
0 8 16 24 32 40 48 56
Wiper Setting (decimal)
Wiper Resistance 
(Rw)(ohms)
-0.4
-0.2
0
0.2
0.4
0.6
0.8
Error (LSb)
-40C Rw 25C Rw 85C Rw 125C Rw
-40C INL 25C INL 85C INL 125C INL
-40C DNL 25C DNL 85C DNL 125C DNL
INL
DNLRW
0
100
200
300
400
500
0 8 16 24 32 40 48 56
Wiper Setting (decimal)
Wiper Resistance 
(Rw)(ohms)
-2
0
2
4
6
8
10
Error (LSb)
-40C Rw 25C Rw 85C Rw 125C Rw
-40C INL 25C INL 85C INL 125C INL
-40C DNL 25C DNL 85C DNL 125C DNL
INL
DNLRW
0
50
100
150
200
0 8 16 24 32 40 48 56
Wiper Setting (decimal)
Wiper Resistance 
(Rw)(ohms)
-0.1
-0.05
0
0.05
0.1
0.15
Error (LSb)
-40C Rw 25C Rw 85C Rw 125C Rw
-40C INL 25C INL 85C INL 125C INL
-40C DNL 25C DNL 85C DNL 125C DNL
INL
DNL
RW
0
100
200
300
400
500
600
0 8 16 24 32 40 48 56
Wiper Setting (decimal)
Wiper Resistance 
(Rw)(ohms)
-1.5
-1
-0.5
0
0.5
1
1.5
Error (LSb)
-40C Rw 25C Rw 85C Rw 125C Rw
-40C INL 25C INL 85C INL 125C INL
-40C DNL 25C DNL 85C DNL 125C DNL
INL
DNL
RW

## Page 9

© 2007 Microchip Technology Inc. DS01080A-page 9
AN1080
Table 4 shows the relationship of the Step resistance
(RS) to the Wiper Resistance. This is important to
understand when the resistor network is being used in
a Rheostat configuration, since the variation of the
wiper resistance (RW) has a direct effect on the RBW (or
RAW) resistance. The system can be designed to
calibrate these variations as long as the system is
capable of measuring the digital potentiometer device
voltage and the system temperature.
TABLE 4: TYPICAL STEP RESISTANCES AND RELATIONSHIP TO WIPER RESISTANCE
Resistance (Ω)R W / RS (%) (1) R W / RAB (%) (2) 
Typical Wiper (R W) (3) 
RW = Typical
RW = Max @ 5.5V
RW = Max @ 2.7V
RW = Typical
RW = Max @ 5.5V
RW = Max @ 2.7V
Total 
(RAB) 
Step (RS)
Typical Max @ 
5.5V
Max @ 
2.7V
 6-bit Device 
(63 resistors)
8-bit Device 
(256 resistors)
(4) 
2100 33.33 — 75 125 325 225.0% 375.0% 975.0% 3. 57% 5.95% 15.48%
5000 79.37 — 75 125 325 94.5% 157.5% 409.5% 1.5% 2.50% 6.50%
10000 158.73 — 75 125 325 47.25% 78.75% 204.75% 0.75% 1.25% 3.25%
— 39.06 75 100 125 192.0% 256.0% 320.0% 0.75% 1.0% 1.25%
50000 793.65 — 75 125 325 9.45% 15.75% 40.95% 0.15% 0.25% 0.65%
— 195.31 75 100 125 38.4% 51.2% 64.0% 0.15% 0.20% 0.25%
100000 — 390.63 75 100 125 19.2% 25.6%% 32.0% 0.08% 0.10% 0.13%
Note 1: RS is the typical value. The variation of this resistance is minimal over voltage.
2: RAB is the typical value. The variation of this resistance is minimal over voltage.
3: RW values are taken from the MCP402X Data Sheet (6-bit devices) and the MCP41XXX/MCP42XXX Data
Sheet (8-bit devices). 
4: MCP41XXX and MCP42XXX devices.

## Page 10

AN1080
DS01080A-page 10 © 2007 Microchip Technology Inc.
THE A AND B TERMINALS
The voltage on the A and B terminals (VA and VB) can
be any voltage within the devices power supply rails
(VSS and VDD). Lets call the voltages at these nodes,
VA and VB. 
The voltage across the resistor RAB (VAB) is | VA - VB |.
In the circuit shown in Figure 14, as the V AB voltage
becomes smaller relative to the voltage range, the
effective resolution of the device increase, though the
resolution is limited to between the V
A and VB voltages. 
This means that the potentiometer can be used to trim
a voltage set point within a defined voltage window (see
Figure 14). So, if the digital potentiometer is 8-bits (256
steps) and the delta voltage between V
A and VB is 1V,
then each step of the digital potentiometer results in a
change of 1/256 V, or 3.9 mV. If the device needed to
have this resolution over an entire 5V range, then the
digital potentiometer would require 1280 steps, which
is over 10-bits of accuracy.
This allows a less precise (lower cost) device to be
used for more precise circuit tuning over a narrower
voltage range. Table 5 shows the effective resolution of
the digital potentiometer relative to the system voltage
and the V
A - VB voltage.
FIGURE 14: Windowed Trimming.
There is no requirement for a voltage polarity between
Terminal A and Terminal B. This means that VA can be
higher or lower then VB.
TABLE 5: HOW THE V AB VOLTAGE 
EFFECTS THE EFFECTIVE 
RESOLUTION
Shutdown Mode
Some devices support a “shutdown” mode. The
purpose of this mode is to reduce system current. A
common implementation is to disconnect either Termi-
nal A or Terminal B from the internal resistor ladder.
This creates an open circuit and eliminates the current
from Terminal A (or Terminal B) through the R
S
resistors to Terminal B (or Terminal A). The current to/
from the wiper depends on what the device does with
the W Terminal in shutdown. The MCP42XXX device
forces the W Terminal to connect to Terminal B (Zero
Scale).
FIGURE 15: Disconnecting Terminal A (or 
Terminal B) from the Resistor Ladder.
VA R1
POT1 (RAB)
R2 VB 
W 
V1 
V2 
A
B
VAB 
(V) 
Step Voltage 
(VS) (mV)
Effective 
Resolution
Comment
6-bit Device 
(63 RS)
8-bit Device 
(256 RS)
6-bit Device 
(63 RS)
8-bit Device 
(256 RS)
5.0 79.4 19.5 6-bits 8-bits V AB = VDD 
2.5 39.7 9.8 7-bits 9-bits V DD = 5.0V, 
VAB = VDD/2 
1.25 1.98 4.9 8-bits 10-bits V DD = 5.0V, 
VAB = VDD/4 
A 
RS 
RS
RS 
B 
N = 256
N = 255
N = 1
N = 0
RW 
W 
Analog
Mux
RW 
RW 
RW 
(00h)
(01h)
(FFh)
(100h)
SHDN
SHDN

## Page 11

© 2007 Microchip Technology Inc. DS01080A-page 11
AN1080
IMPLEMENTING A MORE PRECISE 
RHEOSTAT
The RAB (RS) value of a typical digital potentiometer
can vary as much as ±20% from device to device. This
variation can have a great effect on a circuit that is
using the RBW resistance for tuning and this variation
for the rheostat value may not be desirable. 
If you want to make your variable resistor more precise
for system calibration and tuning, the following
technique may be useful.
To create a circuit with greater accuracy, the system
needs to be able to calibrate the digital potentiometer
to make a precise rheostat. This is at a cost of the
resolution of the digital potentiometer.
At the system manufacturing test, a method needs to
be present to measure the resistance of the R
AB value.
This could be done by measuring the current through
RAB. This value (R AB(CAL)) would be saved on the
embedded systems non-volatile memory. The embed-
ded systems controller coul d use this information to
calibrate the rheostat value (R
BW), where: 
RBW = ((RAB(CAL)/Resolution) * Wiper Value) + RW 
For this discussion, we will use a digital potentiometer
with a typical RAB resistance of 10 kΩ. That means that
the R AB resistance could be as small as 8 k Ω
(RAB(MIN)) or as large as 12 kΩ (RAB(MAX)). Figure 16 a
graphic representation of the variations of R AB
resistance by showing the minimum and maximum
resistances verses the wiper code value.
Table 6 shows the actual calculations for each step for
the typical R
AB resistance (10 kΩ) and worst-case RAB
resistances (8 k Ω and 12 k Ω). When the R AB (R BW)
resistance is 12 kΩ, the RBW = 8 kΩ crossover occurs
at wiper value 171 (decimal). 
Very few devices will actually be the 8 k Ω value, but
every device will have a wiper register value that will be
close to this 8 k Ω resistance. The circuit should
assume that the resistance  is the minimum. That is
because all devices can have a wiper value which
“creates” this resistance value.
The embedded systems controller firmware would take
the calibration value and ensure that the digital potenti-
ometer wiper value did not exceed the desired
resistance (8 k Ω). For a system that had a “typical”
device (10 kΩ), that would mean the wiper value would
not exceed 205 (decimal), while for a “+20% “device
(12 kΩ) the wiper value would not exceed 171
(decimal). These values give the closest resistance
value to the desired rheostat target value of 8 kΩ.
The calibration information could be represented as the
maximum wiper value code or as the actual RAB or RS
value. The embedded systems controller firmware then
would calculate the appropriate wiper values for the
desired R
BW resistance. Voltage and temperature
calibration information could also be stored.
FIGURE 16: RAB Variation.
Here we have designed the application circuit where
this rheostat only operates from 0 Ω to 8 k Ω and all
digital potentiometer devices (over process) will meet
this requirement. This means that we have reduced the
resolution of the digital potentiometer since we no
longer have the full 256 steps. Looking at the worst-
case resistance (+20%), t here are a maximum of 171
steps. This means that the worst-case step accuracy is
1/171 (~0.58%). This represents a resolution of
approximately 7.4-bits. We have a trade-off between a
precise variable resistor and the resolution (number of
steps) that the variable resistor can support.
The error from the 8 k Ω target will be no greater than
±R
S(MAX)/2 (or ± 23.5Ω) which is ≤ 0.29%. Where: 
RS(MAX) = RAB(MAX)/Resolution 
= 12000/256 = 46.875Ω.
Any R BW resistance ≤ 8k Ω can be selected for the
variable resistor range. Choosing a lower resistance
does not necessarily affect the accuracy, but does
affect the number of steps available for the resistor.
Let’s say that we select a 5 k Ω resistance, the wiper
values would range from 107 (+20%) to 160 (-20%).
The worst-case (minimum) number of steps is 107,
which gives an step accuracy of 1/107 (~0.93%) and an
error from target resistance ≤ 0.47%. This is still in line
with systems designed using 1% resistors, but still
requires a fixed voltage and  temperature. Additional
calibration values can be used to correct for the change
of the wiper resistance (R
W) over temperature and
voltage.
Additional embedded systems controller firmware
calibration can be done to take into account the change
in RS and RW resistance over temperature and voltage.
8k Ω 
12 kΩ 
Zero Full
Wiper Code
RBW Resistance
Scale
(0)
Scale
(256)
10 kΩ 
171 205

## Page 12

AN1080
DS01080A-page 12 © 2007 Microchip Technology Inc.
Referring to Table 3, for the 10 kΩ (typical) device, the
RAB variation over the specified voltage range is
~0.4%. The R AB variation for a given device over
temperature is ~1.4%. Other system techniques could
be used to calibrate out the effect of these variations.
A precise variable resistor can be implemented in a
system, if each system’s  digital potentiometer is
calibrated.
Table 6 shows the calculations for a 10 kΩ device, over
process. The calculation is based on an 8-bit device
that has 256 step resistors (R S) and 257 steps. When
the Wiper code value is “01”, that shows the step resis-
tance (R
S).
SUMMARY
We have discussed how the components of the resistor
network (R AB, R S, and R W) can vary over process,
voltage, temperature, and wiper code. Understanding
these variations allows you to understand the
implications in your app lication and if required use
techniques to compensate or calibrate for these
variations to optimize the application operation. 
Using some of these calibr ation techniques, it was
shown how a precise rheostat (variable resistor) can be
implemented in a system.
TABLE 6: R BW RESISTANCE AT WIPER CODE - 10 kΩ (TYPICAL) 8-BIT (256 RS’S) DEVICE
Wiper 
Code
RBW Resistance (Ω) (1) 
Comment
Min. (-20%) Typical Max (+20%)
00 0.00 0.00 0.00
01 31.25 39.0625 46.875 This indicates the R S resistance value
02 62.50 78.125 93.75
:: : :
106 3312.50 4140.625 4868.75
107 3343.75 4179.6875
5015.625 This Wiper Code makes a +20% device have the closest 
resistance to the 5 kΩ target. 
108 3375.00 4218.75 5062.50
:: : :
159 4968.75 6210.9375 7453.125
160 5000.00 6250.00 7500.00 This Wiper Code makes a -20% device have the closest 
resistance to the 5 kΩ target. 
161 5031.25 6289.0625 7546.875
:: : :
170 5312.50 6640.625 7968.75
171 5343.75 6679.6875 8015.625 This Wiper Code makes a +20% device have the closest 
resistance to the 8 kΩ target. 
172 5375.00 6718.75 8062.50
:: : :
204 6375.00 7968.75 9562.50
205 6406.25
8007.8125 9609.375 This Wiper Code makes a typical device have the closest 
resistance to the 8 kΩ target. 
206 6437.50 8046.875 9656.25
:: : :
254 7937.50 9921.875 11906.25
255 7968.75 9960.9375 11953.125
256 8000.00 10000.00 12000.00 8 k Ω resistance is the maximum resistance that is 
supported by ALL 10 kΩ (typical) devices (over process)
Note 1: RBW resistance assume a wiper resistance (RW) of 0Ω.

## Page 13

© 2007 Microchip Technology Inc. DS01080A-page 13
Information contained in this  publication regarding device
applications and the like is provided only for your convenience
and may be superseded by updates. It is your responsibility to
ensure that your application me ets with your specifications.
MICROCHIP MAKES NO REPRESENTATIONS OR
WARRANTIES OF ANY KIND WHETHER EXPRESS OR
IMPLIED, WRITTEN OR ORAL, STATUTORY OR
OTHERWISE, RELATED TO THE INFORMATION,
INCLUDING BUT NOT LIMITED TO ITS CONDITION,
QUALITY , PERFORMANCE, MERCHANTABILITY OR
FITNESS FOR PURPOSE . Microchip disclaims all liability
arising from this information and its use. Use of Microchip
devices in life support and/or safety applications is entirely at
the buyer’s risk, and the buyer agrees to defend, indemnify and
hold harmless Microchip from any and all damages, claims,
suits, or expenses resulting fr om such use. No licenses are
conveyed, implicitly or ot herwise, under any Microchip
intellectual property rights.
Trademarks
The Microchip name and logo, the Microchip logo, Accuron, 
dsPIC, KEELOQ, KEELOQ logo, microID, MPLAB, PIC, 
PICmicro, PICSTART, PRO MATE, PowerSmart, rfPIC, and 
SmartShunt are registered trademarks of Microchip 
Technology Incorporated in the U.S.A. and other countries.
AmpLab, FilterLab, Linear Active Thermistor, Migratable 
Memory, MXDEV, MXLAB, PS logo, SEEVAL, SmartSensor 
and The Embedded Control Solutions Company are 
registered trademarks of Microchip Technology Incorporated 
in the U.S.A.
Analog-for-the-Digital Age, Application Maestro, CodeGuard, 
dsPICDEM, dsPICDEM.net, dsPICworks, ECAN, 
ECONOMONITOR, FanSense, FlexROM, fuzzyLAB, 
In-Circuit Serial Programming, ICSP , ICEPIC, Mindi, MiWi, 
MPASM, MPLAB Certified logo, MPLIB, MPLINK, PICkit, 
PICDEM, PICDEM.net, PICLAB, PICtail, PowerCal, 
PowerInfo, PowerMate, PowerTool, REAL ICE, rfLAB, 
rfPICDEM, Select Mode, Smart Serial, SmartTel, Total 
Endurance, UNI/O, WiperLock and ZENA are trademarks of 
Microchip Technology Incorporated in the U.S.A. and other 
countries.
SQTP is a service mark of Microchip Technology Incorporated 
in the U.S.A.
All other trademarks mentioned herein are property of their 
respective companies.
© 2007, Microchip Technology Incorporated, Printed in the 
U.S.A., All Rights Reserved.
 Printed on recycled paper.
Note the following details of the code protection feature on Microchip devices:
• Microchip products meet the specification cont ained in their particular Microchip Data Sheet.
• Microchip believes that its family of products is one of the mo st secure families of its kind on the market today, when used in the 
intended manner and under normal conditions.
• There are dishonest and possibly illegal meth ods used to breach the code protection feature. All of these methods, to our 
knowledge, require using the Microchip products in a manner outside the operating specifications contained in Microchip’s Data 
Sheets. Most likely, the person doing so is engaged in theft of intellectual property.
• Microchip is willing to work with the customer  who is concerned about the integrity of their code.
• Neither Microchip nor any other semiconduc tor manufacturer can guarantee the security of their code. Code protection does not 
mean that we are guaranteeing the product as “unbreakable.”
Code protection is constantly evolving. We at Microchip are committed to continuously improving the code protection features of our
products. Attempts to break Microchip’s code protection feature may be a violation of the Digital Millennium Copyright Act. If such acts
allow unauthorized access to your software or other copyrighted work, you may have a right to sue for relief under that Act.
Microchip received ISO/TS-16949:2002 certification for its worldwide 
headquarters, design and wafer fabrication facilities in Chandler and 
Tempe, Arizona, Gresham, Oregon and Mountain View, California. The 
Company’s quality system processes and procedures are for its PIC
® 
MCUs and dsPIC® DSCs, KEELOQ® code hopping devices, Serial 
EEPROMs, microperipherals, nonvolatile memory and analog 
products. In addition, Microchip’s quality system for the design and 
manufacture of development systems is ISO 9001:2000 certified.

## Page 14

DS01080A-page 14 © 2007 Microchip Technology Inc.
AMERICAS
Corporate Office
2355 West Chandler Blvd.
Chandler, AZ  85224-6199
Tel:  480-792-7200  
Fax:  480-792-7277
Technical Support: 
http://support.microchip.com
Web Address: 
www.microchip.com
Atlanta
Duluth, GA 
Tel: 678-957-9614 
Fax: 678-957-1455
Boston
Westborough, MA  
Tel: 774-760-0087 
Fax: 774-760-0088
Chicago
Itasca, IL  
Tel: 630-285-0071 
Fax: 630-285-0075
Dallas
Addison, TX 
Tel: 972-818-7423  
Fax: 972-818-2924
Detroit
Farmington Hills, MI 
Tel: 248-538-2250
Fax: 248-538-2260
Kokomo
Kokomo, IN 
Tel: 765-864-8360
Fax: 765-864-8387
Los Angeles
Mission Viejo, CA 
Tel: 949-462-9523  
Fax: 949-462-9608
Santa Clara
Santa Clara, CA 
Tel: 408-961-6444
Fax: 408-961-6445
Toronto
Mississauga, Ontario, 
Canada
Tel: 905-673-0699  
Fax:  905-673-6509
ASIA/PACIFIC
Asia Pacific Office
Suites 3707-14, 37th Floor
Tower 6, The Gateway
Habour City, Kowloon
Hong Kong
Tel: 852-2401-1200
Fax: 852-2401-3431
Australia - Sydney
Tel: 61-2-9868-6733
Fax: 61-2-9868-6755
China - Beijing
Tel: 86-10-8528-2100 
Fax: 86-10-8528-2104
China - Chengdu
Tel: 86-28-8665-5511
Fax: 86-28-8665-7889
China - Fuzhou
Tel: 86-591-8750-3506  
Fax: 86-591-8750-3521
China - Hong Kong SAR
Tel: 852-2401-1200  
Fax: 852-2401-3431
China - Qingdao
Tel: 86-532-8502-7355
Fax: 86-532-8502-7205
China - Shanghai
Tel: 86-21-5407-5533  
Fax: 86-21-5407-5066
China - Shenyang
Tel: 86-24-2334-2829
Fax: 86-24-2334-2393
China - Shenzhen
Tel: 86-755-8203-2660 
Fax: 86-755-8203-1760
China - Shunde
Tel: 86-757-2839-5507 
Fax: 86-757-2839-5571
China - Wuhan
Tel: 86-27-5980-5300
Fax: 86-27-5980-5118
China - Xian
Tel: 86-29-8833-7250
Fax: 86-29-8833-7256
ASIA/PACIFIC
India - Bangalore
Tel: 91-80-4182-8400 
Fax: 91-80-4182-8422
India - New Delhi
Tel: 91-11-4160-8631
Fax: 91-11-4160-8632
India - Pune
Tel: 91-20-2566-1512
Fax: 91-20-2566-1513
Japan - Yokohama
Tel: 81-45-471- 6166  
Fax: 81-45-471-6122
Korea - Gumi
Tel: 82-54-473-4301
Fax: 82-54-473-4302
Korea - Seoul
Tel: 82-2-554-7200
Fax: 82-2-558-5932 or 
82-2-558-5934
Malaysia - Penang
Tel: 60-4-646-8870
Fax: 60-4-646-5086
Philippines - Manila
Tel: 63-2-634-9065
Fax: 63-2-634-9069
Singapore
Tel:  65-6334-8870
Fax: 65-6334-8850
Taiwan - Hsin Chu
Tel: 886-3-572-9526
Fax: 886-3-572-6459
Taiwan - Kaohsiung
Tel: 886-7-536-4818
Fax: 886-7-536-4803
Taiwan - Taipei
Tel: 886-2-2500-6610  
Fax: 886-2-2508-0102
Thailand - Bangkok
Tel: 66-2-694-1351
Fax: 66-2-694-1350
EUROPE
Austria - Wels
Tel: 43-7242-2244-39
Fax: 43-7242-2244-393
Denmark - Copenhagen
Tel: 45-4450-2828 
Fax: 45-4485-2829
France - Paris
Tel: 33-1-69-53-63-20  
Fax: 33-1-69-30-90-79
Germany - Munich
Tel: 49-89-627-144-0 
Fax: 49-89-627-144-44
Italy - Milan 
Tel: 39-0331-742611  
Fax: 39-0331-466781
Netherlands - Drunen
Tel: 31-416-690399 
Fax: 31-416-690340
Spain - Madrid
Tel: 34-91-708-08-90
Fax: 34-91-708-08-91
UK - Wokingham
Tel: 44-118-921-5869
Fax: 44-118-921-5820
WORLDWIDE SALES AND SERVICE
12/08/06
