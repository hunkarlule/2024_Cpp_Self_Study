#ifndef SENECA_UTILS_H
#define SENECA_UTILS_H
namespace seneca {
	struct Utils {
		int getInt();
		void getCstr(char* str, size_t len);
	};

	// this say to client code that included "Utils.h" this:
	//  there is a external Utils variable named ut declared somewhere. you can use it!
	extern Utils ut; // prototype for ut variable inside Utils.cpp
}
#endif // ! SENECA_UTILS_H



