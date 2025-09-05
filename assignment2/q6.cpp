#include <iostream>
using namespace std;

struct Term {
    int row, col, val;
};

struct Sparse {
    int rows, cols, terms;
    Term data[100];
};

void readSparse(Sparse &s) {
    cin >> s.rows >> s.cols >> s.terms;
    for(int i = 0; i < s.terms; i++)
        cin >> s.data[i].row >> s.data[i].col >> s.data[i].val;
}

void printSparse(Sparse s) {
    for(int i = 0; i < s.terms; i++)
        cout << s.data[i].row << " " << s.data[i].col << " " << s.data[i].val << endl;
}

Sparse transpose(Sparse s) {
    Sparse t;
    t.rows = s.cols;
    t.cols = s.rows;
    t.terms = s.terms;
    int k = 0;
    for(int c = 0; c < s.cols; c++) {
        for(int i = 0; i < s.terms; i++) {
            if(s.data[i].col == c) {
                t.data[k].row = s.data[i].col;
                t.data[k].col = s.data[i].row;
                t.data[k].val = s.data[i].val;
                k++;
            }
        }
    }
    return t;
}

Sparse add(Sparse a, Sparse b) {
    Sparse c;
    if(a.rows != b.rows || a.cols != b.cols) {
        c.rows = c.cols = c.terms = 0;
        return c;
    }
    c.rows = a.rows; c.cols = a.cols;
    int i = 0, j = 0, k = 0;
    while(i < a.terms && j < b.terms) {
        if(a.data[i].row < b.data[j].row || 
          (a.data[i].row == b.data[j].row && a.data[i].col < b.data[j].col))
            c.data[k++] = a.data[i++];
        else if(b.data[j].row < a.data[i].row || 
               (b.data[j].row == a.data[i].row && b.data[j].col < a.data[i].col))
            c.data[k++] = b.data[j++];
        else {
            c.data[k] = a.data[i];
            c.data[k++].val = a.data[i++].val + b.data[j++].val;
        }
    }
    while(i < a.terms) c.data[k++] = a.data[i++];
    while(j < b.terms) c.data[k++] = b.data[j++];
    c.terms = k;
    return c;
}

Sparse multiply(Sparse a, Sparse b) {
    Sparse c;
    if(a.cols != b.rows) {
        c.rows = c.cols = c.terms = 0;
        return c;
    }
    c.rows = a.rows; c.cols = b.cols; c.terms = 0;
    Sparse bt = transpose(b);
    for(int i = 0; i < a.rows; i++) {
        for(int j = 0; j < b.cols; j++) {
            int sum = 0;
            for(int p = 0; p < a.terms; p++) {
                if(a.data[p].row == i) {
                    for(int q = 0; q < bt.terms; q++) {
                        if(bt.data[q].row == j && bt.data[q].col == a.data[p].col)
                            sum += a.data[p].val * bt.data[q].val;
                    }
                }
            }
            if(sum != 0) {
                c.data[c.terms].row = i;
                c.data[c.terms].col = j;
                c.data[c.terms].val = sum;
                c.terms++;
            }
        }
    }
    return c;
}

int main() {
    Sparse a, b;
    readSparse(a);
    readSparse(b);

    cout << "Transpose of first matrix:" << endl;
    printSparse(transpose(a));

    cout << "Addition of matrices:" << endl;
    printSparse(add(a, b));

    cout << "Multiplication of matrices:" << endl;
    printSparse(multiply(a, b));
}
