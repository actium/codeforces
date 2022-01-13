#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(size_t x)
{
    std::cout << x << '\n';
}

void solve(std::vector<unsigned>& a)
{
    size_t n = a.size();

    std::sort(a.begin(), a.end());

    std::priority_queue<unsigned> q;

    size_t j = 0;
    for (size_t i = 0; i < n; ++i) {
        if (a[i] != a[j]) {
            q.push(i - j);
            j = i;
        }
    }
    q.push(n - j);

    for ( ; q.size() > 1; n -= 2) {
        unsigned x = q.top(); q.pop();
        unsigned y = q.top(); q.pop();

        if (--x != 0)
            q.push(x);

        if (--y != 0)
            q.push(y);
    }

    answer(n);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
