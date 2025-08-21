#pragma once

template<typename I, typename R>
struct ITask{
    virtual void init()=0;
    virtual void process(I input)=0;
    virtual R end()=0;
};

template<typename T>
struct IList{
    virtual ~IList() = default;

    virtual void add(const T& item) = 0;
    virtual T& operator[](size_t index) = 0;
    virtual int size() const = 0;
    virtual void clear() = 0;
    //virtual void show() const = 0;
    //virtual template execute(ITask<T, R>* task) = 0;
    template<typename R>
    R execute(ITask<T, R>* task) {}
};

