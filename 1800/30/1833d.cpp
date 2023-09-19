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

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& p)
{
    size_t x = std::max_element(p.begin() + 1, p.end()) - p.begin();

    std::vector<unsigned> q;
    q.insert(q.end(), p.begin() + x, p.end());
    if (x + 1 < p.size())
        q.push_back(p[--x]);
    while (x-- > 0 && p[x] > p[0])
        q.push_back(p[x]);
    q.insert(q.end(), p.begin(), p.begin() + x + 1);

    answer(q);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n);
    std::cin >> p;

    solve(p);
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
