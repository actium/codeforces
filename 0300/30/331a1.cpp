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

void answer(long long x, const std::vector<size_t>& y)
{
    std::cout << x << ' ' << y.size();

    const char* separator = "\n";
    for (const size_t p : y) {
        std::cout << separator << 1+p;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<int>& a)
{
    const size_t n = a.size();

    std::vector<long long> p(1 + n);
    {
        for (size_t i = 0; i < n; ++i)
            p[i+1] = p[i] + std::max(a[i], 0);
    }

    const auto sum = [&](size_t lb, size_t ub) {
        return a[lb] + p[ub-1] - p[lb+1] + a[ub-1];
    };

    std::pair<size_t, size_t> r = { n, n };
    {
        std::map<int, size_t> x;
        for (size_t i = 0; i < n; ++i) {
            const auto it = x.find(a[i]);
            if (it == x.end()) {
                x.emplace(a[i], i);
                continue;
            }

            if (r.first == n || sum(it->second, i+1) > sum(r.first, r.second)) {
                r.first = it->second;
                r.second = i + 1;
            }
        }
    }

    std::vector<size_t> d;
    {
        for (size_t i = 0; i < r.first; ++i)
            d.push_back(i);

        for (size_t i = r.first + 1; i < r.second - 1; ++i) {
            if (a[i] < 0)
                d.push_back(i);
        }

        for (size_t i = r.second; i < n; ++i)
            d.push_back(i);
    }

    answer(sum(r.first, r.second), d);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
