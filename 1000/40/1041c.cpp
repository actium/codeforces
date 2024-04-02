#include <iostream>
#include <map>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned u, const std::vector<unsigned>& v)
{
    std::cout << u << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& a, unsigned d)
{
    const size_t n = a.size();

    std::map<unsigned, size_t> x;
    for (size_t i = 0; i < n; ++i)
        x.emplace(a[i], i);

    std::vector<unsigned> s(n);
    unsigned t = 0, k = 1;
    while (!x.empty()) {
        const auto it = x.lower_bound(t);
        if (it == x.end()) {
            t = 0;
            ++k;
        } else {
            s[it->second] = k;
            t = it->first + d + 1;
            x.erase(it);
        }
    }

    answer(k, s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned m, d;
    std::cin >> m >> d;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, d);

    return 0;
}
