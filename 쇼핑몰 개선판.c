#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    int n = 5; // �⺻ ��ǰ ���� (Ȯ�� ����)
    int stock[MAX] = { 0 }, sales[MAX] = { 0 }, remain[MAX] = { 0 };
    char names[MAX][50];
    int choice;

    // �ʱ� ��ǰ�� �� ���ڿ��� ����
    for (int i = 0; i < n; i++) {
        strcpy(names[i], "�̵��");
    }

    while (1) {
        printf("\n[���θ� ���� ���α׷�]\n");
        printf("1. �԰�  2. �Ǹ�  3. ��ǰ��Ȳ  4. ��ǰ�� �Է�  5. ����\n");
        printf("�޴� ���� >> ");
        scanf("%d", &choice);

        if (choice == 1) {  // �԰�
            int mode;
            printf("�԰���� �Է� : ��ü��ǰ(1) / ������ǰ(2) ���� >> ");
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
                printf("��ǰID �Է�(1~%d) >> ", n);
                scanf("%d", &id);
                printf("�԰���� �Է� >> ");
                scanf("%d", &qty);
                stock[id - 1] += qty;
                remain[id - 1] = stock[id - 1] - sales[id - 1];
            }
        }

        else if (choice == 2) {  // �Ǹ�
            int mode;
            printf("�Ǹż��� �Է� : ��ü��ǰ(1) / ������ǰ(2) ���� >> ");
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
                printf("��ǰID �Է�(1~%d) >> ", n);
                scanf("%d", &id);
                printf("�Ǹż��� �Է� >> ");
                scanf("%d", &qty);
                sales[id - 1] += qty;
                remain[id - 1] = stock[id - 1] - sales[id - 1];
            }
        }

        else if (choice == 3) {  // ��ǰ��Ȳ
            int totalSales = 0, totalStock = 0;
            int maxSale = -1, minSale = 1e9, maxID = -1, minID = -1;

            printf("������ : ");
            for (int i = 0; i < n; i++) {
                printf("%d ", remain[i]);
                totalSales += sales[i];
                totalStock += stock[i];
                if (sales[i] > maxSale) { maxSale = sales[i]; maxID = i; }
                if (sales[i] < minSale) { minSale = sales[i]; minID = i; }
            }
            printf("\n�� �Ǹŷ� : %d (�Ǹ��� %.2f%%)\n",
                totalSales, totalStock ? (totalSales * 100.0 / totalStock) : 0);

            printf("���� ���� �Ǹŵ� ��ǰ : ID %d, �̸�:%s, �Ǹŷ� %d\n",
                maxID + 1, names[maxID], sales[maxID]);
            printf("���� ���� �Ǹŵ� ��ǰ : ID %d, �̸�:%s, �Ǹŷ� %d\n",
                minID + 1, names[minID], sales[minID]);

            for (int i = 0; i < n; i++) {
                if (remain[i] <= 2) {
                    printf("��ǰ ID %d (%s) : ������(%d)\n",
                        i + 1, names[i], remain[i]);
                }
            }
        }

        else if (choice == 4) {  // ��ǰ�� �Է�
            for (int i = 0; i < n; i++) {
                printf("ID %d ��ǰ�� : ", i + 1);
                scanf("%s", names[i]);
            }
        }

        else if (choice == 5) {  // ����
            printf("���α׷��� �����մϴ�.\n");
            break;
        }

        else {
            printf("�߸��� �Է��Դϴ�.\n");
        }
    }
    return 0;
}
