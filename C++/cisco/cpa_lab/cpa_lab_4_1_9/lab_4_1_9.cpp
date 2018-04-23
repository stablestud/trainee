#include <iostream>

// class StudentClasses {
// private:
//         static int classNumber;
//         int* grades;
//         int numberOfGrades;
//         float total;
// public:
//         StudentClasses ( void )
//         {
//                 numberOfGrades = 0;
//                 total = 0;
//                 classNumber++;
//                 std::cout << "Number of grades and then the gained grades" << std::endl;
//                 std::cin >> numberOfGrades;
//                 grades = new int [numberOfGrades];
//                 for ( int i = 0; i < numberOfGrades; i++ )
//                         std::cin >> grades[i];
//                 std::cout << "Enough! (" << classNumber << ")" << std::endl;
//         }
//         ~StudentClasses ( void )
//         {
//                 std::cout << "\nCourse: " << classNumber-- << " final: ";
//                 std::cout << total / numberOfGrades << " Grades: ";
//                 for ( int i = 0; i < numberOfGrades; i++)
//                         std::cout << " " << grades[i];
//                 delete[] grades;
//                 std::cout << std::endl;
//         }
//         int finalGrade ( void )
//         {
//                 for ( int i = 0; i < numberOfGrades; i++)
//                         total += grades[i];
//                 return total;
//         }
//         int callNumbrofGrades ( void )
//         {
//                 return numberOfGrades;
//         }
// };
//
// int StudentClasses::classNumber = 0;

int main ( void )
{
//         int numberOfClasses;
//         std::cout << "Number of classes: ";
//         std::cin >> numberOfClasses;
//         StudentClasses student[numberOfClasses];
//         int total = 0;
//         float total_numbr_grades = 0;
//         //for ( int i = 0; i < numberOfClasses; i++)
//         std::cout << std::endl;
//         for ( int i = 0; i < numberOfClasses; i++) {
//                 total += student[i].finalGrade();
//                 total_numbr_grades += student[i].callNumbrofGrades();
//         }
//         std:: cout << "Final Grade: " << total / total_numbr_grades << std::endl;
//         return 0;

        int totalClasses;
        int** containerClasses = nullptr;

        std::cout << "Please Input number of taken classes: ";
        std::cin >> totalClasses;

        containerClasses = new int* [totalClasses];

        for ( int i = 0; i < totalClasses; i++ ) {
                int totalGradesPerClass;

                std::cout << i + 1 << " class: ";
                std::cin >> totalGradesPerClass;

                containerClasses[i] = new int [totalGradesPerClass + 2];
                containerClasses[i][0] = totalGradesPerClass;

                containerClasses[i][1] = 0;

                for ( int j = 0; j < totalGradesPerClass; j++ )
                        std::cin >> containerClasses[i][j + 2];
        }
        std::cout << "Saved!" << std::endl;

        for ( int i = 0; i < totalClasses; i++ ) {
                std::cout << "Class: " << i + 1 << ", ";

                /* Saves the total of the grades in the class */
                for ( int j = 0; j < containerClasses[i][0]; j++ )
                        containerClasses[i][1] += containerClasses[i][j + 2];

                std::cout << "Final: " << static_cast<float> ( containerClasses[i][1] ) / containerClasses[i][0] << ", ";

                std::cout << "Grades: ";
                for ( int j = 0; j < containerClasses[i][0]; j++ )
                        std::cout << containerClasses[i][j + 2] << " ";

                std::cout << std::endl;

        }

        std::cout << std::endl;

        int finalGrade = 0;
        int totalGrades = 0;

        std::cout << "Final Grade: ";
        for ( int i = 0; i < totalClasses; i++) {
                totalGrades += containerClasses[i][0];
                finalGrade += containerClasses[i][1];
        }

        std::cout << static_cast<float> ( finalGrade ) / totalGrades << std::endl;
}
