#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    std::cout << "Possible" << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << "Impossible" << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<std::vector<size_t>> s(n);
    for (size_t i = 0; i < n; ++i)
        s[a[i]].push_back(i);

    std::vector<unsigned> c(n);
    for (size_t i = 0, x = 1; i < n; ++i) {
        const size_t k = n - i;
        if (s[i].size() % k != 0)
            return no_answer();

        for ( ; !s[i].empty(); ++x) {
            for (size_t j = 0; j < k; ++j) {
                c[s[i].back()] = x;
                s[i].pop_back();
            }
        }
    }

    answer(c);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
