#include "task.h"
using namespace std;

Task::Task(const ST& title, Priority priority)
    : Item (title, priority), completed(false) {}

Task::~Task() {
    for (auto i = 0; i < subtasks.size(); i++) {
        delete subtasks[i];
    }
}

void Task::markComplete() { completed = true; }

void Task::addSubtask(Task* subtask) {
    subtasks.push_back(subtask);
}

I Task::getSubtaskCount() const {
    return subtasks.size();
}

ItemType Task::getType() const { return ItemType:: TASK; }

B Task::isComplete() const {
    if (!completed) return false;

    for (auto i = 0; i < subtasks.size(); i++) {
        if (!subtasks[i]->isComplete()) {
            return false;
        }
    }
    return true;
}

I Task::countSubtasks() const {
    I total = subtasks.size();

    for (auto i = 0; i < subtasks.size(); i++) {
        total += subtasks[i]->countSubtasks();
    }
    return total;
}

ST Task::toString() const {
    return toStringHelper(0);
}

ST Task::toStringHelper(I level) const {
    ST indent(level * 2, ' ');
    ST check = completed ? "[x]" : "[ ]";
    ST result = indent + check + " " + title +
                     "(prioridad " + to_string(priority) + ")\n";
    for (auto i = 0; i < subtasks.size(); i++) {
        result += subtasks[i]->toStringHelper(level + 1);
    }
    return result;
}