# Using a Digital Potentiometer to Optimize a Precision Single-Supply Photo Detection Circuit - Extracted Text

- Source PDF: `../Microchip_AN692_Precision_Single_Supply_Photo_Detection.pdf`
- Manufacturer URL: https://ww1.microchip.com/downloads/en/Appnotes/00692b.pdf
- Extraction date: 2026-05-09
- Page count: 8
- SHA256: `943990DC8E88E2C6E919DFCB759326255F6B3EB97E192D816F6627CB3A902DE4`
- Notes: Raw text extracted with pypdf. Tables, equations, and figures may require checking against the source PDF.

## Page 1

 2004 Microchip Technology Inc. DS00692B-page 1
M AN692
INTRODUCTION
Photodiodes bridge the gap between light and
electronics. Many times, precision applications (such
as CT scanners, blood analyzers, smoke detectors,
position sensors, IR pyrometers and chromatographs)
utilize the basic transimpedance amplifier circuit that
transforms light energy into a usable electrical voltage.
In these circuits, photodiodes are used to capture the
light energy and transform it into a small current. This
current is proportional to the level of illumination from
the light source. A preamplifier then converts the
current (in amperes) from the photodiode sensor into a
usable voltage level.
FIGURE 1: In this precision 
photosensing configuration, a photodiode (in the 
Photovoltaic mode) is used to capture the 
luminance energy from a light source. The effects 
of the variability, due to alignment problems, is 
reduced by using a potentiometer for the resistive 
element in the feedback loop of the amplifier.
This application note will show how the adjustability of
the digital potentiometer can be used as an advantage
in photosensing circuits. Initially, photodiode
characteristics will be looked at, followed by various
digital potentiometer circuits that use photodiodes in
the Photoconductive and Photovoltaic modes.
Photodiode Characteristics 
A photodiode can be operated in the Photovoltaic or
Photoconductive mode, as shown in Figure 2.
FIGURE 2: The two modes that 
photodiodes can be used in are: (a) Photovoltaic 
and (b) Photoconductive. In the Photovoltaic 
mode, the photodiode is biased with zero volts 
which optimizes the sensor’s accuracy. In the 
Photoconductive mode, the diode is reverse 
biased in order to optimize the responses to step 
functions.
A photodiode configured in the Photovoltaic mode is
zero biased. In this mode, the light-to-current response
of the diode is maximized for light sensitivity and
linearity, making it well suited for precision applications.
A photodiode configured in the Photoconductive mode
has a reverse voltage bias applied. In this mode, the
photodiode is optimized for fast response to light
sources. An ideal application for a diode configured in
the Photoconductive mode is digital communication.
The key elements that influence the circuit
performance of each mode are the photodiode
capacitance (C
PD) and the photodiode leakage current
(IL), as shown in Figure 3. These parasitic elements
can effect the precision and speed of photo detection
circuits.
Author: Bonnie C. Baker
Microchip Technology Inc.
Light
VOUT
RF
ISC
+5V
MCP601
Source
VOUT = +ISCRF
-VBIAS
Light
Source
Light
Source
b) Photodiode
configured in
Photoconductive mode
a) Photodiode
configured in
Photovoltaic mode
Using a Digital Potentiometer to Optimize a Precision
Single-Supply Photo Detection Circuit

## Page 2

AN692
DS00692B-page 2  2004 Microchip Technology Inc.
FIGURE 3: The photodiode can be 
described with an ideal current source (ISC) that is 
a result of radiant flux energy from light, an ideal 
diode (D
PD), a junction capacitance (C PD), 
leakage current (I L ), a parasitic series resistor 
(RS) and a shunt resistor (RPD).
The junction capacitance (C PD) is determined by the
width of the depletion region between the p-type and
n-type material of the photodiode. The depletion
region width of the photodiode is inversely proportional
to the diode’s reverse bias voltage. Wider depletion
regions will increase the magnitude of the junction
capacitance. Conversely, wider depletion regions
(found with PIN photodiodes) have broader spectral
responses.
Values of the junction capacitance of silicon
photodiodes in the Photovoltaic mode (zero bias) range
from approximately 20 pF to 25 pF, up to several
thousand pico farads. Values of the junction
capacitance of silicon photodiodes in the Photoconduc-
tive mode (with a reverse bias of -10V) are generally
ten times lower. This reduced parasitic capacitance
facilitates high-speed operation. However, the linearity
and offset errors are not optimized.
A reverse bias voltage across the photodiode will
cause an increase in leakage current, I
L. When the
reverse bias voltage exceeds several millivolts,
linearity starts to be compromised in precision circuits.
With large voltages, this leakage current can be high
enough to make the diode only useful in digital
applications.
The shunt resistance (R
PD), also called “dark”
resistance, is measured with zero volts across the
element. At room temperature, the magnitude of this
resistance typically exceeds 100 M Ω. In most circuits,
this resistance is generally ignored.
The second parasitic diode resistance (R
S) is known as
the series resistance of the diode. This parasitic
resistance typically ranges from 10 to 1,000 Ω. Due to
the small size of this resistor, it only has an affect on the
frequency response of the circuit well past the
bandwidth of operation.
When light illuminates on the photodiode, current (I
SC)
flows from the anode to the cathode of the device. The
transfer function of light-to-photodiode current is equal
to the following:
EQUATION
Photovoltaic Mode Circuits
A practical way to design a precision photosensing
circuit is to place a photodiode in a Photovoltaic mode.
This can be done by placing the device across the
inputs of a CMOS input amplifier and a resistor in the
feedback loop. The single-supply circuit
implementation of this circuit is shown in Figure 4.
FIGURE 4: This is a standard, single-
supply, transimpedance amplifier circuit with the 
photodiode in the Photovoltaic (zero bias) mode.
In this circuit, the light source illuminates the
photodiode, causing diode current to flow from cathode
to anode. Since the input impedance of the inverting
input of the MCP601 CMOS amplifier is extremely high,
the current generated by the photodiode flows through
the feedback resistor (R
F). In this configuration, the
feedback resistor is implemented with a digital
potentiometer (MCP41100). 
RS
CPD RPD
IL
DPD
VOUT
+
-
ISC
where:
ISC = the current produced by the photodiode
with units in amperes/cm2.
Radiant Flux Energy  = the light energy with
units in watts/cm2.
Flux Responsivity = the measure of the pho-
todiode’s sensitivity with units in watts/
amperes.
I
SC Radiant Flux Energy/Flux Responsivity=
Light
VOUT
RF
ISC
+5V
MCP601
MCP41100
Digital 
Potentiometer
PB PA
Source
VOUT = +ISCRF
CRF
CF

## Page 3

 2004 Microchip Technology Inc. DS00692B-page 3
AN692
The current-to-voltage transfer function of this circuit is:
EQUATION
The programmed value of the digital potentiometer
(RF) is equal to:
EQUATION
If the digital potentiometer is programmed to equal
50 kΩ (D
CODE = 128), the maximum current from the
photodiode is 75 µA and the maximum output voltage
(V
OUT) is 3.75V. With this configuration, the digital
potentiometer capacitance (C RF) is 75 pF . As a result,
the frequency response of the circuit is equal to
1/2πRFCRF or 42.4 kHz. 
Circuit flexibility is added with the inclusion of a digital
potentiometer, as opposed to a standard resistor. By
changing the value of the digital potentiometer, the
maximum output voltage (V
OUT) can be adjusted. This
kind of flexibility accommodates alignment problems
between the light source and the photodiode.
Another circuit configuration that can be used for
Photovoltaic mode circuits is shown in Figure 5.
FIGURE 5: In this precision light-
sensing circuit, the potentiometer is to implement 
a T-network style feedback loop. This configura-
tion provides higher gains while using a lower 
value potentiometer.
In this circuit, the digital potentiometer is configured to
form a T-network. The digital potentiometer is a good fit
in this circuit because of its low wiper resistance and
resistor adjustability. The potentiometer’s A and B
resistive elements are used in this circuit so that the
gain versus the potentiometer digital code is linear.
The transfer function of this circuit is:
EQUATION
with a single pole at 1/(2pRF(CRF + CF))
where:
VOUT = the voltage at the output of the
operational amplifier in volts.
ISC = the current produced by the
photodiode with units in amperes.
RF = a digital potentiometer that is serving
as the feedback resistor with units in ohms.
CRF = the parasitic capacitance of the digital
potentiometer with units in farads. This
parasitic capacitor can cause oscillation
with some digital potentiometer settings. If
this occurs, place a 100 pF to 500 pF in
parallel (C
F) with the digital potentiometer,
as shown in Figure 4.
VOUT ISC RF×=
RF
DCODE RNOMINAL×
2n---------------------------------------------------=
where:
DCODE = the programmed code to the digital
potentiometer.
RNOMINAL = the nominal resistance of the
digital pot from PA to PB.
n = the number of bits that the digital
potentiometer has. In the case of Microchip
digital potentiometers, the ‘ n’ is equal to
eight.
VOUT = + ISC (1+RF – A/RW)RF – B
RF – B>>RF – A
LIGHT
VOUTISC
+5V
MCP601
MCP41010
Digital 
Potentiometer
RF – B RF – A
SOURCE
RF – W
VOUT
ISC
-------------RFA–
1R FA–+
RW
-----------------------
 RFB–+=
where:
RF – A  = the A portion of the digital
potentiometer resistor.
RF – B  = the A portion of the digital
potentiometer resistor.
RW = the parasitic resistance through the
wiper.

## Page 4

AN692
DS00692B-page 4  2004 Microchip Technology Inc.
This formula can be further worked by using the
following substitutions: 
EQUATION
Given all of the above calculations, the graph in
Figure 6 shows the gain of this T-network circuit for the
entire digital code range of the MCP41010. The
resistive values used in this graph are:
R
F – NOM = 10 kΩ (data sheet typical)
RW = 25Ω (data sheet typical)
FIGURE 6: This graph shows the gain 
versus digital code of the circuit shown in 
Figure 7.
The primary sources of error that effect the
performance of this circuit are amplifier offset voltage,
amplifier noise and digital potentiometer noise.
The actual offset voltage of the amplifier will produce a
gain error in the lower codes. For instance, an offset
voltage of 0.35 mV will produce a 4.2% error when the
digital potentiometer is set to code 50. When the offset
of the amplifier is 0.1 mV, the gain error of the circuit is
1% with the same digital potentiometer code.
In cases where this circuit is used for precision sensing,
the noise response of the circuit should be kept as low
as possible. The two factors that effect the overall noise
originate from the amplifier and the resistive network. In
order to achieve the lowest possible noise in this circuit
R
F – B >> R F – A . The range of digital potentiometer
codes that meet this criteria is from codes 233 to 255.
Photoconductive Mode Circuits
The response of a photodiode can be configured in the
Photoconductive mode, as shown in Figure 7.
FIGURE 7: When a photodiode is 
configured in the Photoconductive mode, the 
diode is reversed biased in order to reduce the 
diode parasitic capacitance.
RFA– RFN O M– RFB––=
RFB–
RFN O M– Dn
2n-----------------------------=
where:
RF – NOM = the nominal resistance across the
digital potentiometer. In Figure 5, this value is
equal to 10 kΩ.
Dn = the programmed digital code of the
potentiometer.
n = the number of bits of the digital
potentiometer. In Figure 5, this value is equal
to eight.
0
200000
400000
600000
800000
1000000
1200000
0 50 100 150 200 250
Digital Code of Potentiometer
Transimpedance Amplifier Gain (V/A)
Gain Calculations Use 
Typical Values 
for R
F-NOM  and R W
Resistive Range
that will Give the
Lowest Noise
Response
-5V
Light
VOUT
RF
ISC
+5V
MCP601
MCP41050
Digital 
Potentiometer
PB PA
Source
VOUT = ISC * RF

## Page 5

 2004 Microchip Technology Inc. DS00692B-page 5
AN692
CONCLUSION
The two modes that a photosensing circuit can be
configured are: Photovoltaic and Photoconductive.
Photovoltaic configurations are best suited for
precision circuits, while Photoconductive configura-
tions are best suited for higher speed, digital circuits. If
real-time adjustability of photodiode current to voltage
gain is an issue in these photo detection circuits, a dig-
ital potentiometer can effectively be used to achieve
this goal.
This application note presents three photosensing
circuits configured with a digital potentiometer for real-
time adjustments that can be used to calibrate LED/
photodiode alignment variability.
REFERENCES
“Keeping the Signal Clean in Photosensing 
Instrumentation”, Bonnie C. Baker, SENSORS, 
June 1997.
“The Eyes of the Electronics World” , 
http://www.chipcenter.com/analog/tn006.htm, 
Bonnie C. Baker, Knowledge Center, Analog, 
January, 1998.
“Comparison of Noise Performance between a FET 
Transimpedance Amplifier and a Switched Integrator”, 
Bonnie C. Baker, Burr-Brown Application Note, AB-057, 
January 1994.
“Optoelectronics”, Reston Publishing Company, Inc., 
Robert G. Seippel, 1981.
“Photodiode Amplifiers”, Jerald Graeme, McGraw Hill, 
1996.
“Design a Precision, Single-Supply Photo Detection 
Circuit”, http://www.chipcenter.com, Bonnie C. Baker, 
Knowledge Center, Online T ools, June, 1999.

## Page 6

AN692
DS00692B-page 6  2004 Microchip Technology Inc.
NOTES:

## Page 7

DS00692B-page 7  2004 Microchip Technology Inc.
Information contained in this publication regarding device
applications and the like is intended through suggestion only
and may be superseded by updates. It is your responsibility to
ensure that your application meets with your specifications.
No representation or warranty is given and no liability is
assumed by Microchip Technology Incorporated with respect
to the accuracy or use of such information, or infringement of
patents or other intellectual property rights arising from such
use or otherwise. Use of Microchip’s products as critical
components in life support systems is not authorized except
with express written approval by Microchip. No licenses are
conveyed, implicitly or otherwise, under any intellectual
property rights.
Trademarks
The Microchip name and logo, the Microchip logo, Accuron, 
dsPIC, KEELOQ, MPLAB, PIC, PICmicro, PICSTART, 
PRO MATE and PowerSmart are registered trademarks of 
Microchip Technology Incorporated in the U.S.A. and other 
countries.
AmpLab, FilterLab, micro ID, MXDEV, MXLAB, PICMASTER, 
SEEVAL, SmartShunt and The Embedded Control Solutions 
Company are registered trademarks of Microchip Technology 
Incorporated in the U.S.A.
Application Maestro, dsPICDEM, dsPICDEM.net, 
dsPICworks, ECAN, ECONOMONITOR, FanSense, 
FlexROM, fuzzyLAB, In-Circuit Serial Programming, ICSP, 
ICEPIC, Migratable Memory, MPASM, MPLIB, MPLINK, 
MPSIM, PICkit, PICDEM, PICDEM.net, PICtail, PowerCal, 
PowerInfo, PowerMate, PowerTool, rfLAB, rfPIC, Select 
Mode, SmartSensor, SmartTel and T otal Endurance are 
trademarks of Microchip Technology Incorporated in the 
U.S.A. and other countries.
Serialized Quick Turn Programming (SQTP) is a service mark 
of Microchip Technology Incorporated in the U.S.A.
All other trademarks mentioned herein are property of their 
respective companies.
© 2004, Microchip Technology Incorporated, Printed in the 
U.S.A., All Rights Reserved.
 Printed on recycled paper.
Note the following details of the code protection feature on Microchip devices:
• Microchip products meet the specification contained in their particular Microchip Data Sheet.
• Microchip believes that its family of products is one of the most secure families of its kind on the market today, when used i n the 
intended manner and under normal conditions.
• There are dishonest and possibly illegal methods used to breach the code protection feature. All of these methods, to our 
knowledge, require using the Microchip products in a manner outside the operating specifications contained in Microchip's Data 
Sheets. Most likely, the person doing so is engaged in theft of intellectual property.
• Microchip is willing to work with the customer who is concerned about the integrity of their code.
• Neither Microchip nor any other semiconductor manufacturer can guarantee the security of their code. Code protection does not 
mean that we are guaranteeing the product as “unbreakable.”
Code protection is constantly evolving. We at Microchip are committed to continuously improving the code protection features of  our
products. Attempts to break Microchip’s code protection feature may be a violation of the Digital Millennium Copyright Act. If such acts
allow unauthorized access to your software or other copyrighted work, you may have a right to sue for relief under that Act.
Microchip received ISO/TS-16949:2002 quality system certification for 
its worldwide headquarters, design and wafer fabrication facilities in 
Chandler and Tempe, Arizona and Mountain View, California in October 
2003. The Company’s quality system processes and procedures are for 
its PICmicro
® 8-bit MCUs, KEELOQ® code hopping devices, Serial 
EEPROMs, microperipherals, nonvolatile memory and analog 
products. In addition, Microchip’s quality system for the design and 
manufacture of development systems is ISO 9001:2000 certified.

## Page 8

DS00692B-page 8  2004 Microchip Technology Inc.
M
AMERICAS
Corporate Office
2355 West Chandler Blvd.
Chandler, AZ  85224-6199
Tel:  480-792-7200  
Fax:  480-792-7277
Technical Support: 480-792-7627
Web Address: http://www.microchip.com
Atlanta
3780 Mansell Road, Suite 130
Alpharetta, GA  30022
Tel: 770-640-0034  
Fax: 770-640-0307
Boston
2 Lan Drive, Suite 120
Westford, MA  01886
Tel: 978-692-3848 
Fax: 978-692-3821
Chicago
333 Pierce Road, Suite 180
Itasca, IL  60143
Tel: 630-285-0071 
Fax: 630-285-0075
Dallas
4570 Westgrove Drive, Suite 160
Addison, TX 75001
Tel: 972-818-7423  
Fax: 972-818-2924
Detroit
Tri-Atria Office Building 
32255 Northwestern Highway, Suite 190
Farmington Hills, MI  48334
Tel: 248-538-2250
Fax: 248-538-2260
Kokomo
2767 S. Albright Road 
Kokomo, IN  46902
Tel: 765-864-8360
Fax: 765-864-8387
Los Angeles
18201 Von Karman, Suite 1090
Irvine, CA  92612
Tel: 949-263-1888  
Fax: 949-263-1338
San Jose
1300 Terra Bella Avenue
Mountain View, CA 94043
Tel: 650-215-1444
Fax: 650-961-0286
Toronto
6285 Northam Drive, Suite 108
Mississauga, Ontario L4V 1X5, Canada
Tel: 905-673-0699  
Fax:  905-673-6509
ASIA/PACIFIC
Australia
Suite 22, 41 Rawson Street
Epping 2121, NSW
Australia
Tel: 61-2-9868-6733 
Fax: 61-2-9868-6755
China - Beijing
Unit 706B
Wan Tai Bei Hai Bldg.
No. 6 Chaoyangmen Bei Str. 
Beijing, 100027, China
Tel: 86-10-85282100 
Fax: 86-10-85282104
China - Chengdu
Rm. 2401-2402, 24th Floor, 
Ming Xing Financial Tower
No. 88 TIDU Street
Chengdu 610016, China
Tel: 86-28-86766200  
Fax: 86-28-86766599
China - Fuzhou
Unit 28F, World Trade Plaza
No. 71 Wusi Road
Fuzhou 350001, China
Tel: 86-591-7503506  
Fax: 86-591-7503521
China - Hong Kong SAR
Unit 901-6, Tower 2, Metroplaza
223 Hing Fong Road
Kwai Fong, N.T., Hong Kong
Tel: 852-2401-1200  
Fax: 852-2401-3431
China - Shanghai
Room 701, Bldg. B
Far East International Plaza
No. 317 Xian Xia Road
Shanghai, 200051
Tel: 86-21-6275-5700  
Fax: 86-21-6275-5060
China - Shenzhen
Rm. 1812, 18/F, Building A, United Plaza
No. 5022 Binhe Road, Futian District
Shenzhen 518033, China
Tel: 86-755-82901380 
Fax: 86-755-8295-1393
China - Shunde
Room 401, Hongjian Building, No. 2 
Fengxiangnan Road, Ronggui Town, Shunde
District, Foshan City, Guangdong 528303, China
Tel: 86-757-28395507  Fax: 86-757-28395571
China - Qingdao
Rm. B505A, Fullhope Plaza,
No. 12 Hong Kong Central Rd.
Qingdao 266071, China
Tel: 86-532-5027355  Fax: 86-532-5027205
India
Divyasree Chambers
1 Floor, Wing A (A3/A4)
No. 11, O’Shaugnessey Road
Bangalore, 560 025, India
Tel: 91-80-2290061 Fax: 91-80-2290062
Japan
Benex S-1 6F
3-18-20, Shinyokohama
Kohoku-Ku, Yokohama-shi
Kanagawa, 222-0033, Japan
Tel: 81-45-471- 6166  Fax: 81-45-471-6122
Korea
168-1, Youngbo Bldg. 3 Floor
Samsung-Dong, Kangnam-Ku
Seoul, Korea 135-882
Tel: 82-2-554-7200  Fax: 82-2-558-5932 or 
82-2-558-5934
Singapore
200 Middle Road
#07-02 Prime Centre
Singapore, 188980
Tel:  65-6334-8870  Fax: 65-6334-8850
Taiwan
Kaohsiung Branch
30F - 1 No. 8
Min Chuan 2nd Road
Kaohsiung 806, Taiwan
Tel: 886-7-536-4818
Fax: 886-7-536-4803
Taiwan
Taiwan Branch
11F-3, No. 207
Tung Hua North Road
Taipei, 105, Taiwan
Tel: 886-2-2717-7175  Fax: 886-2-2545-0139
EUROPE
Austria
Durisolstrasse 2
A-4600 Wels
Austria
Tel: 43-7242-2244-399
Fax: 43-7242-2244-393
Denmark
Regus Business Centre
Lautrup hoj 1-3
Ballerup DK-2750 Denmark
Tel: 45-4420-9895 Fax: 45-4420-9910
France
Parc d’Activite du Moulin de Massy
43 Rue du Saule Trapu
Batiment A - ler Etage
91300 Massy, France
Tel: 33-1-69-53-63-20  
Fax: 33-1-69-30-90-79
Germany
Steinheilstrasse 10
D-85737 Ismaning, Germany
Tel: 49-89-627-144-0 
Fax: 49-89-627-144-44
Italy
Via Quasimodo, 12
20025 Legnano (MI)
Milan, Italy 
Tel: 39-0331-742611  
Fax: 39-0331-466781
Netherlands
P. A. De Biesbosch 14
NL-5152 SC Drunen, Netherlands
Tel: 31-416-690399 
Fax: 31-416-690340
United Kingdom
505 Eskdale Road
Winnersh Triangle
Wokingham 
Berkshire, England RG41 5TU
Tel: 44-118-921-5869
Fax: 44-118-921-5820
01/26/04
WORLDWIDE SALES AND SERVICE
