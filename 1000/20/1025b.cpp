#include <iostream>
#include <vector>

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

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

void solve(const std::vector<std::pair<unsigned, unsigned>>& p)
{
    const auto check = [&](unsigned x) {
        for (const std::pair<unsigned, unsigned>& e : p) {
            if (e.first % x != 0 && e.second % x != 0)
                return false;
        }
        return true;
    };

    for (unsigned x : { p[0].first, p[0].second }) {
        for (unsigned i = 2; i * i <= x; ++i) {
            if (check(i))
                return answer(i);

            while (x % i == 0)
                x /= i;
        }

        if (x != 1 && check(x))
            return answer(x);
    }

    no_answer();
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> p(n);
    std::cin >> p;

    solve(p);

    return 0;
}