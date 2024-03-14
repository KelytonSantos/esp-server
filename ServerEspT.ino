#include <WiFi.h>
#include <WebServer.h>
#include "Web.hpp"

const char *ssid = "MultilaserPRO_ZTE_2.4G_TDEDEd";
const char *password = "PSRMFKfR";

WebServer server(80);
Web pagi(server);

void setup() {
	Serial.begin(115200);
	WiFi.begin(ssid, password);

	while(WiFi.status() != WL_CONNECTED){
		delay(500);
		Serial.println("Conectando...");
	}
	Serial.println("Conectado a rede!");
	server.on("/", HTTP_GET, [](){
		pagi.handleRoot();
	});
	server.begin();
	Serial.println("HTTP server started");
	Serial.print("IP: ");
	Serial.println(WiFi.localIP());

}

void loop() {
	server.handleClient();

}
