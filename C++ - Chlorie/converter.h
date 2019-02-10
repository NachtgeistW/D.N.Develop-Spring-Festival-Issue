#pragma once

#include "string_template.h"

template <int Value, bool IsSingleDigit = (Value < 10)> struct IntConverter;

template <int Value>
struct IntConverter<Value, true> final
{
    static_assert(Value >= 0, "Value should be non-negative");
    using Result = String<'0' + Value>;
};

template <int Value>
struct IntConverter<Value, false> final
{
    using Result =
        typename IntConverter<Value / 10>::Result::
        template Add<Value % 10 + '0'>;
};

template <int Value>
using ToString = typename IntConverter<Value>::Result;
