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

void answer(const std::vector<int>& v)
{
    std::cout << "YES" << '\n';

    const char* separator = "";
    for (const int x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(const std::vector<int>& a)
{
    std::map<int, unsigned> f;
    for (const int x : a)
        ++f[x];

    std::vector<int> s;
    for (const auto& e : f) {
        for (unsigned i = 2; i <= 8; i += 2) {
            if (e.second >= i)
                s.push_back(e.first);
        }
    }

    const size_t k = s.size();
    if (k < 4)
        return no_answer();

    answer({ s[0], s[1], s[0], s[k-1], s[k-2], s[1], s[k-2], s[k-1] });
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
