# UNO-WiFi-R3-ATmega328P-ESP8266

<br />

This project is made for Arduino Uno WiFi is an Arduino Uno with an integrated WiFi module. Now you can use both module together communicating with each other using serial pins without modifying any firmware.
 
<img width="450px" height="350px" src="https://user-images.githubusercontent.com/23693439/118520926-ecec2680-b753-11eb-8ccb-41cf73a27d85.jpg" style="display: block; margin-left: auto; margin-right: auto; width: 50%;" />



Don't forget to change board options before uploading when switching.

<table border="1" cellspacing="0" cellpadding="0">
<tbody>
<tr>
<td>
<p>&nbsp;</p>
</td>
<td>
<p>1</p>
</td>
<td>
<p>2</p>
</td>
<td>
<p>3</p>
</td>
<td>
<p>4</p>
</td>
<td>
<p>5</p>
</td>
<td>
<p>6</p>
</td>
<td>
<p>7</p>
</td>
<td>
<p>8</p>
</td>
</tr>
<tr>
<td>
<p>CH340 connect to ESP8266 (upload sketch)</p>
</td>
<td>
<p>OFF</p>
</td>
<td>
<p>OFF</p>
</td>
<td>
<p>OFF</p>
</td>
<td>
<p>OFF</p>
</td>
<td>
<p>ON</p>
</td>
<td>
<p>ON</p>
</td>
<td>
<p>ON</p>
</td>
<td>
<p>NoUSE</p>
</td>
</tr>
<tr>
<td>
<p>CH340 connect to ESP8266 (connect)</p>
</td>
<td>
<p>OFF</p>
</td>
<td>
<p>OFF</p>
</td>
<td>
<p>OFF</p>
</td>
<td>
<p>OFF</p>
</td>
<td>
<p>ON</p>
</td>
<td>
<p>ON</p>
</td>
<td>
<p>OFF</p>
</td>
<td>
<p>NoUSE</p>
</td>
</tr>
<tr>
<td>
<p>CH340 connect to ATmega328 (upload sketch)</p>
</td>
<td>
<p>OFF</p>
</td>
<td>
<p>OFF</p>
</td>
<td>
<p>ON</p>
</td>
<td>
<p>ON</p>
</td>
<td>
<p>OFF</p>
</td>
<td>
<p>OFF</p>
</td>
<td>
<p>OFF</p>
</td>
<td>
<p>NoUSE</p>
</td>
</tr>
<tr>
<td>
<p>Mega328+ESP8266</p>
</td>
<td>
<p>ON</p>
</td>
<td>
<p>ON</p>
</td>
<td>
<p>OFF</p>
</td>
<td>
<p>OFF</p>
</td>
<td>
<p>OFF</p>
</td>
<td>
<p>OFF</p>
</td>
<td>
<p>OFF</p>
</td>
<td>
<p>NoUSE</p>
</td>
</tr>
<tr>
<td>
<p>All modules work independent</p>
</td>
<td>
<p>OFF</p>
</td>
<td>
<p>OFF</p>
</td>
<td>
<p>OFF</p>
</td>
<td>
<p>OFF</p>
</td>
<td>
<p>OFF</p>
</td>
<td>
<p>OFF</p>
</td>
<td>
<p>OFF</p>
</td>
<td>
<p>NoUSE</p>
</td>
</tr>
</tbody>
</table>

<br />

## Note: 
Download and install ESP & Blynk libraries to your Arduino IDE its very important before programming (Search on YouTube you can find easily).

## Step 1:
- Before uploading the sketch you will need to activate the deep switches 5, 6, 7.
- Open ESP8266_Serial sketch file in Arduino IDE.
- Enter your WiFi details on line 35, 36.
- Select Arduino IDE --> Tools --> Board: --> Generic ESP8266 Module.
- Hit upload, the green led blinks till it gets uploaded.

## Step 2:
- Before uploading the sketch you will need to activate the deep switches 3, 4.
- Open Blynk_SoftwareSerialTest sketch file in Arduino IDE.
- Replace with your Auth Token in the Blynk App on line 34. 
  You should get Auth Token in the Blynk App.
  Go to the Project Settings (nut icon).
- Select Arduino IDE --> Tools --> Board: --> Arduino Uno.
- Hit upload, the green led blinks till it gets uploaded.




## Step 3:
After Uploading Sketches on both modules. Connect those pins as shown in the diagram. <br />

ESP8266:-------------- >Arduino: <br />

RXD -------------------------- 11 Pin <br />

TXD -------------------------- 10 Pin <br />


<img src="https://user-images.githubusercontent.com/23693439/118506781-0dfa4a80-b747-11eb-80cf-364dffe105fc.png" alt="" style="display: block; margin-left: auto; margin-right: auto; width: 50%;">

<br />

## Step 4:
- To communicate between Arduino and ESP you will need to activate deep switches 1 and 2.


Now you are all done.  <br />
Open Blynk App and check it is connected and ready use. <br />

That's it, you are done!!!  <br />


<br>


_________________________________________
#### Creating and maintaining project consume a lot of time and effort, if you would like to share your appreciation, feel free to "Star".

