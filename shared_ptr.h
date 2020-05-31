//
// Created by user on 18.05.2020.
//

#ifndef INCLUDE_POINTERS_SHARED_PTR_H_
#define INCLUDE_POINTERS_SHARED_PTR_H_


template<typename T>
class shared_ptr {
    T *ptr_;    // сам сырой указатель
    int *count_;// счетчик ссылок. Скорее всего это указатель на int :)
public:
    typedef T element_type;

    explicit shared_ptr(T *ptr = nullptr) : ptr_(ptr), count_(new int{1}) {}// явный конструктор для оборачивания указателя

    shared_ptr(const shared_ptr &sharedPtr):ptr_(sharedPtr.get()),count_ (sharedPtr.count_) {
        (*count_)++;
    }// конструктор копирования, который инкрементирует счетчик ссылок  и сохраняет указатель


    shared_ptr& operator=(const shared_ptr& shared_ptr) {
        if (this != &shared_ptr) {
            ptr_ = shared_ptr.get();
            count_ = shared_ptr.count_;
            (*count_)++;
        }
        return *this;
    }

    //shared_ptr(shared_ptr &&scopedPtr) noexcept = default;// конструктор перемещения оставьте тот, который генерируется по-умолчанию


    ~shared_ptr() {
        (*count_)--;
        if ((*count_) == 0) {
            ptr_ = nullptr;
            delete ptr_;
            delete count_;
        }
    }// деструктор (уменьшает счетчик ссылок.
    //   Если видит, что счетчик ссылок == 0, то уничтожает данные и по самому указателю.

    // метод get чтобы взять указатель
    T *get() const {
        return ptr_;
    }

    int GetCount() {
        return *count_;
    }

    T *operator->() const { return ptr_; }// оператор -> чтобы взять указатель.

    T& operator*() const { return *ptr_; }// оператор * разыменования указателя и получения ссылки на объект T

    // заменяет хранимый указатель на другой
    void reset(T *other = nullptr) {
        ptr_ = other;
        (*count_)--;
        count_ = new int{1};
    }

    // метода release нет, так как он в жанном случае не имеет смысла

    // это оператор, чтобы можно было писать if (sptr) { ... }.
    explicit operator bool() const { return ptr_ != nullptr; }
};
#endif//INCLUDE_POINTERS_SHARED_PTR_H_
