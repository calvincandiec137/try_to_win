#include <stdio.h>

char matrix[3][3] = {' '};  // Fix array initialization

// Function prototypes
char check(void);
void get_input(void);
void get_comp_input(int z);
void display_result(void);
void ini_matrix(void);

int main(void) {
    int z = 0;
    ini_matrix();

    char done = ' ';

    while (z < 4) {
        //display_result(); 
        get_comp_input(z);
        display_result();
        done = check();
        if(done!=' '){break;}
        get_input();
        done = check();
        if (done != ' ') {break;}
        z++;
    }

    display_result();
    
    if (done == 'X') {
        printf("You won !!");
    } else if (done == 'O')  {
        printf("I won!!");
    }

    

    return 0;
}

void get_input(void) {
    int x, y;

    printf("Write the coordinates of move x & y\nx:");
    scanf("%d", &x);
    printf("y:");
    scanf("%d", &y);
    

    if (x < 0 || x >=3 || y < 0 || y >= 3 || matrix[x][y] != ' ') {
        printf("Invalid move, try again.\n");
        get_input();
    } else {
        
        matrix[x][y] = 'X';
    }

}

void get_comp_input(int z) {
    if (z == 0) {
        matrix[0][0] = 'O';
    } else if (z == 1) {
        if (matrix[2][2] == ' ') {
            matrix[2][2] = 'O';
        } else {
            matrix[2][0] = 'O';
        }
    } else if (z == 2) {
        // Implement the logic for z == 2
         if ( matrix[2][0]=='O')
    {
      if (matrix[2][2]==' ')
    {
        matrix[2][2]='O';
    }else{
        matrix[0][2]='O';
    }
    }
//--------------------------------------
    if (matrix[2][2]=='O')
    {
      if (matrix[0][2]==' ')
    {
        matrix[0][2]='O';
    }else{
        matrix[2][0]='O';
    }
    }
 //----------------------------------------   
    } else if (z == 3) {
        // Implement the logic for z == 3
        if ( matrix[2][0]=='O' && matrix[2][2]=='O'&& matrix[2][1]==' ')
    {
      matrix[2][1]='O';
    }

    if ( matrix[2][0]=='O' && matrix[2][2]=='O'&& matrix[1][0]==' ')
    {
      matrix[1][0]='O';
    }

    if ( matrix[2][0]=='O' && matrix[0][2]=='O'&& matrix[1][0]!=' ')
    {
      matrix[0][1]='O';
    }

    if ( matrix[2][0]=='O' && matrix[0][2]=='O'&& matrix[0][1]!=' ')
    {
      matrix[1][0]='O';
    }

    if (matrix[2][2]=='O' && matrix[0][2]=='O'&& matrix[1][2]!=' ')
    {
      matrix[0][1]='O';
    }

    if ( matrix[2][2]=='O' && matrix[0][2]=='O'&& matrix[0][1]!=' ')
    {
      matrix[1][2]='O';
    }
    }
}

void display_result(void) {
    for (int t = 0; t < 3; t++) {
        printf(" %c | %c | %c ", matrix[t][0], matrix[t][1], matrix[t][2]);
        if (t != 2) {
            printf("\n------------");
        }
        printf("\n");
    }
}

char check(void) {
    for (int i = 0; i < 3; i++) {
        if (matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2]) {
            return matrix[i][0];
        }
    }

    for (int i = 0; i < 3; i++) {
        if (matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i]) {
            return matrix[0][i];
        }
    }

    if (matrix[0][0] == matrix[1][1] && matrix[0][0] == matrix[2][2]) {
        return matrix[0][0];
    }

    if (matrix[0][2] == matrix[1][1] && matrix[0][2] == matrix[2][0]) {
        return matrix[0][2];
    }

   return ' ';
}

void ini_matrix(void) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = ' ';
        }
    }
}
