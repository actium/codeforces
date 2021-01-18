#include <iostream>
#include <string>
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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s, const std::vector<std::pair<unsigned, unsigned>>& p)
{
    constexpr size_t N = 200;

    const size_t n = p.size();

    std::vector<unsigned> c(N);
    for (size_t i = 0; i < n; ++i) {
        const auto [a, b] = p[i];

        unsigned x = s[i] - '0';
        for (unsigned t = 0; t < N; ++t) {
            x ^= (t >= b && (t - b) % a == 0);
            c[t] += x;
        }
    }

    unsigned k = 0;
    for (size_t t = 0; t < N; ++t)
        k = std::max(k, c[t]);

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::vector<std::pair<unsigned, unsigned>> p(n);
    std::cin >> p;

    solve(s, p);

    return 0;
}

