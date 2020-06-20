#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(std::string& s, const std::string& l1, const std::string& l2)
{
    char conversion_table[256];
    for (size_t i = 0; i < 26; ++i) {
        conversion_table[l1[i]] = l2[i];
        conversion_table[toupper(l1[i])] = toupper(l2[i]);
    }

    for (char& c : s) {
        if (isalpha(c))
            c = conversion_table[c];
    }

    answer(s);
}

int main()
{
    std::string l1;
    std::cin >> l1;

    std::string l2;
    std::cin >> l2;

    std::string s;
    std::cin >> s;

    solve(s, l1, l2);

    return 0;
}

