#include <iostream>
#include <string>
#include <vector>

#include <cassert>

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

void solve(integer a, const std::vector<unsigned>& digits)
{
    const size_t n = digits.size();

    if (n == 1 && digits[0] == 0)
        return answer(a);

    const auto x = std::to_string(a);
    const auto m = x.length();

    std::string d(n, '0');
    for (size_t i = 0; i < n; ++i)
        d[i] += digits[i];

    std::string ub;
    for (const char c : x) {
        if (d.find(c) != std::string::npos) {
            ub.push_back(c);
            continue;
        }

        ub.push_back(d[0]);
        for (size_t i = 1; i < n && ub.back() < c; ++i)
            ub.back() = d[i];

        if (ub.back() < c) {
            assert(ub.back() == d[n-1]);
            while (!ub.empty() && ub.back() == d[n-1])
                ub.pop_back();

            if (!ub.empty()) {
                const auto i = d.find(ub.back());
                assert(i != std::string::npos && i+1 < n);
                ub.back() = d[i+1];
            } else {
                ub.push_back(d[0] == '0' ? d[1] : d[0]);
                ub.append(m, d[0]);
            }
        }

        while (ub.size() < m)
            ub.push_back(d[0]);

        break;
    }

    const auto u = std::stoull(ub);
    assert(u >= a);

    if (digits[0] >= a)
        return answer(u - a);

    std::string lb;
    for (const char c : x) {
        if (d.find(c) != std::string::npos) {
            lb.push_back(c);
            continue;
        }

        lb.push_back(d[n-1]);
        for (size_t i = n-1; i > 0 && lb.back() > c; --i)
            lb.back() = d[i-1];

        if (c < lb.back()) {
            assert(lb.back() == d[0]);
            while (!lb.empty() && lb.back() == d[0])
                lb.pop_back();

            if (!lb.empty()) {
                const auto i = d.find(lb.back());
                assert(i != std::string::npos && i > 0);
                lb.back() = d[i-1];
            } else {
                lb.push_back('0');
            }
        }

        while (lb.size() < m)
            lb.push_back(d[n-1]);

        break;
    }

    const auto v = std::stoull(lb);
    assert(v <= a);

    answer(std::min(u - a, a - v));
}

void test_case()
{
    integer a;
    std::cin >> a;

    size_t n;
    std::cin >> n;

    std::vector<unsigned> d(n);
    std::cin >> d;

    solve(a, d);
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
