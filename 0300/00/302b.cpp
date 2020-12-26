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

void answer(unsigned v)
{
    std::cout << 1+v << '\n';
}

void solve(const std::vector<std::pair<unsigned, unsigned>>& p, const std::vector<unsigned>& v)
{
    const size_t n = p.size(), m = v.size();

    std::vector<unsigned long long> t(n);
    for (size_t i = 0; i < n; ++i)
        t[i] = p[i].first * p[i].second;

    for (size_t i = 1; i < n; ++i)
        t[i] += t[i-1];

    for (size_t i = 0, j = 0; j < m; ++j) {
        while (t[i] < v[j])
            ++i;

        answer(i);
    }
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::pair<unsigned, unsigned>> p(n);
    std::cin >> p;

    std::vector<unsigned> v(m);
    std::cin >> v;

    solve(p, v);

    return 0;
}

