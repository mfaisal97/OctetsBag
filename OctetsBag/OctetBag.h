#pragma once
typedef unsigned __int8 CountType;

class OctetBag
{
private:
	CountType * Data;
	const unsigned __int8 MaxElement;

public:
	OctetBag();
	OctetBag(const OctetBag &);
	OctetBag(int);
	~OctetBag();

	void Insert(int);
	void Remove(const int);
	bool HasElement(const int) const;
	CountType HasCount(const int) const;
	void PrintElements();
};

