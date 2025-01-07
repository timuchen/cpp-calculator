#pragma once

enum class Operation {
    MULTIPLICATION,
    DIVISION,
    SUBTRACTION,
    ADDITION,
    POWER,
};

enum class ControlKey {
    EQUALS,     // Кнопка "Равно".
    CLEAR,      // Кнопка "C".
    MEM_SAVE,   // Кнопка "MS".
    MEM_LOAD,   // Кнопка "ML".
    MEM_CLEAR,  // Кнопка "MC".
    PLUS_MINUS, // Кнопка "+-".
    BACKSPACE,  // Кнопка "Стереть последний символ".
    EXTRA_KEY,  // Дополнительная экстра-кнопка.
};

enum class ControllerType {
    DOUBLE = 0,
    UINT8_T,
    INT,
    INT64_T,
    SIZE_T,
    FLOAT,
    RATIONAL,
};
