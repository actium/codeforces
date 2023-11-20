#include <iostream>
#include <queue>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b, unsigned p)
{
    const size_t n = a.size();

    std::priority_queue<std::pair<int, unsigned>> q;
    for (size_t i = 0; i < n; ++i)
        q.emplace(-b[i], a[i]);

    integer c = p;
    for (unsigned m = n - 1; m != 0; ) {
        const std::pair<int, unsigned> u = q.top();
        q.pop();

        if (-u.first < p) {
            const integer d = std::min(u.second, m);
            c += -u.first * d;
            m -= d;
        } else {
            c += 1ull * m * p;
            break;
        }
    }

    answer(c);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned p;
    std::cin >> p;

    std::vector<unsigned> a(n), b(n);
    std::cin >> a >> b;

    solve(a, b, p);
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
