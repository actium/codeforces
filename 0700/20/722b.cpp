#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<unsigned>& p, const std::vector<std::string>& t)
{
    const size_t n = p.size();

    const auto v = [](char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
    };

    for (size_t i = 0; i < n; ++i) {
        if (std::count_if(t[i].cbegin(), t[i].cend(), v) != p[i])
            return answer(false);
    }

    answer(true);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n);
    std::cin >> p;
    std::cin.ignore();

    std::vector<std::string> t(n);
    for (size_t i = 0; i < n; ++i)
        std::getline(std::cin, t[i]);

    solve(p, t);

    return 0;
}

