int main(int argc, char * argv[]){
    if (argc < 2) {
        printf("Invalid number of arguments!\n");
        printf("USAGE: qoi FILE1 [FILE2] ...\n");
        printf("Only .ppm and .qoi formats supported.");
    }

    for (int file_number = 1; file_number <= argc; file_number++) {
        const char * FILENAME = argv[file_number];
    }
    return 0;
}