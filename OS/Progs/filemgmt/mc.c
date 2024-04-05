
int main(int argc, char *argv[])
{

    int input_fd, output_fd; /* Input and output file descriptors */

    /* Are src and dest file name arguments missing */
    if (argc != 3)
    {
        printf("Usage: mv file1 file2");
        return 1;
    }

    /* Create input file descriptor */
    input_fd = link(argv[1], argv[2]);
    if (input_fd == -1)
    {
        perror("link error");
        return 2;
    }

    /* Create output file descriptor */
    output_fd = unlink(argv[1]);
    if (output_fd == -1)
    {
        perror("unlink");
        return 3;
    }
}
