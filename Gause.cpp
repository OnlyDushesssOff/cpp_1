#include <random>
#include <iostream>
#include <clocale>
#include <iomanip>
#include <stdlib.h>

//функция вывода расширенной матрицы
void Show(double** matrix, int size, int vector, int number, int values){

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            std::cout<< std::setw(10)<<matrix[i][j] << " ";
        }
        std::cout << "|" << std::setw(10) << matrix[i][vector] << std::endl; 
    }
}
//функция вывода результатов вычисления
void Result(double** matrix, int size, int vector, int number, int values){
        int h = 0;
    while(h != 11*(size+1)){
        std::cout << "-"; 
        h+=1;       
    }
    std::cout << std::endl;
    for(int i = 0; i < size; i++){
        std::cout << std::setw(10)<<matrix[i][values]<< " ";
    }
    std::cout << std::endl;
}
//функция заполнения матрицы путем генерации псевдослучайных чисел
double** Computer_generation(double** matrix, int size, int vector, int number, int values){

    std::mt19937 gen;
    gen.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist;

    for(int i = 0; i < size; i++){
        matrix[i][vector] = dist(gen) % 10;
        for(int j = 0; j < size; j++){
            matrix[i][j] = dist(gen) % 10;
        }
    }
    Show(matrix, size, vector, number, values);
    return matrix;
}
//функция обратного хода работы 
double** behind_work(double** matrix, int size, int vector, int number, int values){
        for(int i = size-1; i>= 0; i--){
            for(int j = 0; j<size; j++){
                matrix[i][vector] -= matrix[j][values]*matrix[i][j];
            }
        matrix[i][values] = matrix[i][vector]/matrix[i][i];
        }
    Result(matrix, size, vector, number, values);
    return matrix;
}
//функция первого режима работы - упрощенный(если размер 7, то завершение из-за нуля)
double** Simplifed(double** matrix, int size, int vector, int number, int values){
    for(int i = 0; i<size-1; i++){
        double R = matrix[i][i];
        if(R == 0){
            std::cout << "The program has stopped. Reason for error: 0 on diagonal";
            exit(0);
        }
        else{
            matrix[i][vector] = matrix[i][vector]/R;
            for(int j = i; j < size; j++){
               matrix[i][j] = matrix[i][j]/R;
            }
            R = matrix[i+1][i]/matrix[i][i];
            for(int j = i; j<size;j++){
                matrix[i+1][j] = matrix[i+1][j] - matrix[i][j]*R;
            }
            for(int j = 0; j<=i;j++){
                matrix[i+1][j] = 0;
            }
        }
    }
    Show(matrix, size, vector, number, values);
    matrix = behind_work(matrix, size, vector, number, values);
    return matrix;
} 
//функция второго режима работы - перестановка
double** Permutation(double** matrix, int size, int vector, int number, int values){
    return NULL;
} 
//функция третьего режима работы - поиск максимума
double** Maximum(double** matrix, int size, int vector, int number, int values){
    return NULL;
} 
//функция прямого хода работы
double** forward_work(double** matrix, int size, int vector, int number, int values){
    int flag = 1;
    std::cout << "Select operating mode; 1 - simplified, 2 - permutation, 3 - maximum." << std::endl;
    std::cin >> flag;
    if(flag == 1){//первый режим работы - упрощенный
        matrix = Simplifed(matrix, size, vector, number, values);
    } 
    else if(flag == 2){//второй режим работы - перестановки
        matrix = Permutation(matrix, size, vector, number, values);
    }
    else if(flag == 3){//третий режим работы - поиск максимума
        matrix = Maximum(matrix, size, vector, number, values);
    }
    else{
        std::cout << "Input Error"<<std::endl;
        exit(0);
    }
}

int main(){
//задание размера матрицы
    int size = 0;
    std::cout << "Input your size of matrix: ";
    std::cin >> size;
    int vector = size;
    int number = size+1;
    int values = size+2;
//создание матрицы
    double** matrix = new double*[size];
    for(int i = 0; i < size; i++){
        matrix[i] = new double[values+1];
    }
    for(int i = 0; i < size; i++){
        matrix[i][values] = 0;
    }
// генерация маnрицы / пока машина, потом сделать развилку для машины или человека//
    matrix = Computer_generation(matrix, size, vector, number, values);
    matrix = forward_work(matrix, size, vector, number, values);
    std::cout << "Complete!";
}