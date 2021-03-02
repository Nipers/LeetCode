  
#include<iostream>
using namespace std;
int table[7][1000] = {{}}, choice[1000] = {}, step = 1, fail[7][1000] = {{}}, size = 0;
bool move(int c) {//该选择能不能走
    int chosen[7] = {};//是否有改动，无改动则继承上一步的值
    switch (c) {
        case 1:// 0 -> 1
            if (table[1][step - 1] == 8 || table[0][step - 1] == 8 || table[0][step - 1] == 0|| table[1][step - 1] == 0)
                return false;
            chosen[0] = chosen[1] = 1;
            table[1][step] = table[0][step - 1] + table[1][step - 1];
            if (table[1][step] > 8) {
                table[0][step] = table[1][step] - 8;
                table[1][step] = 8;
            }
            else 
                table[0][step] = 0;
            break;
        case 2:// 0 -> 2
            if (table[0][step - 1] == 0 || table[2][step - 1] >= 3)
                return false;
            chosen[0] = chosen[2] = 1;
            table[2][step] = table[0][step - 1] + table[2][step - 1];
            if (table[2][step] > 3) {
                table[0][step] = table[2][step] - 3;
                table[2][step] = 3;
            }
            else 
                table[0][step] = 0;
            break;
        case 3:// 1 -> 0
            if (table[0][step - 1] == 8 || table[1][step - 1] == 8 || table[1][step - 1] == 0|| table[0][step - 1] == 0)
                return false;
            chosen[0] = chosen[1] = 1;
            table[0][step] = table[0][step - 1] + table[1][step - 1];
            if (table[0][step] > 8) {
                table[1][step] = table[0][step] - 8;
                table[0][step] = 8;
            }
            else 
                table[1][step] = 0;
            break;
        case 4:// 1 -> 2
            if (table[1][step - 1] == 0 || table[2][step - 1] >= 3)
                return false;
            chosen[2] = chosen[1] = 1;
            table[2][step] = table[1][step - 1] + table[2][step - 1];
            if (table[2][step] > 3) {
                table[1][step] = table[2][step] - 3;
                table[2][step] = 3;
            }
            else 
                table[1][step] = 0;
            break;
        case 5:// 2 -> 0
            if (table[2][step - 1] == 0 || table[0][step - 1] >= 8)
                return false;
            chosen[0] = chosen[2] = 1;
            table[0][step] = table[0][step - 1] + table[2][step - 1];
            if (table[0][step] > 8) {
                table[2][step] = table[0][step] - 8;
                table[0][step] = 8;
            }
            else 
                table[2][step] = 0;
            break;
        case 6: // 2 -> 1
            if (table[2][step - 1] == 0 || table[1][step - 1] >= 8)
                return false;
            chosen[2] = chosen[1] = 1;
            table[1][step] = table[1][step - 1] + table[2][step - 1];
            if (table[1][step] > 8) {
                table[2][step] = table[1][step] - 8;
                table[1][step] = 8;
            }
            else 
                table[2][step] = 0;
            break;
        case 7: // 0 -> 3
            if (table[0][step - 1] + table[3][step - 1] > 4 || table[0][step - 1] == 0)
                return false;
            chosen[0] = chosen[3] = 1;
            table[3][step] = table[0][step - 1] + table[3][step - 1];
            table[0][step] = 0;                                    
            break;
        case 8:// 0 -> 4
            if (table[0][step - 1] + table[4][step - 1] > 4 || table[0][step - 1] == 0)
                return false;
            chosen[0] = chosen[4] = 1;
            table[4][step] = table[0][step - 1] + table[4][step - 1];
            table[0][step] = 0;                                    
            break;
        case 9:// 0 -> 5
            if (table[0][step - 1] + table[5][step - 1] > 4 || table[0][step - 1] == 0)
                return false;
            chosen[0] = chosen[5] = 1;
            table[5][step] = table[0][step - 1] + table[5][step - 1];
            table[0][step] = 0;                                    
            break;
        case 10:// 0 -> 6
            if (table[0][step - 1] + table[6][step - 1] > 4 || table[0][step - 1] == 0)
                return false;
            chosen[0] = chosen[6] = 1;
            table[6][step] = table[0][step - 1] + table[6][step - 1];  
            table[0][step] = 0;                                              
            break;
        case 11:// 1 -> 3
            if (table[1][step - 1] + table[3][step - 1] > 4 || table[1][step - 1] == 0)
                return false;
            chosen[1] = chosen[3] = 1;
            table[3][step] = table[1][step - 1] + table[3][step - 1];
            table[1][step] = 0;                                    
            break;
        case 12:// 1 -> 4
            if (table[1][step - 1] + table[4][step - 1] > 4 || table[1][step - 1] == 0)
                return false;
            chosen[1] = chosen[4] = 1;
            table[4][step] = table[1][step - 1] + table[4][step - 1];
            table[1][step] = 0;                                    
            break;
        case 13:// 1 -> 5
            if (table[1][step - 1] + table[5][step - 1] > 4 || table[1][step - 1] == 0)
                return false;
            chosen[1] = chosen[5] = 1;
            table[5][step] = table[1][step - 1] + table[5][step - 1]; 
            table[1][step] = 0;                                               
            break;
        case 14:// 1 -> 6
            if (table[1][step - 1] + table[6][step - 1] > 4 || table[1][step - 1] == 0)
                return false;
            chosen[1] = chosen[6] = 1;
            table[6][step] = table[1][step - 1] + table[6][step - 1];  
            table[1][step] = 0;                                    
            break;
        case 15:// 2 -> 3
            if (table[2][step - 1] + table[3][step - 1] > 4 || table[2][step - 1] == 0)
                return false;
            chosen[2] = chosen[3] = 1;
            table[3][step] = table[2][step - 1] + table[3][step - 1];  
            table[2][step] = 0;                      
            break;
        case 16:// 2 -> 4
            if (table[2][step - 1] + table[4][step - 1] > 4 || table[2][step - 1] == 0)
                return false;
            chosen[2] = chosen[4] = 1;
            table[4][step] = table[2][step - 1] + table[4][step - 1];  
            table[2][step] = 0;                      
            break;
        case 17:// 2 -> 5
            if (table[2][step - 1] + table[5][step - 1] > 4 || table[2][step - 1] == 0)
                return false;
            chosen[2] = chosen[5] = 1;
            table[5][step] = table[2][step - 1] + table[5][step - 1];  
            table[2][step] = 0;                         
            break;
        case 18:// 2 -> 6
            if (table[2][step - 1] + table[6][step - 1] > 4 || table[2][step - 1] == 0)
                return false;
            chosen[2] = chosen[6] = 1;
            table[6][step] = table[2][step - 1] + table[6][step - 1];  
            table[2][step] = 0;            
            break;      
        default:
            return false;
            break;
    }
    for (int i = 0; i < 7; i++) {
        if (!chosen[i])
            table[i][step] = table[i][step - 1];
    }
    for (int i = 0; i < step; i++) {
        if (table[0][i] == table[0][step] && table[1][i] == table[1][step] && table[2][i] == table[2][step]
         && table[3][i] == table[3][step] && table[4][i] == table[4][step]
         && table[5][i] == table[5][step] && table[6][i] == table[6][step])
            return false;
    }
    for (int i = 0; i < size; i++) {
        if (fail[0][i] == table[0][step] && fail[1][i] == table[1][step] && fail[2][i] == table[2][step]
         && fail[3][i] == table[3][step] && fail[4][i] == table[4][step]
         && fail[5][i] == table[5][step] && fail[6][i] == table[6][step])
            return false;
    }
    return true;
}
int main() {
    table[0][0] = table[1][0] = 8; 
    bool end = false;
    while (!end) {
        cout << "step" << step << " :" << endl;
        cout << "old choice " << choice[step] << endl;
        while (choice[step] < 18) {
            choice[step]++;
            if (move(choice[step])) {
                cout << "right choice " << choice[step] << endl << "result: ";
                for (int i = 0; i < 7; i++) {
                    cout << table[i][step] << " ";
                }
                cout << endl;
                step++;
                if (table[3][step] == 4 && table[4][step] == 4 && table[5][step] == 4 && table[6][step] == 4)
                    end = true;
                break;
            }
        }
        cout << endl;
        if (end)
            break;
        if (choice[step] >= 18) {
            bool same, need = true;
            for (int i = 0; i < size; i++) {
                same = true;
                for (int j = 0; j < 7; j++) {
                    if (table[j][step] != fail[j][i])
                        same = false;
                }
                if (same) {
                    need = false;
                }
            }
            if (need) {
                cout << "fail case: ";
                for (int j = 0; j < 7; j++) {
                    fail[j][size] = table[j][step];
                    cout << table[j][step] << " ";
                }
                cout << endl;
                size++;
            }
            while (choice[step] >= 18) {
                choice[step] = 0;
                step--;
            }
        }
    }
    for (int i = 0; i < step; i++) {
        cout << table[0][i] << " " << table[1][i] << " " << table[2][i] << " " << table[3][i] << " " << table[4][i] << " " << table[5][i] << " " << table[6][i] << endl; 
    }
    return 0;
}
/* 
8 8 0 0 0 0 0 
5 8 3 0 0 0 0 
5 8 0 3 0 0 0
2 8 3 3 0 0 0
0 8 3 3 2 0 0
3 8 0 3 2 0 0
3 5 3 3 2 0 0
6 5 0 3 2 0 0
6 2 3 3 2 0 0
8 2 1 3 2 0 0
8 2 0 4 2 0 0
8 0 2 4 2 0 0
7 0 3 4 2 0 0
7 3 0 4 2 0 0
4 3 3 4 2 0 0
4 6 0 4 2 0 0
1 6 3 4 2 0 0
1 8 1 4 2 0 0
1 8 0 4 2 1 0
0 8 0 4 2 1 1
0 5 3 4 2 1 1
0 5 0 4 2 4 1
0 2 3 4 2 4 1
0 2 0 4 2 4 4
0 0 0 4 4 4 4
*/
