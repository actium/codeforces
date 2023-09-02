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

void solve(std::vector<int>& a, std::vector<int>& b, int w, int h)
{
    const size_t n = a.size();

    int ld = 0, rd = 0;
    for (size_t i = 0; i < n; ++i) {
        if (a[i] - w > b[i] - h)
            ld = std::max(ld, (a[i] - w) - (b[i] - h));

        if (a[i] + w < b[i] + h)
            rd = std::max(rd, (b[i] + h) - (a[i] + w));
    }

    for (size_t i = 0; i < n; ++i) {
        if (a[i] - ld + rd - w > b[i] - h || a[i] - ld + rd + w < b[i] + h)
            return answer(false);
    }

    answer(true);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    int w, h;
    std::cin >> w >> h;

    std::vector<int> a(n), b(n);
    std::cin >> a >> b;

    solve(a, b, w, h);
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
