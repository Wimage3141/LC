class Solution {
public:
    void diagonalFlip(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n - 1; i++) {
            int currLimit = n - 1 - i;
            for(int j = 0; j < currLimit; j++) {
                swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
            }
        }
    }
    void horizontalFlip(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n / 2; i++) {
            for(int j = 0; j < n; j++) {
                swap(matrix[i][j], matrix[n - 1- i][j]);
            }
        }
    }
    void printMatrix(const vector<vector<int>>& matrix) const {
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix.size(); j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    void rotateByNinetyDegree(vector<vector<int>>& matrix) {
        diagonalFlip(matrix);
        horizontalFlip(matrix);
    }
    void rotate(vector<vector<int>>& matrix) {
        rotateByNinetyDegree(matrix);
        printMatrix(matrix);
    }
};