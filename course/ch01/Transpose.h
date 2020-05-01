#ifndef _Matrix
#define _Matrix
struct MatrixElements;
typedef struct MatrixElements *Matrix;
Matrix Initialize();
void FreeMatrix(Matrix T);
void SetSize(Matrix T, int a, int b);
void SetMatrix(Matrix T, double *arr);
void Print(Matrix T);
void Transpose(Matrix T, Matrix M);
#endif