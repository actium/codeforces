#include <iostream>
#include <set>
#include <string>

void answer(size_t v)
{
    std::cout << v << '\n';
}

int main()
{
    size_t n;
    std::cin >> n;

    std::set<std::pair<std::string, std::string>> s;
    for (size_t i = 0; i < n; ++i) {
        std::string t, c;
        std::cin >> t >> c;

        s.emplace(t, c);
    }

    answer(s.size());

    return 0;
}

