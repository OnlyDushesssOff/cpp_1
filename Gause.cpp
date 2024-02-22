#include <random>
#include <iostream>
#include <clocale>
#include <iomanip>
#include <stdlib.h>

//функция вывода расширенной матрицы
void Show(double** matrix, int size, int vector, int highe, int weght){

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(i == highe && j == weght){
                std::cout<<">>> "<< std::setw(6)<<matrix[i][j]<< " ";
            }
            else{
                std::cout<< std::setw(10)<<matrix[i][j]<< " ";
            }
        }
        if(i == highe && vector == weght){
            std::cout << "|" << std::setw(10) <<">>"<< matrix[i][vector] << std::endl; 
        }
        else{
            std::cout << "|" << std::setw(10) << matrix[i][vector] << std::endl;             
        }
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
    for(int b = 0; b< size; b++){
        std::cout << std::setw(9)<<"x"<<matrix[b][number]+1<< " ";
    }
    std::cout << std::endl;
    for(int i = 0; i < size; i++){
        int ans = 0;
        for(int h = 0; h < size; h++){
            if(matrix[h][number] = i){
                ans = h;
            }
        }
        std::cout << std::setw(10)<<matrix[ans][values]<< " ";
    }
    std::cout << std::endl;
}
//функция заполнения матрицы путем генерации псевдослучайных чисел
double** Person_generation(double** matrix, int size, int vector){
    char aboba = 0;
    double znach = 0;
    int hight1 = 0;
    int hight2 = hight1;
    int weght1 = 0;
    int weght2 = weght1;
    while(aboba != 1){
        Show(matrix, size, vector, hight2, weght2);
        std::cout << "select the cell whose value you will change:"<<std::endl<<" D - Right, A - Left, S - Down, W - Up, R - save and activate, P - exit from programm"<<std::endl;
        std::cin >> aboba;
        if(aboba == 68 || aboba == 100 || aboba ==65 || aboba ==97 || aboba ==115 ||aboba == 83 || aboba == 87|| aboba ==119 || aboba ==82 || aboba ==114 ||aboba == 80 || aboba == 112){
            switch(aboba){
                case 68: weght2 += 1;break;
                case 100: weght2 += 1;break;
                case 65: weght2 -= 1;break;
                case 97: weght2 -= 1;break;
                case 115: hight2 -= 1;break;
                case 83: hight2 -= 1;break;
                case 87: hight2 += 1;break;
                case 119: hight2 += 1;break;
                case 82: aboba = 1;break;
                case 114: aboba = 1;break;
                case 80: exit(1);break;
                case 112: exit(1);break;
            } 
            Show(matrix, size, vector, hight2, weght2);  
        }else{
            std::cout<<"input error: you entered an invalid command"<<std::endl;
            Show(matrix, size, vector, hight1, weght1);
        }
        if(aboba == 1){
            return matrix;
        }
        if(aboba == 68 || aboba == 100 || aboba ==65 || aboba ==97 || aboba ==115 ||aboba == 83 || aboba == 87|| aboba ==119){
            std::cout << "Do you want to change the value of the current cell or do you want to leave it the same?" << std::endl<<"Y - yes, N - no"<<std::endl;
            std::cin >> aboba;
            if(aboba == 121 || aboba == 89 || aboba ==78 || aboba == 110){
                switch(aboba){
                    case 121:{
                        std::cout << "Enter new value" << std::endl;
                        std::cin >> znach;
                        break;
                    }
                    case 89:{
                        std::cout << "Enter new value" << std::endl;
                        std::cin >> znach;
                        break;
                    }
                    case 78:break;
                    case 110:break;
                }
            }
            else{
                std::cout<<"input error: you entered an invalid command"<<std::endl;
                Show(matrix, size, vector, hight2, weght2);
            }
            if(hight2 < 0 || hight2 >= size || weght2 < 0 || weght2 >= size+1){
                std::cout<< "input error: you are out of matrix"<<std::endl;
                Show(matrix, size, vector, hight1, weght1);
            }
            else{
                matrix[hight2][weght2] = znach;
                hight1 = hight2;
                weght1 = weght2;
            }
        aboba = 0;
        }
    }
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
    Show(matrix, size, vector, 1000, 1000);
    return matrix;
}
//функция перестановки столбцов
double** Replace(double** matrix, int size, int i, int j, int number, int values){
    double vec = 0;
    for(int h = 0; h < size; h++){
        vec = matrix[h][i];
        matrix[h][i] = matrix[h][j];
        matrix[h][j] = vec;
    }
    double num = matrix[i][number];
    matrix[i][number] = matrix[j][number];
    matrix[j][number] = num;
    double val = matrix[i][values];
    matrix[i][values] = matrix[j][values];
    matrix[j][values] = val;
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
//функция первого режима работы - упрощенный
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
            matrix[i+1][vector] = matrix[i+1][vector] - matrix[i][vector]*R;
            for(int j = 0; j<=i;j++){
                matrix[i+1][j] = 0;
            }
        }
    }
    Show(matrix, size, vector, 1000,1000);
    matrix = behind_work(matrix, size, vector, number, values);
    return matrix;
} 
//функция второго режима работы - перестановка
double** Permutation(double** matrix, int size, int vector, int number, int values){
        for(int i = 0; i<size-1; i++){
        double R = matrix[i][i];
        if(R == 0){
            for(int j = i; j < size; j++){
                if(matrix[i][j] != 0){
                    matrix = Replace(matrix, size, i, j, number, values);
                    break;
                }
            }
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
            matrix[i+1][vector] = matrix[i+1][vector] - matrix[i][vector]*R;
            for(int j = 0; j<=i;j++){
                matrix[i+1][j] = 0;
            }
        }
    }
    Show(matrix, size, vector, 1000,1000);
    matrix = behind_work(matrix, size, vector, number, values);
    return matrix;
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
    return matrix;
}

int main(){
//задание размера матрицы
    int size = 0;
    std::cout << "Input your size of matrix: ";
    std::cin >> size;
    int vector = size;
    int number = size+1;
    int values = size+2;
    char mod = 0;
//создание матрицы
    double** matrix = new double*[size];
    for(int i = 0; i < size; i++){
        matrix[i] = new double[values+1];
    }
    for(int i = 0; i < size; i++){
        matrix[i][values] = 0;
        matrix[i][number] = i;
    }
    std::cout << "select matrix generation mode: P - human, C - computer"<<std::endl;
    std::cin >> mod;
    if(mod ==112 || mod == 80){
        matrix = Person_generation(matrix, size, vector);
    }else if(mod == 67 || mod == 99){
        matrix = Computer_generation(matrix, size, vector, number, values);
    }else{
        std::cout<<"input error: you entered an invalid command"<<std::endl;
        return 0;
    }
    matrix = forward_work(matrix, size, vector, number, values);
    std::cout << "Complete!";
}
