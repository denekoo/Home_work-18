#include "User.h"

void User::show_user()
{
	std::cout << "User name:     " << m_name  << std::endl;
	std::cout << "User login:    " << m_login << std::endl;
	std::cout << "User password: " << m_pass  << std::endl;
}
void User::clear_user()
{
	m_name = "";
	m_login = "";
	m_pass = "";
}



void User::read_from_file(std::string& file_name)
{
	std::ifstream file(file_name, std::ios::in | std::ios::binary);
		if(file.is_open())
		{ 
			
			std::getline(file, m_name,  '\0');
			std::getline(file, m_login, '\0');
			std::getline(file, m_pass,  '\0');
			file.close();
		}
		else
		{
			std::cout << "Could not open file!" << std::endl;
		}
}

void User::write_to_file(std::string& file_name)
{
	std::ofstream file(file_name, std::ios::out | std::ios::binary | std::ios::trunc);
	if (file.is_open())
	{
		file.write(m_name.data(), m_name.size());
		file.put('\0');

		file.write(m_login.data(), m_login.size());
		file.put('\0');

		file.write(m_pass.data(),  m_pass.size());
		file.put('\n');
		file.close();
	}
	else
	{
		std::cout << "Could not open file to write!" << std::endl;
	}
}