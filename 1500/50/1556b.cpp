#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<size_t> p[2];
    for (size_t i = 0; i < n; ++i)
        p[a[i] % 2].push_back(i);

    const auto evaluate = [&](unsigned x) {
        unsigned k = 0;
        for (size_t i = 0; i < n; ++i) {
            const size_t j = p[i%2^x][i/2];
            if (j > i)
                k += j - i;
        }
        return k;
    };

    const size_t fe = p[0].size(), fo = p[1].size();
    if (fe > fo) {
        if (fe - fo > 1)
            return no_answer();

        return answer(evaluate(0));
    }
    if (fe < fo) {
        if (fo - fe > 1)
            return no_answer();

        return answer(evaluate(1));
    }

    answer(std::min(evaluate(0), evaluate(1)));
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

