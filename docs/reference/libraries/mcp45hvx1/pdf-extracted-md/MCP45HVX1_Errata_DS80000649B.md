# MCP45HVX1 Rev. A1 Silicon/Data Sheet Errata

- Source PDF: `../MCP45HVX1_Errata_DS80000649B.pdf`
- Extraction tool: pdfplumber
- Page count: 6
- SHA256: `6b8ee344f3ca581bb51153bc1fb2ea5dbcb457f94903808fff974886088c9bd3`

## Page 1

MCP45HVX1
MCP45HVX1 Rev. A1 Silicon/Data Sheet Errata
The MCP45HVX1 parts that you have received 2. Module: I2C Interface
conform functionally to the current device data sheet
The I2C General Call command (see Figure 1)
(DS20005304A) except for the anomalies described in
does not properly decode the four address bits
this document.
(b7:b4) in the second byte with respect to the
All the issues discussed in the following pages will be two command bits (b3:b2). If the received
addressed in future revisions of the MCP45HVX1 silicon. address is invalid for the specified command,
then the device will use the address from the
Silicon Errata Issues previous valid command received. If either of
these addresses was a valid combination for the
Note: This document summarizes all silicon specified command, then the MCP45HVX1 will
errata issues from all revisions of silicon, generate an ACK on this second byte and
previous as well as current. operate the command.
Work around
1. Module: I2CTM Interface
If the second byte of the I2C General Call
The MCP45HVX1 interface will accept the serial command is a different value than the three
data that was intended for other devices on the reserved commands or the four Microchip-specific
I2CTM bus. commands, then the MCP45HVX1 device would
need to be on a separate I2C bus where those
This occurs when the other device on the same
I2C bus Acknowledges the I2C Control Byte (con- commands would not occur.
tains the I2C Slave Address). This causes the
MCP45HVX1 to accept the subsequent serial data
until either a Stop or Restart condition occurs. The
MCP45HVX1 will interpret this received data per
the defined command definitions.
Note: If the MCP45HVX1 interprets the
data as a Read command, the I2C
SDA signal will result in a value of the
expected data (of the addressed
device) logically ANDed with the read
data of the MCP45HVX1.
Work around
Each MCP45HVX1 device would need to be on
a unique I2C bus with no other I2C devices.
 2015 Microchip Technology Inc. DS80000649B-page 1

## Page 2

MCP45HVX1
3. Module: I2C Interface
The I2C General Call command (see Figure 1)
does not properly decode the Hardware General
Call bit (b0) in the second byte. The device
ignores the state of this bit, and responds
according to the state of the previous seven bits.
Work around
None.
Format 1:
Second Byte
S 0 0 0 0 0 0 0 0 A X X X X X X X 0 A P
General Call Address 7-bit Command
Reserved 7-bit Commands (By I2CTM Specification - NXP UM10204, Ver. 05 October 2012)
‘0000 011’b – Reset and write programmable part of slave address by hardware.
‘0000 010’b – Write programmable part of slave address by hardware.
‘0000 000’b – NOT Allowed
MCP45HVX1 7-bit Commands
‘1000 01x’b – Increment Wiper 0 Register.
‘1000 10x’b – Decrement Wiper 0 Register.
Format 2:
The following is a Microchip extension to this General Call format
Second Byte Third Byte
S 0 0 0 0 0 0 0 0 A X X X X X X X 0 A d d d d d d d d A P
General Call Address 7-bit Command “0” for General Call Command
MCP45HVX1 7-bit Commands
‘1000 00x’b - Write Next Byte (Third Byte) to Volatile Wiper 0 Register.
‘1100 00x’b - Write Next Byte (Third Byte) to TCON Register.
Format 3:
The following is a “Hardware General Call” format
Second Byte n occurrences of (Data + A)
S 0 0 0 0 0 0 0 0 A X X X X X X X 1 A X X X X X X X X A P
General Call Address 7-bit Command
This indicates a “Hardware General Call”
MCP45HVX1 will ignore this byte and
all following bytes (and A) until
a Stop bit (P) is encountered.
FIGURE 1: General Call Formats.
DS80000649B-page 2  2015 Microchip Technology Inc.

## Page 3

MCP45HVX1
Data Sheet Clarifications APPENDIX A: DOCUMENT
REVISION HISTORY
The following typographic corrections and clarifications
are to be noted for the latest version of the device data
Revision B (7/2015)
sheet (DS20005304A):
• Added two dates to Appendix B: “Silicon
None.
Revision History”.
Revision A (3/2015)
• Initial release of this document.
 2015 Microchip Technology Inc. DS80000649B-page 3

## Page 4

MCP45HVX1
APPENDIX B: SILICON REVISION Package Marking Information
HISTORY
14-Lead TSSOP (4.4 mm)
The following table and package marking information
indicates how to determine the revision of the
MCP45HVX1 device. The revision information can be
determined by the Year and Week Code of the XXXXXXXX
manufacture printed on the device.
YWW
TABLE B-1: SILICON REVISION/DEVICE (cid:59)
MARKING
NNN
YYWWNNN
Silicon
Comments
Revision
Start Date End Date
Rev A2 1520NNN — Current Sample
Stock,
Production Start
Date 1520NNN
20-Lead QFN (5x5x0.9 mm)
Rev A1 — 1518NNN
Legend: “N” is any alphanumeric character.
Legend: XX...X Customer-specific information
Y Year code
(last digit of calendar year)
YY Year code
(last 2 digits of calendar year)
WW Week code
(week of January 1 is
week ‘01’)
NNN Alphanumeric traceability code
e3 RoHS Compliant JEDEC
designator for Matte Tin (Sn)
Note: In the event the full Microchip part number
cannot be marked on one line, it will be
carried over to the next line, thus limiting
the number of available characters for
customer-specific information.
* Standard marking consists of Microchip part
number, year code, week code, and traceability
code.
DS80000649B-page 4  2015 Microchip Technology Inc.

## Page 5

Note the following details of the code protection feature on Microchip devices:
• Microchip products meet the specification contained in their particular Microchip Data Sheet.
• Microchip believes that its family of products is one of the most secure families of its kind on the market today, when used in the
intended manner and under normal conditions.
• There are dishonest and possibly illegal methods used to breach the code protection feature. All of these methods, to our
knowledge, require using the Microchip products in a manner outside the operating specifications contained in Microchip’s Data
Sheets. Most likely, the person doing so is engaged in theft of intellectual property.
• Microchip is willing to work with the customer who is concerned about the integrity of their code.
• Neither Microchip nor any other semiconductor manufacturer can guarantee the security of their code. Code protection does not
mean that we are guaranteeing the product as “unbreakable.”
Code protection is constantly evolving. We at Microchip are committed to continuously improving the code protection features of our
products. Attempts to break Microchip’s code protection feature may be a violation of the Digital Millennium Copyright Act. If such acts
allow unauthorized access to your software or other copyrighted work, you may have a right to sue for relief under that Act.
Information contained in this publication regarding device Trademarks
applications and the like is provided only for your convenience
The Microchip name and logo, the Microchip logo, dsPIC,
and may be superseded by updates. It is your responsibility to
FlashFlex, flexPWR, JukeBlox, KEELOQ, KEELOQ logo, Kleer,
ensure that your application meets with your specifications.
LANCheck, MediaLB, MOST, MOST logo, MPLAB,
MICROCHIP MAKES NO REPRESENTATIONS OR OptoLyzer, PIC, PICSTART, PIC32 logo, RightTouch, SpyNIC,
WARRANTIES OF ANY KIND WHETHER EXPRESS OR
SST, SST Logo, SuperFlash and UNI/O are registered
IMPLIED, WRITTEN OR ORAL, STATUTORY OR
trademarks of Microchip Technology Incorporated in the
OTHERWISE, RELATED TO THE INFORMATION,
U.S.A. and other countries.
INCLUDING BUT NOT LIMITED TO ITS CONDITION,
QUALITY, PERFORMANCE, MERCHANTABILITY OR The Embedded Control Solutions Company and mTouch are
FITNESS FOR PURPOSE. Microchip disclaims all liability registered trademarks of Microchip Technology Incorporated
arising from this information and its use. Use of Microchip in the U.S.A.
devices in life support and/or safety applications is entirely at Analog-for-the-Digital Age, BodyCom, chipKIT, chipKIT logo,
the buyer’s risk, and the buyer agrees to defend, indemnify and CodeGuard, dsPICDEM, dsPICDEM.net, ECAN, In-Circuit
hold harmless Microchip from any and all damages, claims, Serial Programming, ICSP, Inter-Chip Connectivity, KleerNet,
suits, or expenses resulting from such use. No licenses are KleerNet logo, MiWi, MPASM, MPF, MPLAB Certified logo,
conveyed, implicitly or otherwise, under any Microchip MPLIB, MPLINK, MultiTRAK, NetDetach, Omniscient Code
intellectual property rights. Generation, PICDEM, PICDEM.net, PICkit, PICtail,
RightTouch logo, REAL ICE, SQI, Serial Quad I/O, Total
Endurance, TSHARC, USBCheck, VariSense, ViewSpan,
WiperLock, Wireless DNA, and ZENA are trademarks of
Microchip Technology Incorporated in the U.S.A. and other
countries.
SQTP is a service mark of Microchip Technology Incorporated
in the U.S.A.
Silicon Storage Technology is a registered trademark of
Microchip Technology Inc. in other countries.
GestIC is a registered trademarks of Microchip Technology
Germany II GmbH & Co. KG, a subsidiary of Microchip
Technology Inc., in other countries.
All other trademarks mentioned herein are property of their
respective companies.
© 2015, Microchip Technology Incorporated, Printed in the
U.S.A., All Rights Reserved.
ISBN: 978-1-63277-563-4
QUALITY MANAGEMENT SYSTEM
Microchip received ISO/TS-16949:2009 certification for its worldwide
headquarters, design and wafer fabrication facilities in Chandler and
CERTIFIED BY DNV Tempe, Arizona; Gresham, Oregon and design centers in California
and India. The Company’s quality system processes and procedures
== ISO/TS 16949 == are for its PIC® MCUs and dsPIC® DSCs, KEELOQ® code hopping
devices, Serial EEPROMs, microperipherals, nonvolatile memory and
analog products. In addition, Microchip’s quality system for the design
and manufacture of development systems is ISO 9001:2000 certified.
 2015 Microchip Technology Inc. DS80000649B-page 5

## Page 6

Worldwide Sales and Service
AMERICAS ASIA/PACIFIC ASIA/PACIFIC EUROPE
Corporate Office Asia Pacific Office China - Xiamen Austria - Wels
2355 West Chandler Blvd. Suites 3707-14, 37th Floor Tel: 86-592-2388138 Tel: 43-7242-2244-39
Chandler, AZ 85224-6199 Tower 6, The Gateway Fax: 86-592-2388130 Fax: 43-7242-2244-393
Tel: 480-792-7200 Harbour City, Kowloon China - Zhuhai Denmark - Copenhagen
Fax: 480-792-7277 Hong Kong Tel: 45-4450-2828
Tel: 86-756-3210040
Technical Support: Tel: 852-2943-5100 Fax: 45-4485-2829
Fax: 86-756-3210049
http://www.microchip.com/
Fax: 852-2401-3431 France - Paris
support India - Bangalore
Web Address: Australia - Sydney Tel: 91-80-3090-4444 Tel: 33-1-69-53-63-20
Tel: 61-2-9868-6733 Fax: 33-1-69-30-90-79
www.microchip.com Fax: 91-80-3090-4123
Fax: 61-2-9868-6755
Germany - Dusseldorf
Atlanta India - New Delhi
China - Beijing Tel: 49-2129-3766400
Duluth, GA Tel: 91-11-4160-8631
Tel: 86-10-8569-7000
Tel: 678-957-9614 Fax: 91-11-4160-8632 Germany - Munich
Fax: 86-10-8528-2104
Fax: 678-957-1455 India - Pune Tel: 49-89-627-144-0
China - Chengdu Fax: 49-89-627-144-44
Austin, TX Tel: 91-20-3019-1500
Tel: 86-28-8665-5511
Tel: 512-257-3370 Japan - Osaka Germany - Pforzheim
Fax: 86-28-8665-7889 Tel: 49-7231-424750
Boston Tel: 81-6-6152-7160
Westborough, MA China - Chongqing Fax: 81-6-6152-9310 Italy - Milan
Tel: 774-760-0087 Tel: 86-23-8980-9588 Tel: 39-0331-742611
Japan - Tokyo
Fax: 774-760-0088 Fax: 86-23-8980-9500 Fax: 39-0331-466781
Tel: 81-3-6880- 3770
Chicago China - Dongguan Fax: 81-3-6880-3771 Italy - Venice
Itasca, IL Tel: 86-769-8702-9880 Tel: 39-049-7625286
Korea - Daegu
Tel: 630-285-0071 China - Hangzhou Tel: 82-53-744-4301 Netherlands - Drunen
Fax: 630-285-0075 Tel: 86-571-8792-8115 Fax: 82-53-744-4302 Tel: 31-416-690399
Cleveland Fax: 86-571-8792-8116 Fax: 31-416-690340
Korea - Seoul
Independence, OH China - Hong Kong SAR Tel: 82-2-554-7200 Poland - Warsaw
Tel: 216-447-0464 Tel: 852-2943-5100 Fax: 82-2-558-5932 or Tel: 48-22-3325737
Fax: 216-447-0643
Fax: 852-2401-3431 82-2-558-5934 Spain - Madrid
Dallas China - Nanjing Malaysia - Kuala Lumpur Tel: 34-91-708-08-90
Addison, TX Tel: 86-25-8473-2460 Tel: 60-3-6201-9857 Fax: 34-91-708-08-91
Tel: 972-818-7423
Fax: 86-25-8473-2470 Fax: 60-3-6201-9859 Sweden - Stockholm
Fax: 972-818-2924
China - Qingdao Malaysia - Penang Tel: 46-8-5090-4654
Detroit
Novi, MI Tel: 86-532-8502-7355 Tel: 60-4-227-8870 UK - Wokingham
Tel: 248-848-4000 Fax: 86-532-8502-7205 Fax: 60-4-227-4068 Tel: 44-118-921-5800
Houston, TX China - Shanghai Philippines - Manila Fax: 44-118-921-5820
Tel: 281-894-5983 Tel: 86-21-5407-5533 Tel: 63-2-634-9065
Fax: 86-21-5407-5066 Fax: 63-2-634-9069
Indianapolis
Noblesville, IN China - Shenyang Singapore
Tel: 317-773-8323 Tel: 86-24-2334-2829 Tel: 65-6334-8870
Fax: 317-773-5453 Fax: 86-24-2334-2393 Fax: 65-6334-8850
Los Angeles China - Shenzhen Taiwan - Hsin Chu
Mission Viejo, CA Tel: 86-755-8864-2200 Tel: 886-3-5778-366
Tel: 949-462-9523 Fax: 86-755-8203-1760 Fax: 886-3-5770-955
Fax: 949-462-9608 China - Wuhan Taiwan - Kaohsiung
New York, NY Tel: 86-27-5980-5300 Tel: 886-7-213-7828
Tel: 631-435-6000 Fax: 86-27-5980-5118 Taiwan - Taipei
San Jose, CA China - Xian Tel: 886-2-2508-8600
Tel: 408-735-9110 Tel: 86-29-8833-7252 Fax: 886-2-2508-0102
Canada - Toronto Fax: 86-29-8833-7256 Thailand - Bangkok
Tel: 905-673-0699 Tel: 66-2-694-1351
Fax: 905-673-6509 Fax: 66-2-694-1350
01/27/15
DS80000649B-page 6  2015 Microchip Technology Inc.
