# Elevator Simulator Xtreme
Last Updated: 2021-08-06
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

#### The Concept of Time
It's important to understand that this is a "simulation". Meaning you won't actually have to wait in a real-evelavtor to go up 100 floors. We will simulate versions of time.

For the sake of this program... 1mph in real time ~ .5ms in simulation time. (See Gloabl > ELEVATOR_MAX_SPEED for more details). 

 - Metrics are then calculated as X simulation time * 10 = ?

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
	 - Note: Elevator's Max Speed is rarely used in the real-word because of acceleration and other [physics/mathly concepts](https://www.phoenixmodularelevator.com/elevator-speed/). This field is used mainly to be used for how long the elevator should WAIT i.e. "going 1 floor up --> wait 1/1 1ms=1mph in simulation time ~ 5s." = 3mph
 - uint32 ELEVATOR_CAPACITY

##### People (Elevator Customers)
People are represented as a struct and contain the most important fields: 
 - ID
 - Floor src
 - Floor dest
 - [Metrics]added later
	 - Wait time (starts at time entered queue and ends when leaves queue)

##### Elevator
The elevator will use a queue data structure = people on the elevator. (INSIDE QUEUE)
The elevator will use another queue data structure = people on the outside of the elevator who have pressed the button. (OUTSIDE QUEUE)
The elevator will use a Min Heap (going up) and Max Heap (going down) depending if it's going UP or DOWN = it's current destinations.

The elevator will start on Floor 0. 
- The basic behavior of the elevator is: Go to the next person on the OUTSIDE QUEUE and enqueue them to the INSIDE QUEUE.
- Depending on the directon, it gets it's next destination by Min Heap or Max Heap. As the elevator passes each Floor that the Elevator travels by, it will check if this Floor's Desired Direction is the same as it's going. If yes, then allow every one on this floor onto the INSIDE QUEUE and insert into Min Heap.

So in summary:
- Variables 
	- private array of queues (each floor will get a queue)
	- private queue
	- min heap (up)
	- max heap (down)
	- bool direction
	- elevator_capacity
- Methods
	- arrive at destination
		- pick people up
		- let people off
	- go to next destination

Example 1:
1. Start on Floor 0.
2. Randomly generated: Tim (0, UP, 20). Tim gets enqueued to queue on Floor 0.
3. Enqueue Tim on Elevator. Set direction UP. Insert into MinHeap 20.
4. Starting at current Elevator position (0), for loop to current MinHeap (20). If any array value (floor) is going 1 (UP) then get the first people in that (floor) going up. (that doesn't reach capacity.)
5. Everyone who has destination 20 are left off.


Example 2:
- Start on Floor 0.
- Randomly generated: Tim (5, UP, 20) and Alice (5, DOWN, 3). Both get enqueued to queue at floor 5.
- Tim gets in first. Set direction UP. Insert into MinHeap 20. Not at capacity. Calculate that Alice is going down, therefore she does not go in, but we have a flag that states when set, we must go back to that floor. (we could just keep going up forever if people come on at the right time).
- Starting at current Elevator position (5), for loop to current Minheap (20). if any array value (floor) has people going (UP) and not at capacity then the first people in that (floor) will go up.
- 



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
