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

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(std::vector<unsigned>& h, unsigned b)
{
    std::sort(h.begin(), h.end(), std::greater<unsigned>());

    while (!h.empty() && h.back() <= b)
        h.pop_back();

    unsigned t = 0;
    while (!h.empty()) {
        t += h.back() - b;
        if (t > b)
            return answer(false);

        b = h.back();
        h.pop_back();
    }

    answer(true);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> h(n);
    std::cin >> h;

    solve(h, h[k-1]);
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
