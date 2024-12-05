#include <stdio.h>

int main() {
    int arr[100], n = 0, choice;
    do {
        printf("\nMenu:\n");
        printf("1. Nhap so phan tu và gia tri cho mang\n");
        printf("2. In ra gia tri các phan tu trong mang\n");
        printf("3. Dem so luong cac so hoan hao\n");
        printf("4. Tim gia tri lon nhat 2 trong mang\n");
        printf("5. Them mot phan tu vao vi tri bat ki\n");
        printf("6. Xoa phan tu tai mot vi tri bat ki\n");
        printf("7. Sap xep mang tang dan\n");
        printf("8. Tim kiem nhi phan mot gia tri\n");
        printf("9. Dao nguoc mang\n");
        printf("10. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                
                printf("Nhap so luong phan tu trong mang: ");
                scanf("%d", &n);
                int i=0
                for (i = 0; i < n; i++) {
                    printf("Nhap gia tri phan tu %d: ", i + 1);
                    scanf("%d", &arr[i]);
                }
                break;
            }
            case 2: {
                printf("Mang hien tai: ");
                int i=0
                for ( i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            }
            case 3: {
                int count = 0;
                int i=0
                for (i = 0; i < n; i++) {
                    int num = arr[i], sum = 0;
                    for (int j = 1; j < num; j++) {
                        if (num % j == 0) {
                            sum += j;
                        }
                    }
                    if (sum == num) {
                        count++;
                    }
                }
                printf("So luong so hoan hao: %d\n", count);
                break;
            }
            case 4: {
                if (n < 2) {
                    printf("Khong du phan tu de tim gia tri lon nhat 2\n");
                    break;
                }
                int first = -1, second = -1;
                int i=0
                for ( i = 0; i < n; i++) {
                    if (arr[i] > first) {
                        second = first;
                        first = arr[i];
                    } else if (arr[i] > second && arr[i] != first) {
                        second = arr[i];
                    }
                }
                printf("Gia tri lon nhat 2: %d\n", second);
                break;
            }
            case 5: {
                int value, pos;
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                printf("Nhap vi tri can them: ");
                scanf("%d", &pos);
                if (pos >= 0 && pos <= n) {
                	int i=0
                    for ( i = n; i > pos; i--) {
                        arr[i] = arr[i - 1];
                    }
                    arr[pos] = value;
                    n++;
                } else {
                    printf("Vi tri khong hop ly\n");
                }
                break;
            }
            case 6: {
                int pos;
                printf("Nhap vi tri can xoa: ");
                scanf("%d", &pos);
                if (pos >= 0 && pos < n) {
                	int i=0
                    for ( i = pos; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    n--;
                } else {
                    printf("Vi tri khong hop ly\n");
                }
                break;
            }
            case 7: {
                int i=0
                for ( i = 0; i < n - 1; i++) {
                    for (int j = i + 1; j < n; j++) {
                        if (arr[i] > arr[j]) {
                            int temp = arr[i];
                            arr[i] = arr[j];
                            arr[j] = temp;
                        }
                    }
                }
                printf("Mang khi duoc sap xep: ");
                int i=0
                for ( i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            }
            case 8: {
                int target;
                printf("Nhap gia tri can tim: ");
                scanf("%d", &target);
                int left = 0, right = n - 1, found = 0;
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (arr[mid] == target) {
                        printf("Gia tri %d tim thay toi vi tri %d\n", target, mid);
                        found = 1;
                        break;
                    } else if (arr[mid] < target) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                if (!found) {
                    printf("Khong tim thay gia tri %d\n", target);
                }
                break;
            }
            case 9: {
                int left = 0, right = n - 1;
                while (left < right) {
                    int temp = arr[left];
                    arr[left] = arr[right];
                    arr[right] = temp;
                    left++;
                    right--;
                }
                printf("Mang sau khi dao nguoc: ");
                int i= 0
                for ( i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            }
            case 10:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop li\n");
        }
    } while (choice != 10);

    return 0;
}
