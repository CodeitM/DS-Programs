//To implement a SIC Assembler

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LINE_strlen 10

int Search_Symtab(char *label);
int Search_Optab(char *opcode);

void main(){

    int i_operand,locctr=0,ins_length,start_address,end_address,length;
    FILE *input, *first, *symtab;

    input = fopen("input_code.txt","r");
    first = fopen("first.txt","a");
    symtab = fopen("symtab.txt","a");
    char label[LINE_strlen], opcode[LINE_strlen], operand[LINE_strlen];

    if(input == NULL){
        printf("\n The Code does not Exist!");
        exit(0);
    }

    while(!feof(input)){
        //printf("\n In here0");
        fscanf(input,"%s %s %s",label,opcode,operand);
        //printf("\nLabel:  %s Operator: %s Operand: %s",label,opcode,operand);
        if(strcmp(opcode,"START") == 0){
            //printf("\n In here1");
            if(strcmp(operand,"-") != 0){
                //printf("\n In here2");
               locctr= strtol(operand,NULL,16);
            }
            else{
                locctr = strtol(0,NULL,16);
            }
            fprintf(symtab," %s %x \n",label,locctr);
            start_address = locctr;
            continue;
        }
        if(strcmp(opcode,"END") != 0){
            if(strcmp(label,"-") != 0){
                if(Search_Symtab(label) == 1){
                    fprintf(first,"Error: Duplicate Symbol!");    
                }
                else{
                    fprintf(symtab," %s %x \n",label,locctr);
                }
            }
            //printf("\n**");
            if(Search_Optab(opcode) == 1){
                //printf("$");
                ins_length=3;
                locctr+=ins_length;
            }
            else if(strcmp(opcode,"WORD") == 0){
                ins_length=3;
                locctr+=ins_length;
            }
            else if(strcmp(opcode,"RESW") == 0){
                i_operand = strtol(operand,NULL,16);
                ins_length=3*i_operand;
                locctr+=ins_length;
            }
            else if(strcmp(opcode,"RESB") == 0){
                i_operand= strtol(operand,NULL,16);
                ins_length=i_operand;
                locctr+=ins_length;
            }
            else if(strcmp(opcode,"BYTE") == 0){
                ins_length=strlen(operand);
                locctr+=ins_length;
            }
            else{
                fprintf(first,"Error: Invalid Opcode!"); 
            }
            fprintf(first,"%x %s %s \n",(locctr-ins_length),opcode,operand);
            continue;
        }
        else{
            end_address = locctr;
            break;
        }
  
    }
    length = end_address - start_address;
    printf("\n The length of the program is: %x",length);
    fclose(first);
    fclose(input);
    fclose(symtab);
}

int Search_Symtab(char *label){
    char read[LINE_strlen], op[LINE_strlen];
    FILE *sym;
    sym = fopen("symtab.txt","r");
    while(!feof(sym)){
        fscanf(sym,"%s %s",read,op);
        if(strcmp(read,label)==0)
            return 1;
    }
    fclose(sym);
    return 0;
}

int Search_Optab(char *opcode){
    FILE *optab;
    char code[LINE_strlen],hex[LINE_strlen];
    //printf("\n optab search");
    optab = fopen("optab.txt","r");
    while(!feof(optab)){
        fscanf(optab,"%s %s",code,hex);
        //printf("\n %s %s",code,hex);
        if(strcmp(code,opcode)==0)
            return 1;
        else
            continue;
    }
    fclose(optab);
    return 0;
}