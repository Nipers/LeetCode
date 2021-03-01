#include<iostream>
using namespace std;
int table[7][1000] = {{}}, choice[1000] = {}, step = 1;
bool move(int choice) {//该选择能不能走
    int chosen[7] = {};
    switch (choice) {
        case 1://x -> y
            chosen[0] = chosen[1] = 1;
            break;
        case 2:// x -> z
            chosen[0] = chosen[2] = 1;
            break;
        case 3:// y -> x
            chosen[0] = chosen[1] = 1;
            break;
        case 4:// y -> z
            chosen[2] = chosen[1] = 1;
            break;
        case 5:// z -> x
            chosen[0] = chosen[2] = 1;
            break;
        case 6: // z -> y
            chosen[2] = chosen[1] = 1;
            break;
        case 7: // x -> w
            chosen[0] = chosen[3] = 1;
            
            break;
        case 8:// x -> o
            chosen[0] = chosen[4] = 1;
            break;
        case 9:// x -> p
            chosen[0] = chosen[5] = 1;
            break;
        case 10:// x -> q
            chosen[0] = chosen[6] = 1;
            
            break;
        case 11:// y -> w
            chosen[1] = chosen[3] = 1;
            break;
        case 12:// y -> o
            chosen[1] = chosen[4] = 1;
            break;
        case 13:// y -> p
            chosen[1] = chosen[5] = 1;
            
            break;
        case 14:// y -> q
            chosen[1] = chosen[6] = 1;
            
            break;
        case 15:// z -> w
            chosen[2] = chosen[2] = 1;
            
            break;
        case 16:// z -> o
            chosen[2] = chosen[4] = 1;
            
            break;
        case 17:// z -> p
            chosen[2] = chosen[5] = 1;
            
            break;
        case 18:// z -> q
            chosen[2] = chosen[6] = 1;
            
            break;      
        default:
            break;
    }
    for (int i = 0; i < 7; i++) {
        if (!chosen[i])
            table[i][step] = table[i][step];
    }
    return true;
}
int main() {
    
    for (int i = 0; i < step; i++) {
        cout << table[0][i] << " " << table[1][i] << " " << table[2][i] << " " << table[3][i] << " " << table[4][i] << " " << table[5][i] << " " << table[6][i] << endl; 
    }
    return 0;
}