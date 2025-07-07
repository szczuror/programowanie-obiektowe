#include "Subtask.hpp"
#include <iostream>

Subtask::Subtask(const std::string& desc, unsigned int prio, bool done)
: description(desc), priority(prio), completed(done){}


void Subtask::mark_completed(){
	completed = true;
}

bool Subtask::is_completed() const{
	return completed;
}

unsigned int Subtask::get_priority() const{
	return priority;
}
void Subtask::print() const{
	std::cout << "[" << (completed ? "X" : " ") << "]" << "P: " << priority << ", " << description << std::endl;
}


