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

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned v, const std::vector<unsigned>& a)
{
    size_t b = 0;
    for (size_t i = 1; i < 9; ++i) {
        if (a[i] <= a[b])
            b = i;
    }

    const size_t k = v / a[b];
    if (k == 0)
        return no_answer();

    std::string s(k, '1' + b);
    v -= a[b] * k;

    for (char& c : s) {
        size_t x = 8;
        while (x > b && a[x] - a[b] > v)
            --x;

        c = '1' + x;
        v -= a[x] - a[b];
    }

    answer(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned v;
    std::cin >> v;

    std::vector<unsigned> a(9);
    std::cin >> a;

    solve(v, a);

    return 0;
}
