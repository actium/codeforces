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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(size_t n, const std::vector<unsigned>& x)
{
    const size_t k = x.size();

    std::set<std::pair<unsigned, unsigned>> s;

    std::vector<bool> v(1 + n + 1);
    for (size_t i = 0; i < k; ++i) {
        s.emplace(x[i], x[i]);

        if (v[x[i]-1])
            s.emplace(x[i]-1, x[i]);

        if (v[x[i]+1])
            s.emplace(x[i]+1, x[i]);

        v[x[i]] = true;
    }

    answer(n * 3 - 2 - s.size());
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> x(k);
    std::cin >> x;

    solve(n, x);

    return 0;
}
