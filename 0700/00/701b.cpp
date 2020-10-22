#include <iostream>
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

using integer = unsigned long long;

void answer(const std::vector<integer>& v)
{
    const char* separator = "";
    for (const integer x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(integer n, const std::vector<std::pair<unsigned, unsigned>>& p)
{
    std::vector<integer> v;

    std::vector<bool> r(n), c(n);
    unsigned k[2] = {};
    for (const auto& e : p) {
        if (!r[e.first-1]) {
            r[e.first-1] = true;
            ++k[0];
        }
        if (!c[e.second-1]) {
            c[e.second-1] = true;
            ++k[1];
        }

        const integer d = n * k[0] + n * k[1] - 1ull * k[0] * k[1];
        v.push_back(n * n - d);
    }

    answer(v);
}

int main()
{
    unsigned n;
    std::cin >> n;

    size_t m;
    std::cin >> m;

    std::vector<std::pair<unsigned, unsigned>> p(m);
    std::cin >> p;

    solve(n, p);

    return 0;
}

