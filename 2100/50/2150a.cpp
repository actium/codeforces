#include <algorithm>
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

void answer(const std::vector<unsigned>& v)
{
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::string& s, const std::vector<unsigned>& a)
{
    std::vector<unsigned> b = a;
    {
        unsigned x = 1;

        for (const char c : s) {
            ++x;

            if (c == 'B') {
                while (std::binary_search(a.begin(), a.end(), x))
                    ++x;
            }

            b.push_back(x);

            if (c == 'B')
                while (std::binary_search(a.begin(), a.end(), ++x));
        }
    }

    std::sort(b.begin(), b.end());
    b.erase(std::unique(b.begin(), b.end()), b.end());

    answer(b);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::string s;
    std::cin >> s;

    std::vector<unsigned> a(m);
    std::cin >> a;

    solve(s, a);
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
