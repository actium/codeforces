#include <algorithm>
#include <iostream>
#include <string>
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

void no_answer()
{
    std::cout << "NO" << '\n';
}

void answer(const std::string& v)
{
    std::cout << "YES" << '\n';
    std::cout << v << '\n';
}

void solve(std::vector<std::pair<unsigned, unsigned>>& p)
{
    const auto comparator = [](const std::pair<unsigned, unsigned>& a, const std::pair<unsigned, unsigned>& b) {
        return a.second == b.second ? a.first < b.first : a.second < b.second;
    };
    std::sort(p.begin(), p.end(), comparator);

    std::string a;

    unsigned x = 0, y = 0;
    for (const auto& q : p) {
        if (q.first < x || q.second < y)
            return no_answer();

        a.append(q.first - x, 'R');
        a.append(q.second - y, 'U');

        x = q.first, y = q.second;
    }

    answer(a);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> p(n);
    std::cin >> p;

    solve(p);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

