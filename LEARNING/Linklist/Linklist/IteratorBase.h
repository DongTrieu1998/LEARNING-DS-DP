#pragma once

template<typename T>
class IteratorBase //Iterable
{
public:
	virtual bool hasNext() = 0;
	virtual T next() = 0;
	virtual bool hasPrev() = 0;
	virtual T prev() = 0;
};

