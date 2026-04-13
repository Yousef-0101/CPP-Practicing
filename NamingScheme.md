# C++ Naming Conventions (Best Practices)

There's no single enforced standard in C++, but the most widely followed conventions are:

---

## Files

| Type         | Convention   | Example             |
| ------------ | ------------ | ------------------- |
| Source files | `snake_case` | `calculate_age.cpp` |
| Header files | `snake_case` | `calculate_age.h`   |

---

## Code Elements

| Element            | Convention                  | Example                              |
| ------------------ | --------------------------- | ------------------------------------ |
| Variables          | `camelCase` or `snake_case` | `ageInDays` / `age_in_days`          |
| Functions          | `camelCase` or `snake_case` | `calculateAge()` / `calculate_age()` |
| Classes            | `PascalCase`                | `AgeCalculator`                      |
| Constants / Macros | `UPPER_SNAKE_CASE`          | `MAX_AGE`, `PI`                      |
| Namespaces         | `snake_case` (lowercase)    | `my_app`                             |

---

## The Key Rule

**Pick one style and stay consistent.** Mixing `camelCase` and `snake_case` in the same project is the main thing to avoid.

---

## What Most People Actually Use

- **Google C++ Style Guide** → prefers `snake_case` for variables/functions, `PascalCase` for classes
- **Many beginners & game devs** → prefer `camelCase` for variables/functions (feels familiar from other languages)

Since you're coming from JavaScript, `camelCase` for variables and functions will feel natural, and that's perfectly fine for your coursework.
