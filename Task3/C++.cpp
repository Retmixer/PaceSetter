 //Сортировка выбором (Selection Sort) 

include <iostream>
#include <vector>
// Функция сортировки выбором
void selection_sort(std::vector<int>& arr) {
    // Проходим по всем элементам массива
    for (size_t i = 0; i < arr.size(); i++) {
        // Предполагаем, что первый элемент - минимальный
        size_t min_index = i;
        // Ищем минимальный элемент в оставшейся части массива
        for (size_t j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        // Меняем найденный минимальный элемент с первым элементом в неотсортированной части
        std::swap(arr[i], arr[min_index]);
    }
}
// Вспомогательная функция для вывода массива
void print_array(const std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i];
        if (i != arr.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

// Пример использования
int main() {
    // Создаем тестовый массив
    std::vector<int> test_array = {64, 25, 12, 22, 11};
    
    std::cout << "Исходный массив: ";
    print_array(test_array);
    
    // Сортируем массив
    selection_sort(test_array);
    
    std::cout << "Отсортированный массив: ";
    print_array(test_array);
    
    return 0;
}


//Сортировка вставками (Insertion Sort)
#include <iostream>
using namespace std;

// Метод для сортировки массива
void insertionSort(int array[], int n) {
    // Проходим по всем элементам массива, начиная со второго
    for (int i = 1; i < n; i++) {
        int key = array[i]; // Текущий элемент, который нужно вставить
        int j = i - 1; // Индекс предыдущего элемента

        // Перемещаем элементы array[0..i-1], которые больше key
        // на одну позицию вперед
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key; // Вставляем key на правильное место
    }
}

// Метод для вывода массива
void printArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// Основной метод для тестирования
int main() {
    int array[] = {12, 11, 13, 5, 6};
    int n = sizeof(array) / sizeof(array[0]);

    cout << "Исходный массив:" << endl;
    printArray(array, n);

    insertionSort(array, n);

    cout << "Отсортированный массив:" << endl;
    printArray(array, n);

    return 0;
}

//Сортировка слиянием (Merge Sort) 

#include <iostream>
#include <vector>
using namespace std;

// Функция для слияния двух отсортированных массивов
vector<int> merge(vector<int> left, vector<int> right) {
    vector<int> result;
    int i = 0, j = 0;
    
    // Пока есть элементы в обоих массивах
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            result.push_back(left[i]);
            i++;
        } else {
            result.push_back(right[j]);
            j++;
        }
    }
    
    // Добавляем оставшиеся элементы
    while (i < left.size()) {
        result.push_back(left[i]);
        i++;
    }
    
    while (j < right.size()) {
        result.push_back(right[j]);
        j++;
    }
    
    return result;
}

// Основная функция сортировки слиянием
vector<int> mergeSort(vector<int> arr) {
    // Базовый случай: массив длиной 0 или 1 уже отсортирован
    if (arr.size() <= 1) {
        return arr;
    }
    
    // Находим середину массива
    int mid = arr.size() / 2;
    
    // Делим массив на две части
    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());
    
    // Рекурсивно сортируем каждую часть
    left = mergeSort(left);
    right = mergeSort(right);
    
    // Сливаем отсортированные части
    return merge(left, right);
}

// Пример использования
int main() {
    vector<int> array = {38, 27, 43, 3, 9, 82, 10};
    
    cout << "Исходный массив: ";
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;
    
    vector<int> sortedArray = mergeSort(array);
    
    cout << "Отсортированный массив: ";
    for (int num : sortedArray) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}


//Быстрая сортировка (Quick Sort) 


#include <iostream>
#include <vector>
using namespace std;

// Метод для разбиения массива
int partition(vector<int>& array, int low, int high) {
    // Выбираем последний элемент в качестве опорного
    int pivot = array[high];
    int i = (low - 1); // Индекс меньшего элемента

    for (int j = low; j < high; j++) {
        // Если текущий элемент меньше или равен опорному
        if (array[j] <= pivot) {
            i++;

            // Поменять местами array[i] и array[j]
            swap(array[i], array[j]);
        }
    }

    // Поменять местами array[i+1] и array[high] (опорный элемент)
    swap(array[i + 1], array[high]);
    return i + 1;
}

// Метод для сортировки массива
void quickSort(vector<int>& array, int low, int high) {
    if (low < high) {
        // pi - это индекс разбиения, array[pi] находится на своем месте
        int pi = partition(array, low, high);

        // Отсортировать элементы до и после разбиения
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

// Вспомогательный метод для вывода массива
void printArray(const vector<int>& array) {
    for (int value : array) {
        cout << value << " ";
    }
    cout << endl;
}

// Основной метод для запуска сортировки
int main() {
    vector<int> array = {10, 7, 8, 9, 1, 5};

    cout << "Исходный массив:" << endl;
    printArray(array);

    quickSort(array, 0, array.size() - 1);

    cout << "Отсортированный массив:" << endl;
    printArray(array);

    return 0;
}

//Пирамидальная сортировка 

#include <iostream>
#include <vector>
using namespace std;

// Функция для преобразования поддерева в двоичную кучу
void heapify(vector<int>& arr, int n, int i) {
    int largest = i; // Инициализируем наибольший элемент как корень
    int left = 2 * i + 1; // левый = 2*i + 1
    int right = 2 * i + 2; // правый = 2*i + 2
    
    // Проверяем существует ли левый дочерний элемент больший, чем корень
    if (left < n && arr[i] < arr[left]) {
        largest = left;
    }
    
    // Проверяем существует ли правый дочерний элемент больший, чем корень
    if (right < n && arr[largest] < arr[right]) {
        largest = right;
    }
    
    // Меняем корень, если нужно
    if (largest != i) {
        swap(arr[i], arr[largest]); // своп
        
        // Применяем heapify к корню
        heapify(arr, n, largest);
    }
}

// Основная функция для пирамидальной сортировки
void heapSort(vector<int>& arr) {
    int n = arr.size();
    
    // Построение max-heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    
    // Один за другим извлекаем элементы
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]); // меняем корень с последним элементом
        heapify(arr, i, 0);
    }
}

// Пример использования:
int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    
    cout << "Исходный массив: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    heapSort(arr);
    
    cout << "Отсортированный массив: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
} 


//Интерполирующий поиск 

#include <iostream>
#include <vector>
using namespace std;

int interpolationSearch(vector<int>& arr, int lo, int hi, int x) {
    if (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
        // Вычисляем позицию с помощью интерполяционной формулы
        int pos = lo + (((hi - lo) * (x - arr[lo])) / (arr[hi] - arr[lo]));
        
        // Если элемент найден
        if (arr[pos] == x) {
            return pos;
        }
        
        // Если x больше, x находится в правом подмассиве
        if (arr[pos] < x) {
            return interpolationSearch(arr, pos + 1, hi, x);
        }
        
        // Если x меньше, x находится в левом подмассиве
        if (arr[pos] > x) {
            return interpolationSearch(arr, lo, pos - 1, x);
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47};
    int x = 18;
    
    int result = interpolationSearch(arr, 0, arr.size() - 1, x);
    
    if (result != -1) {
        cout << "Элемент найден на позиции: " << result << endl;
    } else {
        cout << "Элемент не найден" << endl;
    }
    
    return 0;
}
