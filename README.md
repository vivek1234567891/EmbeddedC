# EmbeddedC
## CASE STUDY: SEAT TEMPERATURE CONTROL USING AVR PROGRAMMING(Atmegha 328)
The task is divied into 3 Activityes.
- Activity 1
- Activity 2
- Activity 3
 
# Badges


## Activity 1
As soon the person enter the car once he sit and start the car that person will get the some set of instruction ehich is display on the LCD screen. Onces they sit the switch is close and is connected to the LED which indicated that person is seated and in case that person is get out of car that will notificated by the LCD screen.
| Input | Descriptions | Port pin used |     
| ------ | ------ | ------ |
| Normal switch 01 | when the person occupies the seat inside the car switch will close | D7 |
| LED ON |Switch that gets closed when the person turns ON   | B0 |

## Activity 2
After the person is sit inside the car and switch on the heater it is done by using another switch and also if the heater is on or not is indicated by the LED and also on LCD screen.
| Input | Descriptions | Port pin used |     
| ------ | ------ | ------ |
| Normal switch 02 | when the person occupies the seat inside the car and switch on the heater| D1 |
| LED ON |Switch that gets closed when the person turns ON the heater  | D0 |
|Temperature sensor|Temperature sensor to set the seat temperature by the user|C0|
## Activity 3
Onces the temperatur is tuned by the person by generate PWM pulse with varying duty cycle based on the temperature value set by the user.
| Input | Descriptions | Port pin used |     
| ------ | ------ | ------ |
| Oscilloscope | Oscilloscope to view the PWM pulse corresponding to temperature value | B1 |

# Simulation
![Power supply is On](https://user-images.githubusercontent.com/89660364/133598753-9c63ef40-5bb7-4f60-8b07-fa013ef96c07.png)
