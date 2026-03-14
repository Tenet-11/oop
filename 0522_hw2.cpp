// 0522 HW2.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//


//--------------詳細註解版的BST

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 定義樹的節點，每個節點儲存一個數字，和它的左右子節點（指標）
struct TreeNode {
    int value;           // 這個節點的數值
    TreeNode* left;      // 指向「左子樹」的指標
    TreeNode* right;     // 指向「右子樹」的指標

    // 建構子：初始化節點的值，同時左右子節點先設為空指標
    TreeNode(int x) : value(x), left(nullptr), right(nullptr) {}
};

// 定義一棵二元搜尋樹
class BinaryTree {
private:
    TreeNode* root;  // root 是指向整棵樹根節點的指標

public:
    BinaryTree() : root(nullptr) {} // 一開始樹是空的，root 為 nullptr

    // 實際插入節點的遞迴函式，從 root 開始往下插入
    TreeNode* insert(TreeNode* node, int val) {
        // 如果目前節點是空的，代表可以在這邊插入新節點
        if (!node) return new TreeNode(val);  // new 會在 heap 中配置記憶體並回傳該位置的指標

        // 若要插入的值比目前節點小，就往左邊遞迴
        if (val < node->value) {
            node->left = insert(node->left, val);
            // node->left 是指向左子節點的指標，我們將它設為新的插入結果
        }
        else {
            // 否則插入右邊
            node->right = insert(node->right, val);
        }
        return node; // 回傳此層節點（因為有可能左右子樹更新）
    }

    // 遞迴搜尋某個值
    TreeNode* search(TreeNode* node, int val) {
        // 如果節點是空的，代表找不到
        if (node == nullptr) {
            cout << "The value is not in this binary search tree." << endl;
            return nullptr;
        }
        if (node->value == val) {
            return node; // 找到就回傳這個節點指標
        }
        // 繼續往左子樹或右子樹搜尋
        if (val < node->value)
            return search(node->left, val);
        else
            return search(node->right, val);
    }

    // 使用者用這個對外的 insert
    void insert(int val) {
        root = insert(root, val);
        // 注意：回傳的是新的 root 指標（如果整棵樹原本是空的）
    }

    // 使用者對外查詢的函式
    TreeNode* search(int val) {
        return search(root, val);  // 從 root 開始搜尋
    }
};

// 主程式
int main() {
    BinaryTree bst;
    vector<int> numbers;
    int number;

    cout << "Enter numbers: ";
    // 讀入第一行的數字（直到換行結束）
    while (cin >> number) {
        numbers.push_back(number);
        if (cin.peek() == '\n') break; // 如果下一個字元是換行就中止
    }
    cout << endl;

    // 把每個數字插入二元搜尋樹
    for (int n : numbers) {
        bst.insert(n);
    }

    // 重複讓使用者查詢節點，直到輸入 -1 為止
    while (true) {
        cout << "Find the number you want: ";
        int target;
        cin >> target;
        if (target == -1) break;  // -1 表示離開查詢

        TreeNode* node = bst.search(target);  // 回傳搜尋到的節點指標

        // 如果沒找到（指標是 nullptr），跳過印出
        if (!node) continue;

        // 印出左子節點
        cout << "left: ";
        if (node->left) {
            cout << node->left->value << " ";  // 使用指標取值
        }
        else {
            cout << "null ";
        }

        // 印出右子節點
        cout << "right: ";
        if (node->right) {
            cout << node->right->value << endl << endl;
        }
        else {
            cout << "null\n\n";
        }
    }

    return 0;
}

