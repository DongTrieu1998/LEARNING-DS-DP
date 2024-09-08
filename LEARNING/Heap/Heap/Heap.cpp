#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

#define MAX 100

//Tạo 1 vector random
std::vector<int> createVector() {
    std::srand(time(NULL));
    std::vector<int> vec;
    for (int i = 0; i < MAX; i++) {
        vec.push_back(std::rand() % 100);
    }
    return vec;
}

// Hàm đổi giá trị giữa hai biến
void swap(int &a, int &b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

// Tạo hàm heapify để sắp xếp lại vector (tạo max heap)
void heapify(std::vector<int> &vec, int index, int size) {
    //Assume chỉ số của giá trị largest là index 
    int largestIndex = index;
    int leftIndex = 2 * index + 1;
    int rightIndex = 2 * index + 2;

    /*
    Kiểm tra giá trị bên phải và trái của nút con với nút cha
    Nếu nút con lớn hơn nút cha thì gán giá trị largest cho nút con
    Cần kiểm tra điều kiện của các chỉ số con luôn nhỏ hơn size của mảng
    */
    if (leftIndex < size && vec[leftIndex] > vec[largestIndex]) {
        largestIndex = leftIndex;
    }
    if (rightIndex < size && vec[rightIndex] > vec[largestIndex]) {
        largestIndex = rightIndex;
    }

    //Đổi giá trị cho nút con và tiếp tục heapify để tìm giá trị lớn nhất
    if (largestIndex != index) {
        swap(vec[largestIndex], vec[index]);
        heapify(vec, largestIndex, size);
    }
}

//Hàm sort 
void heapSort(std::vector<int> &vec) {
    /*
    Để sort được chúng ta cần tạo 1 max heap.Max heap là 1 cấu trúc dạng tree mà các giá trị tại các
    nút cha luôn là lớn nhất
    Để tạo được max heap, chúng ta cần bắt đầu từ nút cha cuối cùng. Chỉ số của nút cha đó trong mảng 
    là (n/2 - 1)
    NOTE: last value n = 2i + 2 => i = n/2 -1
    */
    int size = vec.size();
    // Xây dựng max heap (tạo heap từ nửa mảng cuối)
    for (int i = size/2 - 1; i >= 0; i--) {
        heapify(vec, i, size);
    }

    // Trích xuất từng phần tử một từ heap
    for (int i = size - 1; i > 0; i--) {
        // Đưa phần tử lớn nhất (ở gốc) xuống cuối mảng
        swap(vec[0], vec[i]);
        // Heapify lại heap (loại trừ phần đã sắp xếp)
        heapify(vec, 0, i);
    }
}



int main()
{
    std::vector<int> vec = createVector();
    for (int val : vec)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    heapSort(vec);
    for (int val : vec)
    {
        std::cout << val << " ";
    }
}
