#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void answer(const std::vector<std::pair<unsigned, unsigned>>& v)
{
    std::cout << v.size() << '\n';

    for (const auto& x : v)
        std::cout << 1 + x.second << ' ' << 1 + x.first << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<std::pair<unsigned, unsigned>> t;
    std::vector<size_t> u, v;
    for (size_t x = n; x-- > 0; ) {
        if (a[x] == 1) {
            t.emplace_back(x, x);
            u.push_back(x);
        }
        if (a[x] == 2) {
            if (u.empty())
                return no_answer();

            t.emplace_back(x, u.back());
            u.pop_back();
            v.push_back(x);
        }
        if (a[x] == 3) {
            auto& p = v.empty() ? u : v;
            if (p.empty())
                return no_answer();

            t.emplace_back(p.back(), x);
            t.emplace_back(x, x);
            p.pop_back();
            v.push_back(x);
        }
    }

    answer(t);
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

