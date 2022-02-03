#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<std::vector<size_t>>& v)
{
    std::cout << v.size() << '\n';

    for (const std::vector<size_t>& s : v) {
        std::cout << s.size();

        for (const size_t x : s)
            std::cout << ' ' << 1+x;

        std::cout << '\n';
    }
}

void combine(const std::vector<size_t>& o, size_t x, std::vector<bool>& v, std::vector<size_t>& s)
{
    if (v[x])
        return;

    s.push_back(x);
    v[x] = true;

    combine(o, o[x], v, s);
}

void solve(const std::vector<int>& a)
{
    const size_t n = a.size();

    std::vector<size_t> o(n);
    for (size_t i = 0; i < n; ++i)
        o[i] = i;

    std::sort(o.begin(), o.end(), [&a](size_t x, size_t y) { return a[x] < a[y]; });

    std::vector<std::vector<size_t>> s;
    {
        std::vector<bool> v(n);
        for (const size_t i : o) {
            std::vector<size_t> t;
            combine(o, i, v, t);

            if (!t.empty())
                s.push_back(std::move(t));
        }
    }

    answer(s);
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
