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

void solve(const std::vector<unsigned>& p, size_t x, size_t y)
{
    std::vector<unsigned> mid(p.begin() + x, p.begin() + y);
    std::rotate(mid.begin(), std::min_element(mid.begin(), mid.end()), mid.end());

    std::vector<unsigned> q;
    q.insert(q.end(), p.begin(), p.begin() + x);
    q.insert(q.end(), p.begin() + y, p.end());

    const auto it = std::find_if(q.begin(), q.end(), [&](unsigned v) { return v > mid[0]; });
    q.insert(it, mid.begin(), mid.end());

    answer(q);
}

void test_case()
{
    size_t n, x, y;
    std::cin >> n >> x >> y;

    std::vector<unsigned> p(n);
    std::cin >> p;

    solve(p, x, y);
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
