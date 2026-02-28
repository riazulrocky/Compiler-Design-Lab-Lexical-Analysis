# 🛡️ LEXICAL ANALYZER ENGINE (C++)
> **The Modern Tokenizer for Compiler Design Enthusiasts**

![C++](https://img.shields.io/badge/Language-C%2B%2B17-00599C?style=for-the-badge&logo=c%2B%2B)
![Status](https://img.shields.io/badge/Course-Assignment-FF8C00?style=for-the-badge)
![Lexer](https://img.shields.io/badge/Phase-01_Lexical_Analysis-4CAF50?style=for-the-badge)

---

### 🌌 Overview
This project is a high-performance, modular **Lexical Analyzer** built as part of the Compiler Design Laboratory. It acts as the "eyes" of the compiler, scanning raw source code and transforming it into meaningful, categorized **Tokens**.

---

### 🚀 Key Modules & Intelligence

| 🔥 Module | 🛠️ Responsibility | 📂 Source File |
| :--- | :--- | :--- |
| **Master Engine** | Full spectrum token identification | `lexical analysis.cpp` |
| **Unified Lexer** | Integrated classification system | `all.cpp` |
| **Regex Scanner**| Validates Identifier naming rules | `identifier.cpp` |
| **Dictionary** | Reserved Keyword cross-referencing | `keyword.cpp` |
| **Constant Lab** | High-precision numeric extraction | `constant.cpp` |

---

### 🎨 Token Classification Matrix

```ansi
[ 🔑 KEYWORDS ]      -> int, float, if, else, return...
[ 🆔 IDENTIFIERS ]   -> variableNames, functionNames, x, y...
[ 🔢 CONSTANTS ]     -> 10, 3.14, 500 (Numeric literals)
[ ➕ OPERATORS ]     -> +, -, *, /, =, ==, !=
[ 📍 PUNCTUATION ]   -> ;, :, ,
[ 📐 PARENTHESES ]   -> (), {}, []
