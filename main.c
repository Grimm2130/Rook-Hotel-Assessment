#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TO_CHAR(x) (x+48)
/**********  Q1 *************/
/** 
 * @brief Get the possible perfect Squares from paper and returns the possible dimensions
 * 
 * @param N : Length
 * @param M : Width
 * @return char* 
 */
char* getSquares(int N, int M){
    // Compute product
    int prod = (int) N*M;
    // define return variable
    char* ret = calloc(prod, sizeof(char));
    int retIdx = 0;
    for(int i = prod; i >= 1; i--){
        // Check for the number of squares that can be extracted
        while((prod/i) >= i){
            // remove the square from the paper
            prod -= i*i;
            // Print the values
            // printf("%dx%d, ", i, i);
            // Append the square to the paper
            ret[retIdx++] = TO_CHAR(i);
            ret[retIdx++] = 'x';
            ret[retIdx++] = TO_CHAR(i);
            ret[retIdx++] = ',';
            ret[retIdx] = ' ';
        }
    }
    // terminate string
    ret[--retIdx] = '\0';
    // return string of characters
    return ret;
}


/**********  Q2 *************/
/*
Q(2): The solution for the function is estimated to be:
            B' = 857.62x + 15119, linearly.
        but Programming anc be used to find the standard error observable 
        for each estimation.
        then the equation can then be defined as such:

        B exists within { B' +/- σ_min/max}, where σ is the standard error

        calculations for  σ [min, max] will be done below
*/
// function to read in the output values
int* readFile(){
    // declare
    int* ret = calloc(100, sizeof(int));
    int ret_idx = 0;
    // declare file object pointer
    FILE* fp;
    char buff[255]; // char buffer
    
    fp = fopen("EmbeddedTest.txt", "r");
    // read FILE
    while( fscanf(fp, "%s", buff) != EOF ){
        ret[ret_idx++] = atoi(buff);
        // printf("%s\n", buff);
    }    
    fclose(fp);
    return ret;
}


// Function to calculate the max and min deviation
float* getError(float a, float b, int* nums, int n){
    // Int {σ_min, σ_max}
    float *ret = calloc(2, sizeof(float));
    for(int i = 0; i < n; i++){
        // Compute the approximation
        float approx = (a * (i+1)) + b;
        // check for positive deviation
        if(approx > nums[i]){
            float diff = approx - (float) nums[i];
            ret[1] = ret[1] > diff ? ret[1] : diff;
        }
        // Check for nnegative deviation
        else if(approx < nums[i]){
            float diff = approx - (float)nums[i];
            ret[0] = ret[0] < diff ? ret[0] : diff;
        }
    }
    return ret;
}


int main()
{
    // Q1: Get the square from a sheet of paper
    char* res = getSquares(1,1);
    printf("***Part 1***\nResult :");
    int i = 0;
    for(i; res[i] != '\0'; i++){
        printf(" %c", res[i]);
    }
    printf("\n");
    memset(res, '\0', i*sizeof(char));
    free(res);
    // Q2: Find the function of relation for some points
    printf("This question does not make sense...\n");
    return 0;
}