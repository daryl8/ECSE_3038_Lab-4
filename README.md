In this assignment, you'll utilize an ESP32 board to make a GET request to a server, use the response to set the LED states, and then use that information to control the states of three LEDs.Three LEDs should be connected to the ESP32 board's digital output pins. To control the current and guard against LED damage, add a resistor to each LED.

The API to access the light switch has already been constructed.
The user will be allowed to change the desired state of each of the three LEDs by using this [tester site](https://ecse-three-led.netlify.app/). The site should determine the behaviour of the user circuit by toggling each of the three light switches. 

Note the assigned username in the top left corner of the webpage. This is a unique identifier and should be included in the GET requests to the API as an API key.

This ensures that each person is able to control their own circuit.
