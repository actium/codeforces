#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using integer = unsigned long long;

std::vector<unsigned> primes;

void initialize()
{
    unsigned spf[31623] = {};
    for (unsigned i = 2; i < 31623; ++i) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }

        for (const unsigned p : primes) {
            if (p > spf[i] || i * p > 31622)
                break;

            spf[i * p] = p;
        }
    }
}

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

std::vector<std::pair<unsigned, unsigned>> factorize(unsigned n)
{
    std::vector<std::pair<unsigned, unsigned>> factors;
    for (const unsigned p : primes) {
        if (p * p > n)
            break;

        if (n % p != 0)
            continue;

        factors.emplace_back(p, 0);
        do {
            ++factors.back().second;
            n /= p;
        } while (n % p == 0);
    }
    if (n != 1)
        factors.emplace_back(n, 1);

    return factors;
}

void solve(const std::vector<unsigned>& a)
{
    std::map<unsigned, unsigned> f;
    for (const unsigned x : a)
        ++f[x];

    integer count = 0;
    for (const auto& e : f) {
        const integer c = e.second;
        if (c >= 3)
            count += c * (c - 1) * (c - 2);

        std::vector<unsigned> q = { 1 };
        for (const auto& [p, k] : factorize(e.first)) {
            for (unsigned i = 2; i <= k; i += 2) {
                for (size_t j = q.size(); j != 0; --j)
                    q.push_back(q[j-1] * p);
            }
        }

        std::sort(q.begin(), q.end());

        for (size_t i = 1; i < q.size(); ++i) {
            const unsigned b = q[i];
            if (b == q[i-1])
                continue;

            const auto it = f.find(e.first / b);
            if (it == f.end())
                continue;

            const auto jt = f.find(it->first / b);
            if (jt != f.end())
                count += c * it->second * jt->second;
        }
    }

    answer(count);
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
    std::cin.tie(nullptr)->sync_with_stdio(false);

    initialize();

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
