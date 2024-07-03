# metrology

> metrology: the science of  measurement, embracing both experimental and theoretical determinations  at any level of uncertainty in any field of science and technology
> -International Bureau of Weights and Measures (BIPM) 

## solar panel output limits

Measure the short-circuit current (max current, $I_{sc}$) and open-circuit voltage (max voltage, $V_{oc}$) of your solar array both in series and in parallel. You will use the range of these measurements to select appropriate sensors for current and voltage. 

Connect the four cells of your solar array in series. 
There are 18 pins at the top of your solar panel. 

```
+ + + +      x x x x x

- - - -      y y y y y
```

The block of 8 pins at the top left connects to the positive and negative end of each solar cell. To wire the cells in series, place jumper wires between the cells like this. 

```
pos output---+ + + +      x x x x x
              / / /
             - - - -      y y y y y
                    `---neg output
```

The top left pin and bottom right pin are the outputs of your 4S (4 cells in series) solar array. Ignore the block of 10 pins for now. 

Using a multimeter, measure the current and voltage of your solar array. Use the smallest valid measurement range to obtain the most accurate measurements. Record your measurements. 

Now wire your solar array in parallel. 

```
       _____
etc.  / ___ \  etc.
 /   / /   \ \      \
+ + + +      x x x x x--- pos output

- - - -      y y y y y--- neg output
etc.   \____/  etc. 
```

Use the block of 10 pins to wire the cells in parallel. The top 5 (x) are wired together and the bottom 5 (y) are wired together. The far-right pins are the outputs of your 4P (4 cells in parallel) solar array. 

Using a multimeter, measure the current and voltage of your solar array. Use the smallest valid measurement range to obtain the most accurate measurements. Record your measurements. 

|               | series | parallel |
| ------------- | ------ | -------- |
| $I_{sc}$ (mA) |        |          |
| $V_{oc}$ (V)  |        |          |

## current and voltage measurements

Previously, you determined the current and voltage limits of a 4-cell solar array. In a future lab you will measure the full range of the array's current and voltage output and create an I-V curve to characterize the array. In this lab you will begin learning how to measure analog signals with FlatSAT’s Arduino microcontroller. 

To measure the current and voltage provided by FlatSAT’s solar array, you must pick appropriate sensors. 

Today you will create a voltage divider to scale FlatSAT's solar array output to a value that FlatSAT's Arduino flight computer can read safely. 

You will also use a voltage divider and photoresistor/phototransistor to create a light sensor and perform basic calibration. 

## Overview

- voltage measurement
  
  - voltage divider
  - analog-to-digital converter (ADC)
  - calibration

- light measurement 

- Arduino basics

## Hardware

- FlatSAT
  - Arduino MKR Zero
  - breadboard
  - resistors
  - photoresistor/phototransistor

## Equipment

- benchtop power supply
- laptop
- Micro USB cable
- multimeter

## Software

- Arduino IDE

- SAMD drivers 
  
  - if necessary tools -> board -> boards manager -> "SAMD" -> Arduino SAMD Boards -> install

- `lab_00_metrology.ino`

## Documentation

- Arduino MKR Zero datasheet

## Preliminary

- git sync -> pull
- use a label maker to identify FlatSAT with your group name

## Solar arrays limits

For this lab, use these values as your solar array's max current and voltage. 

|              | series | parallel |
| ------------ | ------ | -------- |
| current (mA) | 40     | 160      |
| voltage (V)  | 30     | 7.5      |

## Voltage

To accurately measure FlatSAT's solar array performance, your sensor must be able to measure DC voltage from 0–30 V. 

Investigate this requirement. 

### Arduino limits

Prepare to measure voltage with an Arduino MKR. 

Review the Arduino MKR datasheet and record the following values. 

- Allowable input voltage: 
  - see the warning at the bottom of page 2
- Max ADC resolution: 

Using these values, how many digits do you expect to be able to report for the voltage of FlatSAT's 30 V solar array?

Every sensor is resolution-limited. Sensors provides maximum resolution when the range of the measured signal matches the sensor's detection range. To achieve the best available voltage resolution you will need to map the 0–30 V panel voltage to the 0–3.3 V input range of the Arduino MKR. Note: 3.3 V is sometimes referred to as 3V3. 

If you connect anything higher than 3.3 V directly to an input pin on your 3.3 V Arduino, the best possible outcome is that the Arduino will falsely report its maximum of 3.3 V. You may also permanently damage your Arduino. 

To map a 30 V signal to a 3.3 V sensor, you will use a voltage divider. 

### Voltage Divider

> A **voltage divider** is a passive linear circuit that produces an output voltage $V_{out}$ that is a fraction of its input voltage $V_{in}$. **Voltage division** is the result of distributing the input voltage among the components of the divider. A simple example of a voltage divider is two resistors connected in series, with the input voltage applied across the resistor pair and the output voltage emerging from the connection between them.
> -[Wikipedia](https://en.wikipedia.org/wiki/Voltage_divider)

![Resistive_divider2](sources/Resistive_divider2.svg)

$$
V_{out} = \frac{R_2}{R_1+R_2}V_{in}
$$

Approximately how much do you need to reduce your input voltage? 

What relative values of $R_1$ and $R_2$ will give you that ratio? Work this out in your lab notebook. 

Now you have to pick actual resistors and make a voltage divider. Use these equations.  

- $V = IR$
- $P=IV$
- your resistors are 1/4 W resistors
- **hint**: an ideal voltmeter has infinite resistance: should you pick large values for $R_1$ and $R_2$, or small values?

Select resistors for R1 and R2. Ensure your resistors won't smoke or catch fire. Record these values (in your lab notebook). 

**At this time, explain your choice to your instructor.** 

Begin building FlatSAT. 

**Note:** Do not connect your Arduino to power or to a computer at this time. 

- Place the two resistors of your voltage divider
- connect Vin of your voltage divider to a 30 V power supply
- Vout of your voltage divider will connect to pin A3
  - **don't connect this yet**
- ground–ground–ground (voltage divider, Arduino, power supply)

Set your benchtop power supply to 30 V/0.05 A. 

Connect the power supply to the top and bottom of your voltage divider. 

With your multimeter, measure the voltage between ground (black) and the center of your voltage divider (Vout)—it should be less than 3.3 V. 

**Do not proceed until Ground–middle is ≤ 3.3 V**

### Arduino measurement

Now you will measure voltage with Arduino. Connect Vout of your voltage divider to pin A3. 

#### Arduino program flow

Review `lab_00b_metrology.ino`. Look at the next-to-last line. 

```c++
  delay(100);
```

This line inserts a delay of 100 milliseconds between every run of loop(). This prevents the serial monitor from scrolling uselessly fast. However, it's a terrible way to run a program. Since Arduino is a single-processor microcontroller, nothing else can happen during the delay. 

This is acceptable for a simple program like this one, used to calibrate a sensor. However, FlatSAT constantly needs to accomplish and monitor multiple tasks, so it won't be acceptable in the future. 

#### Measure!

- Connect Arduino to your computer. 
- Select the correct board (tools -> board -> SAMD -> Arduino MKR Zero)
- Select the correct port (COMXX—if more than one, try until one works). 
- Click *upload* (right arrow near the top of the window). 

Open the Arduino IDE's serial plotter (tools -> serial plotter). Select "value 2" and unselect "value 1." 

The serial plotter will show a moving graph. Adjust the power supply **downward only** and watch the plotted line move. As the power supply moves from 30 V–0 V, Arduino sees from 3.3 V–0V. What range of values does the serial plotter display? 

This is because of the Arduino’s 12-bit ADC resolution. You must add a scale factor to output the correct voltage. 

Arduino's default ADC resolution is 10-bit. This lab uses the command `analogReadResolution(12);` to instead select a higher 12-bit resolution. 

With an input range of 0–3.3 V and 12-bit/4096 count, Arduino's sensitivity is 0.8 mV/count (3.3V/4096 count). 

​    To properly display Arduino's measured voltage in mV, you must multiply the ADC reading `volt_counts` by 0.8. 

However, you instead want to display the voltage of your solar array/solar array simulator. You must **multiply the measured voltage** by the ratio of your voltage divider. 

Note: For this calculation, use measured resistance values for R1 and R2 rather than their specification values. 

$voltage = volt\_ counts * \left(\frac{0.8\ mV}{count} * \frac{R_1+R_2}{R_2}\right)$ 

Calculate this factor and change the following code line to include the proper scale factor instead of 1. 

```c++
volts = volt_counts * 1.0;
```

Upload this modified code and ensure that the serial plotter matches the output of your power supply. If not, adjust as necessary. 

## Sun Sensor

There are many ways to determine a spacecraft's orientation to the sun. You will create a light sensor that can be used in a sun sensor. 

Replace one of the resistors of your voltage divider with a photoresistor/phototransistor. Connect Vin of your voltage divider to Arduino's Vcc pin, which provides 3V3. 

Change this code back to its original value (as shown below). 

```c++
volts = volt_counts * 1.0;
```

Connect Arduino, upload the code, and view the value on the serial monitor. Cover the photoresistor/phototransistor with your hands and watch the value change. 

Using the values in complete darkness and bright light (sunlight if possible), determine a calibration curve to distinguish darkness, dim light, and bright light.

If you had multiple photoresistors/phototransistors you could measure their relative brightnesses to determine the sun's location. 

## Current measurement

You could also measure current using Ohm's law. 

$$
V=IR
$$

Rearranged:

$$
I = \frac{V}{R}  
$$

In a future lab you will use an INA219 current sensor to measure the current output of your solar array. That sensor uses a voltage divider to measure current. 

## Cleanup

- disconnect Arduino and place in your team's drawer
- turn off multimeter
- turn off power supply. 
