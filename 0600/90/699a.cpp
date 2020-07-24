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

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s, const std::vector<unsigned>& x)
{
    const size_t n = x.size();

    unsigned d = ~0u;
    for (size_t i = 1; i < n; ++i) {
        if (s[i] == 'L' && s[i-1] == 'R')
            d = std::min(d, (x[i] - x[i-1]) / 2);
    }

    answer(d != ~0u ? d : -1);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::vector<unsigned> x(n);
    std::cin >> x;

    solve(s, x);

    return 0;
}

