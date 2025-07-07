#include "Task.hpp"

Task::Task(const std::string &desc) : description(desc), head(nullptr) {}

Task::~Task() { clear(); }
Task::Task() : description(""), head(nullptr) {}

void Task::add_subtask(const Subtask &subtask) {
  SubtaskNode *newNode = new SubtaskNode(subtask);

  if (head == nullptr || head->data.get_priority() < subtask.get_priority()) {
    newNode->next = head;
    head = newNode;
  } else {
    SubtaskNode *curr = head;
    while (curr->next != nullptr && curr->next->data.get_priority()) {
      curr = curr->next;
    }
    newNode->next = curr->next;
    curr->next = newNode;
  }
}
void Task::complete_subtask(unsigned int index) {
  SubtaskNode *curr = head;
  unsigned int i = 0;
  while (curr->next != nullptr && i < index) {
    i++;
    curr = curr->next;
  }
  if (curr != nullptr) {
    curr->data.mark_completed();
  }
}

bool Task::is_completed() const {
  SubtaskNode *curr = head;
  while (curr->next != nullptr) {
    if (curr->next->data.is_completed() == false) {
      return false;
    }
    curr = curr->next;
  }
  return true;
}
void Task::clear() {
  while (head != nullptr) {
    SubtaskNode *temp = head;
    head = head->next;
    delete temp;
  }
}
void Task::print() const {
  if (head == nullptr) {
    std::cout << "[" << " " << "]" << ", " << description << std::endl;
    return;
  }
  std::cout << "[" << (is_completed() ? "X" : " ") << "]" << ", " << description
            << std::endl;
  SubtaskNode *curr = head;
  while (curr) {
    std::cout << "- ";
    curr->data.print();
    curr = curr->next;
  }
}

Task::Task(const Task &other) : description(other.description) {
  head = nullptr;
  SubtaskNode *curr = other.head;
  SubtaskNode *last = nullptr;
  while (curr) {
    SubtaskNode *NewNode = new SubtaskNode(curr->data);
    if (last == nullptr) {
      head = NewNode;
    } else {
      last->next = NewNode;
    }
    last = NewNode;
    curr = curr->next;
  }
}

Task &Task::operator=(const Task &other) {
  if (this == &other)
    return *this;
  clear();
  description = other.description;
  head = nullptr;
  SubtaskNode *curr = other.head;
  SubtaskNode *last = nullptr;
  while (curr) {
    SubtaskNode *NewNode = new SubtaskNode(curr->data);
    if (last == nullptr) {
      head = NewNode;
    } else {
      last->next = NewNode;
    }
    last = NewNode;
    curr = curr->next;
  }
  return *this;
}

Task::Task(Task &&other)
    : description(std::move(other.description)), head(other.head) {
  other.head = nullptr;
}

// Operator przenoszenia
Task &Task::operator=(Task &&other) {
  if (this != &other) {
    clear(); // Zwolnij aktualne zasoby

    description = std::move(other.description);
    head = other.head;

    other.head = nullptr; // Unieważnij stan źródła
  }
  return *this;
}
