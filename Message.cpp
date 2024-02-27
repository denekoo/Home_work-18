#include "Message.h"

void Message::show_message()
{
	std::cout << "Text message:      " << m_text     << std::endl;
	std::cout << "Message sender:    " << m_sender   << std::endl;
	std::cout << "Message receiver : " << m_receiver << std::endl;
}
void Message::clear_message()
{
	m_text = "";
	m_sender = "";
	m_receiver = "";
}


void Message::read_from_file(std::string& file_name)
{
	std::ifstream file(file_name, std::ios::in | std::ios::binary);
	if (file.is_open())
	{
		std::getline(file, m_text, '\0');
		std::getline(file, m_sender, '\0');
		std::getline(file, m_receiver, '\0');
		file.close();
	}
	else
	{
		std::cout << "Could not open file!" << std::endl;
	}
}

void Message::write_to_file(std::string& file_name)
{
	std::ofstream file(file_name, std::ios::out | std::ios::binary | std::ios::trunc);
	if (file.is_open())
	{
		file.write(m_text.data(), m_text.size());
		file.put('\0');

		file.write(m_sender.data(), m_sender.size());
		file.put('\0');

		file.write(m_receiver.data(), m_receiver.size());
		file.put('\0');

		file.close();
	}
	else
	{
		std::cout << "Could not open file to write!" << std::endl;
	}

}