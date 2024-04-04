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

std::vector<unsigned> primes;

void initialize()
{
    primes.push_back(2);

    const auto is_prime = [&](unsigned x) {
        for (const unsigned p : primes) {
            if (x % p == 0)
                return false;
        }
        return true;
    };

    for (unsigned i = 3; i * i <= 1000000000; i += 2) {
        if (is_prime(i))
            primes.push_back(i);
    }
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    std::set<unsigned> s;
    for (unsigned x : a) {
        for (const unsigned p : primes) {
            if (p * p > x)
                break;

            if (x % p != 0)
                continue;

            if (!s.insert(p).second)
                return answer(true);

            while (x % p == 0)
                x /= p;
        }

        if (x != 1 && !s.insert(x).second)
            return answer(true);
    }

    answer(false);
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
