#ifndef __TASK_H__
#define __TASK_H__

#include "item.h"
#include "cvector.h"
using namespace std;

class Task;

using SubtaskList = CVector<Task*>;

class Task : public Item {
private:
    B completed;
    SubtaskList subtasks;

public:
    Task(const string& title, Priority priority = 2);
    ~Task() override;

    void markComplete();
    void addSubtask(Task* subtask);
    I getSubtaskCount() const;

    ItemType getType() const override;
    B isComplete() const override;
    string toString() const override;

    I countSubtasks() const;

private:
    string toStringHelper(I level) const;
};

#endif //__TASK_H__