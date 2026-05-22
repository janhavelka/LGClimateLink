# Optimizing Digital Potentiometer Circuits to Reduce Absolute and Temperature Variations - Extracted Text

- Source PDF: `../Microchip_AN691_Optimizing_Digital_Potentiometer_Circuits.pdf`
- Manufacturer URL: https://ww1.microchip.com/downloads/en/Appnotes/00691a.pdf
- Extraction date: 2026-05-09
- Page count: 12
- SHA256: `37A312E067C68BDC2167892721A0E7A6E2C97B879E74CD1AEB6725459B565EFA`
- Notes: Raw text extracted with pypdf. Tables, equations, and figures may require checking against the source PDF.

## Page 1

  2001 Microchip Technology Inc. DS00691A-page 1
M AN691
INTRODUCTION
Mechanical potentiometers are typically used to adjust
system reference levels, gain errors and offset errors.
Digital potentiometers can be used for the same func-
tions while offering the added capability of digital
adjustment control. Devices, such as Microchip’s
MCP41XXX and MCP42XXX digital potentiometer
families, can be used much like a mechanical potenti-
ometer in that they have three resistive terminals for
the single versions (MCP41010, MCP41050, and
MCP41100) and six resistive terminals for the dual ver-
sions (MCP42010, MCP42050, and MCP42100) as
illustrated in Figure 1.
The two modes that a potentiometer can be configured
in are the Rheostat mode and Voltage Divider mode.
When used in the Rheostat mode, the wiper (terminal
P
W), is shorted to either the P A or P B terminal of the
device. This configuration is shown in Figure 2. When
a digital potentiometer is used in the Voltage Divider
mode (Figure 2.b) all three terminals are connected to
differing nodes in the circuit.
In both of these configurations, the digital potentiome-
ter will have a nominal resistance and temperature
coefficient error that may affect the overall application
unless precautions are taken. In this application note,
circuit ideas will be presented that use the necessary
design techniques to mitigate these errors, conse-
quently optimizing the performance of the digital poten-
tiometer.
FIGURE 1: The operation of the digital potentiometer as compared to the mechanical potentiometer is functionally
the same. The adjustment of the digital potentiometer is done with a serial code to the device. Although the mechanical
potentiometer provides simplicity, the digital potentiometer provides flexibility and reliability.
Author: Bonnie C. Baker,
Microchip Technology Inc.
RDAC1
SCK
SOSI
Decode
Logic
16-bit Shift Register
PA0 PB0
RDAC2
Data Register 1
PA1 PB1PW1
CS
RS
SHDN
D7 D0
Data Register 0
D7 D0D7 D0
Mechanical
PA PBPW
Potentiometer
Model
Digital
PA PBPW
Potentiometer
Model
PW0
Dual Digital Potentiometer
Optimizing Digital Potentiometer Circuits to Reduce 
Absolute and Temperature Variations

## Page 2

AN691
DS00691A-page 2   2001 Microchip Technology Inc.
Rheostat Mode Operation and Specifications
In the Rheostat mode, either terminal PA or PB are con-
nected to the wiper terminal as shown in Figure 2.a. In
this mode, the output resistance is digitally adjusted
from the maximum nominal value, minus one LSB,
down to zero ohms. The nominal resistance of the ele-
ment in the Rheostat mode is calculated with the fol-
lowing formulas:
or 
where:
R
AW is the resistance between pin A and pin W of
the digital potentiometer.
RAB is the nominal resistance across the entire
potentiometer, from pin A to pin B.
RBW is the resistance between pin B and pin W of
the digital potentiometer.
n is the number of digital potentiometer bits. For
the MCP4XXXX family of potentiometers, the
number of bits is eight.
Dn is the digital code in decimal form that is used
to program the digital potentiometer. With the
MCP4XXXX   8-bit digital potentiometers the pro-
grammable digital code ranges from 0 to 2
8 - 1 or
255.
RW is the parasitic resistance through the wiper.
As summarized in the table in Figure 2, the nominal
resistance of the digital potentiometer varies, depend-
ing on the device selected. Additionally, the part to part
variation of the nominal resistance is specified to be
within a given percentage. For example, the nominal
resistance of the MCP4X010 is 10 kΩ  ±20%. The resis-
tance variation of these digital potentiometers is prima-
rily dependent on the process variation of the sheet-rho
of a diffused p-silicon layer and the on-resistance of the
internal switches.
The temperature variance of the digital potentiometers
element is also shown in Figure 2. For instance, the
variance of the MCP41010 (10 kΩ ) digital potentiome-
ter is 800 ppm/ °C (typical). With this specification, the
expected change of the total resistance of the
MCP41010 is from 10 kΩ  at 25°C to 9.52 kΩ  at 85°C.
FIGURE 2:
The resistive elements of the digital potentiometer can be configured in (a.) the Rheostat mode or (b.) the Voltage
Divider mode. Each mode has its own set of performance specifications.
RBW
RAB DN()
N2
------------------------ RW+=
RAW
RAB 2
N
DN–

2N
---------------------------------------- RW+=
a. Rheostat Mode b. Voltage Divider Mode
Device
Nominal 
RAB 
Resistance 
(typ)
RAB Change 
with 
Temperature 
(typ)
Nominal
Resistance 
Match (typ)
RA, RB
Relative 
Accuracy INL 
(typ)
Tempco 
Variance 
Between RA 
and RB (typ)
Code to Code
Variance
DNL (typ)
MCP41010
 (single)
10 KΩ  ±20% 800 ppm/°C ----- ±0.25 LSB 1% ±0.25 LSB
MCP42010 (dual) 10 KΩ  ±20% 800 ppm/ °C 0.2% ±0.25 LSB 1% ±0.25 LSB
MCP41050 
(single)
50 KΩ  ±30% 800 ppm/ °C ----- ±0.25 LSB 1% ±0.25 LSB
MCP42050 (dual) 50 KΩ  ±30% 800 ppm/ °C 0.2% ±0.25 LSB 1% ±0.25 LSB
MCP41100
 (single)
100 KΩ  ±30% 800 ppm/ °C ----- ±0.25 LSB 1% ±0.25 LSB
MCP42100 (dual) 100 KΩ  ±30% 800 ppm/ °C 0.2% ±0.25 LSB 1% ±0.25 LSB
PW
PA PB
PA
PB PW

## Page 3

  2001 Microchip Technology Inc. DS00691A-page 3
AN691
Digital Potentiometer Circuits Configured in the 
Rheostat Mode
The level of nominal resistive matching that is shown in
Figure 2 can be acceptable for some applications.
However, if a degree of precision is desired, the dual
potentiometer can be used to an advantage in the
Rheostat mode. With the dual digital potentiometer, the
nominal resistances between the two potentiometers
are ratio matched to a very small percentage as shown
in Figure 2. For instance, the matching of the two resis-
tive potentiometer elements in the MCP42010 (dual,
10 kΩ ) is guaranteed to be less than ±0.2% (typ). This
close relationship between the two resistor arrays can
be used to a distinct advantage.
One circuit that takes advantage of the relationship
between the two potentiometers in the dual,
MCP42100 is shown in Figure 3.
FIGURE 3: The digital potentiometers in this
differential amplifier can be programmed to change
the gain of the circuit as well as enhance the common-
mode rejection. The common-mode rejection of this
circuit is fairly immune to temperature changes.
In Figure 3, the arrangement of the resistors around an
operational amplifier is called the difference amplifier or
op amp subtractor. The DC transfer function of this cir-
cuit is equal to:
If R
1/R2 is equal to R3/R4, the system gain of this circuit
equals:
The fact that R 1/R2 is equal to R 3/R4 simplifies the
mathematics in this system considerably. Since the
gain of both input signals are the same, the common-
mode voltage (CMV) of the two signals is conveniently
subtracted from the output results.
Ideally, CMV changes are rejected by this circuit. The
calculated common-mode rejection (CMR) error that is
attributed to resistor mismatches in this circuit is equal
to:
where (% of mismatch error) is the mismatch in the
equation R
1/R2 = R3/R4.
An example of the impact of this error is demonstrated
with a 12-bit, 5V system, where the gain of the circuit is
100V/V, the common-mode voltage ranges 0 to 5V and
the matching error is ±0.2%. Using the formula above,
the contributed error of this type of common-mode
excursion is equal to 0.2 mV. This voltage is five times
less than 1 LSB.
Adjustable gain is easily implemented by making the
discrete resistors equal (R
1=R3) and changing both
potentiometers together as desired. Although, any dig-
ital potentiometer can be used in the R
2 and R4 position
in this circuit, the higher the nominal value of the digital
potentiometer, the wider the adjustable gain range will
be.
In a single supply environment, a voltage reference is
used to center the output signal between ground and
the power supply. This voltage is represented in this cir-
cuit as V
REF. The V REF circuit function can be imple-
mented with a precision voltage reference or with an
adjustable voltage reference circuit that uses a digital
potentiometer as shown in Figures 5, 6 and 7. The
adjustable voltage reference designs offer the flexibility
of removing offset system errors.
An alternative to the circuit shown in Figure 3 is illus-
trated in Figure 4. In this circuit configuration, the differ-
ential inputs are high impedance and the output is
differential. There are three resistors used in this cir-
cuit, two of which are 1/2 of a dual potentiometer.
PA
VIN -
VOUT
PA
VIN +
R1=1 KΩ 
R4 (1/2 of MCP42100)
R2 (1/2 of MCP42100)
R3=1 KΩ
PB
PB
PW
+
-
PW
VREF
VOUT
V1R4 R1 R2+()
R3 R4+() R1()-------------------------------------------V2
R2
R1
-------


–
VREF R3
R1 R2+()
R3 R4+() R1()----------------------------------------+=
VOUT V1 V2–()
R2
R1
-------


 VREF+=
CMR 100
1
R1
R2
-------+



% of mismatch error-----------------------------------------------------=

## Page 4

AN691
DS00691A-page 4   2001 Microchip Technology Inc.
FIGURE 4: This differential in and differential out
circuit uses two digital potentiometers in the Rheostat
mode. When the two digital potentiometers are set to
be equal, the gains on the two input signals are equal.
If R
2 = R3, the transfer function of this circuit is:
This flexible gain circuit uses the matching of nominal
resistance and thermal shifts of the dual potentiometer
to an advantage.
Voltage Divider Mode: Operation and 
Specifications
In the Voltage Divider mode shown in Figure 2, all three
terminals to the potentiometer are connected to sepa-
rate nodes in the circuit. In this mode, the total resis-
tance of the device is separated into two resistors. The
first being the resistance from terminal P
B to the wiper
(PW) and the second is between terminal P A to the
wiper. The relationship between these two resistors is
equal to:
where:
RB is equal to the resistance between the PB 
terminal and PW terminal minus the wiper 
resistance.
RA is equal to the resistance between the PA 
terminal and PW terminal minus the wiper 
resistance.
There is a third resistance from the digital potentiome-
ters element to the wiper terminal. This resistance is
called the wiper resistance or R W. If the wiper of the
digital potentiometer is followed by a high impedance
node, errors caused by the wiper resistance are elimi-
nated.
The absolute value of these resistances will still vary
between ±20% and ±30% (depending on the device
used), however as shown in the table in Figure 2, the
ratio between the two elements will be much lower. In
the case of the MCP4X010, the maximum mismatch
error between R
B and RA is ±0.098% (DNL specifica-
tion).
The related temperature performance of these two
resistors is also lower than the absolute temperature
behavior at a typical 1 ppm/°C. Since the resistive ele-
ments of R
B and RA are manufactured with the same
material on the same chip, the ratio of the thermal
changes with temperature is considerably better as
compared to the single resistive element in the Rheo-
stat mode.
Digital Potentiometer Circuits Configured in the 
Voltage Divider Mode
The digital potentiometer can be used very effectively
in a variety of circuits when it is configured in the Volt-
age Divider mode. All of the following circuits take
advantage of the resistive ratio matching of the two
resistive elements (R
B and RA).
Voltage Reference Circuits
One form of offset voltage adjustment is implemented
with a voltage reference. This type of adjustment usu-
ally compensates for all of the system offset errors in
the signal path. 
In Figure 5, a digital potentiometer is used to design an
adjustable voltage reference. In Figure 5.a, the potenti-
ometer is placed between the positive power supply
and ground. The output voltage of the adjustable refer-
ence is equal to:
The resolution of this reference circuit is dependent on
the number of programmable bits of the digital potenti-
ometer and the value of V
DD. When using any of the 8-
bit digital potentiometers from Microchip and a 5V sup-
ply, the nominal LSB size would be 19.53 mV.
+
-
+
- VOUT1
VIN2
VIN1
PA
R1
R2 (1/2 of a dual Digital Potentiometer)
VOUT2
PB
PW
PA
R3 (1/2 of a dual Digital Potentiometer)
PB
PW
VOUT1 VOUT2–() VIN1 VIN2–() 1
2R2
R1
-----------+



=
RB RAB
Dn()
n2
------------=
RA RAB
2n Dn–

2n--------------------------=
VREF
VDD RPOT B–
RPOT AB–
-----------------------------------------=

## Page 5

  2001 Microchip Technology Inc. DS00691A-page 5
AN691
FIGURE 5: A digitally adjustable reference can be
designed using the power supply across the digital
potentiometer (a). Higher accuracy can be achieved
by using additional resistors (b) in series with the
digital potentiometer.
In this circuit, the operational amplifier acts to isolate or
buffer the digital potentiometer resistance from follow-
ing stages.
The absolute accuracy and over temperature perfor-
mance of the voltage presented to the input of the
amplifier is dependent on the matching of the digital
potentiometer resistive elements as well as the stability
of the power supply.
As an example of the effects of the digital potentiome-
ter errors, the MCP4X010 (10 kΩ  digital potentiometer)
would perform with an absolute accuracy less than
±0.25 LSB (typ) or ±3.9065 mV at 25°C. Over temper-
ature, the output voltage would typically vary 1% due to
resistance matching. This translates into a typical vari-
ance over temperature (-40 °C to +85 °C) of 1.172 mV
or ±0.585 mV. Adding this to the error at room temper-
ature, the total possible error becomes ±4.99 mV. In
this example, it is assumed that the power supply is a
stable 5V.
If a smaller LSB size is required for an adjustable volt-
age reference that has the full dynamic range of the
power supply voltage, the circuit in Figure 6 can be
used.
FIGURE 6: Three digital potentiometers in
combination with a dual amplifier can be configured for
a wide dynamic range, adjustable voltage reference
that has an ideal LSB size of V
DD / 22n, where n is the
number of digital potentiometer bits.
In this circuit, the wiper voltage of R POT1 is buffered
with A1, a single supply, CMOS amplifier and RPOT2 is
buffered with A2. The dynamic range of the output of A1
and A 2 is equal to approximately (GND+50 mV) to
(VDD−1.2V). The positive output swing range is prima-
rily restricted by the amplifiers maximum input common
mode voltage. The theoretical LSB size of the voltages
at V
REF-A and VREF-B are equal to VDD/2n or 19.53 mV. 
The voltage difference of V REF-A and V REF-B is
impressed across RPOT3. The difference of these volt-
ages are then divided again by the third digital potenti-
ometer to have an ideal LSB size equal to:
The configuration in Figure 6 provides an theoretical
output resolution of 16 bits. When V
DD is equal to 5V,
the theoretical LSB size is 76.29 µV.
VREF A–
VDD RPOT B–()
RPOT AB–()----------------------------------------------=
+
MCP606
VDD
RA
RB
RPOT
VREF-A
-
VDD
a.)
+
MCP606
VDD
RA
RB
RPOT
VREF-B
-
VDDR2
R3
b.) VREF B–
VDD RPOT B– R3+()
R2 RPOT AB– R3++()-----------------------------------------------------------------=
-
½ MCP602
VDD = 5V
RA
RB
RPOT1
VREF-A
+
RA
RB
-
½ MCP602
VDD
RA
RB
RPOT2
VREF-B
+
VREF-C
RPOT3
A2
A1
VREF A–  and VREF B–
VDD RPOTx B–()
RPOTx AB–()-------------------------------------------------=
VREF C–
VREF A– VREF B––() RPOT3 B–()
RPOT3 AB–()------------------------------------------------------------------------------------------------------=
VREF C–
VDD 2n⁄()
2n------------------------------=
VREF C–
VDD
22n-------------=

## Page 6

AN691
DS00691A-page 6   2001 Microchip Technology Inc.
The value of the output of this precision adjustable ref-
erence is compromised by the absolute matching resis-
tance and temperature coefficient of the digital
potentiometers.
In the error analysis of this circuit, it can quickly be
found that at 25 °C, the nominal errors of the digital
potentiometer have the highest potential to create the
largest errors. This in shown in Table 1.
The errors of the first stage (including the amplifiers)
are divided down by the second stage. Given this error
analysis, the circuit in Figure 6 is accurate to 13.3 bits
or ±0.057 mV. This analysis does not take into account
variations in V
DD over temperature.
Another technique that can be used to design a preci-
sion adjustable voltage reference is shown in Figure 7.
FIGURE 7: A precision adjustable reference can be
configured using a precision reference that is not
adjustable along with a digital potentiometer. The
value of R
1 is set so that the current through the
LM4040 does not go below its minimum operating
current. 
In this circuit, the variability of the power supply is sta-
bilized with a precision voltage reference. Since the
digital potentiometer is configured in the Voltage
Divider mode, the errors at the output of the amplifier is
similar to the errors discussed in Figure 5. The only dif-
ference being that the power supply is replaced with a
precision reference. This configuration is often used
when the digital potentiometer is used as a DAC.
Offset Adjustment Circuits
Offset adjustment can be implemented in the analog
circuit by injecting a voltage into the signal path with a
simple voltage divider or a complete adjustable voltage
reference.
In Figures 8 and 9, a digital potentiometer is used to
change the offset errors of a simple amplifier circuit.
FIGURE 8: A high resolution offset adjust circuit is
implemented in this standard inverting amplifier
configuration with the addition of a digital
potentiometer, R
3, R4 and R5.
In this circuit, the amplifier is configured in a inverting
configuration. The transfer function for the input signal,
V
IN is equal to:
An offset voltage is injected with the same voltage
divider that was used in the circuit in Figure 5.b. The
transfer function of the offset voltage, VOFF is:
With the resistor values shown in the figure, the gain on
the VIN is 10V/V and the gain on V OFF is 0.1V/V. With
VDD = 5V, the LSB size of the offset adjust circuitry is
651 µV.
With this configuration, the nominal errors and over
temperature errors that are generated by the digital
potentiometer is 10X smaller than the errors discussed
in Figure 5.b.
Another method of implementing an analog offset
adjustment with a digital potentiometer is shown in
Figure 9.
Room 
Temp.
Over -40°C
to 85°C 
range
RPOT1 
(±0.25 LSB typical error)
±0.019 mV ±0.003 mV
RPOT2 
(±0.25 LSB typical error)
±0.019 mV ±0.003 mV
RPOT3 
(±0.25 LSB typical error)
±0.019 mV ±0.003 mV
Total typical error
at VREF-C
±0.057 mV ±0.009 mV
TABLE 1: This table shows the nominal and
temperature errors effecting adjustable voltage
reference shown in Figure 6. Calculations assume A
1
and A 2 are ideal amplifiers, the MCP4X010 digital
potentiometers are used and V DD = 5V. All values are
referred to the output, VREF-C.
VZ = 2.5V ±2.0%
LM4040-2.5
(Precision
Voltage 
Reference)
+
MCP606
VDD
RA
RB
RPOT
VREF
-
R1
or
DAC
Output
+
-
VIN
VOUT
R3 = 100 KΩ
R4 =
MCP41010
RBRA
R1 <10 KΩ R2 = 10 KΩ
VDD
VOFF
10 KΩ
10 KΩ
MCP601VDD
R5 =
10 KΩ
RW
10 KΩ
VOUT V– IN
R2
R1
-------



VDD
2-------------+=
VOUT V– OFF
R2
R3
-------



=

## Page 7

  2001 Microchip Technology Inc. DS00691A-page 7
AN691
FIGURE 9: A lower resolution offset adjust circuit
using a digital potentiometer can be used to adjust
large system offsets.
In this circuit, the gain of the signal is equal to:
And the gain of the offset adjust circuitry is equal to:
The offset adjustment circuit used in this application
has the same topology as the circuit in Figure 5.b. Con-
sequently, the errors due to this configuration is consis-
tent with previous discussions.
Gain Adjust Amplifier Circuits
Circuit gain errors can compromise the analog dynamic
range of a circuit. These types of errors can be easily
calibrated out of the system digitally with the microcon-
troller, however, the analog dynamic range is never
fully utilized. Consequently, analog gain adjustments
are done where the full dynamic analog range is
needed.
An example of an amplifier circuit that has an adjust-
able positive (noninverted) gain is shown in Figure 10.
FIGURE 10: An amplifier circuit designed with an
adjustable noninverting gain.
In this circuit, the transfer function is:
The adjustable gain is implemented with the digital
potentiometer, R
POT. Digital potentiometers that have
higher nominal values are best suited for this circuit.
Higher value resistances minimize the error that is con-
tributed by the source resistance of V
IN. 
The maximum gain is equal to:
Using the values of resistors in Figure 10:
Gain (max) = (1 + 100kΩ /1kΩ ) − (28 −1)/28
= 101.996V/V
At room temperature, the digital potentiometer ’s DNL
error effects the circuit gain accuracy with gains that
are lower 10% of the range (assuming DNL (max) =
±0.25 LSB). This relationship is shown graphically in
Figure 11.
+
-
VIN
VOUT
10  KΩ
10 KΩ
MCP41010
R1<10 KΩ R2=10 KΩ
RBRA
VOUT V– IN
R2
R1
-------


=
VOUT VDD RPOT B–
1
R2
R1
-------+



RPOT AB– R2 R3++()-----------------------------------------------------------------=
+
-
RA
RB
VIN
R3=100 KΩ
RPOT1
MCP41100
VOUT
R2=10 KΩ
VOUT VIN
1
R3
R2
-------+



RPOT1 B–
RPOT1 AB–
------------------------------------



-------------------------------------------=
Gain (max) 1
R3
R2
-------+



2n 1–
2n----------------


–
=

## Page 8

AN691
DS00691A-page 8   2001 Microchip Technology Inc.
FIGURE 11: For the circuit in Figure 10, the gain vs.
digital code is linear. The maximum possible gain error
is logarithmic, decreasing with higher digital
potentiometer codes. 
In terms of temperature effects on the digital potentiom-
eter in this configuration, the changes of R
A and R B
over temperature track at a rate of 800 ppm/ °C (typ).
Since these elements are configured as a mathemati-
cal ratio, this error is cancelled. The variance between
the two elements over temperature is 1% (typ). This
variance will be directly translated into gain error over
temperature.
Another amplifier gain circuit that uses a digital poten-
tiometer is shown in Figure 12. In this circuit, the ampli-
fier circuit executes an inverting adjustable gain
function.
FIGURE 12: This amplifier circuit uses a digital
potentiometer to implement an adjustable inverting
gain.
The circuit transfer function is:
With this circuit, the gain function versus digital poten-
tiometer code is nonlinear as shown in Figure 13. 
FIGURE 13: The transfer function of V
OUT to V IN of
the circuit shown in Figure 12 has a nonlinear
response over the code span of the digital
potentiometer. This phenomena creates a circuit that
gains the input signal below digital potentiometer
codes of 128 and attenuates the signal with codes
above 128.
The nominal accuracy of this gain cell is minimized
because the two sides of the digital potentiometer are
ratioed in the circuit transfer function. Any gain error at
room temperature is due to the DNL error of the digital
potentiometer. The maximum effects of the error is
shown graphically in Figure 13.
In terms of temperature effects on the digital potentiom-
eter in this configuration, R
A and RB are configured as
a mathematical ratio in the transfer function. This can-
cels the change in the 800 ppm/ °C (typ) resistive ele-
ment. The variance between the two elements over
temperature is 1% (typ). This variance will be directly
translated into gain error over temperature.
The circuits in Figure 10 and Figure 12 can be com-
bined to build an adjustable gain difference amplifier
much like the circuit shown in Figure 3. This configura-
tion is shown Figure 14.
VIN
+
-
MCP601
VREF
RPOT2
RA RB
VDD
VOUT VREF
RPOT2 B–
RPOT 2 A–
-------------------------------1+



VIN–
RPOT2 B–
RPOT2 A–
-------------------------------



=
VOUT VIN
RPOT2 A–
R4B–
-------------------------
 VREF
RPOT2 A–
RPOT2 B–
-------------------------
 1++=

## Page 9

  2001 Microchip Technology Inc. DS00691A-page 9
AN691
FIGURE 14: A difference amplifier that has stable
resistor matching and temperature coefficients.
If the digital code setting for R POT1 and R POT2 are
equal, the transfer function for this circuit is:
The gain of this circuit (VOUT/(V1-V2)) versus the digital
potentiometer code is shown graphically in Figure 15.
FIGURE 15: The gain of circuit in Figure 14 is greater
than one with digital code settings larger than 128 and
between zero and one for digital code settings less
than 128. The gain error, due to typical DNL errors, is
less than 1% between 28 and 229.
The temperature performance of this circuit is signifi-
cantly improved over the circuit shown in Figure 3
because all of the resistors in this circuit are elements
of the digital potentiometers.
Once again, the common-mode rejection (CMR) error
that is attributed to resistor mismatches in this circuit is
equal to:
where (% of mismatch error) is the mismatch in the
equation R
1/R2 = R3/R4.
CONCLUSION
The digital potentiometer has entered the market with
clear advantages over the mechanical potentiometer.
Its programmability allows to change the offset, gain
and voltage references reliably as well as on the fly.
The effects of variances of the absolute resistances
and temperature drifts can be minimized if good circuit
design techniques are used.
RA
RB RPOT1
VIN+
VREF
VIN-
RPOT2
RA RB
VDD
+
-
MCP601 VOUT
VOUT V1 V2–()
RPOTX B–
RXA–
--------------------------
 VREF+=
CMR 100
1 R1
R2
-------+

% of mismatch error-----------------------------------------------------=

## Page 10

AN691
DS00691A-page 10   2001 Microchip Technology Inc.
NOTES:

## Page 11

 2001 Microchip Technology Inc. DS00691A-page 11
AN691
“All rights   reserved.   Copyright ©  2001,   Microchip 
Technology Incorporated, USA. Information contained
in this publication regarding device applications and the
like is intended through suggestion only and may be
superseded by updates. No representation or warranty
is   given   and   no   liability   is   assumed by  Microchip 
Technology Incorporated with respect to the accuracy
or use of such information, or infringement of patents or
other intellectual property rights arising from such use
or otherwise. Use of Microchip’s products as critical
components in life support systems is not authorized
except with express written approval by Microchip. No
licenses are conveyed, implicitly or otherwise, under
any intellectual property rights. The Microchip logo and
name   are    registered    trademarks    of    Microchip 
Technology Inc. in the U.S.A. and other countries. All
rights reserved. All other trademarks mentioned herein
are the property of their respective companies. No
licenses are conveyed, implicitly or otherwise, under
any intellectual property rights.”
Trademarks
The      Microchip     name,     logo,     PIC,     PICmicro, 
PICMASTER, PICSTART, PRO MATE, K
EELOQ,
SEEVAL,    MPLAB    and    The    Embedded    Control 
Solutions Company are registered trademarks of
Microchip Technology Incorporated in the U.S.A. and
other countries.
Total Endurance, ICSP , In-Circuit Serial Programming,
FilterLab, MXDEV, microID, FlexROM, fuzzyLAB,
MPASM,     MPLINK,    MPLIB,    PICDEM,    ICEPIC, 
Migratable Memory, FanSense, ECONOMONITOR,
Select Mode    and    microPort    are    trademarks   of
Microchip Technology Incorporated in the U.S.A.
Serialized   Quick   Term   Programming   (SQTP)  is a 
service mark of Microchip Technology Incorporated in
the U.S.A.
All other trademarks mentioned herein are property of
their respective companies.
© 2001, Microchip Technology Incorporated, Printed in
the U.S.A., All Rights Reserved.
Microchip received QS-9000 quality system 
certification for its worldwide headquarters, 
design and wafer fabrication facilities in 
Chandler and Tempe, Arizona in July 1999. The 
Company’s quality system processes and 
procedures are QS-9000 compliant for its 
PICmicro® 8-bit MCUs, KEELOQ® code hopping 
devices, Serial EEPROMs and microperipheral 
products. In addition, Microchip’s quality 
system for the design and manufacture of 
development systems is ISO 9001 certified.

## Page 12

Information contained in this publication regarding device applications and the like is intended through suggestion only and ma y be superseded by
updates. It is your responsibility to ensure that your application meets with your specifications. No representation or warrant y is given and no liability is
assumed by Microchip Technology Incorporated with respect to the accuracy or use of such information, or infringement of patent s or other intellectual
property rights arising from such use or otherwise. Use of Microchip’s products as critical components in life support systems is not authorized except with
express written approval by Microchip. No licenses are conveyed, implicitly or otherwise, except as maybe explicitly expressed herein, under any intellec-
tual property rights. The Microchip logo and name are registered trademarks of Microchip Technology Inc. in the U.S.A. and othe r countries. All rights
reserved. All other trademarks mentioned herein are the property of their respective companies.
DS00691A-page 12  2001 Microchip Technology Inc.
All rights reserved.   © 2001 Microchip Technology Incorporated.  Printed in the USA.  5/01  Printed on recycled paper.
M
AMERICAS
Corporate Office
2355 West Chandler Blvd.
Chandler, AZ  85224-6199
Tel:  480-792-7200  Fax:  480-792-7277
Technical Support: 480-792-7627
Web Address: http://www.microchip.com
Rocky Mountain
2355 West Chandler Blvd.
Chandler, AZ  85224-6199
Tel:  480-792-7966  Fax:  480-792-7456
Atlanta
500 Sugar Mill Road, Suite 200B
Atlanta, GA  30350
Tel: 770-640-0034  Fax: 770-640-0307
Austin
Analog Product Sales
8303 MoPac Expressway North
Suite A-201
Austin, TX  78759
Tel: 512-345-2030  Fax: 512-345-6085
Boston
2 Lan Drive, Suite 120
Westford, MA  01886
Tel: 978-692-3848  Fax: 978-692-3821
Boston
Analog Product Sales
Unit A-8-1 Millbrook Tarry Condominium
97 Lowell Road
Concord, MA  01742
Tel: 978-371-6400  Fax: 978-371-0050
Chicago
333 Pierce Road, Suite 180
Itasca, IL  60143
Tel: 630-285-0071 Fax: 630-285-0075
Dallas
4570 Westgrove Drive, Suite 160
Addison, TX 75001
Tel: 972-818-7423  Fax: 972-818-2924
Dayton
Two Prestige Place, Suite 130
Miamisburg, OH 45342
Tel: 937-291-1654  Fax: 937-291-9175
Detroit
Tri-Atria Office Building 
32255 Northwestern Highway, Suite 190
Farmington Hills, MI  48334
Tel: 248-538-2250 Fax: 248-538-2260
Los Angeles
18201 Von Karman, Suite 1090
Irvine, CA  92612
Tel: 949-263-1888  Fax: 949-263-1338
Mountain View
Analog Product Sales
1300 Terra Bella Avenue
Mountain View, CA  94043-1836
Tel: 650-968-9241  Fax: 650-967-1590
New York
150 Motor Parkway, Suite 202
Hauppauge, NY  11788
Tel: 631-273-5305  Fax: 631-273-5335
San Jose
Microchip Technology Inc.
2107 North First Street, Suite 590
San Jose, CA  95131
Tel: 408-436-7950  Fax: 408-436-7955
Toronto
6285 Northam Drive, Suite 108
Mississauga, Ontario L4V 1X5, Canada
Tel: 905-673-0699  Fax:  905-673-6509
ASIA/PACIFIC
Australia
Microchip Technology Australia Pty Ltd
Suite 22, 41 Rawson Street
Epping 2121, NSW
Australia
Tel: 61-2-9868-6733 Fax: 61-2-9868-6755
China - Beijing
Microchip Technology Beijing Office
Unit 915
New China Hong Kong Manhattan Bldg.
No. 6 Chaoyangmen Beidajie 
Beijing, 100027, No. China
Tel: 86-10-85282100 Fax: 86-10-85282104
China - Shanghai
Microchip Technology Shanghai Office
Room 701, Bldg. B
Far East International Plaza
No. 317 Xian Xia Road
Shanghai, 200051
Tel: 86-21-6275-5700  Fax: 86-21-6275-5060
Hong Kong
Microchip Asia Pacific
RM 2101, Tower 2, Metroplaza
223 Hing Fong Road
Kwai Fong, N.T., Hong Kong
Tel: 852-2401-1200  Fax: 852-2401-3431
India
Microchip Technology Inc.
India Liaison Office
Divyasree Chambers
1 Floor, Wing A (A3/A4)
No. 11, O’Shaugnessey Road
Bangalore, 560 025, India
Tel: 91-80-2290061 Fax: 91-80-2290062
Japan
Microchip Technology Intl. Inc.
Benex S-1 6F
3-18-20, Shinyokohama
Kohoku-Ku, Yokohama-shi
Kanagawa, 222-0033, Japan
Tel: 81-45-471- 6166  Fax: 81-45-471-6122
ASIA/PACIFIC (continued)
Korea
Microchip Technology Korea
168-1, Youngbo Bldg. 3 Floor
Samsung-Dong, Kangnam-Ku
Seoul, Korea
Tel: 82-2-554-7200  Fax: 82-2-558-5934
Singapore
Microchip Technology Singapore Pte Ltd.
200 Middle Road
#07-02 Prime Centre
Singapore, 188980
Tel:  65-334-8870  Fax: 65-334-8850
Taiwan
Microchip Technology Taiwan
11F-3, No. 207
Tung Hua North Road
Taipei, 105, Taiwan
Tel: 886-2-2717-7175  Fax: 886-2-2545-0139
EUROPE
Denmark
Microchip Technology Denmark ApS
Regus Business Centre
Lautrup hoj 1-3
Ballerup DK-2750 Denmark
Tel: 45 4420 9895 Fax: 45 4420 9910
France
Arizona Microchip Technology SARL
Parc d’Activite du Moulin de Massy
43 Rue du Saule Trapu
Batiment A - ler Etage
91300 Massy, France
Tel: 33-1-69-53-63-20  Fax: 33-1-69-30-90-79
Germany
Arizona Microchip Technology GmbH
Gustav-Heinemann Ring 125
D-81739 Munich, Germany
Tel: 49-89-627-144 0  Fax: 49-89-627-144-44
Germany
Analog Product Sales
Lochhamer Strasse 13
D-82152 Martinsried, Germany
Tel: 49-89-895650-0  Fax: 49-89-895650-22
Italy
Arizona Microchip Technology SRL
Centro Direzionale Colleoni 
Palazzo Taurus 1 V. Le Colleoni 1
20041 Agrate Brianza
Milan, Italy 
Tel: 39-039-65791-1  Fax: 39-039-6899883
United Kingdom
Arizona Microchip Technology Ltd.
505 Eskdale Road
Winnersh Triangle
Wokingham 
Berkshire, England RG41 5TU
Tel: 44 118 921 5869 Fax: 44-118 921-5820
01/30/01
WORLDWIDE SALES AND SERVICE
