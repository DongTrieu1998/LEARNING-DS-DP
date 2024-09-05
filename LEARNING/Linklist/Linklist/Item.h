#pragma once
#include <string>

class Item
{
public:
	Item(std::string name): m_name(name) {}
	~Item() = default;

	std::string getName() { return m_name; }
	void setName(std::string name) { m_name = name; }

private:
	std::string m_name;
};