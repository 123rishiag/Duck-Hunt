#pragma once

namespace Utility
{
    template <typename Enum>
    Enum ToEnum(int value)
    {
        return static_cast<Enum>(value);
    }
}