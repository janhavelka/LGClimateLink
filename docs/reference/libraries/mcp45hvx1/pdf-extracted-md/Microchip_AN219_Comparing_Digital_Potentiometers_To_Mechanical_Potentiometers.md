# Comparing Digital Potentiometers to Mechanical Potentiometers - Extracted Text

- Source PDF: `../Microchip_AN219_Comparing_Digital_Potentiometers_To_Mechanical_Potentiometers.pdf`
- Manufacturer URL: https://ww1.microchip.com/downloads/en/appnotes/00219.pdf
- Extraction date: 2026-05-09
- Page count: 6
- SHA256: `2BD4866A7998E10CCF9A4F3257108F15A6F826D67783E30D664660542A468246`
- Notes: Raw text extracted with pypdf. Tables, equations, and figures may require checking against the source PDF.

## Page 1

  2000 Microchip Technology Inc. Preliminary DS00219A-page 1
AN219
INTRODUCTION
Resistor potentiometers can be found in electronic cir-
cuits across a wide spectrum of applications. Most typ-
ically, they function in a voltage divider configuration in
order to execute various types of tasks, such as offset
or gain adjust. The two types of potentiometers com-
pared in this application note are the mechanical poten-
tiometer (also called a trimmer potentiometer) and the
digital potentiometer. The physical descriptions and cir-
cuit models of these two devices are shown in Figure 1.
Basics of Mechanical Potentiometers
The first type of potentiometer on the market was
mechanical in nature. This type of potentiometer is still
available and adjustments of the wiper are imple-
mented by twisting a knob, moving a slider, or using a
screw driver. Although this method seems awkward,
given the advent of the digital potentiometer, mechani-
cal potentiometers still find their way into various elec-
tronic circuits.
Earlier mechanical potentiometers were built by wrap-
ping a resistive wire around a cylinder. With this con-
struction, the wiper moves from one winding to the
next. As the wiper is moved across the element, there
are discrete steps in resistance. Following this style of
fabrication, the mechanical potentiometer was built
using a resistive thick film that was screened onto a
ceramic substrate. With this construction, the change in
resistance across the element is continuous.
There are a variety of resistive materials that are used
by mechanical potentiometer manufacturers. They
include molded conductive plastic, conductive plastic
film, screened conductive plastic, and cermet. Each
resistive material has its own set of performance char-
acteristics. In this application note the digital potentiom-
eter will only be compared to the more popular cermet
potentiometer. Cermet is a thick film resistive material
that is a mixture of fine particles of ceramic or glass and
precision metals such as silver, platinum, rhodium, or
gold. The wiper of the mechanical potentiometer slides
along the distance on the resistive material providing
an analog resistive output that has an infinite number of
positions across the span of the element.
 
Figure 1: The mechanical potentiometer is constructed so that the user can easily adjust the position of
the wiper (PW) by hand or with a screw driver. The digital potentiometer is manufactured so that the
position of the wiper is adjusted by means of a serial digital code. The circuit representation of the digital
potentiometer and the mechanical potentiometer is fundamentally the same.
Author: Bonnie C. Baker,
Microchip Technology Inc.
Mechanical
Potentiometer
Model
Digital
PA PB PW
Potentiometer
Model
An example of PCB 
mountable Mechanical 
potentiometers
wiper
PA PB PW
MCP41010
MCP42010
contact resistanceresistance
Comparing Digital Potentiometers to Mechanical 
Potentiometers

## Page 2

AN219
DS00219A-page 2 Preliminary   2000 Microchip Technology Inc.
The metal contacts of the mechanical potentiometer
can affect the performance and reliability of the device.
Higher cost potentiometers use multi-fingers made
from precious metals in order to promote longer life as
well as improve electrical performance in all environ-
ments. These higher quality potentiometers are not
included in the discussions in this application note.
Basics of Digital Potentiometers
Digital potentiometers (Figure 2) were introduced in the
market after the mechanical potentiometer. The digital
potentiometer is fabricated using the same silicon tech-
nology used in active analog and digital integrated cir-
cuits use. This device comprises a combination of
segmented resistive elements and on-chip switches.
The resistive elements are manufactured using stan-
dard p-type silicon diffusions. Each resistive element
can be switched from one side to the other side of the
wiper using a serial digital command.
The digital potentiometer exhibits the same fundamen-
tal operation as the mechanical potentiometer with one
primary exception. The wiper position is digitally pro-
grammed with a microcontroller. This style of adjust-
ment allows the designer to adjust circuit performance
dynamically using a digital controller. The additional
programmability provides a solution where human
intervention is not required. With this “hands-off” pro-
grammability, the digital potentiometer offers signifi-
cant flexibility for a variety of applications.
Because this system is digital, the number of wiper
positions is no longer infinite. For example, Microchip’s
MCP41XXX and MCP42XXX family of potentiometers
are all 8-bit and have 256 unique linear positions along
the total resistive element.
Beyond the basic differences in fabrication and func-
tionality of these two styles of potentiometers, there are
several specifications that describe the difference and
similarities of these devices further.
Changes of Resistive Element Due to 
Environmental Cycling
Environmental changes such as temperature or humid-
ity can have an adverse effect on an application circuit
where a mechanical potentiometer is used. Since
mechanical potentiometers have moving parts, they
can be more sensitive to these types of environmental
changes. The reaction of a typical mechanical potenti-
ometer to these types of environmental changes is
shown in Table 1.
Figure 2: This is an example of a dual digital potentiometer. The digital potentiometer is programmed via
a serial interface.
Environmental Event
(per Mil-R-94 standard)
Maximum Allowable 
Resistance Change of 
Mechanical 
Potentiometer
Temperature Cycling ±1% to ±10%
High Temperature
Exposure
±2% @ 125 °C for 250 
hours
Humidity excursions ±15%
Table 1: The environment can have an
adverse effect on the reliability of the mechanical
potentiometer. The specifications in this table
were taken from data sheets of higher quality
mechanical potentiometers.
RDAC1
SCK
SOSI
Decode
Logic
16 Bit Shift Register
PA0 PB0PW0
RDAC2
Data Register 1
PA1 PB1PW1
CS
RS
SHDN
D7 D0
Data Register 0
D7 D0D7 D0

## Page 3

  2000 Microchip Technology Inc. Preliminary DS00219A-page 3
AN219
Since digital potentiometers are manufactured using a
standard CMOS process with no moving parts, the
reaction to these environmental changes are signifi-
cantly reduced.
Vibration or Shock
Vibration or shock can also have an effect on an appli-
cation circuit by causing physical movement. All
devices that are soldered on a PCB can have failures
due to vibration or shock, but the moving mechanism of
mechanical potentiometers may also move.
A typical specification for a mechanical potentiometer
would be a ±2% change due to vibrations that span
from 10Hz to 2kHz. Another way of describing the
effects of movement on the mechanical potentiometer
is force. Typically 20Gs of force on a higher quality
mechanical potentiometer would cause a maximum of
±1% resistive change.
Since there are no moving parts in digital potentiome-
ters, the element will remain unchanged with vibration
or shock tests unless discontinuities occur in the PCB
construction.
Mean Time to Failure Life
One type of failure that is quantified with mechanical
potentiometers is the mean time to failure life of the
wiper adjustment capability. A typical specification for
this type of failure would be that the device could sur-
vive several hundred cycles without discontinuity. A
cycle is defined as changing the wiper position across
full scale once. With thin film mechanical potentiome-
ters, such as those constructed of cermet, a failure
resulting from repeated cycles manifests itself as
reduced performance.
Since the wiper of the digital potentiometer is controlled
by electrical switches, the resistive elements are not
effected by repeated cycles. Consequently, the digital
potentiometer is a more robust solution.
Nominal Total Resistance
The nominal total resistance of a potentiometer is the
typical specified resistance (in ohms) that can be mea-
sured between terminal PA and terminal PB per
Figure 1. Typical values for digital potentiometers are
10kΩ, 50k Ω , and 100k Ω . Nominal resistance values
below 10k Ω  become difficult to implement in silicon
because of the switch resistances. Values higher than
100kΩ  are possible but require more silicon, which
increases the cost of the device.
The range of the selection of the mechanical potenti-
ometer is considerably wider with values such as 10Ω ,
20Ω , 50 Ω , 100 Ω , 200 Ω , 500 Ω , 1k Ω , 2k Ω , 5k Ω , 10k Ω ,
20kΩ , 25k Ω , 50kΩ , 100k Ω , 250k Ω , 500k Ω , 1M Ω , and
2MΩ .
The mechanical potentiometer might be considered
attractive because of the wide range of nominal resis-
tance offerings. However, the most common nominal
resistance ranges used in adjustment type circuits are
1kΩ  through 1M Ω . This range of potentiometers are
available in both the digital and mechanical potentiom-
eters.
Total Resistance Tolerance
The total resistance tolerance of the element between
terminal PA and terminal PB varies from part to part.
With digital potentiometers that variance is dependent
on processing variance of the resistive material and
switches. Typical digital potentiometer total resistance
tolerances are between ±20% to ±30%. On the other
hand, variance of the cermet material in mechanical
potentiometers range from ±10 to ±25%.
Although there seems to be a degree of difference
between the digital potentiometer and mechanical
potentiometer, the variability of the nominal resistance
of both devices is considerably larger than standard 1%
discrete resistors. In some applications, these toler-
ance values can cause errors that are too large. For
additional design help, refer to the numerous circuit
ideas in Microchip’s application note, AN-691,”Optimiz-
ing Digital Potentiometer Circuits to Reduce Absolute
and Temperature Variations”.
Temperature Coefficient
Mechanical potentiometers and digital potentiometers
drift with temperature. The range of typical drift specifi-
cations for the total resistance of the mechanical poten-
tiometer is from ±100ppm/°C to ±300ppm/°C. Typical
drift versus temperature specification for the digital
potentiometer is around ±800ppm/°C. With both types
of potentiometers, the temperature coefficient differ-
ence between the A element (resistance between PA
and PW minus the wiper resistance) and B element
(resistance between PB and PW minus the wiper resis-
tance) is very low.
The magnitude of these specifications may or may not
affect the performance of the circuit. If it is found that
they do, numerous circuit ideas are available in Micro-
chip’s application note, AN-691, ”Optimizing Digital
Potentiometer Circuits to Reduce Absolute and Tem-
perature Variations”.
Power Rating
Mechanical potentiometers can sustain more power
dissipation than the digital potentiometers. It is not
unusual to have a mechanical potentiometer that is
capable of dissipating 0.5W @ 70°C (usually specified
for 1000 hours). However, the wiper of the mechanical
potentiometer usually can only conduct up to 1mA of
current. This becomes a limitation if the potentiometer
is configured so that the wiper is directly connected to
terminal A or terminal B.
The digital potentiometer is capable of conducting
power up to 0.0055W @ 70°C. It also has a 1mA max-
imum wiper current restriction.

## Page 4

AN219
DS00219A-page 4 Preliminary   2000 Microchip Technology Inc.
Temperature Range
Both the mechanical potentiometer and digital potenti-
ometer are specified to be able to operate over indus-
trial temperature range of -40°C to 85°C. Most typically,
the mechanical potentiometer is specified to operate
over the military range of -55°C to 125°C.
CONCLUSION
Mechanical potentiometers have advantages in terms
of having a wide variety of values available and tighter
specifications such as nominal resistance, tolerance,
temperature coefficient, power rating and temperature
range specifications. But in many applications the over-
riding factors are related to environmental and reliabil-
ity issues. These characteristics are not necessarily
specified by the mechanical potentiometer vendor.
Digital potentiometers go hand in hand with the drive
towards digital system control. This type of potentiom-
eter is considerably more robust that its predecessor,
the mechanical potentiometer, in terms of environmen-
tal exposure issues and longevity with repeated use of
the wiper. But beyond the reliability issues, the digital
potentiometer offers hands-off programmability. This
programmability also allows the user to repeatedly and
reliably return to the same wiper position.
REFERENCES:
Baker, Bonnie C., “Optimizing Digital Potentiometer
Circuits to Reduce Absolute and Temperature Varia-
tions”, AN-691, Microchip Technology Inc.
Todd, Carl David, “The Potentiometer Handbook:
Users’ Guide to Cost-effective Applications”, McGraw-
Hill, 1975.
Baker, Bonnie C., “Using a Digital Potentiometer to
Optimize a Precision Single Supply Photo Detection
Circuit”, AN-692, Microchip Technology Inc.
Baker, Bonnie C., “Using Digital Potentiometers to
Design Low Pass Adjustable Filters”, AN-737, 
Microchip Technology Inc.

## Page 5

 2002 Microchip Technology Inc.
Information contained in this publication regarding device
applications and the like is intended through suggestion only
and may be superseded by updates. It is your responsibility to
ensure that your application meets with your specifications.
No representation or warranty is given and no liability is
assumed by Microchip Technology Incorporated with respect
to the accuracy or use of such information, or infringement of
patents or other intellectual property rights arising from such
use or otherwise. Use of Microchip’s products as critical com-
ponents in life support systems is not authorized except with
express written approval by Microchip. No licenses are con-
veyed, implicitly or otherwise, under any intellectual property
rights.
Trademarks
The Microchip name and logo, the Microchip logo, FilterLab,
KEELOQ, microID, MPLAB, PIC, PICmicro, PICMASTER,
PICSTART, PRO MATE, SEEVAL and The Embedded Control
Solutions Company are registered trademarks of Microchip Tech-
nology Incorporated in the U.S.A. and other countries.
dsPIC, ECONOMONITOR, FanSense, FlexROM, fuzzyLAB,
In-Circuit Serial Programming, ICSP, ICEPIC, microPort,
Migratable Memory, MPASM, MPLIB, MPLINK, MPSIM,
MXDEV, PICC, PICDEM, PICDEM.net, rfPIC, Select Mode
and Total Endurance are trademarks of Microchip Technology
Incorporated in the U.S.A.
Serialized Quick Turn Programming (SQTP) is a service mark
of Microchip Technology Incorporated in the U.S.A.
All other trademarks mentioned herein are property of their
respective companies.
© 2002, Microchip Technology Incorporated, Printed in the
U.S.A., All Rights Reserved.
 Printed on recycled paper.
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
Note the following details of the code protection feature on PICmicro ® MCUs.
 The PICmicro family meets the specifications contained in the Microchip Data Sheet.
 Microchip believes that its family of PICmicro microcontrollers is one of the most secure products of its kind on the market today, 
when used in the intended manner and under normal conditions.
 There are dishonest and possibly illegal methods used to breach the code protection feature. All of these methods, to our knowl -
edge, require using the PICmicro microcontroller in a manner outside the operating specifications contained in the data sheet. 
The person doing so may be engaged in theft of intellectual property.
 Microchip is willing to work with the customer who is concerned about the integrity of their code.
 Neither Microchip nor any other semiconductor manufacturer can guarantee the security of their code. Code protection does not 
mean that we are guaranteeing the product as “unbreakable”.
 Code protection is constantly evolving. We at Microchip are committed to continuously improving the code protection features of 
our product.
If you have any further questions about this matter, please contact the local sales office nearest to you.

## Page 6

 2002 Microchip Technology Inc.
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
Boston
2 Lan Drive, Suite 120
Westford, MA  01886
Tel: 978-692-3848  Fax: 978-692-3821
Chicago
333 Pierce Road, Suite 180
Itasca, IL  60143
Tel: 630-285-0071 Fax: 630-285-0075
Dallas
4570 Westgrove Drive, Suite 160
Addison, TX 75001
Tel: 972-818-7423  Fax: 972-818-2924
Detroit
Tri-Atria Office Building 
32255 Northwestern Highway, Suite 190
Farmington Hills, MI  48334
Tel: 248-538-2250 Fax: 248-538-2260
Kokomo
2767 S. Albright Road 
Kokomo, Indiana  46902
Tel: 765-864-8360 Fax: 765-864-8387
Los Angeles
18201 Von Karman, Suite 1090
Irvine, CA  92612
Tel: 949-263-1888  Fax: 949-263-1338
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
Microchip Technology Consulting (Shanghai)
Co., Ltd., Beijing Liaison Office
Unit 915
Bei Hai Wan Tai Bldg.
No. 6 Chaoyangmen Beidajie 
Beijing, 100027, No. China
Tel: 86-10-85282100 Fax: 86-10-85282104
China - Chengdu
Microchip Technology Consulting (Shanghai)
Co., Ltd., Chengdu Liaison Office
Rm. 2401, 24th Floor, 
Ming Xing Financial Tower
No. 88 TIDU Street
Chengdu 610016, China
Tel: 86-28-6766200  Fax: 86-28-6766599
China - Fuzhou
Microchip Technology Consulting (Shanghai)
Co., Ltd., Fuzhou Liaison Office
Unit 28F, World Trade Plaza
No. 71 Wusi Road
Fuzhou 350001, China
Tel: 86-591-7503506  Fax: 86-591-7503521
China - Shanghai
Microchip Technology Consulting (Shanghai)
Co., Ltd.
Room 701, Bldg. B
Far East International Plaza
No. 317 Xian Xia Road
Shanghai, 200051
Tel: 86-21-6275-5700  Fax: 86-21-6275-5060
China - Shenzhen
Microchip Technology Consulting (Shanghai)
Co., Ltd., Shenzhen Liaison Office
Rm. 1315, 13/F, Shenzhen Kerry Centre,
Renminnan Lu
Shenzhen 518001, China
Tel: 86-755-2350361  Fax: 86-755-2366086
Hong Kong
Microchip Technology Hongkong Ltd.
Unit 901-6, Tower 2, Metroplaza
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
Microchip Technology Japan K.K.
Benex S-1 6F
3-18-20, Shinyokohama
Kohoku-Ku, Yokohama-shi
Kanagawa, 222-0033, Japan
Tel: 81-45-471- 6166  Fax: 81-45-471-6122
Korea
Microchip Technology Korea
168-1, Youngbo Bldg. 3 Floor
Samsung-Dong, Kangnam-Ku
Seoul, Korea 135-882
Tel: 82-2-554-7200  Fax: 82-2-558-5934
Singapore
Microchip Technology Singapore Pte Ltd.
200 Middle Road
#07-02 Prime Centre
Singapore, 188980
Tel:  65-6334-8870  Fax: 65-6334-8850
Taiwan
Microchip Technology Taiwan
11F-3, No. 207
Tung Hua North Road
Taipei, 105, Taiwan
Tel: 886-2-2717-7175  Fax: 886-2-2545-0139
EUROPE
Denmark
Microchip Technology Nordic ApS
Regus Business Centre
Lautrup hoj 1-3
Ballerup DK-2750 Denmark
Tel: 45 4420 9895 Fax: 45 4420 9910
France
Microchip Technology SARL
Parc d’Activite du Moulin de Massy
43 Rue du Saule Trapu
Batiment A - ler Etage
91300 Massy, France
Tel: 33-1-69-53-63-20  Fax: 33-1-69-30-90-79
Germany
Microchip Technology GmbH
Gustav-Heinemann Ring 125
D-81739 Munich, Germany
Tel: 49-89-627-144 0  Fax: 49-89-627-144-44
Italy
Microchip Technology SRL
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
03/01/02
WORLDWIDE SALES AND SERVICE
