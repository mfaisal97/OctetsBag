#pragma once
typedef unsigned __int8 CountType;

class OctetBag
{
private:
	CountType * Data;
	unsigned __int8 MaxElement;

public:
	OctetBag();
	OctetBag(const OctetBag &);
	OctetBag(unsigned __int8);
	~OctetBag();

	void Add(unsigned __int8);
	void Remove(const unsigned __int8);
	bool HasElement(const unsigned __int8) const;
	CountType HasCount(const unsigned __int8) const;
	void PrintElements();
};

