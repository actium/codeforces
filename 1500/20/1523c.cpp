#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<std::string>& v)
{
    for (const std::string& x : v)
        std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<std::string> s(n);
    {
        std::vector<unsigned> t;
        for (size_t i = 0; i < n; ++i) {
            if (a[i] == 1) {
                t.emplace_back();
            } else {
                while (t.back() + 1 != a[i])
                    t.pop_back();
            }
            ++t.back();

            for (auto it = t.begin(); it != t.end(); ++it) {
                s[i].append(std::to_string(*it));
                s[i].push_back('.');
            }
            s[i].pop_back();
        }
    }

    answer(s);
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

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
