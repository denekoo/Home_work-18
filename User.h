#pragma once
#include <string>
#include <fstream>
#include <iostream>

class User {
    std::string m_name;
    std::string m_login;
    std::string m_pass;


public:
	User(std::string name, std::string login, std::string pass) :m_name(name), m_login(login), m_pass(pass) {}
	
	void clear_user();
	void read_from_file(std::string& file_name);
	void write_to_file(std::string& file_name);

	void show_user();
};

