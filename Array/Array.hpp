#include <cstdio>

template <class T>
class Array {
public:
    Array(int length) {
        list = new T[length];
        this->length = length;
        size = 0;
    }

    Array(const Array &arr) {
        this->list = new T[arr.length];
        for(int i = 0; i < arr.length; i++) {
            list[i] = arr.list[i];
        }
        this->length = arr.length;
        this->size = arr.size;
    }

    ~Array() {
        delete[] list;
    }

    Array& operator=(const Array &arr) {
        if(list != NULL) {
            delete[] list;
            list = NULL;
            length = 0;
            size = 0;
        }

        this->list = new T[arr.length];
        for(int i = 0; i < arr.length; i++) {
            list[i] = arr.list[i];
        }
        this->length = arr.length;
        this->size = arr.size;

        return *this;
    }

    T operator[](int i) {
        if(i < 0 || i >= size) {
            T temp;
            return temp;
        }
        else {
            return list[i];
        }
    }

    bool addElement(const T& element) {
        if(size >= length) return false;
        list[size] = element;
        size++;
        return true;
    }

    bool deleteElement() {
        if(size <= 0) return false;
        size--;
        return true;
    } 

    int getLength() {
        return length;
    }

    int getSize() {
        return size;
    }

private:
    T *list;
    int length;
    int size;
};