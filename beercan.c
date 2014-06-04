#include <stdlib.h>
#include <stdio.h>

int my_strlen(char * str) {
    int i = 0;
    while(str[i] != '\0') {
        i++;
    }
    return i;
}

void highlight_file(char * key, char * fname) {
    FILE *fp = fopen(fname, "r");
    char c;
    int i = 0;
    int keycount = 0;
    int len_key = my_strlen(key);

    if ( fp != NULL ) {
        while ( !feof(fp) ) {
            c = fgetc(fp);
            if ( c != '\0' ) {
                printf("%c",c);

                if ( c == key[i] ) {
                    i++;
                    if ( i == len_key ) {
                        keycount++;
                        printf("(%d)", keycount);
                        i = 0;
                    }

                } else {
                    if ( i > 0 ) {
                        //fseek(fp, i*-1, SEEK_CUR);
                        i = 0;
                    }
                }

            }
        }
    } else {
        fprintf(stderr, "Unable to access file %s. Check that file exists or has appropriate access permissions.\n", fname);
    }
    fclose(fp);
}


int main(int argc, char * argv[]) {
    //PREP WORK
    //check for arguments.
    if ( !(argc == 3) ) {
        fprintf(stderr, "Error: not enough arguments. Requires a keyword and a filename.\n");
        return 1;
    }
    char * _key = argv[1];
    char * _fname = argv[2];
    highlight_file(_key, _fname);
    return 0;
}
