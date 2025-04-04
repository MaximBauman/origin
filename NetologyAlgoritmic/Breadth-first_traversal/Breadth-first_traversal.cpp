
#include <iostream>
#include <fstream>
#include <vector>




//void array_fill(int** arr, int rows, std::ifstream& file) {
//
//};

void breadthFirst_parser(int* visited, int** matrix, int rows, int start_position) {
    std::cout << "Order of bypass: ";
    int vertex; 
    visited[start_position - 1] = 1;

    std::vector<int> queue;
    queue.push_back(start_position - 1);

    while (queue.size() != 0) {
        vertex = queue.front();
        std::cout << vertex + 1 << " ";
        queue.erase(queue.begin());
        for (int i = 0; i < rows; i++) {
            if (matrix[vertex][i] == 1 && visited[i] == 0) {
                queue.push_back(i);
                visited[i] = 1;
            }
        }
    }
    std::cout << std::endl;
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

        int* visited = new int[rows] {0};

        do {
            std::cout << "There are 7 vertices in the column. Enter the number of the vertex from which the traversal will begin: ";
            std::cin >> ans;
            std::cout << std::endl;
            breadthFirst_parser(visited, arr, rows, ans);
            for (int i = 0; i < rows; i++) {
                visited[i] = 0;
            }
        } while (ans != -1);
        





    }
    else {
        std::cout << "Something wrong. Can't open file." << std::endl;
    };
}


