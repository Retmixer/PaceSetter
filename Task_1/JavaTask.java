public class Main {
    public static void main(String[] args) {
        String str_1 = "AaBbCcDd";
        StringBuilder uppercaseStr = new StringBuilder();
        StringBuilder lowercaseStr = new StringBuilder();
        
        // Получаем заглавные буквы (четные индексы: 0, 2, 4, 6)
        for (int i = 0; i < str_1.length(); i += 2) {
            uppercaseStr.append(str_1.charAt(i));
        }
        
        // Получаем строчные буквы (нечетные индексы: 1, 3, 5, 7)
        for (int i = 1; i < str_1.length(); i += 2) {
            lowercaseStr.append(str_1.charAt(i));
        }
        
        // Выводим результаты
        System.out.println("Заглавные буквы: " + uppercaseStr.toString());
        System.out.println("Строчные буквы: " + lowercaseStr.toString());
    }
}


//Стеком

import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        List<String> li = new ArrayList<>();
        li.add("a");
        li.add("1");
        li.add("b");
        li.add("2");
        li.add("c");
        li.add("3");
        
        List<String> li_1 = new ArrayList<>(); // для букв
        List<String> li_2 = new ArrayList<>(); // для чисел
        
        // Разделяем список на буквы и числа
        for (int i = 0; i < li.size(); i++) {
            if (i % 2 == 0) {
                li_1.add(li.get(i)); // четные индексы - буквы
            } else {
                li_2.add(li.get(i)); // нечетные индексы - числа
            }
        }
        
        // Очищаем исходный список (аналог del li в Python)
        li.clear();
        
        // Выводим полученные списки
        System.out.println("Буквы: " + li_1);
        System.out.println();
        System.out.println("Числа: " + li_2);
    }
}

//Стеком №2

public class MyStack<T> {  
    private T stackArray;  
    private int top;  
    public MyStack(int capacity) {  
        stackArray = (T) new Object[capacity];  
        top = -1;  
    }  
    public void push(T item) {  
        if (top == stackArray.length - 1) {  
            throw new IllegalStateException("Stack overflow");  
        }  
        stackArray[++top] = item;  
    }  
    public T pop() {  
        if (top == -1) {  
            throw new IllegalStateException("Stack underflow");  
        }  
        return stackArray[top--];  
    }  
    public T peek() {  
        if (top == -1) {  
            throw new IllegalStateException("Stack is empty");  
        }  
        return stackArray[top];  
    }  
    public boolean isEmpty() {  
        return (top == -1);  
    }  
    public int size() {  
        return (top + 1);  
    }  
}  


