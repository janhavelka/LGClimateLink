# MCP45HVX1 Typical Performance Curves - Extracted Text

- Source PDF: `../MCP45HVX1_Typical_Performance_Curves_DS20005307A.pdf`
- Manufacturer URL: https://ww1.microchip.com/downloads/en/DeviceDoc/20005307A.pdf
- Extraction date: 2026-05-09
- Page count: 60
- SHA256: `BC6658231BE377B42E5370FD80C62E48AEA26A38A828F651B3A09F4FA15CB32C`
- Notes: Raw text extracted with pypdf. Tables, equations, and figures may require checking against the source PDF.

## Page 1

 2014 Microchip Technology Inc. DS20005307A-page 1
MCP45HVX1
1.0 TYPICAL PERFORMANCE CURVES
Note: Unless otherwise indicated, TA = +25°C, VL = 5.5V, DGND = V-, V+ = 36V.
FIGURE 1-1: Device Digital Supply Static 
Current (IDDD) vs. Temperature and V+ Voltage 
(VL = 5.5V, A = V+, B = V-, DGND = V-, 
V+ = 10V, 20V and 36V). 
FIGURE 1-2: Device Digital Supply Active 
Current (IDDD) vs. Temperature and V+ Voltage 
(VL = 5.5V, FSCL = 3.4 MHz, A = V+, B = V-, 
DGND = V-, V+ = 10V, 20V and 36V).
FIGURE 1-3: Device Analog Supply Static 
Current (IDDA) vs. Temperature and V+ Voltage 
(VL = 5.5V, A = B =V-, DGND = V-, 
V+ = 10V, 20V and 36V).
FIGURE 1-4: Digital Supply POR Voltage 
(VDPOR) vs. Temperature and V+ Voltage 
(V+ = 10V and 36V).
Note: The following performance graphs are for the devices that are documented in the MCP45HVX1 data sheet
(DS20005304). This document allows the MCP45HVX1 data sheet’s functional description to be in PDF
format with a file size smaller than the 10 MB limit of many email file servers.
The graphs and tables provided following this note are a statistical summary based on a limited number of
samples and are provided for informational purposes only. The performance characteristics listed herein
are not tested or guaranteed. In some graphs or tables, the data presented may be outside the specified
operating range (e.g., outside specified power supply range) and therefore, outside the warranted range.
3.00
3.25
3.50
3.75
4.00
4.25
4.50
4.75
5.00
Ͳ40 Ͳ2 00 2 04 06 08 0 1 0 0 1 2 0
IDD Static (Digital) (uA)
Temperature (°C)
V+=10V
V+=20V
V+=36V
500
504
508
512
516
Ͳ40 Ͳ2 00 2 04 06 08 0 1 0 0 1 2 0
IDD Active (Digital) (uA)
Temperature (°C)
V+=10V
V+=20V
V+=36V
1.25
1.50
1.75
2.00
2.25
Ͳ40 Ͳ2 00 2 04 06 08 0 1 0 0 1 2 0
IDD Analog (uA)
Temperature (°C)
V+=10V
V+=20V
V+=36V
1.0
1.1
1.2
1.3
1.4
1.5
1.6
1.7
1.8
Ͳ40 Ͳ2 00 2 04 06 08 0 1 0 0 1 2 0
Digital POR Voltage - V+ Powered (V)
Temperature (°C)
V+=10V
V+=36V
Typical Performance Curves

## Page 2

MCP45HVX1
DS20005307A-page 2  2014 Microchip Technology Inc.
Note: Unless otherwise indicated, TA = +25°C, VL = 5.5V, DGND = V-, V+ = 36V.
FIGURE 1-5: Digital Supply POR Voltage 
(VDPOR) vs. Temperature (Analog Supply (V+/V-) 
Not Powered).
FIGURE 1-6: Analog Supply POR Voltage 
(VAPOR) vs. Temperature 
(Digital Supply (VL/DGND) Not Powered).
1.0
1.1
1.2
1.3
1.4
1.5
Ͳ40 Ͳ2 00 2 04 06 08 0 1 0 0 1 2 0
Digtal POR Voltage -
Write / Read Wiper Register (V)
Temperature (°C)
WiperRegister
WriteRead
1.20
1.45
1.70
1.95
2.20
Ͳ40 Ͳ2 00 2 04 06 08 0 1 0 0 1 2 0
Analog POR Voltage - Digital not Powered 
(V)
Temperature (°C)
AnalogPOR

## Page 3

 2014 Microchip Technology Inc. DS20005307A-page 3
MCP45HVX1
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-7: Total Unadjusted Error (Pot. 
Mode) (VW) vs. Wiper Setting, RAB Resistance 
and Temperature (8-bit: VL = 1.8V, 2.7V, 5.5V, 
A = V+, B = V-, DGND = V-, V+ = 36V). 
FIGURE 1-8: Total Unadjusted Error (Pot. 
Mode) (VW) vs. Wiper Setting, RAB Resistance 
and Temperature (8-bit: VL = 1.8V, 2.7V, 5.5V, 
A = V+, B = V-, DGND = V-, V+ = 20V). 
FIGURE 1-9: Total Unadjusted Error (Pot. 
Mode) (VW) vs. Wiper Setting, RAB Resistance 
and Temperature (8-bit: VL = 1.8V, 2.7V, 5.5V, 
A = V+, B = V-, DGND = V-, V+ = 10V).
FIGURE 1-10: Wiper Resistance (RW) vs. 
Wiper Setting, RAB Resistance, IW Current and 
Temperature (8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-).   
Ͳ4
Ͳ2
0
2
4
6
8
10
12
Unadjusted Error (LSb)
Ͳ40C5k +25C5k +85C5k +125C5k
Ͳ40C10k +25C10k +85C10k +125C10k
Ͳ40C50k +25C50K +85C50k +125C50k
Ͳ40C100k +25C100k +85C100k +125C100k+125C
Ͳ40C
+85C+25C
Ͳ12
Ͳ10
Ͳ8
Ͳ6
4
0 32 64 96 128 160 192 224 256
Total U
DAC Wiper Code
TotalUnadjustedErrorimproveswithlower
temperaturesandincreasedRABresistance
Ͳ4
Ͳ2
0
2
4
6
8
10
12
Unadjusted Error (LSb)
Ͳ40C5k +25C5k +85C5k +125C5k
Ͳ40C10k +25C10k +85C10k +125C10k
Ͳ40C50k +25C50K +85C50k +125C50k
Ͳ40C100k +25C100k +85C100k +125C100k
+125C
Ͳ40C
+85C
+25C
Ͳ12
Ͳ10
Ͳ8
Ͳ6
4
0 32 64 96 128 160 192 224 256
Total U
DAC Wiper Code
TotalUnadjustedErrorimproveswithlower
temperaturesandincreasedRABresistance
Ͳ4
Ͳ2
0
2
4
6
8
10
12
Unadjusted Error (LSb)
Ͳ40C5k +25C5k +85C5k +125C5k
Ͳ40C10k +25C10k +85C10k +125C10k
Ͳ40C50k +25C50K +85C50k +125C50k
Ͳ40C100k +25C100k +85C100k +125C100k
+125C
Bow caused by analog switch leakage
+125C
Ͳ40C
+85C
+25C
Ͳ12
Ͳ10
Ͳ8
Ͳ6
4
0 32 64 96 128 160 192 224 256
Total U
DAC Wiper Code
Bowcausedbyanalogswitchleakage
athighertemperaturesandthe
lowwipercurrent(IW,=83uA)used
inthesemeasurements
TotalUnadjustedErrorimproveswithlower
temperaturesandincreasedRABresistance
600
800
1000
1200
1400
esistance RW (:)
+85C5kIW=1.7mA +125C5kIW=1.7mA
+85C10kIW=830uA +125C10kIW=830uA
+85C50kIW=170uA +125C50kIW=170uA
+85C50kIW=330uA +125C50kIW=330uA
+85C100kIW=83uA +125C100kIW=83uA
+85C100kIW=170uA +125C100kIW=170uA
+85C100kIW=300uA +125C100kIW=300uA
100k:,IW =83uA(V+=10V)
100k:,IW =170uA(V+=20V)
50k:,IW =170uA(V+=10V)
100k:,IW =300uA(V+=36V)
Increasedwiperresistance(RW)occurs
duetoincreasedanalog switchleakage at
highertemperatures(suchas+125C)and
largerRAB resistances,whichusedsmall
wipercurrent(IW).
+125C +85C
+125C +85C
+125C +85C
+125C +85C
50k:,IW =330uA(V+=20V)
10k:,IW =830uA(V+=10V)
5k: I 17 A (V 10V)
0
200
400
0 32 64 96 128 160 192 224 256
Wiper Re
DAC Wiper Code
5k:,IW =1.7mA(V+=10V)

## Page 4

MCP45HVX1
DS20005307A-page 4  2014 Microchip Technology Inc.
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V
FIGURE 1-11: Full-Scale Error (Pot. Mode) 
(FSE) vs. Temperature, RAB Resistance and 
V+ Voltage (8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V).
FIGURE 1-12: Zero Scale Error (Pot. Mode) 
(FSE) vs. Temperature, RAB Resistance and 
V+ Voltage (8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V).
FIGURE 1-13: VW PPM / °C (Pot. Mode) vs. 
Temperature, RAB Resistance and V+ Voltage 
( ( (VW(code = n, +125°C) – VW(code = n, -40°C))/ 
VW(code = 255, +25°C)) * 1,000,000/+165°C) 
(8-bit: VL = 1.8V, 2.7V, 5.5V, 
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V).
FIGURE 1-14: Full-Scale Error (Pot. Mode) 
(FSE) vs. Temperature, RAB Resistance and 
V+ Voltage (7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V).
FIGURE 1-15: Zero Scale Error (Pot. Mode) 
(FSE) vs. Temperature, RAB Resistance and 
V+ Voltage (7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V).
FIGURE 1-16: VW PPM / °C (Pot. Mode) vs. 
Temperature, RAB Resistance and V+ Voltage 
( ( (VW(code = n, +125°C) – VW(code = n, -40°C))/ 
VW(code = 127, +25°C)) * 1,000,000/+165°C) 
(7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V).
8
Ͳ7
Ͳ6
Ͳ5
Ͳ4
Ͳ3
Ͳ2
Ͳ1
0
e Error: 8-bit (LSb)
Ͳ12
Ͳ11
Ͳ10
Ͳ9
Ͳ8
Ͳ40 Ͳ20 0 20 40 60 80 100 120
Full Scale
Temperature (°C)
5kͲ10V 5kͲ20V 5kͲ36V
10kͲ10V 10kͲ20V 10kͲ36V
50kͲ10V 50kͲ20V 50kͲ36V
100kͲ10V 100kͲ20V 100kͲ36V
4
5
6
7
8
9
10
11
12
e Error: 8-bit (LSb)
5kͲ10V 5kͲ20V 5kͲ36V
10kͲ10V 10kͲ20V 10kͲ36V
50kͲ10V 50kͲ20V 50kͲ36V
100kͲ10V 100kͲ20V 100kͲ36V
0
1
2
3
4
Ͳ40 Ͳ20 0 20 40 60 80 100 120
Zero Scale
Temperature (°C)
Ͳ50
Ͳ30
Ͳ10
10
30
50
70
90
110
130
150
PPM per °C
5kͲ10V 5kͲ20V 5kͲ36V
10kͲ10V 10kͲ20V 10kͲ36V
50kͲ10V 50kͲ20V 50kͲ36V
100kͲ10V 100kͲ20V 100kͲ36V
Ͳ150
Ͳ130
Ͳ110
Ͳ90
Ͳ70
50
0 32 64 96 128 160 192 224 256
DAC Wiper Code
10V 20V 36V
8
Ͳ7
Ͳ6
Ͳ5
Ͳ4
Ͳ3
Ͳ2
Ͳ1
0
e Error: 7-bit (LSb)
Ͳ12
Ͳ11
Ͳ10
Ͳ9
Ͳ8
Ͳ40 Ͳ20 0 20 40 60 80 100 120
Full Scale
Temperature (°C)
5kͲ10V 5kͲ20V 5kͲ36V
10kͲ10V 10kͲ20V 10kͲ36V
50kͲ10V 50kͲ20V 50kͲ36V
100kͲ10V 100kͲ20V 100kͲ36V
4
5
6
7
8
9
10
11
12
e Error: 7-bit (LSb)
5kͲ10V 5kͲ20V 5kͲ36V
10kͲ10V 10kͲ20V 10kͲ36V
50kͲ10V 50kͲ20V 50kͲ36V
100kͲ10V 100kͲ20V 100kͲ36V
0
1
2
3
4
Ͳ40 Ͳ20 0 20 40 60 80 100 120
Zero Scale
Temperature (°C)
Ͳ50
Ͳ30
Ͳ10
10
30
50
70
90
110
130
150
PPM per °C
5kͲ10V 5kͲ20V 5kͲ36V
10kͲ10V 10kͲ20V 10kͲ36V
50kͲ10V 50kͲ20V 50kͲ36V
100kͲ10V 100kͲ20V 100kͲ36V
Ͳ150
Ͳ130
Ͳ110
Ͳ90
Ͳ70
50
0 1 63 24 86 48 09 6 1 1 2 1 2 8
DAC Wiper Code
10V 20V 36V

## Page 5

 2014 Microchip Technology Inc. DS20005307A-page 5
MCP45HVX1
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-17: Total Unadjusted Error (Pot. 
Mode) (VW) vs. Wiper Setting and Temperature 
(5.0 k, 8-bit: VL = 1.8V, 2.7V, 5.5V, 
A = V+, B = V-, DGND = V-, V+ = 36V).
FIGURE 1-18: Total Unadjusted Error (Pot. 
Mode) (VW) vs. Wiper Setting and Temperature 
(5.0 k, 8-bit: VL = 1.8V, 2.7V, 5.5V, 
A = V+, B = V-, DGND = V-, V+ = 20V).
FIGURE 1-19: Total Unadjusted Error (Pot. 
Mode) (VW) vs. Wiper Setting and Temperature 
(5.0 k, 8-bit: VL = 1.8V, 2.7V, 5.5V, 
A = V+, B = V-, DGND = V-, V+ = 10V).
FIGURE 1-20: Total Unadjusted Error (Pot. 
Mode) (VW) vs. Wiper Setting and Temperature 
(5.0 k, 7-bit: VL = 1.8V, 2.7V, 5.5V, 
A = V+, B = V-, DGND = V-, V+ = 36V).
FIGURE 1-21: Total Unadjusted Error (Pot. 
Mode) (VW) vs. Wiper Setting and Temperature 
(5.0 k, 7-bit: VL = 1.8V, 2.7V, 5.5V, 
A = V+, B = V-, DGND = V-, V+ = 20V).
FIGURE 1-22: Total Unadjusted Error (Pot. 
Mode) (VW) vs. Wiper Setting and Temperature 
(5.0 k, 7-bit: VL = 1.8V, 2.7V, 5.5V, 
A = V+, B = V-, DGND = V-, V+ = 10V).
Ͳ4
Ͳ2
0
2
4
6
8
10
12
Unadjusted Error (LSb)
Ͳ40C
+25C
+85C
+125C
Ͳ12
Ͳ10
Ͳ8
Ͳ6
4
0 32 64 96 128 160 192 224 256
Total U
DAC Wiper Code
Ͳ4
Ͳ2
0
2
4
6
8
10
12
Unadjusted Error (LSb)
Ͳ40C
+25C
+85C
+125C
Ͳ12
Ͳ10
Ͳ8
Ͳ6
4
0 32 64 96 128 160 192 224 256
Total U
DAC Wiper Code
Ͳ4
Ͳ2
0
2
4
6
8
10
12
Unadjusted Error (LSb)
Ͳ40C
+25C
+85C
+125C
Ͳ12
Ͳ10
Ͳ8
Ͳ6
4
0 32 64 96 128 160 192 224 256
Total U
DAC Wiper Code
Ͳ4
Ͳ2
0
2
4
6
8
10
12
Unadjusted Error (LSb)
Ͳ40C
+25C
+85C
+125C
Ͳ12
Ͳ10
Ͳ8
Ͳ6
4
0 1 63 24 86 48 09 6 1 1 2 1 2 8
Total U
DAC Wiper Code
Ͳ4
Ͳ2
0
2
4
6
8
10
12
Unadjusted Error (LSb)
Ͳ40C
+25C
+85C
+125C
Ͳ12
Ͳ10
Ͳ8
Ͳ6
4
0 1 63 24 86 48 09 6 1 1 2 1 2 8
Total U
DAC Wiper Code
Ͳ4
Ͳ2
0
2
4
6
8
10
12
Unadjusted Error (LSb)
Ͳ40C
+25C
+85C
+125C
Ͳ12
Ͳ10
Ͳ8
Ͳ6
4
0 1 63 24 86 48 09 6 1 1 2 1 2 8
Total U
DAC Wiper Code

## Page 6

MCP45HVX1
DS20005307A-page 6  2014 Microchip Technology Inc.
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-23: Total Unadjusted Error 
(Pot. Mode) (VW) vs. Wiper Setting (@ +25°C) 
(5.0 k, 8-bit: VL = 1.8V, 2.7V, 5.5V, 
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V). 
FIGURE 1-24: Full-Scale Error (Pot. Mode) 
(FSE) vs. Temperature and V+ Voltage
(5.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V).
 
FIGURE 1-25: Zero Scale Error (Pot. Mode) 
(ZSE) vs. Temperature and V+ Voltage
(5.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V). 
FIGURE 1-26: Total Unadjusted Error 
(Pot. Mode) (VW) vs. Wiper Setting (@ +25°C)
(5.0 k, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V). 
FIGURE 1-27: Full-Scale Error (Pot. Mode) 
(FSE) vs. Temperature and V+ Voltage
(5.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V). 
FIGURE 1-28: Zero Scale Error (Pot. Mode) 
(ZSE) vs. Temperature and V+ Voltage
(5.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V). 
Ͳ4
Ͳ2
0
2
4
6
8
10
12
Unadjusted Error (LSb)
10V+25C
20V+25C
36V+25C
Ͳ12
Ͳ10
Ͳ8
Ͳ6
4
0 32 64 96 128 160 192 224 256
Total U
DAC Wiper Code
8
Ͳ7
Ͳ6
Ͳ5
Ͳ4
Ͳ3
Ͳ2
Ͳ1
0
l Scale Error (LSb)
FSEͲ10V
FSEͲ20V
FSEͲ36V
Ͳ12
Ͳ11
Ͳ10
Ͳ9
Ͳ8
Ͳ40 Ͳ20 0 20 40 60 80 100 120
Full
Temperature (°C)
4
5
6
7
8
9
10
11
12
o Scale Error (LSb)
0
1
2
3
4
Ͳ40 Ͳ20 0 20 40 60 80 100 120
Zero
Temperature (°C)
ZSEͲ10V
ZSEͲ20V
ZSEͲ36V
Ͳ4
Ͳ2
0
2
4
6
8
10
12
Unadjusted Error (LSb)
10V+25C
20V+25C
36V+25C
Ͳ12
Ͳ10
Ͳ8
Ͳ6
4
0 1 63 24 86 48 09 6 1 1 2 1 2 8
Total U
DAC Wiper Code
8
Ͳ7
Ͳ6
Ͳ5
Ͳ4
Ͳ3
Ͳ2
Ͳ1
0
l Scale Error (LSb)
FSEͲ10V
FSEͲ20V
FSEͲ36V
Ͳ12
Ͳ11
Ͳ10
Ͳ9
Ͳ8
Ͳ40 Ͳ20 0 20 40 60 80 100 120
Full
Temperature (°C)
4
5
6
7
8
9
10
11
12
o Scale Error (LSb)
0
1
2
3
4
Ͳ40 Ͳ20 0 20 40 60 80 100 120
Zero
Temperature (°C)
ZSEͲ10V
ZSEͲ20V
ZSEͲ36V

## Page 7

 2014 Microchip Technology Inc. DS20005307A-page 7
MCP45HVX1
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-29: INL Error – Pot. Mode 
(P-INL) vs. Wiper Setting and Temperature 
(5.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V). 
FIGURE 1-30: INL Error – Pot. Mode 
(P-INL) vs. Wiper Setting and Temperature 
(5.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V, 
A = V+, B = V-, DGND = V-, V+ = 20V).
FIGURE 1-31: INL Error – Pot. Mode 
(P-INL) vs. Wiper Setting and Temperature 
(5.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 10V).
FIGURE 1-32: INL Error – Pot. Mode 
(P-INL) vs. Wiper Setting and Temperature 
(5.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V). 
FIGURE 1-33: INL Error – Pot. Mode 
(P-INL) vs. Wiper Setting and Temperature 
(5.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 20V).
FIGURE 1-34: INL Error – Pot. Mode 
(P-INL) vs. Wiper Setting and Temperature 
(5.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 10V).
Ͳ0.15
0.00
0.15
0.30
0.45
0.60
0.75
P -I N L  ( L S b )
Ͳ40C
+25C
+85C
+125C
Ͳ0.75
Ͳ0.60
Ͳ0.45
Ͳ0.30
0 32 64 96 128 160 192 224 256
P
DAC Wiper Code
Typical Device
Ͳ0.15
0.00
0.15
0.30
0.45
0.60
0.75
P -I N L  ( L S b )
Ͳ40C
+25C
+85C
+125C
Ͳ0.75
Ͳ0.60
Ͳ0.45
Ͳ0.30
0 32 64 96 128 160 192 224 256
P
DAC Wiper Code
Typical Device
Ͳ0.15
0.00
0.15
0.30
0.45
0.60
0.75
P -I N L  ( L S b )
Ͳ40C
+25C
+85C
+125C
Ͳ0.75
Ͳ0.60
Ͳ0.45
Ͳ0.30
0 32 64 96 128 160 192 224 256
P
DAC Wiper Code
Typical Device
Ͳ0.15
0.00
0.15
0.30
0.45
0.60
0.75
P -I N L  ( L S b )
Ͳ40C
+25C
+85C
+125C
Ͳ0.75
Ͳ0.60
Ͳ0.45
Ͳ0.30
0 1 63 24 86 48 09 6 1 1 2 1 2 8
P
DAC Wiper Code
Typical Device
Ͳ0.15
0.00
0.15
0.30
0.45
0.60
0.75
P -I N L  ( L S b )
Ͳ40C
+25C
+85C
+125C
Ͳ0.75
Ͳ0.60
Ͳ0.45
Ͳ0.30
0 1 63 24 86 48 09 6 1 1 2 1 2 8
P
DAC Wiper Code
Typical Device
Ͳ0.15
0.00
0.15
0.30
0.45
0.60
0.75
P -I N L  ( L S b )
Ͳ40C
+25C
+85C
+125C
Ͳ0.75
Ͳ0.60
Ͳ0.45
Ͳ0.30
0 1 63 24 86 48 09 6 1 1 2 1 2 8
P
DAC Wiper Code
Typical Device

## Page 8

MCP45HVX1
DS20005307A-page 8  2014 Microchip Technology Inc.
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-35: INL Error – Pot. Mode 
(P-INL) vs. Wiper Setting (@ +25°C)
(5.0 k, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V).
FIGURE 1-36: INL Error – Pot. Mode 
(P-INL) vs. Wiper Setting (@ +25°C)
(5.0 k, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V).
Ͳ0.15
0.00
0.15
0.30
0.45
0.60
0.75
P -I N L  ( L S b )
10V+25C
20V+25C
36V+25C
Ͳ0.75
Ͳ0.60
Ͳ0.45
Ͳ0.30
0 32 64 96 128 160 192 224 256
P
DAC Wiper Code
Typical Device Typical Device
Ͳ0.15
0.00
0.15
0.30
0.45
0.60
0.75
P -I N L  ( L S b )
10V+25C
20V+25C
36V+25C
Ͳ0.75
Ͳ0.60
Ͳ0.45
Ͳ0.30
0 1 63 24 86 48 09 6 1 1 2 1 2 8
P
DAC Wiper Code

## Page 9

 2014 Microchip Technology Inc. DS20005307A-page 9
MCP45HVX1
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-37: DNL Error – Pot. Mode 
(P-DNL) vs. Wiper Setting and Temperature 
(5.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V).
FIGURE 1-38: DNL Error – Pot. Mode 
(P-DNL) vs. Wiper Setting and Temperature 
(5.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 20V).
FIGURE 1-39: DNL Error – Pot. Mode 
(P-DNL) vs. Wiper Setting and Temperature 
(5.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 10V).
FIGURE 1-40: DNL Error – Pot. Mode 
(P-DNL) vs. Wiper Setting and Temperature 
(5.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V).
FIGURE 1-41: DNL Error – Pot. Mode 
(P-DNL) vs. Wiper Setting and Temperature 
(5.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 20V).
FIGURE 1-42: DNL Error – Pot. Mode 
(P-DNL) vs. Wiper Setting and Temperature 
(5.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 10V).
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P - DNL (LSb)
Ͳ40C +25C +85C +125C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 32 64 96 128 160 192 224 256
P
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P - DNL (LSb)
Ͳ40C +25C +85C +125C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 32 64 96 128 160 192 224 256
P
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P - DNL (LSb)
Ͳ40C +25C +85C +125C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 32 64 96 128 160 192 224 256
P
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P - DNL (LSb)
Ͳ40C +25C +85C +125C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 1 63 24 86 48 09 6 1 1 2 1 2 8
P
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P - DNL (LSb)
Ͳ40C +25C +85C +125C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 1 63 24 86 48 09 6 1 1 2 1 2 8
P
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P - DNL (LSb)
Ͳ40C +25C +85C +125C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 1 63 24 86 48 09 6 1 1 2 1 2 8
P
DAC Wiper Code
Typical Device

## Page 10

MCP45HVX1
DS20005307A-page 10  2014 Microchip Technology Inc.
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-43: DNL Error – Pot. Mode 
(P-DNL) vs. Wiper Setting (@ +25°C)
(5.0 k, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V). 
FIGURE 1-44: DNL Error – Pot. Mode 
(P-DNL) vs. Wiper Setting (@ +25°C)
(5.0 k, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V).
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P - DNL (LSb)
10V+25C 20V+25C 36V+25C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 32 64 96 128 160 192 224 256
P
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P - DNL (LSb)
10V+25C 20V+25C 36V+25C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 1 63 24 86 48 09 6 1 1 2 1 2 8
P
DAC Wiper Code
Typical Device

## Page 11

 2014 Microchip Technology Inc. DS20005307A-page 11
MCP45HVX1
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-45: Wiper Resistance (RW) vs. 
Wiper Setting and Temperature 
(5.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 
IW = 6.0 mA). 
FIGURE 1-46: Wiper Resistance (RW) vs. 
Wiper Setting and Temperature 
(5.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 20V, 
IW = 3.3 mA).
FIGURE 1-47: Wiper Resistance (RW) vs. 
Wiper Setting and Temperature 
(5.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 10V, 
IW = 1.7 mA). 
FIGURE 1-48: Wiper Resistance (RW) vs. 
Wiper Setting and Temperature 
(5.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 
IW = 6.0 mA). 
FIGURE 1-49: Wiper Resistance (RW) vs. 
Wiper Setting and Temperature 
(5.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 20V, 
IW = 3.3 mA).
FIGURE 1-50: Wiper Resistance (RW) vs. 
Wiper Setting and Temperature 
(5.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 10V, 
IW = 1.7 mA). 
120
160
200
240
280
esistance RW (:)
Ͳ40C(IW=6.0mA)
+25C(IW=6.0mA)
+85C(IW=6.0mA)
+125C(IW=6.0mA)
0
40
80
0 32 64 96 128 160 192 224 256
Wiper Re
DAC Wiper Code
120
160
200
240
280
esistance RW (:)
Ͳ40C(IW=3.3mA)
+25C(IW=3.3mA)
+85C(IW=3.3mA)
+125C(IW=3.3mA)
0
40
80
0 32 64 96 128 160 192 224 256
Wiper Re
DAC Wiper Code
120
160
200
240
280
esistance RW (:)
Ͳ40C(IW=1.7mA)
+25C(IW=1.7mA)
+85C(IW=1.7mA)
+125C(IW=1.7mA)
0
40
80
0 32 64 96 128 160 192 224 256
Wiper Re
DAC Wiper Code
120
160
200
240
280
esistance RW (:)
Ͳ40C(IW=6.0mA)
+25C(IW=6.0mA)
+85C(IW=6.0mA)
+125C(IW=6.0mA)
0
40
80
0 1 63 24 86 48 09 6 1 1 2 1 2 8
Wiper Re
DAC Wiper Code
120
160
200
240
280
esistance RW (:)
Ͳ40C(IW=3.3mA)
+25C(IW=3.3mA)
+85C(IW=3.3mA)
+125C(IW=3.3mA)
0
40
80
0 1 63 24 86 48 09 6 1 1 2 1 2 8
Wiper Re
DAC Wiper Code
120
160
200
240
280
esistance RW (:)
Ͳ40C(IW=1.7mA)
+25C(IW=1.7mA)
+85C(IW=1.7mA)
+125C(IW=1.7mA)
0
40
80
0 1 63 24 86 48 09 6 1 1 2 1 2 8
Wiper Re
DAC Wiper Code

## Page 12

MCP45HVX1
DS20005307A-page 12  2014 Microchip Technology Inc.
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V
FIGURE 1-51: Wiper Resistance (RW) vs. 
Wiper Setting @ +29°C
(5.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, 
V+ = 36V and I
W = 6.0mA, V+ = 20V and 
IW = 3.3 mA, V+ = 10V and IW = 1.7 mA).   
FIGURE 1-52: Wiper Resistance (RW) vs. 
Wiper Setting @ +29°C 
(5.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
V+ = 36V and IW = 6.0mA, V+ = 20V and 
IW = 3.3 mA, V+ = 10V and IW = 1.7 mA).   
120
160
200
240
280
esistance RW (:)
10V+25C(IW=1.7mA)
20V+25C(IW=3.3mA)
36V+25C(IW=6.0mA)
0
40
80
0 32 64 96 128 160 192 224 256
Wiper Re
DAC Wiper Code
120
160
200
240
280
esistance RW (:)
10V+25C(IW=1.7mA)
20V+25C(IW=3.3mA)
36V+25C(IW=6.0mA)
0
40
80
0 1 63 24 86 48 09 6 1 1 2 1 2 8
Wiper Re
DAC Wiper Code

## Page 13

 2014 Microchip Technology Inc. DS20005307A-page 13
MCP45HVX1
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-53: INL Error – Rheo. Mode 
(R-INL) vs. Wiper Setting and Temperature 
(5.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 
IW = 6.0 mA).
FIGURE 1-54: INL Error – Rheo. Mode 
(R-INL) vs. Wiper Setting and Temperature 
(5.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 20V, 
IW = 3.3 mA).
FIGURE 1-55: INL Error – Rheo. Mode 
(R-INL) vs. Wiper Setting and Temperature 
(5.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 10V, 
IW = 1.7 mA).
FIGURE 1-56: INL Error – Rheo. Mode 
(R-INL) vs. Wiper Setting and Temperature 
(5.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 
IW = 6.0 mA).
FIGURE 1-57: INL Error – Rheo. Mode 
(R-INL) vs. Wiper Setting and Temperature 
(5.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 20V, 
IW = 3.3 mA).   
FIGURE 1-58: INL Error – Rheo. Mode 
(R-INL) vs. Wiper Setting and Temperature 
(5.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 10V, 
IW = 1.7 mA).
10
15
20
25
30
R -I N L  ( L S b )
Ͳ40C(IW=6.0mA)
+25C(IW=6.0mA)
+85C(IW=6.0mA)
+125C(IW=6.0mA)
0
5
10
0 32 64 96 128 160 192 224 256
R
DAC Wiper Code
Typical Device
10
15
20
25
30
R -I N L  ( L S b )
Ͳ40C(IW=3.3mA)
+25C(IW=3.3mA)
+85C(IW=3.3mA)
+125C(IW=3.3mA)
0
5
10
0 32 64 96 128 160 192 224 256
R
DAC Wiper Code
Typical Device
Typical Device
10
15
20
25
30
R -I N L  ( L S b )
0
5
10
0 32 64 96 128 160 192 224 256
R
DAC Wiper Code
Ͳ40C(IW=1.7mA)
+25C(IW=1.7mA)
+85C(IW=1.7mA)
+125C(IW=1.7mA)
10
15
20
25
30
R -I N L  ( L S b )
Ͳ40C(IW=6.0mA)
+25C(IW=6.0mA)
+85C(IW=6.0mA)
+125C(IW=6.0mA)
0
5
10
0 1 63 24 86 48 09 6 1 1 2 1 2 8
R
DAC Wiper Code
Typical Device
10
15
20
25
30
R -I N L  ( L S b )
Ͳ40C(IW=3.3mA)
+25C(IW=3.3mA)
+85C(IW=3.3mA)
+125C(IW=3.3mA)
0
5
10
0 1 63 24 86 48 09 6 1 1 2 1 2 8
R
DAC Wiper Code
Typical Device
10
15
20
25
30
R -I N L  ( L S b )
Ͳ40C(IW=1.7mA)
+25C(IW=1.7mA)
+85C(IW=1.7mA)
+125C(IW=1.7mA)
0
5
10
0 1 63 24 86 48 09 6 1 1 2 1 2 8
R
DAC Wiper Code
Typical Device

## Page 14

MCP45HVX1
DS20005307A-page 14  2014 Microchip Technology Inc.
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-59: INL Error – Rheo. Mode 
(R-INL) vs. Wiper Setting (@ +25°C)
(5.0 k, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, 
V+ = 36V and I
W = 6.0 mA, V+ = 20V and 
IW = 3.3 mA, V+ = 10V and IW = 1.7 mA).
FIGURE 1-60: INL Error – Rheo. Mode 
(R-INL) vs. Wiper Setting (@ +25°C)
(5.0 k, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, 
V+ = 36V and I
W = 6.0 mA, V+ = 20V and 
IW = 3.3 mA, V+ = 10V and IW = 1.7 mA).
10
15
20
25
30
R -I N L  ( L S b )
10V(1.7mA)+25C
20V(3.3mA)+25C
36V(6.0mA)+25C
0
5
10
0 32 64 96 128 160 192 224 256
R
DAC Wiper Code
Typical Device
10
15
20
25
30
R -I N L  ( L S b )
10V(1.7mA)+25C
20V(3.3mA)+25C
36V(6.0mA)+25C
0
5
10
0 1 63 24 86 48 09 6 1 1 2 1 2 8
R
DAC Wiper Code
Typical Device

## Page 15

 2014 Microchip Technology Inc. DS20005307A-page 15
MCP45HVX1
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-61: DNL Error – Rheo. Mode 
(R-DNL) vs. Wiper Setting and Temperature 
(5.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 
IW = 6.0 mA).
FIGURE 1-62: DNL Error – Rheo. Mode 
(R-DNL) vs. Wiper Setting and Temperature 
(5.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 20V, 
IW = 3.3 mA).    
FIGURE 1-63: DNL Error – Rheo. Mode 
(R-DNL) vs. Wiper Setting and Temperature 
(5.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 10V, 
IW = 1.7 mA).
FIGURE 1-64: DNL Error – Rheo. Mode 
(R-DNL) vs. Wiper Setting and Temperature 
(5.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 
IW = 6.0 mA).
FIGURE 1-65: DNL Error – Rheo. Mode 
(R-DNL) vs. Wiper Setting and Temperature 
(5.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 20V, 
IW = 3.3 mA).
FIGURE 1-66: DNL Error – Rheo. Mode 
(R-DNL) vs. Wiper Setting and Temperature 
(5.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 10V, 
IW = 1.7 mA).
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
R - DNL (LSb)
Ͳ40C(IW=6.0mA)
+25C(IW=6.0mA)
+85C(IW=6.0mA)
+125C(IW=6.0mA)
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 32 64 96 128 160 192 224 256
R
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
R - DNL (LSb)
Ͳ40C(IW=3.3mA)
+25C(IW=3.3mA)
+85C(IW=3.3mA)
+125C(IW=3.3mA)
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 32 64 96 128 160 192 224 256
R
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
R - DNL (LSb)
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 32 64 96 128 160 192 224 256
R
DAC Wiper Code
Ͳ40C(IW=1.7mA)
+25C(IW=1.7mA)
+85C(IW=1.7mA)
+125C(IW=1.7mA)
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
R - DNL (LSb)
Ͳ40C(IW=6.0mA)
+25C(IW=6.0mA)
+85C(IW=6.0mA)
+125C(IW=6.0mA)
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 1 63 24 86 48 09 6 1 1 2 1 2 8
R
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
R - DNL (LSb)
Ͳ40C(IW=3.3mA)
+25C(IW=3.3mA)
+85C(IW=3.3mA)
+125C(IW=3.3mA)
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 1 63 24 86 48 09 6 1 1 2 1 2 8
R
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
R - DNL (LSb)
Ͳ40C(IW=1.7mA)
+25C(IW=1.7mA)
+85C(IW=1.7mA)
+125C(IW=1.7mA)
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 1 63 24 86 48 09 6 1 1 2 1 2 8
R
DAC Wiper Code
Typical Device

## Page 16

MCP45HVX1
DS20005307A-page 16  2014 Microchip Technology Inc.
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-67: DNL Error – Rheo. Mode 
(R-DNL) vs. Wiper Setting (@ +25°C)
(5.0 k, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, 
V+ = 36V and I
W = 6.0 mA, V+ = 20V and 
IW = 3.3 mA, V+ = 10V and IW = 1.7 mA).
FIGURE 1-68: DNL Error – Rheo. Mode 
(R-DNL) vs. Wiper Setting (@ +25°C)
(5.0 k, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, 
V+ = 36V and I
W = 6.0 mA, V+ = 20V and 
IW = 3.3 mA, V+ = 10V and IW = 1.7 mA).
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
R - DNL (LSb)
10V(1.7mA)+25C
20V(3.3mA)+25C
36V(6.0mA)+25C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 32 64 96 128 160 192 224 256
R
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
R - DNL (LSb)
10V(1.7mA)+25C
20V(3.3mA)+25C
36V(6.0mA)+25C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 1 63 24 86 48 09 6 1 1 2 1 2 8
R
DAC Wiper Code
Typical Device

## Page 17

 2014 Microchip Technology Inc. DS20005307A-page 17
MCP45HVX1
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-69: VW PPM/°C (Pot. Mode) vs. 
Temperature and V+ Voltage 
( ( (V
W(code = n, +125°C) – VW(code = n, -40°C))/ 
VW(code = 255, +25°C)) * 1,000,000/+165°C) 
(5.0 k, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V).
FIGURE 1-70: VW PPM/°C (Pot. Mode) vs. 
Temperature and V+ Voltage 
( ( (V
W(code = n, +125°C) – VW(code = n, -40°C))/ 
VW(code = 127, +25°C)) * 1,000,000/+165°C) 
(5.0 k, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V).
FIGURE 1-71: RAB Resistance vs. 
Temperature and V+ Voltage    
(5.0 k
: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V).
50
Ͳ30
Ͳ10
10
30
50
70
90
110
130
150
PPM per °C
PPMperCͲ10V
PPMperCͲ20V
PPMperCͲ36V
Ͳ150
Ͳ130
Ͳ110
Ͳ90
Ͳ70
Ͳ50
0 32 64 96 128 160 192 224 256
DAC Wiper Code
50
Ͳ30
Ͳ10
10
30
50
70
90
110
130
150
PPM per °C
PPMperCͲ10V
PPMperCͲ20V
PPMperCͲ36V
Ͳ150
Ͳ130
Ͳ110
Ͳ90
Ͳ70
Ͳ50
0 1 63 24 86 48 09 6 1 1 2 1 2 8
DAC Wiper Code
4800
5000
5200
5400
5600
5800
6000
RAB Resistance (:)
RABͲ10V
RABͲ20V
RABͲ36V
4000
4200
4400
4600
Ͳ40 Ͳ20 0 20 40 60 80 100 120
R
Temperature (°C)

## Page 18

MCP45HVX1
DS20005307A-page 18  2014 Microchip Technology Inc.
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-72: Total Unadjusted Error (Pot. 
Mode) (VW) vs. Wiper Setting and Temperature 
(10.0 k, 8-bit: VL = 1.8V, 2.7V, 5.5V, 
A = V+, B = V-, DGND = V-, V+ = 36V). 
FIGURE 1-73: Total Unadjusted Error (Pot. 
Mode) (VW) vs. Wiper Setting and Temperature 
(10.0 k, 8-bit: VL = 1.8V, 2.7V, 5.5V, 
A = V+, B = V-, DGND = V-, V+ = 20V). 
FIGURE 1-74: Total Unadjusted Error (Pot. 
Mode) (VW) vs. Wiper Setting and Temperature 
(10.0 k, 8-bit: VL = 1.8V, 2.7V, 5.5V, 
A = V+, B = V-, DGND = V-, V+ = 10V). 
FIGURE 1-75: Total Unadjusted Error (Pot. 
Mode) (VW) vs. Wiper Setting and Temperature 
(10.0 k, 7-bit: VL = 1.8V, 2.7V, 5.5V, 
A = V+, B = V-, DGND = V-, V+ = 36V). 
FIGURE 1-76: Total Unadjusted Error (Pot. 
Mode) (VW) vs. Wiper Setting and Temperature 
(10.0 k, 7-bit: VL = 1.8V, 2.7V, 5.5V, 
A = V+, B = V-, DGND = V-, V+ = 20V). 
FIGURE 1-77: Total Unadjusted Error (Pot. 
Mode) (VW) vs. Wiper Setting and Temperature 
(10.0 k, 7-bit: VL = 1.8V, 2.7V, 5.5V, 
A = V+, B = V-, DGND = V-, V+ = 10V).
Ͳ2
Ͳ1
0
1
2
3
4
5
6
Unadjusted Error (LSb)
Ͳ40C
+25C
+85C
+125C
Ͳ6
Ͳ5
Ͳ4
Ͳ3
0 32 64 96 128 160 192 224 256
Total U
DAC Wiper Code
Ͳ2
Ͳ1
0
1
2
3
4
5
6
Unadjusted Error (LSb)
Ͳ40C
+25C
+85C
+125C
Ͳ6
Ͳ5
Ͳ4
Ͳ3
0 32 64 96 128 160 192 224 256
Total U
DAC Wiper Code
Ͳ2
Ͳ1
0
1
2
3
4
5
6
Unadjusted Error (LSb)
Ͳ40C
+25C
+85C
+125C
Ͳ6
Ͳ5
Ͳ4
Ͳ3
0 32 64 96 128 160 192 224 256
Total U
DAC Wiper Code
Ͳ2
Ͳ1
0
1
2
3
4
5
6
Unadjusted Error (LSb)
Ͳ40C
+25C
+85C
+125C
Ͳ6
Ͳ5
Ͳ4
Ͳ3
0 1 63 24 86 48 09 6 1 1 2 1 2 8
Total U
DAC Wiper Code
Ͳ2
Ͳ1
0
1
2
3
4
5
6
Unadjusted Error (LSb)
Ͳ40C
+25C
+85C
+125C
Ͳ6
Ͳ5
Ͳ4
Ͳ3
0 1 63 24 86 48 09 6 1 1 2 1 2 8
Total U
DAC Wiper Code
Ͳ2
Ͳ1
0
1
2
3
4
5
6
Unadjusted Error (LSb)
Ͳ40C
+25C
+85C
+125C
Ͳ6
Ͳ5
Ͳ4
Ͳ3
0 1 63 24 86 48 09 6 1 1 2 1 2 8
Total U
DAC Wiper Code

## Page 19

 2014 Microchip Technology Inc. DS20005307A-page 19
MCP45HVX1
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-78: Total Unadjusted Error (Pot. 
Mode) (VW) vs. Wiper Setting (@ +25°C)
(10.0 k, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V).
FIGURE 1-79: Full-Scale Error (Pot. Mode) 
(FSE) vs. Temperature and V+ Voltage
(10.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V).
FIGURE 1-80: Zero Scale Error (Pot. Mode) 
(ZSE) vs. Temperature and V+ Voltage
(10.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V).
FIGURE 1-81: Total Unadjusted Error (Pot. 
Mode) (VW) vs. Wiper Setting (@ +25°C)
(10.0 k, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V).
FIGURE 1-82: Full-Scale Error (Pot. Mode) 
(FSE) vs. Temperature and V+ Voltage
(10.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V). 
FIGURE 1-83: Zero Scale Error (Pot. Mode) 
(ZSE) vs. Temperature and V+ Voltage
(10.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V).
Ͳ2
Ͳ1
0
1
2
3
4
5
6
Unadjusted Error (LSb)
10V+25C
20V+25C
36V+25C
Ͳ6
Ͳ5
Ͳ4
Ͳ3
0 32 64 96 128 160 192 224 256
Total U
DAC Wiper Code
40
Ͳ3.5
Ͳ3.0
Ͳ2.5
Ͳ2.0
Ͳ1.5
Ͳ1.0
Ͳ0.5
0.0
l Scale Error (LSb)
FSEͲ10V
FSEͲ20V
FSEͲ36V
Ͳ6.0
Ͳ5.5
Ͳ5.0
Ͳ4.5
Ͳ4.0
Ͳ40 Ͳ20 0 20 40 60 80 100 120
Full
Temperature (°C)
20
2.5
3.0
3.5
4.0
4.5
5.0
5.5
6.0
o Scale Error (LSb)
0.0
0.5
1.0
1.5
2.0
Ͳ40 Ͳ20 0 20 40 60 80 100 120
Zero
Temperature (°C)
ZSEͲ10V
ZSEͲ20V
ZSEͲ36V
Ͳ2
Ͳ1
0
1
2
3
4
5
6
Unadjusted Error (LSb)
10V+25C
20V+25C
36V+25C
Ͳ6
Ͳ5
Ͳ4
Ͳ3
0 1 63 24 86 48 09 6 1 1 2 1 2 8
Total U
DAC Wiper Code
4
Ͳ3
Ͳ2
Ͳ1
0
l Scale Error (LSb)
Ͳ6
Ͳ5
Ͳ4
Ͳ40 Ͳ20 0 20 40 60 80 100 120
Full
Temperature (°C)
FSEͲ10V
FSEͲ20V
FSEͲ36V
2
3
4
5
6
o Scale Error (LSb)
ZSEͲ10V
ZSEͲ20V
ZSEͲ36V
0
1
2
Ͳ40 Ͳ20 0 20 40 60 80 100 120
Zero
Temperature (°C)

## Page 20

MCP45HVX1
DS20005307A-page 20  2014 Microchip Technology Inc.
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-84: INL Error – Pot. Mode 
(P-INL) vs. Wiper Setting and Temperature 
(10.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V).
FIGURE 1-85: INL Error – Pot. Mode 
(P-INL) vs. Wiper Setting and Temperature 
(10.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 20V).
FIGURE 1-86: INL Error – Pot. Mode 
(P-INL) vs. Wiper Setting and Temperature 
(10.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 10V).
FIGURE 1-87: INL Error – Pot. Mode 
(P-INL) vs. Wiper Setting and Temperature 
(10.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V).
FIGURE 1-88: INL Error – Pot. Mode 
(P-INL) vs. Wiper Setting and Temperature 
(10.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 20V).
FIGURE 1-89: INL Error – Pot. Mode 
(P-INL) vs. Wiper Setting and Temperature 
(10.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 10V).
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P -I N L  ( L S b )
Ͳ40C
+25C
+85C
+125C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 32 64 96 128 160 192 224 256
P
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P -I N L  ( L S b )
Ͳ40C
+25C
+85C
+125C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 32 64 96 128 160 192 224 256
P
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P -I N L  ( L S b )
Ͳ40C
+25C
+85C
+125C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 32 64 96 128 160 192 224 256
P
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P -I N L  ( L S b )
Ͳ40C
+25C
+85C
+125C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 1 63 24 86 48 09 6 1 1 2 1 2 8
P
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P -I N L  ( L S b )
Ͳ40C
+25C
+85C
+125C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 1 63 24 86 48 09 6 1 1 2 1 2 8
P
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P -I N L  ( L S b )
Ͳ40C
+25C
+85C
+125C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 1 63 24 86 48 09 6 1 1 2 1 2 8
P
DAC Wiper Code
Typical Device

## Page 21

 2014 Microchip Technology Inc. DS20005307A-page 21
MCP45HVX1
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-90: INL Error – Pot. Mode 
(P-INL) vs. Wiper Setting (@ +25°C)
(10.0 k, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V). 
FIGURE 1-91: INL Error – Pot. Mode 
(P-INL) vs. Wiper Setting (@ +25°C)
(10.0 k, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V).
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P -I N L  ( L S b )
10V+25C
20V+25C
36V+25C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 32 64 96 128 160 192 224 256
P
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P -I N L  ( L S b )
10V+25C
20V+25C
36V+25C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 1 63 24 86 48 09 6 1 1 2 1 2 8
P
DAC Wiper Code
Typical Device

## Page 22

MCP45HVX1
DS20005307A-page 22  2014 Microchip Technology Inc.
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-92: DNL Error – Pot. Mode 
(P-DNL) vs. Wiper Setting and Temperature 
(10.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V).
FIGURE 1-93: DNL Error – Pot. Mode 
(P-DNL) vs. Wiper Setting and Temperature 
(10.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 20V).
FIGURE 1-94: DNL Error – Pot. Mode 
(P-DNL) vs. Wiper Setting and Temperature 
(10.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 10V). 
FIGURE 1-95: DNL Error – Pot. Mode 
(P-DNL) vs. Wiper Setting and Temperature 
(10.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V).
FIGURE 1-96: DNL Error – Pot. Mode 
(P-DNL) vs. Wiper Setting and Temperature 
(10.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 20V).
FIGURE 1-97: DNL Error – Pot. Mode 
(P-DNL) vs. Wiper Setting and Temperature 
(10.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 10V). 
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P - DNL (LSb)
Ͳ40C +25C +85C +125C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 32 64 96 128 160 192 224 256
P
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P - DNL (LSb)
Ͳ40C +25C +85C +125C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 32 64 96 128 160 192 224 256
P
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P - DNL (LSb)
Ͳ40C +25C +85C +125C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 32 64 96 128 160 192 224 256
P
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P - DNL (LSb)
Ͳ40C +25C +85C +125C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 1 63 24 86 48 09 6 1 1 2 1 2 8
P
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P - DNL (LSb)
Ͳ40C +25C +85C +125C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 1 63 24 86 48 09 6 1 1 2 1 2 8
P
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P - DNL (LSb)
Ͳ40C +25C +85C +125C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 1 63 24 86 48 09 6 1 1 2 1 2 8
P
DAC Wiper Code
Typical Device

## Page 23

 2014 Microchip Technology Inc. DS20005307A-page 23
MCP45HVX1
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-98: DNL Error – Pot. Mode 
(P-DNL) vs. Wiper Setting (@ +25°C)
(10.0 k, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V). 
FIGURE 1-99: DNL Error – Pot. Mode 
(P-DNL) vs. Wiper Setting (@ +25°C)
(10.0 k, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V). 
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P - DNL (LSb)
10V+25C 20V+25C 36V+25C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 32 64 96 128 160 192 224 256
P
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P - DNL (LSb)
10V+25C 20V+25C 36V+25C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 1 63 24 86 48 09 6 1 1 2 1 2 8
P
DAC Wiper Code
Typical Device

## Page 24

MCP45HVX1
DS20005307A-page 24  2014 Microchip Technology Inc.
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-100: Wiper Resistance (RW) vs. 
Wiper Setting and Temperature 
(10.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 
IW = 3.0 mA).
FIGURE 1-101: Wiper Resistance (RW) vs. 
Wiper Setting and Temperature 
(10.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 20V, 
IW = 1.7 mA).
FIGURE 1-102: Wiper Resistance (RW) vs. 
Wiper Setting and Temperature 
(10.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 10V, 
IW = 830 µA).
FIGURE 1-103: Wiper Resistance (RW) vs. 
Wiper Setting and Temperature 
(10.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 
IW = 3.0 mA).
FIGURE 1-104: Wiper Resistance (RW) vs. 
Wiper Setting and Temperature 
(10.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 20V, 
IW = 1.7 mA).
FIGURE 1-105: Wiper Resistance (RW) vs. 
Wiper Setting and Temperature 
(10.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 10V, 
IW = 830 µA).
120
160
200
240
280
esistance RW (:)
Ͳ40C(IW=3.0mA)
+25C(IW=3.0mA)
+85C(IW=3.0mA)
+125C(IW=3.0mA)
0
40
80
0 32 64 96 128 160 192 224 256
Wiper Re
DAC Wiper Code
120
160
200
240
280
esistance RW (:)
Ͳ40C(IW=1.7mA)
+25C(IW=1.7mA)
+85C(IW=1.7mA)
+125C(IW=1.7mA)
0
40
80
0 32 64 96 128 160 192 224 256
Wiper Re
DAC Wiper Code
120
160
200
240
280
esistance RW (:)
Ͳ40C(IW=830uA)
+25C(IW=830uA)
+85C(IW=830uA)
+125C(IW=830uA)
0
40
80
0 32 64 96 128 160 192 224 256
Wiper Re
DAC Wiper Code
120
160
200
240
280
esistance RW (:)
Ͳ40C(IW=3.0mA)
+25C(IW=3.0mA)
+85C(IW=3.0mA)
+125C(IW=3.0mA)
0
40
80
0 1 63 24 86 48 09 6 1 1 2 1 2 8
Wiper Re
DAC Wiper Code
120
160
200
240
280
esistance RW (:)
Ͳ40C(IW=1.7mA)
+25C(IW=1.7mA)
+85C(IW=1.7mA)
+125C(IW=1.7mA)
0
40
80
0 1 63 24 86 48 09 6 1 1 2 1 2 8
Wiper Re
DAC Wiper Code
120
160
200
240
280
esistance RW (:)
Ͳ40C(IW=830uA)
+25C(IW=830uA)
+85C(IW=830uA)
+125C(IW=830uA)
0
40
80
0 1 63 24 86 48 09 6 1 1 2 1 2 8
Wiper Re
DAC Wiper Code

## Page 25

 2014 Microchip Technology Inc. DS20005307A-page 25
MCP45HVX1
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-106: Wiper Resistance (RW) vs. 
Wiper Setting (@ +29°C)
(10.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,    
A = V+, B = V-, DGND = V-, 
V+ = 36V and I
W = 3.0 mA, V+ = 20V and 
IW = 1.7 mA, V+ = 10V and IW = 830 µA).
FIGURE 1-107: Wiper Resistance (RW) vs. 
Wiper Setting (@ +29°C)
(10.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,   
A = V+, B = V-, DGND = V-, 
V+ = 36V and I
W = 3.0 mA, V+ = 20V and 
IW = 1.7 mA, V+ = 10V and IW = 830A).
120
160
200
240
280
esistance RW (:)
10V+25C(IW=830uA)
20V+25C(IW=1.7mA)
36V+25C(IW=3.0mA)
0
40
80
0 32 64 96 128 160 192 224 256
Wiper Re
DAC Wiper Code
120
160
200
240
280
esistance RW (:)
10V+25C(IW=830uA)
20V+25C(IW=1.7mA)
36V+25C(IW=3.0mA)
0
40
80
0 1 63 24 86 48 09 6 1 1 2 1 2 8
Wiper Re
DAC Wiper Code

## Page 26

MCP45HVX1
DS20005307A-page 26  2014 Microchip Technology Inc.
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-108: INL Error – Rheo. Mode 
(R-INL) vs. Wiper Setting and Temperature 
(10.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 
IW = 3.0 mA).
FIGURE 1-109: INL Error – Rheo. Mode 
(R-INL) vs. Wiper Setting and Temperature 
(10.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 20V, 
IW = 1.7 mA).
FIGURE 1-110: INL Error – Rheo. Mode 
(R-INL) vs. Wiper Setting and Temperature 
(10.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 10V, 
IW = 830 µA).
FIGURE 1-111: INL Error – Rheo. Mode 
(R-INL) vs. Wiper Setting and Temperature 
(10.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 
IW = 3.0 mA).
FIGURE 1-112: INL Error – Rheo. Mode 
(R-INL) vs. Wiper Setting and Temperature 
(10.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 20V, 
IW = 1.7 mA).
FIGURE 1-113: INL Error – Rheo. Mode 
(R-INL) vs. Wiper Setting and Temperature 
(10.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 10V, 
IW = 830 µA).
6
8
10
12
14
R -I N L  ( L S b )
Ͳ40C(IW=3.0mA)
+25C(IW=3.0mA)
+85C(IW=3.0mA)
+125C(IW=3.0mA)
0
2
4
0 32 64 96 128 160 192 224 256
R
DAC Wiper Code
Typical Device
6
8
10
12
14
R -I N L  ( L S b )
Ͳ40C(IW=1.7mA)
+25C(IW=1.7mA)
+85C(IW=1.7mA)
+125C(IW=1.7mA)
0
2
4
0 32 64 96 128 160 192 224 256
R
DAC Wiper Code
Typical Device
6
8
10
12
14
R -I N L  ( L S b )
0
2
4
0 32 64 96 128 160 192 224 256
R
DAC Wiper Code
Ͳ40C(IW=830uA)
+25C(IW=830uA)
+85C(IW=830uA)
+125C(IW=830uA)
Typical Device
6
8
10
12
14
R -I N L  ( L S b )
Ͳ40C(IW=3.0mA)
+25C(IW=3.0mA)
+85C(IW=3.0mA)
+125C(IW=3.0mA)
0
2
4
0 1 63 24 86 48 09 6 1 1 2 1 2 8
R
DAC Wiper Code
Typical Device
6
8
10
12
14
R -I N L  ( L S b )
Ͳ40C(IW=1.7mA)
+25C(IW=1.7mA)
+85C(IW=1.7mA)
+125C(IW=1.7mA)
0
2
4
0 1 63 24 86 48 09 6 1 1 2 1 2 8
R
DAC Wiper Code
Typical Device
6
8
10
12
14
R -I N L  ( L S b )
Ͳ40C(IW=830uA)
+25C(IW=830uA)
+85C(IW=830uA)
+125C(IW=830uA)
0
2
4
0 1 63 24 86 48 09 6 1 1 2 1 2 8
R
DAC Wiper Code
Typical Device

## Page 27

 2014 Microchip Technology Inc. DS20005307A-page 27
MCP45HVX1
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V
FIGURE 1-114: INL Error – Rheo. Mode 
(R-INL) vs. Wiper Setting (@ +25°C)
(10.0 k, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-,
V+ = 36V and I
W = 3.0 mA, V+ = 20V and 
IW = 1.7 mA, V+ = 10V and IW = 830 µA).
FIGURE 1-115: INL Error – Rheo. Mode 
(R-INL) vs. Wiper Setting (@ +25°C)
(10.0 k, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-,
V+ = 36V and I
W = 3.0 mA, V+ = 20V and 
IW = 1.7 mA, V+ = 10V and IW = 830 µA).
6
8
10
12
14
R -I N L  ( L S b )
10V(830uA)+25C
20V(1.7mA)+25C
36V(3.0mA)+25C
0
2
4
0 32 64 96 128 160 192 224 256
R
DAC Wiper Code
Typical Device
6
8
10
12
14
R -I N L  ( L S b )
10V(830uA)+25C
20V(1.7mA)+25C
36V(3.0mA)+25C
0
2
4
0 1 63 24 86 48 09 6 1 1 2 1 2 8
R
DAC Wiper Code
Typical Device

## Page 28

MCP45HVX1
DS20005307A-page 28  2014 Microchip Technology Inc.
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-116: DNL Error – Rheo. Mode 
(R-DNL) vs. Wiper Setting and Temperature 
(10.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 
IW = 3.0 mA).
FIGURE 1-117: DNL Error – Rheo. Mode 
(R-DNL) vs. Wiper Setting and Temperature 
(10.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 20V, 
IW = 1.7 mA).
FIGURE 1-118: DNL Error – Rheo. Mode 
(R-DNL) vs. Wiper Setting and Temperature 
(10.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 10V, 
IW = 830 µA).
FIGURE 1-119: DNL Error – Rheo. Mode 
(R-DNL) vs. Wiper Setting and Temperature 
(10.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 
IW = 3.0 mA).
FIGURE 1-120: DNL Error – Rheo. Mode 
(R-DNL) vs. Wiper Setting and Temperature 
(10.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 20V, 
IW = 1.7 mA).
FIGURE 1-121: DNL Error – Rheo. Mode 
(R-DNL) vs. Wiper Setting and Temperature 
(10.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 10V, 
IW = 830 µA).
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
R - DNL (LSb)
Ͳ40C(IW=3.0mA)
+25C(IW=3.0mA)
+85C(IW=3.0mA)
+125C(IW=3.0mA)
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 32 64 96 128 160 192 224 256
R
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
R - DNL (LSb)
Ͳ40C(IW=1.7mA)
+25C(IW=1.7mA)
+85C(IW=1.7mA)
+125C(IW=1.7mA)
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 32 64 96 128 160 192 224 256
R
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
R - DNL (LSb)
Ͳ40C(IW=830uA)
+25C(IW=830uA)
+85C(IW=830uA)
+125C(IW=830uA)
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 32 64 96 128 160 192 224 256
R
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
R - DNL (LSb)
Ͳ40C(IW=3.0mA)
+25C(IW=3.0mA)
+85C(IW=3.0mA)
+125C(IW=3.0mA)
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 1 63 24 86 48 09 6 1 1 2 1 2 8
R
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
R - DNL (LSb)
Ͳ40C(IW=1.7mA)
+25C(IW=1.7mA)
+85C(IW=1.7mA)
+125C(IW=1.7mA)
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 1 63 24 86 48 09 6 1 1 2 1 2 8
R
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
R - DNL (LSb)
Ͳ40C(IW=830uA)
+25C(IW=830uA)
+85C(IW=830uA)
+125C(IW=830uA)
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 1 63 24 86 48 09 6 1 1 2 1 2 8
R
DAC Wiper Code
Typical Device

## Page 29

 2014 Microchip Technology Inc. DS20005307A-page 29
MCP45HVX1
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-122: DNL Error – Rheo. Mode 
(R-DNL) vs. Wiper Setting (@ +25°C)
(10.0 k, 8-bit: VL = 1.8V, 2.7V, 5.5V,    
A = V+, B = V-, DGND = V-,
V+ = 36V and I
W = 3.0 mA, V+ = 20V and 
IW = 1.7 mA, V+ = 10V and IW = 830 µA).
FIGURE 1-123: DNL Error – Rheo. Mode 
(R-DNL) vs. Wiper Setting (@ +25°C)
(10.0 k, 7-bit: VL = 1.8V, 2.7V, 5.5V,    
A = V+, B = V-, DGND = V-,
V+ = 36V and I
W = 3.0 mA, V+ = 20V and 
IW = 1.7 mA, V+ = 10V and IW = 830 µA).
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
R - DNL (LSb)
10V(830uA)+25C
20V(1.7mA)+25C
36V(3.0mA)+25C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 32 64 96 128 160 192 224 256
R
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
R - DNL (LSb)
10V(830uA)+25C
20V(1.7mA)+25C
36V(3.0mA)+25C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 1 63 24 86 48 09 6 1 1 2 1 2 8
R
DAC Wiper Code
Typical Device

## Page 30

MCP45HVX1
DS20005307A-page 30  2014 Microchip Technology Inc.
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-124: VW PPM/°C (Pot. Mode) vs. 
Temperature and V+ Voltage 
( ( (V
W(code = n, +125°C) – VW(code = n, -40°C))/ 
VW(code = 255, +25°C)) * 1,000,000/+165°C) 
(10.0 k, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V).
FIGURE 1-125: VW PPM/°C (Pot. Mode) vs. 
Temperature, and V+ Voltage 
( ( (V
W(code = n, +125°C) – VW(code = n, -40°C))/ 
VW(code = 127, +25°C)) * 1,000,000/+165°C) 
(10.0 k, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V).
FIGURE 1-126: RAB Resistance vs. 
Temperature and V+ Voltage
(10.0 k
: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V).
Ͳ30
Ͳ20
Ͳ10
0
10
20
30
40
50
60
70
80
90
100
PPM per °C
PPMperCͲ10V
PPMperCͲ20V
PPMperCͲ36V
Ͳ100
Ͳ90
Ͳ80
Ͳ70
Ͳ60
Ͳ50
Ͳ40
30
0 32 64 96 128 160 192 224 256
DAC Wiper Code
Ͳ20
0
20
40
60
80
100
PPM per °C
PPMperCͲ10V
PPMperCͲ20V
PPMperCͲ36V
Ͳ100
Ͳ80
Ͳ60
Ͳ40
0 1 63 24 86 48 09 6 1 1 2 1 2 8
DAC Wiper Code
9900
10000
10100
10200
10300
10400
10500
RAB Resistance (:)
RABͲ10V
RABͲ20V
RABͲ36V
9500
9600
9700
9800
Ͳ40 Ͳ20 0 20 40 60 80 100 120
R
Temperature (°C)

## Page 31

 2014 Microchip Technology Inc. DS20005307A-page 31
MCP45HVX1
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-127: Total Unadjusted Error (Pot. 
Mode) (VW) vs. Wiper Setting and Temperature 
(50.0 k, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V).
FIGURE 1-128: Total Unadjusted Error (Pot. 
Mode) (VW) vs. Wiper Setting and Temperature 
(50.0 k, 8-bit: VL = 1.8V, 2.7V, 5.5V, 
A = V+, B = V-, DGND = V-, V+ = 20V).
FIGURE 1-129: Total Unadjusted Error (Pot. 
Mode) (VW) vs. Wiper Setting and Temperature 
(50.0 k, 8-bit: VL = 1.8V, 2.7V, 5.5V, 
A = V+, B = V-, DGND = V-, V+ = 10V).
FIGURE 1-130: Total Unadjusted Error (Pot. 
Mode) (VW) vs. Wiper Setting and Temperature 
(50.0 k, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V).
FIGURE 1-131: Total Unadjusted Error (Pot. 
Mode) (VW) vs. Wiper Setting and Temperature 
(50.0 k, 7-bit: VL = 1.8V, 2.7V, 5.5V, 
A = V+, B = V-, DGND = V-, V+ = 20V).
FIGURE 1-132: Total Unadjusted Error (Pot. 
Mode) (VW) vs. Wiper Setting and Temperature 
(50.0 k, 7-bit: VL = 1.8V, 2.7V, 5.5V, 
A = V+, B = V-, DGND = V-, V+ = 10V).
Ͳ0.5
0.0
0.5
1.0
1.5
2.0
Unadjusted Error (LSb)
Ͳ40C
+25C
+85C
+125C
Ͳ2.0
Ͳ1.5
Ͳ1.0
0 32 64 96 128 160 192 224 256
Total U
DAC Wiper Code
Ͳ0.5
0.0
0.5
1.0
1.5
2.0
Unadjusted Error (LSb)
Ͳ40C
+25C
+85C
+125C
Ͳ2.0
Ͳ1.5
Ͳ1.0
0 32 64 96 128 160 192 224 256
Total U
DAC Wiper Code
Ͳ0.5
0.0
0.5
1.0
1.5
2.0
Unadjusted Error (LSb)
Ͳ40C
+25C
+85C
+125C
Ͳ2.0
Ͳ1.5
Ͳ1.0
0 32 64 96 128 160 192 224 256
Total U
DAC Wiper Code
Ͳ0.5
0.0
0.5
1.0
1.5
2.0
Unadjusted Error (LSb)
Ͳ40C
+25C
+85C
+125C
Ͳ2.0
Ͳ1.5
Ͳ1.0
0 1 63 24 86 48 09 6 1 1 2 1 2 8
Total U
DAC Wiper Code
Ͳ0.5
0.0
0.5
1.0
1.5
2.0
Unadjusted Error (LSb)
Ͳ40C
+25C
+85C
+125C
Ͳ2.0
Ͳ1.5
Ͳ1.0
0 1 63 24 86 48 09 6 1 1 2 1 2 8
Total U
DAC Wiper Code
Ͳ0.5
0.0
0.5
1.0
1.5
2.0
Unadjusted Error (LSb)
Ͳ40C
+25C
+85C
+125C
Ͳ2.0
Ͳ1.5
Ͳ1.0
0 1 63 24 86 48 09 6 1 1 2 1 2 8
Total U
DAC Wiper Code

## Page 32

MCP45HVX1
DS20005307A-page 32  2014 Microchip Technology Inc.
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-133: Total Unadjusted Error (Pot. 
Mode) (VW) vs. Wiper Setting (@ +25°C)
(50.0 k, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V).
FIGURE 1-134: Full-Scale Error (Pot. Mode) 
(FSE) vs. Temperature and V+ Voltage
(50.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V).
FIGURE 1-135: Zero Scale Error (Pot. Mode) 
(ZSE) vs. Temperature and V+ Voltage
(50.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V).
FIGURE 1-136: Total Unadjusted Error (Pot. 
Mode) (VW) vs. Wiper Setting (@ +25°C)
(50.0 k, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V).
FIGURE 1-137: Full-Scale Error (Pot. Mode) 
(FSE) vs. Temperature and V+ Voltage
(50.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V).
FIGURE 1-138: Zero Scale Error (Pot. Mode) 
(ZSE) vs. Temperature and V+ Voltage
(50.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V).
Ͳ0.5
0.0
0.5
1.0
1.5
2.0
Unadjusted Error (LSb)
10V+25C
20V+25C
36V+25C
Ͳ2.0
Ͳ1.5
Ͳ1.0
0 32 64 96 128 160 192 224 256
Total U
DAC Wiper Code
Ͳ1.2
Ͳ1.0
Ͳ0.8
Ͳ0.6
Ͳ0.4
Ͳ0.2
0.0
l Scale Error (LSb)
FSEͲ10V
FSEͲ20V
FSEͲ36V
Ͳ2.0
Ͳ1.8
Ͳ1.6
Ͳ1.4
Ͳ40 Ͳ20 0 20 40 60 80 100 120
Full
Temperature (°C)
0.8
1.0
1.2
1.4
1.6
1.8
2.0
o Scale Error (LSb)
0.0
0.2
0.4
0.6
Ͳ40 Ͳ20 0 20 40 60 80 100 120
Zero
Temperature (°C)
ZSEͲ10V
ZSEͲ20V
ZSEͲ36V
Ͳ0.5
0.0
0.5
1.0
1.5
2.0
Unadjusted Error (LSb)
10V+25C
20V+25C
36V+25C
Ͳ2.0
Ͳ1.5
Ͳ1.0
0 1 63 24 86 48 09 6 1 1 2 1 2 8
Total U
DAC Wiper Code
Ͳ1.2
Ͳ1.0
Ͳ0.8
Ͳ0.6
Ͳ0.4
Ͳ0.2
0.0
l Scale Error (LSb)
FSEͲ10V
FSEͲ20V
FSEͲ36V
Ͳ2.0
Ͳ1.8
Ͳ1.6
Ͳ1.4
Ͳ40 Ͳ20 0 20 40 60 80 100 120
Full
Temperature (°C)
0.8
1.0
1.2
1.4
1.6
1.8
2.0
o Scale Error (LSb)
ZSEͲ10V
ZSEͲ20V
ZSEͲ36V
0.0
0.2
0.4
0.6
Ͳ40 Ͳ20 0 20 40 60 80 100 120
Zero
Temperature (°C)

## Page 33

 2014 Microchip Technology Inc. DS20005307A-page 33
MCP45HVX1
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-139: INL Error – Pot. Mode 
(P-INL) vs. Wiper Setting and Temperature 
(50.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V).
FIGURE 1-140: INL Error – Pot. Mode 
(P-INL) vs. Wiper Setting and Temperature 
(50.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 20V).
FIGURE 1-141: INL Error – Pot. Mode 
(P-INL) vs. Wiper Setting and Temperature 
(50.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 10V).
FIGURE 1-142: INL Error – Pot. Mode 
(P-INL) vs. Wiper Setting and Temperature 
(50.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V).
FIGURE 1-143: INL Error – Pot. Mode 
(P-INL) vs. Wiper Setting and Temperature 
(50.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 20V).
FIGURE 1-144: INL Error – Pot. Mode 
(P-INL) vs. Wiper Setting and Temperature 
(50.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 10V).
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P -I N L  ( L S b )
Ͳ40C
+25C
+85C
+125C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 32 64 96 128 160 192 224 256
P
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P -I N L  ( L S b )
Ͳ40C
+25C
+85C
+125C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 32 64 96 128 160 192 224 256
P
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P -I N L  ( L S b )
Ͳ40C
+25C
+85C
+125C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 32 64 96 128 160 192 224 256
P
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P -I N L  ( L S b )
Ͳ40C
+25C
+85C
+125C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 1 63 24 86 48 09 6 1 1 2 1 2 8
P
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P -I N L  ( L S b )
Ͳ40C
+25C
+85C
+125C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 1 63 24 86 48 09 6 1 1 2 1 2 8
P
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P -I N L  ( L S b )
Ͳ40C
+25C
+85C
+125C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 1 63 24 86 48 09 6 1 1 2 1 2 8
P
DAC Wiper Code
Typical Device

## Page 34

MCP45HVX1
DS20005307A-page 34  2014 Microchip Technology Inc.
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-145: INL Error – Pot. Mode 
(P-INL) vs. Wiper Setting (@ +25°C)
(50.0 k, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V).
FIGURE 1-146: INL Error – Pot. Mode 
(P-INL) vs. Wiper Setting (@ +25°C)
(50.0 k, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V).
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P -I N L  ( L S b )
10V+25C
20V+25C
36V+25C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 32 64 96 128 160 192 224 256
P
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P -I N L  ( L S b )
10V+25C
20V+25C
36V+25C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 1 63 24 86 48 09 6 1 1 2 1 2 8
P
DAC Wiper Code
Typical Device

## Page 35

 2014 Microchip Technology Inc. DS20005307A-page 35
MCP45HVX1
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-147: DNL Error – Pot. Mode 
(P-DNL) vs. Wiper Setting and Temperature 
(50.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V). 
FIGURE 1-148: DNL Error – Pot. Mode 
(P-DNL) vs. Wiper Setting and Temperature 
(50.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 20V).
FIGURE 1-149: DNL Error – Pot. Mode 
(P-DNL) vs. Wiper Setting and Temperature 
(50.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 10V).
FIGURE 1-150: DNL Error – Pot. Mode 
(P-DNL) vs. Wiper Setting and Temperature 
(50.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V). 
FIGURE 1-151: DNL Error – Pot. Mode 
(P-DNL) vs. Wiper Setting and Temperature 
(50.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 20V).
FIGURE 1-152: DNL Error – Pot. Mode 
(P-DNL) vs. Wiper Setting and Temperature 
(50.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 10V).
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P - DNL (LSb)
Ͳ40C +25C +85C +125C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 32 64 96 128 160 192 224 256
P
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P - DNL (LSb)
Ͳ40C +25C +85C +125C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 32 64 96 128 160 192 224 256
P
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P - DNL (LSb)
Ͳ40C +25C +85C +125C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 32 64 96 128 160 192 224 256
P
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P - DNL (LSb)
Ͳ40C +25C +85C +125C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 1 63 24 86 48 09 6 1 1 2 1 2 8
P
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P - DNL (LSb)
Ͳ40C +25C +85C +125C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 1 63 24 86 48 09 6 1 1 2 1 2 8
P
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P - DNL (LSb)
Ͳ40C +25C +85C +125C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 1 63 24 86 48 09 6 1 1 2 1 2 8
P
DAC Wiper Code
Typical Device

## Page 36

MCP45HVX1
DS20005307A-page 36  2014 Microchip Technology Inc.
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-153: DNL Error – Pot. Mode 
(P-DNL) vs. Wiper Setting (@ +25°C)
(50.0 k, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V).
FIGURE 1-154: DNL Error – Pot. Mode 
(P-DNL) vs. Wiper Setting (@ +25°C)
(50.0 k, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V).
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P - DNL (LSb)
10V+25C 20V+25C 36V+25C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 32 64 96 128 160 192 224 256
P
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P - DNL (LSb)
10V+25C 20V+25C 36V+25C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 1 63 24 86 48 09 6 1 1 2 1 2 8
P
DAC Wiper Code
Typical Device

## Page 37

 2014 Microchip Technology Inc. DS20005307A-page 37
MCP45HVX1
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-155: Wiper Resistance (RW) vs. 
Wiper Setting and Temperature 
(50.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 
IW = 600 µA).
FIGURE 1-156: Wiper Resistance (RW) vs. 
Wiper Setting and Temperature 
(50.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 20V, 
IW = 330 µA).
FIGURE 1-157: Wiper Resistance (RW) vs. 
Wiper Setting and Temperature 
(50.0 k, 8-bit: VL = 1.8V, 2.7V, 5.5V, 
A = V+, B = V-, DGND = V-, V+ = 10V, 
IW = 170 µA). 
FIGURE 1-158: Wiper Resistance (RW) vs. 
Wiper Setting and Temperature 
(50.0 k, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 
IW = 600 µA).
FIGURE 1-159: Wiper Resistance (RW) vs. 
Wiper Setting and Temperature 
(50.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 20V, 
IW = 330 µA).
FIGURE 1-160: Wiper Resistance (RW) vs. 
Wiper Setting and Temperature 
(50.0 k, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 10V, 
IW = 170 µA).
160
200
240
280
320
360
400
440
480
esistance RW (:)
Ͳ40C(IW=600uA)
+25C(IW=600uA)
+85C(IW=600uA)
+125C(IW=600uA)
0
40
80
120
160
0 32 64 96 128 160 192 224 256
Wiper Re
DAC Wiper Code
Measured RW is influenced by the analog switch leakage at +125°C.
See Section 5.2.1 of the “MCP45HVX1 Data Sheet” (DS20005304)
for additional information.
160
200
240
280
320
360
400
440
480
esistance RW ( )
-40C (IW = 330uA)
+25C (IW = 330uA)
+85C (IW = 330uA)
+125C (IW = 330uA)
0
40
80
120
160
0 32 64 96 128 160 192 224 256
Wiper Re
DAC Wiper Code
Wiper Resistance RW (Ω)
Measured RW is influenced by the analog switch leakage at +125°C.
See Section 5.2.1 of the “MCP45HVX1 Data Sheet” (DS20005304)
for additional information.
160
200
240
280
320
360
400
440
480
esistance RW (Ω )
-40C (IW = 170uA)
+25C (IW = 170uA)
+85C (IW = 170uA)
+125C (IW = 170uA)
0
40
80
120
160
0 32 64 96 128 160 192 224 256
Wiper Re
DAC Wiper Code
Measured RW is influenced by the analog switch leakage at +125°C.
See Section 5.2.1 of the “MCP45HVX1 Data Sheet” (DS20005304)
for additional information.
160
200
240
280
320
360
400
440
480
-40C (IW = 600uA)
+25C (IW = 600uA)
+85C (IW = 600uA)
+125C (IW = 600uA)
0
40
80
120
160
0 1 63 24 86 48 09 6 1 1 2 1 2 8
DAC Wiper Code
Wiper Resistance ȍRW
Measured RW is influenced by the analog switch leakage at +125°C.
See Section 5.2.1 of the “MCP45HVX1 Data Sheet” (DS20005304)
for additional information.
   
   
  
   
Wiper Resistance ȍRW
160
200
240
280
320
360
400
440
480
-40C (IW = 330uA)
+25C (IW = 330uA)
+85C (IW = 330uA)
+125C (IW = 330uA)
0
40
80
120
160
0 1 63 24 86 48 09 6 1 1 2 1 2 8
DAC Wiper Code
Wiper Resistance ȍRW
Measured RW is influenced by the analog switch leakage at +125°C.
See Section 5.2.1 of the “MCP45HVX1 Data Sheet” (DS20005304)
for additional information.
Wiper Resistance ȍRW
160
200
240
280
320
360
400
440
480
-40C (IW = 170uA)
+25C (IW = 170uA)
+85C (IW = 170uA)
+125C (IW = 170uA)
0
40
80
120
160
0 1 63 24 86 48 09 6 1 1 2 1 2 8
DAC Wiper Code
Wiper Resistance ȍRW
Measured RW is influenced by the analog switch leakage at +125°C.
See Section 5.2.1 of the “MCP45HVX1 Data Sheet” (DS20005304)
for additional information.

## Page 38

MCP45HVX1
DS20005307A-page 38  2014 Microchip Technology Inc.
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-161: Wiper Resistance (RW) vs. 
Wiper Setting (@ +29°C)
(50.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-,
V+ = 36V and I
W = 600 µA, V+ = 20V and 
IW = 330 µA, V+ = 10V and IW = 170 µA).
FIGURE 1-162: Wiper Resistance (RW) vs. 
Wiper Setting (@ +29°C)
(50.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-,
V+ = 36V and I
W = 600 µA, V+ = 20V and 
IW = 330 µA, V+ = 10V and IW = 170 µA).
160
200
240
280
320
360
400
440
480
esistance RW (:)
10V+25C(IW=170uA)
20V+25C(IW=330uA)
36V+25C(IW=600uA)
0
40
80
120
160
0 32 64 96 128 160 192 224 256
Wiper Re
DAC Wiper Code
160
200
240
280
320
360
400
440
480
esistance RW (:)
10V+25C(IW=170uA)
20V+25C(IW=330uA)
36V+25C(IW=600uA)
0
40
80
120
160
0 1 63 24 86 48 09 6 1 1 2 1 2 8
Wiper Re
DAC Wiper Code

## Page 39

 2014 Microchip Technology Inc. DS20005307A-page 39
MCP45HVX1
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-163: INL Error – Rheo. Mode 
(R-INL) vs. Wiper Setting and Temperature 
(50.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 
IW = 600 µA).
FIGURE 1-164: INL Error – Rheo. Mode 
(R-INL) vs. Wiper Setting and Temperature 
(50.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 20V, 
IW = 330 µA).
FIGURE 1-165: INL Error – Rheo. Mode 
(R-INL) vs. Wiper Setting and Temperature 
(50.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 10V, 
IW = 170 µA). 
FIGURE 1-166: INL Error – Rheo. Mode 
(R-INL) vs. Wiper Setting and Temperature 
(50.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 
IW = 600 µA).
FIGURE 1-167: INL Error – Rheo. Mode 
(R-INL) vs. Wiper Setting and Temperature 
(50.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 20V, 
IW = 330 µA).
FIGURE 1-168: INL Error – Rheo. Mode 
(R-INL) vs. Wiper Setting and Temperature 
(50.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 10V, 
IW = 170 µuA). 
10
Ͳ0.5
0.0
0.5
1.0
1.5
2.0
2.5
3.0
R -I N L  ( L S b )
Ͳ40C(IW=600uA)
+25C(IW=600uA)
+85C(IW=600uA)
+125C(IW=600uA)
Ͳ3.0
Ͳ2.5
Ͳ2.0
Ͳ1.5
Ͳ1.0
0 32 64 96 128 160 192 224 256
R
DAC Wiper Code
Typical Device
10
Ͳ0.5
0.0
0.5
1.0
1.5
2.0
2.5
3.0
R -I N L  ( L S b )
Ͳ3.0
Ͳ2.5
Ͳ2.0
Ͳ1.5
Ͳ1.0
0 32 64 96 128 160 192 224 256
R
DAC Wiper Code
Ͳ40C(IW=330uA)
+25C(IW=330uA)
+85C(IW=330uA)
+125C(IW=330uA)
Typical Device
10
Ͳ0.5
0.0
0.5
1.0
1.5
2.0
2.5
3.0
R -I N L  ( L S b )
Ͳ3.0
Ͳ2.5
Ͳ2.0
Ͳ1.5
Ͳ1.0
0 32 64 96 128 160 192 224 256
R
DAC Wiper Code
Ͳ40C(IW=170uA)
+25C(IW=170uA)
+85C(IW=170uA)
+125C(IW=170uA)
Typical Device
10
Ͳ0.5
0.0
0.5
1.0
1.5
2.0
2.5
3.0
R -I N L  ( L S b )
Ͳ40C(IW=600uA)
+25C(IW=600uA)
+85C(IW=600uA)
+125C(IW=600uA)
Ͳ3.0
Ͳ2.5
Ͳ2.0
Ͳ1.5
Ͳ1.0
0 1 63 24 86 48 09 6 1 1 2 1 2 8
R
DAC Wiper Code
Typical Device
10
Ͳ0.5
0.0
0.5
1.0
1.5
2.0
2.5
3.0
R -I N L  ( L S b )
Ͳ40C(IW=330uA)
+25C(IW=330uA)
+85C(IW=330uA)
+125C(IW=330uA)
Ͳ3.0
Ͳ2.5
Ͳ2.0
Ͳ1.5
Ͳ1.0
0 1 63 24 86 48 09 6 1 1 2 1 2 8
R
DAC Wiper Code
Typical Device
10
Ͳ0.5
0.0
0.5
1.0
1.5
2.0
2.5
3.0
R -I N L  ( L S b )
Ͳ40C(IW=170uA)
+25C(IW=170uA)
+85C(IW=170uA)
+125C(IW=170uA)
Ͳ3.0
Ͳ2.5
Ͳ2.0
Ͳ1.5
Ͳ1.0
0 1 63 24 86 48 09 6 1 1 2 1 2 8
R
DAC Wiper Code
Typical Device

## Page 40

MCP45HVX1
DS20005307A-page 40  2014 Microchip Technology Inc.
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V
FIGURE 1-169: INL Error – Rheo. Mode 
(R-INL) vs. Wiper Setting (@ +25°C)
(50.0 k, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-,
V+ = 36V and I
W = 600 µA, V+ = 20V and 
IW = 330 µA, V+ = 10V and IW = 170 µA).
FIGURE 1-170: INL Error – Rheo. Mode 
(R-INL) vs. Wiper Setting (@ +25°C)
(50.0 k, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-,
V+ = 36V and I
W = 600 µA, V+ = 20V and 
IW = 330 µA, V+ = 10V and IW = 170 µA).
10
Ͳ0.5
0.0
0.5
1.0
1.5
2.0
2.5
3.0
R -I N L  ( L S b )
10V(170uA)+25C
20V(330uA)+25C
36V(600uA)+25C
Ͳ3.0
Ͳ2.5
Ͳ2.0
Ͳ1.5
Ͳ1.0
0 32 64 96 128 160 192 224 256
R
DAC Wiper Code
Typical Device
10
Ͳ0.5
0.0
0.5
1.0
1.5
2.0
2.5
3.0
R -I N L  ( L S b )
10V(170uA)+25C
20V(330uA)+25C
36V(600uA)+25C
Ͳ3.0
Ͳ2.5
Ͳ2.0
Ͳ1.5
Ͳ1.0
0 1 63 24 86 48 09 6 1 1 2 1 2 8
R
DAC Wiper Code
Typical Device

## Page 41

 2014 Microchip Technology Inc. DS20005307A-page 41
MCP45HVX1
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-171: DNL Error – Rheo. Mode 
(R-DNL) vs. Wiper Setting and Temperature 
(50.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 
IW = 600 µA).
FIGURE 1-172: DNL Error – Rheo. Mode 
(R-DNL) vs. Wiper Setting and Temperature 
(50.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 20V, 
IW = 330 µA).
FIGURE 1-173: DNL Error – Rheo. Mode 
(R-DNL) vs. Wiper Setting and Temperature 
(50.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 10V, 
IW = 170 µA).
FIGURE 1-174: DNL Error – Rheo. Mode 
(R-DNL) vs. Wiper Setting and Temperature 
(50.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 
IW = 600 µA).
FIGURE 1-175: DNL Error – Rheo. Mode 
(R-DNL) vs. Wiper Setting and Temperature 
(50.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 20V, 
IW = 330 µA).
FIGURE 1-176: DNL Error – Rheo. Mode 
(R-DNL) vs. Wiper Setting and Temperature 
(50.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 10V, 
IW = 170 µA).
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
R - DNL (LSb)
Ͳ40C(IW=600uA)
+25C(IW=600uA)
+85C(IW=600uA)
+125C(IW=600uA)
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 32 64 96 128 160 192 224 256
R
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
R - DNL (LSb)
Ͳ40C(IW=330uA)
+25C(IW=330uA)
+85C(IW=330uA)
+125C(IW=330uA)
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 32 64 96 128 160 192 224 256
R
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
R - DNL (LSb)
Ͳ40C(IW=170uA)
+25C(IW=170uA)
+85C(IW=170uA)
+125C(IW=170uA)
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 32 64 96 128 160 192 224 256
R
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
R - DNL (LSb)
Ͳ40C(IW=600uA)
+25C(IW=600uA)
+85C(IW=600uA)
+125C(IW=600uA)
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 1 63 24 86 48 09 6 1 1 2 1 2 8
R
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
R - DNL (LSb)
Ͳ40C(IW=330uA)
+25C(IW=330uA)
+85C(IW=330uA)
+125C(IW=330uA)
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 1 63 24 86 48 09 6 1 1 2 1 2 8
R
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
R - DNL (LSb)
Ͳ40C(IW=170uA)
+25C(IW=170uA)
+85C(IW=170uA)
+125C(IW=170uA)
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 1 63 24 86 48 09 6 1 1 2 1 2 8
R
DAC Wiper Code
Typical Device

## Page 42

MCP45HVX1
DS20005307A-page 42  2014 Microchip Technology Inc.
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-177: DNL Error – Rheo. Mode 
(R-DNL) vs. Wiper Setting (@ +25°C)
(50.0 k, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-,
V+ = 36V and I
W = 600 µA, V+ = 20V and 
IW = 330 A, V+ = 10V and IW = 170 µA).
FIGURE 1-178: DNL Error – Rheo. Mode 
(R-DNL) vs. Wiper Setting (@ +25°C)
(50.0 k, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-,
V+ = 36V and I
W = 600 µA, V+ = 20V and 
IW = 330 µA, V+ = 10V and IW = 170 µA).
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
R - DNL (LSb)
10V(170uA)+25C
20V(330uA)+25C
36V(600uA)+25C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 32 64 96 128 160 192 224 256
R
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
R - DNL (LSb)
10V(170uA)+25C
20V(330uA)+25C
36V(600uA)+25C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 1 63 24 86 48 09 6 1 1 2 1 2 8
R
DAC Wiper Code
Typical Device

## Page 43

 2014 Microchip Technology Inc. DS20005307A-page 43
MCP45HVX1
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-179: VW PPM/°C (Pot. Mode) vs. 
Temperature and V+ Voltage 
( ( (V
W(code = n, +125°C) – VW(code = n, -40°C))/ 
VW(code = 255, +25°C)) * 1,000,000/+165°C) 
(50.0 k, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V).
FIGURE 1-180: VW PPM/°C (Pot. Mode) vs. 
Temperature and V+ Voltage 
( ( (V
W(code = n, +125°C) – VW(code = n, -40°C))/ 
VW(code = 127, +25°C)) * 1,000,000/+165°C) 
(50.0 k, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V).
FIGURE 1-181: RAB Resistance vs. 
Temperature and V+ Voltage    
(50.0 k
: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V).
Ͳ10
0
10
20
30
40
50
PPM per °C
PPMperCͲ10V
PPMperCͲ20V
PPMperCͲ36V
Ͳ50
Ͳ40
Ͳ30
Ͳ20
0 32 64 96 128 160 192 224 256
DAC Wiper Code
Ͳ10
0
10
20
30
40
50
PPM per °C
PPMperCͲ10V
PPMperCͲ20V
PPMperCͲ36V
Ͳ50
Ͳ40
Ͳ30
Ͳ20
0 1 63 24 86 48 09 6 1 1 2 1 2 8
DAC Wiper Code
49600
50000
50400
50800
51200
51600
RAB Resistance (:)
RABͲ10V
RABͲ20V
RABͲ36V
48400
48800
49200
Ͳ40 Ͳ20 0 20 40 60 80 100 120
R
Temperature (°C)

## Page 44

MCP45HVX1
DS20005307A-page 44  2014 Microchip Technology Inc.
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-182: Total Unadjusted Error (Pot. 
Mode) (VW) vs. Wiper Setting and Temperature 
(100.0 k, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V).
FIGURE 1-183: Total Unadjusted Error (Pot. 
Mode) (VW) vs. Wiper Setting and Temperature 
(100.0 k, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 20V).
FIGURE 1-184: Total Unadjusted Error (Pot. 
Mode) (VW) vs. Wiper Setting and Temperature 
(100.0 k, 8-bit: VL = 1.8V, 2.7V, 5.5V, 
A = V+, B = V-, DGND = V-, V+ = 10V).
FIGURE 1-185: Total Unadjusted Error (Pot. 
Mode) (VW) vs. Wiper Setting and Temperature 
(100.0 k, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V).
FIGURE 1-186: Total Unadjusted Error (Pot. 
Mode) (VW) vs. Wiper Setting and Temperature 
(100.0 k, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 20V).
FIGURE 1-187: Total Unadjusted Error (Pot. 
Mode) (VW) vs. Wiper Setting and Temperature 
(100.0 k, 7-bit: VL = 1.8V, 2.7V, 5.5V, 
A = V+, B = V-, DGND = V-, V+ = 10V).
Ͳ0.2
0.0
0.2
0.4
0.6
0.8
1.0
Unadjusted Error (LSb)
Ͳ40C
+25C
+85C
+125C
Ͳ1.0
Ͳ0.8
Ͳ0.6
Ͳ0.4
0 32 64 96 128 160 192 224 256
Total U
DAC Wiper Code
Ͳ0.2
0.0
0.2
0.4
0.6
0.8
1.0
Unadjusted Error (LSb)
Ͳ40C
+25C
+85C
+125C
Ͳ1.0
Ͳ0.8
Ͳ0.6
Ͳ0.4
0 32 64 96 128 160 192 224 256
Total U
DAC Wiper Code
Ͳ0.20
0.00
0.20
0.40
0.60
0.80
1.00
P -I N L  ( L S b )
Ͳ40C
+25C
+85C
+125C
Ͳ1.00
Ͳ0.80
Ͳ0.60
Ͳ0.40
0 32 64 96 128 160 192 224 256
P
DAC Wiper Code
Ͳ0.2
0.0
0.2
0.4
0.6
0.8
1.0
Unadjusted Error (LSb)
Ͳ40C
+25C
+85C
+125C
Ͳ1.0
Ͳ0.8
Ͳ0.6
Ͳ0.4
0 1 63 24 86 48 09 6 1 1 2 1 2 8
Total U
DAC Wiper Code
Ͳ0.2
0.0
0.2
0.4
0.6
0.8
1.0
Unadjusted Error (LSb)
Ͳ40C
+25C
+85C
+125C
Ͳ1.0
Ͳ0.8
Ͳ0.6
Ͳ0.4
0 1 63 24 86 48 09 6 1 1 2 1 2 8
Total U
DAC Wiper Code
Ͳ0.2
0.0
0.2
0.4
0.6
0.8
1.0
Unadjusted Error (LSb)
Ͳ40C
+25C
+85C
+125C
Ͳ1.0
Ͳ0.8
Ͳ0.6
Ͳ0.4
0 1 63 24 86 48 09 6 1 1 2 1 2 8
Total U
DAC Wiper Code

## Page 45

 2014 Microchip Technology Inc. DS20005307A-page 45
MCP45HVX1
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-188: Total Unadjusted Error (Pot. 
Mode) (VW) vs. Wiper Setting (@ +25°C)
(100.0 k, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V).
FIGURE 1-189: Full-Scale Error (Pot. Mode) 
(FSE) vs. Temperature and V+ Voltage
(100.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V).
FIGURE 1-190: Zero Scale Error (Pot. Mode) 
(ZSE) vs. Temperature and V+ Voltage
(100.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V).
FIGURE 1-191: Total Unadjusted Error (Pot. 
Mode) (VW) vs. Wiper Setting (@ +25°C)
(100.0 k, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V).
FIGURE 1-192: Full-Scale Error (Pot. Mode) 
(FSE) vs. Temperature and V+ Voltage
(100.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V). 
FIGURE 1-193: Zero Scale Error (Pot. Mode) 
(ZSE) vs. Temperature and V+ Voltage
(100.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V).
Ͳ0.20
0.00
0.20
0.40
0.60
0.80
1.00
P -I N L  ( L S b )
10V+25C
20V+25C
36V+25C
Ͳ1.00
Ͳ0.80
Ͳ0.60
Ͳ0.40
0 32 64 96 128 160 192 224 256
P
DAC Wiper Code
Ͳ0.6
Ͳ0.4
Ͳ0.2
0.0
l Scale Error (LSb)
Ͳ1.0
Ͳ0.8
Ͳ40 Ͳ20 0 20 40 60 80 100 120
Full
Temperature (°C)
FSEͲ10V
FSEͲ20V
FSEͲ36V
0.4
0.6
0.8
1.0
o Scale Error (LSb)
ZSEͲ10V
ZSEͲ20V
ZSEͲ36V
0.0
0.2
Ͳ40 Ͳ20 0 20 40 60 80 100 120
Zero
Temperature (°C)
Ͳ0.2
0.0
0.2
0.4
0.6
0.8
1.0
Unadjusted Error (LSb)
10V+25C
20V+25C
36V+25C
Ͳ1.0
Ͳ0.8
Ͳ0.6
Ͳ0.4
0 1 63 24 86 48 09 6 1 1 2 1 2 8
Total U
DAC Wiper Code
Ͳ0.6
Ͳ0.4
Ͳ0.2
0.0
l Scale Error (LSb)
FSEͲ10V
FSEͲ20V
FSEͲ36V
Ͳ1.0
Ͳ0.8
Ͳ40 Ͳ20 0 20 40 60 80 100 120
Full
Temperature (°C)
0.4
0.6
0.8
1.0
o Scale Error (LSb)
ZSEͲ10V
ZSEͲ20V
ZSEͲ36V
0.0
0.2
Ͳ40 Ͳ20 0 20 40 60 80 100 120
Zero
Temperature (°C)

## Page 46

MCP45HVX1
DS20005307A-page 46  2014 Microchip Technology Inc.
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-194: INL Error – Pot. Mode 
(P-INL) vs. Wiper Setting and Temperature 
(100.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V). 
FIGURE 1-195: INL Error – Pot. Mode 
(P-INL) vs. Wiper Setting and Temperature 
(100.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 20V).
FIGURE 1-196: INL Error – Pot. Mode 
(P-INL) vs. Wiper Setting and Temperature 
(100.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 10V).
FIGURE 1-197: INL Error – Pot. Mode 
(P-INL) vs. Wiper Setting and Temperature 
(100.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V). 
FIGURE 1-198: INL Error – Pot. Mode 
(P-INL) vs. Wiper Setting and Temperature 
(100.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 20V).
FIGURE 1-199: INL Error – Pot. Mode (P-
INL) vs. Wiper Setting and Temperature 
(100.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 10V).
Ͳ0.15
0.00
0.15
0.30
0.45
0.60
0.75
P -I N L  ( L S b )
Ͳ40C
+25C
+85C
+125C
Ͳ0.75
Ͳ0.60
Ͳ0.45
Ͳ0.30
0 32 64 96 128 160 192 224 256
P
DAC Wiper Code
Typical Device
Ͳ0.15
0.00
0.15
0.30
0.45
0.60
0.75
P -I N L  ( L S b )
Ͳ40C
+25C
+85C
+125C
Ͳ0.75
Ͳ0.60
Ͳ0.45
Ͳ0.30
0 32 64 96 128 160 192 224 256
P
DAC Wiper Code
Typical Device
Ͳ0.15
0.00
0.15
0.30
0.45
0.60
0.75
P -I N L  ( L S b )
Ͳ40C
+25C
+85C
+125C
Ͳ0.75
Ͳ0.60
Ͳ0.45
Ͳ0.30
0 32 64 96 128 160 192 224 256
P
DAC Wiper Code
Typical Device
Ͳ0.15
0.00
0.15
0.30
0.45
0.60
0.75
P -I N L  ( L S b )
Ͳ40C
+25C
+85C
+125C
Ͳ0.75
Ͳ0.60
Ͳ0.45
Ͳ0.30
0 1 63 24 86 48 09 6 1 1 2 1 2 8
P
DAC Wiper Code
Typical Device
Ͳ0.15
0.00
0.15
0.30
0.45
0.60
0.75
P -I N L  ( L S b )
Ͳ40C
+25C
+85C
+125C
Ͳ0.75
Ͳ0.60
Ͳ0.45
Ͳ0.30
0 1 63 24 86 48 09 6 1 1 2 1 2 8
P
DAC Wiper Code
Typical Device
Ͳ0.15
0.00
0.15
0.30
0.45
0.60
0.75
P -I N L  ( L S b )
Ͳ40C
+25C
+85C
+125C
Ͳ0.75
Ͳ0.60
Ͳ0.45
Ͳ0.30
0 1 63 24 86 48 09 6 1 1 2 1 2 8
P
DAC Wiper Code
Typical Device

## Page 47

 2014 Microchip Technology Inc. DS20005307A-page 47
MCP45HVX1
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-200: INL Error – Pot. Mode 
(P-INL) vs. Wiper Setting (@ +25°C)
(100.0 k, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V).
FIGURE 1-201: INL Error – Pot. Mode 
(P-INL) vs. Wiper Setting (@ +25°C)
(100.0 k, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V).
Ͳ0.15
0.00
0.15
0.30
0.45
0.60
0.75
P -I N L  ( L S b )
10V+25C
20V+25C
36V+25C
Ͳ0.75
Ͳ0.60
Ͳ0.45
Ͳ0.30
0 32 64 96 128 160 192 224 256
P
DAC Wiper Code
Typical Device
Ͳ0.15
0.00
0.15
0.30
0.45
0.60
0.75
P -I N L  ( L S b )
10V+25C
20V+25C
36V+25C
Ͳ0.75
Ͳ0.60
Ͳ0.45
Ͳ0.30
0 1 63 24 86 48 09 6 1 1 2 1 2 8
P
DAC Wiper Code
Typical Device

## Page 48

MCP45HVX1
DS20005307A-page 48  2014 Microchip Technology Inc.
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-202: DNL Error – Pot. Mode 
(P-DNL) vs. Wiper Setting and Temperature 
(100.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V).
FIGURE 1-203: DNL Error – Pot. Mode 
(P-DNL) vs. Wiper Setting and Temperature 
(100.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 20V).
FIGURE 1-204: DNL Error – Pot. Mode 
(P-DNL) vs. Wiper Setting and Temperature 
(100.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 10V).
FIGURE 1-205: DNL Error – Pot. Mode 
(P-DNL) vs. Wiper Setting and Temperature 
(100.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V).
FIGURE 1-206: DNL Error – Pot. Mode 
(P-DNL) vs. Wiper Setting and Temperature 
(100.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 20V).
FIGURE 1-207: DNL Error – Pot. Mode 
(P-DNL) vs. Wiper Setting and Temperature 
(100.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 10V).
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P - DNL (LSb)
Ͳ40C +25C +85C +125C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 32 64 96 128 160 192 224 256
P
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P - DNL (LSb)
Ͳ40C +25C +85C +125C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 32 64 96 128 160 192 224 256
P
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P - DNL (LSb)
Ͳ40C +25C +85C +125C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 32 64 96 128 160 192 224 256
P
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P - DNL (LSb)
Ͳ40C +25C +85C +125C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 1 63 24 86 48 09 6 1 1 2 1 2 8
P
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P - DNL (LSb)
Ͳ40C +25C +85C +125C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 1 63 24 86 48 09 6 1 1 2 1 2 8
P
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P - DNL (LSb)
Ͳ40C +25C +85C +125C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 1 63 24 86 48 09 6 1 1 2 1 2 8
P
DAC Wiper Code
Typical Device

## Page 49

 2014 Microchip Technology Inc. DS20005307A-page 49
MCP45HVX1
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-208: DNL Error – Pot. Mode 
(P-DNL) vs. Wiper Setting (@ +25°C)
(100.0 k, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V).
FIGURE 1-209: DNL Error – Pot. Mode 
(P-DNL) vs. Wiper Setting (@ +25°C)
(100.0 k, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V).
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P - DNL (LSb)
10V+25C 20V+25C 36V+25C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 32 64 96 128 160 192 224 256
P
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
P - DNL (LSb)
10V+25C 20V+25C 36V+25C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 1 63 24 86 48 09 6 1 1 2 1 2 8
P
DAC Wiper Code
Typical Device

## Page 50

MCP45HVX1
DS20005307A-page 50  2014 Microchip Technology Inc.
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-210: Wiper Resistance (RW) vs. 
Wiper Setting and Temperature 
(100.0 k, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 
IW = 300 µA).
FIGURE 1-211: Wiper Resistance (RW) vs. 
Wiper Setting and Temperature 
(100.0 k, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 20V, 
IW = 170 µA).
FIGURE 1-212: Wiper Resistance (RW) vs. 
Wiper Setting and Temperature 
(100.0 k, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 10V, 
IW = 83 µA).
FIGURE 1-213: Wiper Resistance (RW) vs. 
Wiper Setting and Temperature 
(100.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 
IW = 300 µA).
FIGURE 1-214: Wiper Resistance (RW) vs. 
Wiper Setting and Temperature 
(100.0 k, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 20V, 
IW = 170 µA).
FIGURE 1-215: Wiper Resistance (RW) vs. 
Wiper Setting and Temperature 
(100.0 k, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 10V, 
IW = 83 µA).
500
600
700
800
900
1000
1100
1200
1300
1400
esistance RW
-40C (IW = 300uA)
+25C (IW = 300uA)
+85C (IW = 300uA)
+125C (IW = 300uA)
0
100
200
300
400
0 32 64 96 128 160 192 224 256
Wiper Re
DAC Wiper Code
(Ω)
Measured RW is influenced by the analog switch leakage at +125°C.
See Section 5.2.1 of the “MCP45HVX1 Data Sheet” (DS20005304)
for additional information.
500
600
700
800
900
1000
1100
1200
1300
1400
-40C (IW = 170uA)
+25C (IW = 170uA)
+85C (IW = 170uA)
+125C (IW = 170uA)
0
100
200
300
400
0 32 64 96 128 160 192 224 256
DAC Wiper Code
Measured RW is influenced by the analog switch leakage at +125°C.
See Section 5.2.1 of the “MCP45HVX1 Data Sheet” (DS20005304)
for additional information.
Wiper Resistance RW (Ω)
500
600
700
800
900
1000
1100
1200
1300
1400
-40C (IW = 83uA)
+25C (IW = 83uA)
+85C (IW = 83uA)
+125C (IW = 83uA)
0
100
200
300
400
0 32 64 96 128 160 192 224 256
DAC Wiper Code
Measured RW is influenced by the analog switch leakage at +125°C.
See Section 5.2.1 of the “MCP45HVX1 Data Sheet” (DS20005304)
for additional information.
Wiper Resistance RW (Ω)
500
600
700
800
900
1000
1100
1200
1300
1400
-40C (IW = 300uA)
+25C (IW = 300uA)
+85C (IW = 300uA)
+125C (IW = 300uA)
0
100
200
300
400
0 1 63 24 86 48 09 6 1 1 2 1 2 8
DAC Wiper Code
Measured RW is influenced by the analog switch leakage at +125°C.
See Section 5.2.1 of the “MCP45HVX1 Data Sheet” (DS20005304) for
additional information.
Wiper Resistance RW (Ω)
500
600
700
800
900
1000
1100
1200
1300
1400
-40C (IW = 170uA)
+25C (IW = 170uA)
+85C (IW = 170uA)
+125C (IW = 170uA)
0
100
200
300
400
0 1 63 24 86 48 09 6 1 1 2 1 2 8
DAC Wiper Code
Measured RW is influenced by the analog switch leakage at +125°C.
See Section 5.2.1 of the “MCP45HVX1 Data Sheet” (DS20005304) for
additional information.Wiper Resistance R W (Ω)
500
600
700
800
900
1000
1100
1200
1300
1400
-40C (IW = 83uA)
+25C (IW = 83uA)
+85C (IW = 83uA)
+125C (IW = 83uA)
0
100
200
300
400
0 1 63 24 86 48 09 6 1 1 2 1 2 8
DAC Wiper Code
Measured RW is influenced by the analog switch leakage at +125°C.
See Section 5.2.1 of the “MCP45HVX1 Data Sheet” (DS20005304)
for additional information.
Wiper Resistance RW (Ω)

## Page 51

 2014 Microchip Technology Inc. DS20005307A-page 51
MCP45HVX1
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-216: Wiper Resistance (RW) vs. 
Wiper Setting (@ +29°C)
(100.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,    
A = V+, B = V-, DGND = V-,
V+ = 36V and I
W = 300 µA, V+ = 20V and 
IW = 170 µA, V+ = 10V and IW = 83 µA). 
FIGURE 1-217: Wiper Resistance (RW) vs. 
Wiper Setting (@ +29°C)
(100.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,    
A = V+, B = V-, DGND = V-,
V+ = 36V and I
W = 300 µA, V+ = 20V and 
IW = 170 µA, V+ = 10V and IW = 83 µA). 
500
600
700
800
900
1000
1100
1200
1300
1400
esistance RW (:)
10V+25C(IW=83uA)
20V+25C(IW=170uA)
36V+25C(IW=300uA)
0
100
200
300
400
0 32 64 96 128 160 192 224 256
Wiper Re
DAC Wiper Code
500
600
700
800
900
1000
1100
1200
1300
1400
esistance RW (:)
10V+25C(IW=83uA)
20V+25C(IW=170uA)
36V+25C(IW=300uA)
0
100
200
300
400
0 1 63 24 86 48 09 6 1 1 2 1 2 8
Wiper Re
DAC Wiper Code

## Page 52

MCP45HVX1
DS20005307A-page 52  2014 Microchip Technology Inc.
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-218: INL Error – Rheo. Mode 
(R-INL) vs. Wiper Setting and Temperature 
(100.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 
IW = 300 µA).
FIGURE 1-219: INL Error – Rheo. Mode 
(R-INL) vs. Wiper Setting and Temperature 
(100.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 20V, 
IW = 170 µA).
FIGURE 1-220: INL Error – Rheo. Mode 
(R-INL) vs. Wiper Setting and Temperature 
(100.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 10V, 
IW = 83 µA).
FIGURE 1-221: INL Error – Rheo. Mode 
(R-INL) vs. Wiper Setting and Temperature 
(100.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 
IW = 300 µA). 
FIGURE 1-222: INL Error – Rheo. Mode 
(R-INL) vs. Wiper Setting and Temperature 
(100.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 20V, 
IW = 170 µA).
FIGURE 1-223: INL Error – Rheo. Mode 
(R-INL) vs. Wiper Setting and Temperature 
(100.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 10V, 
IW = 83 µA).
Ͳ0.5
0.0
0.5
1.0
1.5
2.0
R -I N L  ( L S b )
Ͳ2.0
Ͳ1.5
Ͳ1.0
0 32 64 96 128 160 192 224 256
R
DAC Wiper Code
Ͳ40C(IW=300uA)
+25C(IW=300uA)
+85C(IW=300uA)
+125C(IW=300uA)
Typical Device
Ͳ0.5
0.0
0.5
1.0
1.5
2.0
R -I N L  ( L S b )
Ͳ2.0
Ͳ1.5
Ͳ1.0
0 32 64 96 128 160 192 224 256
R
DAC Wiper Code
Ͳ40C(IW=170uA)
+25C(IW=170uA)
+85C(IW=170uA)
+125C(IW=170uA)
Typical Device
Ͳ0.5
0.0
0.5
1.0
1.5
2.0
R -I N L  ( L S b )
Ͳ2.0
Ͳ1.5
Ͳ1.0
0 32 64 96 128 160 192 224 256
R
DAC Wiper Code
Ͳ40C(IW=83uA)
+25C(IW=83uA)
+85C(IW=83uA)
+125C(IW=83uA)
Typical Device
Ͳ0.5
0.0
0.5
1.0
1.5
2.0
R -I N L  ( L S b )
Ͳ40C(IW=300uA)
+25C(IW=300uA)
+85C(IW=300uA)
+125C(IW=300uA)
Ͳ2.0
Ͳ1.5
Ͳ1.0
0 1 63 24 86 48 09 6 1 1 2 1 2 8
R
DAC Wiper Code
Typical Device
Ͳ0.5
0.0
0.5
1.0
1.5
2.0
R -I N L  ( L S b )
Ͳ40C(IW=170uA)
+25C(IW=170uA)
+85C(IW=170uA)
+125C(IW=170uA)
Ͳ2.0
Ͳ1.5
Ͳ1.0
0 1 63 24 86 48 09 6 1 1 2 1 2 8
R
DAC Wiper Code
Typical Device
Ͳ0.5
0.0
0.5
1.0
1.5
2.0
R -I N L  ( L S b )
Ͳ40C(IW=83uA)
+25C(IW=83uA)
+85C(IW=83uA)
+125C(IW=83uA)
Ͳ2.0
Ͳ1.5
Ͳ1.0
0 1 63 24 86 48 09 6 1 1 2 1 2 8
R
DAC Wiper Code
Typical Device

## Page 53

 2014 Microchip Technology Inc. DS20005307A-page 53
MCP45HVX1
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V
FIGURE 1-224: INL Error – Rheo. Mode 
(R-INL) vs. Wiper Setting (@ +25°C)
(100.0 k, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, 
V+ = 36V and I
W = 300 µA, V+ = 20V and 
IW = 170 µA, V+ = 10V and IW = 83 µA).
FIGURE 1-225: INL Error – Rheo. Mode 
(R-INL) vs. Wiper Setting (@ +25°C)
(100.0 k, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, 
V+ = 36V and I
W = 300 µA, V+ = 20V and 
IW = 170 µA, V+ = 10V and IW = 83 µA).
Ͳ0.5
0.0
0.5
1.0
1.5
2.0
R -I N L  ( L S b )
10V(83uA)+25C
20V(170uA)+25C
36V(300uA)+25C
Ͳ2.0
Ͳ1.5
Ͳ1.0
0 32 64 96 128 160 192 224 256
R
DAC Wiper Code
Typical Device
Ͳ0.5
0.0
0.5
1.0
1.5
2.0
R -I N L  ( L S b )
10V(83uA)+25C
20V(170uA)+25C
36V(300uA)+25C
Ͳ2.0
Ͳ1.5
Ͳ1.0
0 1 63 24 86 48 09 6 1 1 2 1 2 8
R
DAC Wiper Code
Typical Device

## Page 54

MCP45HVX1
DS20005307A-page 54  2014 Microchip Technology Inc.
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-226: DNL Error – Rheo. Mode 
(R-DNL) vs. Wiper Setting and Temperature 
(100.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 
IW = 300 µA).
FIGURE 1-227: DNL Error – Rheo. Mode 
(R-DNL) vs. Wiper Setting and Temperature 
(100.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 20V, 
IW = 170 µA).
FIGURE 1-228: DNL Error – Rheo. Mode 
(R-DNL) vs. Wiper Setting and Temperature 
(100.0 k
, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 10V, 
IW = 83 µA).
FIGURE 1-229: DNL Error – Rheo. Mode 
(R-DNL) vs. Wiper Setting and Temperature 
(100.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 
IW = 300 µA).
FIGURE 1-230: DNL Error – Rheo. Mode 
(R-DNL) vs. Wiper Setting and Temperature 
(100.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 20V, 
IW = 170 µA).
FIGURE 1-231: DNL Error – Rheo. Mode 
(R-DNL) vs. Wiper Setting and Temperature 
(100.0 k
, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 10V, 
IW = 83 µA).
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
R - DNL (LSb)
Ͳ40C(IW=300uA)
+25C(IW=300uA)
+85C(IW=300uA)
+125C(IW=300uA)
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 32 64 96 128 160 192 224 256
R
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
R - DNL (LSb)
Ͳ40C(IW=170uA)
+25C(IW=170uA)
+85C(IW=170uA)
+125C(IW=170uA)
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 32 64 96 128 160 192 224 256
R
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
R - DNL (LSb)
Ͳ40C(IW=83uA)
+25C(IW=83uA)
+85C(IW=83uA)
+125C(IW=83uA)
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 32 64 96 128 160 192 224 256
R
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
R - DNL (LSb)
Ͳ40C(IW=300uA)
+25C(IW=300uA)
+85C(IW=300uA)
+125C(IW=300uA)
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 1 63 24 86 48 09 6 1 1 2 1 2 8
R
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
R - DNL (LSb)
Ͳ40C(IW=170uA)
+25C(IW=170uA)
+85C(IW=170uA)
+125C(IW=170uA)
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 1 63 24 86 48 09 6 1 1 2 1 2 8
R
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
R - DNL (LSb)
Ͳ40C(IW=83uA)
+25C(IW=83uA)
+85C(IW=83uA)
+125C(IW=83uA)
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 1 63 24 86 48 09 6 1 1 2 1 2 8
R
DAC Wiper Code
Typical Device

## Page 55

 2014 Microchip Technology Inc. DS20005307A-page 55
MCP45HVX1
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-232: DNL Error – Rheo. Mode 
(R-DNL) vs. Wiper Setting (@ +25°C)
(100.0 k, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, 
V+ = 36V and I
W = 300 µA, V+ = 20V and 
IW = 170 µA, V+ = 10V and IW = 83 µA).
FIGURE 1-233: DNL Error – Rheo. Mode 
(R-DNL) vs. Wiper Setting (@ +25°C)
(100.0 k, 7-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, 
V+ = 36V and I
W = 300 µA, V+ = 20V and 
IW = 170 µA, V+ = 10V and IW = 83 µA).
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
R - DNL (LSb)
10V(83uA)+25C
20V(170uA)+25C
36V(300uA)+25C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 32 64 96 128 160 192 224 256
R
DAC Wiper Code
Typical Device
Ͳ0.1
0.0
0.1
0.2
0.3
0.4
0.5
R - DNL (LSb)
10V(83uA)+25C
20V(170uA)+25C
36V(300uA)+25C
Ͳ0.5
Ͳ0.4
Ͳ0.3
Ͳ0.2
0 1 63 24 86 48 09 6 1 1 2 1 2 8
R
DAC Wiper Code
Typical Device

## Page 56

MCP45HVX1
DS20005307A-page 56  2014 Microchip Technology Inc.
Note: Unless otherwise indicated, TA = +25°C, VL = 5.0V, DGND = V-, V+ = 36V.
FIGURE 1-234: VW PPM/°C (Pot. Mode) vs. 
Temperature and V+ Voltage 
( ( (V
W(code = n, +125°C) – VW(code = n, -40°C))/ 
VW(code = 255, +25°C)) * 1,000,000/+165°C) 
(100.0 k, 8-bit: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V).
FIGURE 1-235: VW PPM/°C (Pot. Mode) vs. 
Temperature and V+ Voltage 
( ( (V
W(code = n, +125°C) – VW(code = n, -40°C))/ 
VW(code = 127, +25°C)) * 1,000,000/+165°C) 
(100.0 k, 7-bit: VL = 1.8V, 2.7V, 5.5V, 
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V).
FIGURE 1-236: RAB Resistance vs. 
Temperature and V+ Voltage    
(100.0 k
: VL = 1.8V, 2.7V, 5.5V,
A = V+, B = V-, DGND = V-, V+ = 36V, 20V, 10V).
1.1 Test Circuits
FIGURE 1-237: RW and RBW Measurement.
Ͳ10
0
10
20
30
40
50
PPM per °C
PPMperCͲ10V
PPMperCͲ20V
PPMperCͲ36V
Ͳ50
Ͳ40
Ͳ30
Ͳ20
0 32 64 96 128 160 192 224 256
DAC Wiper Code
Ͳ10
0
10
20
30
40
50
PPM per °C
PPMperCͲ10V
PPMperCͲ20V
PPMperCͲ36V
Ͳ50
Ͳ40
Ͳ30
Ͳ20
0 1 63 24 86 48 09 6 1 1 2 1 2 8
DAC Wiper Code
93000
93500
94000
94500
95000
95500
96000
RAB Resistance (:)
RABͲ10V
RABͲ20V
RABͲ36V
91000
91500
92000
92500
Ͳ40 Ͳ20 0 20 40 60 80 100 120
R
Temperature (°C)
A
B
W
IW 
VW 
RBW = VW/IW 
VA 
VB 
RW = (VW – VA)/IW 
0.1V
+
-
+
-
V- to V+
Code = ZS to FS
Floating

## Page 57

 2014 Microchip Technology Inc. DS20005307A-page 57
MCP45HVX1
APPENDIX A: REVISION HISTORY
Revision A (June 2014)
• Original Release of this Document.

## Page 58

MCP45HVX1
DS20005307A-page 58  2014 Microchip Technology Inc.
NOTES:

## Page 59

 2014 Microchip Technology Inc. DS20005307A-page 59
Information contained in this publication regarding device
applications and the like is provided only for your convenience
and may be superseded by updates. It is your responsibility to
ensure that your application meets with your specifications.
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
suits, or expenses resulting from such use. No licenses are
conveyed, implicitly or otherwise, under any Microchip
intellectual property rights.
Trademarks
The Microchip name and logo, the Microchip logo, dsPIC, 
FlashFlex, KEELOQ, KEELOQ logo, MPLAB, PIC, PICmicro, 
PICSTART, PIC32 logo, rfPIC, SST, SST Logo, SuperFlash 
and UNI/O are registered trademarks of Microchip Technology 
Incorporated in the U.S.A. and other countries.
FilterLab, Hampshire, HI-TECH C, Linear Active Thermistor, 
MTP, SEEVAL and The Embedded Control Solutions 
Company are registered trademarks of Microchip Technology 
Incorporated in the U.S.A.
Silicon Storage Technology is a registered trademark of 
Microchip Technology Inc. in other countries.
Analog-for-the-Digital Age, Application Maestro, BodyCom, 
chipKIT, chipKIT logo, CodeGuard, dsPICDEM, 
dsPICDEM.net, dsPICworks, dsSPEAK, ECAN, 
ECONOMONITOR, FanSense, HI-TIDE, In-Circuit Serial 
Programming, ICSP, Mindi, MiWi, MPASM, MPF, MPLAB 
Certified logo, MPLIB, MPLINK, mTouch, Omniscient Code 
Generation, PICC, PICC-18, PICDEM, PICDEM.net, PICkit, 
PICtail, REAL ICE, rfLAB, Select Mode, SQI, Serial Quad I/O, 
Total Endurance, TSHARC, UniWinDriver, WiperLock, ZENA 
and Z-Scale are trademarks of Microchip Technology 
Incorporated in the U.S.A. and other countries.
SQTP is a service mark of Microchip Technology Incorporated 
in the U.S.A.
GestIC and ULPP are registered trademarks of Microchip 
Technology Germany II GmbH & Co. KG, a subsidiary of 
Microchip Technology Inc., in other countries. 
All other trademarks mentioned herein are property of their 
respective companies.
© 2014, Microchip Technology Incorporated, Printed in the 
U.S.A., All Rights Reserved.
 Printed on recycled paper.
ISBN: 978-1-63276-296-2
Note the following details of the code protection feature on Microchip devices:
• Microchip products meet the specification contai ned in their particular Microchip Data Sheet.
• Microchip believes that its family of products is one of the most secure families of its kind on the market today, when used i n the 
intended manner and under normal conditions.
• There are dishonest and possibly illegal methods used to breach the code protection feature. All of these methods, to our 
knowledge, require using the Microchip products in a manner outside the operating specifications contained in Microchip’s Data 
Sheets. Most likely, the person doing so is engaged in theft of intellectual property.
• Microchip is willing to work with the customer who is concerned about the integrity of their code.
• Neither Microchip nor any other semiconduc tor manufacturer can guarantee the security of their code. Code protection does not 
mean that we are guaranteeing the product as “unbreakable.”
Code protection is constantly evolving. We at Microchip are co mmitted to continuously improvin g the code protection features of  our
products. Attempts to break Microchip’s code protection feature may be a violation of the Digital Millennium Copyright Act. If such acts
allow unauthorized access to your software or other copyrighted work, you may have a right to sue for relief under that Act.
Microchip received ISO/TS-16949:2009 certification for its worldwide 
headquarters, design and wafer fabrication facilities in Chandler and 
Tempe, Arizona; Gresham, Oregon and design centers in California 
and India. The Company’s quality system processes and procedures 
are for its PIC® MCUs and dsPIC® DSCs, KEELOQ® code hopping 
devices, Serial EEPROMs, microperipherals, nonvolatile memory and 
analog products. In addition, Microchip’s quality system for the design 
and manufacture of development systems is ISO 9001:2000 certified.
QUALITY MANAGEMENT  S YSTEM 
CERTIFIED BY DNV 
== ISO/TS 16949 ==

## Page 60

DS20005307A-page 60  2014 Microchip Technology Inc.
AMERICAS
Corporate Office
2355 West Chandler Blvd.
Chandler, AZ 85224-6199
Tel: 480-792-7200 
Fax: 480-792-7277
Technical Support: 
http://www.microchip.com/
support
Web Address: 
www.microchip.com
Atlanta
Duluth, GA 
Tel: 678-957-9614 
Fax: 678-957-1455
Austin, TX
Tel: 512-257-3370 
Boston
Westborough, MA 
Tel: 774-760-0087 
Fax: 774-760-0088
Chicago
Itasca, IL 
Tel: 630-285-0071 
Fax: 630-285-0075
Cleveland
Independence, OH 
Tel: 216-447-0464 
Fax: 216-447-0643
Dallas
Addison, TX 
Tel: 972-818-7423 
Fax: 972-818-2924
Detroit
Novi, MI 
Tel: 248-848-4000
Houston, TX 
Tel: 281-894-5983
Indianapolis
Noblesville, IN 
Tel: 317-773-8323
Fax: 317-773-5453
Los Angeles
Mission Viejo, CA 
Tel: 949-462-9523 
Fax: 949-462-9608
New York, NY 
Tel: 631-435-6000
San Jose, CA 
Tel: 408-735-9110
Canada - Toronto
Tel: 905-673-0699 
Fax: 905-673-6509
ASIA/PACIFIC
Asia Pacific Office
Suites 3707-14, 37th Floor
Tower 6, The Gateway
Harbour City, Kowloon
Hong Kong
Tel: 852-2943-5100
Fax: 852-2401-3431
Australia - Sydney
Tel: 61-2-9868-6733
Fax: 61-2-9868-6755
China - Beijing
Tel: 86-10-8569-7000 
Fax: 86-10-8528-2104
China - Chengdu
Tel: 86-28-8665-5511
Fax: 86-28-8665-7889
China - Chongqing
Tel: 86-23-8980-9588
Fax: 86-23-8980-9500
China - Hangzhou
Tel: 86-571-8792-8115 
Fax: 86-571-8792-8116
China - Hong Kong SAR
Tel: 852-2943-5100 
Fax: 852-2401-3431
China - Nanjing
Tel: 86-25-8473-2460
Fax: 86-25-8473-2470
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
Tel: 86-755-8864-2200 
Fax: 86-755-8203-1760
China - Wuhan
Tel: 86-27-5980-5300
Fax: 86-27-5980-5118
China - Xian
Tel: 86-29-8833-7252
Fax: 86-29-8833-7256
China - Xiamen
Tel: 86-592-2388138 
Fax: 86-592-2388130
China - Zhuhai
Tel: 86-756-3210040 
Fax: 86-756-3210049
ASIA/PACIFIC
India - Bangalore
Tel: 91-80-3090-4444 
Fax: 91-80-3090-4123
India - New Delhi
Tel: 91-11-4160-8631
Fax: 91-11-4160-8632
India - Pune
Tel: 91-20-3019-1500
Japan - Osaka
Tel: 81-6-6152-7160 
Fax: 81-6-6152-9310
Japan - Tokyo
Tel: 81-3-6880- 3770 
Fax: 81-3-6880-3771
Korea - Daegu
Tel: 82-53-744-4301
Fax: 82-53-744-4302
Korea - Seoul
Tel: 82-2-554-7200
Fax: 82-2-558-5932 or 
82-2-558-5934
Malaysia - Kuala Lumpur
Tel: 60-3-6201-9857
Fax: 60-3-6201-9859
Malaysia - Penang
Tel: 60-4-227-8870
Fax: 60-4-227-4068
Philippines - Manila
Tel: 63-2-634-9065
Fax: 63-2-634-9069
Singapore
Tel: 65-6334-8870
Fax: 65-6334-8850
Taiwan - Hsin Chu
Tel: 886-3-5778-366
Fax: 886-3-5770-955
Taiwan - Kaohsiung
Tel: 886-7-213-7830
Taiwan - Taipei
Tel: 886-2-2508-8600 
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
Germany - Dusseldorf
Tel: 49-2129-3766400
Germany - Munich
Tel: 49-89-627-144-0 
Fax: 49-89-627-144-44
Germany - Pforzheim
Tel: 49-7231-424750
Italy - Milan 
Tel: 39-0331-742611 
Fax: 39-0331-466781
Italy - Venice
Tel: 39-049-7625286 
Netherlands - Drunen
Tel: 31-416-690399 
Fax: 31-416-690340
Poland - Warsaw
Tel: 48-22-3325737 
Spain - Madrid
Tel: 34-91-708-08-90
Fax: 34-91-708-08-91
Sweden - Stockholm
Tel: 46-8-5090-4654
UK - Wokingham
Tel: 44-118-921-5800
Fax: 44-118-921-5820
Worldwide Sales and Service
03/25/14
