#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct
{
  int lin;
  int col;
  int val;
} point;

int main()
{

  int row, col;

  scanf("%d %d", &row, &col);

  int **m = (int **)malloc(row * sizeof(int *));

  for (int i = 0; i < row; i++)
  {
    m[i] = (int *)malloc(col * sizeof(int));
  }


  int count = 0;

  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      scanf("%d", m[i][j]);

      if (m[i][j] != 0)
      {
        count++;
      }
    }
  }

  point *notnull = (point *) malloc(count * sizeof(point));
  int k = 0;


  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {

      if (m[i][j] != 0)
      {
        notnull[k].col = j;
        notnull[k].lin = i;
        notnull[k].val = m[i][j];
        k++;
      }
    }
  }

  for(int i = 0; i < count; i++){
    printf("row: %d / col: %d // val: %d\n\n", notnull[i].lin, notnull[i].col, notnull[i].val);
  }
}
