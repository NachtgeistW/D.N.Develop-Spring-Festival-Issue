#pragma once

template <int Size>
class StaticString final
{
    template <int OtherSize> friend class StaticString;
private:
    char value_[Size + 1]{};
    constexpr StaticString(const StaticString<Size - 1>& str, const char last)
    {
        for (int i = 0; i < Size - 1; i++) value_[i] = str.value_[i];
        value_[Size - 1] = last;
    }
    constexpr StaticString(const char first, const StaticString<Size - 1>& str)
    {
        value_[0] = first;
        for (int i = 0; i < Size - 1; i++) value_[i + 1] = str.value_[i];
    }
public:
    constexpr const char* value() const { return value_; }
    constexpr StaticString<Size + 1> push_back(const char c) const
    {
        return StaticString<Size + 1>(*this, c);
    }
    constexpr StaticString<Size + 1> push_front(const char c) const
    {
        return StaticString<Size + 1>(c, *this);
    }
};

template <>
class StaticString<0> final
{
    template <int OtherSize> friend class StaticString;
private:
    char value_[1]{};
public:
    constexpr StaticString() = default;
    constexpr const char* value() const { return value_; }
    constexpr StaticString<1> push_back(const char c) const
    {
        return StaticString<1>(*this, c);
    }
    constexpr StaticString<1> push_front(const char c) const
    {
        return StaticString<1>(c, *this);
    }
};
