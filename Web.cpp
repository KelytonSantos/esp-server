#include "Web.hpp"
 
Web::Web(WebServer &server):serv(server){
}

void Web::handleRoot(){
	String htmlContent = "<!DOCTYPE html><html><head><title>ESP Web Server</title></head><body>";
	htmlContent += "<h1>Hello from ESP8266!</h1>";
	htmlContent += "<p>This is a sample web page served from an ESP8266.</p>";
	htmlContent += "</body></html>";
	serv.send(200, "text/html", htmlContent); // Envie a resposta para o cliente

}

Web::~Web(){
}