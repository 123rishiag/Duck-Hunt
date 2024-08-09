#pragma once

// TO convert one enum class to other type
namespace Utility
{
    template <typename Enum>
    Enum ToEnum(int value)
    {
        return static_cast<Enum>(value);
    }
}