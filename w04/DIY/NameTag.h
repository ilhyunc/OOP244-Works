#ifndef SDDS_NAMETAG_H
#define SDDS_NAMETAG_H

namespace sdds {
	class NameTag
	{
		char* m_name;		// dynamically hold name, print >= 20 spaces, <= 40 chars
		int m_extensionNum; // 5 digit, if not provided, it's N/A
		void setEmpty();
		void deallocate();

	public:
		NameTag();
		~NameTag();
		NameTag(const char* name);
		NameTag(const char* name, int c);
		void set(const char* name, int eNumber);
		void print();
		NameTag& read();
		bool isEmpty();
	};
}

#endif // !SDDS_NAMETAG_H