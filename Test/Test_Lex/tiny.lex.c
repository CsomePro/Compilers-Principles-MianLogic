
#include <stdio.h>
#include <fcntl.h>
#include <malloc.h>
#include <string.h>

FILE *file = NULL;
FILE *out = NULL;
#define SIZE_LENGTH 8
unsigned char mp[][128 / SIZE_LENGTH] =
        {
{0,0,0,0,0,0,0,0,222,253,75,7,222,253,75,7},
{0,0,0,0,0,0,255,3,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,32,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8},
{0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,32,0,0,0,32,0,0,0},
{0,0,0,0,0,0,0,0,0,0,4,0,0,0,4,0},
{0,6,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,128,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,128,0,0,0,128,0},
{0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,32,0,0,0,32,0},
{0,0,0,0,0,0,0,0,0,2,0,0,0,2,0,0},
{0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,32,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,16,0,0,0,16,0},
{0,0,0,0,0,0,0,16,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,254,255,255,7,254,255,255,7},
{0,0,0,0,0,0,255,3,0,0,0,0,0,0,0,0},
{0,4,0,0,255,255,255,255,255,255,255,255,255,255,255,95},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,32},
{0,0,0,0,0,0,0,0,254,175,255,7,254,175,255,7},
{0,0,0,0,0,0,0,0,0,16,0,0,0,16,0,0},
{0,0,0,0,0,0,0,0,0,64,0,0,0,64,0,0},
{0,0,0,0,0,0,0,0,222,255,255,7,222,255,255,7},
{0,0,0,0,0,0,0,0,32,0,0,0,32,0,0,0},
{0,6,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,254,255,251,7,254,255,251,7},
{0,0,0,0,0,0,0,0,0,0,4,0,0,0,4,0},
{0,0,0,0,0,0,0,32,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,254,191,255,7,254,191,255,7},
{0,0,0,0,0,0,0,0,0,64,0,0,0,64,0,0},
{0,0,0,0,0,0,0,0,190,255,255,7,190,255,255,7},
{0,0,0,0,0,0,0,0,64,0,0,0,64,0,0,0},
{0,0,0,0,0,0,0,0,254,254,255,7,254,254,255,7},
{0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0},
{0,0,0,0,0,0,0,0,254,255,247,7,254,255,247,7},
{0,0,0,0,0,0,0,0,0,0,8,0,0,0,8,0},
{0,0,0,0,0,0,0,0,238,255,255,7,238,255,255,7},
{0,0,0,0,0,0,0,0,16,0,0,0,16,0,0,0},
{0,0,0,0,0,0,0,0,252,255,254,7,252,255,254,7},
{0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0},
{0,0,0,0,0,0,0,0,2,0,0,0,2,0,0,0},
{0,0,0,0,0,0,0,0,254,253,255,7,254,253,255,7},
{0,0,0,0,0,0,0,0,0,2,0,0,0,2,0,0},
{0,0,0,0,0,0,0,0,0,0,16,0,0,0,16,0},
{0,0,0,0,0,0,0,0,254,255,239,7,254,255,239,7},
{0,0,0,0,0,0,0,0,254,255,255,7,254,255,255,7},
{0,0,0,0,0,0,0,0,222,255,255,7,222,255,255,7},
{0,0,0,0,0,0,0,0,32,0,0,0,32,0,0,0},
{0,0,0,0,0,0,0,0,222,255,255,7,222,255,255,7},
{0,0,0,0,0,0,0,0,32,0,0,0,32,0,0,0},
{0,0,0,0,0,0,0,0,254,255,255,7,254,255,255,7},
{0,0,0,0,0,0,0,0,222,255,255,7,222,255,255,7},
{0,0,0,0,0,0,0,0,32,0,0,0,32,0,0,0},
{0,0,0,0,0,0,0,0,238,255,255,7,238,255,255,7},
{0,0,0,0,0,0,0,0,16,0,0,0,16,0,0,0},
{0,0,0,0,0,0,0,0,254,255,239,7,254,255,239,7},
{0,0,0,0,0,0,0,0,0,0,16,0,0,0,16,0},
{0,0,0,0,0,0,0,0,254,253,255,7,254,253,255,7},
{0,0,0,0,0,0,0,0,0,2,0,0,0,2,0,0},
{0,0,0,0,0,0,0,0,254,191,255,7,254,191,255,7},
{0,0,0,0,0,0,0,0,0,64,0,0,0,64,0,0},
{0,0,0,0,0,0,0,0,254,255,255,7,254,255,255,7},
{0,0,0,0,0,0,0,0,252,255,255,7,252,255,255,7},
{0,0,0,0,0,0,0,0,2,0,0,0,2,0,0,0},
{0,0,0,0,0,0,0,0,254,255,255,7,254,255,255,7},
{0,0,0,0,0,0,0,0,222,255,255,7,222,255,255,7},
{0,0,0,0,0,0,0,0,32,0,0,0,32,0,0,0},
{0,0,0,0,0,0,0,0,254,239,255,7,254,239,255,7},
{0,0,0,0,0,0,0,0,0,16,0,0,0,16,0,0},
{0,0,0,0,0,0,0,0,254,255,255,7,254,255,255,7},
{0,0,0,0,0,0,0,0,254,255,239,7,254,255,239,7},
{0,0,0,0,0,0,0,0,0,0,16,0,0,0,16,0},
{0,0,0,0,0,0,0,0,254,255,255,7,254,255,255,7},
{0,0,0,0,0,0,0,0,254,255,255,7,254,255,255,7},
{0,0,0,0,0,0,0,0,254,255,255,7,254,255,255,7},
}
        ;

char getNextChar(){
    return (char)fgetc(file);
}

void undoGetChar(char c){
    if(c != -1) fseek(file, -1, SEEK_CUR);
}

void error(char* msg) {
    printf("%s\n", msg);
    exit(0);
}

int check(int id, char x) {
    return (mp[id][x / SIZE_LENGTH] & (1 << (x % SIZE_LENGTH))) != 0;
}

void output(char* token, char* raw) {
    size_t length = strlen(raw);
    char* buffer = calloc(1, length * 2 + 1);
    char* p = buffer;
    for(size_t i = 0; i < length; ++i) {
        if(raw[i] == '"' || raw[i] == '\\') *p++ = '\\';
        *p++ = raw[i];
    }
    *p = 0;
    fprintf(out, "%s \"%s\"\n", token, buffer);
    free(buffer);
    buffer = NULL;
    p = NULL;
}


void next(){
    int state = 0;
    char* buffer = calloc(1, 1024), *p = buffer;
    while (1) {
        char c = getNextChar();
        switch (state) {
            case 0: 
if(check(0, c)) { *p++ = c; state=1; }
else if(check(1, c)) { *p++ = c; state=18; }
else if(check(2, c)) { *p++ = c; state=13; }
else if(check(3, c)) { *p++ = c; state=20; }
else if(check(4, c)) { *p++ = c; state=17; }
else if(check(5, c)) { *p++ = c; state=3; }
else if(check(6, c)) { *p++ = c; state=5; }
else if(check(7, c)) { *p++ = c; state=19; }
else if(check(8, c)) { *p++ = c; state=11; }
else if(check(9, c)) { *p++ = c; state=16; }
else if(check(10, c)) { *p++ = c; state=14; }
else if(check(11, c)) { *p++ = c; state=7; }
else if(check(12, c)) { *p++ = c; state=15; }
else if(check(13, c)) { *p++ = c; state=6; }
else if(check(14, c)) { *p++ = c; state=2; }
else if(check(15, c)) { *p++ = c; state=8; }
else if(check(16, c)) { *p++ = c; state=10; }
else if(check(17, c)) { *p++ = c; state=9; }
else if(check(18, c)) { *p++ = c; state=4; }
else if(check(19, c)) { *p++ = c; state=12; }
else if(c == -1) { return; }
else { undoGetChar(c); *p = 0; error("Lex Error"); }
break;
case 1: 
if(check(20, c)) { *p++ = c; state=1; }
else { undoGetChar(c); *p = 0; output("ID", buffer); p = buffer; state = 0; }
break;
case 18: 
if(check(21, c)) { *p++ = c; state=18; }
else { undoGetChar(c); *p = 0; output("NUMBER", buffer); p = buffer; state = 0; }
break;
case 13: 
{ undoGetChar(c); *p = 0; output("EQ", buffer); p = buffer; state = 0; }
break;
case 20: 
if(check(22, c)) { *p++ = c; state=20; }
else if(check(23, c)) { *p++ = c; state=29; }
else { undoGetChar(c); *p = 0; error("Lex Error"); }
break;
case 17: 
{ undoGetChar(c); *p = 0; output("RP", buffer); p = buffer; state = 0; }
break;
case 3: 
if(check(24, c)) { *p++ = c; state=1; }
else if(check(25, c)) { *p++ = c; state=22; }
else if(check(26, c)) { *p++ = c; state=23; }
else { undoGetChar(c); *p = 0; output("ID", buffer); p = buffer; state = 0; }
break;
case 5: 
if(check(27, c)) { *p++ = c; state=1; }
else if(check(28, c)) { *p++ = c; state=25; }
else { undoGetChar(c); *p = 0; output("ID", buffer); p = buffer; state = 0; }
break;
case 19: 
if(check(29, c)) { *p++ = c; state=19; }
else { undoGetChar(c); p = buffer; state = 0; }
break;
case 11: 
{ undoGetChar(c); *p = 0; output("DIV", buffer); p = buffer; state = 0; }
break;
case 16: 
{ undoGetChar(c); *p = 0; output("LP", buffer); p = buffer; state = 0; }
break;
case 14: 
{ undoGetChar(c); *p = 0; output("SEM", buffer); p = buffer; state = 0; }
break;
case 7: 
if(check(30, c)) { *p++ = c; state=1; }
else if(check(31, c)) { *p++ = c; state=27; }
else { undoGetChar(c); *p = 0; output("ID", buffer); p = buffer; state = 0; }
break;
case 15: 
if(check(32, c)) { *p++ = c; state=28; }
else { undoGetChar(c); *p = 0; error("Lex Error"); }
break;
case 6: 
if(check(33, c)) { *p++ = c; state=1; }
else if(check(34, c)) { *p++ = c; state=26; }
else { undoGetChar(c); *p = 0; output("ID", buffer); p = buffer; state = 0; }
break;
case 2: 
if(check(35, c)) { *p++ = c; state=1; }
else if(check(36, c)) { *p++ = c; state=21; }
else { undoGetChar(c); *p = 0; output("ID", buffer); p = buffer; state = 0; }
break;
case 8: 
{ undoGetChar(c); *p = 0; output("PLUS", buffer); p = buffer; state = 0; }
break;
case 10: 
{ undoGetChar(c); *p = 0; output("MUL", buffer); p = buffer; state = 0; }
break;
case 9: 
{ undoGetChar(c); *p = 0; output("MINUS", buffer); p = buffer; state = 0; }
break;
case 4: 
if(check(37, c)) { *p++ = c; state=1; }
else if(check(38, c)) { *p++ = c; state=24; }
else { undoGetChar(c); *p = 0; output("ID", buffer); p = buffer; state = 0; }
break;
case 12: 
{ undoGetChar(c); *p = 0; output("LT", buffer); p = buffer; state = 0; }
break;
case 29: 
{ undoGetChar(c); p = buffer; state = 0; }
break;
case 22: 
if(check(39, c)) { *p++ = c; state=1; }
else if(check(40, c)) { *p++ = c; state=30; }
else { undoGetChar(c); *p = 0; output("ID", buffer); p = buffer; state = 0; }
break;
case 23: 
if(check(41, c)) { *p++ = c; state=1; }
else if(check(42, c)) { *p++ = c; state=31; }
else { undoGetChar(c); *p = 0; output("ID", buffer); p = buffer; state = 0; }
break;
case 25: 
if(check(43, c)) { *p++ = c; state=1; }
else if(check(44, c)) { *p++ = c; state=33; }
else if(check(45, c)) { *p++ = c; state=34; }
else { undoGetChar(c); *p = 0; output("ID", buffer); p = buffer; state = 0; }
break;
case 27: 
if(check(46, c)) { *p++ = c; state=1; }
else if(check(47, c)) { *p++ = c; state=36; }
else { undoGetChar(c); *p = 0; output("ID", buffer); p = buffer; state = 0; }
break;
case 28: 
{ undoGetChar(c); *p = 0; output("ASSIGN", buffer); p = buffer; state = 0; }
break;
case 26: 
if(check(48, c)) { *p++ = c; state=35; }
else if(check(49, c)) { *p++ = c; state=1; }
else { undoGetChar(c); *p = 0; output("ID", buffer); p = buffer; state = 0; }
break;
case 21: 
if(check(50, c)) { *p++ = c; state=1; }
else { undoGetChar(c); *p = 0; output("IF", buffer); p = buffer; state = 0; }
break;
case 24: 
if(check(51, c)) { *p++ = c; state=1; }
else if(check(52, c)) { *p++ = c; state=32; }
else { undoGetChar(c); *p = 0; output("ID", buffer); p = buffer; state = 0; }
break;
case 30: 
if(check(53, c)) { *p++ = c; state=1; }
else if(check(54, c)) { *p++ = c; state=37; }
else { undoGetChar(c); *p = 0; output("ID", buffer); p = buffer; state = 0; }
break;
case 31: 
if(check(55, c)) { *p++ = c; state=1; }
else { undoGetChar(c); *p = 0; output("END", buffer); p = buffer; state = 0; }
break;
case 33: 
if(check(56, c)) { *p++ = c; state=1; }
else if(check(57, c)) { *p++ = c; state=39; }
else { undoGetChar(c); *p = 0; output("ID", buffer); p = buffer; state = 0; }
break;
case 34: 
if(check(58, c)) { *p++ = c; state=1; }
else if(check(59, c)) { *p++ = c; state=40; }
else { undoGetChar(c); *p = 0; output("ID", buffer); p = buffer; state = 0; }
break;
case 36: 
if(check(60, c)) { *p++ = c; state=1; }
else if(check(61, c)) { *p++ = c; state=42; }
else { undoGetChar(c); *p = 0; output("ID", buffer); p = buffer; state = 0; }
break;
case 35: 
if(check(62, c)) { *p++ = c; state=1; }
else if(check(63, c)) { *p++ = c; state=41; }
else { undoGetChar(c); *p = 0; output("ID", buffer); p = buffer; state = 0; }
break;
case 32: 
if(check(64, c)) { *p++ = c; state=1; }
else if(check(65, c)) { *p++ = c; state=38; }
else { undoGetChar(c); *p = 0; output("ID", buffer); p = buffer; state = 0; }
break;
case 37: 
if(check(66, c)) { *p++ = c; state=1; }
else { undoGetChar(c); *p = 0; output("ELSE", buffer); p = buffer; state = 0; }
break;
case 39: 
if(check(67, c)) { *p++ = c; state=1; }
else if(check(68, c)) { *p++ = c; state=43; }
else { undoGetChar(c); *p = 0; output("ID", buffer); p = buffer; state = 0; }
break;
case 40: 
if(check(69, c)) { *p++ = c; state=1; }
else { undoGetChar(c); *p = 0; output("READ", buffer); p = buffer; state = 0; }
break;
case 42: 
if(check(70, c)) { *p++ = c; state=1; }
else if(check(71, c)) { *p++ = c; state=45; }
else { undoGetChar(c); *p = 0; output("ID", buffer); p = buffer; state = 0; }
break;
case 41: 
if(check(72, c)) { *p++ = c; state=1; }
else if(check(73, c)) { *p++ = c; state=44; }
else { undoGetChar(c); *p = 0; output("ID", buffer); p = buffer; state = 0; }
break;
case 38: 
if(check(74, c)) { *p++ = c; state=1; }
else { undoGetChar(c); *p = 0; output("THEN", buffer); p = buffer; state = 0; }
break;
case 43: 
if(check(75, c)) { *p++ = c; state=1; }
else if(check(76, c)) { *p++ = c; state=46; }
else { undoGetChar(c); *p = 0; output("ID", buffer); p = buffer; state = 0; }
break;
case 45: 
if(check(77, c)) { *p++ = c; state=1; }
else { undoGetChar(c); *p = 0; output("WRITE", buffer); p = buffer; state = 0; }
break;
case 44: 
if(check(78, c)) { *p++ = c; state=1; }
else { undoGetChar(c); *p = 0; output("UNTIL", buffer); p = buffer; state = 0; }
break;
case 46: 
if(check(79, c)) { *p++ = c; state=1; }
else { undoGetChar(c); *p = 0; output("REPEAT", buffer); p = buffer; state = 0; }
break;

            default:
                error("unknown error");
                return;
        }
    }
}


int main(int argv, char** args) {
    if(argv < 3) {
        printf("Usage: lex file.l target.lex\n");
        return 0;
    }
    file = fopen(args[1], "r+");
    if(file == NULL) {
        printf("Open %s Error.", args[1]);
        return 0;
    }
    out = fopen(args[2], "w");
    if(file == NULL) {
        printf("Open %s Error.", args[2]);
        return 0;
    }
    next();
    fclose(file);
    fclose(out);
    printf("success\n");
}
