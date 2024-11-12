#include <stdio.h>

int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int max_area = 0;

    while (left < right) {
        int h = (height[left] < height[right]) ? height[left] : height[right];
        int width = right - left;
        int current_area = h * width;

        if (current_area > max_area) {
            max_area = current_area;
        }//if

        if (height[left] < height[right]) {
            left++;
        }//if 
        else {
            right--;
        }//else
    }//while

    return max_area;
}//max_area

int main() {
    int height[] = {9, 8, 6, 2, 5, 4, 8, 3, 7};
    int heightSize = sizeof(height) / sizeof(height[0]);
    int result = maxArea(height, heightSize);
    
    printf("La máxima cantidad de agua que se puede contener es: %d\n", result);

    return 0;
}
