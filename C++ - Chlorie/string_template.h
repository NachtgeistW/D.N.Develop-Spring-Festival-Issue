#pragma once

#include "static_string.h"

template <char... Str> struct String;

namespace detail
{
    template <typename Left, typename Right> struct ConcatenateImpl;
    template <char... Str1, char... Str2>
    struct ConcatenateImpl<String<Str1...>, String<Str2...>> final
    {
        using ResultType = String<Str1..., Str2...>;
    };
}

template <char... Str>
struct String final
{
    template <char... OtherStr>
    using Add = String<Str..., OtherStr...>;
    constexpr static StaticString<sizeof...(Str)> value();
    template <typename StrType>
    using Concatenate = typename detail::ConcatenateImpl<String<Str...>, StrType>::ResultType;
};

namespace detail
{
    template <char First, char... Rest>
    constexpr StaticString<sizeof...(Rest) + 1> value_impl()
    {
        return String<Rest...>::value().push_front(First);
    }
}

template <char... Str>
constexpr StaticString<sizeof...(Str)> String<Str...>::value()
{
    return detail::value_impl<Str...>();
}

template <>
struct String<> final
{
    template <char... Str>
    using Concatenate = String<Str...>;
    constexpr static StaticString<0> value() { return {}; }
};

namespace detail
{
    template <typename... StrTypes> struct JoinImpl;
    template <typename First, typename... Rest>
    struct JoinImpl<First, Rest...> final
    {
        using ResultType =
            typename First::
            template Concatenate<typename JoinImpl<Rest...>::ResultType>;
    };
    template <>
    struct JoinImpl<> final
    {
        using ResultType = String<>;
    };
}

template <typename... StrTypes>
using Join = typename detail::JoinImpl<StrTypes...>::ResultType;
