//
// Created by user on 15.05.2020.
//

#ifndef INCLUDE_POINTERS_SCOPED_PTR_H_
#define INCLUDE_POINTERS_SCOPED_PTR_H_


template<typename T>
class scoped_ptr {
    T *ptr_ = nullptr;

public:
    typedef T element_type;// просто оставьте это здесь.

    explicit scoped_ptr(T *ptr = nullptr) : ptr_(ptr) {}// явный конструктор для оборачивания указателя

    scoped_ptr(const scoped_ptr &scopedPtr) = delete;// удалите конструктор копирования

    scoped_ptr(scoped_ptr &&scopedPtr) = delete;// удалите конструктор перемещения

    virtual ~scoped_ptr() { delete ptr_; }// деструктор

    T *get() const { return ptr_; }// метод get чтобы взять указатель

    scoped_ptr &operator=(scoped_ptr ptr) = delete;

    T *operator->() const { return ptr_; }// оператор -> чтобы взять указатель.

    T operator*() const { return *ptr_; }// оператор * разыменования указателя и получения ссылки на объект T


    void reset(T *ptr = nullptr) {
        ptr_ = ptr;// метод reset для очистки или замены указателя
    }

    T *release() { return ptr_; }// метод release чтобы отдать сырой указатель, НО НЕ УДАЛЯТЬ его

    // это оператор, чтобы можно было писать if (sptr) { ... }.
    explicit operator bool() const { return ptr_ != nullptr; }
};

#endif//INCLUDE_POINTERS_SCOPED_PTR_H_