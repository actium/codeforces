#include <iostream>
#include <string>

constexpr char correction_table[26][2] = {
    { ' ', 's' },
    { 'v', 'n' },
    { 'x', 'v' },
    { 's', 'f' },
    { 'w', 'r' },
    { 'd', 'g' },
    { 'f', 'h' },
    { 'g', 'j' },
    { 'u', 'o' },
    { 'h', 'k' },
    { 'j', 'l' },
    { 'k', ';' },
    { 'n', ',' },
    { 'b', 'm' },
    { 'i', 'p' },
    { 'o', ' ' },
    { ' ', 'w' },
    { 'e', 't' },
    { 'a', 'd' },
    { 'r', 'y' },
    { 'y', 'i' },
    { 'c', 'b' },
    { 'q', 'e' },
    { 'z', 'c' },
    { 't', 'u' },
    { ' ', 'x' },
};

void answer(char c, size_t index)
{
    if (isalpha(c)) {
        std::cout << correction_table[c - 'a'][index];
    } else {
        switch (c) {
            case ';':
                std::cout << (index == 0 ? 'l' : ' ');
                break;
            case ',':
                std::cout << (index == 0 ? 'm' : '.');
                break;
            case '.':
                std::cout << (index == 0 ? ',' : '/');
                break;
            case '/':
                std::cout << (index == 0 ? '.' : ' ');
                break;
        }
    }
}

void solve(const std::string& s, size_t index)
{
    for (const char c : s)
        answer(c, index);

    std::cout << '\n';
}

int main()
{
    char shift;
    std::cin >> shift;

    std::string s;
    std::cin >> s;

    solve(s, shift == 'R' ? 0 : 1);

    return 0;
}

