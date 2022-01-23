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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    size_t r = 0;

    std::map<unsigned, unsigned> f;
    for (size_t i = 0, j = 0; j < n; ++j) {
        ++f[a[j]];

        while (f.rbegin()->first - f.begin()->first > 1) {
            const auto it = f.find(a[i++]);
            if (--it->second == 0)
                f.erase(it);
        }

        r = std::max(r, j - i + 1);
    }

    answer(r);
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
