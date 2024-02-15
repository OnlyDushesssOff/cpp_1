/*cmake_minimum_required(VERSION 3.8)


project(
	CPlusBestC
	LANGUAGES CXX)
	
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_executable(main main.cpp)
*/
#include <iostream>
#include <random>
#include <algorithm>

struct WintVeryBigName{
    int a = 0;
};

inline double MySqr(double a) { // inline делает функцию быстрее за счет того, что используется внутренноси этой функции и подставляют их в код
    return a*a;
}

double Sum(double a, double b = 10){//можно значения переменных задавать прямо в создании функции
    return a+b;
}
// Тип данныъх "Перечисление"
enum BluetoothState{connected, disconnected, connecting, disconnecting, ctotoehe};
// в с++ работет полиморфизм функций - можно создавать функции, которые называются одинакого(но нужно, чтобы результат они выводили один и тот же)
double Divide(double a, double b){
    return a/b;
}
double Divide(int a, int b){
    int res = a/b;
    return res;
}
// шаблонные функции
template<typename T, typename F>// позволяет под Т задавать любые виды данных
double DivideTemplate(T a, T b, F c){// но нужно учесть, что первые 2 переменные должны иметь одинаковый тип данных
    return a/b;
}

int main(){

    auto myStruct = WintVeryBigName();

    int a = myStruct.a;

    double res1 = MySqr(10);
    double res2 = 10*10;

    double res3 = Sum(5);
    double res4 = Sum(5, 20);
    bool isFlag = true;// переменая логики(имеет всего 2 значения; True и False)

    //массивы
    int* arr = new int[100];
    for (int i = 0; i<100; i++){
        arr[i] = i;
    }
    delete [] arr;
    int s = arr[0]; // нельзя использовать массив после его удаления, иначе БАН!!!

    const int b = 10;

    const int* const pointer_b = &b; //первая константа(перед int*) не позволяет менять значение, на которое показывает указатель
                                     //вторая константа(после int*) не позволяет менять адрес указатель
                                     //при этом хранить адрес на константу может только указатель с константой в начале
    
    double base_val = 100.0;
    int target_val = static_cast<int>(base_val); // теперь менять тип данных меняется с помощью этой новой функции

    double res_div = Divide(10.0, 10.0);
    int res_div_int = Divide(10,10);

    double res_template = DivideTemplate(10, 10, 'd'); // пример шаблонной функции

    BluetoothState currentBluetoothState = BluetoothState::connected;
    switch (currentBluetoothState){
        case BluetoothState::connected:
            std::cout << "Device connected" <<std::endl;
            break;
        case BluetoothState::disconnected:
            std::cout << "Device connected" <<std::endl;
            break;
        case BluetoothState::connecting:
            std::cout << "Device connected" <<std::endl;
            break;
        case BluetoothState::disconnecting:
            std::cout << "Device connected" <<std::endl;
            break;
        case BluetoothState::ctotoehe:
            std::cout << "Device connected" <<std::endl;
            break;
    }
    //создание двумерного масива
    int** matrix = new int*[5];//создаем массив из каких-то(не заданных) элементов
    for(int i = 0; i < 5; i++){//его заполнение
        matrix[i] = new int[10];
    }
    for(int i = 0; i < 5; i++){//его удаление
        delete [] matrix[i];
    }
    delete [] matrix;

    std::mt19937 gen;
    gen.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist;

    std::cout << dist(gen) << std::endl;

    //std::cin >> a; //ввод значния переменной

    std::cout << a << std::endl; //вывод значения переменной, std::endl используется для перехода на следующую строку

    return 0;
}
