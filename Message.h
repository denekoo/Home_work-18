#pragma once
#include <string>
#include <fstream>
#include <iostream>


class Message {
   std::string m_text;
   std::string m_sender;
   std::string m_receiver;
   
public:	  
	 Message(std::string text, std::string sender, std::string receiver) :m_text(text), m_sender(sender), m_receiver(receiver) {}

	 void clear_message();
	 void read_from_file(std::string& file_name);
	 void write_to_file(std::string& file_name);
	 void show_message();
};

