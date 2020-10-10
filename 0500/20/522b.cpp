#include <iostream>
#include <set>
#include <vector>

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<std::pair<unsigned, unsigned>>& s)
{
    const size_t n = s.size();

    unsigned w = 0;
    std::multiset<unsigned> h;
    for (const auto& x : s) {
        w += x.first;
        h.insert(x.second);
    }

    std::vector<unsigned> b;
    b.reserve(n);
    for (const auto& x : s) {
        h.erase(h.find(x.second));
        b.push_back((w - x.first) * *h.rbegin());
        h.insert(x.second);
    }

    answer(b);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> s(n);
    std::cin >> s;

    solve(s);

    return 0;
}

