#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    int n = 5; // 기본 상품 개수 (확장 가능)
    int stock[MAX] = { 0 }, sales[MAX] = { 0 }, remain[MAX] = { 0 };
    char names[MAX][50];
    int choice;

    // 초기 상품명 빈 문자열로 설정
    for (int i = 0; i < n; i++) {
        strcpy(names[i], "미등록");
    }

    while (1) {
        printf("\n[쇼핑몰 관리 프로그램]\n");
        printf("1. 입고  2. 판매  3. 상품현황  4. 상품명 입력  5. 종료\n");
        printf("메뉴 선택 >> ");
        scanf("%d", &choice);

        if (choice == 1) {  // 입고
            int mode;
            printf("입고수량 입력 : 전체상품(1) / 개별상품(2) 선택 >> ");
            scanf("%d", &mode);
            if (mode == 1) {
                for (int i = 0; i < n; i++) {
                    int qty;
                    scanf("%d", &qty);
                    stock[i] += qty;
                    remain[i] = stock[i] - sales[i];
                }
            }
            else {
                int id, qty;
                printf("상품ID 입력(1~%d) >> ", n);
                scanf("%d", &id);
                printf("입고수량 입력 >> ");
                scanf("%d", &qty);
                stock[id - 1] += qty;
                remain[id - 1] = stock[id - 1] - sales[id - 1];
            }
        }

        else if (choice == 2) {  // 판매
            int mode;
            printf("판매수량 입력 : 전체상품(1) / 개별상품(2) 선택 >> ");
            scanf("%d", &mode);
            if (mode == 1) {
                for (int i = 0; i < n; i++) {
                    int qty;
                    scanf("%d", &qty);
                    sales[i] += qty;
                    remain[i] = stock[i] - sales[i];
                }
            }
            else {
                int id, qty;
                printf("상품ID 입력(1~%d) >> ", n);
                scanf("%d", &id);
                printf("판매수량 입력 >> ");
                scanf("%d", &qty);
                sales[id - 1] += qty;
                remain[id - 1] = stock[id - 1] - sales[id - 1];
            }
        }

        else if (choice == 3) {  // 상품현황
            int totalSales = 0, totalStock = 0;
            int maxSale = -1, minSale = 1e9, maxID = -1, minID = -1;

            printf("재고수량 : ");
            for (int i = 0; i < n; i++) {
                printf("%d ", remain[i]);
                totalSales += sales[i];
                totalStock += stock[i];
                if (sales[i] > maxSale) { maxSale = sales[i]; maxID = i; }
                if (sales[i] < minSale) { minSale = sales[i]; minID = i; }
            }
            printf("\n총 판매량 : %d (판매율 %.2f%%)\n",
                totalSales, totalStock ? (totalSales * 100.0 / totalStock) : 0);

            printf("가장 많이 판매된 상품 : ID %d, 이름:%s, 판매량 %d\n",
                maxID + 1, names[maxID], sales[maxID]);
            printf("가장 적게 판매된 상품 : ID %d, 이름:%s, 판매량 %d\n",
                minID + 1, names[minID], sales[minID]);

            for (int i = 0; i < n; i++) {
                if (remain[i] <= 2) {
                    printf("상품 ID %d (%s) : 재고부족(%d)\n",
                        i + 1, names[i], remain[i]);
                }
            }
        }

        else if (choice == 4) {  // 상품명 입력
            for (int i = 0; i < n; i++) {
                printf("ID %d 상품명 : ", i + 1);
                scanf("%s", names[i]);
            }
        }

        else if (choice == 5) {  // 종료
            printf("프로그램을 종료합니다.\n");
            break;
        }

        else {
            printf("잘못된 입력입니다.\n");
        }
    }
    return 0;
}
