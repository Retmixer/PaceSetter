#Сортировка обменом (пузырьком) (Bubble Sort)

def bubble_sort(arr):
    n = len(arr)
    # Проходим по всем элементам массива
    for i in range(n-1):
        # Последний элемент на каждой итерации уже на своем месте
        for j in range(n-i-1):
            # Сравниваем соседние элементы
            if arr[j] > arr[j+1]:
                # Меняем местами, если они стоят в неправильном порядке
                arr[j], arr[j+1] = arr[j+1], arr[j]

def print_array(arr):
    for i in range(len(arr)):
        print(arr[i], end=" ")
    print()

# Пример использования
if __name__ == "__main__":
    arr = [64, 34, 25, 12, 22, 11, 90]
    
    print("Исходный массив:")
    print_array(arr)
    
    bubble_sort(arr)
    
    print("Отсортированный массив:")
    print_array(arr)



#Сортировка Шелла (Shellsort) 

def shell_sort(arr):
    n = len(arr)
    
    # Начинаем с большого промежутка и уменьшаем его
    gap = n // 2
    while gap > 0:
        # Проходим по всем элементам с текущим промежутком
        for i in range(gap, n):
            # Сохраняем текущий элемент
            temp = arr[i]
            j = i
            
            # Сдвигаем элементы, которые больше temp, вправо
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            
            # Вставляем temp на правильное место
            arr[j] = temp
        
        # Уменьшаем промежуток
        gap //= 2

# Функция для вывода массива
def print_array(arr):
    for num in arr:
        print(num, end=" ")
    print()

# Пример использования
if __name__ == "__main__":
    arr = [12, 34, 54, 2, 3]
    
    print("Исходный массив:", end=" ")
    print_array(arr)
    
    shell_sort(arr)
    
    print("Отсортированный массив:", end=" ")
    print_array(arr)



#Последовательный (линейный) поиск 

def linear_search(arr, target):
    # Проходим по всем элементам массива
    for i in range(len(arr)):
        # Если нашли искомый элемент
        if arr[i] == target:
            return i  # Возвращаем индекс найденного элемента
    return -1  # Возвращаем -1, если элемент не найден

def main():
    # Создаем массив
    array = [3, 5, 2, 7, 9, 1, 4]
    
    target = 7  # Искомое значение
    
    # Вызываем функцию поиска
    result = linear_search(array, target)
    
    # Выводим результат
    if result != -1:
        print(f"Элемент найден на позиции: {result}")
    else:
        print("Элемент не найден")

if __name__ == "__main__":
    main()



#Бинарный (двоичный, дихотомический) поиск 
def binary_search(array, target):
    left = 0  # Левая граница поиска
    right = len(array) - 1  # Правая граница поиска
    
    while left <= right:
        # Находим середину массива
        mid = left + (right - left) // 2
        
        # Проверяем средний элемент
        if array[mid] == target:
            return mid  # Элемент найден
        
        # Если искомый элемент меньше среднего
        if array[mid] > target:
            right = mid - 1  # Перемещаемся влево
        else:
            left = mid + 1  # Перемещаемся вправо
    
    return -1  # Элемент не найден

def main():
    sorted_array = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19]
    target = 7
    
    result = binary_search(sorted_array, target)
    
    if result != -1:
        print(f"Элемент найден на позиции: {result}")
    else:
        print("Элемент не найден")

if __name__ == "__main__":
    main()




#Поиск по Фибоначчи 
def fibonacci_search(arr, x):
    n = len(arr)
    
    # Находим наименьшее число Фибоначчи, большее или равное n
    fib_m2 = 0  # (m-2)'е число Фибоначчи
    fib_m1 = 1  # (m-1)'е число Фибоначчи
    fib_m = fib_m2 + fib_m1
    
    # Находим m такое, что F[m] >= n
    while fib_m < n:
        fib_m2 = fib_m1
        fib_m1 = fib_m
        fib_m = fib_m2 + fib_m1
    
    # Маркеры для элементов, которые не входят в массив
    offset = -1
    
    # Поиск
    while fib_m > 1:
        # Проверяем возможный индекс
        i = min(offset + fib_m2, n - 1)
        
        # Если x больше элемента, переходим к правому подмассиву
        if arr[i] < x:
            fib_m = fib_m1
            fib_m1 = fib_m2
            fib_m2 = fib_m - fib_m1
            offset = i
        # Если x меньше элемента, переходим к левому подмассиву
        elif arr[i] > x:
            fib_m = fib_m2
            fib_m1 = fib_m1 - fib_m2
            fib_m2 = fib_m - fib_m1
        # Элемент найден
        else:
            return i
    
    # Проверяем последний элемент
    if fib_m1 and offset + 1 < n and arr[offset + 1] == x:
        return offset + 1
    
    return -1  # Элемент не найден

def main():
    arr = [10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100]
    x = 85
    
    result = fibonacci_search(arr, x)
    
    if result != -1:
        print("Элемент найден на позиции: " + str(result))
    else:
        print("Элемент не найден")

if __name__ == "__main__":
    main()





