#include <iostream>
#include <set>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

std::ostream& operator <<(std::ostream& output, const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        output << separator << x;
        separator = " ";
    }
    return output;
}

void answer(const std::vector<unsigned>& x, const std::vector<unsigned>& y)
{
    std::cout << x << '\n';
    std::cout << y << '\n';
}

void solve(const std::vector<unsigned>& q)
{
    const size_t n = q.size();

    std::set<unsigned> s[2];
    for (unsigned i = 1; i <= n; ++i) {
        s[0].insert(i);
        s[1].insert(i);
    }

    std::vector<unsigned> x(n), y(n);

    const auto place = [&](size_t i, unsigned u, unsigned v) {
        x[i] = u;
        s[0].erase(u);

        y[i] = v;
        s[1].erase(v);
    };

    place(0, q[0], q[0]);
    for (size_t i = 1, j = 0; i < n; ++i) {
        if (q[i] > q[j]) {
            place(i, q[i], q[i]);
            j = i;
        } else {
            place(i, *s[0].begin(), *std::prev(s[1].lower_bound(y[i-1])));
        }
    }

    answer(x, y);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> q(n);
    std::cin >> q;

    solve(q);
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
