#include <iostream>
#include <map>
#include <string>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

unsigned hash(const std::string& s)
{
    unsigned h = 0;
    for (const char c : s)
        h ^= 1 << c - 'a';

    return h;
}

void solve(const std::vector<std::string>& s)
{
    integer k = 0;

    std::map<unsigned, unsigned> f;
    for (const std::string& x : s) {
        const unsigned h = hash(x);

        k += f[h]++;

        for (unsigned i = 0; i < 26; ++i)
            ++f[h ^ (1 << i)];
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::string> s(n);
    std::cin >> s;

    solve(s);

    return 0;
}
