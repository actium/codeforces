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

void solve(const std::vector<unsigned>& a, const std::vector<std::pair<unsigned, unsigned>>& r)
{
    const size_t n = a.size();

    std::vector<unsigned> pz(1+n), pc(1+n);
    for (size_t i = 0; i < n; ++i) {
        pz[i+1] = pz[i] + (a[i] == 0);

        if (i != 0)
            pc[i+1] = pc[i] + (a[i] == a[i-1]);
    }

    for (const auto& [l, r] : r) {
        const unsigned m = r - l + 1;

        if (m % 3 == 0 && (pz[r] - pz[l-1]) % 3 == 0) {
            answer(m / 3 + (pc[r] == pc[l]));
        } else {
            no_answer();
        }
    }
}

void test_case()
{
    size_t n, q;
    std::cin >> n >> q;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<std::pair<unsigned, unsigned>> r(q);
    std::cin >> r;

    solve(a, r);
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
