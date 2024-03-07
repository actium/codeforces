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

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<unsigned>& x, const std::vector<unsigned>& c, unsigned k, unsigned a)
{
    const size_t n = x.size();

    integer s = 0;

    std::priority_queue<unsigned, std::vector<unsigned>, std::greater<unsigned>> q;
    for (size_t i = 0; i < n; ++i) {
        q.push(c[i]);

        while (k < x[i] && !q.empty()) {
            s += q.top();
            q.pop();
            k += a;
        }

        if (k < x[i])
            return no_answer();
    }

    answer(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::vector<unsigned> x(n);
    std::cin >> x;

    unsigned a;
    std::cin >> a;

    std::vector<unsigned> c(n);
    std::cin >> c;

    solve(x, c, k, a);

    return 0;
}
