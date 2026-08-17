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

void solve(const std::vector<unsigned>& a)
{
    std::vector<std::pair<unsigned, unsigned>> b;
    for (const unsigned x : a) {
        if (b.empty() || x != b.back().first)
            b.emplace_back(x, 0);

        ++b.back().second;
    }

    const size_t m = b.size(); 

    if (m > 1) {
        for (size_t i = 1; i < m; ++i) {
            if (b[i-1].second > 1 && b[i].second > 1)
                return answer(m + 2);
        }
        
        for (size_t i = 2; i < m; ++i) {
            if (b[i-2].second > 1 && b[i-2].first != b[i].first)
                return answer(m + 1);
                
            if (b[i].second > 1 && b[i-2].first != b[i].first)
                return answer(m + 1); 
        }

        if (b[1].second > 1 || b[m-2].second > 1)
            return answer(m + 1);
    }

    answer(m);
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
