int main(int argc, char * argv[]){
    if (argc < 2) {
        printf("Invalid number of arguments!\n");
        printf("USAGE: qoi FILE1 [FILE2] ...\n");
        printf("Only .ppm and .qoi formats supported.");
    }
    return 0;
}