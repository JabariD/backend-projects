# Elevator Simulator Xtreme
Last Updated: 2021-07-17
Reviewers: N/A
**Draft** | Review | Final

**TLDR**: Elevator Simulator Xtreme is...

## How to Run
To run Elevator Simulator Xtreme follow these steps simply go to the Github webpage link located in this repo.

No additional setup required. ENJOY!

## Objective
a

## Background
Elevators are seen in hotels, malls, and so many different establishments across the globe. But... how do they work?? Without getting into the physics of the elevator, this game will give us a glimpse of the decision-making of an elevator. "Right... what decisions does an elevator have to make?" Well interesting questions arise from elevators such as...

 - If 2 people press the "Call Elevator" button at the same time who should go on the elevator first?
 - How does an Elevator take into account the destinations of everyone on the elevator?
 - Does an Elevator change behavior based on capacity or speed?
 - How fast should the elevator close it's doors and 

All these and more are answered in Elevator Simulator Xtreme.

## Overview
Elevator Simulator Xtreme is a console-only game (to focus primarily on backend, but will shift to having a frontend later) that mimics running an elevator service in a hotel. In game there are 3 modes:

The first mode is: **Watch-only**. The user is able to specify the building that the elevator operates on and other general fields (described in the Detailed Design section).   . This will be the first-mode that is created.

The second mode is: **User**. In this mode, the user has full control of the elevator and decides who goes where. 

The third mode is: **Creative**. It's unlikely that random people all have random destinations. Most times, an elevator

Similiar to a Papa's Pizzeria, Freezieria, X game, 
 

## High-level Detailed Design
### Language Choice
Based on the objective, backend design principles want to be practiced. TypeScript will be used and compiled into JavaScript (but will be treated in a OOP matter). By using TypeScript we take advantage of a seamless simple GUI (in the browser) rather than fiddling with a GUI for Java or C++ which would be normally used.

 - This is primarily used to allow us to have a better GUI to show 1) Elevator messages i.e. "Elevator arrived on Floor 2." and 2) People messages. "Person X has pressed the Elevator Button on Floor 2."

### "Watch-only" Game-Mode
This will be the first-mode that is created. 
##### User
The user will be able to specify 
 - the building capacity's size (how many floors),
 - busyness of the elevator (3 levels: 1, 2, 3), 
	 - This controls how often "People" will spawn at random floors.
- elevator speed (how long does the elevator have to wait to get to the next floor depending on how close it is)
- elevator capacity (how many people are allowed in at a time)

##### Global
Global variables will include:

 - uint32 MAX_FLOOR
 - enum BUSYNESS (LEVEL_1, LEVEL_2, LEVEL_3)
 - uint32 ELEVATOR_MAX_SPEED 
	 - Note: Elevator's Max Speed is rarely used in the real-word because of acceleration and other [physics/mathly concepts](https://www.phoenixmodularelevator.com/elevator-speed/). This field is used to 
 - uint32 ELEVATOR_CAPACITY

##### People (Elevator Customers)
People are represent as a struct and contain the most important fields: 
 - ID
 - Floor src
 - Floor dest

For metrics, People will also contain, wait_time to begin with

##### Elevator
The elevator will use it's own queue data structure to manage People nodes. 

The elevator will start on Floor 0.

### "User" Game-Mode
In this mode, the user has full control of the elevator and decides who goes where. Depending on 3 busyness (1, 2, 3) elevator customers randomly appear on different floors at a specific rate. Each customer has 

### Metrics
For each mode, metrics will be tracked and displayed at the end of each round. The metrics that are currently tracked are
 - Avg. waiting time to get from Floor X to Floor Y.

Added In time..
 - Avg. waiting time to get in elevator
 - Avg. waiting time spent in elevator
 - Shortest time in elevator.
 - Longest time in elevator.
 - 

## Alternatives Considered
a

## Testing Plan
To allow for efficient 

## Timeline
|Functionality|Time  |
|--|--|
|Design Doc  |1 SWE Week  |
|Basic Watch-only| 1 SWE Month | 
|Watch-only + more features | 2 SWE weeks

## Future Enhancements

 - **Enhanced Frontend UI**: An enchanced Frontend UI will include animations, 
