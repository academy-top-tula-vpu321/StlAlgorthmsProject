#pragma once
#include <iostream>

class User
{
	std::string name;
	int age;
public:
	User(std::string name, int age)
		: name{ name }, age{ age } {}
	User() : User("Anonim", 0) {}

	std::string& Name() { return name; }
	int& Age() { return age; }

	friend std::ostream& operator<<(std::ostream& out, User user)
	{
		out << "Name: " << user.name << ", Age: " << user.age;
		return out;
	}

	friend bool operator==(User u1, User u2)
	{
		return (u1.name == u2.name) && (u1.age == u2.age);
	}
};

