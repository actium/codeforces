#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<std::pair<size_t, size_t>>& v)
{
    std::cout << v.size() << '\n';
    for (const std::pair<size_t, size_t>& x : v)
        std::cout << 1+x.first << ' ' << 1+x.second << '\n';
}

void solve(std::vector<unsigned>& p)
{
    const size_t n = p.size();

    std::vector<size_t> x(n);
    for (size_t i = 0; i < n; ++i)
        x[p[i]-1] = i;

    std::vector<std::pair<size_t, size_t>> q;

    const auto swap = [&](size_t s, size_t t) {
        std::swap(x[p[s]-1], x[p[t]-1]);
        std::swap(p[s], p[t]);
        q.emplace_back(s, t);
    };

    for (size_t t = 0; t < n; ++t) {
        const size_t s = x[t];

        if (t < n/2 && s < n/2) {
            swap(s, n-1);
            swap(n-1, t);
        }
        if (t >= n/2 && s >= n/2) {
            swap(s, 0);
            swap(0, t);
        }
        if (t < n/2 && s >= n/2) {
            swap(s, 0);
            swap(0, n-1);
            swap(n-1, t);
        }
        if (t >= n/2 && s < n/2) {
            swap(s, n-1);
            swap(n-1, 0);
            swap(0, t);
        }
    }

    answer(q);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n);
    std::cin >> p;

    solve(p);

    return 0;
}
