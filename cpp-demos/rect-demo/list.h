#pragma once

template<typename T>
struct IList{
    virtual ~IList() = default;

    virtual void add(const T& item) = 0;
    virtual T& operator[](size_t index) = 0;
    virtual int size() const = 0;
    virtual void clear() = 0;
    virtual void show() const = 0;
};

