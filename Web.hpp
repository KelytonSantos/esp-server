#ifndef _WEB_
#define _WEB_
#include <WebServer.h>

class Web{

	public:
     	Web(WebServer &server);

     	void handleRoot();
		void titlePage(const String title);
		void dispInt(unsigned value);
		void dispInt(String intName, unsigned value);
		void formXHTML(String action);
		void calc();
     	~Web();
	
	private:
		WebServer	&serv;

};

#endif 