#include <iostream>
#include <vector>

struct Friend {
    unsigned a;
    unsigned b;
    char c;
};

std::istream& operator >>(std::istream& input, Friend& v)
{
    return input >> v.c >> v.a >> v.b;
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

void solve(const std::vector<Friend>& f)
{
    const size_t n = f.size();

    unsigned x[366] = {}, y[366] = {};
    for (size_t i = 0; i < n; ++i) {
        auto& p = (f[i].c == 'M' ? x : y);
        for (size_t j = f[i].a - 1; j < f[i].b; ++j)
            ++p[j];
    }

    unsigned k = 0;
    for (size_t i = 0; i < 366; ++i)
        k = std::max(k, std::min(x[i], y[i]));

    answer(2 * k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<Friend> f(n);
    std::cin >> f;

    solve(f);

    return 0;
}

