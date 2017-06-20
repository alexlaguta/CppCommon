/*!
    \file stack.inl
    \brief Intrusive stack container inline implementation
    \author Ivan Shynkarenka
    \date 20.06.2017
    \copyright MIT License
*/

namespace CppCommon {

template <typename T>
inline size_t Stack<T>::size() const noexcept
{
    size_t size = 0;
    for (T* node = _top; node != nullptr; node = node->next)
        ++size;
    return size;
}

template <typename T>
inline StackIterator<T> Stack<T>::begin() noexcept
{
    return StackIterator<T>(_top);
}

template <typename T>
inline StackConstIterator<T> Stack<T>::begin() const noexcept
{
    return StackConstIterator<T>(_top);
}

template <typename T>
inline StackIterator<T> Stack<T>::end() noexcept
{
    return StackIterator<T>(nullptr);
}

template <typename T>
inline StackConstIterator<T> Stack<T>::end() const noexcept
{
    return StackConstIterator<T>(nullptr);
}

template <typename T>
inline Stack<T>& Stack<T>::Push(T& item) noexcept
{
    item.next = _top;
    _top = &item;
    return *this;
}

template <typename T>
inline T* Stack<T>::Pop() noexcept
{
    if (_top == nullptr)
        return nullptr;

    T* result = _top;
    _top = result->next;
    result->next = nullptr;
    return result;
}

template <typename T>
inline void Stack<T>::Reverse() noexcept
{
    T* current = _top;
    T* prev = nullptr;
    T* next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    _top = prev;
}

template <typename T>
inline void Stack<T>::swap(Stack& stack) noexcept
{
    using std::swap;
    swap(_top, stack._top);
}

template <typename T>
inline void swap(Stack<T>& stack1, Stack<T>& stack2) noexcept
{
    stack1.swap(stack2);
}

template <typename T>
StackIterator<T>& StackIterator<T>::operator++() noexcept
{
    if (_current != nullptr)
        _current = _current->next;
    return *this;
}

template <typename T>
inline StackIterator<T> StackIterator<T>::operator++(int) noexcept
{
    StackIterator<T> result(*this);
    operator++();
    return result;
}

template <typename T>
T& StackIterator<T>::operator*() noexcept
{
    assert((_current != nullptr) && "Iterator must be valid!");

    return *_current;
}

template <typename T>
T* StackIterator<T>::operator->() noexcept
{
    return _current;
}

template <typename T>
void StackIterator<T>::swap(StackIterator& it) noexcept
{
    using std::swap;
    swap(_current, it._current);
}

template <typename T>
void swap(StackIterator<T>& it1, StackIterator<T>& it2) noexcept
{
    it1.swap(it2);
}

template <typename T>
StackConstIterator<T>& StackConstIterator<T>::operator++() noexcept
{
    if (_current != nullptr)
        _current = _current->next;
    return *this;
}

template <typename T>
inline StackConstIterator<T> StackConstIterator<T>::operator++(int) noexcept
{
    StackConstIterator<T> result(*this);
    operator++();
    return result;
}

template <typename T>
const T& StackConstIterator<T>::operator*() const noexcept
{
    assert((_current != nullptr) && "Iterator must be valid!");

    return *_current;
}

template <typename T>
const T* StackConstIterator<T>::operator->() const noexcept
{
    return _current;
}

template <typename T>
void StackConstIterator<T>::swap(StackConstIterator& it) noexcept
{
    using std::swap;
    swap(_current, it._current);
}

template <typename T>
void swap(StackConstIterator<T>& it1, StackConstIterator<T>& it2) noexcept
{
    it1.swap(it2);
}

} // namespace CppCommon