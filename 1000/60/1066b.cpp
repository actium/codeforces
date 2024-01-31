#include <iostream>
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

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<unsigned>& a, size_t r)
{
    const size_t n = a.size();

    std::vector<size_t> p;
    for (size_t i = 0; i < n; ++i) {
        if (a[i] == 0)
            continue;

        if (!p.empty() && p.back() + r + r <= i)
            return no_answer();

        if (p.size() == 1 && i < r || p.size() > 1 && p.end()[-2] + r + r > i)
            p.back() = i;
        else
            p.push_back(i);

        if (p.back() + r >= n)
            break;
    }

    if (p.empty() || p.front() >= r || p.back() + r < n)
        return no_answer();

    answer(p.size());
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, r;
    std::cin >> n >> r;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, r);

    return 0;
}
