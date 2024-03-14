#include "Web.hpp"
 
Web::Web(WebServer &server):serv(server){
}

void Web::handleRoot(){
    String htmlContent = "<!DOCTYPE html><html><head><title>ESP Web Server</title>";

    // Adicionando estilos
    htmlContent += "<style>"
                  "body { background-color: #0E11E8; font-family: Arial, sans-serif; }"
                  "h1 { color: #333333; }"
                  "p { color: #666666; }"
                  "</style>";

    htmlContent += "</head><body>";
    htmlContent += "<h1>Hello from ESP8266!</h1>";
    htmlContent += "<p>This is a sample web page served from an ESP8266.</p>";
    htmlContent += "</body></html>";
    serv.send(200, "text/html", htmlContent);
}

void Web::titlePage(const String title){
	String content = "<h1>" + title + "</h1>";
    serv.send(200, "text/html", content);
}

void Web::dispInt(unsigned value){
	String content = "<body><p>" + String(value) + "</p></body></html>";
	serv.send(200, "text/html", content);
}

void Web::dispInt(String intName, unsigned value){
	String content = "<body><p>" + intName + ": " + String(value) + "</p></body></html>";
	serv.send(200, "text/html", content);
}

void Web::formXHTML(String action) {
    String content = "<p>" + action + "</p>"
                   + "<form method=\"get\" action=\"/calc""\">"
                   + "<input type=\"text\" name=\"word\"/>"
                   + "<input type=\"submit\" value=\"Enter\"/></form>";
    serv.send(200, "text/html", content);
}

void Web::calc(){
	String content = serv.arg("word");
	unsigned d = content.toInt();
	unsigned r = d*1000;
	String ret = String(r);

	String htmlContent = "<!DOCTYPE html><html><head><title>ESP Web Server</title></head><body>";
	htmlContent += "<h2>Result: " + ret + "</h2>";
	htmlContent += "</body></html>";
	serv.send(200, "text/html", htmlContent);
}

Web::~Web(){
}