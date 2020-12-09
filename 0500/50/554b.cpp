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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(std::vector<std::string>& s)
{
    const size_t n = s.size();

    unsigned k = 0;
    for (size_t i = 0; i < n; ++i) {
        const unsigned c = std::count(s.cbegin(), s.cend(), s[i]);
        k = std::max(k, c);
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::string> s(n);
    std::cin >> s;

    solve(s);

    return 0;
}

