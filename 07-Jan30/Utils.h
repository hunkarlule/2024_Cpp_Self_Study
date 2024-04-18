#ifndef SENECA_UTILS_H
#define SENECA_UTILS_H
namespace seneca {
	const size_t MAX_DYNAMIC_READ = 24;
	struct Utils {

		size_t strlen(const char* str);
		char* strcpy(char* des, const char* src);
		char* strcpy(char* des, const char* src, size_t len);
		int getInt();
		void getCstr(char* str, size_t len);

		/// <summary>
		/// Dynamically reads from cin, str must be deleted before and after usage
		/// </summary>
		/// <param name="str">points to dynamic value enterd by the user</param>
		/// <returns>success</returns>
		bool getCstr(char*& str); 
		bool getCstr2(char*& str);
		bool yes(const char* prompt = nullptr);
	};

	// this say to client code that included "Utils.h" this:
	//  there is a external Utils variable named ut declared somewhere. you can use it!
	extern Utils ut; // prototype for ut variable inside Utils.cpp
}
#endif // ! SENECA_UTILS_H



