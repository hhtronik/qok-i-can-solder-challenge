HHTronik Q.O.K. / I.CAN.SOLDER SMD Challenge
============================================

![HHTronik Q.O.K. / I.CAN.SOLDER Challenge Q.O.K PCB rendering](./assets/pcb-rendering.png)

The question you always had is: how small can it get? Here's the answer: 01005 resistors (that's 0.4x0.2mm) and 0201 LEDs (0.65x0.38mm)

*The question we have is: __are you and your soldering iron ready for this challenge?__*


On this board you'll find:

- a STM8 microcontroller ready for some blinky action
- a small step up driver providing 3.6V to light those blue LEDs
- a PCB-integrated CR20xx battery holder
- polarity protection with reverse battery insertion LED
- a "power good" LED
- 12 footprints to show your soldering skill:
	- 1206 resistor and LED (3.0x1.5 mm / 0.12x0.06 inch)
	- 0805 resistor and LED (2.0x1.3 mm / 0.08x0.05 inch)
	- 0603 resistor and LED (1.5x0.8 mm / 0.06x0.03 inch)
	- 0402 resistor and LED (1.0x0.5 mm / 0.04x0.02 inch)
	- 0201 resistor and LED (0.6x0.3 mm / 0.02x0.01 inch)
	- 01005 resistor and 0201 LED (0.4x0.2 mm / 0.016x0.008 inch)
- Test points to ease probing

>
> This PCB is designed to be challenging to complete, this means you're
> likely to fail, at least for the smaller components which are super easy
> to drown in a blob of solder or to lose track of
>
> There's no way you could perform the assembly without good fine tip tweezers
> very steady hands, buckets of flux and your favourite expletives at hand!
>
> Good luck ;)
>

What equipement do I need?
--------------------------

- A great soldering iron
- Your favourite solder
- Lots of flux, because flux is life
- Fine tip tweezers
- Lots of üatience
- a multimeter (ideally with a diode test mode)

As always, work safety is important, so don't burn yourself and don't inhale the fumes released while soldering. Working in a well ventilated area is good. We'd definitely recommend adding some ventilation (for example a fan of some sort blowing the fumes away from you or a proper soldering fume extractor if you plan on doing this over and over again :)

Optionally you may have these things around:

- rubbing alcool or isopropanol
- some lint-free cloth / paper towel
- probably magnifying glasses or a binocular microscope

Components
----------

| Ref. | Part                        | Notes / Alternative parts  |
| ---- | --------------------------- | -------------------------- |
| D1   | `Diodes Inc. 1N5819HW1`     | `MBR0520LT1G` or any other SOD123 Schottky diode with If > 500mA and low Vf
| L1   | `TDK VLS252012HBU-220M`     | `Murata LQH2HPZ220MJRL` / 22uH 2.5x2.0mm inductor
| U1   | `Hexin  HX3001`             | `Chipown AP2000ATCER` / Current mode step up converter SOT23-6
| C1   | `Samsung CL21A106KPFNNNF`   | 10uF 0805 X5R 10V MLC capacitor
| C2   | `Samsung CL21B474KAFNNNE`   | 470nF 0805 X7R 25V MLC capacitor
| R1   | `Panasonic ERJ-6ENF51R1V`   | 51 Ohm 0805 1% resistor
| R2   | `Panasonic ERJ-3GEYJ105V`   | 1 MOhm 0603 5% resistor
| LED1 | `Inolux IN-S126ASUW`        | Side view white LED If = 20mA 
| LED2 | `Inolux IN-S126ASUW`        | Side view white LED If = 20mA
| S1   | `C&K PTS645SL50SMTR92`      | Many surface mount tactile switches with a 6x6mm outline
| BAT1 | `Keystone Electronics 3034` | `Linx Technologies BAT-HLD-001` or `MPD BK-912-TR` or `Q&J WJ-CR2032-1-W`


I don't know anything about electronics, what can I learn?
----------------------------------------------------------

Errrr.... you should probably start with some of our other soldering kits:

- [HHTronik / I learn soldering SMD Boost Edition](https://github.com/hhtronik/qok-i-learn-soldering-smd-boost) (this one might be a challenge already :)
- [HHTronik / I learn soldering SMD](https://github.com/hhtronik/qok-i-learn-soldering-smd)
- [HHTronik / I learn soldering TH](https://github.com/hhtronik/qok-i-learn-soldering-th)

LICENCE
-------

This project is licenced under CERN Open Hardware Licence Version 2 - Strongly Reciprocal see LICENCE file for the full text.