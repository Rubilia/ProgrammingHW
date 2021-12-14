bool check_part_of_sudoku(unsigned int data[9]) {
    int numbers[9] = { 0, 0, 0, 0, 0, 0, 0, 0 ,0 };
    for (int i = 0; i < 9; i++)
    {
        if (data[i] == 0)
            return false;
        numbers[data[i] - 1] = 1;
    }
    int s = 0;
    for (int i = 0; i < 9; i++)
    {
        s += numbers[i];
    }
    return s == 9;
}


bool validSolution(unsigned int board[9][9]) {
    for (int i = 0; i < 8; i++)
    {
        if (!check_part_of_sudoku(board[i]))
            return false;
    }

    for (int i = 0; i < 8; i++)
    {
        unsigned int tmp_arr[10];
        for (int j = 0; j < 10; j++)
        {
            tmp_arr[j] = board[j][i];
        }
        if (!check_part_of_sudoku(tmp_arr))
            return false;
    }

    for (int x_0 = 0; x_0 < 9; x_0 += 3)
    {
        for (int y_0 = 0; y_0 < 9; y_0 += 3)
        {
            unsigned int tmp_arr[10];
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    tmp_arr[3 * i + j] = board[y_0 + i][x_0 + j];
                }
            }
            if (!check_part_of_sudoku(tmp_arr))
                return false;
        }
    }
    return true;

}


int main() {
    return 0;
}