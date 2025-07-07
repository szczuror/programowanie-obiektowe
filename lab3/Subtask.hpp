#pragma once
#include <iostream>
#include <cstring>

class Subtask{
    private:
        std::string description;
        unsigned int priority;
        bool completed;

    public:
        Subtask(const std::string& desc, unsigned int prio = 0, bool done = false);
        void mark_completed();
        bool is_completed() const;
        unsigned int get_priority() const;
        void print() const;
};