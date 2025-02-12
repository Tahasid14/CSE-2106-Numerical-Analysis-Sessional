#include <bits/stdc++.h>
using namespace std;

float uValue(float u, int n) {
    float temp = u;
    for (int i = 1; i < n; i++) {
        temp = temp * (u + i);
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
        for (int j = n - 1; j >= i; j--)
            diffTable[j][i] = diffTable[j][i - 1] - diffTable[j - 1][i - 1];
    }

    cout << endl << "Backward Difference Table:" << endl;
    for (int i = 0; i < n; i++) {
        cout << setw(4) << dataPoints[i] << "\t";
        for (int j = 0; j < n - i; j++)
            cout << setw(4) << diffTable[i][j] << "\t";
        cout << endl;
    }

    float targetValue;
    cout << "Enter the value to interpolate at: ";
    cin >> targetValue;

    float result = diffTable[n-1][0];
    float u = (targetValue - dataPoints[n-1]) / (dataPoints[n-1] - dataPoints[n-2]);
    for (int i = 1; i < n; i++) {
        result = result + (uValue(u, i) * diffTable[n-1][i]) / factorial(i);
    }

    cout << "\nInterpolated value at " << targetValue << " is " << result << endl;
    return 0;
}