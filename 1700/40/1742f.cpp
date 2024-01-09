#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct Operation {
    unsigned t;
    unsigned k;
    std::string x;
};

std::istream& operator >>(std::istream& input, Operation& op)
{
    return input >> op.t >> op.k >> op.x;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<Operation>& ops)
{
    unsigned long long f[2] = { 1, 1 }, k[2] = { 1, 1 };
    for (const Operation& op : ops) {
        for (const char c : op.x) {
            if (c == 'a')
                f[op.t-1] += op.k;

            k[op.t-1] += op.k;
        }

        answer(f[0] == k[0] && k[0] < k[1] || k[1] != f[1]);
    }
}

void test_case()
{
    size_t q;
    std::cin >> q;

    std::vector<Operation> ops(q);
    std::cin >> ops;

    solve(ops);
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
