
#include <iostream>
#include <fstream>



//void array_fill(int** arr, int rows, std::ifstream& file) {
//
//};

void depth_parser(int* checked, int position, int**matrix, int rows) {
    checked[position] = 1;
    std::cout << position + 1 << " ";
    for (int i = 0; i < rows; i++) {
        if (matrix[position][i] == 1 && checked[i] == 0) {
            depth_parser(checked, i, matrix, rows);
        }
    }
}

void memory_cleaner(int** arr, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
}



int main()
{

    std::ifstream input_file;
    int rows;
    int ans;
    input_file.open("input.txt");
    if (input_file.is_open()) {
        input_file >> rows;
        int** arr = new int* [rows];
        for (int i = 0; i < rows; i++) {
            arr[i] = new int[rows];
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < rows; j++) {
                input_file >> arr[i][j];
                std::cout << arr[i][j];
            }
            std::cout << std::endl;
        }

        input_file.close();

        int* checked = new int[rows] {0};


        depth_parser(checked, 0, arr, rows);



        

    }
    else {
        std::cout << "Something wrong. Can't open file." << std::endl;
    };
}


