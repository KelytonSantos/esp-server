#ifndef _WEB_
#define _WEB_
#include <WebServer.h>

class Web{

	public:
     	Web(WebServer &server);
     	void handleRoot();
     	~Web();
	private:
		WebServer	&serv;

};

#endif 