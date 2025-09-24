#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Node {
public:
    char cymbol;
    set<Node> childs = {};

    bool operator<(const Node& other) const {
        return cymbol < other.cymbol;
    }
};

class Treis {
private:
    int cntNodes = 0;
    set<Node> nodes = {};

public:
    void add(string phone) {
        set<Node>* curNode = &nodes;
        for (char d : phone) {
            bool found = false;
            for (const Node& n : *curNode) {
                if (n.cymbol == d) {
                    curNode = (set<Node>*)&n.childs;;
                    found = true;
                    break;
                }
            }
            if (found)
                continue;
            Node newN;
            newN.cymbol = d;
            curNode->insert(newN);
            cntNodes++;
            for (const Node& n : *curNode) {
                if (n.cymbol == d) {
                    curNode = (set<Node>*)&n.childs;
                    break;
                }
            }
        }
    }

    int get_cnt() {
        return cntNodes;
    }
};

int main()
{
    int n;
    cin >> n; cin.ignore();
    Treis tree;
    for (int i = 0; i < n; i++) {
        string telephone;
        cin >> telephone; cin.ignore();
        tree.add(telephone);
    }

    cout << tree.get_cnt() << endl;

    return 0;
}
