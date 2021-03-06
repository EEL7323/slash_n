#include <user_config.h>
#include <SmingCore/SmingCore.h>

// If you want, you can define WiFi settings globally in Eclipse Environment Variables
#ifndef WIFI_SSID
	#define WIFI_SSID "admin" // Put you SSID and Password here
	#define WIFI_PWD ""
#endif

void onReceive(UdpConnection& connection, char *data, int size, IPAddress remoteIP, uint16_t remotePort); // Declaration


// UDP server
const uint16_t EchoPort = 1234;
UdpConnection udp(onReceive);


void onReceive(UdpConnection& connection, char *data, int size, IPAddress remoteIP, uint16_t remotePort)
{
	debugf("UDP Sever callback from %s:%d, %d bytes", remoteIP.toString().c_str(), remotePort, size);

	// We implement string mode server for example
	Serial.print(">\t");
	Serial.print(data);

	// Send echo to remote sender
	String text = String("echo: ") + data;
	udp.sendStringTo(remoteIP, remotePort, text);
}

void onConnected()
{
	udp.listen(EchoPort);

	Serial.println("\r\n=== UDP SERVER STARTED ===");
	Serial.print(WifiStation.getIP().toString()); Serial.print(":"); Serial.println(EchoPort);
	Serial.println("=============================\r\n");

	//udp.connect(IPAddress(192, 168, 100, 17), 500);
	//udp.sendString("Hello from ESP8266!");
}

void init()
{
	Serial.begin(SERIAL_BAUD_RATE); // 115200 by default
	Serial.systemDebugOutput(true);

	WifiStation.config(WIFI_SSID, WIFI_PWD);
	WifiStation.waitConnection(onConnected);
}
