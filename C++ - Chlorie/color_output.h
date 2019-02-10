#pragma once

#include "string_template.h"
#include "converter.h"

using Semicolon = String<';'>;
using CtrlSeq = String<'\033', '['>;
using LowerCaseM = String<'m'>;

template <int Red, int Green, int Blue>
using ColorStr = Join<CtrlSeq,
    ToString<38>, Semicolon,
    ToString<2>, Semicolon,
    ToString<Red>, Semicolon,
    ToString<Green>, Semicolon,
    ToString<Blue>, LowerCaseM>;
