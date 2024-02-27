
#include <filesystem>
#include <fstream>
#include "User.h"
#include "Message.h"

// if not compile on g++ use key  -std=c++17


//  Напишите программу, которая сможет считывать из файла при своей загрузке 
// и записывать в файл состояния объектов классов User и Message (для каждого класса свой файл)


namespace fs = std::filesystem;


void show_perms(fs::perms p)
{
  std::cout << ((p & fs::perms::owner_read)   != fs::perms::none ? "r" : "-")
			<< ((p & fs::perms::owner_write)  != fs::perms::none ? "w" : "-")
			<< ((p & fs::perms::owner_exec)   != fs::perms::none ? "x" : "-")
			<< ((p & fs::perms::group_read)   != fs::perms::none ? "r" : "-")
			<< ((p & fs::perms::group_write)  != fs::perms::none ? "w" : "-")
			<< ((p & fs::perms::group_exec)   != fs::perms::none ? "x" : "-")
			<< ((p & fs::perms::others_read)  != fs::perms::none ? "r" : "-")
			<< ((p & fs::perms::others_write) != fs::perms::none ? "w" : "-")
			<< ((p & fs::perms::others_exec)  != fs::perms::none ? "x" : "-")
			<< "\n";
}

void set_perms(std::string& file_name)
{
// Установим права на файл:
	fs::permissions(file_name, fs::perms::owner_all);

	show_perms(fs::status(file_name).permissions());
}


void init_file( std::string& name)
{
	std::fstream file = std::fstream(name, std::ios::in | std::ios::out);
	if (!file) {
		file = std::fstream(name, std::ios::in | std::ios::out | std::ios::trunc);
	}
}


int main() {

	std::fstream user_file;
	std::string name_user_file = "users.txt";
	User user("Alex", "qwerty", "12345");

	std::fstream msg_file;
	std::string name_msg_file = "messages.txt";
	Message msg("telegram", "Alex", "Eustace");

	// Создаем файлы пользователя и сообщений
	init_file(name_user_file);
	init_file(name_msg_file);

	// Запись полей класса в файл
		user.write_to_file(name_user_file);
		msg.write_to_file(name_msg_file);
		
		// Для чистоты эксперимента очистим поля классов 
		user.clear_user();
		msg.clear_message();

		// Читаем файл
		user.read_from_file(name_user_file);
		msg.read_from_file(name_msg_file);
		
		// Вывод сообщений
		user.show_user();
		msg.show_message();

		// Установим права на файл
		std::cout << std::endl;
		std::cout << "Permissions for" << name_msg_file << " :" << std::endl;
		set_perms(name_msg_file);
		std::cout << std::endl;
		std::cout << "Permissions for" << name_user_file << " :" << std::endl;
		set_perms(name_user_file);


		return 0;
}

