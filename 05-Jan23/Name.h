#ifndef SENECA_NAME_H
#define SENECA_NAME_H
namespace seneca {
	//we can repalce struct keyword with class like this: struct Name {
	// that will work and exactly same. However, there is one difference 
	// between struct and class in C++:
	// In struct: Everything is default 'public'. So to make anything private 
	// we need to put them under 'private' asccess modifier.
	// In class: Everything is default 'private'. So to make anything public 
	// we need to put them under 'public' asccess modifier.
	struct Name {
	// private access modifier. The things under this
	// (member variable, member functions) are private. 
	// That menas they are only accessible inside the struct/class.
	private:
		// member variables/data
		char* m_givenName;
		char* m_surname;
		void deallocate();
		//void init(); // no need for this one. we will be doing same thing in constructor.

	// public access modifier. The things under this
	// (member variable, member functions) are public. 
	// That menas they can be accessed outdide of class directly.
	public:
		// these are special member functions ( even call them procedures)
		// they are called automatically when an object created or died
		// we do not call them manually!

		Name(); // construction - constructor
		~Name();// desteruction - destructor
		// all member-variables/attributes are visible/reachable in
		// member functions.
		
		void set(const char* name, const char* surname);
		void read();
		void print() const;
		//void finalize(); // no need anymore because we are using destructor.
		size_t length() const;


	};
}
#endif //SENECA_NAME_H

