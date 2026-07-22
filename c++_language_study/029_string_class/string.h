#pragma once

namespace my
{
	class string
	{
	public:
		string();
		string(const char*);
		string(const char*, int);
		string(const string&);
		~string();
		
		static string& convert(int);
		static int& convert(const string&);
		
		string& reverse();
		
		string& remove(const char);
		string& replace(const char, const char);

		string& removeAt(int);
		string& removeback();
		string& removefront();

		string& insert(int at, const string&);
		string& insert(int at, const char*);
		string& insert(int at, char);
		string& concat(const string&);


		string& pushback(const string&);
		string& pushback(const char*);
		string& pushback(char);

		string& pushfront(const string&);
		string& pushfront(const char*);
		string& pushfront(char);

		char at(int) const;
		char* getString() const;
		int getLength() const;
		int getBufferSize() const;
		void setString(char*);
		void setLength(int);
		void init(const char*, int);
		void delstr();
		static char* alloc(int);
		static void copy(char*, const char*, int);
		static int calcLength(const char*);
		static void settmp(char c);

	private:
		static char _tmp[2];
		char* _str;
		int _len;
	};
}