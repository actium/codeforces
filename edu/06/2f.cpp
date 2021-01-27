#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

template <typename T, typename F>
T search(T lb, T ub, F&& f)
{
    for (auto k = ub - lb; k > 1; ) {
        const auto half = k / 2;
        if (!f(lb + half))
            lb += half;

        k -= half;
    }
    return lb;
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::string& t, const std::string& p, const std::vector<unsigned>& a)
{
    const size_t n = t.length(), m = p.length();

    // returns true if p cannot be constructed using last n-k characters of t
    const auto f = [&](size_t k) {
        if (n - k < m)
            return true;

        std::string q = t;
        for (size_t i = 0; i < k; ++i)
            q[a[i]-1] = ' ';

        size_t j = 0;
        for (size_t i = 0; i < n && j < m; ++i) {
            if (p[j] == q[i])
                ++j;
        }
        return j < m;
    };

    answer(search<size_t>(0, n, f));
}

int main()
{
    std::string t, p;
    std::cin >> t >> p;

    std::vector<unsigned> a(t.length());
    std::cin >> a;

    solve(t, p, a);

    return 0;
}

