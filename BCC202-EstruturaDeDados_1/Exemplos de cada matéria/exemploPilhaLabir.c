#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void pop(struct Node** head) {
    if (*head == NULL) {
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

int isEmpty(struct Node* head) {
    return (head == NULL);
}

struct Maze {
    int** maze;
    int rows;
    int cols;
};

struct Maze* createMaze(int rows, int cols) {
    struct Maze* newMaze = (struct Maze*)malloc(sizeof(struct Maze));
    
    newMaze->maze = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        newMaze->maze[i] = (int*)malloc(cols * sizeof(int));
    }
    
    newMaze->rows = rows;
    newMaze->cols = cols;
    
    return newMaze;
}

void deleteMaze(struct Maze* maze) {
    for (int i = 0; i < maze->rows; i++) {
        free(maze->maze[i]);
    }
    
    free(maze->maze);
    free(maze);
}

int isValid(struct Maze* maze, int row, int col) {
    return (row >= 0 && row < maze->rows && col >= 0 && col < maze->cols && maze->maze[row][col] == 1);
}

void solveMaze(struct Maze* maze, int startRow, int startCol, int endRow, int endCol) {
    int dir[][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int numDirs = 4;
    
    struct Node* stack = NULL;
    
    int** visited = (int**)malloc(maze->rows * sizeof(int*));
    for (int i = 0; i < maze->rows; i++) {
        visited[i] = (int*)malloc(maze->cols * sizeof(int));
        for (int j = 0; j < maze->cols; j++) {
            visited[i][j] = 0;
        }
    }
    
    push(&stack, startRow);
    push(&stack, startCol);
    
    while (!isEmpty(stack)) {
        int col = stack->data;
        pop(&stack);
        int row = stack->data;
        pop(&stack);
        
        visited[row][col] = 1;
        
        if (row == endRow && col == endCol) {
            printf("Caminho encontrado!\n");
            return;
        }
        
        for (int i = 0; i < numDirs; i++) {
            int newRow = row + dir[i][0];
            int newCol = col + dir[i][1];
            
            if (isValid(maze, newRow, newCol) && !visited[newRow][newCol]) {
                push(&stack, newRow);
                push(&stack, newCol);
                
                visited[newRow][newCol] = 1;
            }
        }
    }
    
    printf("Caminho não encontrado!\n");
}

int main() {
    int rows, cols;
    printf("Informe o número de linhas: ");
    scanf("%d", &rows);
    printf("Informe o número de colunas: ");
    scanf("%d", &cols);
    
    struct Maze* maze = createMaze(rows, cols);
    printf("Preencha o labirinto com 0 para obstáculos e 1 para caminhos livres:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &maze->maze[i][j]);
        }
    }
    
    int startRow, startCol, endRow, endCol;
    printf("Informe as coordenadas da posição inicial (linha coluna): ");
    scanf("%d %d", &startRow, &startCol);
    printf("Informe as coordenadas da posição final (linha coluna): ");
    scanf("%d %d", &endRow, &endCol);
    
    solveMaze(maze, startRow, startCol, endRow, endCol);
    
    deleteMaze(maze);
    
    return 0;
}


/*Este código permite que você informe o número de linhas e colunas do 
labirinto, em seguida, preencha o labirinto com obstáculos (0) e 
caminhos livres (1). Ele também solicita as coordenadas da posição 
inicial e final. Em seguida, ele usa a função `solveMaze` para resolver 
o labirinto e exibir se um caminho foi encontrado ou não.*/
