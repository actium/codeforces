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

std::ostream& operator <<(std::ostream& output, const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        output << separator << x;
        separator = " ";
    }
    return output;
}

void answer(const std::vector<std::vector<unsigned>>& v)
{
    for (const std::vector<unsigned>& x : v)
        std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    std::vector<std::vector<unsigned>> p;
    for (const unsigned x : a) {
        if (p.empty() || x < p.back().back()) {
            p.emplace_back(1, x);
        } else {
            const auto it = std::upper_bound(p.begin(), p.end(), x, [](unsigned x, const auto& v) {
                return x > v.back();
            });
            it->push_back(x);
        }
    }

    answer(p);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
