#include "OctetBag.h"
#include <iostream>

OctetBag::OctetBag(unsigned __int8 FirstElement) : MaxElement(FirstElement)
{
	Data = new CountType[MaxElement + 1];
	for (unsigned __int8 i = 0; i < MaxElement; i++)
		Data[i] = 0;

	Data[MaxElement] = 1;
}

OctetBag::OctetBag():MaxElement(0)
{
	Data = new CountType[MaxElement + 1];
	Data[MaxElement] = 0;
}

OctetBag::OctetBag(const OctetBag & ToBeCopied)
{
	MaxElement = ToBeCopied.MaxElement;
	Data = new CountType[MaxElement + 1];
	for (unsigned __int8 i = 0; i <= MaxElement; i++) {
		Data[i] = ToBeCopied.Data[i];
	}
}


OctetBag::~OctetBag()
{
	delete[] Data;
}

void OctetBag::Add(unsigned __int8 element)
{
	if (element > MaxElement) {
		CountType* NewData = new CountType[element + 1];
		unsigned __int8 i;
		for (i = 0; i <= MaxElement; i++) {
			NewData[i] = Data[i];
		}
		for (i; i < element; i++) {
			NewData[i] = 0;
		}
		NewData[element] = 1;

		delete[] Data;
		Data = NewData;
	}
	else
	{
		Data[element] += 1;
	}
}

void OctetBag::Remove(const unsigned __int8 element)
{
	if (element <= MaxElement) {
		if (Data[element] > 0) {
			Data[element] -= 1;
		}
	}
}

bool OctetBag::HasElement(const unsigned __int8 element) const
{
	return (MaxElement >= element) && (Data[element] != 0);
}

CountType OctetBag::HasCount(const unsigned __int8 element) const
{
	if (MaxElement >= element) {
		return Data[element];
	}
	else
	{
		return 0;
	}
	
}

void OctetBag::PrintElements()
{
	for (unsigned __int8 i = 0; i <= MaxElement; i++) {
		for (CountType j = 0; j < Data[i]; j++) {
			std::cout << i << "\t";
		}
	}
	std::cout << "\n";
}
