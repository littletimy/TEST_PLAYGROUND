#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
# include <fcntl.h>

int main()
{
    int file;
    int index;
    char buffer;
    char *buffer_str;

    //simply output
    file = open("text.txt", O_RDONLY);
    while(read(file, &buffer, 1))
    {
        write(1, &buffer, 1);
    }
    write(1, "\n", 1);
    close(file);

    //assign into a str;
    file = open("text.txt", O_RDONLY);
    index = 0;
    while(read(file, &buffer, 1))
        buffer_str[index++] = buffer;
    buffer_str[index] = '\0';
    close(file);    

    //display
    index = 0;
    while(buffer_str[index])
        write(1, &buffer_str[index++], 1);
    write(1, "\n", 1);


    return (0);
}