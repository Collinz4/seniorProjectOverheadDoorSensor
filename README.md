# seniorProjectOverheadDoorSensor

This was the code for my high school senior project. It is written in Arduino's language which is similar if not identical to C++.

This code runs in a continuous loop waiting for two signals (+5 volts) on pins 2 and 3. If one of the pins recieves the signal the controller activates a set of sirens for 5 seconds and emergency lights for 30 seconds. These devices are activated on pins 31, 32, 33, and 34 via relay bank which opens a 12 volt circuit.

The most difficult part about writing the program was that I couldn't use the sleep function. This is because in the unlikely event that both sensors on each side of the door were triggered, the system would have to respond to both sides. Using the sleep function sleeps the controller and blocks all incoming signals until the sleep function is over. To fix this, I had the program check the clock timer and did simple arithmetic to see if the appropriate alarm time passed. If it did, the alarms were shut off via relay and the controller continued waiting for activity. This method also allows a user to add as many sensor and alarm sets as needed.

I worked directly with lab technicians to develop design goals for the project, presented a few designs to lab managers, and  delivered a product a few weeks later. This project allowed me to learned a lot about controllers and how to develop projects within a time frame.
