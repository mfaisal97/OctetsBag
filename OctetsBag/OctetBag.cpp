#include "OctetBag.h"
#include <iostream>
#include <limits>

OctetBag::OctetBag(int FirstElement) : MaxElement(255)
{
	if (FirstElement > MaxElement || FirstElement < 0) {
		throw("Entered Element not in Range.");
	}
	Data = new CountType[MaxElement + 1];
	for (unsigned __int8 i = 0; i < MaxElement; i++)
		Data[i] = 0;
	Data[MaxElement] = 0;

	Data[FirstElement] = 1;
}

OctetBag::OctetBag():MaxElement(255)
{
	Data = new CountType[MaxElement + 1];
	for (unsigned __int8 i = 0; i < MaxElement; i++)
		Data[i] = 0;
	Data[MaxElement] = 0;
}

OctetBag::OctetBag(const OctetBag & ToBeCopied) : MaxElement(ToBeCopied.MaxElement)
{
	Data = new CountType[MaxElement + 1];
	for (unsigned __int8 i = 0; i < MaxElement; i++) {
		Data[i] = ToBeCopied.Data[i];
	}
	Data[MaxElement] = ToBeCopied.Data[MaxElement];
}


OctetBag::~OctetBag()
{
	delete[] Data;
}

void OctetBag::Insert(int element)
{
	if (element > MaxElement || element < 0) {
		throw("Entered Element not in Possible Range.");
	} else if (Data[element] == std::numeric_limits<CountType>::max()) {
		throw("Element has already reached its maximum possible count");
	}
	else
	{
		Data[element] = Data[element] + 1;
	}
}

void OctetBag::Remove(const int element)
{
	if (element <= MaxElement && element >= 0) {
		if (Data[element] > 0) {
			Data[element] -= 1;
		}
	}
}

bool OctetBag::HasElement(const int element) const
{
	return (MaxElement >= element) && (element >=0 ) && (Data[element] != 0);
}

CountType OctetBag::HasCount(const int element) const
{
	if (MaxElement >= element && (element >= 0)) {
		return Data[element];
	}
	else
	{
		return 0;
	}
}

void OctetBag::PrintElements()
{
	for (unsigned __int8 i = 0; i < MaxElement; i++) {
		for (CountType j = 0; j < Data[i]; j++) {
			std::cout << (int)i << " ";
		}
	}
	
	for (CountType j = 0; j < Data[MaxElement]; j++) {
		std::cout << (int)MaxElement << " ";
	}
	std::cout << "\n";
}
