int main(int argc, char *argv[])
{

    output_fd = unlink(argv[1]);
    if (output_fd == -1)
    {
        perror("unlink error");
        return 3;
    }
}
