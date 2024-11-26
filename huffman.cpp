#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void buildCodes(Node* root, string code, unordered_map<char, string>& huffmanCodes) {
    if (!root) return;
    if (!root->left && !root->right) huffmanCodes[root->ch] = code;
    buildCodes(root->left, code + "0", huffmanCodes);
    buildCodes(root->right, code + "1", huffmanCodes);
}

int main() {
    int n;
    cout << "Enter the number of characters: ";
    cin >> n;

    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (int i = 0; i < n; i++) {
        char ch;
        int freq;
        cout << "Enter character and frequency: ";
        cin >> ch >> freq;
        pq.push(new Node(ch, freq));
    }

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        pq.push(merged);
    }

    unordered_map<char, string> huffmanCodes;
    buildCodes(pq.top(), "", huffmanCodes);

    cout << "Huffman Codes:\n";
    for (auto& pair : huffmanCodes) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
