#include <bits/stdc++.h>
using namespace std;

float uValue(float u, int n) {
    float temp = u;
    for (int i = 1; i < n; i++) {
        temp = temp * (u - i);
    }
    return temp;
}

int factorial(int n) {
    int f = 1;
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}

int main() {
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;

    float dataPoints[n], diffTable[n][n];

    cout << "Enter the x values:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "] = ";
        cin >> dataPoints[i];
    }

    cout << "Enter the corresponding y values:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "y[" << i << "] = ";
        cin >> diffTable[i][0];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++)
            diffTable[j][i] = diffTable[j + 1][i - 1] - diffTable[j][i - 1];
    }

    cout << endl << "Forward Difference Table:" << endl;
    for (int i = 0; i < n; i++) {
        cout << setw(4) << dataPoints[i] << "\t";
        for (int j = 0; j < n - i; j++)
            cout << setw(4) << diffTable[i][j] << "\t";
        cout << endl;
    }

    float targetValue;
    cout << "Enter the value to interpolate at: ";
    cin >> targetValue;

    float result = diffTable[0][0];
    float u = (targetValue - dataPoints[0]) / (dataPoints[1] - dataPoints[0]);
    for (int i = 1; i < n; i++) {
        result = result + (uValue(u, i) * diffTable[0][i]) / factorial(i);
    }

    cout << "\nInterpolated value at " << targetValue << " is " << result << endl;
    return 0;
}