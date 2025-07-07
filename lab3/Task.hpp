#pragma once
#include "Subtask.hpp"

struct SubtaskNode {
    Subtask data;
    SubtaskNode* next;
    SubtaskNode(const Subtask& data) : data(data), next(nullptr) {}
};

class Task {
    private:
        std::string description;
        SubtaskNode* head;

    public:
	Task();
    Task(const std::string& desc);

    Task(const Task& other);
    Task& operator=(const Task& other);
    Task(Task&& other);
    Task& operator=(Task&& other);

    ~Task();

    void add_subtask(const Subtask& subtask);
    void complete_subtask(unsigned int index);
    bool is_completed() const;
    void clear();
    void print() const;

};
