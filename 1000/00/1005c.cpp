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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    std::map<unsigned, unsigned> f;
    for (const unsigned x : a)
        ++f[x];

    const auto check = [&f](unsigned q) {
        for (size_t i = 1; i < 31; ++i) {
            const unsigned x = 1 << i;
            if (x < q)
                continue;

            const auto it = f.find(x - q);
            if (it != f.end() && it->second > (x - q == q))
                return true;
        }
        return false;
    };

    unsigned k = 0;
    for (const unsigned x : a)
        k += !check(x);

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

