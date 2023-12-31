## IoT Temperature and Humidity Monitoring Endpoint

An Arduino IoT endpoint for monitoring temperature and humidity using a DHT22 sensor. It provides real-time data over an Ethernet connection, making it suitable for IoT applications that require environmental monitoring.

### Features:
- Ethernet Connectivity: The sketch establishes an Ethernet connection, allowing remote access to sensor data.
- DHT22 Sensor: It integrates the DHT22 sensor to measure temperature and humidity accurately.
- HTTP Server: The endpoint responds to HTTP requests and provides data in JSON format.
- Continuous Monitoring: The Arduino continuously reads sensor data and responds to incoming requests.

### Usage:
1. Connect a DHT22 sensor to pin 2 on the Arduino Mega.
2. Ensure you have the required libraries (Ethernet and DHT) installed in your Arduino IDE.
3. Upload this sketch to your Arduino Mega.
4. Access the temperature and humidity data by making HTTP GET requests to the Arduino's IP address.
