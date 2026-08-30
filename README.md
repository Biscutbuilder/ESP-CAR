# ESP-CAR


## About
This project will be a rover/car that will be controlled with ESP-NOW (hence the name). One ESP32 will act as a controller, sending inputs from various sensors to the Car, which will have another ESP32 to execute those inputs as commands. This vehicle thingy will use 3 mechanical systems that are used inside of real cars today, those are a differential and a rack and pinion, and finally, 4 belt drives. The differential is for the rear wheels and the rack and pinion is for steering in the front wheels. The belt drives are to lower the wheels down to create ground clearance for the body.

## Electronic part break down + BOM info
The contontroller will have 1 linear potentiometer to control the throttle of the BLDC motor and one joystick to control the steering, and a breadboard to connect everything.The car/rover will also have 1 ESP32 and a breadboard, a ESC and a BLDC motor with a Lipo battery.
Here is a more in-depth explanation for each part:
The 2 breadboards are to help connect everything together, as a PCB would be very impractical due to the distances some components need to go compared to where the microcontroller will be, like the BLDC motor will be fairly far from the ESP32 and its just impractical to have a PCB.
The joystick is to control the steering of the car/rover, I chose a joystick because of its ease of use and its more practical to use compared to a potentiometer for left and right motion.
The linear potentiometer is to control the throttle of the BLDC motor, I choose a linear potentiometer and not a rotary one because of one complex reason, I wanted the controller to be able to be used by anyone without having to ask many questions. So I thought a linear potentiometer would be more suitable than a rotary one because when looking at it, you can see that it moves up and down which you can easily correlate to the car moving forward, and having a rotary pot would be more difficult for someone to correlate rapidly.
I choose a BLDC motor and ESC kit because online I could only find a few videos on how to use a BLDC motor with microcontrollers, and they all seem to use the exact same kit with a specific BLDC motor and ESC set.
The connectors for the Lipo battery to the ESC are because most Lipo batteries do not share the same type of connector as the ESC in the kit listed above, so that's what lead me to adding connectors.
Wires are needed because I kinda have to connect everything together :/
Finally, 2 ESP32's because this entire project is supposed to use ESP-NOW to run. Its also supposed to be a example of why ESPNOW should be developed more to increase its range to allow for more probes and other projects. Instead of using other alternatives such as Radio which doesn't always work and cost more than 2 ESP32's.
The BOM is in BOM.csv
Rubber Bands for the Belt drive, but I have rubber bands, they are still in the BOM but have a needed quantiy of ZERO
I do NOT need a Lipo battery!! I already have one, it is still listen in the bom with a quantity of 0!!!!!

## Mechanical Systems
The Car will use the following mechanical systems and parts, just like a real car. A differential and a rack and pinion for steering of the car. Below is a image of the differential housing that will contain 3 bevel gears.
<img width="504" height="432" alt="image" text-align="Center" src="https://github.com/user-attachments/assets/3bec2503-2a95-4092-a381-63aefb0a602e" />
Here is a picture of the midsection of the car/rover. There is a easter egg that is visible on model, try to find its meaning!
<img width="653" height="428" alt="Screenshot 2026-08-30 113022" src="https://github.com/user-attachments/assets/c05e9522-de55-4db7-b546-10762c4df52b" />







## Software used and credits
CAD - Onshape
Coding - Arduino IDE and Visual Studio (I need the coding time!!!)
Shopping - Aliexpress and Amazon.

Websites and videos used:

The biggest thanks go to Stardance and Hackclub, for supporting this project, and to the Stardance and Hackclub staff, that might be reading this right now. None of this would be possible without you guys, Love you :)

I used [How to make a bevel gear](youtube.com/watch?v=eZJXjRCpf1w&time_continue=2&source_ve_path=MjM4NTE&embeds_referring_euri=https%3A%2F%2Fwww.google.com%2Fsearch%3Fq%3Dbevel%2Bgear%2Bin%2Bonsahep%2Bturtorial%26rlz%3D1C1CHBD_enUS1045US1046%26oq%3Dbevel%26gs_lcrp%3DEgZjaHJvbWUqBggAEEUY) to learn how to make a bevel gear inside of Onshape

I used [How does a differential work](https://www.youtube.com/watch?v=nC6fsNXdcMQ) to learn how a differential works.
Big thanks to Ogbugbo technologies youtube channel for their video [ESP NOW Joystick Controlled Servo Transmitter & Receiver Project](http://youtube.com/watch?v=0NG6z2Ef6p0). I used this video to help me learn and code ESP-NOW with a joystick and servos, I re-did some of the code to meet my projects needs.

Another thank you to INOVATRIX's video [How to use Linear Potentiometer with Arduino and control a Servo Motor](https://www.youtube.com/watch?v=TRxRAwCIGew). I used the video to help me use a linear potentiometer in my code that I then integrated with my ESP-NOW code, Intergrated of using a servo like in the video, a BLDC motor will be used.
