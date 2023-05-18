#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "calculator.h"

     Calculator* create_calculator(double (**operations)(int, int), int operationCount){
            
            Calculator* newCalculator = malloc(sizeof(Calculator));

            newCalculator->operations = operations;
            newCalculator->data = malloc(100*sizeof(int*));
            newCalculator->operationCount = operationCount;
            newCalculator->dataLength = 0;


            return newCalculator;

     }

     bool load_calculator_data(Calculator* calculatorPtr, char* fileName){

            bool storedCalculator = 1;

            if(fileName == NULL){

                return storedCalculator = 0;

            }

            if(calculatorPtr == NULL){

                return storedCalculator = 0;

            }

            FILE* filePtr = fopen(fileName, "r");


            for(int i = 0; i < 100; i++){

                    calculatorPtr->data[i] = malloc(sizeof(int) * 3);

                for(int j = 0; j < 3; j++){ 

                fscanf(filePtr, "%d", &(calculatorPtr->data[i][j]));
                    
                

                }

            }
                
            fclose(filePtr);

            calculatorPtr->dataLength = 100;

            return storedCalculator;

     }
 
     void run_calculator(Calculator* calcPtr){

            for(int i = 0; i < calcPtr->dataLength; i++){
                int op = calcPtr->data[i][0];
                printf("%.5lf\n", (*calcPtr->operations[op])(calcPtr->data[i][1], calcPtr->data[i][2]));
            }

     }
 
     bool destroy_calculator(Calculator* calculatorPtr){
        
            int success = 1;
            
            if(calculatorPtr == NULL){
                return success = 0;
            }

            for(int i = 0; i < calculatorPtr->dataLength; i++){
 
 
                 free(calculatorPtr->data[i]);
                
 
             }
 
            free(calculatorPtr->data);


            free(calculatorPtr);

            return success;

     }
 
     double add_calculator(int a, int b){

        double ans = (double)a + (double)b;

        return ans;

     }
 
     double sub_calculator(int a, int b){
        
        double ans = (double)a - (double)b;


        return ans;

     }
 
     double mul_calculator(int a, int b){
        double ans = (double)a * (double)b;

        return ans;
     }
 
     double div_calculator(int a, int b){

         double ans = (double)a / (double)b;

         return ans;

     }
 
     double mod_calculator(int a, int b){

        
         double ans = a % b;


        return ans;
    }
     
