#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<size_t>& v)
{
    std::cout << v.size() << '\n';

    if (!v.empty()) {
        const char* separator = "";
        for (const size_t x : v) {
            std::cout << separator << x;
            separator = " ";
        }
        std::cout << '\n';
    }
}

int main()
{
    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::vector<size_t> d;
    for (size_t i = 0, b = 0; i < n; ++i) {
        if (s[i] != 'B')
            continue;

        if (i == 0 || s[i-1] != 'B')
            d.push_back(1);
        else
            ++d.back();
    }

    answer(d);

    return 0;
}

