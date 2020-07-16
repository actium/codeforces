#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<size_t>& v)
{
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const size_t x : v) {
        std::cout << separator << 1 + x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<std::vector<unsigned>>& s, unsigned v)
{
    const size_t n = s.size();

    std::vector<size_t> q;
    for (size_t i = 0; i < n; ++i) {
        if (std::find_if(s[i].cbegin(), s[i].cend(), [v](unsigned x) { return x < v; }) != s[i].cend())
            q.push_back(i);
    }

    answer(q);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned v;
    std::cin >> v;

    std::vector<std::vector<unsigned>> s(n);
    for (size_t i = 0; i < n; ++i) {
        size_t k;
        std::cin >> k;

        s[i].resize(k);
        std::cin >> s[i];
    }

    solve(s, v);

    return 0;
}

