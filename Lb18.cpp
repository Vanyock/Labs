#include <iostream>
#include <vector>

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double calculateArea() {
        return length * width;
    }

    bool isCube() {
        return length == width;
    }
};

int main() {
    int numRectangles;
    std::cout << "Введите количество прямоугольников: ";
    std::cin >> numRectangles;

    std::vector<Rectangle> rectangles;
    for (int i = 0; i < numRectangles; ++i) {
        double length, width;
        std::cout << "Введите длину и ширину прямоугольника " << i + 1 << ": ";
        std::cin >> length >> width;
        rectangles.push_back(Rectangle(length, width));
    }

    int countRectanglesAboveAverageArea = 0;
    int countCubes = 0;

    double totalArea = 0.0;
    for (Rectangle rectangle : rectangles) {
        totalArea += rectangle.calculateArea();
    }
    double averageArea = totalArea / rectangles.size();

    for (Rectangle rectangle : rectangles) {
        if (rectangle.calculateArea() > averageArea) {
            countRectanglesAboveAverageArea++;
        }
        if (rectangle.isCube()) {
            countCubes++;
        }
        std::cout << "Площадь прямоугольника: " << rectangle.calculateArea() << std::endl;
    }

    std::cout << "Количество прямоугольников с площадью выше средней: " << countRectanglesAboveAverageArea << std::endl;
    std::cout << "Количество кубов: " << countCubes << std::endl;

    return 0;
}

