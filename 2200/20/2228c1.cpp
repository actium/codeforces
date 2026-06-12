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
    assert(digits.size() == 2);

    const char d[2] = { char('0' + digits[0]), char('0' + digits[1]) };

    const auto x = std::to_string(a);
    const auto n = x.length();

    std::string ub;
    for (const char c : x) {
        if (c == d[0] || c == d[1]) {
            ub.push_back(c);
            continue;
        }

        if (c > d[0])
            ub.push_back(d[1]);

        if (c > d[1]) {
            while (!ub.empty() && ub.back() == d[1])
                ub.pop_back();

            if (!ub.empty()) {
                ub.back() = d[1];
            } else {
                ub.push_back(d[0] == '0' ? d[1] : d[0]);
                ub.append(n, d[0]);
            }
        }

        while (ub.size() < n)
            ub.push_back(d[0]);

        break;
    }

    const auto u = std::stoull(ub);
    assert(u >= a);

    if (digits[0] >= a)
        return answer(u - a);

    std::string lb;
    for (const char c : x) {
        if (c == d[0] || c == d[1]) {
            lb.push_back(c);
            continue;
        }

        if (c < d[1])
            lb.push_back(d[0]);

        if (c < d[0]) {
            while (!lb.empty() && lb.back() == d[0])
                lb.pop_back();

            if (!lb.empty()) {
                lb.back() = d[0];
            } else {
                lb.push_back('0');
            }
        }

        while (lb.size() < n)
            lb.push_back(d[1]);

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
