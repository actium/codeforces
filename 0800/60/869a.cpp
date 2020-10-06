#include <iostream>
#include <set>
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
    constexpr const char* s[2] = { "Karen", "Koyomi" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<unsigned>& x, const std::vector<unsigned>& y)
{
    const size_t n = x.size();

    std::set<unsigned> s;
    s.insert(x.cbegin(), x.cend());
    s.insert(y.cbegin(), y.cend());

    unsigned k = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            k += s.count(x[i] ^ y[j]);
        }
    }

    answer(k % 2);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> x(n);
    std::cin >> x;

    std::vector<unsigned> y(n);
    std::cin >> y;

    solve(x, y);

    return 0;
}

