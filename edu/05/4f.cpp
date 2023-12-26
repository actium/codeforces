#include <iostream>
#include <optional>

struct Query {
    char t;
    union {
        struct {
            unsigned a;
            unsigned b;
            int d;
        };
        unsigned h;
    };
};

std::istream& operator >>(std::istream& input, Query& q)
{
    input >> q.t;
    if (q.t == 'I')
        input >> q.a >> q.b >> q.d;
    if (q.t == 'Q')
        input >> q.h;
    return input;
}

class SegmentTree {
    struct Node {
        const long long range_begin;
        const long long range_end;

        long long sum = 0;
        long long prefix = 0;

        std::optional<int> common_delta;

        Node* subnodes[2] = {};

        Node(unsigned range_begin, unsigned range_end)
            : range_begin(range_begin)
            , range_end(range_end)
        {}

        void update(int delta)
        {
            sum = int(range_end - range_begin) * delta;
            prefix = std::max(sum, 0ll);
            common_delta = delta;
        }

        void propagate_updates()
        {
            if (range_begin + 1 == range_end)
                return;

            if (common_delta) {
                subnodes[0]->update(*common_delta);
                subnodes[1]->update(*common_delta);
                common_delta = std::nullopt;
            }
        }

        void compose()
        {
            sum = subnodes[0]->sum + subnodes[1]->sum;
            prefix = std::max(subnodes[0]->prefix, subnodes[0]->sum + subnodes[1]->prefix);
        }
    };

public:
    explicit SegmentTree(unsigned size)
        : size_(size)
        , root_(0, size)
    {}

    void update(unsigned range_begin, unsigned range_end, int delta)
    {
        update(&root_, range_begin, range_end, delta);
    }

    unsigned search(unsigned height)
    {
        return root_.prefix <= height ? size_ : search(&root_, height);
    }

private:
    void update(Node* subtree, unsigned range_begin, unsigned range_end, int delta)
    {
        if (range_end <= subtree->range_begin || subtree->range_end <= range_begin)
            return;

        if (range_begin <= subtree->range_begin && subtree->range_end <= range_end) {
            subtree->update(delta);
            return;
        }

        const unsigned mid = (subtree->range_begin + subtree->range_end) / 2;

        if (subtree->subnodes[0] == nullptr)
            subtree->subnodes[0] = new Node(subtree->range_begin, mid);
        if (subtree->subnodes[1] == nullptr)
            subtree->subnodes[1] = new Node(mid, subtree->range_end);

        subtree->propagate_updates();

        update(subtree->subnodes[0], range_begin, range_end, delta);
        update(subtree->subnodes[1], range_begin, range_end, delta);
        subtree->compose();
    }

    unsigned search(Node* subtree, unsigned height)
    {
        if (subtree->range_begin + 1 == subtree->range_end)
            return subtree->range_begin;

        const unsigned mid = (subtree->range_begin + subtree->range_end) / 2;

        if (subtree->subnodes[0] == nullptr)
            subtree->subnodes[0] = new Node(subtree->range_begin, mid);
        if (subtree->subnodes[1] == nullptr)
            subtree->subnodes[1] = new Node(mid, subtree->range_end);

        subtree->propagate_updates();

        return subtree->subnodes[0]->prefix <= height ?
            search(subtree->subnodes[1], height - subtree->subnodes[0]->sum) : search(subtree->subnodes[0], height);
    }

private:
    const unsigned size_;

    Node root_;

}; // class SegmentTree

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n;
    std::cin >> n;

    SegmentTree st(n);

    Query q;
    for (std::cin >> q; q.t != 'E'; std::cin >> q) {
        if (q.t == 'I') {
            st.update(q.a-1, q.b, q.d);
        } else {
            std::cout << st.search(q.h) << '\n';
        }
    }

    return 0;
}
