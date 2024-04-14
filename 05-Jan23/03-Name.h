#ifndef SENECA_NAME_H
#define SENECA_NAME_H
namespace seneca {
	struct Name {
	// private access modifier. The things under this
	// (member variable, member functions) are private. 
	// That menas they are only accessible inside the struct/class.
	private:
		// member variables/data
		char* m_givenName;
		char* m_surname;
		void deallocate();
		void init();

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

