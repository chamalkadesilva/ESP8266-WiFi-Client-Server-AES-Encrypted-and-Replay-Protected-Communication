# ESP8266-WiFi-Client-Server-AES-Encrypted-and-Replay-Protected-Communication
This repository contains codes for ESP8266 devices to communicate securely using AES encryption and Replay Protection mechanism. The repository is divided into two parts: a client that encrypts and sends data, and a server that receives and decrypts the data

**Features**
AES Encryption/Decryption: Secure communication using 128-bit AES.
WiFi Connectivity: Both devices connect to a WiFi network.
HTTP Communication: The client sends data over HTTP POST, while the server listens and responds to incoming HTTP requests.
Sequence Numbers: Both devices use sequence numbers to detect and avoid replay attacks.

**Dependencies**
AESLib: A library for handling AES encryption and decryption.
ESP8266WiFi: Default WiFi library for ESP8266.
ESP8266WebServer (for the server): A library to create a web server using the ESP8266.
ESP8266HTTPClient (for the client): A library to make HTTP requests from the ESP8266.

**Setup**
Clone this repository:

Navigate to the client or server directory, based on which device you're setting up.

Replace the placeholders SSIDNAME and PASSWORD with your WiFi credentials.

For the client, also update the serverName variable to point to the server's API endpoint.

Install the necessary libraries (mentioned in Dependencies) through Arduino IDE or PlatformIO.

Upload the respective code to the ESP8266 device.

**Client**
The client encrypts a simple command ("Turn On Light") with a sequence number using AES encryption and sends it to the specified server over HTTP.

**Usage:**
Once running on the ESP8266, it will attempt to connect to the WiFi network. Upon a successful connection, it will send encrypted data to the server every 5 seconds.

**Possible Improvements:**

Error handling for failed HTTP requests.
External configuration methods for server address, SSID, and password.
Enhanced encryption methodologies.

**Server**
The server listens for encrypted data from the client. Upon receiving, it decrypts the data, processes the message (which typically consists of a sequence number and a command), and then responds to the client.

**Usage:**
After uploading to the ESP8266, it will connect to the specified WiFi network. Once connected, it will start listening for incoming HTTP POST requests on the "/api" endpoint. Monitor the Serial output for processed commands and possible replay attacks.

**Possible Improvements:**

Expand the set of processable commands.
External configuration methods for credentials and AES key.
Periodic or dynamic IV updates.

**License**
MIT License. Feel free to use, modify, and distribute as you see fit. However, please give appropriate credit.
