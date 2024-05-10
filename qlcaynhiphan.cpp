#include <stdio.h>
#include <stdlib.h>

// Khai báo cấu trúc Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Khởi tạo một nút mới
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Thêm một phần tử vào cây
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Tìm một phần tử trong cây
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

// Xóa một nút trong cây
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }

        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Duyệt cây theo thứ tự NLR (preorder)
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Duyệt cây theo thứ tự LNR (inorder)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Duyệt cây theo thứ tự LRN (postorder)
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Hàm main để kiểm tra các thủ tục
int main() {
    struct Node* root = NULL;

    // Thêm các phần tử vào cây
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // In ra cây theo thứ tự LNR
    printf("Cay theo thu tu LNR: ");
    inorderTraversal(root);
    printf("\n");
// Tìm một phần tử trong cây
    int key = 40;
    struct Node* result = search(root, key);
    if (result != NULL) {
        printf("%d duoc tim thay trong cay.\n", key);
    } else {
        printf("%d khong duoc tim thay trong cay.\n", key);
    }

    // Xóa một phần tử trong cây và in ra kết quả
    printf("Xoa phan tu 20 trong cay...\n");
    root = deleteNode(root, 20);
    printf("Cay sau khi xoa: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}