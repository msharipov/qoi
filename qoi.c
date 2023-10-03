#include <stdio.h>
#include <string.h>

// format: R, G, B, A
struct Pixel {
    int R, G, B, A;
};

void print_help() {
    printf("Usage: qoi [options] FILE \n\n");
    printf("-f                  Display supported formats.\n");
    printf("-h                  Display this help.\n");
}

void list_formats() {
    printf("Supported formats:\n");
    printf(".QOI \n");
    printf(".PPM \n");
}

void complain_args() {
    printf("Error! Invalid number of arguments\n");
    print_help();
}

void complain_option(char * opt) {
    printf("Error! Invalid option: %s\n", opt);
    print_help();
}

void complain_no_outfile() {
    printf("Error! Missing filename after '-o'\n");
}

void complain_no_infile() {
    printf("Error! Input file was not specified\n");
}

/* Error codes:
    1 - Invalid user input
    2 - Help/Formats screen requested
*/
int main(int argc, char * argv[]){
    if (argc < 2) {
        complain_args();
        return 1;
    }

    char * infilename = NULL,
         * outfile = NULL;

    // Handle arguments
    for (int i = 1; i < argc; i++) {

        if (argv[i][0] == '-') {

            // When there is no option after '-'
            if (strlen(argv[i]) == 1) {
                complain_option(argv[i]);
                return 1;
            }

            switch (argv[i][1]) {
            case 'h':
                print_help();
                return 2;

            case 'f':
                list_formats();
                return 2;

            case 'o':
                if (i + 1 < argc && argv[i + 1][0] != '-') {
                    outfile = argv[i + 1];
                    i++;
                } else {
                    complain_no_outfile();
                    return 1;
                }
                break;

            default:
                complain_option(argv[i]);
                return 1;
            }

        } else {

            infilename = argv[i];
        }
    }

    if (!infilename) {
        complain_no_infile();
        return 1;
    }

    FILE * INFILE = fopen(infilename, "r");

    fclose(INFILE);

    return 0;
}
