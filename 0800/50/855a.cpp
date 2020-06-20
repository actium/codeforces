#include <iostream>
#include <string>
#include <unordered_set>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

int main()
{
    size_t n;
    std::cin >> n;

    std::unordered_set<std::string> s;
    for (size_t i = 0; i < n; ++i) {
        std::string t;
        std::cin >> t;

        answer(!s.insert(t).second);
    }

    return 0;
}

