#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义结构体表示一本书的信息
typedef struct Book {
    char title[100];
    char author[100];
    int book_id;
    char quantity;	//book quantity
    struct Book *next;
} Book;

// 指向图书链表头节点的指针
Book *head = NULL;

// 函数声明
void addBook();
void searchBookById();
void searchBookByTitle();
void deleteBookById();
void displayAllBooks();

// 添加图书函数
void addBook() {
    Book *newBook = (Book *)malloc(sizeof(Book));
    if (newBook == NULL) {
        printf("内存分配失败！\n");
        return;
    }

    printf("请输入图书标题: ");
    scanf("%s", newBook->title);
    getchar();  // 吸收换行符

    printf("请输入图书作者: ");
    scanf("%s", newBook->author);
    getchar();

    printf("请输入图书编号: ");
    scanf("%d", &newBook->book_id);
    getchar();

    newBook->next = head;
    head = newBook;

    printf("图书添加成功！\n");
}

// 根据图书编号查询图书函数
void searchBookById() {
    int id;
    printf("请输入要查询的图书编号: ");
    scanf("%d", &id);
    getchar();

    Book *current = head;
    while (current!= NULL) {
        if (current->book_id == id) {
            printf("找到图书信息如下:\n");
            printf("标题: %s\n", current->title);
            printf("作者: %s\n", current->author);
            printf("编号: %d\n", current->book_id);
            return;
        }
        current = current->next;
    }

    printf("未找到对应编号的图书！\n");
}

// 根据图书标题查询图书函数
void searchBookByTitle() {
    char title[100];
    printf("请输入要查询的图书标题: ");
    scanf("%s", title);
    getchar();

    Book *current = head;
    while (current!= NULL) {
        if (strcmp(current->title, title) == 0) {
            printf("找到图书信息如下:\n");
            printf("标题: %s\n", current->title);
            printf("作者: %s\n", current->author);
            printf("编号: %d\n", current->book_id);
            return;
        }
        current = current->next;
    }

    printf("未找到对应标题的图书！\n");
}

// 根据图书编号删除图书函数
void deleteBookById() {
    int id;
    printf("请输入要删除的图书编号: ");
    scanf("%d", &id);
    getchar();

    Book *prev = NULL;
    Book *current = head;
    while (current!= NULL) {
        if (current->book_id == id) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("图书删除成功！\n");
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("未找到对应编号的图书，无法删除！\n");
}

// 显示所有图书信息函数
void displayAllBooks() {
    Book *current = head;
    if (current == NULL) {
        printf("当前没有图书记录！\n");
        return;
    }

    printf("所有图书信息如下:\n");
    while (current!= NULL) {
        printf("标题: %s\n", current->title);
        printf("作者: %s\n", current->author);
        printf("编号: %d\n", current->book_id);
        printf("-------------------\n");
        current = current->next;
    }
}

int main() {
    int choice;
    while (1) {
        printf("图书管理系统\n");
        printf("1. 添加图书\n");
        printf("2. 根据编号查询图书\n");
        printf("3. 根据标题查询图书\n");
        printf("4. 根据编号删除图书\n");
        printf("5. 显示所有图书\n");
        printf("6. 退出系统\n");
        printf("请输入你的选择: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                searchBookById();
                break;
            case 3:
                searchBookByTitle();
                break;
            case 4:
                deleteBookById();
                break;
            case 5:
                displayAllBooks();
                break;
            case 6:
                printf("感谢使用图书管理系统，已退出！\n");
                return 0;
            default:
                printf("输入无效，请重新输入！\n");
        }
    }

    return 0;
}
