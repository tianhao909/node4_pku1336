#include "add.h"
#include "max.h"
#include "sq.h"

int main(int argc, char **argv){
    //call
    add( atoi(argv[1]), atoi(argv[2]) );
    max(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]) );
    sqrts();
    return 0;
}