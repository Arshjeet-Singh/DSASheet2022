#include <iostream>
using namespace std;
long* productExceptSelf(int a[], int n)
{
    long prod = 1;
    long flag = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0)
            flag++;
        else
            prod *= a[i];
    }
    long* arr = new long[n];
    for (int i = 0; i < n; i++) {
        if (flag > 1) {
            arr[i] = 0;
        }
        else if (flag == 0)
            arr[i] = (prod / a[i]);
        else if (flag == 1 && a[i] != 0) {
            arr[i] = 0;
        }
        else
            arr[i] = prod;
    }
    return arr;
}
int main()
{
    int n = 5;
    int array[] = { 10, 3, 5, 6, 2 };
    long* ans;
    ans = productExceptSelf(array, n);
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
