#pragma once
#include "IterableBase.h"
#include "Iterator.h"
#include "Linklist.h"

template<typename T>
class Iterable : public IterableBase
{
public:
	Iterable(Linklist<T> list): m_list(list) {}
	~Iterable() override {}
	IterableBase createIterator() override {
		return new Iterator(m_list);
	}

private:
	Linklist<T> m_list;
};
