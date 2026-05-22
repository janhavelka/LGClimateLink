# Using Digital Potentiometers to Design Low-Pass Adjustable Filters - Extracted Text

- Source PDF: `../Microchip_AN737_Low_Pass_Adjustable_Filters.pdf`
- Manufacturer URL: https://ww1.microchip.com/downloads/aemDocuments/documents/APID/ApplicationNotes/ApplicationNotes/00737c.pdf
- Extraction date: 2026-05-09
- Page count: 8
- SHA256: `3E225F6D1D9DD1F7E6BD6B1BFCA8F0E6591B7A6CBE4B9128DE58C3222DD4D7A9`
- Notes: Raw text extracted with pypdf. Tables, equations, and figures may require checking against the source PDF.

## Page 1

 2004 Microchip Technology Inc. DS00737C-page 1
M AN737
INTRODUCTION
The most common filter found in a data acquisition
system signal path is a low-pass filter. This type of filter
is usually used to reduce A/D Converter (ADC) aliasing
errors. If there is more than one signal that is applied to
the A/D converter through a multiplexer, each signal
source may have its own set of filter requirements (i.e.,
settling time, fast transition region, etc.). Consequently,
a variety of filters may be required in the circuit prior to
the multiplexer. Usually these filters are implemented
with operational amplifiers (op amps) in combination
with fixed resistors and capacitors.
An alternative filter design solution is to have one filter
following the multiplexer. In this circuit, the low-pass
filter would need to be programmable. The obvious
advantage of having the filter serve many analog inputs
is that there is a reduction in chip count. An example of
this type of approach is shown in Figure 1.
FIGURE 1: If a programmable low-pass 
filter is used in the application circuit, it can be 
placed after the analog multiplexer. The 
programmability of the filter allows for a wide vari-
ety of input signals.
Programmable Low-Pass Filters
In this application note, a programmable, second-
order, low-pass filter will be presented in four different
scenarios. The first three scenarios will illustrate how a
dual digital potentiometer and a single amplifier can be
configured for low-pass second-order Butterworth,
Bessel and Chebyshev responses with a programma-
ble corner frequency range of 1:100. An example of the
digital potentiometer setting for these designs is
summarized in Tables 1, 2 and 3. The fourth scenario
will show the same circuit design, where all three
approximation methods (Butterworth, Bessel and
Chebyshev) can coexist with a programmable corner
frequency range of 1:10. An example of the digital
potentiometer settings for this combination of
approximation methods is summarized in Table 4.
Figure 2 shows the details of a single-supply, unity
gain, second-order, programmable low-pass Sallen
Key filter. This filter is implemented with two resistors
and two capacitors. The two resistors in this circuit are
replaced with the dual MCP42100, 100 kΩ, 8-bit, digital
potentiometer.
FIGURE 2: The combination of a dual 
digital potentiometer and a single-supply, rail-to-
rail amplifier can be used to construct a program-
mable, second-order, Sallen-Key, low-pass filter.
Digital potentiometers can be used to adjust system
reference levels, gain errors and offset errors, while
offering the added capability of digital adjustment
control. Devices such as Microchip’s MCP41XXX and
MCP42XXX digital potentiometer families have three
resistive terminals for the single versions (MCP41010,
MCP41050 and MCP41100) and six resistive terminals
for the dual versions (MCP42010, MCP42050 and
MCP42100) and are illustrated in Figure 3. The
MCP41010 and MCP42010 are both 10 k Ω
potentiometers. The MCP41050 and MCP42050 are
both 50 k Ω potentiometers, while the MCP41100 and
42100 are both 100 kΩ potentiometers.
Author: Bonnie C. Baker
Microchip Technology Inc.
Analog
Multiplexer Programmable
Low-Pass
Filter
12-bit
A/D Converter
Temperature 1
Vibration
Pressure
Temperature 2
Temperature 3
Acceleration
+
-
VIN
VOUT
C1
C2
R1
MCP601 MCP3201
12-bit ADC1/2
100 kΩ Digital
Potentiometers
Single-Supply, 
Rail-to-Rail Input 
Op Amp
PA1
PW1
PB1
MCP42100
1/2
MCP42100
PA0
PW0
PB0
R2
Using Digital Potentiometers to Design
Low-Pass Adjustable Filters

## Page 2

AN737
DS00737C-page 2  2004 Microchip Technology Inc.
FIGURE 3: The operation of the digital potentiometer as compared to the mechanical potentiome-
ter is functionally the same. The adjustment of the digital potentiometer is done with a serial code to the 
device. Although the mechanical potentiometer provides simplicity, the digital potentiometer provides 
flexibility and reliability.
The potentiometer can be configured for two modes:
the Rheostat mode and Voltage Divider mode. In the
Rheostat mode, the wiper (terminal P
W) is shorted to
either the P A or P B terminal of the device. This
configuration is shown in Figure 4. When used in the
Voltage Divider mode (Figure 4.b), all three terminals
are connected to differing nodes in the circuit. For the
analog filter example in this application note, the digital
potentiometer will be configured in the Rheostat mode.
FIGURE 4: A digital potentiometer can 
be configured in the (a) Rheostat mode or (b) 
Voltage Divider mode.
The operational amplifier used in this application circuit
is a single-supply, rail-to-rail out device. The MCP601
is a single amplifier that belongs to the MCP601/2/3/4
family of operational amplifiers. The MCP603 is also a
single amplifier with a Chip Select
 feature. The dual
version is the MCP602, while the quad version is the
MCP604. These amplifiers are optimized for high
speed, low offset voltage and single-supply operation.
By adjusting the two digital potentiometers in Figure 2,
the frequency cutoff and the filter approximation
method of this second-order low-pass filter can be
changed.
The design equation for this low-pass filter
configuration is:
With this formula, the appropriate resistance and capac-
itance can be calculated. An alternative to this tedious
design exercise is to determine the capacitor and resis-
tor values using the FilterLab
® software, a filter design
program that can be downloaded from Microchip’s web
site at www.microchip.com.
The Circuit screen in this program allows the user to
adjust the capacitors to desired values (C
1 and C2 per
Figure 2). When these capacitors are set, the software
changes the resistors in the circuit to appropriate
values for the circuit implementation. There may be a
corner frequency and stability error with low-pass filters
that are designed at frequencies higher than 100 kHz.
This error is introduced by the parasitic capacitance of
the digital potentiometer. As a general guideline, C
1
and C2 should be larger than 10 nF.
For more detailed information concerning anti-aliasing
filters, please refer to Microchip’s Application Note 699,
entitled “Anti-Aliasing, Analog Filters for Data
Acquisition Systems” (DS00699).
RDAC1
SCK SOSI
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
(a) Rheostat Mode (b) Voltage Divider Mode
PW
PA PB
RX = ±30% accurate
500 ppm/°C
RA/RB = ±3% accurate
15 ppm/°C
PW
PA PB
PA
PB PW
VOUT
VIN
-----------------
K/ R 1R2C1C2()
s2 s1 / R1C1 1/R 2/C1 1/R 2+C 2 K/R 2– C2+() 1/R 1R2C1C2++
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------=
Where: K = 1

## Page 3

 2004 Microchip Technology Inc. DS00737C-page 3
AN737
Butterworth Second-Order Low-Pass 
Filters
When a Butterworth filter is required, the Sallen Key
configuration shown in Figure 2 can have an adjustable
frequency range of 1:100. The frequency behavior of
the Butterworth filter is maximally flat in the magnitude
response in pass band. The rate of attenuation in
transition band is better than the Bessel filter, though
not as good as the Chebyshev filter. There is no ringing
in the stop band. The step response of the Butterworth
filter has some overshoot and ringing in the time
domain, though this is less than the Chebyshev filter.
The capacitor values in this circuit are kept constant
while the resistive elements are adjusted. The two
capacitors should be carefully selected to be constants
in the FilterLab software so that the digital potentiome-
ter resistances are the only values that are changing.
These capacitive values can easily be found in the
FilterLab software through experimentation.
As an example, a programmable second-order, low-
pass Butterworth filter with a corner frequency that
ranges from 100 Hz to 10 kHz can be designed by
setting C
1 = 0.047 µF and C 2 = 0.018 µF. The values
calculated by the FilterLab software for this filter design
are summarized in T able 1. Table 1 also includes the
closest values for R
1 and R 2 from the digital
potentiometer, along with the digital program code for
the MCP42100.
Verification of the performance of the Butterworth filters
that use 1% discrete resistors can be performed with
the SPICE listing that is provided as an output from  the
FilterLab software. The SPICE simulations for the
100 Hz, 200 Hz, 300 Hz and 1,000 Hz filters using the
values calculated by the FilterLab software are shown
in Figure 5.
To validate the digital potentiometer design, SPICE
simulations can be performed on the Butterworth filters
using the digital potentiometer values. The 100 Hz,
200 Hz, 300 Hz and 1,000 Hz filters using the
calculated nominal resistance values of the digital
potentiometers, per Table 2, are shown in Figure 6.
From these two SPICE simulations, it is easy to see
that the filters from Figure 5 behave fundamentally the
same over frequency as compared to Figure 6.
TABLE 1: A BUTTERWORTH FILTER DESIGN ADJUSTING THE RESISTORS THROUGH A 
DIGITAL POTENTIOMETER
Specifications: Programmable cutoff frequency range of 100 Hz to 10 kHz by using capacitors of C 1 = 0.047 µF,
C2 = 0.018 µF and adjusting the resistors through a digital potentiometer.
Cutoff 
Frequency, Hz
FilterLab 
Calculated 1% 
R1 Value, kΩ
Closest 
Nominal 
Digital Pot. R1 
Value, kΩ
Digital Pot. R1 
Code, decimal
FilterLab 
Calculated 1% 
R2 Value, kΩ
Closest 
Digital Pot. R2 
Value, kΩ
Digital Pot. R2 
Code, decimal
100 32.2 32.031 82 92.8 92.969 238
200 16.1 16.016 41 46.4 46.484 119
300 10.7 10.156 26 30.9 30.859 79
1000 3.22 3.125 8 9.28 9.375 24
2000 1.61 1.563 4 4.64 4.688 12
3000 1.07 1.172 3 3.09 3.125 8
10000 322 0.391 1 928 0.781 2

## Page 4

AN737
DS00737C-page 4  2004 Microchip Technology Inc.
FIGURE 5: SPICE simulation of four Butterworth, se cond-order low-pass filters with corner 
frequencies of 100 Hz, 200 Hz, 300 Hz and 1,000 Hz. In this simulation, 1% resistor values were used.
FIGURE 6: SPICE simulation of four Butterworth, se cond-order low-pass filters with corner 
frequencies of 100 Hz, 200 Hz, 300 Hz and 1,000 Hz. In this simulation, nominal digital potentiometer 
resistor values, per Table 1, were used.
TABLE 2: A PROGRAMMABLE BESSEL FILTER DESIGN USING A DUAL 100 K Ω DIGITAL 
POTENTIOMETER.
Specifications: A programmable Bessel filter with a cutoff frequency range of 100 Hz to 10 kHz can be implemented 
with C1 = 0.033 µF, C2 = 0.018 µF and a dual 100 k Ω digital potentiometer.
Cutoff 
Frequency, Hz
FilterLab 
Calculated 1% 
R1 Value, kΩ
Closest 
Nominal 
Digital Pot. R1 
Value, kΩ
Digital Pot. R1 
Code, decimal
FilterLab 
Calculated 1% 
R2 Value, kΩ
Closest 
Digital Pot. R2 
Value, kΩ
Digital Pot. R2 
Code, decimal
100 28.7 28.516 73 91.5 91.406 234
200 14.3 14.453 37 45.7 43.75 117
300 9.57 9.375 24 30.5 30.469 78
1000 2.87 2.734 7 9.15 8.984 23
2000 1.43 1.563 4 4.57 4.688 12
3000 0.957 0.781 2 3.05 3.125 8
10000 0.287 0.391 1 0.915 0.781 2

## Page 5

 2004 Microchip Technology Inc. DS00737C-page 5
AN737
Bessel Second-Order Low-Pass Filters
When a Bessel filter is desired, the Sallen Key
configuration, shown in Figure 2, can have an adjust-
able frequency range of 1:100. As with the Butterworth
filter, the frequency response of the Bessel filter has a
flat magnitude response in the pass band. Following
the pass band, the rate of attenuation in the transition
band is slower than the Butterworth or Chebyshev.
Finally, there is no ringing in the stop band. This filter
has the best step response of all of the filters men-
tioned in this application note, with very little overshoot
or ringing.
In T able 3, a programmable Bessel filter is designed
with a corner frequency range of 100 Hz to 10 kHz, by
setting C
1 = 0.033 µF and C 2 = 0.018 µF . Once again,
in the FilterLab software, the capacitor values are kept
constant, while the resistive elements are adjusted.
Chebyshev 2nd Order Low-Pass Filters
The filter in Figure 2 can also be designed in the
Chebyshev approximation for an adjustable range of
1:100. With the Chebyshev filter, the frequency behavior
exhibits a ripple in the pass-band that is determined by
the specific placement of the poles in the circuit design.
With the design discussed in this application note, the
ripple is 3 dB. In general, an increase in ripple magnitude
will lessen the width of the transition band. The rate of
attenuation in the transition band is steeper than
Butterworth and Bessel filters. Although there is ringing
in the pass-band region with this filter, the stop band is
devoid of ringing. The step response has a fair degree
of overshoot and ringing.
An example of the digital potentiometer settings for a
2nd order, low-pass Chebyshev filter is given in
Table 3.
TABLE 3: CHEBYSHEV FILTER DESIGN
Specification: Chebyshev, 3 dB Ripple, 100 to 10 kHz cutoff, C 1 = 0.15 µF, C2 = 0.015 µF
Cutoff 
Frequency, Hz
FilterLab 
Calculated 1% 
R1 Value, kΩ
Closest 
Nominal Digital 
Pot. R1 Value, 
kΩ
Digital Pot. R1 
Code, decimal
FilterLab 
Calculated 1% 
R2 Value, kΩ
Closest Digital 
Pot. R2 Value, 
kΩ
Digital Pot. R2 
Code, decimal
100 21.0 21.094 54 75.6 75.781 194
200 10.5 10.547 27 37.8 37.891 97
300 7.01 7.031 18 25.2 25.391 65
1000 2.10 1.953 5 7.56 16.016 41
2000 1.05 1.563 4 3.78 3.9063 10
3000 0.701 0.781 2 2.52 2.344 6
10000 0.210 0.391 1 0.756 0.781 2
TABLE 4: THE BUTTERWORTH, BESSEL AND CHEBYSHEV APPROXIMATION METHODS
Specifications: The Butterworth, Bessel and Chebyshev approximation methods can be designed into the circuit in Figure 2 by 
using a dual potentiometer and capacitive values of C 1 = 0.015 µF, C2 = 0.0022 µF . The adjustable cutoff frequency range of these 
filters is 1,000 Hz to 10 kHz.
Cutoff Frequency, 
Hz
Filter 
Approximation 
Method
Closest Digital 
Pot. R1 Value, Ω
Digital Pot. R1 
Code, decimal
Closest Digital 
Pot. R2 Value, Ω
Digital Pot. R2 
Code, decimal
1,000 Butterworth 8.203 21 94.141 241
Bessel 5.078 13 93.359 239
Chebyshev
(3 dB Ripple)
3.516 9 33.984 87
2,000 Butterworth 3.906 10 47.266 121
Bessel 2.344 6 46.484 119
Chebyshev
(3 dB Ripple)
15.625 40 17.188 44
3,000 Butterworth 2.734 7 31.250 80
Bessel 1.563 4 31.250 80
Chebyshev
(3 dB Ripple)
10.547 27 11.328 29
10,000 Butterworth 0.781 2 9.375 24
Bessel 0.391 1 9.375 24
Chebyshev
(3 dB Ripple)
3.125 8 3.516 9

## Page 6

AN737
DS00737C-page 6  2004 Microchip Technology Inc.
Combining Butterworth, Bessel and 
Chebyshev Second-Order Low-Pass 
Filters
All three approximation methods can be combined,
with some limitations, in this circuit. Since there is a
large variety of pole locations, the cutoff frequency
range is 1:10. An example of a programmable filter with
a cutoff frequency range of 1,000 Hz to 10 kHz is
shown in Table 4.
ERROR ANALYSIS OF 
PROGRAMMABLE FILTERS
Absolute Accuracy of Circuit Elements
The nominal resistance of a 100 kΩ digital potentiome-
ter (MCP42100), per data sheet specifications, varies
approximately ±30%. If the 10 kΩ digital potentiometer
(MCP42010) is substituted for the MCP42100, the
nominal resistance variance from part-to-part is
specified at ±20% for the MCP42010. When the 10 k Ω
potentiometer is substituted, the capacitive values
should be increased by 10X. For instance, in the
Butterworth example of Table 1, C
1 should be changed
to 0.47 µ F and C 2 changed to 0.18 µ F. When this is
done, the codes to the potentiometer that can stay the
same, remain unchanged. The change of the potenti-
ometer from the MPC42100 (100 k Ω) to the
MCP42010 (10 k Ω) will, in fact, decrease the values,
as stated in Table 1, by 10X.
In this application circuit, it is suggested that the dual
version of the digital potentiometer be used because
there can be part-to-part variation of the nominal
resistance (±30% for the MCP42100 and ±20% for the
MCP42010). With the dual potentiometer, resistor-to-
resistor variation on chip is specified to a typical value
of 0.2%. The resistance variation of these digital
potentiometers is primarily dependent on the process
variation of the sheet-rho of a diffused p-silicon layer
and the on-resistance of the internal switches.
If 20% accurate capacitors are used, the variability of
this filter in a manufacturing environment is dominated
by the capacitors.
Wiper resistance
The wiper resistance of the MCP42100 digital
potentiometer is approximately 125 Ω (typ) when
VDD = 5.5V. This wiper resistance appears as an error
in the resistance value of the digital potentiometer only
at lower programmed settings. For instance, with the
MCP42100, the nominal resistance step for each code
is equal to 100 k Ω/256, or 390.625 Ω. With a digital
code setting of ‘ 1’, the ideal nominal resistance is
390.625Ω. However, with the added wiper resistance,
this resistance is nominally 515.625 Ω.
CONCLUSION
It is possible to design second-order, low-pass,
programmable filters with one dual digital
potentiometer, one amplifier and two capacitors.
REFERENCES
AN699, “Anti-Aliasing, Analog Filters for Data 
Acquisition Systems”, Bonnie C. Baker,
Microchip Technology Inc., DS00699, 1999.
AN219, “Comparing Digital Potentiometers to 
Mechanical Potentiometers” , Bonnie C. Baker, 
Microchip Technology Inc., DS00219, 2000.
AN691, “Optimizing Digital Potentiometer Circuits to 
Reduce Absolute and Temperature Variations”, 
Bonnie C. Baker, Microchip Technology Inc., 
DS00691, 2001.

## Page 7

 2004 Microchip Technology Inc. DS00737C-page 7
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

DS00737C-page 8  2004 Microchip Technology Inc.
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
