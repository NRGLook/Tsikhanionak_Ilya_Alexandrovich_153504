#pragma once

#ifndef PAIR_H
#define PAIR_H

#include <iostream>

template<typename T1, typename T2>
class pair;

template<size_t I>
struct pair_get;

template<>
struct pair_get<0> {
    template<typename T1, typename T2>
    static constexpr T1&
        get(pair<T1, T2>& pair_) noexcept {
        return pair_.first;
    }

    template<typename T1, typename T2>
    static constexpr T1&
        get(pair<T1, T2>&& pair_) noexcept {
        return std::forward(pair_.first);
    }
};

template<>
struct pair_get<1> {
    template<typename T1, typename T2>
    static constexpr T2&
        get(pair<T1, T2>& pair_) noexcept {
        return pair_.second;
    }

    template<typename T1, typename T2>
    static constexpr T2&
        get(pair<T1, T2>&& pair_) noexcept {
        return std::forward(pair_.second);
    }
};

template<typename T1, typename T2>
pair<T1, T2> make_pair(T1&& val1, T2&& val2) {

    return pair<T1, T2>(std::forward<T1>(val1), std::forward<T2>(val2));
}

template<typename T1, typename T2>
class pair {
public:
    T1 first = T1();
    T2 second = T2();

    pair() = default;

    pair(const pair<T1, T2> &rhs) : first(rhs.first), second(rhs.second) {}

    pair(const pair<T1, T2> &&rhs) noexcept
        : first(std::move(rhs.first)), second(std::move(rhs.second)) {}

    pair(T1 &&first_, T2 &&second_) : first(std::move(first_)), second(std::move(second_)) {}

    pair(T1& first_, T2& second_) : first(first_), second(second_) {}

    void swap(pair& other) noexcept {

        std::swap(first, other.first);
        std::swap(second, other.second);
    }

    void swap(const pair& other) noexcept {
        std::swap(*this, other);
    }

    pair& operator= (const pair& rhs) {

        first = rhs.first;
        second = rhs.second;

        return *this;
    }

    pair& operator= (const pair&& rhs) noexcept {

        first = std::move(rhs.first);
        second = std::move(rhs.second);

        return *this;
    }

    template <class U1, class U2>
    pair& operator= (const pair<U1, U2>&& rhs) noexcept {

        first = std::move(static_cast<T1>(rhs.first));
        second = std::move(static_cast<T2>(rhs.second));

        return *this;
    }

    template<class U1, class U2>
    constexpr bool operator== (const pair<U1, U2>& rhs) {
        return first == rhs.first ? second == rhs.second : false;
    }

    template<class U1, class U2>
    constexpr bool operator!= (const pair<U1, U2>& rhs) {
        return (first != rhs.first) && (second != rhs.second);
    }

    template<class U1, class U2>
    constexpr bool operator< (const pair<U1, U2>& rhs) {
        return first == rhs.first ?
            second < rhs.second :
            first < rhs.first;
    }

    template<class U1, class U2>
    constexpr bool operator> (const pair<U1, U2>& rhs) {
        return first == rhs.first ?
            second > rhs.second :
            first > rhs.first;
    }

    template<class U1, class U2>
    constexpr bool operator>= (const pair<U1, U2>& rhs) {
        return first == rhs.first ?
            second >= rhs.second :
        first >= rhs.first;
    }

    template<class U1, class U2>
    constexpr bool operator<= (const pair<U1, U2>& rhs) {
        return first == rhs.first ?
            second <= rhs.second :
            first <= rhs.first;
    }


    ~pair() = default;

    friend std::ostream& operator<<(std::ostream& out, const pair<T1, T2>& rhs) {

        out << rhs.first << ' ' << rhs.second;

        return out;
    }

    friend std::istream& operator>>(std::istream& in, pair<T1, T2>& rhs) {

        in >> rhs.first >> rhs.second;

        return in;
    }
};

template <class T, class U>
constexpr T& get(pair<T, U>& p) noexcept {

    return p.first;
}

template <class T, class U>
constexpr T&& get(pair<T, U>&& p) noexcept {

    return std::forward(p.first);
}


template <class T, class U>
constexpr T& get(pair<U, T>& p) noexcept {

    return p.second;
}

template <class T, class U>
constexpr T&& get(pair<U, T>&& p) noexcept {

    return std::forward(p.second);
}

template<size_t I, class T>
struct tuple_element {};

template<class T1, class T2>
struct tuple_element<0, pair<T1, T2>> {
    typedef T1 type;
};

template<class T1, class T2>
struct tuple_element<1, pair<T1, T2>> {
    typedef T2 type;
};

template<size_t I, class T1, class T2>
constexpr typename tuple_element<I, pair<T1, T2>>::type&
get(pair<T1, T2>& pair_) noexcept {
    return pair_get<I>::get(pair_);
}

template<size_t I, class T1, class T2>
constexpr typename tuple_element<I, pair<T1, T2>>::type&
get(pair<T1, T2>&& pair_) noexcept {
    return pair_get<I>::get(std::move(pair_));
}

#endif // PAIR_H
