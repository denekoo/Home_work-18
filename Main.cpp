﻿//#include <string>
#include <filesystem>
#include <fstream>
#include "User.h"
#include "Message.h"

// if not compile on g++ use key  -std=c++17

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






int main() {

	std::fstream user_file = std::fstream("users.txt", std::ios::in | std::ios::out);
	if (!user_file)
		// Для создания файла используем параметр ios::trunc
		user_file = std::fstream("users.txt", std::ios::in | std::ios::out | std::ios::trunc);

	if (user_file) {
		User obj("Alex", "qwerty", "12345");
		// Запишем данные по в файл
		user_file << obj << std::endl;
		// Чтобы считать данные из файла, надо установить позицию для чтения в начало файла
		user_file.seekg(0, std::ios_base::beg);
		// Считываем данные из файла
		user_file >> obj;
		std::cout << obj << std::endl;
	}
	else
	{
		std::cout << "Could not open file users.txt !" << '\n';
		return 0;
	}

	show_perms(fs::status("users.txt").permissions());
	// Установим права на файл:
	fs::permissions("users.txt", fs::perms::owner_all);

	show_perms(fs::status("users.txt").permissions());

}


//
//int main() {
//    User user{ "John Doe", "john", "password123" };
//    Message message{ "Hello, World!", "john", "jane" };
//
//    {
//        std::ofstream file("data.dat", std::ios::binary | std::ios::out);
//        if (file.is_open()) {
//            file.write(reinterpret_cast<const char*>(&user), sizeof(User));
//            file.write(reinterpret_cast<const char*>(&message), sizeof(Message));
//        }
//        else {
//            std::cerr << "Unable to open file for writing." << std::endl;
//            return 1;
//        }
//    }
//
//    User loadedUser;
//    Message loadedMessage;
//
//    {
//        std::ifstream file("data.dat", std::ios::binary);
//        if (file.is_open()) {
//            file.read(reinterpret_cast<char*>(&loadedUser), sizeof(User));
//            file.read(reinterpret_cast<char*>(&loadedMessage), sizeof(Message));
//        }
//        else {
//            std::cerr << "Unable to open file for reading." << std::endl;
//            return 1;
//        }
//    }
//
//    return 0;
//}

//#include <fstream>
//#include <iostream>
//#include <filesystem>
//namespace fs = std::filesystem;
//using namespace std;
//
//class User
//{
//    string _name;
//    string _login;
//    string _pass;
//
//public:
//    User(string name, string login, string pass) :_name(name), _login(login), _pass(pass) {}
//
//    friend fstream& operator >>(fstream& is, User& obj);
//    friend ostream& operator <<(ostream& os, const User& obj);
//};
//
//fstream& operator >>(fstream& is, User& obj)
//{
//    is >> obj._name;
//    is >> obj._login;
//    is >> obj._pass;
//    return is;
//}
//ostream& operator <<(ostream& os, const User& obj)
//{
//    os << obj._name;
//    os << ' ';
//    os << obj._login;
//    os << ' ';
//    os << obj._pass;
//    return os;
//}
//
//class Message
//{
//    string _text;
//    string _sender;
//    string _receiver;
//
//public:
//    Message(string text, string sender, string receiver) :_text(text), _sender(sender), _receiver(receiver) {}
//
//    friend fstream& operator >>(fstream& lup, Message& bip);
//    friend ostream& operator <<(ostream& cup, const Message& bip);
//
//};
//
//fstream& operator >>(fstream& lup, Message& bip)
//{
//    lup >> bip._text;
//    lup >> bip._sender;
//    lup >> bip._receiver;
//    return lup;
//}
//ostream& operator <<(ostream& cup, const Message& bip)
//{
//    cup << bip._text;
//    cup << ' ';
//    cup << bip._sender;
//    cup << ' ';
//    cup << bip._receiver;
//    return cup;
//}
//
//void demo_perms(fs::perms p)
//{
//    std::cout << ((p & fs::perms::owner_read) != fs::perms::none ? "r" : "-")
//        << ((p & fs::perms::owner_write) != fs::perms::none ? "w" : "-")
//        << ((p & fs::perms::owner_exec) != fs::perms::none ? "x" : "-")
//        << ((p & fs::perms::group_read) != fs::perms::none ? "r" : "-")
//        << ((p & fs::perms::group_write) != fs::perms::none ? "w" : "-")
//        << ((p & fs::perms::group_exec) != fs::perms::none ? "x" : "-")
//        << ((p & fs::perms::others_read) != fs::perms::none ? "r" : "-")
//        << ((p & fs::perms::others_write) != fs::perms::none ? "w" : "-")
//        << ((p & fs::perms::others_exec) != fs::perms::none ? "x" : "-")
//        << '\n';
//}
//
//
//int main()
//{
//    fstream user_file = fstream("users.txt", ios::in | ios::out);
//    if (!user_file)
//        // Для создания файла используем параметр ios::trunc
//        user_file = fstream("users.txt", ios::in | ios::out | ios::trunc);
//
//    if (user_file)
//    {
//        User obj("Alex", "qwerty", "12345");
//
//        demo_perms(fs::status("user.txt").permissions());
//        fs::permissions("users.txt", fs::perms::owner_write | fs::perms::others_all, fs::perm_options::remove);
//
//        // Запишем данные по в файл
//        user_file << obj << endl;
//
//        // Чтобы считать данные из файла, надо установить позицию для чтения в начало файла
//        user_file.seekg(0, ios_base::beg);
//        // Считываем данные из файла
//        user_file >> obj;
//        cout << obj << endl;
//    }
//    else
//    {
//        cout << "Could not open file users.txt !" << '\n';
//        return 0;
//    }
//
//
//    fstream user_file2 = fstream("Message.txt", ios::in | ios::out);
//    if (!user_file2)
//        // Для создания файла используем параметр ios::trunc
//        user_file2 = fstream("Message.txt", ios::in | ios::out | ios::trunc);
//
//    if (user_file2)
//    {
//        Message bip("chtoto poshlo ne tak", "Alex", "Tom");
//
//        demo_perms(fs::status("Message.txt").permissions());
//        fs::permissions("Message.txt", fs::perms::owner_write | fs::perms::owner_read, fs::perm_options::remove);
//
//        // Запишем данные по в файл
//        user_file2 << bip << endl;
//
//        // Чтобы считать данные из файла, надо установить позицию для чтения в начало файла
//        user_file2.seekg(0, ios_base::beg);
//        // Считываем данные из файла
//        user_file2 >> bip;
//        cout << bip << endl;
//    }
//    else
//    {
//        cout << "Could not open file users.txt !" << '\n';
//        return 0;
//
//    }
//
//    return 0;
//
//}