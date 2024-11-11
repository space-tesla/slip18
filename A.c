/* Write a C program to find whether a given file is present in the current directory or not.*/
#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main() {
    char filename[100];
    int found = 0;
    DIR *d;
    struct dirent *dir;

    printf("Enter the filename to search: ");
    scanf("%s", filename);

    d = opendir(".");
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (strcmp(dir->d_name, filename) == 0) {
                found = 1;
                break;
            }
        }
        closedir(d);
    }

    if (found) {
        printf("File '%s' found in the current directory.\n", filename);
    } else {
        printf("File '%s' not found in the current directory.\n", filename);
    }

    return 0;
}



/*Enter the filename to search: example.txt
File 'example.txt' found in the current directory.
*/