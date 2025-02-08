#include "Plotter.h"
using namespace std;

void runPlotterScript(istream& input) {
    bool isDraw = false;
    int x_0 = 0, y_0 = 0;
    int x_1, y_1;
    int x_basis, y_basis;
    string operation;
    PenStyle style = {1, "black"};

    while (!input.eof()) {
        input >> operation;
        if (operation == "PenDown") {
            isDraw = true;
        } else if (operation == "PenUP") {
            isDraw = false;
        } else if (operation == "MoveAbs") {
            input >> x_1 >> y_1;
            if (isDraw) {
                drawLine(x_0, y_0, x_1, y_1, style);
            }
            x_0 = x_1;
            y_0 = y_1;
        } else if (operation == "MoveRel") {
            input >> x_basis >> y_basis;
            x_1 = x_0 + x_basis;
            y_1 = y_0 + y_basis;

            if (isDraw) {
                drawLine(x_0, y_0, x_1, y_1, style);
            }
            x_0 = x_1;
            y_0 = y_1;
        } else if (operation == "PenColor") {
            input >> style.color;
        } else if (operation == "PenWidth") {
            input >> style.width;
        }
    }
}
