#include "todo.h"
#include <stdexcept>

void TodoList::init() {
    // TODO: set size to 0 and all task pointers to nullptr
    size = 0;
    for(int i=0; i<MAX_TASKS; i++) {
        tasks[i] = nullptr;
    }
}

void TodoList::destroy() {
    // TODO: delete all tasks and reset pointers
    for(int i=0; i<MAX_TASKS; i++) {
        delete tasks[i];
        tasks[i] = nullptr;
    }
}

int TodoList::string_length(const char* str) const {
    // TODO: return the number of characters before '\0'
    int len = 0;
    while(1) {
        if(str[len] == '\0') {
            break;
        }
        len++;
    }
    return len;
}

void TodoList::string_copy(char* dest, const char* src) const {
    // TODO: copy characters from src to dest
    int len = string_length(src);
    for(int i=0; i<=len; i++) {
        dest[i] = src[i];
    }
}

void TodoList::add_task(const char* task) {
    // TODO: if full, throw. otherwise allocate and copy new task
    if(size >= MAX_TASKS) {
        throw std::overflow_error("TODO: is full");
    }
    int len = string_length(task);
    char* new_task = new char[len+1];
    string_copy(new_task, task);
    tasks[size] = new_task;
    size++;
}

void TodoList::remove_task(int index) {
    // TODO: check bounds, delete task, shift left
    if(index < 0 || index >= size) {
        throw std::out_of_range("Wrong bound");
    }
    delete[] tasks[index];
    for(int i=index; i<size; i++) {
        tasks[i] = tasks[i+1];
    }
    size--;
    delete[] tasks[size];
    tasks[size] = nullptr;
}

const char** TodoList::get_pending_tasks(int& count) const {
    // TODO: set count and return task array
    count = size;
    const char** new_tasks = new const char*[size];
    for(int i=0; i<size; i++) {
        new_tasks[i] = tasks[i];
    }
    return new_tasks;
}