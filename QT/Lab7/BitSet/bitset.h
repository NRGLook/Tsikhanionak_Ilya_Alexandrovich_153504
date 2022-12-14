#ifndef BITSET_H
#define BITSET_H

#include <iostream>
#include <string>

template <size_t bits>
class Bitset
{
private:
    using type = unsigned long long;
    static const size_t bits_in_byte = 8;
    static const size_t bits_in_word = bits_in_byte * sizeof(type); // means 64 beats(8*8)
    static const size_t words = (bits == 0) ? 0 : (bits - 1) / bits_in_word + 1;
    type arr[words];//create ou array

public:
    //gives us responsibility to work with EVERY bitset(alone)
    class reference
    {
    private:
        friend class Bitset<bits>;//include operrations bitset and etc.

        Bitset<bits>* bitSet;
        size_t position;

        reference() : bitSet(nullptr), position(0) {} //first position - 0

        reference(Bitset<bits>& _bitset, size_t pos) : bitSet(&_bitset), position(pos) {}

    public:
        //overloading operators(according parametrs)

        reference& operator=(bool val)
        {
            bitSet->set_bit(position, val);
            return *this;
        }

        reference& operator=(const reference& bitref)
        {
            bitSet->set_bit(position, bitref.operator bool());
            return *this;
        }

        bool operator~() const
        {
            return !bitSet->test(position);
        }

        operator bool() const
        {
            return bitSet->test(position);
        }

        reference& flip() // change 0-1 1-0
        {
            bitSet->flip(position);
            return *this;
        }
    };

    Bitset() : arr{} { }

    Bitset(unsigned long long value) : arr{ value } {}

    Bitset(const std::string& value) : arr{}
    {
        size_t count = value.size();
        if (count > bits)
            count = bits;

        size_t pos = 0;
        for (int i = count - 1; i >= 0; --i)
        {
            set_bit(pos, value[i] - '0');
            pos++;
        }
    }

    bool all() const noexcept
    {
        size_t pos = 0;
        for (int i = 0; i < bits; i++)
        {
            if ((arr[pos / bits_in_word] & (type{ 1 } << pos % bits_in_word)) == 0)
                return false;
            pos++;
        }
        return true;
    }

    //count of 1
    bool any() const noexcept
    {
        size_t pos = 0;
        for (int i = 0; i < bits; i++)
        {
            if ((arr[pos / bits_in_word] & (type{ 1 } << pos % bits_in_word)) != 0)
                return true;
            pos++;
        }
        return false;
    }

    //count of 0
    bool none() const noexcept
    {
        size_t pos = 0;
        for (int i = 0; i < bits; i++)
        {
            if ((arr[pos / bits_in_word] & (type{ 1 } << pos % bits_in_word)) != 0)
                return false;
            pos++;
        }
        return true;
    }

    //count of the same bits of bitset

    size_t count() const noexcept
    {
        size_t counter = 0;
        size_t pos = 0;
        for (int i = 0; i < bits; i++)
        {
            if ((arr[pos / bits_in_word] & (type{ 1 } << pos % bits_in_word)) != 0)
                counter++;
            pos++;
        }
        return counter;
    }

    Bitset& flip() noexcept
    {
        for (int i = 0; i < words; i++)
            arr[i] = ~arr[i];
        return *this;
    }

    Bitset& flip(size_t pos)
    {
        this->operator[](pos) = ~this->operator[](pos);
        return *this;
    }

    Bitset& reset() noexcept
    {
        size_t pos = 0;
        for (int i = bits - 1; i >= 0; --i)
        {
            auto& selected_word = arr[pos / bits_in_word];
            const auto bit = type{ 1 } << pos % bits_in_word;
            selected_word &= ~bit;
            pos++;
        }
        return *this;
    }

    Bitset& reset(size_t pos)
    {
        size_t p = 0;
        for (int i = bits - 1; i >= 0; --i)
        {
            if(pos == p)
            {
                auto& selected_word = arr[p / bits_in_word];
                const auto bit = type{ 1 } << p % bits_in_word;
                selected_word &= ~bit;
            }
            p++;
        }
        return *this;
    }

    Bitset& set() noexcept
    {
        size_t pos = 0;
        for (int i = bits - 1; i >= 0; --i)
        {
            auto& selected_word = arr[pos / bits_in_word];
            const auto bit = type{ 1 } << pos % bits_in_word;
            selected_word |= bit;
            pos++;
        }
        return *this;
    }

    Bitset& set(size_t pos, bool value = true)
    {
        size_t p = 0;
        for (int i = bits - 1; i >= 0; --i)
        {
            if (p == pos)
                set_bit(pos, value);
            p++;
        }
        return *this;
    }

    size_t size() const { return bits; }

    bool operator[](size_t pos) const
    {
        if (pos < bits)
            return test(pos);
        throw std::out_of_range("Out of range. Incorrect index");
    }

    reference operator[](size_t pos)
    {
        if (pos < bits)
            return reference(*this, pos);
        throw std::out_of_range("Out of range. Incorrect index");
    }

    bool test(size_t pos) const
    {
        if (pos >= bits)
            throw std::out_of_range("Out of range. Incorrect position");
        return (arr[pos / bits_in_word] & (type{ 1 } << pos % bits_in_word)) != 0;
    }

    Bitset& operator&=(const Bitset& other) noexcept
    {
        for (int i = 0; i < words; i++)
        {
            arr[i] &= other.arr[i];
        }
        return *this;
    }

    Bitset& operator|=(const Bitset& other) noexcept
    {
        for (int i = 0; i < words; i++)
        {
            arr[i] |= other.arr[i];
        }
        return *this;
    }

    std::string to_string() const
    {
        std::string s;
        s.reserve(bits);

        for (auto pos = bits; 0 < pos;)
        {
            s.push_back(test(--pos) ? '1' : '0');
        }

        return s;
    }

    unsigned long long to_ullong() const
    {
        if (bits == 0) return 0;

        for (size_t i = 1; i < words; i++)
            if (arr[i] != 0)
                throw std::overflow_error("Bitset overflow");

        return arr[0];
    }

    unsigned long to_ulong() const
    {
        if (bits == 0)  return 0;

        if (bits <= 32)
        {
            return static_cast<unsigned long>(arr[0]);
        }

        for (size_t i = 1; i < words; i++)
            if (arr[i] != 0)
                throw std::overflow_error("Bitset overflow");
        return static_cast<unsigned long>(arr[0]);
    }

protected:
    Bitset& set_bit(size_t pos, bool val)
    {
        auto& selected_word = arr[pos / bits_in_word];
        const auto bit = type{ 1 } << pos % bits_in_word;

        if (val)
        {
            selected_word |= bit;
        }
        else
        {
            selected_word &= ~bit;
        }
        return *this;
    }
};

template<size_t bits>
Bitset<bits> operator&(const Bitset<bits>& left, const Bitset<bits>& right) noexcept
{
    Bitset<bits> result = left;
    result &= right;
    return result;
}

template <size_t bits>
Bitset<bits> operator|(const Bitset<bits>& left, const Bitset<bits>& right) noexcept
{
    Bitset<bits> result = left;
    result |= right;
    return result;
}

#endif // BITSET_H
