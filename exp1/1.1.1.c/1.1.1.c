//Type your content here
#include <stdio.h>

int main() {
    int n, key, i, pos = -1;
    scanf("%d", &n);
    int arr[n];
    
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    scanf("%d", &key);
    
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            pos = i;
            break;
        }
    }
    
    if (pos != -1) {
        printf("found at position %d\n", pos);
    } else {
        printf("%d not found\n", key);
    }
    
    return 0;
}

