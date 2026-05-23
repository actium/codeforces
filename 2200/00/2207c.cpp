#include <iostream>
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

template <typename Iterator>
std::vector<integer> prepare(Iterator begin, Iterator end, integer h)
{
    const auto prefix_length = [&](Iterator x) {
        return x - begin + 1;
    };

    std::vector<integer> p(prefix_length(end));
    {
        std::vector<Iterator> q;
        for (auto it = begin; it != end; ++it) {
            while (!q.empty() && *q.back() <= *it)
                q.pop_back();

            const size_t x = prefix_length(it);
            if (q.empty())
                p[x] = x * (h - *it);
            else
                p[x] = p[prefix_length(q.back())] + (it - q.back()) * (h - *it);

            q.push_back(it);
        }
    }
    return p;
}

void solve(const std::vector<unsigned>& a, unsigned h)
{
    const size_t n = a.size();

    const std::vector<integer> p = prepare(a.begin(), a.end(), h);
    const std::vector<integer> s = prepare(a.rbegin(), a.rend(), h);

    const auto evaluate = [&](size_t x) {
        return p[x+1] + s[n-x] - (h - a[x]);
    };

    integer v = 0;
    for (size_t i = 0; i < n; ++i) {
        size_t x = i;
        for (size_t j = i + 1; j < n; ++j) {
            if (a[j] > a[x])
                x = j;

            v = std::max(v, evaluate(i) + evaluate(j) - evaluate(x));
        }

        v = std::max(v, evaluate(i));
    }

    answer(v);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned h;
    std::cin >> h;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, h);
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
